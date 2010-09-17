#pragma once
#include "card.h"

namespace Domlib
{

class ProvinceCard :
    public Domlib::Card
{
public:
    virtual ~ProvinceCard( void );

private:
    ProvinceCard( void );

    friend Card;
};

} // namespace Domlib