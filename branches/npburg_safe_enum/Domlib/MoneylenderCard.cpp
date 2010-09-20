#include "StdAfx.h"
#include "MoneylenderCard.h"

namespace Domlib
{

MoneylenderCard::MoneylenderCard( void )
    : Card(
           L"Moneylender",
           CARDID::MONEYLENDER,
           CARDTYPE::ACTION,
           0,
           Treasure( 0, 0 ),
           Treasure( 4, 0 ) )
{
}

MoneylenderCard::~MoneylenderCard( void )
{
}

void MoneylenderCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    if( pPlayer->IsCardInHand( CARDID::COPPER ) )
    {
        pPlayer->TrashFromHand( CARDID::COPPER );
        pPlayer->PlusCoins( 3 );
    }
}

} // namespace Domlib