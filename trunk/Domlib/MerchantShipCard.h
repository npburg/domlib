#pragma once
#include "card.h"

namespace Domlib
{

class MerchantShipCard :
    public Domlib::Card
{
public:
    MerchantShipCard( void );
    virtual ~MerchantShipCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib