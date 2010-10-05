#include "StdAfx.h"
#include "CityCard.h"

namespace Domlib
{

CityCard::CityCard(void)
    : Card( 
        L"City",
        CARDID::CITY,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

CityCard::~CityCard(void)
{
}

void CityCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 2 );
    
    if( pEngine->SupplyPilesEmpty() >= 1 )
    {
        pPlayer->DrawCardsToHand( 1 );
    }
    
    if( pEngine->SupplyPilesEmpty() >= 2 )
    {
        pPlayer->PlusCoins( 1 );
        pPlayer->PlusBuys( 1 );
    }
}

} // namespace Domlib