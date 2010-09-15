#pragma once
#include "card.h"

namespace Domlib
{

class LoanCard :
    public Domlib::Card
{
public:
    virtual ~LoanCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );

private:
    LoanCard(void);

    friend Card;
};

} // namespace Domlib