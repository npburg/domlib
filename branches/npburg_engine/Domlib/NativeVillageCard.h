#pragma once
#include "card.h"

namespace Domlib
{

class NativeVillageCard :
    public Domlib::Card
{
public:
    virtual ~NativeVillageCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    NativeVillageCard( void );

    friend Card;
};

} // namespace Domlib