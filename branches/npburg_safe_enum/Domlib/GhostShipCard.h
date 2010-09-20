#pragma once
#include "card.h"

namespace Domlib
{

class GhostShipCard :
    public Domlib::Card
{
public:
    virtual ~GhostShipCard( void );
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    GhostShipCard( void );

    friend Card;
};

} // namespace Domlib