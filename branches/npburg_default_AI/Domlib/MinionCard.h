#pragma once
#include "card.h"

namespace Domlib
{

class MinionCard :
    public Domlib::Card
{
public:
    MinionCard( void );
    virtual ~MinionCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib