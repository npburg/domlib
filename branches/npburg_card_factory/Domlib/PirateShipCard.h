#pragma once
#include "card.h"

namespace Domlib
{

class PirateShipCard :
    public Domlib::Card
{
public:
    virtual ~PirateShipCard( void );
    
    void OnActionPhase( Engine* pEngine );
    
protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

    // TODO: Warning this field means Pirate Ship is not stateless so
    //       could have threading issues.
    bool    m_bFoundTreasure;

private:
    PirateShipCard( void );

    friend Card;
};

} // namespace Domlib