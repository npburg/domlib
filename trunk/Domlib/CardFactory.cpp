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

// Intrigue Set Cards
#include "BaronCard.h"
#include "BridgeCard.h"
#include "ConspiratorCard.h"
#include "CoppersmithCard.h"
#include "CourtyardCard.h"
#include "DukeCard.h"
#include "GreatHallCard.h"
#include "HaremCard.h"
#include "IronworksCard.h"
#include "MasqueradeCard.h"
#include "MiningVillageCard.h"
#include "MinionCard.h"
#include "NoblesCard.h"
#include "PawnCard.h"
#include "SaboteurCard.h"
#include "ScoutCard.h"
#include "SecretChamberCard.h"
#include "ShantyTownCard.h"
#include "StewardCard.h"
#include "SwindlerCard.h"
#include "TorturerCard.h"
#include "TradingPostCard.h"
#include "TributeCard.h"
#include "UpgradeCard.h"
#include "WishingWellCard.h"

// Seaside Set Cards
#include "AmbassadorCard.h"
#include "BazaarCard.h"
#include "CaravanCard.h"
#include "CutpurseCard.h"
#include "EmbargoCard.h"
#include "ExplorerCard.h"
#include "FishingVillageCard.h"
#include "GhostShipCard.h"
#include "HavenCard.h"
#include "IslandCard.h"
#include "LighthouseCard.h"
#include "LookoutCard.h"
#include "MerchantShipCard.h"
#include "NativeVillageCard.h"
#include "NavigatorCard.h"
#include "OutpostCard.h"
#include "PearlDiverCard.h"
#include "PirateShipCard.h"
#include "SalvagerCard.h"
#include "SeaHagCard.h"
#include "SmugglersCard.h"
#include "TacticianCard.h"
#include "TreasureMapCard.h"
#include "TreasuryCard.h"
#include "WarehouseCard.h"
#include "WharfCard.h"

// Alchemy Set Cards
#include "AlchemistCard.h"
#include "ApothecaryCard.h"
#include "ApprenticeCard.h"
#include "FamiliarCard.h"
#include "GolemCard.h"
#include "HerbalistCard.h"
#include "PhilosophersStoneCard.h"
#include "PossessionCard.h"
#include "PotionCard.h"
#include "ScryingPoolCard.h"
#include "TransmuteCard.h"
#include "UniversityCard.h"
#include "VineyardCard.h"

// Prosperity Set Cards
#include "BankCard.h"
#include "BishopCard.h"
#include "CityCard.h"
#include "ColonyCard.h"
#include "ContrabandCard.h"
#include "CountingHouseCard.h"
#include "ExpandCard.h"
#include "ForgeCard.h"
#include "GoonsCard.h"
#include "GrandMarketCard.h"
#include "HoardCard.h"
#include "KingsCourtCard.h"
#include "LoanCard.h"
#include "MintCard.h"
#include "MonumentCard.h"
#include "MountebankCard.h"
#include "PeddlerCard.h"
#include "PlatinumCard.h"
#include "QuarryCard.h"
#include "RabbleCard.h"
#include "RoyalSealCard.h"
#include "TalismanCard.h"
#include "TradeRouteCard.h"
#include "VaultCard.h"
#include "VentureCard.h"
#include "WatchtowerCard.h"
#include "WorkersVillageCard.h"

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
    if( cardId == CARDID::NULLCARD )
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
    if( pCard->CardId() != CARDID::NULLCARD )
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
    case CARDID::COPPER:             pCard = new CopperCard();               break;
    case CARDID::SILVER:             pCard = new SilverCard();               break;
    case CARDID::GOLD:               pCard = new GoldCard();                 break;
    case CARDID::ESTATE:             pCard = new EstateCard();               break;
    case CARDID::DUCHY:              pCard = new DuchyCard();                break;
    case CARDID::PROVINCE:           pCard = new ProvinceCard();             break;
    case CARDID::CURSE:              pCard = new CurseCard();                break;

    // Base Set Cards
    case CARDID::ADVENTURER:         pCard = new AdventurerCard();           break;
    case CARDID::BUREAUCRAT:         pCard = new BureaucratCard();           break;
    case CARDID::CELLAR:             pCard = new CellarCard();               break;
    case CARDID::CHAPEL:             pCard = new ChapelCard();               break;
    case CARDID::CHANCELLOR:         pCard = new ChancellorCard();           break;
    case CARDID::COUNCILROOM:        pCard = new CouncilRoomCard();          break;
    case CARDID::FEAST:              pCard = new FeastCard();                break;
    case CARDID::FESTIVAL:           pCard = new FestivalCard();             break;
    case CARDID::GARDENS:            pCard = new GardensCard();              break;
    case CARDID::LABORATORY:         pCard = new LaboratoryCard();           break;
    case CARDID::LIBRARY:            pCard = new LibraryCard();              break;
    case CARDID::MARKET:             pCard = new MarketCard();               break;
    case CARDID::MILITIA:            pCard = new MilitiaCard();              break;
    case CARDID::MINE:               pCard = new MineCard();                 break;
    case CARDID::MOAT:               pCard = new MoatCard();                 break;
    case CARDID::MONEYLENDER:        pCard = new MoneylenderCard();          break;
    case CARDID::REMODEL:            pCard = new RemodelCard();              break;
    case CARDID::SMITHY:             pCard = new SmithyCard();               break;
    case CARDID::SPY:                pCard = new SpyCard();                  break;
    case CARDID::THIEF:              pCard = new ThiefCard();                break;
    case CARDID::THRONEROOM:         pCard = new ThroneRoomCard();           break;
    case CARDID::VILLAGE:            pCard = new VillageCard();              break;
    case CARDID::WITCH:              pCard = new WitchCard();                break;
    case CARDID::WOODCUTTER:         pCard = new WoodcutterCard();           break;
    case CARDID::WORKSHOP:           pCard = new WorkshopCard();             break;

    // Intrigue Set Cards
    case CARDID::BARON:              pCard = new BaronCard();                break;
    case CARDID::BRIDGE:             pCard = new BridgeCard();               break;
    case CARDID::CONSPIRATOR:        pCard = new ConspiratorCard();          break;
    case CARDID::COPPERSMITH:        pCard = new CoppersmithCard();          break;
    case CARDID::COURTYARD:          pCard = new CourtyardCard();            break;
    case CARDID::DUKE:               pCard = new DukeCard();                 break;
    case CARDID::GREATHALL:          pCard = new GreatHallCard();            break;
    case CARDID::HAREM:              pCard = new HaremCard();                break;
    case CARDID::IRONWORKS:          pCard = new IronworksCard();            break;
    case CARDID::MASQUERADE:         pCard = new MasqueradeCard();           break;
    case CARDID::MININGVILLAGE:      pCard = new MiningVillageCard();        break;
    case CARDID::MINION:             pCard = new MinionCard();               break;
    case CARDID::NOBLES:             pCard = new NoblesCard();               break;
    case CARDID::PAWN:               pCard = new PawnCard();                 break;
    case CARDID::SABOTEUR:           pCard = new SaboteurCard();             break;
    case CARDID::SCOUT:              pCard = new ScoutCard();                break;
    case CARDID::SECRETCHAMBER:      pCard = new SecretChamberCard();        break;
    case CARDID::SHANTYTOWN:         pCard = new ShantyTownCard();           break;
    case CARDID::STEWARD:            pCard = new StewardCard();              break;
    case CARDID::SWINDLER:           pCard = new SwindlerCard();             break;
    case CARDID::TORTURER:           pCard = new TorturerCard();             break;
    case CARDID::TRADINGPOST:        pCard = new TradingPostCard();          break;
    case CARDID::TRIBUTE:            pCard = new TributeCard();              break;
    case CARDID::UPGRADE:            pCard = new UpgradeCard();              break;
    case CARDID::WISHINGWELL:        pCard = new WishingWellCard();          break;

    // Seaside Set Cards
    case CARDID::AMBASSADOR:         pCard = new AmbassadorCard();           break;
    case CARDID::BAZAAR:             pCard = new BazaarCard();               break;
    case CARDID::CARAVAN:            pCard = new CaravanCard();              break;
    case CARDID::CUTPURSE:           pCard = new CutpurseCard();             break;
    case CARDID::EMBARGO:            pCard = new EmbargoCard();              break;
    case CARDID::EXPLORER:           pCard = new ExplorerCard();             break;
    case CARDID::FISHINGVILLAGE:     pCard = new FishingVillageCard();       break;
    case CARDID::GHOSTSHIP:          pCard = new GhostShipCard();            break;
    case CARDID::HAVEN:              pCard = new HavenCard();                break;
    case CARDID::ISLAND:             pCard = new IslandCard();               break;
    case CARDID::LIGHTHOUSE:         pCard = new LighthouseCard();           break;
    case CARDID::LOOKOUT:            pCard = new LookoutCard();              break;
    case CARDID::MERCHANTSHIP:       pCard = new MerchantShipCard();         break;
    case CARDID::NATIVEVILLAGE:      pCard = new NativeVillageCard();        break;
    case CARDID::NAVIGATOR:          pCard = new NavigatorCard();            break;
    case CARDID::OUTPOST:            pCard = new OutpostCard();              break;
    case CARDID::PEARLDIVER:         pCard = new PearlDiverCard();           break;
    case CARDID::PIRATESHIP:         pCard = new PirateShipCard();           break;
    case CARDID::SALVAGER:           pCard = new SalvagerCard();             break;
    case CARDID::SEAHAG:             pCard = new SeaHagCard();               break;
    case CARDID::SMUGGLERS:          pCard = new SmugglersCard();            break;
    case CARDID::TACTICIAN:          pCard = new TacticianCard();            break;
    case CARDID::TREASUREMAP:        pCard = new TreasureMapCard();          break;
    case CARDID::TREASURY:           pCard = new TreasuryCard();             break;
    case CARDID::WAREHOUSE:          pCard = new WarehouseCard();            break;
    case CARDID::WHARF:              pCard = new WharfCard();                break;

    // Alchemy Set Cards
    case CARDID::ALCHEMIST:          pCard = new AlchemistCard();            break;
    case CARDID::APOTHECARY:         pCard = new ApothecaryCard();           break;
    case CARDID::APPRENTICE:         pCard = new ApprenticeCard();           break;
    case CARDID::FAMILIAR:           pCard = new FamiliarCard();             break;
    case CARDID::GOLEM:              pCard = new GolemCard();                break;
    case CARDID::HERBALIST:          pCard = new HerbalistCard();            break;
    case CARDID::PHILOSOPHERSSTONE:  pCard = new PhilosophersStoneCard();    break;
    case CARDID::POSSESSION:         pCard = new PossessionCard();           break;
    case CARDID::POTION:             pCard = new PotionCard();               break;
    case CARDID::SCRYINGPOOL:        pCard = new ScryingPoolCard();          break;
    case CARDID::TRANSMUTE:          pCard = new TransmuteCard();            break;
    case CARDID::UNIVERSITY:         pCard = new UniversityCard();           break;
    case CARDID::VINEYARD:           pCard = new VineyardCard();             break;

    // Prosperity Set Cards
    case CARDID::BANK:               pCard = new BankCard();                 break;
    case CARDID::BISHOP:             pCard = new BishopCard();               break;
    case CARDID::CITY:               pCard = new CityCard();                 break;
    case CARDID::COLONY:             pCard = new ColonyCard();               break;
    case CARDID::CONTRABAND:         pCard = new ContrabandCard();           break;
    case CARDID::COUNTINGHOUSE:      pCard = new CountingHouseCard();        break;
    case CARDID::EXPAND:             pCard = new ExpandCard();               break;
    case CARDID::FORGE:              pCard = new ForgeCard();                break;
    case CARDID::GOONS:              pCard = new GoonsCard();                break;
    case CARDID::GRANDMARKET:        pCard = new GrandMarketCard();          break;
    case CARDID::HOARD:              pCard = new HoardCard();                break;
    case CARDID::KINGSCOURT:         pCard = new KingsCourtCard();           break;
    case CARDID::LOAN:               pCard = new LoanCard();                 break;
    case CARDID::MINT:               pCard = new MintCard();                 break;
    case CARDID::MONUMENT:           pCard = new MonumentCard();             break;
    case CARDID::MOUNTEBANK:         pCard = new MountebankCard();           break;
    case CARDID::PEDDLER:            pCard = new PeddlerCard();              break;
    case CARDID::PLATINUM:           pCard = new PlatinumCard();             break;
    case CARDID::QUARRY:             pCard = new QuarryCard();               break;
    case CARDID::RABBLE:             pCard = new RabbleCard();               break;
    case CARDID::ROYALSEAL:          pCard = new RoyalSealCard();            break;
    case CARDID::TALISMAN:           pCard = new TalismanCard();             break;
    case CARDID::TRADEROUTE:         pCard = new TradeRouteCard();           break;
    case CARDID::VAULT:              pCard = new VaultCard();                break;
    case CARDID::VENTURE:            pCard = new VentureCard();              break;
    case CARDID::WATCHTOWER:         pCard = new WatchtowerCard();           break;
    case CARDID::WORKERSVILLAGE:     pCard = new WorkersVillageCard();       break;

    // Invalid cases
    case CARDID::UNKNOWN:
    case CARDID::NULLCARD:
    default:
        // TODO: report error
        throw std::wstring( L"Error: Card::CardDeck::CreateCard" );
        break;
    }

    return pCard;
}


} // namespace Domlib