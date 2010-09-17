#pragma once
#include "card.h"

namespace Domlib
{

class ConspiratorCard :
    public Domlib::Card
{
public:
    ConspiratorCard( void );
    virtual ~ConspiratorCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib