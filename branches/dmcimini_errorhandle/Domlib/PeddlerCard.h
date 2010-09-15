#pragma once
#include "card.h"

namespace Domlib
{

class PeddlerCard :
    public Domlib::Card
{
public:
    PeddlerCard(void);
    virtual ~PeddlerCard(void);
    
    void OnActionPhase( Engine* pEngine );
    Treasure Cost( Engine* pEngine );
};

} // namespace Domlib