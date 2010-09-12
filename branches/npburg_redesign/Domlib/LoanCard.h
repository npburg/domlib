#pragma once
#include "card.h"

namespace Domlib
{

class LoanCard :
    public Domlib::Card
{
public:
    LoanCard(void);
    virtual ~LoanCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
};

} // namespace Domlib