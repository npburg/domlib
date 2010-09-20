#pragma once
#include "card.h"

namespace Domlib
{

class UpgradeCard :
    public Domlib::Card
{
public:
    virtual ~UpgradeCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    UpgradeCard( void );

    friend Card;
};

} // namespace Domlib