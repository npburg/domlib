#pragma once
#include "card.h"

namespace Domlib
{

class RabbleCard :
    public Domlib::Card
{
public:
    virtual ~RabbleCard(void);
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    RabbleCard(void);

    friend Card;
};

} // namespace Domlib