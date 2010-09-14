#pragma once
#include "card.h"

namespace Domlib
{

class GreatHallCard :
    public Domlib::Card
{
public:
    GreatHallCard( void );
    virtual ~GreatHallCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib