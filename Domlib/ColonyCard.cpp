#include "StdAfx.h"
#include "ColonyCard.h"

namespace Domlib
{

ColonyCard::ColonyCard(void)
    : Card( 
        L"Colony",
        CARDID_COLONY,
        CARDTYPE_VICTORY,
        10,
        Treasure( 0, 0 ),
        Treasure( 11, 0 ) )
{
}

ColonyCard::~ColonyCard(void)
{
}

} // namespace Domlib