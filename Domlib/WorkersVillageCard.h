#pragma once
#include "card.h"

namespace Domlib
{

class WorkersVillageCard :
    public Domlib::Card
{
public:
    WorkersVillageCard(void);
    virtual ~WorkersVillageCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib