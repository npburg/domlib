#include "StdAfx.h"
#include "MonumentCard.h"

namespace Domlib
{

MonumentCard::MonumentCard(void)
    : Card( 
        L"Monument",
        CARDID_MONUMENT,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

MonumentCard::~MonumentCard(void)
{
}

void MonumentCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 2 );
    pPlayer->PlusVictoryTokens( 1 );
}

} // namespace Domlib