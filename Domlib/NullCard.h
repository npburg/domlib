#pragma once
#include "card.h"

namespace Domlib
{

class NullCard :
    public Domlib::Card
{
public:
    virtual ~NullCard( void );

private:
    NullCard( void );

    friend Card;
};

} // namespace Domlib