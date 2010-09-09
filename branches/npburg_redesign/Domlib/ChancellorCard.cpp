#include "StdAfx.h"
#include "ChancellorCard.h"

namespace Domlib
{

ChancellorCard::ChancellorCard( void )
    : Card( 
        L"Chancellor",
        CARDID_CHANCELLOR,
        CARDTYPE_ACTION,
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
    AI* pAi = pPlayer->GetAI();
    ChancellorOpt chancellorOpt;

    pPlayer->PlusCoins( 2 );
    chancellorOpt = pAi->OnChancellor();
    switch( chancellorOpt )
    {
    case CHANCELLOR_DISCARD_DRAW_DECK:
        pPlayer->DiscardDrawPile();
        break;
    case CHANCELLOR_NO_OP:
        // Do nothing
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: ChancellorCard::OnActionPhase" );
        break;
    }
}

} // namespace Domlib