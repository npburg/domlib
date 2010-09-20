#pragma once
#include <list>

namespace Domlib
{

class AI;
class ICard;
class IEngine;
class IGame;
class IPlayer;
class IPlayerOther;
class ITreasure;

typedef std::list<ICard*>           ICardList;
typedef ICardList::iterator         ICardListIter;
typedef ICardList::const_iterator   ICardListConstIter;


///////////////////////////////////////////////////////////////////////////////
//
// safe_enum Class
//
///////////////////////////////////////////////////////////////////////////////
template< typename def, typename inner = typename def::type > 
class safe_enum : public def
{
private:
    typedef typename def::type type;
    inner val;
    
public:
    safe_enum( void ) {}
    safe_enum( type v ) : val( v ) {}

    inner underlying( void ) const { return val; }
    
    bool operator == (const safe_enum &s) const { return this->val == s.val; }
    bool operator != (const safe_enum &s) const { return this->val != s.val; }
    bool operator <  (const safe_enum &s) const { return this->val <  s.val; }
    bool operator <= (const safe_enum &s) const { return this->val <= s.val; }
    bool operator >  (const safe_enum &s) const { return this->val >  s.val; }
    bool operator >= (const safe_enum &s) const { return this->val >= s.val; }
};



///////////////////////////////////////////////////////////////////////////////
//
// ICard Class
//
///////////////////////////////////////////////////////////////////////////////

struct CARDID_def
{
    enum type
    {
        UNKNOWN,
        NULLCARD,

        // Common Cards
        COPPER,
        SILVER,
        GOLD,
        ESTATE,
        DUCHY,
        PROVINCE,
        CURSE,

        // Base Set - Kingdom Cards
        ADVENTURER,
        BUREAUCRAT,
        CELLAR,
        CHAPEL,
        CHANCELLOR,
        COUNCILROOM,
        FEAST,
        FESTIVAL,
        GARDENS,
        LABORATORY,
        LIBRARY,
        MARKET,
        MILITIA,
        MINE,
        MOAT,
        MONEYLENDER,
        REMODEL,
        SMITHY,
        SPY,
        THIEF,
        THRONEROOM,
        VILLAGE,
        WITCH,
        WOODCUTTER,
        WORKSHOP,

        // Intrigue - Kingdom Cards
        BARON,
        BRIDGE,
        COPPERSMITH,
        CONSPIRATOR,
        COURTYARD,
        DUKE,
        GREATHALL,
        HAREM,    
        IRONWORKS,
        MASQUERADE,
        MININGVILLAGE,
        MINION,
        NOBLES,
        PAWN,
        SCOUT,
        SABOTEUR,
        SECRETCHAMBER,
        SHANTYTOWN,
        STEWARD,
        SWINDLER,
        TORTURER,
        TRADINGPOST,
        TRIBUTE,
        UPGRADE,
        WISHINGWELL,

        // Seaside - Kingdom Cards
        AMBASSADOR,
        BAZAAR,
        CARAVAN,
        CUTPURSE,
        EMBARGO,
        EXPLORER,
        FISHINGVILLAGE,
        GHOSTSHIP,
        HAVEN,
        ISLAND,
        LIGHTHOUSE,
        LOOKOUT,
        MERCHANTSHIP,
        NATIVEVILLAGE,
        NAVIGATOR,
        OUTPOST,
        PEARLDIVER,
        PIRATESHIP,
        SALVAGER,
        SEAHAG,
        SMUGGLERS,
        TACTICIAN,
        TREASUREMAP,
        TREASURY,
        WAREHOUSE,
        WHARF,

        // Alchemy - Kingdom Cards
        APOTHECARY,
        ALCHEMIST,
        APPRENTICE,
        FAMILIAR,
        GOLEM,
        HERBALIST,
        PHILOSOPHERSSTONE,
        POTION,
        POSSESSION,
        SCRYINGPOOL,
        TRANSMUTE,
        UNIVERSITY,
        VINEYARD,

        // Prosperity - Kingdom Cards
        BANK,
        BISHOP,
        CITY,
        COLONY,
        CONTRABAND,
        COUNTINGHOUSE,
        EXPAND,
        FORGE,
        GOONS,
        GRANDMARKET,
        HOARD,
        KINGSCOURT,
        LOAN,
        MINT,
        MONUMENT,
        MOUNTEBANK,
        PEDDLER,
        PLATINUM,
        QUARRY,
        RABBLE,
        ROYALSEAL,
        TALISMAN,
        TRADEROUTE,
        VAULT,
        VENTURE,
        WATCHTOWER,
        WORKERSVILLAGE,
    };
};
typedef safe_enum< CARDID_def > CARDID;


struct CARDTYPE_def
{
    enum type
    {
        UNKNOWN,

        NULLCARD,

        ACTION,
        ACTION_ATTACK,
        ACTION_REACTION,
        ACTION_VICTORY,
        ACTION_DURATION,

        TREASURE,
        TREASURE_VICTORY,

        VICTORY,

        CURSE,
    };
};
typedef safe_enum< CARDTYPE_def > CARDTYPE;


struct CARDSET_def
{
    enum type
    {
        UNKNOWN     = 0,
        BASE        = ( 1 << 1 ),
        INTRIGUE    = ( 1 << 2 ),
        SEASIDE     = ( 1 << 3 ),
        ALCHEMY     = ( 1 << 4 ),
        PROSPERITY  = ( 1 << 5 ),
    };
};
typedef safe_enum< CARDSET_def > CARDSET;

class Card;

typedef std::list<Card*>            CardList;
typedef CardList::iterator          CardListIter;
typedef CardList::const_iterator    CardListConstIter;

class ICard
{
public:
    virtual ~ICard( void );
    ICard( Card* pCard );
    
    static ICard*       GetCard( CARDID cardId );

    Card*               GetCard( void );
    CARDID              CardId( void ) const;
    CARDTYPE            CardType( void ) const;
    int                 VictoryPoints( IEngine* pEngine ) const;
    ITreasure           Cost( IEngine* pEngine ) const;
    ITreasure           TreasureValue( IEngine* pEngine ) const;
    bool                InList( IEngine* pEngine, ICardList cardList ) const;

    bool IsActionCard( void ) const;
    bool IsAttackCard( void ) const;
    bool IsReactionCard( void ) const;
    bool IsDurationCard( void ) const;
    bool IsTreasureCard( void ) const;
    bool IsVictoryCard( void ) const;
    bool IsCurseCard( void ) const;
    bool IsNullCard( void ) const;
    
private:
    Card*   m_pCard;
};

ICardList   CardListToICardList( const CardList& cardList );
CardList    ICardListToCardList( const ICardList& cardList );


///////////////////////////////////////////////////////////////////////////////
//
// IEngine Class
//
///////////////////////////////////////////////////////////////////////////////
class Engine;
class IEngine
{
public:
    virtual ~IEngine( void );

    Engine*         GetEngine( void );
    bool            IsCardInStock( CARDID cardId );
    ICardList       PilesAvailable( void );
    bool            CardsAvailable( CARDID cardId );
    ICardList       CardsCostingExactly( const ITreasure* cost );
    ICardList       CardsCostingUpTo( const ITreasure* cost );
    IPlayerOther*   GetPreviousPlayer( IPlayer* pPlayer );
    
protected:
    IEngine( Engine* pEngine );
    
private:
    Engine* m_pEngine;
    
    friend Engine;
};


///////////////////////////////////////////////////////////////////////////////
//
// IGame Class
//
///////////////////////////////////////////////////////////////////////////////
class Game;
class IGame
{
public:
    IGame( void );
    virtual ~IGame( void );

    void    RegisterAI( AI* pAI );
    void    RandomizeKingdomCards( int cardSet );
    void    Play( void );
    void*   GetResults( void );
    
private:
    Game* m_pGame;
};


///////////////////////////////////////////////////////////////////////////////
//
// IPlayer Class
//
///////////////////////////////////////////////////////////////////////////////
class Player;
class IPlayerOther
{
public:
    virtual ~IPlayerOther( void );

    virtual int         CardsInHand( void );
    virtual ICardList   GainList( void );
    virtual Player*     GetPlayer( void );

protected:
    IPlayerOther( Player* pPlayer );

    Player* m_pPlayer;
    
    friend IEngine;
};


///////////////////////////////////////////////////////////////////////////////
//
// IPlayer Class
//
///////////////////////////////////////////////////////////////////////////////
class IPlayer : public IPlayerOther
{
public:
    virtual ~IPlayer( void );

    ICardList   GetHand( void );
    int         CardsInHand( void );
    int         CardsInHand( ICard* pCard );
    int         CardsInHand( CARDID cardId );
    int         CardsInHand( CARDTYPE cardType );
    int         ActionsPlayed( void );
    int         GetCardCountInHandType( CARDTYPE cardType );

protected:
    IPlayer( Player* pPlayer );
};


///////////////////////////////////////////////////////////////////////////////
//
// ITreasure Class
//
///////////////////////////////////////////////////////////////////////////////
class Treasure;
class ITreasure
{
public:
    ITreasure( void );
    ITreasure( const Treasure& treasure );
    ITreasure( int coins, int potions );
    virtual ~ITreasure( void );
    
    const ITreasure operator+  (const ITreasure t) const;
          ITreasure operator+= (const ITreasure t);
    const ITreasure operator-  (const ITreasure t) const;
          ITreasure operator-= (const ITreasure t);

    const bool     operator<  (const ITreasure t) const;
    const bool     operator<= (const ITreasure t) const;
    const bool     operator>  (const ITreasure t) const;
    const bool     operator>= (const ITreasure t) const;
    const bool     operator== (const ITreasure t) const;
    const bool     operator!= (const ITreasure t) const;

    int      Coins( void ) const;
    int      Potions( void ) const;

private:
    Treasure* m_pTreasure;
};


///////////////////////////////////////////////////////////////////////////////
//
// IA Class
//
///////////////////////////////////////////////////////////////////////////////

////////////////////////
// Base Set Card Options
////////////////////////
struct ChancellorOpt_def
{
    enum type
    {
        DISCARD_DRAW_DECK,
        NO_OP,
    };
};
typedef safe_enum< ChancellorOpt_def > ChancellorOpt;


struct LibraryOpt_def
{
    enum type
    {
        DISCARD_ACTION_CARD,
        KEEP_ACTION_CARD,
    };
};
typedef safe_enum< LibraryOpt_def > LibraryOpt;


struct SpyOpt_def
{
    enum type
    {
        DISCARD_CARD,
        PUT_BACK_CARD,
    };
};
typedef safe_enum< SpyOpt_def > SpyOpt;


struct ThiefOpt_def
{
    enum type
    {
        TRASH_TREASURE_CARD,
        STEAL_TREASURE_CARD,
    };
};
typedef safe_enum< ThiefOpt_def > ThiefOpt;


////////////////////////////
// Intrigue Set Card Options
////////////////////////////

struct BaronOpt_def
{
    enum type
    {
        DISCARD_ESTATE,
        DO_NOT_DISCARD_ESTATE,
    };
};
typedef safe_enum< BaronOpt_def > BaronOpt;


struct MiningVillageOpt_def
{
    enum type
    {
        TRASH_CARD,
        DO_NOT_TRASH_CARD,
    };
};
typedef safe_enum< MiningVillageOpt_def >  MiningVillageOpt;


struct MinionOpt_def
{
    enum type
    {
        PLUS_2_COINS,
        DISCARD_HAND,
    };
};
typedef safe_enum< MinionOpt_def > MinionOpt;


struct NoblesOpt_def
{
    enum type
    {
        PLUS_3_CARDS,
        PLUS_2_ACTIONS,
    };
};
typedef safe_enum< NoblesOpt_def > NoblesOpt;


struct PawnOpt_def
{
    enum type
    {
        PLUS_1_CARD,
        PLUS_1_ACTION,
        PLUS_1_BUY,
        PLUS_1_COIN,
    };
};
typedef safe_enum< PawnOpt_def > PawnOpt;
typedef std::pair< PawnOpt, PawnOpt > PawnOptPair;


struct StewardOpt_def
{
    enum type
    {
        PLUS_2_CARDS,
        PLUS_2_COINS,
        TRASH_2_CARDS,
    };
};
typedef safe_enum< StewardOpt_def > StewardOpt;


///////////////////////////
// Seaside Set Card Options
///////////////////////////

struct ExplorerOpt_def
{
    enum type
    {
        REVEAL_PROVINCE,
        DO_NOT_REVEAL_PROVINCE,
    };
};
typedef safe_enum< ExplorerOpt_def > ExplorerOpt;


struct ILookoutStruct
{
    ICard* pCardToTrash;
    ICard* pCardToDiscard;
    ICard* PCardToPutBack;
};


struct NativeVillageOpt_def
{
    enum type
    {
        SET_ASIDE_CARD,
        DRAW_CARDS,
    };
};
typedef safe_enum< NativeVillageOpt_def > NativeVillageOpt;


struct PearlDiverOpt_def
{
    enum type
    {
        TOP_OF_DRAWPILE,
        BOTTOM_OF_DRAWPILE,
    };
};
typedef safe_enum< PearlDiverOpt_def > PearlDiverOpt;


struct PirateShipOpt_def
{
    enum type
    {
        ATTACK,
        PLUS_COINS,
    };
};
typedef safe_enum< PirateShipOpt_def > PirateShipOpt;


struct TreasuryOpt_def
{
    enum type
    {
        DISCARD,
        PUT_BACK,
    };
};
typedef safe_enum< TreasuryOpt_def > TreasuryOpt;


///////////////////////////
// Alchemy Set Card Options
///////////////////////////

struct AlchemistOpt_def
{
    enum type
    {
        DISCARD,
        PUT_BACK,
    };
};
typedef safe_enum< AlchemistOpt_def > AlchemistOpt;


struct ScryingPoolOpt_def
{
    enum type
    {
        DISCARD_CARD,
        PUT_BACK_CARD,
    };
};
typedef safe_enum< ScryingPoolOpt_def > ScryingPoolOpt;


///////////////////////////
// Alchemy Set Card Options
///////////////////////////

struct LoanOpt_def
{
    enum type
    {
        DISCARD_CARD,
        TRASH_CARD,
    };
};
typedef safe_enum< LoanOpt_def > LoanOpt;


struct MountebankOpt_def
{
    enum type
    {
        DISCARD_CURSE,
        DO_NOT_DISCARD_CURSE,
    };
};
typedef safe_enum< MountebankOpt_def > MountebankOpt;


struct RoyalSealOpt_def
{
    enum type
    {
        DISCARD_CARD,
        PUT_BACK_CARD,
    };
};
typedef safe_enum< RoyalSealOpt_def > RoyalSealOpt;



class __declspec(novtable) AI
{
public:
    AI( void ) 
    {
        m_pEngine = NULL;
    }

    virtual ~AI( void ) 
    {
        if( m_pEngine )
        {
            delete m_pEngine;
        }
    }

    void SetEngine( IEngine* pEngine )
    {
        m_pEngine = pEngine;
    }


    ////////////////////
    // Engine Interfaces
    ////////////////////

    // Return an Action card from hand to play.
    virtual ICard*              PlayAction( void ) = 0;

    // Return a Treasure card to play.
    virtual ICard*              PlayTreasure( void ) = 0;
    
    // Return a card to buy.
    virtual ICard*              BuyCard( void ) = 0;

    /////////////////////
    // General Interfaces
    /////////////////////

    // Return a reaction card in hand when an Attack card is played.
    virtual ICard*              OnAttack( ICard* pAttackCard ) = 0;

    // Return a card to gain up to the value of cost.
    virtual ICard*              OnGainACard( const ITreasure* cost ) = 0;

    // Return a card to gain of the exact value of cost.
    virtual ICard*              OnGainACardExactly( const ITreasure* cost ) = 0;

    // Return a reordered list of cards to put back on top of the draw pile.
    // The first card in the list is the first card pushed onto the draw pile
    // stack so the last card in the list will be on the top of the draw
    // pile when all the cards have been placed in the draw pile.
    virtual ICardList           OnReturnToDrawPile( ICardList cardList ) = 0;

    // Return a card to trash from hand.
    virtual ICard*              OnTrashCardFromHand( void ) = 0;

    ///////////////////////////
    // Base Set Card Interfaces
    ///////////////////////////

    // Return a Victory card in hand to place on top of the draw pile
    // when Bureaucrat is played.
    virtual ICard*              OnBureaucrat( void ) = 0;

    // Return list of cards from hand to discard when Cellar is played.
    virtual ICardList           OnCellar( void ) = 0;

    // Return a Chancellor option when Chancellor is played.
    virtual ChancellorOpt       OnChancellor( void ) = 0;

    // Return a list of cards from hand to trash when Chapel is played.
    virtual ICardList           OnChapel( void ) = 0;

    // Return a Library option to determine if the Action card is discarded
    // when Library is played.
    virtual LibraryOpt          OnLibrary( ICard* pCard ) = 0;

    // Return a list of cards to discard from hand so the hand size is no
    // greater than 3 when Militia is played.
    virtual ICardList           OnMilitia( void ) = 0;

    // Return a Treasure card from hand to trash when Mine is played.
    virtual ICard*              OnMineTrash( void ) = 0;

    // Return a Treasure card from supply up to the cost when Mine is played.
    virtual ICard*              OnMineGain( const ITreasure* cost ) = 0;

    // Return a card in hand to trash when Remodel is played.
    virtual ICard*              OnRemodel( void ) = 0;

    // Return a Spy option when Spy is played on other.
    virtual SpyOpt              OnSpyOther( ICard* pCard ) = 0;

    // Return a Spy option when Spy is played on self.
    virtual SpyOpt              OnSpySelf( ICard* pCard ) = 0;

    // Return a Thief option to determine if the Treasure card is stolen when 
    // Thief is played.
    virtual ThiefOpt            OnThiefGain( ICard* pCard ) = 0;

    // Return a Treasure Card from the card list to trash when Thief is played.
    virtual ICard*              OnThiefTrash( ICardList cardList ) = 0;

    // Return an Action Card from hand when Throne Room is played.
    virtual ICard*              OnThroneRoom( void ) = 0;

    ///////////////////////////////
    // Intrigue Set Card Interfaces
    ///////////////////////////////

    // Return Baron option  to discard an estate from hand when
    // Baron is played.
    virtual BaronOpt            OnBaron( void ) = 0;

    // Return a card from hand to return to top of draw pile when Courtyard 
    // is played.
    virtual ICard*              OnCourtyard( void ) = 0;

    // Return a card to gain up to cost when Ironworks is played.
    virtual ICard*              OnIronworks( const ITreasure* cost ) = 0;

    // Return a card from hand to pass to the player on the left when
    // Masquerade is played.
    virtual ICard*              OnMasqueradePass( void ) = 0;

    // Return a card from hand to trash when Masquerade is played.
    // (Return null card is choosing to not trash a card.)
    virtual ICard*              OnMasqueradeTrash( void ) = 0;

    // Return a Mining Village option to trash Mining Village card
    // when Mining Village is played.
    virtual MiningVillageOpt    OnMiningVillage( void ) = 0;

    // Return a Minion option to gain 2 coins or discard hand
    // when Minion is played.
    virtual MinionOpt           OnMinion( void ) = 0;

    // Return a Nobles option to draw 3 cards or gain 2 actions 
    // when Nobles is played.
    virtual NoblesOpt           OnNobles( void ) = 0;

    // Return a pair of different Pawn options when Pawn is played.
    virtual PawnOptPair         OnPawn( void ) = 0;

    // Return a list of cards from hand to discard when Secret Chamber 
    // is played.
    virtual ICardList           OnSecretChamber( void ) = 0;

    // Return a list of cards from hand to place on top of the draw pile when
    // Secret Chamber is revealed as a Reaction.
    virtual ICardList           OnSecretChamberReaction( void ) = 0;

    // Return a Steward option to draw 2 cards, gain plus 2 coins or
    // trash 2 cards when Steward is played.
    virtual StewardOpt          OnSteward( void ) = 0;

    // Return a list of 2 cards from hand to trash when Steward is played
    // and trash option was chosen.
    virtual ICardList           OnStewardTrash( void ) = 0;

    // Return a card for another player to gain up to the cost of the card 
    // trashed when Swindler is played.
    virtual ICard*              OnSwindler( ICard* pCard ) = 0;

    // Return a list of 2 cards to discard from hand (or empty list to accept 
    // a Curse card) when Torturer is played.
    virtual ICardList           OnTorturer( void ) = 0;

    // Return a list of 2 cards from hand to trash when Trading Post is played.
    virtual ICardList           OnTradingPost( void ) = 0;

    // Return a card from hand to trash when Upgrade is played.
    virtual ICard*              OnUpgrade( void ) = 0;

    // Return a card to wish for when Wishing Well is played.
    virtual ICard*              OnWishingWell( void ) = 0;

    //////////////////////////////
    // Seaside Set Card Interfaces
    //////////////////////////////

    // Return a card from hand to reveal when Ambassador is played.
    virtual ICard*              OnAmbassadorReveal( void ) = 0;

    // Return the number of cards from hand to put back into supply when 
    // Ambassador is played.
    virtual int                 OnAmbassadorPutBack( ICard* pCard ) = 0;

    // Return a card to Embargo in the supply piles when Embargo is played.
    virtual ICard*              OnEmbargo( void ) = 0;

    // Returns an Explorer option to reveal a province in hand when Explorer
    // is played.
    virtual ExplorerOpt         OnExplorer( void ) = 0;

    // Return a list of cards to put back on DrawPile from hand so the hand 
    // size is no greater than 3 when Ghost Ship is played.
    virtual ICardList           OnGhostShip( void ) = 0;

    // Return a card to place with the Haven card in the duration pile when 
    // Haven is played.
    virtual ICard*              OnHaven( void ) = 0;

    // Return a card from hand to place on Island mat when Island is played.
    virtual ICard*              OnIsland( void ) = 0;

    // Return a struct containing cards to trash, discard and return to draw
    // pile when Lookout is played.
    virtual ILookoutStruct      OnLookout( ICardList cardList ) = 0;

    // Return a Native Village option to set aside card from top of the draw pile 
    // or to draw cards into hand from Native Village mat when Native Village 
    // is played.
    virtual NativeVillageOpt    OnNativeVillage( void ) = 0;

    // Return a reordered list of cards to place on the draw pile (or an empty
    // list to indicate to discard the cards from the list) when Naviagtor
    // is played.
    virtual ICardList           OnNavigator( ICardList cardList ) = 0;

    // Return Pearl Diver option to place reveal card on top of the deck or
    // back to the bottom of the deck when Pearl Diver is played.
    virtual PearlDiverOpt       OnPearlDiver( ICard* pCard ) = 0;

    // Return Pirate Ship option to attack other players or gain the plus
    // coins from Pirate Ship mat when Pirate Ship is played.
    virtual PirateShipOpt       OnPirateShip( void ) = 0;
    
    // Return a card from the list to trash when Pirate Ship is played.
    virtual ICard*              OnPirateShipTrash( ICardList cardList ) = 0;

    // Return a card from hand to trash for plus coins when Salvager is played.
    virtual ICard*              OnSalvager( void ) = 0;

    // Return a card from the list to gain when Smugglers is played.
    virtual ICard*              OnSmugglers( ICardList cardList ) = 0;

    // Return a Treasury option to return the Treasury card to the draw pile
    // when Treasury is played.
    virtual TreasuryOpt         OnTreasury( void ) = 0;

    // Return a list of 3 cards from hand to discard when Warehouse is played.
    virtual ICardList           OnWarehouse( void ) = 0;

    //////////////////////////////
    // Alchemy Set Card Interfaces
    //////////////////////////////

    // Return Alchemist option to put the card back on top of the deck
    // when Alchemist is played.
    virtual AlchemistOpt        OnAlchemist( void ) = 0;

    // Return a card from hand to trash for plus coins when Apprentice
    // is played.
    virtual ICard*              OnApprentice( void ) = 0;

    // Return a reordered list of action cards for the Golem to play
    // when Golem is played.
    virtual ICardList           OnGolem( ICardList cardList ) = 0;

    // Return a Treasure card in-play to put back on deck when Herbalist 
    // is played.
    virtual ICard*              OnHerbalist( void ) = 0;

    // Return a Scrying Pool option when Scrying Pool is played on other.
    virtual ScryingPoolOpt      OnScryingPoolOther( ICard* pCard ) = 0;

    // Return a Scrying Pool option when Scrying Pool is played on self.
    virtual ScryingPoolOpt      OnScryingPoolSelf( ICard* pCard ) = 0;

    // Return a card from hand to trash to gain a card based on its type
    // when Transmute is played.
    virtual ICard*              OnTransmute( void ) = 0;

    // Return an Action card which cost up to 5 coins when University is played.
    virtual ICard*              OnUniversity( void ) = 0;

    /////////////////////////////////
    // Prosperity Set Card Interfaces
    /////////////////////////////////
    
    // Return Loan option to trash or discard the Treasure card draw
    // from deck when Loan is played.
    virtual LoanOpt             OnLoan( ICard* pCard ) = 0;

    // Return a card to trash from hand when Biship is played by self.
    virtual ICard*              OnBishopSelf( void ) = 0;

    // Return a card to trash from hand (or return the Null card to decline
    // to trash a card) when Biship is played by other.
    virtual ICard*              OnBishopOther( void ) = 0;

    // Return a card to block the player to the right from buying this turn
    // when Contraband is played.
    virtual ICard*              OnContraband( void ) = 0;

    // Return number of coppers to draw from discard pile when Counting House
    // is played. 
    virtual int                 OnCountingHouse( int numCoppersInDiscard ) = 0;

    // Return a card to trash from hand to gain a card when Expand is played.
    virtual ICard*              OnExpand( void ) = 0;

    // Return a list of cards from hand to trash to gain a card when
    // Forge is played.
    virtual ICardList           OnForge( void ) = 0;

    // Return a list of cards to discard from hand so the hand size is no
    // greater than 3 when Goons is played.
    virtual ICardList           OnGoons( void ) = 0;

    // Return a card from hand to be played 3 times when King's Court is played.
    virtual ICard*              OnKingsCourt( void ) = 0;

    // Return a card from hand for the Mint to copy when Mint is played.
    virtual ICard*              OnMint( void ) = 0;

    // Return a Mountebank option to discard a curse from hand or gain a curse
    // and coper in discard pile when Mountebank is played.
    virtual MountebankOpt       OnMountebank( void ) = 0;

    // Return a RoyalSeal option to put the card on top of the deck or discard
    // when RoyalSeal is played.
    virtual RoyalSealOpt        OnRoyalSeal( ICard* pCard ) = 0;

    // Return a list of cards to discard from hand to gain plus cards when 
    // Vault is played by self.
    virtual ICardList           OnVaultSelf( void ) = 0;

    // Return a list of 2 cards to discard (or an empty list) to draw a card
    // when Vault is played by other.
    virtual ICardList           OnVaultOther( void ) = 0;

protected:
    IEngine*     m_pEngine;
    IPlayer*     m_pPlayer;
};



} // namespace Domlib