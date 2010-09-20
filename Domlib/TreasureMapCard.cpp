#include "StdAfx.h"
#include "TreasureMapCard.h"

namespace Domlib
{

TreasureMapCard::TreasureMapCard( void )
    : Card( 
        L"Treasure Map",
        CARDID::TREASUREMAP,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

TreasureMapCard::~TreasureMapCard( void )
{
}

void TreasureMapCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    if( pPlayer->IsCardInHand( this ) )
    {
        pPlayer->TrashFromHand( this );
        pPlayer->GainCardOnDeck( CARDID::GOLD );
        pPlayer->GainCardOnDeck( CARDID::GOLD );
        pPlayer->GainCardOnDeck( CARDID::GOLD );
        pPlayer->GainCardOnDeck( CARDID::GOLD );
    }
}

void TreasureMapCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->TrashFromInPlay( this );
}

} // namespace Domlib
