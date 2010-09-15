#pragma once
#include "card.h"

namespace Domlib
{

class ChancellorCard :
    public Domlib::Card
{
public:
    virtual ~ChancellorCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ChancellorCard( void );

    friend Card;
};

} // namespace Domlib