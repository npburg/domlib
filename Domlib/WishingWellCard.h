#pragma once
#include "card.h"

namespace Domlib
{

class WishingWellCard :
    public Domlib::Card
{
public:
    WishingWellCard( void );
    virtual ~WishingWellCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib