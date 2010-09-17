#pragma once
#include "card.h"

namespace Domlib
{

class MintCard :
    public Domlib::Card
{
public:
    MintCard(void);
    virtual ~MintCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnBuy( Engine* pEngine );
};

} // namespace Domlib