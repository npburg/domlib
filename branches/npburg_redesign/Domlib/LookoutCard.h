#pragma once
#include "card.h"

namespace Domlib
{

class LookoutCard :
    public Domlib::Card
{
public:
    LookoutCard( void );
    virtual ~LookoutCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib