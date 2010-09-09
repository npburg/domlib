#include "StdAfx.h"
#include "MoneylenderCard.h"

namespace Domlib
{

MoneylenderCard::MoneylenderCard( void )
    : Card(
           L"Moneylender",
           CARDID_MONEYLENDER,
           CARDTYPE_ACTION,
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

    if( pPlayer->IsCardInHand( CARDID_COPPER ) )
    {
        pPlayer->TrashFromHand( CARDID_COPPER );
        pPlayer->PlusCoins( 3 );
    }
}

} // namespace Domlib