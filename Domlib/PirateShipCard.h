#pragma once
#include "card.h"

namespace Domlib
{

class PirateShipCard :
    public Domlib::Card
{
public:
    PirateShipCard( void );
    virtual ~PirateShipCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnAttack( Engine* pEngine, Player* pPlayer );
    
protected:
    bool    m_bFoundTreasure;
};

} // namespace Domlib