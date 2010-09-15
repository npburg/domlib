#pragma once
#include "card.h"

namespace Domlib
{

class CurseCard :
    public Domlib::Card
{
public:
    virtual ~CurseCard( void );

private:
    CurseCard( void );

    friend Card;
};

} // namespace Domlib