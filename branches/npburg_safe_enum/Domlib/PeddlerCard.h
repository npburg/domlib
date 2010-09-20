#pragma once
#include "card.h"

namespace Domlib
{

class PeddlerCard :
    public Domlib::Card
{
public:
    virtual ~PeddlerCard(void);
    
    void OnActionPhase( Engine* pEngine );
    Treasure Cost( Engine* pEngine );

private:
    PeddlerCard(void);

    friend Card;
};

} // namespace Domlib