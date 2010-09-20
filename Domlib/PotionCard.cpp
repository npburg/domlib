#include "StdAfx.h"
#include "PotionCard.h"

namespace Domlib
{

PotionCard::PotionCard( void )
    : Card( 
        L"Potion",
        CARDID::POTION,
        CARDTYPE::TREASURE,
        0,
        Treasure( 0, 1 ),
        Treasure( 4, 0 ) )
{
}

PotionCard::~PotionCard( void )
{
}

} // namespace Domlib