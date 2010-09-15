#pragma once
#include "card.h"

namespace Domlib
{

class TorturerCard :
    public Domlib::Card
{
public:
    TorturerCard( void );
    virtual ~TorturerCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib