#include "StdAfx.h"
#include "PossessionCard.h"

namespace Domlib
{

PossessionCard::PossessionCard( void )
    : Card( 
        L"Possession",
        CARDID_POSSESSION,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 6, 1 ) )
{
}

PossessionCard::~PossessionCard( void )
{
}

void PossessionCard::OnActionPhase( Engine* pEngine )
{
    // TODO: figure out how to implement this card.
    throw std::wstring( L"PossessionCard::OnActionPhase - To be implemented..." );
}

} // namespace Domlib