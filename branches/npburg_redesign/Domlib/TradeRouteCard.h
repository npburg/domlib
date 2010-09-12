#pragma once
#include "card.h"

namespace Domlib
{

class TradeRouteCard :
    public Domlib::Card
{
public:
    TradeRouteCard(void);
    virtual ~TradeRouteCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib