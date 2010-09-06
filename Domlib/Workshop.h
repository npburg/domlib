#pragma once

#include "Card.h"
#include "Game.h"
#include "Player.h"

namespace Domlib
{

class Turn;

class Workshop
    :
    public Card
{
public:

    Workshop( void )
        :
        Card( CARDID_WORKSHOP, true, false, false, 3, 0 )
    {
    }

    virtual ~Workshop( void )
    {
    }

    virtual void Execute(
        Game* pGame,
        Turn* pTurn,
        Player* pPlayer )
    {
        // Get available cards from the piles
        std::vector<Card*> cards;
        pGame->GetAvailableCards( cards );

        // Filter cards the player cannot buy
        std::vector<Card*> filteredCards;
        std::vector<Card*>::iterator cardItr = cards.begin();
        while( cardItr != cards.end() )
        {
            Card* pCard = *cardItr;

            if( pCard->Cost() <= 4 )
            {
                filteredCards.push_back( pCard );
            }

            cardItr++;
        }

        // Ask the player
        Card* pNewCard = pPlayer->SelectCardToGain( filteredCards );

        // Give the player the card
        if( pNewCard )
        {
            pPlayer->GainCard( pNewCard );
        }
    }

};

}; // namespace Domlib