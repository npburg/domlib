#pragma once
#include "card.h"

namespace Domlib
{

class MintCard :
    public Domlib::Card
{
public:
    virtual ~MintCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnBuy( Engine* pEngine );

private:
    MintCard(void);

    friend Card;
};

} // namespace Domlib