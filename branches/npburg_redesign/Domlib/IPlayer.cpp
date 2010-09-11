#include "StdAfx.h"
#include "Domlib.h"
#include "Player.h"

namespace Domlib
{

IPlayer::IPlayer( Player* pPlayer )
{
    m_pPlayer = pPlayer;
}

IPlayer::~IPlayer( void )
{
    // Do nothing. The player was allocated and freed by the caller.
}

ICardList IPlayer::GetHand( void )
{
    return CardListToICardList( m_pPlayer->GetHand() );
}

int IPlayer::HandSize( void )
{
    return m_pPlayer->HandSize();
}

int IPlayer::ActionsPlayed( void )
{
    return m_pPlayer->ActionsPlayed();
}

int IPlayer::GetCardCountInHandType( CARDTYPE cardType )
{
    return m_pPlayer->GetCardCountInHandType( cardType );
}

} // namespace Domlib