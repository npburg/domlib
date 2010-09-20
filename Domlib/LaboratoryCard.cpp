#include "StdAfx.h"
#include "LaboratoryCard.h"

namespace Domlib
{

LaboratoryCard::LaboratoryCard( void )
    : Card( 
        L"Laboratory",
        CARDID::LABORATORY,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

LaboratoryCard::~LaboratoryCard( void )
{
}

void LaboratoryCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 2 );
    pPlayer->PlusActions( 1 );
}

} // namespace Domlib