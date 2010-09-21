#include "StdAfx.h"
#include "SilverCard.h"

namespace Domlib
{

SilverCard::SilverCard( void )
    : Card( 
        L"Silver",
        CARDID::SILVER,
        CARDTYPE::TREASURE,
        0,
        Treasure( 2, 0 ),
        Treasure( 3, 0 ) )
{
}

SilverCard::~SilverCard( void )
{
}

} // namespace Domlib