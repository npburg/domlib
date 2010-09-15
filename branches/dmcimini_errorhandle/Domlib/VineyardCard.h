#pragma once
#include "card.h"

namespace Domlib
{

class VineyardCard :
    public Domlib::Card
{
public:
    VineyardCard( void );
    virtual ~VineyardCard( void );

    int OnScoring( Engine* pEngine );
};

} // namespace Domlib