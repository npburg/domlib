#include "StdAfx.h"
#include "ProvinceCard.h"

namespace Domlib
{

ProvinceCard::ProvinceCard( void )
    : Card( 
        L"Province",
        CARDID::PROVINCE,
        CARDTYPE::VICTORY,
        6,
        Treasure( 8, 0 ),
        Treasure( 0, 0 ) )
{
}

ProvinceCard::~ProvinceCard( void )
{
}

} // namespace Domlib