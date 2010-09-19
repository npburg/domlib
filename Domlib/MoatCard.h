#pragma once
#include "card.h"

namespace Domlib
{

class MoatCard :
    public Domlib::Card
{
public:
    virtual ~MoatCard( void );

    void OnActionPhase( Engine* pEngine );

protected:
    void OnReaction( Engine* pEngine );

private:
    MoatCard( void );

    friend Card;
};

} // namespace Domlib