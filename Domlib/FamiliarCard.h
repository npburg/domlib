#pragma once
#include "card.h"

namespace Domlib
{

class FamiliarCard :
    public Domlib::Card
{
public:
    FamiliarCard( void );
    virtual ~FamiliarCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib