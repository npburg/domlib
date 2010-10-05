#include "StdAfx.h"
#include "MountebankCard.h"

namespace Domlib
{

MountebankCard::MountebankCard(void)
    : Card( 
        L"Mountebank",
        CARDID::MOUNTEBANK,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

MountebankCard::~MountebankCard(void)
{
}

void MountebankCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 2 );
    
    Attack( pEngine, AttackWhom::OTHERS );
}

void MountebankCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    if( pPlayer->IsCardInHand( CARDID::CURSE ) )
    {
        IAI* pAI = pPlayer->GetAI();
        MountebankOpt mountebankOpt = pAI->OnMountebank();
        
        switch( mountebankOpt )
        {
        case Domlib::MountebankOpt::DISCARD_CURSE:
            pPlayer->DiscardFromHand( CARDID::CURSE );
            break;
        case Domlib::MountebankOpt::DO_NOT_DISCARD_CURSE:
            pPlayer->GainCardOnDiscard( CARDID::CURSE );
            pPlayer->GainCardOnDiscard( CARDID::COPPER );
            break;
        default:
            // TODO: report error.
            throw std::wstring( L"Error: MountebankCard::OnAttack" );
            break;
        }
    }
    else
    {
        pPlayer->GainCardOnDiscard( CARDID::CURSE );
        pPlayer->GainCardOnDiscard( CARDID::COPPER );
    }
}

} // namespace Domlib