#pragma once
#include "card.h"

namespace Domlib
{

class ContrabandCard :
    public Domlib::Card
{
public:
    virtual ~ContrabandCard(void);
    
    Treasure    OnTreasurePhase( Engine* pEngine );
    void        OnCleanUpPhase( Engine* pEngine );

private:
    ContrabandCard(void);

    friend Card;
};

} // namespace Domlib