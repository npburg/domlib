#pragma once
#include "card.h"

namespace Domlib
{

class KingsCourtCard :
    public Domlib::Card
{
public:
    virtual ~KingsCourtCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    KingsCourtCard(void);

    friend Card;
};

} // namespace Domlib