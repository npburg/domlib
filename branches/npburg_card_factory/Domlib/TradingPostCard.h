#pragma once
#include "card.h"

namespace Domlib
{

class TradingPostCard :
    public Domlib::Card
{
public:
    virtual ~TradingPostCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    TradingPostCard( void );

    friend Card;
};

} // namespace Domlib