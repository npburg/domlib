#include "StdAfx.h"
#include "Domlib.h"
#include "Card.h"

namespace Domlib
{

CardList ICardListToCardList( ICardList& icardList )
{
    CardList cardList;
    
    for( ICardListIter iter = icardList.begin();
         iter != icardList.end();
         iter++ )
    {
        cardList.push_back( (*iter)->GetCard() );
    }
    
    return cardList;
}


ICardList CardListToICardList( CardList& cardList )
{
    ICardList icardList;
    
    for( CardListIter iter = cardList.begin();
         iter != cardList.end();
         iter++ )
    {
        // TODO: figure out how to clean up ICard.
        icardList.push_back( new ICard( *iter ) );
    }
    
    return icardList;
}

ICard::ICard( Card* pCard )
{
    m_pCard = pCard;
}

ICard::~ICard( void )
{
    // Do nothing. The card was allocated and freed by the caller.
}

Card* ICard::GetCard( void )
{
    return m_pCard;
}

ICard* ICard::GetCard( CARDID cardId )
{
    // TODO: Should the ICard also follow a singleton model? Or should it expect the AI developer to cleanup the memory?
    return new ICard( Card::GetCard( cardId ) );
}

CARDID ICard::CardId( void ) const
{
    return m_pCard->CardId();
}

CARDTYPE ICard::CardType( void ) const
{
    return m_pCard->CardType();
}

int ICard::VictoryPoints( IEngine* pEngine ) const
{
    return m_pCard->VictoryPoints( pEngine->GetEngine() );
}

ITreasure ICard::Cost( IEngine* pEngine ) const
{
    return ITreasure( m_pCard->Cost( pEngine->GetEngine() ) );
}

ITreasure ICard::TreasureValue( IEngine* pEngine ) const
{
    return ITreasure( m_pCard->TreasureValue( pEngine->GetEngine() ) );
}

bool ICard::InList( IEngine* pEngine, ICardList cardList ) const
{
    return m_pCard->InList( pEngine->GetEngine(), ICardListToCardList( cardList ) );
}

bool ICard::IsActionCard( void ) const
{
    return m_pCard->IsActionCard();
}

bool ICard::IsAttackCard( void ) const
{
    return m_pCard->IsAttackCard();
}

bool ICard::IsReactionCard( void ) const
{
    return m_pCard->IsReactionCard();
}

bool ICard::IsDurationCard( void ) const
{
    return m_pCard->IsDurationCard();
}

bool ICard::IsTreasureCard( void ) const
{
    return m_pCard->IsTreasureCard();
}

bool ICard::IsVictoryCard( void ) const
{
    return m_pCard->IsVictoryCard();
}

bool ICard::IsCurseCard( void ) const
{
    return m_pCard->IsCurseCard();
}

bool ICard::IsNullCard( void ) const
{
    return m_pCard->IsNullCard();
}


} // namespace Domlib