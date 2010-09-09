#pragma once

namespace Domlib
{

class Turn;
class Player;
class Game;

namespace Phases
{

class Phase
{
public:
    Phase( void );

    virtual ~Phase( void );

    virtual void Execute( 
                    Game* pGame,
                    Turn* pTurn, 
                    Player* pPlayer ) = 0;
};

} // namespace Domlib::Phases

} // namespace Domlib