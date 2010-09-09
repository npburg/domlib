#pragma once
#include "card.h"

namespace Domlib
{

class ThroneRoomCard :
    public Domlib::Card
{
public:
    virtual ~ThroneRoomCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ThroneRoomCard( void );

    friend Card;
};

} // namespace Domlib