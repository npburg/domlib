#pragma once
#include "card.h"

namespace Domlib
{

class RoyalSealCard :
    public Domlib::Card
{
public:
    virtual ~RoyalSealCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    RoyalSealCard(void);

    friend Card;
};

} // namespace Domlib