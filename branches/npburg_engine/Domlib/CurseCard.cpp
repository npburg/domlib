#include "StdAfx.h"
#include "CurseCard.h"

namespace Domlib
{

CurseCard::CurseCard( void )
    : Card( 
        L"Curse",
        CARDID::CURSE,
        CARDTYPE::CURSE,
        -1,
        Treasure( 0, 0 ),
        Treasure( 0, 0 ) )
{
}

CurseCard::~CurseCard( void )
{
}

} // namespace Domlib