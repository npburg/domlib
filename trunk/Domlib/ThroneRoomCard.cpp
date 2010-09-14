#include "StdAfx.h"
#include "ThroneRoomCard.h"

namespace Domlib
{

ThroneRoomCard::ThroneRoomCard( void )
    : Card( 
        L"ThroneRoom",
        CARDID_THRONEROOM,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

ThroneRoomCard::~ThroneRoomCard( void )
{
}

void ThroneRoomCard::OnActionPhase( Engine* pEngine )
{
    // TODO: This needs to be implemented
    throw std::wstring( L"ThroneRoomCard::OnActionPhase - To be implemented..." );
}

} // namespace Domlib