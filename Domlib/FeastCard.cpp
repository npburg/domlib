#include "StdAfx.h"
#include "FeastCard.h"

namespace Domlib
{

FeastCard::FeastCard( void )
    : Card( 
        L"Feast",
        CARDID::FEAST,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

FeastCard::~FeastCard( void )
{
}

void FeastCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->OnGainACard( &Treasure( 5, 0 ) );

}

void FeastCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->TrashFromInPlay( CARDID::FEAST );
}

} // namespace Domlib