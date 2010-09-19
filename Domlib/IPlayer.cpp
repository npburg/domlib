#include "StdAfx.h"
#include "Domlib.h"
#include "Player.h"

namespace Domlib
{

IPlayer::IPlayer( Player* pPlayer )
    : IPlayerOther( pPlayer )
{
}

IPlayer::~IPlayer( void )
{
    // Do nothing. The player was allocated and freed by the caller.
}

ICardList IPlayer::GetHand( void )
{
    return CardListToICardList( m_pPlayer->GetHand() );
}

int IPlayer::CardsInHand( void )
{
    return m_pPlayer->CardsInHand();
}

int IPlayer::CardsInHand( ICard* pCard )
{
    return m_pPlayer->CardsInHand( pCard->GetCard() );
}

int IPlayer::CardsInHand( CARDID cardId )
{
    return m_pPlayer->CardsInHand( cardId );
}

int IPlayer::CardsInHand( CARDTYPE cardType )
{
    return m_pPlayer->CardsInHand( cardType );
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