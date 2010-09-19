#include "StdAfx.h"
#include "TacticianCard.h"

namespace Domlib
{

TacticianCard::TacticianCard( void )
    : Card( 
        L"Tactician",
        CARDID_TACTICIAN,
        CARDTYPE_ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

TacticianCard::~TacticianCard( void )
{
}

void TacticianCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    if( pPlayer->CardsInHand() > 0 )
    {
        pPlayer->SetTacticianFlag( true );
        pPlayer->DiscardHand();
    }
}

void TacticianCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    if( pPlayer->TacticianFlag() )
    {
        pPlayer->DrawCardsToHand( 5 );
        pPlayer->PlusActions( 1 );
        pPlayer->PlusBuys( 1 );
        pPlayer->SetTacticianFlag( false );
    }
}

} // namespace Domlib