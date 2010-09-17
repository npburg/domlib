#include "StdAfx.h"
#include "MountebankCard.h"

namespace Domlib
{

MountebankCard::MountebankCard(void)
    : Card( 
        L"Mountebank",
        CARDID_MOUNTEBANK,
        CARDTYPE_ACTION_ATTACK,
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
    
    Attack( pEngine, ATTACK_OTHERS );
}

void MountebankCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    if( pPlayer->IsCardInHand( CARDID_CURSE ) )
    {
        IAI* pAI = pPlayer->GetAI();
        MountebankOpt mountebankOpt = pAI->OnMountebank();
        
        switch( mountebankOpt )
        {
        case Domlib::MOUNTEBANK_DISCARD_CURSE:
            pPlayer->DiscardFromHand( CARDID_CURSE );
            break;
        case Domlib::MOUNTEBANK_DO_NOT_DISCARD_CURSE:
            pPlayer->GainCardOnDiscard( CARDID_CURSE );
            pPlayer->GainCardOnDiscard( CARDID_COPPER );
            break;
        default:
            // TODO: report error.
            throw std::wstring( L"Error: MountebankCard::OnAttack" );
            break;
        }
    }
    else
    {
        pPlayer->GainCardOnDiscard( CARDID_CURSE );
        pPlayer->GainCardOnDiscard( CARDID_COPPER );
    }
}

} // namespace Domlib