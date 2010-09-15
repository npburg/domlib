#pragma once
#include "card.h"

namespace Domlib
{

class VentureCard :
    public Domlib::Card
{
public:
    virtual ~VentureCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );

private:
    VentureCard(void);

    friend Card;
};

} // namespace Domlib