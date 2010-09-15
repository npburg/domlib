#pragma once
#include "card.h"

namespace Domlib
{

class BureaucratCard :
    public Domlib::Card
{
public:
    virtual ~BureaucratCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    BureaucratCard( void );

    friend Card;
};

} // namespace Domlib