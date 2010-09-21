#include "StdAfx.h"
#include "ShantyTownCard.h"

namespace Domlib
{

ShantyTownCard::ShantyTownCard( void )
    : Card( 
        L"Shanty Town",
        CARDID::SHANTYTOWN,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

ShantyTownCard::~ShantyTownCard( void )
{
}

void ShantyTownCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusActions( 2 );
    pPlayer->RevealHand();
    if( pPlayer->GetCardCountInHandType( CARDTYPE::ACTION ) == 0 )
    {
        pPlayer->DrawCardsToHand( 2 );
    }
}

} // namespace Domlib