#pragma once
#include "card.h"

namespace Domlib
{

class MilitiaCard :
    public Domlib::Card
{
public:
    virtual ~MilitiaCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    MilitiaCard( void );

    friend Card;
};

} // namespace Domlib