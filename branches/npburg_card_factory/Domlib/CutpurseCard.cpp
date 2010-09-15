#include "StdAfx.h"
#include "CutpurseCard.h"

namespace Domlib
{

CutpurseCard::CutpurseCard( void )
    : Card( 
        L"Cutpurse",
        CARDID_CUTPURSE,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

CutpurseCard::~CutpurseCard( void )
{
}

void CutpurseCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusCoins( 2 );
    Attack( pEngine, ATTACK_OTHERS );
}

void CutpurseCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    if( pPlayer->IsCardInHand( CARDID_COPPER ) )
    {
        pPlayer->DiscardFromHand( CARDID_COPPER );
    }
    else
    {
        // TODO: reveal cards
    }
}

} // namespace Domlib