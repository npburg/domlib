#pragma once

#include "Card.h"

namespace Domlib
{

class Engine;

class ChapelCard :
    public Domlib::Card
{
public:
    virtual ~ChapelCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ChapelCard( void );

    friend Card;
};

} // namespace Domlib