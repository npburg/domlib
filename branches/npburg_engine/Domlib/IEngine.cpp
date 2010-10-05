#include "StdAfx.h"
#include "Domlib.h"
#include "Engine.h"
#include "Treasure.h"

namespace Domlib
{

IEngine::IEngine( Engine* pEngine )
{
    m_pEngine = pEngine;
}

IEngine::~IEngine( void )
{
    // Do nothing. The engine was allocated and freed by the caller.
}

Engine* IEngine::GetEngine( void )
{
    return m_pEngine;
}

bool IEngine::IsCardInStock( CARDID cardId )
{
    return m_pEngine->IsCardInStock( cardId );
}

int IEngine::CardsAvailable( CARDID cardId )
{
    return m_pEngine->CardsAvailable( cardId );
}

ICardList IEngine::CardsCostingExactly( const ITreasure* cost )
{
    return CardListToICardList( m_pEngine->CardsCostingExactly( &Treasure( *cost ) ) );
}

ICardList IEngine::PilesAvailable( void )
{
    return CardListToICardList( m_pEngine->PilesAvailable() );
}

IPlayerOther* IEngine::GetPreviousPlayer( IPlayer* pPlayer )
{
    // TODO: Fix this memory leak since the caller is not expecting to clean up this memory.
    return new IPlayerOther( m_pEngine->GetPreviousPlayer( pPlayer->GetPlayer() ) );
}


} // namespace Domlib