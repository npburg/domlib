#include "StdAfx.h"
#include "WharfCard.h"

namespace Domlib
{

WharfCard::WharfCard( void )
    : Card( 
        L"Wharf",
        CARDID::WHARF,
        CARDTYPE::ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

WharfCard::~WharfCard( void )
{
}

void WharfCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 2 );
    pPlayer->PlusBuys( 1 );
}

void WharfCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 2 );
    pPlayer->PlusBuys( 1 );
}


} // namespace Domlib