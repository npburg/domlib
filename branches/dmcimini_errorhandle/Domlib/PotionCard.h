#pragma once
#include "card.h"

namespace Domlib
{

class PotionCard :
    public Domlib::Card
{
public:
    PotionCard( void );
    virtual ~PotionCard( void );
};

} // namespace Domlib