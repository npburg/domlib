#include "StdAfx.h"
#include "MinionCard.h"

namespace Domlib
{

MinionCard::MinionCard( void )
    : Card( 
        L"Minion",
        CARDID::MINION,
        CARDTYPE::ACTION_ATTACK,
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
    IAI* pAI = pPlayer->GetAI();

    pPlayer->PlusActions( 1 );

    MinionOpt minionOpt = pAI->OnMinion();
    switch( minionOpt )
    {
    case MinionOpt::PLUS_2_COINS:
        pPlayer->PlusCoins( 2 );
        break;
    case MinionOpt::DISCARD_HAND:
        {
        pPlayer->DiscardHand();
        pPlayer->DrawCardsToHand( 4 );

        Attack( pEngine, AttackWhom::OTHERS );
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
    if( pPlayer->CardsInHand() >= 5 )
    {
        CardList hand = pPlayer->GetHand();
        pPlayer->DiscardFromHand( hand );
        pPlayer->DrawCardsToHand( 4 );
    }
}

} // namespace Domlib