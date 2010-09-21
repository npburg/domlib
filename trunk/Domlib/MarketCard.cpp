#include "StdAfx.h"
#include "MarketCard.h"

namespace Domlib
{

MarketCard::MarketCard( void )
    : Card( 
        L"Market",
        CARDID::MARKET,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

MarketCard::~MarketCard( void )
{
}

void MarketCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 1 );
}

} // namespace Domlib