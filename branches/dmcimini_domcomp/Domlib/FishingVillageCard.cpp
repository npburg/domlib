#include "StdAfx.h"
#include "FishingVillageCard.h"

namespace Domlib
{

FishingVillageCard::FishingVillageCard( void )
    : Card( 
        L"Fishing Village",
        CARDID_FISHINGVILLAGE,
        CARDTYPE_ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

FishingVillageCard::~FishingVillageCard( void )
{
}

void FishingVillageCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusActions( 2 );
    pPlayer->PlusCoins( 1 );    
}
    
void FishingVillageCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusActions( 1 );
    pPlayer->PlusCoins( 1 );   
}

} // namespace Domlib