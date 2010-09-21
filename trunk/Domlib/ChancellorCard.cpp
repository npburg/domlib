#include "StdAfx.h"
#include "ChancellorCard.h"

namespace Domlib
{

ChancellorCard::ChancellorCard( void )
    : Card( 
        L"Chancellor",
        CARDID::CHANCELLOR,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

ChancellorCard::~ChancellorCard( void )
{
}

void ChancellorCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    ChancellorOpt chancellorOpt;

    pPlayer->PlusCoins( 2 );
    chancellorOpt = pAI->OnChancellor();
    switch( chancellorOpt )
    {
    case ChancellorOpt::DISCARD_DRAW_DECK:
        pPlayer->DiscardDrawPile();
        break;
    case ChancellorOpt::NO_OP:
        // Do nothing
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: ChancellorCard::OnActionPhase" );
        break;
    }
}

} // namespace Domlib