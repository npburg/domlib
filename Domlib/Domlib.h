#pragma once
#include <list>

namespace Domlib
{

class AI;
class ICard;
class IEngine;
class IGame;
class IPlayer;
class IPlayerSelf;
class ITreasure;

typedef std::list<ICard*>           ICardList;
typedef ICardList::iterator         ICardListIter;
typedef ICardList::const_iterator   ICardListConstIter;


///////////////////////////////////////////////////////////////////////////////
//
// ICard Class
//
///////////////////////////////////////////////////////////////////////////////

enum CARDID
{
    CARDID_UNKNOWN,
    CARDID_NULL,

    // Common Cards
    CARDID_COPPER,
    CARDID_SILVER,
    CARDID_GOLD,
    CARDID_ESTATE,
    CARDID_DUCHY,
    CARDID_PROVINCE,
    CARDID_CURSE,

    // Base Set - Kingdom Cards
    CARDID_ADVENTURER,
    CARDID_BUREAUCRAT,
    CARDID_CELLAR,
    CARDID_CHAPEL,
    CARDID_CHANCELLOR,
    CARDID_COUNCILROOM,
    CARDID_FEAST,
    CARDID_FESTIVAL,
    CARDID_GARDENS,
    CARDID_LABORATORY,
    CARDID_LIBRARY,
    CARDID_MARKET,
    CARDID_MILITIA,
    CARDID_MINE,
    CARDID_MOAT,
    CARDID_MONEYLENDER,
    CARDID_REMODEL,
    CARDID_SMITHY,
    CARDID_SPY,
    CARDID_THIEF,
    CARDID_THRONEROOM,
    CARDID_VILLAGE,
    CARDID_WITCH,
    CARDID_WOODCUTTER,
    CARDID_WORKSHOP,

    // Intrigue - Kingdom Cards
    CARDID_BARON,
    CARDID_BRIDGE,
    CARDID_COPPERSMITH,
    CARDID_CONSPIRATOR,
    CARDID_COURTYARD,
    CARDID_DUKE,
    CARDID_GREATHALL,
    CARDID_HAREM,    
    CARDID_IRONWORKS,
    CARDID_MASQUERADE,
    CARDID_MININGVILLAGE,
    CARDID_MINION,
    CARDID_NOBLES,
    CARDID_PAWN,
    CARDID_SCOUT,
    CARDID_SABOTEUR,
    CARDID_SECRETCHAMBER,
    CARDID_SHANTYTOWN,
    CARDID_STEWARD,
    CARDID_SWINDLER,
    CARDID_TORTURER,
    CARDID_TRADINGPOST,
    CARDID_TRIBUTE,
    CARDID_UPGRADE,
    CARDID_WISHINGWELL,

    // Seaside - Kingdom Cards
    CARDID_AMBASSADOR,
    CARDID_BAZAAR,
    CARDID_CARAVAN,
    CARDID_CUTPURSE,
    CARDID_EMBARGO,
    CARDID_EXPLORER,
    CARDID_FISHINGVILLAGE,
    CARDID_GHOSTSHIP,
    CARDID_HAVEN,
    CARDID_ISLAND,
    CARDID_LIGHTHOUSE,
    CARDID_LOOKOUT,
    CARDID_MERCHANTSHIP,
    CARDID_NATIVEVILLAGE,
    CARDID_NAVIGATOR,
    CARDID_OUTPOST,
    CARDID_PEARLDIVER,
    CARDID_PIRATESHIP,
    CARDID_SALVAGER,
    CARDID_SEAHAG,
    CARDID_SMUGGLERS,
    CARDID_TACTICIAN,
    CARDID_TREASUREMAP,
    CARDID_TREASURY,
    CARDID_WAREHOUSE,
    CARDID_WHARF,

    // Alchemy - Kingdom Cards
    CARDID_APOTHECARY,
    CARDID_ALCHEMIST,
    CARDID_APPRENTICE,
    CARDID_FAMILIAR,
    CARDID_GOLEM,
    CARDID_HERBALIST,
    CARDID_PHILOSOPHERSSTONE,
    CARDID_POTION,
    CARDID_POSSESSION,
    CARDID_SCRYINGPOOL,
    CARDID_TRANSMUTE,
    CARDID_UNIVERSITY,
    CARDID_VINEYARD,

    // Prosperity - Kingdom Cards
    CARDID_BANK,
    CARDID_BISHOP,
    CARDID_CITY,
    CARDID_CONTRABAND,
    CARDID_COUNTINGHOUSE,
    CARDID_EXPAND,
    CARDID_FORGE,
    CARDID_GOONS,
    CARDID_GRANDMARKET,
    CARDID_HOARD,
    CARDID_KINGSCOURT,
    CARDID_LOAN,
    CARDID_MINT,
    CARDID_MONUMENT,
    CARDID_MOUNTEBANK,
    CARDID_PEDDLER,
    CARDID_QUARRY,
    CARDID_RABBLE,
    CARDID_ROYALSEAL,
    CARDID_TALISMAN,
    CARDID_TRADEROUTE,
    CARDID_VAULT,
    CARDID_VENTURE,
    CARDID_WATCHTOWER,
    CARDID_WORKERSVILLAGE,

    // Promo - Kingdom Cards
    // TBD
};

enum CARDTYPE
{
    CARDTYPE_UNKNOWN,

    CARDTYPE_NULL,

    CARDTYPE_ACTION,
    CARDTYPE_ACTION_ATTACK,
    CARDTYPE_ACTION_REACTION,
    CARDTYPE_ACTION_VICTORY,
    CARDTYPE_ACTION_DURATION,

    CARDTYPE_TREASURE,
    CARDTYPE_TREASURE_VICTORY,

    CARDTYPE_VICTORY,

    CARDTYPE_CURSE,
};

enum CARDSET
{
    CARDSET_UNKNOWN     = 0,
    CARDSET_BASE        = ( 1 << 1 ),
    CARDSET_INTRIGUE    = ( 1 << 2 ),
    CARDSET_SEASIDE     = ( 1 << 3 ),
    CARDSET_ALCHEMY     = ( 1 << 4 ),
    CARDSET_PROSPERITY  = ( 1 << 5 ),
};

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

    Engine*     GetEngine( void );
    bool        IsCardInStock( CARDID cardId );
    bool        CardsAvailable( CARDID cardId );
    
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

    void    RegisterAI( AI* pAi );
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
// TODO: Need to split this class into Player-Self and Player-Other since
//       an AI should be able to access more information about the Player-Self
//       than it can access about Player-Other.
//
///////////////////////////////////////////////////////////////////////////////
class Player;
class IPlayer
{
public:
    virtual ~IPlayer( void );

    ICardList   GetHand( void );
    int         CardsInHand( void );
    int         CardsInHand( ICard* pCard );
    int         CardsInHand( CARDID cardId );
    int         ActionsPlayed( void );
    int         GetCardCountInHandType( CARDTYPE cardType );

protected:
    IPlayer( Player* pPlayer );
    
private:
    Player* m_pPlayer;
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

enum ChancellorOpt
{
    CHANCELLOR_DISCARD_DRAW_DECK,
    CHANCELLOR_NO_OP,
};

enum LibraryOpt
{
    LIBRARY_DISCARD_ACTION_CARD,
    LIBRARY_KEEP_ACTION_CARD,
};

enum SpyOpt
{
    SPY_DISCARD_CARD,
    SPY_PUT_BACK_CARD,
};

enum ThiefOpt
{
    THIEF_TRASH_TREASURE_CARD,
    THIEF_STEAL_TREASURE_CARD,
};


////////////////////////////
// Intrigue Set Card Options
////////////////////////////

enum BaronOpt
{
    BARON_DISCARD_ESTATE,
    BARON_DO_NOT_DISCARD_ESTATE,
};

enum MiningVillageOpt
{
    MININGVILLAGE_TRASH_CARD,
    MININGVILLAGE_DO_NOT_TRASH_CARD,
};

enum MinionOpt
{
    MINION_PLUS_2_COINS,
    MINION_DISCARD_HAND,
};

enum NoblesOpt
{
    NOBLES_PLUS_3_CARDS,
    NOBLES_PLUS_2_ACTIONS,
};

enum PawnOpt
{
    PAWN_PLUS_1_CARD,
    PAWN_PLUS_1_ACTION,
    PAWN_PLUS_1_BUY,
    PAWN_PLUS_1_COIN,
};

typedef std::pair<PawnOpt, PawnOpt> PawnOptPair;

enum StewardOpt
{
    STEWARD_PLUS_2_CARDS,
    STEWARD_PLUS_2_COINS,
    STEWARD_TRASH_2_CARDS,
};

///////////////////////////
// Seaside Set Card Options
///////////////////////////

enum ExplorerOpt
{
    EXPLORER_REVEAL_PROVINCE,
    EXPLORER_DO_NOT_REVEAL_PROVINCE,
};

struct ILookoutStruct
{
    ICard* pCardToTrash;
    ICard* pCardToDiscard;
    ICard* PCardToPutBack;
};

enum NativeVillageOpt
{
    NATIVEVILLAGE_SET_ASIDE_CARD,
    NATIVEVILLAGE_DRAW_CARDS,
};

enum PearlDiverOpt
{
    PEARLDIVER_TOP_OF_DRAWPILE,
    PEARLDIVER_BOTTOM_OF_DRAWPILE,
};

enum PirateShipOpt
{
    PIRATESHIP_ATTACK,
    PIRATESHIP_PLUS_COINS,
};

enum TreasuryOpt
{
    TREASURY_DISCARD,
    TREASURY_PUT_BACK,
};

///////////////////////////
// Alchemy Set Card Options
///////////////////////////

enum AlchemistOpt
{
    ALCHEMIST_DISCARD,
    ALCHEMIST_PUT_BACK,
};

enum ScryingPoolOpt
{
    SCRYINGPOOL_DISCARD_CARD,
    SCRYINGPOOL_PUT_BACK_CARD,
};

///////////////////////////
// Alchemy Set Card Options
///////////////////////////

enum LoanOpt
{
    LOAN_DISCARD_CARD,
    LOAN_TRASH_CARD,
};

enum MountebankOpt
{
    MOUNTEBANK_DISCARD_CURSE,
    MOUNTEBANK_DO_NOT_DISCARD_CURSE,
};

enum RoyalSealOpt
{
    ROYALSEAL_DISCARD_CARD,
    ROYALSEAL_PUT_BACK_CARD,
};

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

    // Return a card to trash from hand (or return the Null card to decline
    // to trash a card) when Biship is played.
    virtual ICard*              OnBiship( void ) = 0;

    // Return a card to block the player to the right from buying this turn
    // when Contraband is played.
    virtual ICard*              OnContraband( void ) = 0;

    // Return number of coppers to draw from discard pile when Counting House
    // is played. (Discard pile is passed to the function since it is normally
    // illegal to look through the discard pile.)
    virtual int                 OnCountingHouse( ICardList cardList ) = 0;

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
    virtual ICardList           OnValueOther( void ) = 0;

protected:
    IEngine*     m_pEngine;
};



} // namespace Domlib