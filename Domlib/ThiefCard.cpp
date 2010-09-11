#include "StdAfx.h"
#include "ThiefCard.h"

namespace Domlib
{

ThiefCard::ThiefCard( void )
    : Card( 
        L"Thief",
        CARDID_THIEF,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

ThiefCard::~ThiefCard( void )
{
}


void ThiefCard::OnActionPhase( Engine* pEngine )
{
    Attack( pEngine, ATTACK_OTHERS );
}

void ThiefCard::OnAttack( Engine* pEngine, Player* pPlayer )
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
        pCardToTrash    = pAttackingAi->OnThiefTrash( cardList );

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
            throw std::wstring( L"Error: ThiefCard::OnAttack" );
            return;
        }
        break;
    default:
        // TODO: report error. (early return)
        throw std::wstring( L"Error: ThiefCard::OnAttack" );
        return;
    }
    
    ThiefOpt thiefOpt = 
        pAttackingAi->OnThiefGain( pCardToTrash );
    switch( thiefOpt )
    {
    case THIEF_STEAL_TREASURE_CARD:
        pAttackingPlayer->PutCardInDiscard( pCardToTrash );
        break;
    case THIEF_TRASH_TREASURE_CARD:
        pEngine->PutInTrash( pCardToTrash );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: ThiefCard::OnAttack" );
        break;
    }
}

} // namespace Domlib