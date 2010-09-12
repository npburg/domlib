#pragma once
#include "card.h"

namespace Domlib
{

class MountebankCard :
    public Domlib::Card
{
public:
    MountebankCard(void);
    virtual ~MountebankCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib