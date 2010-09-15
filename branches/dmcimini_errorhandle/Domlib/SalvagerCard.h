#pragma once
#include "card.h"

namespace Domlib
{

class SalvagerCard :
    public Domlib::Card
{
public:
    SalvagerCard( void );
    virtual ~SalvagerCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib