#include "StdAfx.h"
#include "PhilosophersStoneCard.h"

namespace Domlib
{

PhilosophersStoneCard::PhilosophersStoneCard( void )
    : Card( 
        L"Philosopher's Stone",
        CARDID::PHILOSOPHERSSTONE,
        CARDTYPE::TREASURE,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 1 ) )
{
}

PhilosophersStoneCard::~PhilosophersStoneCard( void )
{
}

Treasure PhilosophersStoneCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numCardsInDraw = pPlayer->DrawSize();
    int numCardsInDiscard = pPlayer->DiscardSize();
    return Treasure( (int)( ( numCardsInDraw + numCardsInDiscard ) / 5 ), 0 );
}

} // namespace Domlib