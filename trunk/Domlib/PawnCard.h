#pragma once
#include "card.h"

namespace Domlib
{

class PawnCard :
    public Domlib::Card
{
public:
    PawnCard( void );
    virtual ~PawnCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib