#pragma once
#include "card.h"

namespace Domlib
{

class GrandMarketCard :
    public Domlib::Card
{
public:
    virtual ~GrandMarketCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    GrandMarketCard(void);

    friend Card;
};

} // namespace Domlib