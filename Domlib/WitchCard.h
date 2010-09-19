#pragma once
#include "card.h"

namespace Domlib
{

class WitchCard :
    public Domlib::Card
{
public:
    virtual ~WitchCard( void );

    void OnActionPhase( Engine* pEngine );
    
protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    WitchCard( void );

    friend Card;
};

} // namespace Domlib