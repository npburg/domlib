#pragma once
#include "card.h"

namespace Domlib
{

class ShantyTownCard :
    public Domlib::Card
{
public:
    ShantyTownCard( void );
    virtual ~ShantyTownCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib