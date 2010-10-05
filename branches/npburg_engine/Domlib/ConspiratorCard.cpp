#include "StdAfx.h"
#include "ConspiratorCard.h"

namespace Domlib
{

ConspiratorCard::ConspiratorCard( void )
    : Card( 
        L"Conspirator",
        CARDID::CONSPIRATOR,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

ConspiratorCard::~ConspiratorCard( void )
{
}

void ConspiratorCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusCoins( 2 );
    if( pPlayer->ActionsPlayed() >= 3 )
    {
        pPlayer->DrawCardsToHand( 1 ) ;
        pPlayer->PlusActions( 1 );
    }
}

} // namespace Domlib