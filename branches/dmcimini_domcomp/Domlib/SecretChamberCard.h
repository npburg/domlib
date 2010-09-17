#pragma once
#include "card.h"

namespace Domlib
{

class SecretChamberCard :
    public Domlib::Card
{
public:
    SecretChamberCard( void );
    virtual ~SecretChamberCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnReaction( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib