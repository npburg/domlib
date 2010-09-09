#include "StdAfx.h"
#include "CoppersmithCard.h"

namespace Domlib
{

CoppersmithCard::CoppersmithCard( void )
    : Card( 
        L"Coppersmith",
        CARDID_COPPERSMITH,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

CoppersmithCard::~CoppersmithCard( void )
{
}

void CoppersmithCard::OnActionPhase( Engine* pEngine )
{
    // TODO: It might be enough for this card to be in the "in-play" list;
    // however, it depends on how Throne Room is implemented.
    throw std::wstring( L"CoppersmithCard::OnActionPhase - To be implemented..." );
}

} // namespace Domlib