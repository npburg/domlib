#pragma once
#include "card.h"

namespace Domlib
{

class BazaarCard :
    public Domlib::Card
{
public:
    virtual ~BazaarCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    BazaarCard( void );

    friend Card;
};

} // namespace Domlib