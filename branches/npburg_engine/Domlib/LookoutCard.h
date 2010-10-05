#pragma once
#include "card.h"

namespace Domlib
{

class LookoutCard :
    public Domlib::Card
{
public:
    virtual ~LookoutCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    LookoutCard( void );

    friend Card;
};

} // namespace Domlib