#pragma once
#include "card.h"

namespace Domlib
{

class ScryingPoolCard :
    public Domlib::Card
{
public:
    ScryingPoolCard( void );
    virtual ~ScryingPoolCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib