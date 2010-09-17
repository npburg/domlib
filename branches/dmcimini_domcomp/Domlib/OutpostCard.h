#pragma once
#include "card.h"

namespace Domlib
{

class OutpostCard :
    public Domlib::Card
{
public:
    OutpostCard( void );
    virtual ~OutpostCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib