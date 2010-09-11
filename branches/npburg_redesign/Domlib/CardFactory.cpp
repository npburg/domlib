#include "StdAfx.h"
#include "Card.h"
#include "NullCard.h"

// Common Cards
#include "CopperCard.h"
#include "SilverCard.h"
#include "GoldCard.h"
#include "EstateCard.h"
#include "DuchyCard.h"
#include "ProvinceCard.h"
#include "CurseCard.h"

// Base Set Cards
#include "AdventurerCard.h"
#include "BureaucratCard.h"
#include "CellarCard.h"
#include "ChapelCard.h"
#include "ChancellorCard.h"
#include "CouncilRoomCard.h"
#include "FeastCard.h"
#include "FestivalCard.h"
#include "GardensCard.h"
#include "LaboratoryCard.h"
#include "LibraryCard.h"
#include "MarketCard.h"
#include "MilitiaCard.h"
#include "MineCard.h"
#include "MoatCard.h"
#include "MoneylenderCard.h"
#include "RemodelCard.h"
#include "SmithyCard.h"
#include "SpyCard.h"
#include "ThiefCard.h"
#include "ThroneRoomCard.h"
#include "VillageCard.h"
#include "WitchCard.h"
#include "WoodcutterCard.h"
#include "WorkshopCard.h"

// TODO: Add additional inludes for other sets

// Intrigue Set Cards

// Seaside Set Cards

// Alchemy Set Cards

// Prosperity Set Cards


namespace Domlib
{

Card::CardFactory::CardFactory( void )
{
    m_pNullCard = new NullCard();
}

Card::CardFactory::~CardFactory( void )
{
    for( CardMapConstIter iter = m_CardMap.begin();
         iter != m_CardMap.end();
         iter++ )
    {
        delete iter->second;
        m_CardMap.erase( iter );
    }

    delete m_pNullCard;
}

Card* Card::CardFactory::GetCard( CARDID cardId )
{
    if( cardId == CARDID_NULL )
    {
        return m_pNullCard;
    }
    else
    {
        CardMapConstIter iter = m_CardMap.find( cardId );
        
        if( iter == m_CardMap.end() )
        {
            Card* pCard = CreateCard( cardId );
            AddCard( pCard );
            return pCard;
        }

        return iter->second;
    }
}

void Card::CardFactory::AddCard( Card* pCard )
{
    if( pCard->CardId() != CARDID_NULL )
    {
        if( m_CardMap.find( pCard->CardId() ) == m_CardMap.end() )
        {
            m_CardMap.insert(CardMapPair( pCard->CardId(), pCard ) );
        }
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: Card::CardDeck::AddCard" );
    }
}

Card* Card::CardFactory::CreateCard( CARDID cardId )
{
    // TODO: Add code to instantiate requrested card.
    Card* pCard = m_pNullCard;

    switch( cardId )
    {
    // Common Cards
    case CARDID_COPPER:         pCard = new CopperCard();       break;
    case CARDID_SILVER:         pCard = new SilverCard();       break;
    case CARDID_GOLD:           pCard = new GoldCard();         break;
    case CARDID_ESTATE:         pCard = new EstateCard();       break;
    case CARDID_DUCHY:          pCard = new DuchyCard();        break;
    case CARDID_PROVINCE:       pCard = new ProvinceCard();     break;
    case CARDID_CURSE:          pCard = new CurseCard();        break;

    // Base Set Cards
    case CARDID_ADVENTURER:     pCard = new AdventurerCard();   break;
    case CARDID_BUREAUCRAT:     pCard = new BureaucratCard();   break;
    case CARDID_CELLAR:         pCard = new CellarCard();       break;
    case CARDID_CHAPEL:         pCard = new ChapelCard();       break;
    case CARDID_CHANCELLOR:     pCard = new ChancellorCard();   break;
    case CARDID_COUNCILROOM:    pCard = new CouncilRoomCard();  break;
    case CARDID_FEAST:          pCard = new FeastCard();        break;
    case CARDID_FESTIVAL:       pCard = new FestivalCard();     break;
    case CARDID_GARDENS:        pCard = new GardensCard();      break;
    case CARDID_LABORATORY:     pCard = new LaboratoryCard();   break;
    case CARDID_LIBRARY:        pCard = new LibraryCard();      break;
    case CARDID_MARKET:         pCard = new MarketCard();       break;
    case CARDID_MILITIA:        pCard = new MilitiaCard();      break;
    case CARDID_MINE:           pCard = new MineCard();         break;
    case CARDID_MOAT:           pCard = new MoatCard();         break;
    case CARDID_MONEYLENDER:    pCard = new MoneylenderCard();  break;
    case CARDID_REMODEL:        pCard = new RemodelCard();      break;
    case CARDID_SMITHY:         pCard = new SmithyCard();       break;
    case CARDID_SPY:            pCard = new SpyCard();          break;
    case CARDID_THIEF:          pCard = new ThiefCard();        break;
    case CARDID_THRONEROOM:     pCard = new ThroneRoomCard();   break;
    case CARDID_VILLAGE:        pCard = new VillageCard();      break;
    case CARDID_WITCH:          pCard = new WitchCard();        break;
    case CARDID_WOODCUTTER:     pCard = new WoodcutterCard();   break;
    case CARDID_WORKSHOP:       pCard = new WorkshopCard();     break;

    // TODO: Add additional inludes for other sets

    // Intrigue Set Cards

    // Seaside Set Cards

    // Alchemy Set Cards

    // Prosperity Set Cards

    case CARDID_UNKNOWN:
    case CARDID_NULL:
    default:
        // TODO: report error
        throw std::wstring( L"Error: Card::CardDeck::CreateCard" );
        break;
    }

    return pCard;
}


} // namespace Domlib