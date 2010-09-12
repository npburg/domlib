#include "StdAfx.h"
#include "CaravanCard.h"

namespace Domlib
{

CaravanCard::CaravanCard( void )
    : Card( 
        L"Caravan",
        CARDID_CARAVAN,
        CARDTYPE_ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

CaravanCard::~CaravanCard( void )
{
}

void CaravanCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
}

void CaravanCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
}

} // namespace Domlib