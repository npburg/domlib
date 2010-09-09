#pragma once

#include <vector>
#include <string>
#include "IDomCard.h"

namespace Domlib
{

class Action;
class Turn;
enum CARDID;

class Card
    :
    public AI::IDomCard
{
public:

    Card( void );

    Card( CARDID cardid, bool action, bool treasure, bool victory, int cost, int worth );

    virtual ~Card( void );

    void AddBaseAction( Action* action );

    void Execute( Turn* turn );

    int Worth( void ) const;

    // IDomCard Interfaces
    virtual bool IsAction( void ) const;

    virtual bool IsTreasure( void ) const;

    virtual bool IsVictory( void ) const;

    virtual int Cost( void ) const;

    virtual CARDID CardId( void ) const;

private:
    CARDID                  m_CardId;
    bool                    m_IsAction;
    bool                    m_IsTreasure;
    bool                    m_IsVictory;
    int                     m_Cost;
    
    int                     m_Worth;

    std::vector<Action*>    m_BaseActions;
};

} // namespace Domlib