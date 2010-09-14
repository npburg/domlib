#pragma once
#include "card.h"

namespace Domlib
{

class SilverCard :
    public Domlib::Card
{
public:
    virtual ~SilverCard( void );

private:
    SilverCard( void );

    friend Card;
};

} // namespace Domlib