#pragma once
#include "card.h"

namespace Domlib
{

class MarketCard :
    public Domlib::Card
{
public:
    virtual ~MarketCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    MarketCard( void );

    friend Card;
};

} // namespace Domlib