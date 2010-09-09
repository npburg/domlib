#pragma once
#include "card.h"

namespace Domlib
{

class PossessionCard :
    public Domlib::Card
{
public:
    PossessionCard( void );
    virtual ~PossessionCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib