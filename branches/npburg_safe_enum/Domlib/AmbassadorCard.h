#pragma once
#include "card.h"

namespace Domlib
{

class AmbassadorCard :
    public Domlib::Card
{
public:
    virtual ~AmbassadorCard( void );
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    AmbassadorCard( void );

    friend Card;
};

} // namespace Domlib