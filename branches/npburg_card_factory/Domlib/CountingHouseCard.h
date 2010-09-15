#pragma once
#include "card.h"

namespace Domlib
{

class CountingHouseCard :
    public Domlib::Card
{
public:
    virtual ~CountingHouseCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    CountingHouseCard(void);

    friend Card;
};

} // namespace Domlib