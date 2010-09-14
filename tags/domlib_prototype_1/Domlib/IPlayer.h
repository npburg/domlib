#pragma once

namespace Domlib
{

class Card;
class Game;
enum CARDID;

namespace AI
{

class IGameEngine;
class IDomCard;

/********************************************************************************

    INTERFACE:
        IPlayer

    DESCRIPTION:

        IPlayer is called by the game engine to make player specific choices.
        This includes phase decisions, event notification for events by other
        players, and more.

********************************************************************************/
class IPlayer
{
public:
    IPlayer( void );

    virtual ~IPlayer( void );

    IGameEngine* Engine( void );

    // General Notifications
    virtual void    GainCard( const IDomCard* pCard ) const = 0;

    // Buying
    virtual bool    ContinueBuying( int buysRemaining ) = 0;

    virtual CARDID  BuyCard( int buyingPower ) = 0;

private:

    friend class Game;

    void SetGameEngine( IGameEngine* pEngine );

    IGameEngine*    m_pEngine;
};

} // namespace AI

} // namespace Domlib