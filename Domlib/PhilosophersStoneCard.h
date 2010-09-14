#pragma once
#include "card.h"

namespace Domlib
{

class PhilosophersStoneCard :
    public Domlib::Card
{
public:
    PhilosophersStoneCard( void );
    virtual ~PhilosophersStoneCard( void );

    Treasure OnTreasurePhase( Engine* pEngine );
};

} // namespace Domlib