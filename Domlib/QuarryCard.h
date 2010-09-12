#pragma once
#include "card.h"

namespace Domlib
{

class QuarryCard :
    public Domlib::Card
{
public:
    QuarryCard(void);
    virtual ~QuarryCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib