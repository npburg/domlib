#include "StdAfx.h"
#include "MoatCard.h"

namespace Domlib
{

MoatCard::MoatCard( void )
    : Card( 
        L"Moat",
        CARDID::MOAT,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

MoatCard::~MoatCard( void )
{
}

void MoatCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 2 );
}

void MoatCard::OnReaction( Engine* pEngine )
{
    // No special actions during Reaction phase since this card only needs
    // be revealed during Attack phase for the reaction effect.
}

} // namespace Domlib