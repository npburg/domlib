#pragma once
#include "card.h"

namespace Domlib
{

class IronworksCard :
    public Domlib::Card
{
public:
    IronworksCard( void );
    virtual ~IronworksCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib