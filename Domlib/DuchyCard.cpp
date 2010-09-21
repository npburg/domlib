#include "StdAfx.h"
#include "DuchyCard.h"

namespace Domlib
{

DuchyCard::DuchyCard( void )
    : Card( 
        L"Duchy",
        CARDID::DUCHY,
        CARDTYPE::VICTORY,
        3,
        Treasure( 5, 0 ),
        Treasure( 0, 0 ) )
{
}

DuchyCard::~DuchyCard( void )
{
}

} // namespace Domlib