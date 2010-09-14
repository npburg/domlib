#pragma once
#include "card.h"

namespace Domlib
{

class BankCard :
    public Domlib::Card
{
public:
    BankCard(void);
    virtual ~BankCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
};

} // namespace Domlib