#pragma once
#include "card.h"

namespace Domlib
{

class HoardCard :
    public Domlib::Card
{
public:
    virtual ~HoardCard(void);

    void OnCleanUpPhase( Engine* pEngine );

private: 
    HoardCard(void);

    friend Card;
};

} // namespace Domlib