#pragma once
#include "card.h"

namespace Domlib
{

class DuchyCard :
    public Domlib::Card
{
public:
    virtual ~DuchyCard( void );

private:
    DuchyCard( void );

    friend Card;
};

} // namespace Domlib