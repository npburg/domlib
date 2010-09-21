#include "StdAfx.h"
#include "GrandMarketCard.h"

namespace Domlib
{

GrandMarketCard::GrandMarketCard(void)
    : Card( 
        L"Grand Market",
        CARDID::GRANDMARKET,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 6, 0 ) )
{
}

GrandMarketCard::~GrandMarketCard(void)
{
}

void GrandMarketCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 2 );    
}

} // namespace Domlib