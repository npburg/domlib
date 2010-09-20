#include "StdAfx.h"
#include "FamiliarCard.h"

namespace Domlib
{

FamiliarCard::FamiliarCard( void )
    : Card( 
        L"Familiar",
        CARDID::FAMILIAR,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 1 ) )
{
}

FamiliarCard::~FamiliarCard( void )
{
}

void FamiliarCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );

    Attack( pEngine, AttackWhom::OTHERS );
}

void FamiliarCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    pPlayer->GainCardOnDiscard( CARDID::CURSE );
}

} // namespace Domlib