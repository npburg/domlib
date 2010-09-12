#pragma once
#include "card.h"

namespace Domlib
{

class FishingVillageCard :
    public Domlib::Card
{
public:
    FishingVillageCard( void );
    virtual ~FishingVillageCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib