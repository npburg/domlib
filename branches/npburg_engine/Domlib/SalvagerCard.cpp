#include "StdAfx.h"
#include "SalvagerCard.h"

namespace Domlib
{

SalvagerCard::SalvagerCard( void )
    : Card( 
        L"Salvager",
        CARDID::SALVAGER,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

SalvagerCard::~SalvagerCard( void )
{
}

void SalvagerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    
    pPlayer->PlusBuys( 1 );
    Card* pCard = pAI->OnSalvager();
    // TODO: Check if NullCard returns true for an empty hand 
    //otherwise need to check for empty hand and null card returned.

    if( pPlayer->IsCardInHand( pCard ) )
    {
        pPlayer->TrashFromHand( pCard );
        pPlayer->PlusCoins( pCard->Cost( pEngine ).Coins() );
    }
}

} // namespace Domlib