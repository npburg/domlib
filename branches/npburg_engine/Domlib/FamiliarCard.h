#pragma once
#include "card.h"

namespace Domlib
{

class FamiliarCard :
    public Domlib::Card
{
public:
    virtual ~FamiliarCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    FamiliarCard( void );

    friend Card;
};

} // namespace Domlib