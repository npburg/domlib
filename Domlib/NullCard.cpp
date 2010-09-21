#include "StdAfx.h"
#include "NullCard.h"

namespace Domlib
{

NullCard::NullCard( void )
    : Card(  
        L"NULL",
        CARDID::NULLCARD,
        CARDTYPE::NULLCARD,
        0,
        Treasure( 0, 0 ),
        Treasure( 0, 0 ) )
{
}

NullCard::~NullCard( void )
{
}

} // namespace Domlib