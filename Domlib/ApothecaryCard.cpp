#include "StdAfx.h"
#include "ApothecaryCard.h"

namespace Domlib
{

ApothecaryCard::ApothecaryCard( void )
    : Card( 
        L"Apothecary",
        CARDID_APOTHECARY,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 1 ) )
{
}

ApothecaryCard::~ApothecaryCard( void )
{
}

void ApothecaryCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    AI* pAi = pPlayer->GetAI();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );

    ICardList revealedCardList = 
        pPlayer->RevealCardsFromDeck( 4 );
    ICardListIter cardIter;

    for( cardIter = revealedCardList.begin();
         cardIter != revealedCardList.end();
         cardIter++ )
    {
        ICard* pCardInList = *cardIter;

        if( pCardInList->CardId() == CARDID_COPPER ||
            pCardInList->CardId() == CARDID_POTION )
        {
            pPlayer->PutCardInHand( pCardInList );
            revealedCardList.erase( cardIter );
        }
    }
    
    ICardList reorderedCardList = 
        pAi->OnReturnToDrawPile( revealedCardList );

    if( Card::CardListsMatch( revealedCardList, reorderedCardList ) )
    {
        pPlayer->PutCardsOnDraw( reorderedCardList );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: ScoutCard::OnActionPhase" );
    }
}

} // namespace Domlib