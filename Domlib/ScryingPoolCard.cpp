#include "StdAfx.h"
#include "ScryingPoolCard.h"

namespace Domlib
{

ScryingPoolCard::ScryingPoolCard( void )
    : Card( 
        L"Scrying Pool",
        CARDID_SCRYINGPOOL,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 1 ) )
{
}

ScryingPoolCard::~ScryingPoolCard( void )
{
}

void ScryingPoolCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusActions( 1 );

    Attack( pEngine, ATTACK_ALL );

    ICardList revealedCardList;
    ICard* pRevealedCard;
    
    do
    {
        pRevealedCard = pPlayer->RevealCardFromDeck();
        revealedCardList.push_back( pRevealedCard );
    }
    while( pRevealedCard->IsActionCard() );

    pPlayer->PutCardsInHand( revealedCardList );
}

void ScryingPoolCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    Player* pAttackingPlayer = pEngine->GetCurrentPlayer();
    AI* pAttackingAi = pPlayer->GetAI();
    ICard* pCard = pPlayer->RevealCardFromDeck();
    ScryingPoolOpt scryingPoolOpt;

    if( pAttackingPlayer == pPlayer )
    {
        scryingPoolOpt = pAttackingAi->OnScryingPoolSelf( pCard );
    }
    else
    {
        scryingPoolOpt = pAttackingAi->OnScryingPoolOther( pCard );
    }
    
    switch( scryingPoolOpt )
    {
    case SCRYING_DISCARD_CARD:
        pPlayer->PutCardInDiscard( pCard );
        break;
    case SCRYING_PUT_BACK_CARD:
        pPlayer->PutCardOnDraw( pCard );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: ScryingPoolCard::OnAttack" );
        break;
    }
}

} // namespace Domlib