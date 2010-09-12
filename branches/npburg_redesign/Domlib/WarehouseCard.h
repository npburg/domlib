#pragma once
#include "card.h"

namespace Domlib
{

class WarehouseCard :
    public Domlib::Card
{
public:
    WarehouseCard( void );
    virtual ~WarehouseCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib