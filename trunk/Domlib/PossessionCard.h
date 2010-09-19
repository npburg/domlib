#pragma once
#include "card.h"

namespace Domlib
{

class PossessionCard :
    public Domlib::Card
{
public:
    virtual ~PossessionCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    PossessionCard( void );

    friend Card;
};

} // namespace Domlib