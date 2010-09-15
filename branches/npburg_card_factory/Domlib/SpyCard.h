#pragma once
#include "card.h"

namespace Domlib
{

class SpyCard :
    public Domlib::Card
{
public:
    virtual ~SpyCard( void );

    void OnActionPhase( Engine* pEngine );    

protected:
    void OnAttack( Engine* pEngine, Player* pPlayer );

private:
    SpyCard( void );

    friend Card;
};

} // namespace Domlib