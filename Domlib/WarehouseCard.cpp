#include "StdAfx.h"
#include "WarehouseCard.h"

namespace Domlib
{

WarehouseCard::WarehouseCard( void )
    : Card( 
        L"Warehouse",
        CARDID::WAREHOUSE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

WarehouseCard::~WarehouseCard( void )
{
}

void WarehouseCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    
    pPlayer->DrawCardsToHand( 3 );
    pPlayer->PlusActions( 1 );
    
    CardList cardList = pAI->OnWarehouse();
    if( cardList.size() == 3 &&
        pPlayer->AreCardsInHand( cardList ) )
    {
        pPlayer->DiscardFromHand( cardList );
    }
}

} // namespace Domlib