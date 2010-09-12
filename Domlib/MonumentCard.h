#pragma once
#include "card.h"

namespace Domlib
{

class MonumentCard :
    public Domlib::Card
{
public:
    MonumentCard(void);
    virtual ~MonumentCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib