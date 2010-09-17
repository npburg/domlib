#include "StdAfx.h"
#include "Domlib.h"
#include "Engine.h"

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

bool IEngine::CardsAvailable( CARDID cardId )
{
    return m_pEngine->CardsAvailable( cardId );
}

} // namespace Domlib