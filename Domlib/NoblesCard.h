#pragma once
#include "card.h"

namespace Domlib
{

class NoblesCard :
    public Domlib::Card
{
public:
    NoblesCard( void );
    virtual ~NoblesCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib