#pragma once
#include "card.h"

namespace Domlib
{

class WorkersVillageCard :
    public Domlib::Card
{
public:
    virtual ~WorkersVillageCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    WorkersVillageCard(void);

    friend Card;
};

} // namespace Domlib