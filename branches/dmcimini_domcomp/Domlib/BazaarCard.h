#pragma once
#include "card.h"

namespace Domlib
{

class BazaarCard :
    public Domlib::Card
{
public:
    BazaarCard( void );
    virtual ~BazaarCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib