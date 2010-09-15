#pragma once
#include "card.h"

namespace Domlib
{

class IslandCard :
    public Domlib::Card
{
public:
    IslandCard( void );
    virtual ~IslandCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib