#include "StdAfx.h"
#include "MinionCard.h"

namespace Domlib
{

MinionCard::MinionCard( void )
    : Card( 
        L"Minion",
        CARDID_MINION,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

MinionCard::~MinionCard( void )
{
}

void MinionCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();

    pPlayer->PlusActions( 1 );

    MinionOpt minionOpt = pAi->OnMinion();
    switch( minionOpt )
    {
    case MINION_PLUS_2_COINS:
        pPlayer->PlusCoins( 2 );
        break;
    case MINION_DISCARD_HAND:
        {
        CardList hand = pPlayer->GetHand();
        pPlayer->DiscardFromHand( hand );
        pPlayer->DrawCardsToHand( 4 );

        Attack( pEngine, ATTACK_OTHERS );
        break;
        }
    default:
        // TODO: report error
        throw std::wstring( L"Error: MinionCard::OnActionPhase" );
        break;
    }
}

void MinionCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    if( pPlayer->HandSize() >= 5 )
    {
        CardList hand = pPlayer->GetHand();
        pPlayer->DiscardFromHand( hand );
        pPlayer->DrawCardsToHand( 4 );
    }
}

} // namespace Domlib