#include "StdAfx.h"
#include "EmbargoCard.h"

namespace Domlib
{

EmbargoCard::EmbargoCard( void )
    : Card( 
        L"Embargo",
        CARDID::EMBARGO,
        CARDTYPE::ACTION,
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
    IAI* pAI = pPlayer->GetAI();
    
    pPlayer->PlusCoins( 2 );
    
    Card* pCard = pAI->OnEmbargo();
    pEngine->OnEmbargo( pCard );
}

void EmbargoCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->TakeCardFromInPlay( this );
    pEngine->PutCardInTrash( this );
}

} // namespace Domlib