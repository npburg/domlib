#pragma once
#include "card.h"

namespace Domlib
{

class MonumentCard :
    public Domlib::Card
{
public:
    virtual ~MonumentCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    MonumentCard(void);

    friend Card;
};

} // namespace Domlib