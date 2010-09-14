#pragma once
#include "card.h"

namespace Domlib
{

class VentureCard :
    public Domlib::Card
{
public:
    VentureCard(void);
    virtual ~VentureCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
};

} // namespace Domlib