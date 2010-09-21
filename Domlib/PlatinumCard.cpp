#include "StdAfx.h"
#include "PlatinumCard.h"

namespace Domlib
{

PlatinumCard::PlatinumCard(void)
    : Card( 
        L"Platinum",
        CARDID::PLATINUM,
        CARDTYPE::VICTORY,
        10,
        Treasure( 0, 0 ),
        Treasure( 11, 0 ) )
{
}

PlatinumCard::~PlatinumCard(void)
{
}

} // namespace Domlib