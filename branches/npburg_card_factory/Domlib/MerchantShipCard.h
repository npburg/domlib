#pragma once
#include "card.h"

namespace Domlib
{

class MerchantShipCard :
    public Domlib::Card
{
public:
    virtual ~MerchantShipCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    MerchantShipCard( void );

    friend Card;
};

} // namespace Domlib