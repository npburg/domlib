#include "StdAfx.h"
#include "SeaHagCard.h"

namespace Domlib
{

SeaHagCard::SeaHagCard( void )
    : Card( 
        L"SeaHag",
        CARDID::SEAHAG,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

SeaHagCard::~SeaHagCard( void )
{
}


void SeaHagCard::OnActionPhase( Engine* pEngine )
{
    Attack( pEngine, AttackWhom::OTHERS );
}


void SeaHagCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    pPlayer->DiscardFromDraw( 1 );
    pPlayer->GainCardOnDeck( CARDID::CURSE );
}

} // namespace Domlib