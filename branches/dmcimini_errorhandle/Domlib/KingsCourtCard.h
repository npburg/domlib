#pragma once
#include "card.h"

namespace Domlib
{

class KingsCourtCard :
    public Domlib::Card
{
public:
    KingsCourtCard(void);
    virtual ~KingsCourtCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib