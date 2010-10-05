#pragma once
#include "card.h"

namespace Domlib
{

class VillageCard :
    public Domlib::Card
{
public:
    virtual ~VillageCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    VillageCard( void );

    friend Card;
};

} // namespace Domlib