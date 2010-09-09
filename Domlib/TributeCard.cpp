#include "StdAfx.h"
#include "TributeCard.h"

namespace Domlib
{

TributeCard::TributeCard( void )
    : Card( 
        L"Tribute",
        CARDID_TRIBUTE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

TributeCard::~TributeCard( void )
{
}

void TributeCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    Player* pPlayerToLeft = pEngine->GetNextPlayer( pPlayer );
    ICardList cardsDrawnList = 
        pPlayerToLeft->RevealCardsFromDeck( 2 );
    ICardListIter cardIter;

    ICard* pFirstCard = *cardIter;

    if( pFirstCard->IsActionCard() )
    {
        pPlayer->PlusActions( 2 );
    }

    if( pFirstCard->IsTreasureCard() )
    {
        pPlayer->PlusCoins( 2 );
    }

    if( pFirstCard->IsVictoryCard() )
    {
        pPlayer->DrawCardsToHand( 2 );
    }

    cardIter++;
    ICard* pSecondCard = *cardIter;
    
    if( pSecondCard->CardId() != pFirstCard->CardId() )
    {
        if( pSecondCard->IsActionCard() )
        {
            pPlayer->PlusActions( 2 );
        }

        if( pSecondCard->IsTreasureCard() )
        {
            pPlayer->PlusCoins( 2 );
        }

        if( pSecondCard->IsVictoryCard() )
        {
            pPlayer->DrawCardsToHand( 2 );
        }
    }

}

} // namespace Domlib