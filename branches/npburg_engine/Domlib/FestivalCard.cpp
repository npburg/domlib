#include "StdAfx.h"
#include "FestivalCard.h"

namespace Domlib
{

FestivalCard::FestivalCard( void )
    : Card( 
        L"Festival",
        CARDID::FESTIVAL,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

FestivalCard::~FestivalCard( void )
{
}

void FestivalCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusActions( 2 );
    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 2 );
}

} // namespace Domlib