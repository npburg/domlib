#pragma once
#include "card.h"

namespace Domlib
{

class NavigatorCard :
    public Domlib::Card
{
public:
    virtual ~NavigatorCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    NavigatorCard( void );

    friend Card;
};

} // namespace Domlib