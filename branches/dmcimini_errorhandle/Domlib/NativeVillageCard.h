#pragma once
#include "card.h"

namespace Domlib
{

class NativeVillageCard :
    public Domlib::Card
{
public:
    NativeVillageCard( void );
    virtual ~NativeVillageCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib