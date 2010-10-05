#pragma once
#include "card.h"

namespace Domlib
{

class GoldCard :
    public Domlib::Card
{
public:
    virtual ~GoldCard( void );

private:
    GoldCard( void );

    friend Card;
};

} // namespace Domlib