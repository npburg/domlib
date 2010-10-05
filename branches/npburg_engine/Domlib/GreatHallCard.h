#pragma once
#include "card.h"

namespace Domlib
{

class GreatHallCard :
    public Domlib::Card
{
public:
    virtual ~GreatHallCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    GreatHallCard( void );

    friend Card;
};

} // namespace Domlib