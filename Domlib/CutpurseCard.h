#pragma once
#include "card.h"

namespace Domlib
{

class CutpurseCard :
    public Domlib::Card
{
public:
    CutpurseCard( void );
    virtual ~CutpurseCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
};

} // namespace Domlib