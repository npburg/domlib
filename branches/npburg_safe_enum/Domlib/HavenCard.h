#pragma once
#include "card.h"

namespace Domlib
{

class HavenCard :
    public Domlib::Card
{
public:
    virtual ~HavenCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    HavenCard( void );

    friend Card;
};

} // namespace Domlib