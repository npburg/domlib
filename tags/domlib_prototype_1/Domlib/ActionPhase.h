#pragma once

#include "Phase.h"

namespace Domlib
{

class Turn;
class Player;
class Game;

namespace Phases
{

class ActionPhase
    :
    public Phase
{
public:
    ActionPhase( void );

    virtual ~ActionPhase( void );

    virtual void Execute(
                    Game* pGame,
                    Turn* pTurn,
                    Player* pPlayer );
};

} // namespace Domlib::Phases

} // namespace Domlib