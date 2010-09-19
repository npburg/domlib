#pragma once
#include "card.h"

namespace Domlib
{

class MiningVillageCard :
    public Domlib::Card
{
public:
    virtual ~MiningVillageCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    MiningVillageCard( void );

    friend Card;
};

} // namespace Domlib