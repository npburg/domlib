#include "StdAfx.h"
#include "SmithyCard.h"

namespace Domlib
{

SmithyCard::SmithyCard( void )
    : Card(
           L"Smithy",
           CARDID_SMITHY,
           CARDTYPE_ACTION,
           0,
           Treasure( 0, 0 ),
           Treasure( 4, 0 ) )
{
}

SmithyCard::~SmithyCard( void )
{
}

void SmithyCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 3 );
}

} // namespace Domlib