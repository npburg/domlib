#include "StdAfx.h"
#include "OutpostCard.h"

namespace Domlib
{

OutpostCard::OutpostCard( void )
    : Card( 
        L"Outpost",
        CARDID::OUTPOST,
        CARDTYPE::ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

OutpostCard::~OutpostCard( void )
{
}

void OutpostCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    if( !pPlayer->IsCardInDuration( this ) )
    {
        pEngine->SetOutpostFlag( true );
    }
}

void OutpostCard::OnDurationPhase( Engine* pEngine )
{
    pEngine->SetOutpostFlag( false );
}

} // namespace Domlib