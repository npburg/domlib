#pragma once
#include "card.h"

namespace Domlib
{

class WatchtowerCard :
    public Domlib::Card
{
public:
    WatchtowerCard(void);
    virtual ~WatchtowerCard(void);
    
    void OnActionPhase( Engine* pEngine );
    void OnReaction( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib