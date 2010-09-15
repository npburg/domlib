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
    case CARDID_COPPER:             pCard = new CopperCard();               break;
    case CARDID_SILVER:             pCard = new SilverCard();               break;
    case CARDID_GOLD:               pCard = new GoldCard();                 break;
    case CARDID_ESTATE:             pCard = new EstateCard();               break;
    case CARDID_DUCHY:              pCard = new DuchyCard();                break;
    case CARDID_PROVINCE:           pCard = new ProvinceCard();             break;
    case CARDID_CURSE:              pCard = new CurseCard();                break;

    // Base Set Cards
    case CARDID_ADVENTURER:         pCard = new AdventurerCard();           break;
    case CARDID_BUREAUCRAT:         pCard = new BureaucratCard();           break;
    case CARDID_CELLAR:             pCard = new CellarCard();               break;
    case CARDID_CHAPEL:             pCard = new ChapelCard();               break;
    case CARDID_CHANCELLOR:         pCard = new ChancellorCard();           break;
    case CARDID_COUNCILROOM:        pCard = new CouncilRoomCard();          break;
    case CARDID_FEAST:              pCard = new FeastCard();                break;
    case CARDID_FESTIVAL:           pCard = new FestivalCard();             break;
    case CARDID_GARDENS:            pCard = new GardensCard();              break;
    case CARDID_LABORATORY:         pCard = new LaboratoryCard();           break;
    case CARDID_LIBRARY:            pCard = new LibraryCard();              break;
    case CARDID_MARKET:             pCard = new MarketCard();               break;
    case CARDID_MILITIA:            pCard = new MilitiaCard();              break;
    case CARDID_MINE:               pCard = new MineCard();                 break;
    case CARDID_MOAT:               pCard = new MoatCard();                 break;
    case CARDID_MONEYLENDER:        pCard = new MoneylenderCard();          break;
    case CARDID_REMODEL:            pCard = new RemodelCard();              break;
    case CARDID_SMITHY:             pCard = new SmithyCard();               break;
    case CARDID_SPY:                pCard = new SpyCard();                  break;
    case CARDID_THIEF:              pCard = new ThiefCard();                break;
    case CARDID_THRONEROOM:         pCard = new ThroneRoomCard();           break;
    case CARDID_VILLAGE:            pCard = new VillageCard();              break;
    case CARDID_WITCH:              pCard = new WitchCard();                break;
    case CARDID_WOODCUTTER:         pCard = new WoodcutterCard();           break;
    case CARDID_WORKSHOP:           pCard = new WorkshopCard();             break;

    // Intrigue Set Cards
    case CARDID_BARON:              pCard = new BaronCard();                break;
    case CARDID_BRIDGE:             pCard = new BridgeCard();               break;
    case CARDID_CONSPIRATOR:        pCard = new ConspiratorCard();          break;
    case CARDID_COPPERSMITH:        pCard = new CoppersmithCard();          break;
    case CARDID_COURTYARD:          pCard = new CourtyardCard();            break;
    case CARDID_DUKE:               pCard = new DukeCard();                 break;
    case CARDID_GREATHALL:          pCard = new GreatHallCard();            break;
    case CARDID_HAREM:              pCard = new HaremCard();                break;
    case CARDID_IRONWORKS:          pCard = new IronworksCard();            break;
    case CARDID_MASQUERADE:         pCard = new MasqueradeCard();           break;
    case CARDID_MININGVILLAGE:      pCard = new MiningVillageCard();        break;
    case CARDID_MINION:             pCard = new MinionCard();               break;
    case CARDID_NOBLES:             pCard = new NoblesCard();               break;
    case CARDID_PAWN:               pCard = new PawnCard();                 break;
    case CARDID_SABOTEUR:           pCard = new SaboteurCard();             break;
    case CARDID_SCOUT:              pCard = new ScoutCard();                break;
    case CARDID_SECRETCHAMBER:      pCard = new SecretChamberCard();        break;
    case CARDID_SHANTYTOWN:         pCard = new ShantyTownCard();           break;
    case CARDID_STEWARD:            pCard = new StewardCard();              break;
    case CARDID_SWINDLER:           pCard = new SwindlerCard();             break;
    case CARDID_TORTURER:           pCard = new TorturerCard();             break;
    case CARDID_TRADINGPOST:        pCard = new TradingPostCard();          break;
    case CARDID_TRIBUTE:            pCard = new TributeCard();              break;
    case CARDID_UPGRADE:            pCard = new UpgradeCard();              break;
    case CARDID_WISHINGWELL:        pCard = new WishingWellCard();          break;

    // Seaside Set Cards
    case CARDID_AMBASSADOR:         pCard = new AmbassadorCard();           break;
    case CARDID_BAZAAR:             pCard = new BazaarCard();               break;
    case CARDID_CARAVAN:            pCard = new CaravanCard();              break;
    case CARDID_CUTPURSE:           pCard = new CutpurseCard();             break;
    case CARDID_EMBARGO:            pCard = new EmbargoCard();              break;
    case CARDID_EXPLORER:           pCard = new ExplorerCard();             break;
    case CARDID_FISHINGVILLAGE:     pCard = new FishingVillageCard();       break;
    case CARDID_GHOSTSHIP:          pCard = new GhostShipCard();            break;
    case CARDID_HAVEN:              pCard = new HavenCard();                break;
    case CARDID_ISLAND:             pCard = new IslandCard();               break;
    case CARDID_LIGHTHOUSE:         pCard = new LighthouseCard();           break;
    case CARDID_LOOKOUT:            pCard = new LookoutCard();              break;
    case CARDID_MERCHANTSHIP:       pCard = new MerchantShipCard();         break;
    case CARDID_NATIVEVILLAGE:      pCard = new NativeVillageCard();        break;
    case CARDID_NAVIGATOR:          pCard = new NavigatorCard();            break;
    case CARDID_OUTPOST:            pCard = new OutpostCard();              break;
    case CARDID_PEARLDIVER:         pCard = new PearlDiverCard();           break;
    case CARDID_PIRATESHIP:         pCard = new PirateShipCard();           break;
    case CARDID_SALVAGER:           pCard = new SalvagerCard();             break;
    case CARDID_SEAHAG:             pCard = new SeaHagCard();               break;
    case CARDID_SMUGGLERS:          pCard = new SmugglersCard();            break;
    case CARDID_TACTICIAN:          pCard = new TacticianCard();            break;
    case CARDID_TREASUREMAP:        pCard = new TreasureMapCard();          break;
    case CARDID_TREASURY:           pCard = new TreasuryCard();             break;
    case CARDID_WAREHOUSE:          pCard = new WarehouseCard();            break;
    case CARDID_WHARF:              pCard = new WharfCard();                break;

    // Alchemy Set Cards
    case CARDID_ALCHEMIST:          pCard = new AlchemistCard();            break;
    case CARDID_APOTHECARY:         pCard = new ApothecaryCard();           break;
    case CARDID_APPRENTICE:         pCard = new ApprenticeCard();           break;
    case CARDID_FAMILIAR:           pCard = new FamiliarCard();             break;
    case CARDID_GOLEM:              pCard = new GolemCard();                break;
    case CARDID_HERBALIST:          pCard = new HerbalistCard();            break;
    case CARDID_PHILOSOPHERSSTONE:  pCard = new PhilosophersStoneCard();    break;
    case CARDID_POSSESSION:         pCard = new PossessionCard();           break;
    case CARDID_POTION:             pCard = new PotionCard();               break;
    case CARDID_SCRYINGPOOL:        pCard = new ScryingPoolCard();          break;
    case CARDID_TRANSMUTE:          pCard = new TransmuteCard();            break;
    case CARDID_UNIVERSITY:         pCard = new UniversityCard();           break;
    case CARDID_VINEYARD:           pCard = new VineyardCard();             break;

    // Prosperity Set Cards
    case CARDID_BANK:               pCard = new BankCard();                 break;
    case CARDID_BISHOP:             pCard = new BishopCard();               break;
    case CARDID_CITY:               pCard = new CityCard();                 break;
    case CARDID_COLONY:             pCard = new ColonyCard();               break;
    case CARDID_CONTRABAND:         pCard = new ContrabandCard();           break;
    case CARDID_COUNTINGHOUSE:      pCard = new CountingHouseCard();        break;
    case CARDID_EXPAND:             pCard = new ExpandCard();               break;
    case CARDID_FORGE:              pCard = new ForgeCard();                break;
    case CARDID_GOONS:              pCard = new GoonsCard();                break;
    case CARDID_GRANDMARKET:        pCard = new GrandMarketCard();          break;
    case CARDID_HOARD:              pCard = new HoardCard();                break;
    case CARDID_KINGSCOURT:         pCard = new KingsCourtCard();           break;
    case CARDID_LOAN:               pCard = new LoanCard();                 break;
    case CARDID_MINT:               pCard = new MintCard();                 break;
    case CARDID_MONUMENT:           pCard = new MonumentCard();             break;
    case CARDID_MOUNTEBANK:         pCard = new MountebankCard();           break;
    case CARDID_PEDDLER:            pCard = new PeddlerCard();              break;
    case CARDID_PLATINUM:           pCard = new PlatinumCard();             break;
    case CARDID_QUARRY:             pCard = new QuarryCard();               break;
    case CARDID_RABBLE:             pCard = new RabbleCard();               break;
    case CARDID_ROYALSEAL:          pCard = new RoyalSealCard();            break;
    case CARDID_TALISMAN:           pCard = new TalismanCard();             break;
    case CARDID_TRADEROUTE:         pCard = new TradeRouteCard();           break;
    case CARDID_VAULT:              pCard = new VaultCard();                break;
    case CARDID_VENTURE:            pCard = new VentureCard();              break;
    case CARDID_WATCHTOWER:         pCard = new WatchtowerCard();           break;
    case CARDID_WORKERSVILLAGE:     pCard = new WorkersVillageCard();       break;

    // Invalid cases
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