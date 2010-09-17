#include "StdAfx.h"
#include "Player.h"

namespace Domlib
{

Player::Player( Engine* pEngine, IAI* pAI )
    :
    m_pEngine( pEngine ),
    m_pAI( pAI )
{
}

Player::~Player( void )
{
    delete m_pAI;
}

void Player::PlayTurn( void )
{
    OnDurationPhase();
    OnActionPhase();
    OnTreasurePhase();
    OnBuyPhase();
    OnCleanUpPhase();
}

void Player::OnDurationPhase( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::OnActionPhase( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::OnTreasurePhase( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::OnBuyPhase( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::OnCleanUpPhase( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::DrawCardsToHand( int numCards )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PlusCoins( int numCoins )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PlusActions( int numActions )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PlusBuys( int numBuys )
{
    DOMLIB_NOT_IMPLEMENTED;
}

IAI* Player::GetAI( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

bool Player::AreCardsInHand( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
    return false;
}

bool Player::IsCardInHand( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
    return false;
}

bool Player::IsCardInHand( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
    return false;
}

void Player::DiscardDrawPile( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::DiscardFromHand( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::DiscardFromHandToDrawPile( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::TrashFromHand( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::TrashFromHand( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::TrashFromHand( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::TrashFromInPlay( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::TrashFromInPlay( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::GainCardOnDeck( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::GainCardInHand( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::GainCardInHand( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardInDiscard( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardsInDiscard( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardOnDraw( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardOnDraw( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardsOnDraw( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardInHand( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardsInPlay( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Player::PutCardsInHand( CardList cardList )
{
    DOMLIB_NOT_IMPLEMENTED;
}

bool Player::IsCardInDuration( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
    return false;
}

CardList Player::GetHand( void )
{
    DOMLIB_NOT_IMPLEMENTED;

    CardList null;
    return null;
}

CardList Player::GetBuyList( void )
{
    DOMLIB_NOT_IMPLEMENTED;

    CardList null;
    return null;
}

int Player::CardsInHand( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

int Player::CardsInHand( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

int Player::CardsInHand( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

int Player::CardsInHand( CARDTYPE cardType )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

int Player::CardsInPlay( CARDTYPE cardType )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

int Player::CardsBought( CARDTYPE cardType )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

int Player::ActionsPlayed( void )
{
    return m_ActionsPlayed;
}

int Player::PirateCoins( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

Card* Player::RevealCardFromDeck()
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

CardList Player::RevealCardsFromDeck( int numCards )
{
    DOMLIB_NOT_IMPLEMENTED;
    CardList error;
    return error;
}

CardList Player::RevealHand()
{
    DOMLIB_NOT_IMPLEMENTED;
    CardList error;
    return error;
}

Card* Player::OnGainACard( Treasure* cost )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

int Player::GetDeckSize( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

} // namespace Domlib