#pragma once
#include "card.h"

namespace Domlib
{

class SaboteurCard :
    public Domlib::Card
{
public:
    SaboteurCard( void );
    virtual ~SaboteurCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib