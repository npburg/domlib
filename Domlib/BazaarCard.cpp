#include "StdAfx.h"
#include "BazaarCard.h"

namespace Domlib
{

BazaarCard::BazaarCard( void )
    : Card( 
        L"Bazaar",
        CARDID_BAZAAR,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

BazaarCard::~BazaarCard( void )
{
}

void BazaarCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 2 );
    pPlayer->PlusCoins( 1 );
}

} // namespace Domlib