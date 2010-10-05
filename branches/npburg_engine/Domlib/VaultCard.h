#pragma once
#include "card.h"

namespace Domlib
{

class VaultCard :
    public Domlib::Card
{
public:
    virtual ~VaultCard(void);
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnActionPhaseOther( Engine* pEngine, Player* pPlayer );

private:
    VaultCard(void);

    friend Card;
};

} // namespace Domlib