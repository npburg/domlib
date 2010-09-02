#pragma once

#include <vector>

namespace Domlib
{

class Card;
class Turn;
enum CARDID;

namespace AI
{
    class IPlayer;
}

class Player
{
public:

    Player( AI::IPlayer* pAICallback );

    virtual ~Player( void );

    void    GainCard( Card* card );

    bool    DrawCard( void );

    void    ShuffleDiscardIntoDraw( void );

    int     VictoryPoints( void ) const;

    // ActionPhase
    bool    HasActionCardInHand( void ) const;

    virtual void    SelectActionCardFromHandToPlay(
                Card* &pCard,
                bool& none );

    // BuyPhase
    bool    ContinueBuying( int buys );

    CARDID  BuyCard( Turn* pTurn );

    // CleanupPhase
    void    DiscardHand( void );

protected:

    // Draw Pile Functions
    Card*       TopCardOfDrawPile( void );

    bool        RemoveTopCardFromDrawPile( Card* &pCard );

    inline bool IsDrawPileEmpty( void ) const;

    void        ShuffleDrawPile( void );

    // Discard Pile Functions
    inline bool IsDiscardPileEmpty( void ) const;

    // Hand Functions
    void        AddCardToHand( Card* pCard );

private:

    typedef std::vector<Card*>  CardContainer;

    CardContainer   m_DiscardPile;
    CardContainer   m_DrawPile;
    CardContainer   m_Hand;

    AI::IPlayer*    m_pPlayerAI;
};

} // namespace Domlib