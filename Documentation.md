# Domlib Documentation #

## Table of Contents ##


# Domlib Library #
## Background ##
Domlib is a Dominion card game engine with AI exports for decision making tasks. The goal is to allow the engine to iterate over a set of games to create a competitive environment for custom AIs. The design intent is to keep the AI exports simple and let the engine do all the game validation, phase execution, and card tasks.

This article contains what the end-user AI developer needs to know to implement he or her custom AI hooks into the engine.

## Design ##
If you're interested in the back-end engine design, please read the design document.

[Design](Design.md)

# Domlib AI Interface #
## AI Class ##
TODO: Add description from the AI developer perspective.

## Required AI Functions ##
### General Interfaces ###
| **Function** | **Description** |
|:-------------|:----------------|
| `ICard* OnAttack( ICard* pAttackCard )` | Return a reaction card in hand when an Attack card is played. |
| `ICard* OnGainACard( const ITreasure* cost )` | Return a card to gain up to the value of cost. |
| `ICard* OnGainACardExactly( const ITreasure* cost )` | Return a card to gain of the exact value of cost. |
| `ICardList OnReturnToDrawPile( ICardList cardList )` | Return a reordered list of cards to put back on top of the draw pile. The first card in the list is the first card pushed onto the draw pile stack so the last card in the list will be on the top of the draw pile when all the cards have been placed in the draw pile.|
| `ICard* OnTrashCardFromHand( void )` | Return a card to trash from hand. |

### Engine Interfaces ###
| **Function** | **Description** |
|:-------------|:----------------|
| `ICard* PlayAction( void )` | Return an Action card from hand to play. |
| `ICard* PlayTreasure( void )` | Return a Treasure card to play. |
| `ICard* BuyCard( void )` | Return a card to buy. |

### Base Cards ###

#### Bureaucrat ####
```
ICard* OnBureaucrat( void )
```

Return a Victory card in hand to place on top of the draw pile when Bureaucrat is played.

#### Cellar ####
```
ICardList OnCellar( void )
```

Return list of cards from hand to discard when Cellar is played.

#### Chancellor ####
```
ChancellorOpt OnChancellor( void )

enum ChancellorOpt
{
     CHANCELLOR_DISCARD_DRAW_DECK,
     CHANCELLOR_NO_OP
};
```

Return a Chancellor option when Chancellor is played. Options include:

  * `CHANCELLOR_DISCARD_DRAW_DECK` - Immediately put your draw pile into your discard.
  * `CHANCELLOR_NO_OP` - Do not put your draw pile into your discard.

#### Chapel ####
```
ICardList OnChapel( void )
```

Return a list of cards from hand to trash when Chapel is played.

#### Library ####
```
LibraryOpt OnLibrary( ICard* pCard )

enum LibraryOpt
{
    LIBRARY_DISCARD_ACTION_CARD,
    LIBRARY_KEEP_ACTION_CARD,
};
```

Return a Library option to determine if the Action card is discarded when Library is played. Options include:

  * 'LIBRARY\_DISCARD\_ACTION\_CARD' - Discard the passed action card.
  * 'LIBRARY\_KEEP\_ACTION\_CARD' - Keep the passed action card in hand.

#### Militia ####
```
ICardList OnMilitia( void )
```

Return a list of cards to discard from hand so the hand size is no greater than 3 when Militia is played.

#### Mine ####
```
ICard* OnMineTrash( void )
```

Return a Treasure card from hand to trash when Mine is played.

```
ICard* OnMineGain( const ITreasure* cost );
```

Return a Treasure card from supply up to the cost when Mine is played.

#### Remodel ####
```
ICard* OnRemodel( void );
```

Return a card in hand to trash when Remodel is played.

#### Spy ####
```
SpyOpt OnSpyOther( ICard* pCard );

enum SpyOpt
{
    SPY_DISCARD_CARD,
    SPY_PUT_BACK_CARD,
};
```

Return a Spy option when Spy is played on other. Options include:

  * `SPY_DISCARD_CARD` - Discard the other player's card.
  * `SPY_PUT_BACK_CARD` - Put the other player's card back on his or her deck.

```
SpyOpt OnSpySelf( ICard* pCard );
```

Return a Spy option when Spy is played on self. Options are above but apply to yourself.

#### Theif ####
```
ThiefOpt OnThiefGain( ICard* pCard );

enum ThiefOpt
{
    THIEF_TRASH_TREASURE_CARD,
    THIEF_STEAL_TREASURE_CARD,
};
```

Return a Thief option to determine if the Treasure card is stolen when Thief is played. Options include:

  * `THIEF_TRASH_TREASURE_CARD` - Trash the treasure card.
  * `THIEF_STEAL_TREASURE_CARD` - Steal the treasure card, placing it in your discard pile.

```
ICard* OnThiefTrash( ICardList cardList );
```

Return a Treasure Card from the card list to trash when Thief is played.

### Intrigue Cards ###
```
///////////////////////////////
// Intrigue Set Card Interfaces
///////////////////////////////

// Return Baron option  to discard an estate from hand when
// Baron is played.
BaronOpt            OnBaron( void );

// Return a card from hand to return to top of draw pile when Courtyard 
// is played.
ICard*              OnCourtyard( void );

// Return a card to gain up to cost when Ironworks is played.
ICard*              OnIronworks( const ITreasure* cost );

// Return a card from hand to pass to the player on the left when
// Masquerade is played.
ICard*              OnMasqueradePass( void );

// Return a card from hand to trash when Masquerade is played.
// (Return null card is choosing to not trash a card.)
ICard*              OnMasqueradeTrash( void );

// Return a Mining Village option to trash Mining Village card
// when Mining Village is played.
MiningVillageOpt    OnMiningVillage( void );

// Return a Minion option to gain 2 coins or discard hand
// when Minion is played.
MinionOpt           OnMinion( void );

// Return a Nobles option to draw 3 cards or gain 2 actions 
// when Nobles is played.
NoblesOpt           OnNobles( void );

// Return a pair of different Pawn options when Pawn is played.
PawnOptPair         OnPawn( void );

// Return a list of cards from hand to discard when Secret Chamber 
// is played.
ICardList           OnSecretChamber( void );

// Return a list of cards from hand to place on top of the draw pile when
// Secret Chamber is revealed as a Reaction.
ICardList           OnSecretChamberReaction( void );

// Return a Steward option to draw 2 cards, gain plus 2 coins or
// trash 2 cards when Steward is played.
StewardOpt          OnSteward( void );

// Return a list of 2 cards from hand to trash when Steward is played
// and trash option was chosen.
ICardList           OnStewardTrash( void );

// Return a card for another player to gain up to the cost of the card 
// trashed when Swindler is played.
ICard*              OnSwindler( ICard* pCard );

// Return a list of 2 cards to discard from hand (or empty list to accept 
// a Curse card) when Torturer is played.
ICardList           OnTorturer( void );

// Return a list of 2 cards from hand to trash when Trading Post is played.
ICardList           OnTradingPost( void );

// Return a card from hand to trash when Upgrade is played.
ICard*              OnUpgrade( void );

// Return a card to wish for when Wishing Well is played.
ICard*              OnWishingWell( void );
```

### Seaside Cards ###
```
//////////////////////////////
// Seaside Set Card Interfaces
//////////////////////////////

// Return a list of up to 2 cards from hand to return to the supply piles
// when Ambassador is played.
ICardList           OnAmbassador( void );

// Return a card to Embargo in the supply piles when Embargo is played.
ICard*              OnEmbargo( void );

// Returns an Explorer option to reveal a province in hand when Explorer
// is played.
ExplorerOpt         OnExplorer( void );

// Return a card to place with the Haven card in the duration pile when 
// Haven is played.
ICard*              OnHaven( void );

// Return a card from hand to place on Island mat when Island is played.
ICard*              OnIsland( void );

// Return a struct containing cards to trash, discard and return to draw
// pile when Lookout is played.
LookoutStruct       OnLookout( ICardList cardList );

// Return a Native Village option to set aside card from top of the draw pile 
// or to draw cards into hand from Native Village mat when Native Village 
// is played.
NativeVillageOpt    OnNativeVillage( void );

// Return a reordered list of cards to place on the draw pile (or an empty
// list to indicate to discard the cards from the list) when Naviagtor
// is played.
ICardList           OnNavigator( ICardList cardList );

// Return Pearl Diver option to place reveal card on top of the deck or
// back to the bottom of the deck when Pearl Diver is played.
PearlDiverOpt       OnPearlDiver( void );

// Return Pirate Ship option to attack other players or gain the plus
// coins from Pirate Ship mat when Pirate Ship is played.
PirateShipOpt       OnPirateShip( void );

// Return a card from hand to trash for plus coins when Salvager is played.
ICard*              OnSalvager( void );

// Return a card from the list to gain when Smugglers is played.
ICard*              OnSmugglers( ICardList cardList );

// Return a Treasury option to return the Treasury card to the draw pile
// when Treasury is played.
TreasuryOpt         OnTreasury( void );

// Return a list of 3 cards from hand to discard when Warehouse is played.
ICardList           OnWarehouse( void );
```

### Alchemy Cards ###
```
//////////////////////////////
// Alchemy Set Card Interfaces
//////////////////////////////

// Return Alchemist option to put the card back on top of the deck
// when Alchemist is played.
AlchemistOpt        OnAlchemist( void );

// Return a card from hand to trash for plus coins when Apprentice
// is played.
ICard*              OnApprentice( void );

// Return a reordered list of action cards for the Golem to play
// when Golem is played.
ICardList           OnGolem( ICardList cardList );

// Return a Treasure card in-play to put back on deck when Herbalist 
// is played.
ICard*              OnHerbalist( void );

// Return a Scrying Pool option when Scrying Pool is played on other.
ScryingPoolOpt      OnScryingPoolOther( ICard* pCard );

// Return a Scrying Pool option when Scrying Pool is played on self.
ScryingPoolOpt      OnScryingPoolSelf( ICard* pCard );

// Return a card from hand to trash to gain a card based on its type
// when Transmute is played.
ICard*              OnTransmute( void );

// Return an Action card which cost up to 5 coins when University is played.
ICard*              OnUniversity( void );
```

### Prosperity Cards ###
```
/////////////////////////////////
// Prosperity Set Card Interfaces
/////////////////////////////////

// Return Loan option to trash or discard the Treasure card draw
// from deck when Loan is played.
LoanOpt             OnLoan( ICard* pCard );

// Return a card to trash from hand (or return the Null card to decline
// to trash a card) when Biship is played.
ICard*              OnBiship( void );

// Return a card to block the player to the right from buying this turn
// when Contraband is played.
ICard*              OnContraband( void );

// Return number of coppers to draw from discard pile when Counting House
// is played. (Discard pile is passed to the function since it is normally
// illegal to look through the discard pile.)
int                 OnCountingHouse( ICardList cardList );

// Return a card to trash from hand to gain a card when Expand is played.
ICard*              OnExpand( void );

// Return a list of cards from hand to trash to gain a card when
// Forge is played.
ICardList           OnForge( void );

// Return a list of cards to discard from hand so the hand size is no
// greater than 3 when Goons is played.
ICardList           OnGoons( void );

// Return a card from hand to be played 3 times when King's Court is played.
ICard*              OnKingsCourt( void );

// Return a card from hand for the Mint to copy when Mint is played.
ICard*              OnMint( void );

// Return a Mountebank option to discard a curse from hand or gain a curse
// and coper in discard pile when Mountebank is played.
MountebankOpt       OnMountebank( void );

// Return a RoyalSeal option to put the card on top of the deck or discard
// when RoyalSeal is played.
RoyalSealOpt        OnRoyalSeal( ICard* pCard );

// Return a list of cards to discard from hand to gain plus cards when 
// Vault is played by self.
ICardList           OnVaultSelf( void );

// Return a list of 2 cards to discard (or an empty list) to draw a card
// when Vault is played by other.
ICardList           OnValueOther( void );
```

## ICard Class ##
TODO: Add description from the AI developer perspective.

## IEngine Class ##
TODO: Add description from the AI developer perspective.

## IGame Class ##
TODO: Add description from the AI developer perspective.

## IPlayer Class ##
TODO: Add description from the AI developer perspective.

## ITreasure Class ##
TODO: Add description from the AI developer perspective.

# AI Debugging #
The Game class has functions which makes it easier to debug custom AIs. These functions range from telling the engine to use specific cards to initial game conditions. It also allows the loading of previous game templates for analysis.

TBD

# Domcomp #

The Domcomp project within the Domlib solution builds an executable which runs competitive AIs against each other. It loads each AI via run-time DLL map and executes a series of Domlib games via the command line.

There are a few reasons why DLLs are used:

  1. Easier to share private implementations.
  1. Easier to separate private AI source code from the Domlib solution. AI implementations will not be stored in the Domlib solution, so it will be easier to load implementations via DLLs.

## Commandline Arguments ##

These command line arguments can also be retrieved via `-h`.

### Game Controls ###

`-g X` - Run X games. ( Required )

`-r Y` - Run each game Y times. ( Default = 1 )

### Selecting Card Sets ###

`-b` - Use Base cards

`-i` - Use Intrigue cards

`-s` - Use Seaside

`-a` - Use Alchemy

`-p` - Use Prosperity

`-x` - Use All card sets ( Default )

### Selecting AI DLLs ###

Each DLL is specified after any arguments. At least two must provided and do not need to be unique.

### Examples ###

`Domcomp.exe -g 100000 -r 100 A.dll B.dll C.dll`

  * Run 100,000 games
  * Re-running each game 100 times
  * Using all decks ( default )
  * With competitor AIs A, B, C.

`Domcomp.exe -g 1000 A.dll A.dll A.dll`

  * Run 1,000 games
  * Re-running each game once ( default )
  * Using all decks ( default )
  * With the same three competitor AIs.

`DomComp.exe -g 1000 -b -i A.dll B.dll C.dll`

  * Run 1,000 games
  * Re-running each game once ( default )
  * Using only Base and Intrigue cards
  * With competitor AIs A, B, C.

## Required DLL Exports ##

Domcomp requires two DLL exports.

`void CreateAI( void )`

The DLL is expected to instantiate an instance of the AI and return a pointer to that interface.

`void DestoryAI( void )`

Domcomp will call this to destroy an instance of the AI.

## Sample DLL ##

The domlib solution contains a project called DomAIDLL which contains skeleton DLL code. This will create an empty DLL with the required exports. Developers can use this to begin writing a DLL.

## Output ##

TBD. Most likely Text, CSV, HTML, and XML support.