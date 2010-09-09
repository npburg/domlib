#include "StdAfx.h"
#include "VillageCard.h"

namespace Domlib
{

VillageCard::VillageCard( void )
    : Card( 
        L"Village",
        CARDID_VILLAGE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

VillageCard::~VillageCard( void )
{
}

void VillageCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 2 );
}

} // namespace Domlib