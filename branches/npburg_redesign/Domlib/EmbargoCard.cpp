#include "StdAfx.h"
#include "EmbargoCard.h"

namespace Domlib
{

EmbargoCard::EmbargoCard( void )
    : Card( 
        L"Embargo",
        CARDID_EMBARGO,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

EmbargoCard::~EmbargoCard( void )
{
}

void EmbargoCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    
    pPlayer->PlusCoins( 2 );
    
    Card* pCard = pAi->OnEmbargo();
    pEngine->OnEmbargo( pCard );
}

void EmbargoCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->TakeCardFromInPlay( this );
    pEngine->PutCardInTrash( this );
}

} // namespace Domlib