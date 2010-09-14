#pragma once
#include "card.h"

namespace Domlib
{

class TradingPostCard :
    public Domlib::Card
{
public:
    TradingPostCard( void );
    virtual ~TradingPostCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib