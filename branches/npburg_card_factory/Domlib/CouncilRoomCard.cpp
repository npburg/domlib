#include "StdAfx.h"
#include "CouncilRoomCard.h"

namespace Domlib
{

CouncilRoomCard::CouncilRoomCard( void )
    : Card( 
        L"Council Room",
        CARDID_COUNCILROOM,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

CouncilRoomCard::~CouncilRoomCard( void )
{
}

void CouncilRoomCard::OnActionPhase( Engine* pEngine )
{
    Player* pCurrentPlayer = pEngine->GetCurrentPlayer();
    Player* pNextPlayer = pEngine->GetNextPlayer( pCurrentPlayer );

    pCurrentPlayer->DrawCardsToHand( 4 );
    pCurrentPlayer->PlusBuys( 1 ) ;

    ActionForOthers( pEngine );
}

void CouncilRoomCard::OnActionPhaseOther( Engine* pEngine, Player* pPlayer )
{
    pPlayer->DrawCardsToHand( 1 ) ;
}

} // namespace Domlib