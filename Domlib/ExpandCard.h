#pragma once
#include "card.h"

namespace Domlib
{

class ExpandCard :
    public Domlib::Card
{
public:
    virtual ~ExpandCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    ExpandCard(void);

    friend Card;
};

} // namespace Domlib