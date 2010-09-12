#pragma once
#include "card.h"

namespace Domlib
{

class ContrabandCard :
    public Domlib::Card
{
public:
    ContrabandCard(void);
    virtual ~ContrabandCard(void);
    
    Treasure    OnTreasurePhase( Engine* pEngine );
    void        OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib