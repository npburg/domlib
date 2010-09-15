#include "StdAfx.h"
#include "KingsCourtCard.h"

namespace Domlib
{

KingsCourtCard::KingsCourtCard(void)
    : Card( 
        L"King's Court",
        CARDID_KINGSCOURT,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 7, 0 ) )
{
}

KingsCourtCard::~KingsCourtCard(void)
{
}

void KingsCourtCard::OnActionPhase( Engine* pEngine )
{
    // TODO: This needs to be implemented
    throw std::wstring( L"KingsCourtCard::OnActionPhase - To be implemented..." );
}

} // namespace Domlib