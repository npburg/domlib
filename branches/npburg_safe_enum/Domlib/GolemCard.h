#pragma once
#include "card.h"

namespace Domlib
{

class GolemCard :
    public Domlib::Card
{
public:
    virtual ~GolemCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    GolemCard( void );

    friend Card;
};

} // namespace Domlib