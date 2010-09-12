#include "StdAfx.h"
#include "RabbleCard.h"

namespace Domlib
{

RabbleCard::RabbleCard(void)
    : Card( 
        L"Rabble",
        CARDID_RABBLE,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

RabbleCard::~RabbleCard(void)
{
}

void RabbleCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 3 );
    Attack( pEngine, ATTACK_OTHERS );
}

void RabbleCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    CardList revealedCards = pPlayer->RevealCardsFromDeck( 3 );
    
    for( CardListIter iter = revealedCards.begin();
         iter != revealedCards.end();
         iter++ )
    {
        if( (*iter)->IsActionCard() ||
            (*iter)->IsTreasureCard() )
        {
            pPlayer->PutCardInDiscard( (*iter) );
            revealedCards.erase( iter );
        }
    }
    
    if( revealedCards.size() )
    {
        IAI* pAI = pPlayer->GetAI();
        CardList reorderedCards = pAI->OnReturnToDrawPile( revealedCards );
        
        pPlayer->PutCardsOnDraw( reorderedCards );
    }
}

} // namespace Domlib