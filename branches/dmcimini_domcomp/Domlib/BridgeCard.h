#pragma once
#include "card.h"

namespace Domlib
{

class BridgeCard :
    public Domlib::Card
{
public:
    BridgeCard( void );
    virtual ~BridgeCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib