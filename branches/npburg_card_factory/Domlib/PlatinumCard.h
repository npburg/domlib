#pragma once
#include "card.h"

namespace Domlib
{

class PlatinumCard :
    public Domlib::Card
{
public:
    virtual ~PlatinumCard(void);

private:
    PlatinumCard(void);

    friend Card;
};

} // namespace Domlib