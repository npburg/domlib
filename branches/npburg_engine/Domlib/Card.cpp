#include "StdAfx.h"
#include "Card.h"

namespace Domlib
{

Card::CardFactory Card::m_CardDeck;

Card::Card( 
           std::wstring name,
           CARDID cardId, 
           CARDTYPE cardType, 
           int victoryPoints,
           Treasure treasureValue,
           Treasure cost )
           :
           m_Name( name ),
           m_CardId( cardId ),
           m_CardType( cardType ),
           m_VictoryPoints( victoryPoints ),
           m_TreasureValue( treasureValue ),
           m_Cost( cost )
{
}

Card::~Card( void ) {}

void Card::OnDurationPhase( Engine* pEngine ) {}

void Card::OnActionPhase( Engine* pEngine ) {}

void Card::OnReaction( Engine* pEngine, Player* pPlayer ) {}

void Card::OnActionPhaseOther( Engine* pEngine, Player* pPlayer ) {}

Treasure Card::OnTreasurePhase( Engine* pEngine )
{
    return this->TreasureValue( pEngine );
}

void Card::OnBuyPhase( Engine* pEngine, Card* pCard ) {}

void Card::OnCleanUpPhase( Engine* pEngine ) {}

void Card::OnBuy( Engine* pEngine ) {}

int Card::OnScoring( Engine* pEngine ) { return VictoryPoints( pEngine ); }

void Card::ActionForOthers( Engine* pEngine ) {}

void Card::OnAttack( Engine* pEngine, Player* pPlayer ) {}

void Card::Attack( Engine* pEngine, AttackWhom attackWhom )
{
    Player* pAttackingPlayer;
    Player* pCurrentPlayer;
    
    pAttackingPlayer = pCurrentPlayer = pEngine->GetCurrentPlayer();

    if( attackWhom == AttackWhom::ALL )
    {
        OnAttack( pEngine, pCurrentPlayer );
    }
    else if( attackWhom == AttackWhom::OTHERS )
    {
        // fall through to attack others
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: Card::Attack" );
        return;
    }

    do
    {
        pCurrentPlayer = pEngine->GetNextPlayer( pCurrentPlayer );
        IAI* pCurrentAi = pCurrentPlayer->GetAI();

        Card* pReactionCard = pCurrentAi->OnAttack( this );
        ( (Card*) pReactionCard)->OnReaction( pEngine, pCurrentPlayer );

        if( pReactionCard->CardId() != CARDID::MOAT ||
            pCurrentPlayer->IsCardInDuration( CARDID::LIGHTHOUSE ) == false )
        {
            OnAttack( pEngine, pCurrentPlayer );
        }
    }
    while( pCurrentPlayer != pAttackingPlayer );
}


Card* Card::GetCard( CARDID cardId )
{
    return m_CardDeck.GetCard( cardId );
}

CARDID Card::CardId( void ) const
{
    return m_CardId;
}

CARDTYPE Card::CardType( void ) const
{
    return m_CardType;
}

int Card::VictoryPoints( Engine* pEngine ) const
{
    return m_VictoryPoints;
}

Treasure Card::Cost( Engine* pEngine ) const
{
    return m_Cost;
}

Treasure Card::TreasureValue( Engine* pEngine ) const
{
    return m_TreasureValue;
}

bool Card::InList( Engine* pEngine, CardList cardList ) const
{
    for( CardListIter iter = cardList.begin();
         iter != cardList.end();
         iter++ )
    {
        if( m_CardId == (*iter)->CardId() )
        {
            return true;
        }
    }
    
    return false;
}

bool Card::IsActionCard( void ) const
{
    switch( m_CardType )
    {
    case CARDTYPE::ACTION:
    case CARDTYPE::ACTION_ATTACK:
    case CARDTYPE::ACTION_REACTION:
    case CARDTYPE::ACTION_VICTORY:
    case CARDTYPE::ACTION_DURATION:
        return true;
    default:
        return false;
    }
}

bool Card::IsAttackCard( void ) const
{
    return ( m_CardType == CARDTYPE::ACTION_ATTACK );
}

bool Card::IsReactionCard( void ) const
{
    return ( m_CardType == CARDTYPE::ACTION_REACTION );
}

bool Card::IsDurationCard( void ) const
{
    return ( m_CardType == CARDTYPE::ACTION_DURATION );
}

bool Card::IsTreasureCard( void ) const
{
    switch( m_CardType )
    {
    case CARDTYPE::TREASURE:
    case CARDTYPE::TREASURE_VICTORY:
        return true;
    default:
        return false;
    }
}

bool Card::IsVictoryCard( void ) const
{
    switch( m_CardType )
    {
    case CARDTYPE::VICTORY:
    case CARDTYPE::TREASURE_VICTORY:
        return true;
    default:
        return false;
    }
}

bool Card::IsCurseCard( void ) const
{
    return ( m_CardType == CARDTYPE::CURSE );
}

bool Card::IsNullCard( void ) const
{
    return ( m_CardType == CARDTYPE::NULLCARD );
}

bool Card::CardListsMatch( CardList cardListA,
                           CardList cardListB )
{
    throw std::wstring( L"Error: Card::CardListsMatch - To be implemented..." );
    return false;
}

bool Card::CardListsMatch( CardList cardList,
                          LookoutStruct lookoutStruct)
{
    throw std::wstring( L"Error: Card::CardListsMatch - To be implemented..." );
    return false;
}


bool Card::CardInList( Card* pCard,
                       CardList cardList )
{
    throw std::wstring( L"Error: Card::CardInList - To be implemented..." );
    return false;
}

} // namespace Domlib