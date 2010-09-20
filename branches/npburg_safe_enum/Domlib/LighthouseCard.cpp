#include "StdAfx.h"
#include "LighthouseCard.h"

namespace Domlib
{

LighthouseCard::LighthouseCard( void )
    : Card( 
        L"Lighthouse",
        CARDID::LIGHTHOUSE,
        CARDTYPE::ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

LighthouseCard::~LighthouseCard( void )
{
}

void LighthouseCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusActions( 1 );
    pPlayer->PlusCoins( 1 );
}

void LighthouseCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 1 );
}


} // namespace Domlib