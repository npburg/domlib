#pragma once
#include "card.h"

namespace Domlib
{

class MiningVilliageCard :
    public Domlib::Card
{
public:
    MiningVilliageCard( void );
    virtual ~MiningVilliageCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib