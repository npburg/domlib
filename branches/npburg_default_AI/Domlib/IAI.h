#pragma once
#include "Domlib.h"

namespace Domlib
{

struct LookoutStruct
{
    Card* pCardToTrash;
    Card* pCardToDiscard;
    Card* PCardToPutBack;
};

class IAI
{    
public:
    IAI( AI* pAI );
    virtual ~IAI( void );

    ////////////////////
    // Engine Interfaces
    ////////////////////

    // Return an Action card from hand to play.
    virtual Card*               PlayAction( void );

    // Return a Treasure card to play.
    virtual Card*               PlayTreasure( void );
    
    // Return a card to buy.
    virtual Card*               BuyCard( void );

    /////////////////////
    // General Interfaces
    /////////////////////

    // Return a reaction card in hand when an Attack card is played.
    virtual Card*               OnAttack( Card* pAttackCard );

    // Return a card to gain up to the value of cost.
    virtual Card*               OnGainACard( const Treasure* cost );

    // Return a card to gain of the exact value of cost.
    virtual Card*               OnGainACardExactly( const Treasure* cost );

    // Return a reordered list of cards to put back on top of the draw pile.
    // The first card in the list is the first card pushed onto the draw pile
    // stack so the last card in the list will be on the top of the draw
    // pile when all the cards have been placed in the draw pile.
    virtual CardList            OnReturnToDrawPile( CardList cardList );

    // Return a card to trash from hand.
    virtual Card*               OnTrashCardFromHand( void );

    ///////////////////////////
    // Base Set Card Interfaces
    ///////////////////////////

    // Return a Victory card in hand to place on top of the draw pile
    // when Bureaucrat is played.
    virtual Card*               OnBureaucrat( void );

    // Return list of cards from hand to discard when Cellar is played.
    virtual CardList            OnCellar( void );

    // Return a Chancellor option when Chancellor is played.
    virtual ChancellorOpt       OnChancellor( void );

    // Return a list of cards from hand to trash when Chapel is played.
    virtual CardList            OnChapel( void );

    // Return a Library option to determine if the Action card is discarded
    // when Library is played.
    virtual LibraryOpt          OnLibrary( Card* pCard );

    // Return a list of cards to discard from hand so the hand size is no
    // greater than 3 when Militia is played.
    virtual CardList            OnMilitia( void );

    // Return a Treasure card from hand to trash when Mine is played.
    virtual Card*               OnMineTrash( void );

    // Return a Treasure card from supply up to the cost when Mine is played.
    virtual Card*               OnMineGain( const Treasure* cost );

    // Return a card in hand to trash when Remodel is played.
    virtual Card*               OnRemodel( void );

    // Return a Spy option when Spy is played on other.
    virtual SpyOpt              OnSpyOther( Card* pCard );

    // Return a Spy option when Spy is played on self.
    virtual SpyOpt              OnSpySelf( Card* pCard );

    // Return a Thief option to determine if the Treasure card is stolen when 
    // Thief is played.
    virtual ThiefOpt            OnThiefGain( Card* pCard );

    // Return a Treasure Card from the card list to trash when Thief is played.
    virtual Card*               OnThiefTrash( CardList cardList );

    // Return an Action Card from hand when Throne Room is played.
    virtual Card*               OnThroneRoom( void ) = 0;

    ///////////////////////////////
    // Intrigue Set Card Interfaces
    ///////////////////////////////

    // Return Baron option  to discard an estate from hand when
    // Baron is played.
    virtual BaronOpt            OnBaron( void );

    // Return a card from hand to return to top of draw pile when Courtyard 
    // is played.
    virtual Card*               OnCourtyard( void );

    // Return a card to gain up to cost when Ironworks is played.
    virtual Card*               OnIronworks( const Treasure* cost );

    // Return a card from hand to pass to the player on the left when
    // Masquerade is played.
    virtual Card*               OnMasqueradePass( void );

    // Return a card from hand to trash when Masquerade is played.
    // (Return null card is choosing to not trash a card.)
    virtual Card*               OnMasqueradeTrash( void );

    // Return a Mining Village option to trash Mining Village card
    // when Mining Village is played.
    virtual MiningVillageOpt    OnMiningVillage( void );

    // Return a Minion option to gain 2 coins or discard hand
    // when Minion is played.
    virtual MinionOpt           OnMinion( void );

    // Return a Nobles option to draw 3 cards or gain 2 actions 
    // when Nobles is played.
    virtual NoblesOpt           OnNobles( void );

    // Return a pair of different Pawn options when Pawn is played.
    virtual PawnOptPair         OnPawn( void );

    // Return a list of cards from hand to discard when Secret Chamber 
    // is played.
    virtual CardList            OnSecretChamber( void );

    // Return a list of cards from hand to place on top of the draw pile when
    // Secret Chamber is revealed as a Reaction.
    virtual CardList            OnSecretChamberReaction( void );

    // Return a Steward option to draw 2 cards, gain plus 2 coins or
    // trash 2 cards when Steward is played.
    virtual StewardOpt          OnSteward( void );

    // Return a list of 2 cards from hand to trash when Steward is played
    // and trash option was chosen.
    virtual CardList            OnStewardTrash( void );

    // Return a card for another player to gain up to the cost when
    // Swindler is played.
    virtual Card*               OnSwindler( Card* pCard );

    // Return a list of 2 cards to discard from hand (or empty list to accept 
    // a Curse card) when Torturer is played.
    virtual CardList            OnTorturer( void );

    // Return a list of 2 cards from hand to trash when Trading Post is played.
    virtual CardList            OnTradingPost( void );

    // Return a card from hand to trash when Upgrade is played.
    virtual Card*               OnUpgrade( void );

    // Return a card to wish for when Wishing Well is played.
    virtual Card*               OnWishingWell( void );

    //////////////////////////////
    // Seaside Set Card Interfaces
    //////////////////////////////

     // Return a card from hand to reveal when Ambassador is played.
    virtual Card*               OnAmbassadorReveal( void );

    // Return the number of cards from hand to put back into supply when 
    // Ambassador is played.
    virtual int                 OnAmbassadorPutBack( Card* pCard );

    // Return a card to Embargo in the supply piles when Embargo is played.
    virtual Card*               OnEmbargo( void );

    // Returns an Explorer option to reveal a province in hand when Explorer
    // is played.
    virtual ExplorerOpt         OnExplorer( void );
    
    // Return a list of cards to put back on DrawPile from hand so the hand 
    // size is no greater than 3 when Ghost Ship is played.
    virtual CardList            OnGhostShip( void );

    // Return a card to place with the Haven card in the duration pile when 
    // Haven is played.
    virtual Card*               OnHaven( void );

    // Return a card from hand to place on Island mat when Island is played.
    virtual Card*               OnIsland( void );

    // Return a struct containing cards to trash, discard and return to draw
    // pile when Lookout is played.
    virtual LookoutStruct       OnLookout( CardList cardList );

    // Return a Native Village option to set aside card from top of the draw pile 
    // or to draw cards into hand from Native Village mat when Native Village 
    // is played.
    virtual NativeVillageOpt    OnNativeVillage( void );

    // Return a reordered list of cards to place on the draw pile (or an empty
    // list to indicate to discard the cards from the list) when Naviagtor
    // is played.
    virtual CardList            OnNavigator( CardList cardList );

    // Return Pearl Diver option to place reveal card on top of the deck or
    // back to the bottom of the deck when Pearl Diver is played.
    virtual PearlDiverOpt       OnPearlDiver( Card* pCard );

    // Return Pirate Ship option to attack other players or gain the plus
    // coins from Pirate Ship mat when Pirate Ship is played.
    virtual PirateShipOpt       OnPirateShip( void );

    // Return a card from the list to trash when Pirate Ship is played.
    virtual Card*               OnPirateShipTrash( CardList cardList );

    // Return a card from hand to trash for plus coins when Salvager is played.
    virtual Card*               OnSalvager( void );

    // Return a card from the list to gain when Smugglers is played.
    virtual Card*               OnSmugglers( CardList cardList );

    // Return a Treasury option to return the Treasury card to the draw pile
    // when Treasury is played.
    virtual TreasuryOpt         OnTreasury( void );

    // Return a list of 3 cards from hand to discard when Warehouse is played.
    virtual CardList            OnWarehouse( void );

    //////////////////////////////
    // Alchemy Set Card Interfaces
    //////////////////////////////

    // Return Alchemist option to put the card back on top of the deck
    // when Alchemist is played.
    virtual AlchemistOpt        OnAlchemist( void );

    // Return a card from hand to trash for plus coins when Apprentice
    // is played.
    virtual Card*               OnApprentice( void );

    // Return a reordered list of action cards for the Golem to play
    // when Golem is played.
    virtual CardList            OnGolem( CardList cardList );

    // Return a Treasure card in-play to put back on deck when Herbalist 
    // is played.
    virtual Card*               OnHerbalist( void );

    // Return a Scrying Pool option when Scrying Pool is played on other.
    virtual ScryingPoolOpt      OnScryingPoolOther( Card* pCard );

    // Return a Scrying Pool option when Scrying Pool is played on self.
    virtual ScryingPoolOpt      OnScryingPoolSelf( Card* pCard );

    // Return a card from hand to trash to gain a card based on its type
    // when Transmute is played.
    virtual Card*               OnTransmute( void );

    // Return an Action card which cost up to 5 coins when University is played.
    virtual Card*               OnUniversity( void );

    /////////////////////////////////
    // Prosperity Set Card Interfaces
    /////////////////////////////////
    
    // Return Loan option to trash or discard the Treasure card draw
    // from deck when Loan is played.
    virtual LoanOpt             OnLoan( Card* pCard );

    // Return a card to trash from hand when Biship is played by self.
    virtual Card*               OnBishopSelf( void );

    // Return a card to trash from hand (or return the Null card to decline
    // to trash a card) when Biship is played by other.
    virtual Card*               OnBishopOther( void );

    // Return a card to block the player to the right from buying this turn
    // when Contraband is played.
    virtual Card*               OnContraband( void );

    // Return number of coppers to draw from discard pile when Counting House
    // is played. 
    virtual int                 OnCountingHouse( int numCoppersInDiscard );

    // Return a card to trash from hand to gain a card when Expand is played.
    virtual Card*               OnExpand( void );

    // Return a list of cards from hand to trash to gain a card when
    // Forge is played.
    virtual CardList            OnForge( void );

    // Return a list of cards to discard from hand so the hand size is no
    // greater than 3 when Goons is played.
    virtual CardList            OnGoons( void );

    // Return a card from hand to be played 3 times when King's Court is played.
    virtual Card*               OnKingsCourt( void );

    // Return a card from hand for the Mint to copy when Mint is played.
    virtual Card*               OnMint( void );

    // Return a Mountebank option to discard a curse from hand or gain a curse
    // and coper in discard pile when Mountebank is played.
    virtual MountebankOpt       OnMountebank( void );

    // Return a RoyalSeal option to put the card on top of the deck or discard
    // when RoyalSeal is played.
    virtual RoyalSealOpt        OnRoyalSeal( Card* pCard );

    // Return a list of cards to discard from hand to gain plus cards when 
    // Vault is played by self.
    virtual CardList            OnVaultSelf( void );

    // Return a list of 2 cards to discard (or an empty list) to draw a card
    // when Vault is played by other.
    virtual CardList            OnVaultOther( void );

private:
    AI*     m_pAI;
};

} // namespace Domlib