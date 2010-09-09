#include "StdAfx.h"
#include "BridgeCard.h"

namespace Domlib
{

BridgeCard::BridgeCard( void )
    : Card( 
        L"Bridge",
        CARDID_BRIDGE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

BridgeCard::~BridgeCard( void )
{
}

void BridgeCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 1 );
    // TODO: should this set a flag or should this simply be "in-play" to 
    // affect the cost of cards. This depends on how Thone room is implemented.
    throw std::wstring( L"BridgeCard::OnActionPhase - To be implemented..." );
}

} // namespace Domlib