#pragma once
#include "card.h"

namespace Domlib
{

class ScoutCard :
    public Domlib::Card
{
public:
    virtual ~ScoutCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ScoutCard( void );

    friend Card;
};

} // namespace Domlib