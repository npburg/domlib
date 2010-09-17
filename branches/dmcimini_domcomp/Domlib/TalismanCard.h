#pragma once
#include "card.h"

namespace Domlib
{

class TalismanCard :
    public Domlib::Card
{
public:
    TalismanCard(void);
    virtual ~TalismanCard(void);

    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib