#include "StdAfx.h"
#include "HaremCard.h"

namespace Domlib
{

HaremCard::HaremCard( void )
    : Card( 
        L"Harem",
        CARDID_HAREM,
        CARDTYPE_TREASURE_VICTORY,
        2,
        Treasure( 2, 0 ),
        Treasure( 6, 0 ) )
{
}

HaremCard::~HaremCard( void )
{
}

} // namespace Domlib