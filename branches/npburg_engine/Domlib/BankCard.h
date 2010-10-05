#pragma once
#include "card.h"

namespace Domlib
{

class BankCard :
    public Domlib::Card
{
public:
    virtual ~BankCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );

private:
    BankCard(void);

    friend Card;
};

} // namespace Domlib