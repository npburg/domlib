#include "StdAfx.h"
#include "ExplorerCard.h"

namespace Domlib
{

ExplorerCard::ExplorerCard( void )
    : Card( 
        L"Explorer",
        CARDID_EXPLORER,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

ExplorerCard::~ExplorerCard( void )
{
}

void ExplorerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    
    if( pPlayer->IsCardInHand( CARDID_PROVINCE ) )
    {
        ExplorerOpt explorerOpt = pAi->OnExplorer();
        switch( explorerOpt )
        {
        case Domlib::EXPLORER_REVEAL_PROVINCE:
            // TODO: reveal province
            pPlayer->GainCardInHand( CARDID_GOLD );
            break;
        case Domlib::EXPLORER_DO_NOT_REVEAL_PROVINCE:
            pPlayer->GainCardInHand( CARDID_SILVER );
            break;
        default:
            // TODO: report error
            throw std::wstring( L"Error: ExplorerCard::OnActionPhase." );
            break;
        }
    }
    else
    {
        pPlayer->GainCardInHand( CARDID_SILVER );
    }
}

} // namespace Domlib