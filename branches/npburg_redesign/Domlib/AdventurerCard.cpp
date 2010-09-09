#include "StdAfx.h"
#include "AdventurerCard.h"

namespace Domlib
{

AdventurerCard::AdventurerCard( void )
    : Card( 
        L"Adventurer",
        CARDID_ADVENTURER,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 6, 0 ) )
{
}

AdventurerCard::~AdventurerCard( void )
{
}

void AdventurerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int treasureCardsFound = 0;
    ICard* pCardRevealed;
    ICardList revealedCardList;

    do
    {
        pCardRevealed = pPlayer->RevealCardFromDeck();
        if( pCardRevealed->IsTreasureCard() )
        {
            treasureCardsFound++;
            pPlayer->GainCardInHand( pCardRevealed );
        }
        else 
        {
            if( pCardRevealed->IsNullCard() )
            {
                break;
            }
            revealedCardList.push_back( pCardRevealed );
        }
    }
    while( treasureCardsFound < 2 );
    
    pPlayer->PutCardsInDiscard( revealedCardList );
}

} // namespace Domlib