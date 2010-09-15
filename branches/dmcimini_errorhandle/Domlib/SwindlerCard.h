#pragma once
#include "card.h"

namespace Domlib
{

class SwindlerCard :
    public Domlib::Card
{
public:
    SwindlerCard( void );
    virtual ~SwindlerCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib