#pragma once
#include "card.h"

namespace Domlib
{

class ScoutCard :
    public Domlib::Card
{
public:
    ScoutCard( void );
    virtual ~ScoutCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib