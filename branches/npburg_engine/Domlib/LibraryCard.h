#pragma once
#include "card.h"

namespace Domlib
{

class LibraryCard :
    public Domlib::Card
{
public:
    virtual ~LibraryCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    LibraryCard( void );

    friend Card;
};

} // namespace Domlib