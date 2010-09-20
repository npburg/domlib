#include "StdAfx.h"
#include "EstateCard.h"

namespace Domlib
{

EstateCard::EstateCard( void )
    : Card( 
        L"Estate",
        CARDID::ESTATE,
        CARDTYPE::VICTORY,
        1,
        Treasure( 2, 0 ),
        Treasure( 0, 0 ) )
{
}

EstateCard::~EstateCard( void )
{
}

} // namespace Domlib