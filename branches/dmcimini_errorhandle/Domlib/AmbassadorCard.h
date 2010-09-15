#pragma once
#include "card.h"

namespace Domlib
{

class AmbassadorCard :
    public Domlib::Card
{
public:
    AmbassadorCard( void );
    virtual ~AmbassadorCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib