#pragma once
#include "card.h"

namespace Domlib
{

class LighthouseCard :
    public Domlib::Card
{
public:
    virtual ~LighthouseCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    LighthouseCard( void );

    friend Card;
};

} // namespace Domlib