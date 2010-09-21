#include "StdAfx.h"
#include "ColonyCard.h"

namespace Domlib
{

ColonyCard::ColonyCard(void)
    : Card( 
        L"Colony",
        CARDID::COLONY,
        CARDTYPE::VICTORY,
        10,
        Treasure( 0, 0 ),
        Treasure( 11, 0 ) )
{
}

ColonyCard::~ColonyCard(void)
{
}

} // namespace Domlib