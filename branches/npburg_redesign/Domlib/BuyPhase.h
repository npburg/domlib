#pragma once

#include "Phase.h"

namespace Domlib
{

class Game;
class Turn;
class Player;

namespace Phases
{

class BuyPhase
    :
    public Phase
{
public:
    BuyPhase( void );

    virtual ~BuyPhase( void );

    virtual void Execute(
                    Game* pGame,
                    Turn* pTurn,
                    Player* pPlayer );
};

} // namespace Domlib::Phases

} // namespace Domlib