#pragma once
#include "card.h"

namespace Domlib
{

class ApothecaryCard :
    public Domlib::Card
{
public:
    ApothecaryCard( void );
    virtual ~ApothecaryCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib