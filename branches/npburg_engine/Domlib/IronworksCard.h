#pragma once
#include "card.h"

namespace Domlib
{

class IronworksCard :
    public Domlib::Card
{
public:
    virtual ~IronworksCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    IronworksCard( void );

    friend Card;
};

} // namespace Domlib