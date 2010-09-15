#pragma once
#include "card.h"

namespace Domlib
{

class EmbargoCard :
    public Domlib::Card
{
public:
    EmbargoCard( void );
    virtual ~EmbargoCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib