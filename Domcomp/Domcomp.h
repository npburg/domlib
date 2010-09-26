#pragma once

#include <vector>

class IDll;

struct CardSets
{
    bool    Base;
    bool    Intrigue;
    bool    Seaside;
    bool    Alchemy;
    bool    Prosperity;
};

bool RunGame(
    const std::vector<IDll*>& dllList,
    const CardSets& cardSets );
