#pragma once
#include "card.h"

namespace Domlib
{

class MountebankCard :
    public Domlib::Card
{
public:
    virtual ~MountebankCard(void);
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    MountebankCard(void);

    friend Card;
};

} // namespace Domlib