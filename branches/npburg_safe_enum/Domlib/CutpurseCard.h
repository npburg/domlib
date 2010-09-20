#pragma once
#include "card.h"

namespace Domlib
{

class CutpurseCard :
    public Domlib::Card
{
public:
    virtual ~CutpurseCard( void );
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    CutpurseCard( void );

    friend Card;
};

} // namespace Domlib