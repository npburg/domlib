#pragma once
#include "card.h"

namespace Domlib
{

class NavigatorCard :
    public Domlib::Card
{
public:
    NavigatorCard( void );
    virtual ~NavigatorCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib