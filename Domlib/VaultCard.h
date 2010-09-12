#pragma once
#include "card.h"

namespace Domlib
{

class VaultCard :
    public Domlib::Card
{
public:
    VaultCard(void);
    virtual ~VaultCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnActionPhaseOther( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib