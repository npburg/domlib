#pragma once
#include "card.h"

namespace Domlib
{

class SecretChamberCard :
    public Domlib::Card
{
public:
    virtual ~SecretChamberCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnReaction( Engine* pEngine, Player* pPlayer );

private:
    SecretChamberCard( void );

    friend Card;
};

} // namespace Domlib