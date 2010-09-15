#pragma once
#include "card.h"

namespace Domlib
{

class ScryingPoolCard :
    public Domlib::Card
{
public:
    virtual ~ScryingPoolCard( void );

    void OnActionPhase( Engine* pEngine );
    
protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    ScryingPoolCard( void );

    friend Card;
};

} // namespace Domlib