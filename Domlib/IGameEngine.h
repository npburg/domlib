#pragma once

#include "Deck.h"

namespace Domlib
{

namespace AI
{

class IDomCard;

class __declspec(novtable) IGameEngine
{
public:

    /*
        Deck Queries

        Returns specific cards based on name and id.
    */
    virtual IDomCard*   GetCard( CARDID id ) = 0;
    virtual IDomCard*   GetCopper( void ) = 0;
    virtual IDomCard*   GetSilver( void ) = 0;
    virtual IDomCard*   GetGold( void ) = 0;
    virtual IDomCard*   GetEstate( void ) = 0;
    virtual IDomCard*   GetDuchy( void ) = 0;
    virtual IDomCard*   GetProvince( void ) = 0;
    virtual IDomCard*   GetCurse( void ) = 0;
};

}; // namespace Domlib::AI

}; // namespace Domlib