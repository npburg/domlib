#pragma once
#include "card.h"

namespace Domlib
{

class RabbleCard :
    public Domlib::Card
{
public:
    RabbleCard(void);
    virtual ~RabbleCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib