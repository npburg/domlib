#include "StdAfx.h"
#include "NullCard.h"

namespace Domlib
{

NullCard::NullCard( void )
    : Card(  
        L"NULL",
        CARDID_NULL,
        CARDTYPE_NULL,
        0,
        Treasure( 0, 0 ),
        Treasure( 0, 0 ) )
{
}

NullCard::~NullCard( void )
{
}

} // namespace Domlib