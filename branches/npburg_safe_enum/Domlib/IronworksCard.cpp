#include "StdAfx.h"
#include "IronworksCard.h"

namespace Domlib
{

IronworksCard::IronworksCard( void )
    : Card( 
        L"Ironworks",
        CARDID::IRONWORKS,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

IronworksCard::~IronworksCard( void )
{
}

void IronworksCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    // The interface for OnGainACard needs to be clarified.
    // Does the function get the card from supply and put it into
    // the discard pile?
    throw std::wstring( L"IronworksCard::OnActionPhase - To be implemented..." );

    Card* pCardGained = pPlayer->OnGainACard( &Treasure( 4, 0 ) );

    if( pCardGained->IsActionCard() )
    {
        pPlayer->PlusActions( 1 );
    }

    if( pCardGained->IsTreasureCard() )
    {
        pPlayer->PlusCoins( 1 );
    }

    if( pCardGained->IsVictoryCard() )
    {
        pPlayer->DrawCardsToHand( 1 );
    }
}

} // namespace Domlib