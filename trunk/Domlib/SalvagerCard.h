#pragma once
#include "card.h"

namespace Domlib
{

class SalvagerCard :
    public Domlib::Card
{
public:
    virtual ~SalvagerCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    SalvagerCard( void );

    friend Card;
};

} // namespace Domlib