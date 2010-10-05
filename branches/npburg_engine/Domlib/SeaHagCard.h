#pragma once
#include "card.h"

namespace Domlib
{

class SeaHagCard :
    public Domlib::Card
{
public:
    virtual ~SeaHagCard( void );
    
    void OnActionPhase( Engine* pEngine );

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    SeaHagCard( void );

    friend Card;
};

} // namespace Domlib