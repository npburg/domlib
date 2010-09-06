#pragma once

namespace Domlib
{

class Turn;
class Game;
class Player;

class Action
{
public:
    Action( void );

    ~Action( void );

    virtual void Execute(
        Game* pGame,
        Turn* pTurn,
        Player* pPlayer ) = 0;
};

} // namespace Domlib