#include "Turn.h"
#include "Phase.h"
#include "ActionPhase.h"
#include "BuyPhase.h"
#include "CleanupPhase.h"

namespace Domlib
{

Turn::Turn( void )
{

}

Turn::Turn(
    int buys,
    int actions,
    int treasure )
    :
    m_Buys( buys ),
    m_Actions( actions ),
    m_Treasure( treasure )
{

}

Turn::~Turn( void )
{

}

int Turn::AddBuys( int buys )
{
    m_Buys += buys;

    if( m_Buys < 0 )
    {
        m_Buys = 0;
    }

    return m_Buys;
}

int Turn::AvailableBuys( void ) const
{
    return m_Buys;
}

int Turn::AddActions( int actions )
{
    m_Actions += actions;

    if( m_Actions < 0 )
    {
        m_Actions = 0;
    }

    return m_Actions;
}

int Turn::AvailableActions( void ) const
{
    return m_Actions;
}

int Turn::AddTreasure( int treasure )
{
    m_Treasure += treasure;

    if( m_Treasure < 0 )
    {
        m_Treasure = 0;
    }

    return m_Treasure;
}

int Turn::AvailableTreasure( void ) const
{
    return m_Treasure;
}

void Turn::Execute(
    Game* pGame,
    Player* pPlayer )
{
    Phases::ActionPhase     actionPhase;
    Phases::BuyPhase        buyPhase;
    Phases::CleanupPhase    cleanupPhase;

    actionPhase.Execute(
        pGame,
        this,
        pPlayer );

    buyPhase.Execute(
        pGame,
        this,
        pPlayer );

    cleanupPhase.Execute(
        pGame,
        this,
        pPlayer );
}

}