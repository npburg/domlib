#pragma once
#include "card.h"

namespace Domlib
{

class ColonyCard :
    public Domlib::Card
{
public:
    virtual ~ColonyCard(void);

private:
    ColonyCard(void);

    friend Card;
};

} // namespace Domlib