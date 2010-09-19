#pragma once
#include "card.h"

namespace Domlib
{

class QuarryCard :
    public Domlib::Card
{
public:
    virtual ~QuarryCard(void);
    
    Treasure OnTreasurePhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    QuarryCard(void);

    friend Card;
};

} // namespace Domlib