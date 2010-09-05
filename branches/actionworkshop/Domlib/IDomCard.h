#pragma once

namespace Domlib
{

enum CARDID;

namespace AI
{

class __declspec(novtable) IDomCard
{
public:

    virtual bool    IsAction( void ) const = 0;

    virtual bool    IsTreasure( void ) const = 0;

    virtual bool    IsVictory( void ) const = 0;

    virtual int     Cost( void ) const = 0;

    virtual CARDID  CardId( void ) const = 0;
};

}; // namespace Domlib::AI

}; // namespace Domlib