#pragma once
#include "card.h"

namespace Domlib
{

class StewardCard :
    public Domlib::Card
{
public:
    StewardCard( void );
    virtual ~StewardCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib