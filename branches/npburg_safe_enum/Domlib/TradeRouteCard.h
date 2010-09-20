#pragma once
#include "card.h"

namespace Domlib
{

class TradeRouteCard :
    public Domlib::Card
{
public:
    virtual ~TradeRouteCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    TradeRouteCard(void);

    friend Card;
};

} // namespace Domlib