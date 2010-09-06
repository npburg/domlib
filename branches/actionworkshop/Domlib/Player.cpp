#include <algorithm>
#include "Player.h"
#include "Card.h"
#include "IPlayer.h"
#include "Turn.h"
#include "Game.h"

namespace Domlib
{

Player::Player( AI::IPlayer* pAICallback )
    :
    m_pPlayerAI( pAICallback )
{
    
}

Player::~Player( void )
{

}

void Player::GainCard( Card* card )
{
    m_DiscardPile.push_back( card );

    m_pPlayerAI->GainCard( card );
}

bool Player::DrawCard( void )
{
    bool success = true;

    if( IsDrawPileEmpty() )
    {
        if( IsDiscardPileEmpty() )
        {
            // Draw pile and discard pile empty
            // so unable to draw card.
            success = false;
        }
        else
        {
            ShuffleDiscardIntoDraw();
            
            success = DrawCard();
        }
    }
    else
    {
        Card* pCard = NULL;

        success = RemoveTopCardFromDrawPile( pCard );

        if( success )
        {
            AddCardToHand( pCard );
        }
    }

    return success;
}

Card* Player::TopCardOfDrawPile( void )
{
    return m_DrawPile.back();
}

bool Player::RemoveTopCardFromDrawPile( Card* &pCard )
{
    bool success = true;

    if( !IsDrawPileEmpty() )
    {
        pCard = TopCardOfDrawPile();

        m_DrawPile.pop_back();
    }

    return success;
}

void Player::AddCardToHand( Card* pCard )
{
    m_Hand.push_back( pCard );
}

void Player::ShuffleDiscardIntoDraw( void )
{
    if( !IsDiscardPileEmpty() )
    {
        m_DrawPile.insert(
            m_DrawPile.end(),
            m_DiscardPile.begin(),
            m_DiscardPile.end() );

        m_DiscardPile.clear();

        ShuffleDrawPile();
    }
}

int Player::VictoryPoints( void ) const
{
    int points = 0;

    // Discard
    CardContainer::const_iterator cardItr = m_DiscardPile.begin();
    while( cardItr != m_DiscardPile.end() )
    {
        Card* pCard = *cardItr;

        if( pCard->IsVictory() )
        {
            points += pCard->Worth();
        }

        cardItr++;
    }

    // Hand
    cardItr = m_Hand.begin();
    while( cardItr != m_Hand.end() )
    {
        Card* pCard = *cardItr;

        if( pCard->IsVictory() )
        {
            points += pCard->Worth();
        }

        cardItr++;
    }

    // DrawPile
    cardItr = m_DrawPile.begin();
    while( cardItr != m_DrawPile.end() )
    {
        Card* pCard = *cardItr;

        if( pCard->IsVictory() )
        {
            points += pCard->Worth();
        }

        cardItr++;
    }

    return points;
}

Card* Player::SelectCardToGain( const std::vector<Card*>& cards )
{
    Card* pSelectedCard = NULL;

    // Ask AI
    const std::vector<AI::IDomCard*>& pDomCards = 
         (std::vector<AI::IDomCard*>&)cards;
    CARDID selectedId = m_pPlayerAI->SelectCardToGain( pDomCards );

    // Validate and return selection
    if( selectedId != CARDID_UNKNOWN )
    {
        bool cardFound = false;
        std::vector<Card*>::const_iterator cardItr = cards.begin();
        while( cardItr != cards.end() && !cardFound )
        {
            Card* pCard = *cardItr;

            if( pCard->CardId() == selectedId )
            {
                pSelectedCard = pCard;

                cardFound = true;
            }

            cardItr++;
        }
    }

    return pSelectedCard;
}

bool Player::IsDiscardPileEmpty( void ) const
{
    return ( m_DiscardPile.size() == 0 );
}

bool Player::IsDrawPileEmpty( void ) const
{
    return ( m_DrawPile.size() == 0 );
}

void Player::ShuffleDrawPile( void )
{
    if( !IsDrawPileEmpty() )
    {
        std::random_shuffle( 
            m_DrawPile.begin(), 
            m_DrawPile.end() );
    }
}

bool Player::HasActionCardInHand( void ) const
{
    bool hasActionCard = false;

    std::vector<Card*>::const_iterator cardItr = m_Hand.begin();

    while( cardItr != m_Hand.end() && !hasActionCard )
    {
        hasActionCard = (*cardItr)->IsAction();

        cardItr++;
    }

    return hasActionCard;
}

void Player::SelectActionCardFromHandToPlay(
    Card* &pCard,
    bool& none )
{

}

bool Player::ContinueBuying(
    int buys )
{
    return m_pPlayerAI->ContinueBuying( buys );
}

CARDID Player::BuyCard( Turn* pTurn )
{
    CARDID id = CARDID_UNKNOWN;

    const int turnTreasure = pTurn->AvailableTreasure();

    int handTreasure = 0;

    CardContainer::iterator cardItr = m_Hand.begin();
    while( cardItr != m_Hand.end() )
    {
        Card* pCard = *cardItr;

        if( pCard->IsTreasure() )
        {
            handTreasure += pCard->Worth();
        }

        cardItr++;
    }

    int buyingPower = 
        turnTreasure + 
        handTreasure;

    if( buyingPower )
    {
        id = m_pPlayerAI->BuyCard( buyingPower );
    }

    return id;
}

void Player::DiscardHand( void )
{
    m_DiscardPile.insert(
        m_DiscardPile.end(),
        m_Hand.begin(),
        m_Hand.end() );

    m_Hand.clear();
}

}; // namespace Domlib
