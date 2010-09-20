#pragma once
#include "card.h"

namespace Domlib
{

class MinionCard :
    public Domlib::Card
{
public:
    virtual ~MinionCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    MinionCard( void );

    friend Card;
};

} // namespace Domlib