#pragma once
#include "card.h"

namespace Domlib
{

class OutpostCard :
    public Domlib::Card
{
public:
    virtual ~OutpostCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    OutpostCard( void );

    friend Card;
};

} // namespace Domlib