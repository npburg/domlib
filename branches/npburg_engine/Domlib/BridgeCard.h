#pragma once
#include "card.h"

namespace Domlib
{

class BridgeCard :
    public Domlib::Card
{
public:
    virtual ~BridgeCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    BridgeCard( void );

    friend Card;
};

} // namespace Domlib