#pragma once
#include "card.h"

namespace Domlib
{

class CaravanCard :
    public Domlib::Card
{
public:
    virtual ~CaravanCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    CaravanCard( void );

    friend Card;
};

} // namespace Domlib