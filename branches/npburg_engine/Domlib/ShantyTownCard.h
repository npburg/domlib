#pragma once
#include "card.h"

namespace Domlib
{

class ShantyTownCard :
    public Domlib::Card
{
public:
    virtual ~ShantyTownCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ShantyTownCard( void );

    friend Card;
};

} // namespace Domlib