#pragma once

namespace Domlib
{

class Turn;

class Action
{
public:
    Action( void );

    ~Action( void );

    virtual void Execute( Turn* turn ) = 0;
};

} // namespace Domlib