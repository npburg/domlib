#pragma once

#include "Phase.h"

namespace Domlib
{

class Turn;
class Player;
class Game;

namespace Phases
{

class CleanupPhase
    :
    public Phase
{
public:
    CleanupPhase( void );

    virtual ~CleanupPhase( void );

    virtual void Execute( 
                    Game* pGame,
                    Turn* pTurn,
                    Player* pPlayer );
};

} // namespace Domlib::Phases

} // namespace Domlib