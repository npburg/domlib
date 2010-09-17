#include "StdAfx.h"
#include "MerchantShipCard.h"

namespace Domlib
{

MerchantShipCard::MerchantShipCard( void )
    : Card( 
        L"Merchant Ship",
        CARDID_MERCHANTSHIP,
        CARDTYPE_ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

MerchantShipCard::~MerchantShipCard( void )
{
}

void MerchantShipCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 2 );
}

void MerchantShipCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 2 );
}

} // namespace Domlib