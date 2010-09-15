#pragma once
#include "card.h"

namespace Domlib
{

class CountingHouseCard :
    public Domlib::Card
{
public:
    CountingHouseCard(void);
    virtual ~CountingHouseCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib