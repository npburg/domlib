#pragma once
#include "card.h"

namespace Domlib
{

class BishopCard :
    public Domlib::Card
{
public:
    BishopCard(void);
    virtual ~BishopCard(void);
    
    void OnActionPhase( Engine* pEngine );
    
protected:
    void OnActionPhaseOther( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib