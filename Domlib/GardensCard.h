#pragma once
#include "card.h"

namespace Domlib
{

class GardensCard :
    public Domlib::Card
{
public:
    virtual ~GardensCard( void );

    int OnScoring( Engine* pEngine ) const;

private:
    GardensCard( void );

    friend Card;
};

} // namespace Domlib