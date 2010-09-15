#pragma once
#include "card.h"

namespace Domlib
{

class ApothecaryCard :
    public Domlib::Card
{
public:
    virtual ~ApothecaryCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ApothecaryCard( void );

    friend Card;
};

} // namespace Domlib