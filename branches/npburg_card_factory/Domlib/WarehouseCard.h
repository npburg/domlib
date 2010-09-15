#pragma once
#include "card.h"

namespace Domlib
{

class WarehouseCard :
    public Domlib::Card
{
public:
    virtual ~WarehouseCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    WarehouseCard( void );

    friend Card;
};

} // namespace Domlib