#include "StdAfx.h"
#include "ScoutCard.h"

namespace Domlib
{

ScoutCard::ScoutCard( void )
    : Card( 
        L"Scout",
        CARDID::SCOUT,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

ScoutCard::~ScoutCard( void )
{
}

void ScoutCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusActions( 1 );
    
    IAI* pAI = pPlayer->GetAI();
    CardList revealedCardList = 
        pPlayer->RevealCardsFromDeck( 4 );
    CardList reorderedCardList = 
        pAI->OnReturnToDrawPile( revealedCardList );

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