#pragma once
#include "card.h"

namespace Domlib
{

class GoonsCard :
    public Domlib::Card
{
public:
    GoonsCard(void);
    virtual ~GoonsCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib