#pragma once
#include "card.h"

namespace Domlib
{

class ForgeCard :
    public Domlib::Card
{
public:
    virtual ~ForgeCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    ForgeCard(void);

    friend Card;
};

} // namespace Domlib