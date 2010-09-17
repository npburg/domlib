#pragma once
#include "card.h"

namespace Domlib
{

class ExpandCard :
    public Domlib::Card
{
public:
    ExpandCard(void);
    virtual ~ExpandCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib