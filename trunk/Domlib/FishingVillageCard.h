#pragma once
#include "card.h"

namespace Domlib
{

class FishingVillageCard :
    public Domlib::Card
{
public:
    virtual ~FishingVillageCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    FishingVillageCard( void );

    friend Card;
};

} // namespace Domlib