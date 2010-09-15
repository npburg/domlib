#pragma once
#include "card.h"

namespace Domlib
{

class VineyardCard :
    public Domlib::Card
{
public:
    virtual ~VineyardCard( void );

    int OnScoring( Engine* pEngine );
    
private:
    VineyardCard( void );

    friend Card;
};

} // namespace Domlib