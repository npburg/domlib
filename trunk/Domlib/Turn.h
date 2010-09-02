#pragma once

namespace Domlib
{

class Player;
class Game;

class Turn
{
public:
    Turn( void );

    Turn( int buys, int actions, int treasure );

    ~Turn( void );

    int AddBuys( int buys );
    int AddActions( int actions );
    int AddTreasure( int treasure );

    int AvailableBuys( void ) const;
    int AvailableActions( void ) const;
    int AvailableTreasure( void ) const;


    void Execute(
            Game* pGame,
            Player* pPlayer );

private:
    int    m_Buys;
    int    m_Actions;
    int    m_Treasure;
};

} // namespace Domlib