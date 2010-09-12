#pragma once
#include "card.h"

namespace Domlib
{

class ForgeCard :
    public Domlib::Card
{
public:
    ForgeCard(void);
    virtual ~ForgeCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib