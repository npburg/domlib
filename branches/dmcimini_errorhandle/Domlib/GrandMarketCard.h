#pragma once
#include "card.h"

namespace Domlib
{

class GrandMarketCard :
    public Domlib::Card
{
public:
    GrandMarketCard(void);
    virtual ~GrandMarketCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib