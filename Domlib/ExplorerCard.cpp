#include "StdAfx.h"
#include "ExplorerCard.h"

namespace Domlib
{

ExplorerCard::ExplorerCard( void )
    : Card( 
        L"Explorer",
        CARDID::EXPLORER,
        CARDTYPE::ACTION,
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
    IAI* pAI = pPlayer->GetAI();
    
    if( pPlayer->IsCardInHand( CARDID::PROVINCE ) )
    {
        ExplorerOpt explorerOpt = pAI->OnExplorer();
        switch( explorerOpt )
        {
        case Domlib::ExplorerOpt::REVEAL_PROVINCE:
            // TODO: reveal province
            pPlayer->GainCardInHand( CARDID::GOLD );
            break;
        case Domlib::ExplorerOpt::DO_NOT_REVEAL_PROVINCE:
            pPlayer->GainCardInHand( CARDID::SILVER );
            break;
        default:
            // TODO: report error
            throw std::wstring( L"Error: ExplorerCard::OnActionPhase." );
            break;
        }
    }
    else
    {
        pPlayer->GainCardInHand( CARDID::SILVER );
    }
}

} // namespace Domlib