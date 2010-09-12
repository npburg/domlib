#pragma once
#include "card.h"

namespace Domlib
{

class HavenCard :
    public Domlib::Card
{
public:
    HavenCard( void );
    virtual ~HavenCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib