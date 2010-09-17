#pragma once
#include "card.h"

namespace Domlib
{

class ThiefCard :
    public Domlib::Card
{
public:
    virtual ~ThiefCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    ThiefCard( void );

    friend Card;
};

} // namespace Domlib