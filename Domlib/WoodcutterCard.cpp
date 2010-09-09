#include "StdAfx.h"
#include "WoodcutterCard.h"

namespace Domlib
{

WoodcutterCard::WoodcutterCard( void )
    : Card( 
        L"Woodcutter",
        CARDID_WOODCUTTER,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

WoodcutterCard::~WoodcutterCard( void )
{
}

void WoodcutterCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 2 );
}

} // namespace Domlib