#include "Card.h"
#include "Action.h"
#include "Game.h"

namespace Domlib
{

Card::Card( void )
    :
    m_CardId( CARDID_UNKNOWN ),
    m_IsAction( false ),
    m_IsTreasure( false ),
    m_IsVictory( false ),
    m_Cost( 0 ),
    m_Worth( 0 )
{
}

Card::Card( CARDID cardid, bool action, bool treasure, bool victory, int cost, int worth )
    :
    m_CardId( cardid ),
    m_IsAction( action ),
    m_IsTreasure( treasure ),
    m_IsVictory( victory ),
    m_Cost( cost ),
    m_Worth( worth )
{
}

Card::~Card( void )
{
    while( m_BaseActions.size() )
    {
        Action* action = m_BaseActions.back();
        delete action;
        m_BaseActions.pop_back();
    }
}

int Card::Worth( void ) const
{
    return m_Worth;
}


bool Card::IsAction( void ) const
{
    return m_IsAction;
}

bool Card::IsTreasure( void ) const
{
    return m_IsTreasure;
}

bool Card::IsVictory( void ) const
{
    return m_IsVictory;
}

int Card::Cost( void ) const
{
    return m_Cost;
}

CARDID Card::CardId( void ) const
{
    return m_CardId;
}

void Card::AddBaseAction( Action* action )
{
    m_BaseActions.push_back( action );
}

void Card::Execute( Turn* turn )
{
    std::vector<Action*>::iterator baseActionItr = m_BaseActions.begin();
    while( baseActionItr != m_BaseActions.end() )
    {
        Action* baseAction = *baseActionItr;

        if( baseAction )
        {
            baseAction->Execute( turn );
        }

        baseActionItr++;
    }
}

} // namespace Domlib
