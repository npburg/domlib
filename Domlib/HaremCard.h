#pragma once
#include "card.h"

namespace Domlib
{

class HaremCard :
    public Domlib::Card
{
public:
    virtual ~HaremCard( void );

private:
    HaremCard( void );

    friend Card;
};

} // namespace Domlib