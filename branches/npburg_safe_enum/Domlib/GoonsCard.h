#pragma once
#include "card.h"

namespace Domlib
{

class GoonsCard :
    public Domlib::Card
{
public:
    virtual ~GoonsCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    GoonsCard(void);

    friend Card;
};

} // namespace Domlib