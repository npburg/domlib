#pragma once
#include "card.h"

namespace Domlib
{

class PotionCard :
    public Domlib::Card
{
public:
    virtual ~PotionCard( void );

private:
    PotionCard( void );

    friend Card;
};

} // namespace Domlib