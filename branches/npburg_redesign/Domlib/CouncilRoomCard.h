#pragma once
#include "card.h"

namespace Domlib
{

class CouncilRoomCard :
    public Domlib::Card
{
public:
    virtual ~CouncilRoomCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    CouncilRoomCard( void );

    friend Card;
};

} // namespace Domlib