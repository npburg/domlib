#include "StdAfx.h"
#include "WorkshopCard.h"

namespace Domlib
{

WorkshopCard::WorkshopCard( void )
    : Card( 
        L"Workshop",
        CARDID_WORKSHOP,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

WorkshopCard::~WorkshopCard( void )
{
}

void WorkshopCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->OnGainACard( &Treasure( 4, 0 ) );
}

} // namespace Domlib