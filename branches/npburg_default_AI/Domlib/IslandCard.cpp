#include "StdAfx.h"
#include "IslandCard.h"

namespace Domlib
{

IslandCard::IslandCard( void )
    : Card( 
        L"Island",
        CARDID_ISLAND,
        CARDTYPE_ACTION_VICTORY,
        2,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

IslandCard::~IslandCard( void )
{
}

void IslandCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    Card* pCard = pAI->OnIsland();
    if( pPlayer->IsCardInHand( pCard ) )
    {
        pPlayer->TakeCardFromHand( pCard );
        pPlayer->PutCardOnIsland( pCard );
    }
    else if( pCard->IsNullCard() )
    {
        // Do nothing.
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: IslandCard::OnActionPhase" );
    }
    
    pPlayer->TakeCardFromInPlay( this );
    pPlayer->PutCardOnIsland( this );
}

} // namespace Domlib