#include "StdAfx.h"
#include "WitchCard.h"

namespace Domlib
{

WitchCard::WitchCard( void )
    : Card( 
        L"Witch",
        CARDID_WITCH,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

WitchCard::~WitchCard( void )
{
}

void WitchCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 2 );
    Attack( pEngine, ATTACK_OTHERS );
}

void WitchCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
	pPlayer->GainCardOnDiscard( CARDID_CURSE );
}

} // namespace Domlib