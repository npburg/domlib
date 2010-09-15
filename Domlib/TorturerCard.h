#pragma once
#include "card.h"

namespace Domlib
{

class TorturerCard :
    public Domlib::Card
{
public:
    virtual ~TorturerCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    TorturerCard( void );

    friend Card;
};

} // namespace Domlib