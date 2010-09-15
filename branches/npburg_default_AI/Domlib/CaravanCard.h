#pragma once
#include "card.h"

namespace Domlib
{

class CaravanCard :
    public Domlib::Card
{
public:
    CaravanCard( void );
    virtual ~CaravanCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib