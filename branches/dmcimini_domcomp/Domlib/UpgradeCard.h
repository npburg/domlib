#pragma once
#include "card.h"

namespace Domlib
{

class UpgradeCard :
    public Domlib::Card
{
public:
    UpgradeCard( void );
    virtual ~UpgradeCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib