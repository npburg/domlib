#pragma once
#include "card.h"

namespace Domlib
{

class BishopCard :
    public Domlib::Card
{
public:
    virtual ~BishopCard(void);
    
    void OnActionPhase( Engine* pEngine );
    
protected:
    void OnActionPhaseOther( Engine* pEngine, Player* pPlayer );

private:
    BishopCard(void);

    friend Card;
};

} // namespace Domlib