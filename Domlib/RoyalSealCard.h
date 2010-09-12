#pragma once
#include "card.h"

namespace Domlib
{

class RoyalSealCard :
    public Domlib::Card
{
public:
    RoyalSealCard(void);
    virtual ~RoyalSealCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib