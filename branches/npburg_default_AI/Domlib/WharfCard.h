#pragma once
#include "card.h"

namespace Domlib
{

class WharfCard :
    public Domlib::Card
{
public:
    WharfCard( void );
    virtual ~WharfCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib