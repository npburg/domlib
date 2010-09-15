#pragma once
#include "card.h"

namespace Domlib
{

class SaboteurCard :
    public Domlib::Card
{
public:
    virtual ~SaboteurCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    SaboteurCard( void );

    friend Card;
};

} // namespace Domlib