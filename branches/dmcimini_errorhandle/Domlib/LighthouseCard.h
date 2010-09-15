#pragma once
#include "card.h"

namespace Domlib
{

class LighthouseCard :
    public Domlib::Card
{
public:
    LighthouseCard( void );
    virtual ~LighthouseCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib