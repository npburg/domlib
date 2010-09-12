#pragma once
#include "card.h"

namespace Domlib
{

class SeaHagCard :
    public Domlib::Card
{
public:
    SeaHagCard( void );
    virtual ~SeaHagCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib