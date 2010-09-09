#pragma once
#include "card.h"

namespace Domlib
{

class GolemCard :
    public Domlib::Card
{
public:
    GolemCard( void );
    virtual ~GolemCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib