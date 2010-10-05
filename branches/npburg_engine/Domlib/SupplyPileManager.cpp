#include "StdAfx.h"
#include "SupplyPileManager.h"
#include "SupplyPile.h"
#include "Card.h"

namespace Domlib
{

SupplyPileManager::SupplyPileManager()
{
    m_pNullPile = new SupplyPile( CARDID::NULLCARD, 0 );

    // Default set the pile sizes to 0 and initialize the piles later.
    AddPile( CARDID::COPPER, 0 );
    AddPile( CARDID::SILVER, 0 );
    AddPile( CARDID::GOLD, 0 );
    AddPile( CARDID::ESTATE, 0 );
    AddPile( CARDID::DUCHY, 0 );
    AddPile( CARDID::PROVINCE, 0 );
    AddPile( CARDID::CURSE, 0 );
}

SupplyPileManager::~SupplyPileManager()
{
    for( SupplyPileMapIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++ )
    {
        delete iter->second;
        m_SupplyPiles.erase( iter );
    }
    delete m_pNullPile;
}

void SupplyPileManager::InitializePiles( int numPlayers )
{
    // TODO: Lookup correct number of cards to add to each pile
    for( SupplyPileMapIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++ )
    {
        CARDID cardId = (*iter).first;
        SupplyPile* pSupplyPile = (*iter).second;

        int quantity;

        switch( cardId )
        {
        case CARDID::COPPER:
            quantity = 60 - ( 3 * numPlayers );
            break;
        case CARDID::SILVER:
            quantity = 40;
            break;
        case CARDID::GOLD:
            quantity = 30;
            break;
        case CARDID::POTION:
            quantity = 16;
            break;
        case CARDID::ESTATE:
        case CARDID::DUCHY:
        case CARDID::GARDENS:
        case CARDID::VINEYARD:
            quantity = 12;
            break;
        case CARDID::PROVINCE:
            switch( numPlayers )
            {
            case 2:
                quantity = 8;
                break;
            case 3:
            case 4:
                quantity = 12;
                break;
            case 5:
            case 6:
                quantity = 15;
                break;
            default:
                // TODO: error
                throw std::wstring( L"Error: SupplyPileManager::InitializePiles" );
                break;
            }
            break;
        case CARDID::CURSE:
            quantity = 10 * ( numPlayers - 1 );
            break;
        default:
            quantity = 10;
            break;
        }

        pSupplyPile->SetSize( quantity );
    }
}

void SupplyPileManager::RandomizeKingdomCards( int cardSet )
{
    CardList cardList;

    if( cardSet | CARDSET::BASE )
    {
        cardList.push_back( Card::GetCard( CARDID::ADVENTURER ) );
        cardList.push_back( Card::GetCard( CARDID::BUREAUCRAT ) );
        cardList.push_back( Card::GetCard( CARDID::CELLAR ) );
        cardList.push_back( Card::GetCard( CARDID::CHAPEL ) );
        cardList.push_back( Card::GetCard( CARDID::CHANCELLOR ) );
        cardList.push_back( Card::GetCard( CARDID::COUNCILROOM ) );
        cardList.push_back( Card::GetCard( CARDID::FEAST ) );
        cardList.push_back( Card::GetCard( CARDID::FESTIVAL ) );
        cardList.push_back( Card::GetCard( CARDID::GARDENS ) );
        cardList.push_back( Card::GetCard( CARDID::LABORATORY ) );
        cardList.push_back( Card::GetCard( CARDID::LIBRARY ) );
        cardList.push_back( Card::GetCard( CARDID::MARKET ) );
        cardList.push_back( Card::GetCard( CARDID::MILITIA ) );
        cardList.push_back( Card::GetCard( CARDID::MINE ) );
        cardList.push_back( Card::GetCard( CARDID::MOAT ) );
        cardList.push_back( Card::GetCard( CARDID::MONEYLENDER ) );
        cardList.push_back( Card::GetCard( CARDID::REMODEL ) );
        cardList.push_back( Card::GetCard( CARDID::SMITHY ) );
        cardList.push_back( Card::GetCard( CARDID::SPY ) );
        cardList.push_back( Card::GetCard( CARDID::THIEF ) );
        cardList.push_back( Card::GetCard( CARDID::THRONEROOM ) );
        cardList.push_back( Card::GetCard( CARDID::VILLAGE ) );
        cardList.push_back( Card::GetCard( CARDID::WITCH ) );
        cardList.push_back( Card::GetCard( CARDID::WOODCUTTER ) );
        cardList.push_back( Card::GetCard( CARDID::WORKSHOP ) );
    }

    if( cardSet | CARDSET::INTRIGUE )
    {
        cardList.push_back( Card::GetCard( CARDID::BARON ) );
        cardList.push_back( Card::GetCard( CARDID::BRIDGE ) );
        cardList.push_back( Card::GetCard( CARDID::COPPERSMITH ) );
        cardList.push_back( Card::GetCard( CARDID::CONSPIRATOR ) );
        cardList.push_back( Card::GetCard( CARDID::COURTYARD ) );
        cardList.push_back( Card::GetCard( CARDID::DUKE ) );
        cardList.push_back( Card::GetCard( CARDID::GREATHALL ) );
        cardList.push_back( Card::GetCard( CARDID::HAREM ) );
        cardList.push_back( Card::GetCard( CARDID::IRONWORKS ) );
        cardList.push_back( Card::GetCard( CARDID::MASQUERADE ) );
        cardList.push_back( Card::GetCard( CARDID::MININGVILLAGE ) );
        cardList.push_back( Card::GetCard( CARDID::MINION ) );
        cardList.push_back( Card::GetCard( CARDID::NOBLES ) );
        cardList.push_back( Card::GetCard( CARDID::PAWN ) );
        cardList.push_back( Card::GetCard( CARDID::SCOUT ) );
        cardList.push_back( Card::GetCard( CARDID::SABOTEUR ) );
        cardList.push_back( Card::GetCard( CARDID::SECRETCHAMBER ) );
        cardList.push_back( Card::GetCard( CARDID::SHANTYTOWN ) );
        cardList.push_back( Card::GetCard( CARDID::WORKSHOP ) );
        cardList.push_back( Card::GetCard( CARDID::STEWARD ) );
        cardList.push_back( Card::GetCard( CARDID::SWINDLER ) );
        cardList.push_back( Card::GetCard( CARDID::TORTURER ) );
        cardList.push_back( Card::GetCard( CARDID::TRADINGPOST ) );
        cardList.push_back( Card::GetCard( CARDID::TRIBUTE ) );
        cardList.push_back( Card::GetCard( CARDID::UPGRADE ) );
        cardList.push_back( Card::GetCard( CARDID::WISHINGWELL ) );
    }
    
    if( cardSet | CARDSET::SEASIDE )
    {
        cardList.push_back( Card::GetCard( CARDID::AMBASSADOR ) );
        cardList.push_back( Card::GetCard( CARDID::BAZAAR ) );
        cardList.push_back( Card::GetCard( CARDID::CARAVAN ) );
        cardList.push_back( Card::GetCard( CARDID::CUTPURSE ) );
        cardList.push_back( Card::GetCard( CARDID::EMBARGO ) );
        cardList.push_back( Card::GetCard( CARDID::EXPLORER ) );
        cardList.push_back( Card::GetCard( CARDID::FISHINGVILLAGE ) );
        cardList.push_back( Card::GetCard( CARDID::GHOSTSHIP ) );
        cardList.push_back( Card::GetCard( CARDID::HAVEN ) );
        cardList.push_back( Card::GetCard( CARDID::ISLAND ) );
        cardList.push_back( Card::GetCard( CARDID::LOOKOUT ) );
        cardList.push_back( Card::GetCard( CARDID::MERCHANTSHIP ) );
        cardList.push_back( Card::GetCard( CARDID::NATIVEVILLAGE ) );
        cardList.push_back( Card::GetCard( CARDID::NAVIGATOR ) );
        cardList.push_back( Card::GetCard( CARDID::OUTPOST ) );
        cardList.push_back( Card::GetCard( CARDID::PEARLDIVER ) );
        cardList.push_back( Card::GetCard( CARDID::PIRATESHIP ) );
        cardList.push_back( Card::GetCard( CARDID::SALVAGER ) );
        cardList.push_back( Card::GetCard( CARDID::SEAHAG ) );
        cardList.push_back( Card::GetCard( CARDID::SMUGGLERS ) );
        cardList.push_back( Card::GetCard( CARDID::TACTICIAN ) );
        cardList.push_back( Card::GetCard( CARDID::TREASUREMAP ) );
        cardList.push_back( Card::GetCard( CARDID::TREASURY ) );
        cardList.push_back( Card::GetCard( CARDID::WAREHOUSE ) );
        cardList.push_back( Card::GetCard( CARDID::WHARF ) );
    }

    if( cardSet | CARDSET::ALCHEMY )
    {
        AddPile( CARDID::POTION, 0 );

        cardList.push_back( Card::GetCard( CARDID::APOTHECARY ) );   
        cardList.push_back( Card::GetCard( CARDID::ALCHEMIST ) );
        cardList.push_back( Card::GetCard( CARDID::APPRENTICE ) );
        cardList.push_back( Card::GetCard( CARDID::FAMILIAR ) );
        cardList.push_back( Card::GetCard( CARDID::GOLEM ) );
        cardList.push_back( Card::GetCard( CARDID::HERBALIST ) );
        cardList.push_back( Card::GetCard( CARDID::PHILOSOPHERSSTONE ) );
        cardList.push_back( Card::GetCard( CARDID::POSSESSION ) );
        cardList.push_back( Card::GetCard( CARDID::SCRYINGPOOL ) );
        cardList.push_back( Card::GetCard( CARDID::TRANSMUTE ) );
        cardList.push_back( Card::GetCard( CARDID::UNIVERSITY ) );
        cardList.push_back( Card::GetCard( CARDID::VINEYARD ) );
    }

    if( cardSet | CARDSET::PROSPERITY )
    {
        AddPile( CARDID::COLONY, 0 );
        AddPile( CARDID::PLATINUM, 0 );

        cardList.push_back( Card::GetCard( CARDID::BANK ) );
        cardList.push_back( Card::GetCard( CARDID::BISHOP ) );
        cardList.push_back( Card::GetCard( CARDID::CITY ) );
        cardList.push_back( Card::GetCard( CARDID::CONTRABAND ) );
        cardList.push_back( Card::GetCard( CARDID::COUNTINGHOUSE ) );
        cardList.push_back( Card::GetCard( CARDID::EXPAND ) );
        cardList.push_back( Card::GetCard( CARDID::FORGE ) );
        cardList.push_back( Card::GetCard( CARDID::GOONS ) );
        cardList.push_back( Card::GetCard( CARDID::GRANDMARKET ) );
        cardList.push_back( Card::GetCard( CARDID::HOARD ) );
        cardList.push_back( Card::GetCard( CARDID::KINGSCOURT ) );
        cardList.push_back( Card::GetCard( CARDID::LOAN ) );
        cardList.push_back( Card::GetCard( CARDID::MINT ) );
        cardList.push_back( Card::GetCard( CARDID::MONUMENT ) );
        cardList.push_back( Card::GetCard( CARDID::MOUNTEBANK ) );
        cardList.push_back( Card::GetCard( CARDID::PEDDLER ) );
        cardList.push_back( Card::GetCard( CARDID::QUARRY ) );
        cardList.push_back( Card::GetCard( CARDID::RABBLE ) );
        cardList.push_back( Card::GetCard( CARDID::ROYALSEAL ) );
        cardList.push_back( Card::GetCard( CARDID::TALISMAN ) );
        cardList.push_back( Card::GetCard( CARDID::TRADEROUTE ) );
        cardList.push_back( Card::GetCard( CARDID::VAULT ) );
        cardList.push_back( Card::GetCard( CARDID::VENTURE ) );
        cardList.push_back( Card::GetCard( CARDID::WATCHTOWER ) );
        cardList.push_back( Card::GetCard( CARDID::WORKERSVILLAGE ) );
    }

    // TODO: Randoms Shuffle the cardList

    if( cardList.size() >= NUM_KINGDOM_CARD_PILES )
    {
        CardListIter iter = cardList.begin();
        for( int count = 0;
             count < NUM_KINGDOM_CARD_PILES;
             count++ )
        {
            Card* pCard = *iter;
            AddPile( pCard->CardId(), 0 );
            iter++;
        }
    }
    else
    {
        // TODO: error
        throw std::wstring( L"Error: SupplyPileManager::RandomizeKingdomCards" );
    }
}

void SupplyPileManager::AddPile( const CARDID cardId, const int cardsAvailable )
{
    m_SupplyPiles.insert( 
        std::pair<CARDID, SupplyPile*>( 
            cardId, 
            new SupplyPile( cardId, cardsAvailable ) ) );
}

const SupplyPile* SupplyPileManager::Find( const CARDID cardId ) const
{
    SupplyPileMapConstIter iter = m_SupplyPiles.find( cardId );

    if( iter != m_SupplyPiles.end() )
    {
        return iter->second;
    }

    return m_pNullPile;
}

SupplyPile* SupplyPileManager::Find( const CARDID cardId )
{
    SupplyPileMapIter iter = m_SupplyPiles.find( cardId );

    if( iter != m_SupplyPiles.end() )
    {
        return iter->second;
    }

    return m_pNullPile;
}

int SupplyPileManager::NumEmptyPiles( void ) const
{
    int numEmptyPiles = 0;

    for( SupplyPileMapConstIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++ )
    {
        if( iter->second->CardsAvailable() <= 0 )
        {
            numEmptyPiles++;
        }
    }

    return numEmptyPiles;
}

bool SupplyPileManager::IsPileEmpty( const CARDID cardId ) const
{
    return ( this->CardsAvailable( cardId ) <= 0 );
}

int SupplyPileManager::CardsAvailable( const CARDID cardId ) const
{
    const SupplyPile* pSupplyPile = Find( cardId );
    return pSupplyPile->CardsAvailable();    
}

void SupplyPileManager::AddCard( const CARDID cardId )
{
    SupplyPile* pSupplyPile = Find( cardId );
    pSupplyPile->AddCard();
}

void SupplyPileManager::AddCard( const Card* pCard )
{
    AddCard( pCard->CardId() );
}

void SupplyPileManager::RemoveCard( const CARDID cardId )
{
    SupplyPile* pSupplyPile = Find( cardId );
    pSupplyPile->RemoveCard();
}

void SupplyPileManager::Clear()
{
    m_SupplyPiles.clear();
}

bool SupplyPileManager::IsPileAvailable( const CARDID cardId )
{
    SupplyPileMapIter iter = m_SupplyPiles.find( cardId );

    if( iter == m_SupplyPiles.end() )
    {
        return false;
    }
    
    return true;
}

bool SupplyPileManager::IsPileAvailable( const Card* pCard )
{
    return IsPileAvailable( pCard->CardId() );
}

CardList SupplyPileManager::PilesAvailable( void )
{
    CardList cardList;

    for( SupplyPileMapIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++)
    {
        CARDID cardId = (*iter).first;
        SupplyPile* pSupplyPile = (*iter).second;
        if( !pSupplyPile->IsEmpty() )
        {
            cardList.push_back( Card::GetCard( cardId ) );
        }
    }

    return cardList;
}

bool SupplyPileManager::PileExists( const CARDID cardId ) const
{
    SupplyPileMapConstIter iter = m_SupplyPiles.find( cardId );
    if( iter != m_SupplyPiles.end() )
    {
        return true;
    }

    return false;
}

void SupplyPileManager::SetContrabandCard( const Card* pCard )
{
    if( PileExists( pCard->CardId() ) )
    {
        SupplyPileMapIter iter = m_SupplyPiles.find( pCard->CardId() );
        SupplyPile* pSupplyPile = (*iter).second;
        pSupplyPile->SetContrabandFlag( true );
    }
    else
    {
        // TODO: Error
        throw std::wstring( L"Error: SupplyPileManager::SetContrabandCard" );
    }
}

void SupplyPileManager::ClearContrabandCards( void )
{
    for( SupplyPileMapIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++)
    {
        SupplyPile* pSupplyPile = (*iter).second;
        pSupplyPile->SetContrabandFlag( false );
    }
}

void SupplyPileManager::Embargo( const Card* pCard )
{
    if( PileExists( pCard->CardId() ) )
    {
        SupplyPileMapIter iter = m_SupplyPiles.find( pCard->CardId() );
        SupplyPile* pSupplyPile = (*iter).second;
        pSupplyPile->AddEmbargoToken();
    }
    else
    {
        // TODO: Error
        throw std::wstring( L"Error: SupplyPileManager::SetContrabandCard" );
    }
}

} // namespace Domlib