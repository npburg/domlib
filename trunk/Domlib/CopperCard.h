#pragma once
#include "card.h"

namespace Domlib
{

class CopperCard :
    public Domlib::Card
{
public:
    virtual ~CopperCard( void );

private:
    CopperCard( void );

    friend Card;
};

} // namespace Domlib