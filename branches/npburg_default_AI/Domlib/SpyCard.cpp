#include "StdAfx.h"
#include "SpyCard.h"

namespace Domlib
{

SpyCard::SpyCard( void )
: Card(
       L"Spy",
       CARDID_SPY,
       CARDTYPE_ACTION_ATTACK,
       0,
       Treasure( 0, 0 ),
       Treasure( 4, 0 ) )
{
}

SpyCard::~SpyCard( void )
{
}

void SpyCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    Attack( pEngine, ATTACK_ALL );
}

void SpyCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    Player* pAttackingPlayer = pEngine->GetCurrentPlayer();
    IAI* pAttackingAi = pPlayer->GetAI();
    Card* pCard = pPlayer->RevealCardFromDeck();
    SpyOpt spyOpt;

    if( pAttackingPlayer == pPlayer )
    {
        spyOpt = pAttackingAi->OnSpySelf( pCard );
    }
    else
    {
        spyOpt = pAttackingAi->OnSpyOther( pCard );
    }
    
    switch( spyOpt )
    {
    case SPY_DISCARD_CARD:
        pPlayer->PutCardInDiscard( pCard );
        break;
    case SPY_PUT_BACK_CARD:
        pPlayer->PutCardOnDraw( pCard );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: SpyCard::OnAttack" );
        break;
    }
}

} // namespace Domlib