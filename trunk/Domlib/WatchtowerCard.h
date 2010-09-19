#pragma once
#include "card.h"

namespace Domlib
{

class WatchtowerCard :
    public Domlib::Card
{
public:
    virtual ~WatchtowerCard(void);
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnReaction( Engine* pEngine, Player* pPlayer );

private:
    WatchtowerCard(void);

    friend Card;
};

} // namespace Domlib