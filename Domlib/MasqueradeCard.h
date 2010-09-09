#pragma once
#include "card.h"

namespace Domlib
{

class MasqueradeCard :
    public Domlib::Card
{
public:
    MasqueradeCard( void );
    virtual ~MasqueradeCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib