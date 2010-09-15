#pragma once
#include "card.h"

namespace Domlib
{

class EstateCard :
    public Domlib::Card
{
public:
    virtual ~EstateCard( void );

private:
    EstateCard( void );

    friend Card;
};

} // namespace Domlib