#include "StdAfx.h"
#include "VentureCard.h"

namespace Domlib
{

VentureCard::VentureCard(void)
    : Card( 
        L"Venture",
        CARDID::VENTURE,
        CARDTYPE::TREASURE,
        0,
        Treasure( 1, 0 ),
        Treasure( 5, 0 ) )
{
}

VentureCard::~VentureCard(void)
{
}

Treasure VentureCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    CardList revealedCards;
    Card* pRevealedCard = Card::GetCard( CARDID::NULLCARD );
    
    do
    {
        pRevealedCard = pPlayer->RevealCardFromDeck();
        if( pRevealedCard->IsTreasureCard() )
        {
            pPlayer->PutCardInPlay( pRevealedCard );
            pRevealedCard->OnTreasurePhase( pEngine );
            break;
        }
        revealedCards.push_back( pRevealedCard );
    }
    while( !pRevealedCard->IsNullCard() );
    
    
    return m_TreasureValue;
}

} // namespace Domlib