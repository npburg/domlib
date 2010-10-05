#include "StdAfx.h"
#include "GreatHallCard.h"

namespace Domlib
{

GreatHallCard::GreatHallCard( void )
    : Card( 
        L"Great Hall",
        CARDID::GREATHALL,
        CARDTYPE::ACTION_VICTORY,
        1,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

GreatHallCard::~GreatHallCard( void )
{
}

void GreatHallCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
}

} // namespace Domlib