#include "StdAfx.h"
#include "GoldCard.h"

namespace Domlib
{

GoldCard::GoldCard( void )
    : Card( 
        L"Gold",
        CARDID_GOLD,
        CARDTYPE_TREASURE,
        0,
        Treasure( 3, 0 ),
        Treasure( 6, 0 ) )
{
}

GoldCard::~GoldCard( void )
{
}

} // namespace Domlib