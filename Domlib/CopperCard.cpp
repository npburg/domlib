#include "StdAfx.h"
#include "CopperCard.h"

namespace Domlib
{

CopperCard::CopperCard( void )
    : Card( 
        L"Copper",
        CARDID::COPPER,
        CARDTYPE::TREASURE,
        0,
        Treasure( 1, 0 ),
        Treasure( 0, 0 ) )
{
}

CopperCard::~CopperCard( void )
{
}

} // namespace Domlib