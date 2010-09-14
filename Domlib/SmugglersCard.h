#pragma once
#include "card.h"

namespace Domlib
{

class SmugglersCard :
    public Domlib::Card
{
public:
    SmugglersCard( void );
    virtual ~SmugglersCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib