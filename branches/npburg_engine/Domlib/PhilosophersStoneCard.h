#pragma once
#include "card.h"

namespace Domlib
{

class PhilosophersStoneCard :
    public Domlib::Card
{
public:
    virtual ~PhilosophersStoneCard( void );

    Treasure OnTreasurePhase( Engine* pEngine );

private:
    PhilosophersStoneCard( void );

    friend Card;
};

} // namespace Domlib