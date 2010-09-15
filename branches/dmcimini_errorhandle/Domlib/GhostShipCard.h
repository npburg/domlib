#pragma once
#include "card.h"

namespace Domlib
{

class GhostShipCard :
    public Domlib::Card
{
public:
    GhostShipCard( void );
    virtual ~GhostShipCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib