#pragma once
#include "card.h"

namespace Domlib
{

class SwindlerCard :
    public Domlib::Card
{
public:
    virtual ~SwindlerCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    SwindlerCard( void );

    friend Card;
};

} // namespace Domlib