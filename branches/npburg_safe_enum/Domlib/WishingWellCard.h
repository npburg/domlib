#pragma once
#include "card.h"

namespace Domlib
{

class WishingWellCard :
    public Domlib::Card
{
public:
    virtual ~WishingWellCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    WishingWellCard( void );

    friend Card;
};

} // namespace Domlib