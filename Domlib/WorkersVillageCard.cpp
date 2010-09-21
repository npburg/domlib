#include "StdAfx.h"
#include "WorkersVillageCard.h"

namespace Domlib
{

WorkersVillageCard::WorkersVillageCard(void)
    : Card( 
        L"Worker's Village",
        CARDID::WORKERSVILLAGE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

WorkersVillageCard::~WorkersVillageCard(void)
{
}

void WorkersVillageCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 2 );
    pPlayer->PlusBuys( 1 );
}

} // namespace Domlib