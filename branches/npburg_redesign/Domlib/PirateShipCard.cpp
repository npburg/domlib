#include "StdAfx.h"
#include "PirateShipCard.h"

namespace Domlib
{

PirateShipCard::PirateShipCard( void )
    : Card( 
        L"Pirate Ship",
        CARDID_PIRATESHIP,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

PirateShipCard::~PirateShipCard( void )
{
}

void PirateShipCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    PirateShipOpt pirateShipOpt = pAI->OnPirateShip();
    
    switch( pirateShipOpt )
    {
    case PIRATESHIP_ATTACK:
    {
        m_bFoundTreasure = false;
        Attack( pEngine, ATTACK_OTHERS );
        if( m_bFoundTreasure )
        {
            pPlayer->PlusPirateCoin();
        }
        break;
    }
    case PIRATESHIP_PLUS_COINS:
        pPlayer->PlusCoins( pPlayer->PirateCoins() );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: PirateShipCard::OnActionPhase" );
        break;    
    }
}

void PirateShipCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    Player* pAttackingPlayer = pEngine->GetCurrentPlayer();
    IAI* pAttackingAi = pAttackingPlayer->GetAI();
    CardList cardList = pPlayer->RevealCardsFromDeck( 2 );
    Card* pCardToTrash;
    CardListIter iter;

    
    for( iter = cardList.begin();
         iter != cardList.end();
         iter++ )
    {
        if( (*iter)->IsTreasureCard() == false )
        {
            pPlayer->PutCardInDiscard( *iter );
            cardList.erase( iter );
        }
    }

    switch( cardList.size() )
    {
    case 0:
        // Do nothing (early return)
        return;
    case 1:
        pCardToTrash = cardList.front();
        cardList.clear();
        break;
    case 2:
        pCardToTrash    = pAttackingAi->OnPirateShipTrash( cardList );

        // This can be dangerous since pCardToTrash is a pointer but
        // since every card is unique per game (instance of engine) then all pointers
        // to a particular card are must be the same.
        // Might be safer to use card ID instead of pointer to card
        // but then will have to add a lot of code to get the card
        // to act on it, in addition, need to make sure the card
        // is given the right game context.
        iter = std::find( 
            cardList.begin(),
            cardList.end(),
            pCardToTrash);
        if( iter != cardList.end() )
        {
            cardList.erase( iter );
            Card* pCardToDiscard = cardList.front();
            pPlayer->PutCardInDiscard( pCardToDiscard );
            cardList.clear();
        }
        else
        {
            // TODO: report error (return early)
            throw std::wstring( L"Error: PirateShipCard::OnAttack" );
            return;
        }
        break;
    default:
        // TODO: report error. (early return)
        throw std::wstring( L"Error: PirateShipCard::OnAttack" );
        return;
    }
    
    pEngine->PutCardInTrash( pCardToTrash );
    m_bFoundTreasure = true;
}

} // namespace Domlib