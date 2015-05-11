# Domlib Design Document #
## Classes ##
  * **AI**: The AI class is the base class for any AI that is written by an AI developer. The default implementation will be provided in the DeafultAI so AI developers can extend this class if they do not want to override every interface.
  * **ICard** - The ICard class provides the public interface to the AI to gain public information about the card such as the cost, plus action, etc, (note, some information may vary based on the context of the player for example PhilosopherStoneCard’s cost is determined by the size of the draw pile and discard pile.)
  * **Card** – The Card class is derived from the ICard class to provide the AI information through that interface and the Card class serves as the base class for each specific card class in the game. (i.e. MoatCard, GoldCard, EstateCard, etc.) The Card class provides the basic implementation for the ICard class interfaces as well as the basic implementation for the phase it supports. The cards that derive from this class are expect to implement the phase functions to implement the behavior per phase if it is different than the default implementation..
  * **CardFactory** – The Card class uses to Singleton pattern to prevent the creation of more than one card instance to be instantiated. The CardFactory manages the creation and distribution of the different cards for the Card class. It is a nested class of the Card class and a static member so it is always available and when the program exits, the CardFactory will clean up the Cards it generated.
  * **IEngine** – The IEngine class provides the interface for the AI to request information about the state of the game.
  * **Engine** – The engine manages the list of players, contains the main loop for playing the game and holds the SupplyPileManager and any global state such as the TradeRouteMat or the TrashPile.
  * **IGame** – The IGame class provides the public interface for the Game class.
  * **Game** – The game class contains the engine and provides the link from the application to the engine for setting up the game and registering the AIs. The reason this is separated from the Engine itself is because each AI is provide a reference to the IEngine to get the current state of the game engine to make decisions. The Engine also needs to provide a register AI function to the application; however, if this was part of the IEngine interface then an AI, while in the middle of the game, could register another AI or request the supply piles to be randomized again or any other changes to the game. The IGame/Game class provide the interface for the app to setup the game, while IEngine/Engine provide the current state of the game to the AI while the game is being played.
  * **IPlayer** – The IPlayer class provides the basic interface for the AI to gain public information about a Player. This does not provide any private information about the Player the AI is registered with.
  * **IPlayerSelf** – The IPlayerSelf class provides the basic interface for the AI to gain public and private information about a Player. This still does not provide information a player is not allowed to know about itself such as the contents of the draw pile.
  * **Player** – The Player class manages all the lists, piles, mats and turn state that represent a player in the game.
  * **ITreasure** – The ITreasure class provides the AI access to the Treasure classes external interface. The Treasure class is not provided externally since that would enable an AI to rewrite the Treasure class to modify it’s behavior.
  * **Treasure** – The Treasure class represent the complex value of currency in the game (coins and potions). This class provides overrided operators such as (+, -, ==, <, etc.).
  * **SupplyPile** – The SupplyPile class manages the number of supply cards in a pile, the number of embargo tokens and trade route tokens and any other state of an individual pile.
  * **SupplyPileManager** – The SupplyPileManager class manages all the supply piles in the game and some basic functionality the Engine such as helping determine the victory condition or setting up the piles used in the game.
## Turn Phases ##
  * **Start of turn** – The turn is initialized with setting the number of actions, buys and treasure to start with and clears turn lists (except Duration List, any others???) The AI is notified of the start of the player’s turn to save any state that is cleared at the start of the turn.
  * **Duration Phase** – All the Duration card in the duration list are processed for their duration effects. The cards in this list where places here during the previous turn’s Cleanup phase.
  * **Action Phase** – The AI is requested to play Action cards from Hand one at a time until there are no more actions left this turn or no more Action cards in Hand or the AI returns the NullCard to indicate it does not wish to play any more action cards. Cards which the AI requests to play are checked against the cards in Hand, then placed into the In-Play list, the number of actions for the player’s turn is decremented and the number of actions cards played for the player’s turn is incremented and then the card is played by the Player.
  * **Treasure Phase** – The AI is requested to play Treasure cards from Hand one at a time until they have not more Treasure cards in Hand or the AI returns the NullCard to indicate it does not wish to play any more actions cards. This phase is needed for the new Prosperity Treasure cards since the order the cards are played matter due to the effects of the Treasure cards. As the cards are played, they also return the value of the treasure card at the state in the game at the time the individual treasure card is played to sum up the buying power for the BuyPhase.
  * **Buy Phase** – The AI is requested to buy a card from supply for which they have purchasing power until the player has no more “buys” or no more purchasing power or the AI return the NullCard indicating it does not wish to purchase another card.
  * **Cleanup Phase** – The cards in the InPlayList are processed to preform any special Cleanup phase actions, then the DurationList is cleared and any Duration cards in the InPlayList are put into the DurationList and the remaining cards in the InPlayList and Hand are discarded. Finally the player draws 5 cards (or draws 3 cards if Output is in play.)
## Player / Engine Containers ##
  * **Deck** – all cards in the players possession including draw pile, hand, discard, in-play, duration, island mat, native village mat, etc. The count and contents of this list is not available to any player until the game is over.
  * **DrawPile** – all cards in the draw pile and it is the source of any draw function. When this pile is empty, the cards from the DiscardPile are randomized and transfer to this pile. The count is available to any player (???) and contents is not available to any player.
  * **Hand** – the list of cards in hand which are typically drawn from the DrawPile but can be gained from other sources. The count is available to any player but the contents are only available to the owning player.
  * **InPlayList** – is a list of Action cards that the player has played during the action phase. The count and cards are publicly known.
  * **DiscardPile** – is the list of card which were previously InPlay or gain from another source such as when bought. The count and contents of this pile is not known by any player. (might add the ability to see the top card of this pile.)
  * **RevealedList** – is a list of cards which are temporary revealed to other players and put back to the source. These cards are not InPlay; however, they may come from the SetAside list. A Moat revealed as part of a reaction is in this list but not in the SetAsideList and is returned to hand. The whole hand is put in this list if Bureaucrat is played but the player has no victory cards.
  * **SetAsideList** – is a list of cards that are set aside as a function of implementing the action of a card and typically come from the draw pile. Library will draw cards from the deck and set them aside. Since these cards are face up then they should be also put in the RevealList. The SetAsideList should be managed by the action card where as the RevealedList is managed by the player.
  * **BuyList** – is a list of cards bought by a player and its count and co
  * **DurationList** – is a list of card that are is duration from the previous turn. When a duration card is played it is in the InPlayList until the cleanup phase in which case it is moved to the DurationList. At the start of the next turn, any cards in the DurationList are played for their duration effect and then at the start of the cleanup phase are moved into the DiscardPile. The count and contents of this list is publicly known.
  * **HavenList** – is a special list to hold the cards that Haven plays. During the duration phase any cards in this list are put into the Hand.
  * **TrashPile** is a list of cards that have been trashed. The count and contents of this list is public information.
  * **NativeVillageMat** this is a list of cards placed on the NativeVillageMat. The count and contents of the mat only known by the player.
  * **IslandMat** is a list of cards placed on the island mat. The count and contents of the mat is public information.
  * **PirateShipMat** is a count of pirate coins. This number is public information.
  * **SupplyPile** is the a pile of a supply card (kingdom cards, treasure cards victory cards) in the game. The count and contents is publicly known. In addition, the SupplyPile contains a count of embargo tokens and TradeTokens which are also public information.
  * **TradeRouteMat** is a count of TradeTokens which is public information. Unlike most of the other lists, piles and mats, this mat is managed by the Engine class instead of the Player class since it is a shared mat.
  * **VictoryPointMat** (called player mat in the rules) is a count of the VictoryTokens (called <shield symbol> tokens in the rules). The count is publicly known.
## Function Naming Convention ##
  * **GainCardxxx**( Card ) – this prefix indicates that the card should be taken from a supply pile and put into the post fix destination. If the supply pile is empty then this is a no-op. It is up to the caller to know if it is valid to call this function if the supply pile is empty.
    * For example: GainCardInHand( card ) this takes a card from the supply pile and put it in the Hand list.
  * **OnGainACardxxx**( Cost ) – this prefix indicates that the player’s AI should be queried about a card from supply to gain and then place the card in the destination postfix.
  * **PutCardxxx**( Card ) – this prefix indicates that the card should simply put into the postfix destination without knowing the source. It is up to the caller to handle the bookkeeping for the source of this card.
    * For example: PutCardInTrash( card ) this puts a reference to the card in the trash pile without knowing where it came from but this is just an example since TrashCard( card ) is the same as PutCardInTrash( card ).
  * **TrashCardxxx**( Card ) – this prefix indicates that the card should go to the postfix source. If there is no postfix source then the card is simply trashed and it is up to the caller to handle the bookkeeping of the source.
    * For example: TrashCardFromHand( card ) will take the card from the Hand list and put it in the TrashPile
## AI Class ##
The AI class will contain the logic that drive the player classes decisions. There is an Interface class the AI will derive from and will need to implement the interface functions to work correctly.
TODO: Need to add mechanism to indicate which set of cards an AI supports. There could be some situations when the default AI combined with the implemented AI result in bad behavior if new cards are introduced that the AI was not designed to support. Example, Masquerade could put into deck a new victory card and if the player has that card in hand when Bureaucrat is play the logic might not return the proper card thus generating an error. The AI might still be valid for previous version or previous sets of hands.
## AI Interfaces ##
TODO: Add description of the Bridge pattern and it’s use with the AI interfaces.
## Card Class ##
All cards are derived from the Card class and implement needed functions. The base class will have the default implementation since most operations will be common. The class will have any helper functions for common operations such as AttackCard. The class will also have a reference to the GameEngine to query the players or modify game state. The Card class will also implement AI interface version of Card which provides the user access to some but not all of the class functions. The Card class also implements a singleton model such that there is a private constructor for the class and all derived class, there is a static GetCard method to get a copy a card from a factory by passing in the CARDID.

#### Action Card Execution ####
Each card has a pointer to the game engine enabling the card to execute it’s own instruction. The game engine manages the players (piles, hands, mats, tokens etc) and the deck (piles) and any tokens.

By default, any action card played, decrements the actions by 1 and the card is removed from the player’s hand to the “in-play” list. Duration cards moved from in-play to duration list in clean-up phase.

#### AttackCard Helper function ####
Instead of writing the same loop to attack players for each attack write a single function which takes in the attack card played and a flag to indicate is self attack is possible (i.e. Spy)
```
For each (other) player
{
    If(player does not have Lighthouse in DurationList)
    {
        reactionCard = player->GetReaction( AttackCard )
        if( reactionCard != Moat)
        {
            reactionCard.Reaction( AttackCard, player );
            AttackCard.Attack()
        }
    }
}
```

#### Reaction Cards ####
If an attack occurs the player is queried for a reaction card from hand.
The card returned then has card.Reaction( AttackCard ) function called to perform a reaction action.

#### Card::GainACard() Helper function ####
This should call player::GainACard() function in the player but instead of having a card directly call this function it should call the Card::GainACard() which include checks to make sure play gained a valid card
```
Card::GainACard()
{
    Card = player.GainACard();
    if(Card in stock)
    {
        Put card in player’s discard pile
    }
    // do nothing
}
```
This function always puts the card into the discard pile. If the card is suppose to go into the draw pile or hand then a more explicit function should be called.

#### Cleanup function ####
This allows the card to perform any special actions on the cards in the in-play list (including itself) before the in-play is moved to the discard pile.
## Game Class ##
TODO: Add info
## Engine Class ##
The engine class will contain the list of players, the supply piles and any other general state about the game. The engine will also have functions for running the game such as the different phases of a turn.

The Engine will contain a Supply Pile Manager which has all the piles of a given game and the interfaces to manage the piles. The Supply Pile Manager will also handle setting up the piles for different game types (preloaded, random, mixed/pure sets, etc.) The individual piles will use the Pile class which manages the card in the pile, number of cards available, and add additional state such as embargos or trade route tokens.
## SupplyPile Class ##
TODO: Add info
## SupplyPileManager Class ##
TODO: Add info
## Player Class ##
The player class will contain the various piles/mats/etc (Discard, Draw, Hand, Duration, Reveal, Island Mat, NativeVillage Mat, etc.). It will also log actions of the player and hand the actions requested to/from the AI or Card.
## Treasure Class ##
Treasure struct handles the complex system of currency in the game (coins + potions) since currency is no longer simply coins, it cannot be represented by a single integer.
## Common Cards ##
#### Copper::OnTreasureValue() ####
  * Return 1 + the number of Coppersmiths in the player’s InPlayList.
#### Silver ####
  * Default behavior
#### Gold ####
  * Default behavior
#### Estates ####
  * Default behavior
#### Duchy ####
  * Default behavior
#### Province ####
  * Default behavior
#### Curse ####
  * Default behavior
## Base Set Cards ##
#### Adventurer::OnActionPhase() ####
  * While draw cards from draw pile (if empty but there are cards in discard they should be shuffled and placed in draw pile hidden by draw function) until 2 treasure cards are revealed or draw pile is empty.
  * Place treasure cards into hand
  * Place revealed cards into discard pile
#### Bureaucrat::OnActionPhase() ####
  * Add a SilverCard to the top of the player’s deck.
  * Call Attack and pass in the flag ATTACK\_ALL.
#### Bureaucrat::OnAttack() ####
  * If the player has a victory card in hand then query the player’s AI with OnBureaucrat() to return a victory card in hand to put on draw pile.
  * Check that the victory card returned is in hand.
  * Move the card from the player’s hand to the draw pile.
  * Else if the player had no Victory cards in hand to discard then add the players hand to the reveal list.
#### Cellar::OnActionPhase() ####
  * Add 1 action to player’s turn.
  * Query the player’s AI with OnCellar() for a list of cards from hand to discard.
  * Check the list of cards return against the cards in the player’s hand.
  * Discard the cards in the list from the player’s hand.
  * Equal number of cards are drawn into the players hand.
#### Chapel::OnActionPhase() ####
  * Query the player’s AI with OnChapel for a list of cards from hand to trash.
  * Check the list of cards returned agains the cards in the player’s hand.
  * Trash the cards in the list from the player’s hand.
#### Chancellor::OnActionPhase() ####
  * Add 2 coins to the player’s turn.
  * Query the player’s AI with OnChancellor() to return an option to discard the draw pile immediately.
  * If returns the option to discard then move draw pile to the discard pile.
#### Council Room::OnActionPhase() ####
  * Draw 4 cards to player’s hand
  * Add 1 buy to player’s turn
  * Add 1 card to other player’s hand
#### Feast::OnActionPhase() ####
  * Use OnGainACard( cost = 5 ) helper function to handle this card.
#### Feast::OnCleanup() ####
  * Move the Feast card from the InPlayList to the TrashPile.
#### Festival::OnActionPhase() ####
  * Add 2 actions to player’s turn
  * Add 1 buy to player’s turn
  * Add 2 coin to player’s turn
#### Gardens::OnActionPhase() ####
  * Do nothing
#### Gardens::OnScoring() ####
  * Sum the number of cards in the players Deck (sum the draw pile, discard pile, hand, in-play list, duration list haven list and any other list with a card that is not simply a copy of the card such as reveal list.)
#### Laboratory::OnActionPhase() ####
  * Draw 2 cards to player’s hand
  * Add 1 action to player’s turn
#### Library::OnActionPhase() ####
  * While player’s hand is < 7 cards
  * Draw a card
  * If the card drawn is an Action card query the player’s AI with OnLibrary( card ) for a Library option.
  * If the AI returns to keep the card then put it into Hand otherwise set it aside in revealed pile.
  * End while loop
  * Place cards in reveal pile into discard pile
#### Market::OnActionPhase() ####
  * Draw 1 card into player’s hand
  * Add 1 action to player’s turn
  * Add 1 buy to player’s turn
  * Add 1 coin to player’s turn
#### Militia::OnActionPhase() ####
  * Add 2 coins to this player’s turn.
#### Militia::OnAttack()() ####
  * Query the player’s AI with OnMilitia() to return a list of cards to discard from hand such that the hand’s size will be <= 3.
  * Check the cards returned are in the players hand and it would reduce the size of the hand to <= 3.
  * Discard the cards return from the players hand.
#### Mine::OnActionPhase() ####
  * Query the player’s AI with OnMineTrash() to return a Treasure card from Hand to trash.
  * Check that the card returned is a treasure and is in the player’s hand
  * Trash the card and query the player’s AI with OnMineGain( cost card.coins + 3 ) to gain a card.
  * Check the card returned is a Treasure card.
  * Add the treasure card from the supply pile to player’s hand.
#### Moat::OnActionPhase() ####
  * Draw 2 cards into player’s hand
#### Moat::Reaction() ####
  * Does nothing since there are no special action to perform at this point. The AI is request to return a reaction card in the attack function. At that point the AI would return the MoatCard to block the attack.
#### Moneylender::OnActionPhase() ####
  * If a player has a CopperCard in Hand then
  * Trash a CopperCard from the player’s Hand
  * Add 3 coins to the players turn.
#### Remodel::OnActionPhase() ####
  * Query the player’s AI with OnRemodel () for a card in Hand to trash.
  * Check the card returned against cards in Hand.
  * Trash the card from Hand.
  * Use the OnGainACard( trashed card’s cost + 2 ) helper function to finish handling this function.
#### Smithy::OnActionPhase() ####
  * Draw 3 cards to player’s hand
#### Spy::OnActionPhase() ####
  * Draw 1 card to player’s hand
  * Add 1 action to player’s turn
#### Spy::OnAttack() ####
  * Reveal a card from the player’s deck.
  * If the player is the attacker then query the player’s AI with OnSpySelf() for the spy option.
  * If the player is not the attacker then query the player’s AI with OnSpyOther() for the spy option.
  * If the spy option is discard then move the card revealed to the discard pile.
  * If the spy option is not discard then move the card revealed back to the draw pile.
#### Thief::OnActionPhase() ####
  * Do nothing
#### Thief::OnAttack() ####
  * Reveal top 2 cards from the player’s deck.
  * If both cards revealed then query the attacking player’s AI with ThiefTrash() to return which card to trash and set it to the card to trash.
  * Else if there is only one card then set it to the card to trash.
  * Query the attacking player’s AI with ThiefGain() to gain the card or trash the card.
  * If the AI want to gain the card then put the card on the attacking player’s discard pile.
  * Else put the card into the trash pile.
#### Throne Room::OnActionPhase() ####
  * Query player with ThroneRoom() which returns an action card from hand for the throne room to play twice.
  * Check that the action card is in hand()
  * Add the card to the player’s InPlay list, and increment the number of action cards played in the player’s turn by 1.
  * Call the OnAction() function of the action card.
  * Increment the number of cards played in the player’s turn by 1.
  * Call the OnAction() function of the action card.
#### ThroneRoom::OnDuration() ####
  * Query the AI for a card from the ThroneRoomDurationList to play with OnDuration( DurationCardList ).
  * Check that the card returned is in the ThroneRoomDurationList.
  * Play the card once with its OnDuration(), no need modified the Player’s turn state.
  * Play the card a second time with its OnDuration().

Note: The following cards need to be handled with care with the Throne Room / King’s Court.
  * Feast – this card gains 2 cards but the feast card is trashed only once. Feast is trashed during the cleanup phase so there is no special handling required.
  * Mining Village – If this card is trashed in the first instance it is played then it is not available to be played again by throne room. To handle this, when throne room is in play, it checks if the card to throne room is Mining Village, it then counts the number of Mining Villages in the InPlayList, then adds the Mining Village to the InPlayList plays the Mining Village as normal. Then before playing the card a second time count the number of Mining Village cards in the InPlayList, if it is equal to the earlier count then the Mining Village was trashed from the InPlayList so it should not be played again.
  * Conspirator – Assuming no other action cards were played before throne room, the first time conspirator is played then only 2 actions have been played so the second effect does not apply; however, it does apply the second time Conspirator is used. To track this, Throne Room needs to increment the number of actions played that turn before playing each card.
  * Coppersmith – The effect of coppersmith is applied twice; however, only one copy of the card will be in the InPlay list. One solution would be to have a flag counting the number of coppersmith’s played or second is to have a ThroneRoom list in which Coppersmith would appear once and it would also be in the inplay list so when applying the Coppersmith modification, it would check both the inplay list and ThroneRoomList. (The modification for King’s Court would be to add the card to the ThroneRoomList twice.
  * Bridge – This should be handled similar to Coppersmith.
  * Duration Cards – The effect of the card is doubled both now and later, plus Throne Room is left with the duration card instead of discarded as a reminder to apply the duration card twice again. To handle this, if the Throne Room detect that it is being played on a Duration card then it should play the card as normal the first time and the second time put the Duration card in the ThroneRoomList as normal. During cleanup phase the number of Duration cards in the ThroneRoomList should be counted then each copy of Duration cards in the InPlayList that are also in the ThroneRoomList should be delete (simply removed without being moved to any list). Then while moving cards from the InPlayList to the DurationList, move up to the count of (Durration Cards in the ThroneRoomList) number of Throne Room cards from the InPlayList to the DurationList instead of DiscardPile. For each Duration card in the ThroneRoomList move that card to the DurationThroneRoomList instead of deleting it. During the DurationPhase the AI will be asked which card to play (in order) from the duration list and if Throne Room is selected then the AI should be asked again which Duration card from the ThroneRoomDurationList to play (This should be handled in the Throne Room’s OnDurationPhase() function.
  * Embargo – This should be handled similar to Feast.
  * Island – Set on the Island mat the Island card and 2 cards.
  * Tactician – You basically play Tactician once meaning you discard hand to gain the +5 card next turn and the second time Tactician is played there are no cards in hand to discard so no additional +5 card bonus at the start of next turn.
  * Treasure Map – The first time treasure map is played it is trashed so you gain 4 gold if there was another Treasure Map in hand. The second time treasure map is played you already trashed it so it cannot be trashed with a 3rd treasure map to gain 4 gold; however, if you do have a 3rd treasure map, it will be trashed even if it is for nothing.
  * Golem – If Golem is throne roomed then no problem; however, if Golem plays a Throne Room nothing happens since you cannot have Golem apply the Throne Room to the second card or to any card in hand.
  * Peddler – the cost of buying this card is based on the count of cards in play not the number of times they were played so Throne Room does not have an effect on reducing this any more than the fact that Throne Room and the card chosen to Throne Room are in play thus reducing the cost by 4 not 6.
#### Village::OnActionPhase() ####
  * Draw 1 card into player’s hand.
  * Add 2 actions to player’s turn.
#### Witch::OnActionPhase() ####
  * Draw 2 cards into player’s hand
  * Call Attack with ATTACK\_OTHERS
#### Witch::OnAttack() ####
  * Add a curse to player’s discard pile from supply pile.
#### Woodcutter::OnActionPhase() ####
  * Add 1 buy to player’s turn.
  * Add 2 coins to player’s turn.
#### Workshop::OnActionPhase() ####
  * Use the OnGainACard( cost = 4 ) helper function to handle this card.
## Intrigue Set Cards ##
#### Baron::OnActionPhase() ####
  * Add 1 buy to player’s turn
  * If the player’s hand contains an Estate then query the player’s AI with OnBaron() for a Baron option.
  * If discard estate is select then
  * Check the player’s hand for an estate
  * Discard the estate from hand to the discard pile
  * Add 4 coins the player’s turn
  * Else gain an Estate in the discard pile (this is forced if the card is played)
#### Bridge::OnActionPhase() ####
  * Add 1 buy to player’s turn
  * Add 1 coin to player’s turn
  * When a card’s cost is queried, it should check for the number of Bridges in the current player’s InPlay list to adjust the cost.
#### Conspirator::OnActionPhase() ####
  * Add 2 coin to player’s turn
  * If actions played in player’s turn is >= 3 [action card should have already been accounted for](this.md) then
  * Draw 1 card to player’s hand
  * Add 1 action to player’s turn
#### Coppersmith::OnActionPhase() ####
  * Do nothing.
  * When the treasure value of coppers is calculated in the treasure phase, it should count the number of coppersmiths in the InPlayList and ThroneRoomList and adjust the value.
#### Courtyard::OnActionPhase() ####
  * Draw 3 cards into the player’s hand
  * Query the player’s AI with OnCourtyard() for a card from the player’s hand to put back on the draw pile.
  * Check that the card returned is in the player’s hand.
  * Put back the card from the player’s hand to the draw pile.
#### Duke::OnActionPhase() ####
  * No-op
#### Duke::OnScoring() ####
  * Count the number of Duchies in the player’s Deck.
  * Return the count divided by 5 rounded down.
#### Great Hall::OnActionPhase() ####
  * Draw a card from draw pile
  * Add 1 action to player’s turn
#### Harem::OnActionPhase() ####
  * No-op
#### Ironworks::OnActionPhase() ####
  * Query the player’s AI for GainACard( cost = 4 )
  * Check if card is in stock
  * Place card into discard pile
  * If card gained is an action card then add 1 action to player’s turn
  * If card gained is a treasure card then add 1 coin to player’s turn
  * If card gained is a victory card then draw 1 card to player’s hand
  * (Perform all 3 checks since mixed type cards allow for each result.)
#### Masquerade::OnActionPhase() ####
  * Draw 2 cards into player’s hand
  * Loop through the players and query each with OnMasqueradePass() which card from hand to pass to the next.
  * Check that the card is in hand
  * Pass the card on to the next player after querying that player’s AI which card to pass.
  * End Loop
  * Query the player’s AI with OnMasqueradeTrash() for a card to trash from hand.
  * Check that the card returned is in hand (or do nothing on NullCard)
  * Trash the returned card from the player’s hand.
#### Mining Village::OnActionPhase() ####
  * Draw 1 card into player’s hand
  * Add 2 actions to player’s turn
  * Query the player’s AI with OnMiningVillage() for a Mining Village option where to trash this card.
  * If the option is to trash this card then add 2 coins to player’s turn.
#### Minion::OnActionPhase() ####
  * Add 1 action to player’s turn
  * Query the player’s AI with OnMinion() for a minion option::
    * MINION\_PLUS\_2\_COIN
    * MINION\_ATTACK
  * If MINON\_PLUS\_2\_COIN then add 2 coin to player’s turn
  * Else if MINION\_ATTACK then discard hand and draw 4 cards
  * Attack other players
#### Minion::OnAttack() ####
  * If player has 5 or more cards in hand then
  * Discard hand
  * Draw 4 cards for other player.
#### Nobles::OnActionPhase() ####
  * Query the player’s AI for OnNobles() which returns
    * NOBLES\_PLUS\_3\_CARDS
    * NOBLES\_PLUS\_2\_ACTIONS
  * Draw 3 cards to the player’s hand or add 2 actions to the player’s turn.
#### Pawn::OnActionPhase() ####
  * Query the player’s AI with OnPawn() for a pair of Pawn options
  * Pawn options are:
    * PAWN\_PLUS\_1\_CARD
    * PAWN\_PLUS\_1\_ACTION
    * PAWN\_PLUS\_1\_BUY
    * PAWN\_PLUS\_1\_COIN
  * Check that the options returned are different and perform each of them.
#### Saboteur::OnActionPhase() ####
  * Attack other players
#### Saboteur::OnAttack() ####
  * Reveal cards from draw pile until revealing a card costing >= 3
  * Trash the selected card
  * Query the player’s AI with OnGainACard()to gains a card costing trashedcard.coin – 2
  * Put the revealed cards in the DiscardPile.
#### Scout::OnActionPhase() ####
  * Add 1 action to player’s turn
  * Reveal 4 cards
  * Move any victory cards from revealed pile into the player’s hand
  * Query the player’s AI with OnReturnToDrawPile( cardList ) which gives the player a list of card and returns a list of cards to be placed back on the deck. (The list is pushes on the draw pile stack so the first card in the list is the first pushed on the draw pile stack so the last card in the list will be the new top card after Scout is played.)
  * Check that the cards in the list returned is the same as the cards passed in.
  * Put the cards from the list onto the DrawPile.
#### Shanty Town::OnActionPhase() ####
  * Add 2 actions to players turn
  * Reveal hand()
  * If no action cards in hand then draw 2 cards to the player’s hand.
#### Steward::OnActionPhase() ####
  * Query the player’s AI with OnSteward () to return a Steward option
    * STEWARD\_PLUS\_2\_CARDS
    * STEWARD\_PLUS\_2\_COINS
    * STEWARD\_TRASH\_2\_CARDS
  * If trash 2 cards is selected then query the player’s AI with OnStewardTrash() to return 2 cards to trash from hand.
  * Check that 2 cards were returned and that the 2 cards returned are in the players hand.
  * Trash the 2 cards returned from the player’s hand.
#### Secret Chamber::OnActionPhase() ####
  * Query the player’s AI for a list of cards to discard OnSecretChamber ()
  * Check that the cards are in the player’s hand and for each card discarded, add +coins to the player’s turn.
#### Secret Chamber::Reaction( AttackCard ) ####
  * Draw 2 cards into player’s hand.
  * Query the player’s AI for 2 cards to place on top of the deck with SecretChamberReaction( AttackCard ) and pass in the attack card that triggered this.
  * Check that 2 cards were returned and the returned cards are in the player’s hand.
  * Put back the returned cards from the player’s hand to the draw pile.
#### Swindler::OnActionPhase() ####
  * Add 2 coin to player’s turn
#### Swindler::OnAttack() ####
  * Trash the top for of the player’s deck.
  * Query the attacking player’s AI with OnSwindler( cost ) to return a card for the victim player to gain.
  * Check that the card returned cost <= to the cost passed ot the function and is a valid supply pile.
  * Gain a card from the supply to the victim player’s discard pile.
  * If the supply pile is empty do nothing.
#### Torturer::OnActionPhase() ####
  * Draw 3 cards to the player’s hand.
  * Attack other players
#### Torturer::OnAttack() ####
  * Query the player’s AI with OnTorturer() for two cards from hand to discard.
  * Check the list of cards that the size is 2 and the cards are in the player’s hand.
  * Discard returned cards from hand.
  * Else put a curse in the player’s hand.
#### Trading Post::OnActionPhase() ####
  * Query the player’s AI with OnTradingPost() for two cards from hand to trash.
  * Check that two cards were returned and the cards are in the player’s hand.
  * Trash the cards returned.
  * Gain a SilverCard into the player’s hand.
#### Tribute::OnActionPhase() ####
  * Reveals 2 cards from left player’s deck and then discards them to left player’s discard pile.
  * If card1 is action then add 2 actions to player’s turn
  * If card1 is treasure then add 2 coins to player’s turn
  * If card1 is victory then draw 2 cards into the player’s hand
  * If card2 == card1 then do nothing otherwise repeat checks for card2
#### Upgrade::OnActionPhase() ####
  * Draw 1 card into player’s hand
  * Add 1 action to player’s turn
  * Query the player’s AI with UpgradeTrash() to return a card from hand to trash.
  * Check the card returned is in hand (need to check if the hand is empty in which case no cards are trashed or gained)
  * Generate a list of cards that could be purchased (exclude any cards where the stock is empty)
  * Use GainACardExactly() the finish the function with a cost one more than the trashed card.
#### Wishing Well::OnActionPhase() ####
  * Draw 1 card into player’s hand
  * Add 1 action to player’s turn
  * Query player with OnWishing () to return a card to wish for from the player’s draw pile.
  * Reveal top card of the draw pile.
  * If card is equal to wished card then put the card into hand
  * Else put the revealed card back on deck.
## Seaside Set Cards ##
#### Ambassador::OnActionPhase() ####
  * Query the player’s AI with OnAmbassador() for a list of cards to trash from hand.
  * Check that the list is size 1 or 2 and that the cards are the same
  * Add the cards to the supply pile
  * Set AmbassadorCard to the card in the engine
  * Attack players
  * Set AmbassadorCard to the null card in the engine
#### Ambassador::OnAttack() ####
  * Player gains a copy of the AmbassadorCard (get state from engine) on DiscardPile.
#### Bazaar::OnActionPhase() ####
  * Draw 1 card into the player’s hand
  * Add 2 actions to the player’s turn
  * Add 1 coin to the player’s turn
#### Caravan::OnActionPhase() ####
  * Draw 1 card into the player’s hand
  * Add 1 action to the player’s turn
#### Caravan::OnDurationPhase() ####
  * Draw 1 card into the player’s hand
#### Caravan::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Cutpurse::OnActionPhase() ####
  * Add 2 coin to player’s turn
  * Attack other players
#### Cutpurse::OnAttack() ####
  * If player’s hand has no copper then reveal hand.
  * Else discard copper from player’s hand
#### Embargo::OnActionPhase() ####
  * Add 2 coin to player’s turn
  * Query the player’s AI on Embargo() which returns a card to embargo
  * Check the card is a valid stock
  * Add an embargo token to the stock pile
  * (In the buy phase any purchase of a card with embargo tokens gets Curse card per embargo token)
#### Embargo::OnCleanup() ####
  * Trash this card from the InPlayList.
#### Explorer::OnActionPhase() ####
  * If player has a province in hand then query the player’s AI with OnExplorer() reveal province card from hand.
  * If returns true then gain a Gold card into the player’s hand
  * Else gain a silver card into the player’s hand
#### Fishing Village::OnActionPhase() ####
  * Add 2 actions to the player’s turn
  * Add 1 coin to the player’s turn
#### Fishing Village::OnDurationPhase() ####
  * Add 1 action to the player’s turn
  * Add 1 coin to the player’s turn
#### Fishing Village::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Ghost Ship::OnActionPhase() ####
  * Draw 2 cards into the player’s hand
  * Attack other players
#### Ghost Ship::OnAttack() ####
  * Query the player’s AI with OnGhostShip() to return a list of cards to discard from hand such that the hand’s size will be <= 3.
  * Check the cards returned are in the players hand and it would reduce the size of the hand to <= 3.
  * Discard the cards return from the players hand.
#### Haven::OnActionPhase() ####
  * Add 1 card to player’s hand
  * Add 1 action to player’s turn
  * Query player for card from hand with Haven()
  * Check the card is in the player hand
  * Place card into HavenList
#### Haven::OnDurationPhase() ####
  * Move a card from the HavenList to the player’s hand.
#### Haven::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Island::OnActionPhase() ####
  * Query the player’s AI with OnIsland() for a card from hand to place on Island mat.
  * Check is card is in hand
  * Move card from hand to the Island mat.
  * Move Island from InPlayList to Island mat
#### Lighthouse::OnActionPhase() ####
  * Add 1 action to the player’s turn
  * Add 1 coin to the player’s turn
#### Lighthouse::OnDurationPhase() ####
  * Add 1 coin to the player’s turn
#### Lighthouse::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Lookout::OnActionPhase() ####
  * Add 1 action to player’s turn
  * Generate list of 3 cards from draw pile
  * Query the player’s AI with Lookout( cardList ) which returns LookoutStruct containing 3 cards from hand to trash, discard and put back.
  * Check that each card in the struct is in the output list, watch out to handle duplicate cards correctly
  * Dicard, trash and put back the cards from the struct accordingly.
#### Merchant Ship::OnActionPhase() ####
  * Add 2 coin to the player’s turn
#### Merchant Ship::OnDurationPhase() ####
  * Add 2 coin to the player’s turn
#### Merchant Ship::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Native Village::OnActionPhase() ####
  * Add 2 actions to the player’s turn
  * Query the player’s AI with OnNativeVillage() for a Native Village option
    * NATIVE\_VILLAGE\_PUT\_AWAY\_CARD
    * NATIVE\_VILLAGE\_DRAW\_CARDS
  * If NATIVE\_VILLAGE\_PUT\_AWAY\_CARD then put the card from the top of the players deck on to the players native village mat (list)
  * If NATIVE\_VILLAGE\_DRAW\_CARDS then draw all the cards from the native village mat into the player’s hand
#### Navigator::OnActionPhase() ####
  * Add 2 coin to player’s turn
  * Generate list of 5 cards from draw pile
  * Query the player’s AI with OnNavigator( cardList) to return the list of cards reordered by the player to put back on top of the deck or returns and empty list to indicate that the list of 5 cards should be discarded
  * Check that the list of cards returned is the same as the input list.
  * If the list is empty then put the input list in the DiscardPile
  * Else put the returned list into the draw pile.
#### Outpost::OnActionPhase() ####
  * If Outpost card in DurationList then return error.
#### Outpost::OnCleanupPhase() ####
  * Set the Outpost flag for next turn.
#### Output::OnDurationPhase() ####
  * Reset the Outpost flag.
#### Outpost::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Pearl Diver::OnActionPhase() ####
  * Draw 1 card to player’s hand
  * Add 1 action to player’s turn
  * Set aside the card from the bottom of the player’s DrawPile.
  * Query the player’s AI with OnPearlDiver() for a pearl diver option.
    * PEARLDIVER\_TOP\_OF\_DRAWPILE
    * PEARLDIVER\_BOTTOM\_OF\_DRAWPILE
  * Place the card back in the DrawPile based on the option returned.
#### Pirate Ship::OnActionPhase() ####
  * Query player for an option OnPirateShip() which should return
  * PIRATESHIP\_ATTACK
  * PIRATESHIP\_PLUS\_COINS
  * If PIRATESHIP\_ATTACK then
```
{
    foundTreasure = false
    attack other players
    if( foundTreasure == true )
    {
        Add 1 pirate ship coin to player’s pirate ship mat (int)
    }
}
```
  * Else add pirate ship coins to player’s turn
#### Pirate Ship::OnAttack() ####
  * Reveal 2 cards from player’s draw pile.
  * Add treasure cards to a list
  * If list.size() > 0 then  foundTreasure = true
  * if list.size() == 1 then set card in the list the card to trash
  * else query attacking player with OnPriateShipTrash ( cardList ) to return a treasure card to trash.
  * Check the card returned is in the list.
  * Trash the treasure from the other player’s reveal list
#### Salvager::OnActionPhase() ####
  * Add 1 buy to player’s turn
  * Query the player’s AI with OnSalvager() for a card to trash from hand.
  * Check that the card returned is in the player’s hand.
  * Add the card’s cost to the player’s turn
  * Trash the card from the player’s hand
#### Sea Hag::OnActionPhase() ####
  * Attack each other player
#### Sea Hag::OnAttack() ####
  * Discard a card from the player’s draw pile.
  * Gain a Curse card to the player’s draw pile.
#### Smugglers::OnActionPhase() ####
  * Get the BuyList of cards from the player to the left.
  * Filter out any cards costing more than 6 coins.
  * Query the player with Smugglers( cardList ) to return a card from the list to gain
  * Check that the card returned is in the list.
  * Gain the card from the supply to the player’s DiscardPile.
#### Tactician::OnActionPhase() ####
  * Discard all cards from player’s hand
#### Tactician::OnDurationPhase() ####
  * Draw 5 cards into the player’s hand
  * Add 1 buy to the player’s turn
  * Add 1 action to the player’s turn
#### Tactician::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
#### Treasure Map::OnActionPhase() ####
  * If the player’s hand contains another copy, trash the copy.
  * If the copy was trashed then the player gains 4 gold cards to the top the draw pile.
#### Treasure Map::OnCleanupPhase() ####
  * Trash this card from the InPlayList.
#### Treasury::OnActionPhase() ####
  * Draw 1 card into the player’s hand
  * Add 1 action to the player’s turn
  * Add 1 coin to the player’s turn
#### Treasury::OnCleanupPhase() ####
  * If BuyList does not have a victory card
  * Then query the player’s AI with OnTreasury for a treasury option.
  * If treasure option indicates to put the card back then move this card to draw pile.
#### Warehouse::OnActionPhase() ####
  * Draw 3 cards to player’s hand
  * Add 1 action to player’s turn
  * Query the player’s AI with OnWarehouse() for a list of 3 cards to discard from hand.
  * Check that the list is size 3 and the cards are in hand (handle duplicate cards correctly)
  * Discard the cards from the player’s hand.
#### Wharf::OnActionPhase() ####
  * Draw 2 cards into the player’s hand
  * Add 1 buy to the player’s turn
#### Wharf::OnDurationPhase() ####
  * Draw 2 cards into the player’s hand
  * Add 1 buy to the player’s turn
#### Wharf::OnCleanupPhase() ####
  * Move this card from InPlayList to the DurationList.
## Alchemy Set Cards ##
#### Alchemist::OnActionPhase() ####
  * Draw 2 cards into the player’s hand
  * Add 1 action to the player’s turn
#### Alchemist::OnCleanupPhase() ####
  * If the player’s InPlayList contains a potion then query the player’s AI with OnAlchemist() for an alchemist option.
  * If the option return is to put back the alchemist card then put it on top of the draw pile.
#### Apothecary::OnActionPhase() ####
  * Draw 1 card into the player’s hand
  * Add 1 action to the player’s turn
  * Generate a reveal list of 4 cards from the player’s DrawPile.
  * Put coppers and potions from the reveal list into the player’s hand.
  * Query player with OnReturnToDrawPile ( cardList ) with filtered list to return the list reordered by player  (see Scout for reorder)
  * Check output list is the same as the input list.
  * Put cards in the lost top of the DrawPile.
#### Apprentice::OnActionPhase() ####
  * Add 1 action to the player’s turn
  * Query the player’s AI with OnApprentice() for a card to trash from hand.
  * Check the card return is in hand.
  * Trash the returned card from hand.
  * Add trashedcard.coin + (trashedcard.potion != 0) ? 2 : 0 to the coins in the player’s turn
#### Familiar::OnActionPhase() ####
  * Draw 1 card to player’s hand
  * Add 1 action to player’s turn
  * Attach other players
#### Familiar::OnAttack() ####
  * Player gains a curse to the discard pile
#### Golem::OnActionPhase() ####
  * Reveal cards from the DrawPile until 2 non-Golem cards have been drawn.
  * Discard the revealed cards
  * Query the player’s AI with OnGolem( cardList ) to return a reordered list of action cards to play.
  * Play the action cards from the list in order.
  * (Note: when the cards are played, they should not have access to the player’s hand and do not have access to the other card the Golem plays.)
#### Herbalist::OnActionPhase() ####
  * Add 1 buy to the player’s turn
  * Add 1 coin to the player’s turn
#### Herbalist::OnCleanupPhase() ####
  * If any treasure cards in InPlayList then query the player’s AI with OnHerbalist() to pick a treasure to put on DrawPile.
  * Check that the card returned is a treasure and is in the player’s InPlayList.
  * Move the card from InPlayList to the DrawPile.
#### Philosopher’s Stone::OnActionPhase() ####
  * No-op
#### Philosopher’s Stone::OnTreasurePhase() ####
  * Return the sum of the cards in the players draw pile and discard pile divide by 5 and round down.
#### Philosopher’s Stone::TreasureValue() ####
  * Return 0 for TreasureValue() since this card only return value greater than 0 with in the context of the OnTreasurePhase().
#### Possession::OnActionPhase() ####
  * No-op. This card simply needs to be played in the InPlayList.
#### Possession::OnCleanupPhase() ####
  * Set the Possession flag on the left player’s turn (the turn mechanism needs to be enhanced to allow for a possessing AI and prevent cards from being trashed but instead put into a possession trash pile to be discarded)
Note: At the end of the left player’s possessed turn then the flag has to be disabled.
The turn mechanism needs to be able to swap the player AI temporarily
#### Potion::OnActionPhase() ####
  * No-op
#### Scrying Pool::OnActionPhase() ####
  * Add 1 action to the player’s turn
  * Attack every player (including yourself)
  * Reveal cards from DrawPile until an Action card is revealed.
  * Move cards in reveal list into the players hand.
#### Scrying Pool::OnAttack() ####
  * Reveal a card from the player’s deck.
  * If the player is the attacker then query the player’s AI with OnScryingPoolSelf() for the scrying pool option.
  * If the player is not the attacker then query the player’s AI with OnScryingPoolOther() for the scrying pool option.
  * If the scrying pool option is discard then move the card revealed to the discard pile.
  * If the scrying pool option is not discard then move the card revealed back to the draw pile.
#### Transmute::OnActionPhase() ####
  * Query the player’s AI with OnTransmute() for a card from hand to trash.
  * Check if card returned is in hand
  * Trash card from hand
  * If trashed card is an action then gain a duchy in discard pile.
  * If trashed card is a treasure then gain a transmute in discard pile.
  * If trashed card is a victory card then gain a gold in discard pile.
#### University::OnActionPhase() ####
  * Add 2 actions to player’s turn
  * Query the player’s AI with GainAnActionCard( cost 5 )
  * Check card is an action card that cost <= 5
  * Add the card to the player’s discard pile
#### Vineyard::OnActionPhase() ####
  * No-op
#### Vinyard::OnScoring() ####
  * Return the sum the number of action cards in the player’s Deck divide by 3 rounded down.
## Prosperity Set Cards ##
Need to ask query of treasure cards if the player wants to put them in play since many of the Prosperity Treasure cards have side effects. The Treasure() function should be called one during the buy phase and perform any side effects. Treasure() will calculate give the treasure value of the card. Need to check if there are any other places Treasure() might be needed to be called.
#### Bank::OnTreasurePhase() ####
  * Return the number of treasure cards in “in-play” list as the value of this treasure
#### Bishop::OnActionPhase() ####
  * Draw 1 card to player’s hand
  * Add 1 victory point token to player’s victory point mat
  * If the players hand is not empty query the player with OnBishipSelf() to trash a card from hand.
  * Check that the card returned is in hand. (Error on a NullCard)
  * Add victory point tokens equal to half the card trashed cost in coins rounded down.
  * For each other player query the player’s AI with OnBishipOther() to return a card from hand to trash.
  * Check that the card returned is in hand (do nothing on a NullCard.)
#### City::OnActionPhase() ####
  * Draw 1 card into the player’s hand
  * Add 2 actions to the player’s turn
  * If numEmptySupplyPiles >= 1 then draw 1 card into the player’s hand
  * If numEmptySupplyPiles >= 2 then add 1 coin and add 1 buy into player’s turn
  * (Perform both conditional checks since in the case of >= 2 you still draw 1 card as well.)
#### Contraband::OnActionPhase() ####
  * Add 1 buy to the player’s turn
#### Contraband::OnBuyPhase() ####
  * Query the player’s AI to the left with OnContraband() to name a card
  * Set Contraband flag on Supply Pile named
#### Contraband::OnCleanupPhase() ####
  * Reset the contraband flags for the SupplyPiles.
#### Counting House::OnActionPhase() ####
  * Count the number of Coppers in the DiscardPile.
  * Query the player’s AI with OnCountingHouse() to return the number of coppers to draw from the DiscardPile which is passed to the player.
  * Check the number of coppers returned is <= the number of coppers in the DiscardPile.
  * Move as many coppers from the DiscardPile to the player’s Hand as requested.
#### Expand::OnActionPhase() ####
  * Query the player’s AI to trash a card from hand with OnExpand().
  * Check that the card returned is in the player’s hand.
  * Trash the card returned.
  * Complete the function with a call to OnGainACard( trashedCard.cost + 3)
#### Forge::OnActionPhase() ####
  * Query the player’s AI with OnForge() for list of cards from hand to trash.
  * Check that the cards returned are in hand.
  * Trash the cards in the list from the player’s hand.
  * Complete the function with a call to OnGainACard( sum of the cost of the cards trashed).
#### Goons::OnActionPhase() ####
  * Add 1 buy to player’s turn
  * Add 2 coins to player’s turn
#### Goons::OnCleanupPhase() ####
  * Count the number of cards in the BuyList and add that many victory point tokens to the player’s mat.
#### Goons::OnAttack() ####
  * Query the player’s AI with OnGoon() to return a list of cards to discard from hand such that the hand’s size will be <= 3.
  * Check the cards returned are in the players hand and it would reduce the size of the hand to <= 3.
  * Discard the cards return from the player’s hand.
#### Grand Market::OnActionPhase() ####
  * Draw 1 card into player’s hand
  * Add 1 action to player’s turn
  * Add 1 buy to player’s turn
  * Add 2 coin to player’s turn
  * Note: Add logic to buyphase to block this card if copper is in play but only when the buy is requested. If mint is bought then all the coppers are trashed but the buying power remains the same and if there are enough +buys and treasure points the Grand Market can be bought.
#### Hoard::OnCleanupPhase( card ) ####
  * For each victory card in the BuyList, the player gains a gold card to the discard pile.
#### King’s Court::OnActionPhase() ####
  * See Throne Room for implementation details.
#### Loan::OnBuyPhase() ####
  * Reveal cards from the player’s DrawPile until a Treasure card is revealed.
  * Query the player’s AI with OnLoad() to return a Loan option to discard or trash the Treasure card revealed.
  * Discard or trash the card
  * Discard the cards in the revealed pile to the DiscardPile.
#### Monument::OnActionPhase() ####
  * Add 2 coin to player’s turn
  * Add 1 victory point token to player’s victory point mat
#### Mint::OnActionPhase() ####
  * Query the player’s AI with OnMint() to return a card from hand to copy.
  * Check the card returned is in hand
  * Gain a copy of it in the discard pile.
#### Mint::OnBuy() ####
  * Trash all treasure in “in-play” list.
  * Note: Buy() is not the same as BuyPhase() this operation occurs when this card is purchased not when it is using the in the buy phase.
#### Mountebank::OnActionPhase() ####
  * Add 2 coin to player’s turn
  * Attack other players
#### Mountebank::OnAttack() ####
  * If the player has a Curse card in hand then query the player’s AI with OnMontebank() to return a Montebank option to discard a curse from hand.
  * If the player return to discard a Curse then do nothing.
  * If the player does not discard a Curse then gain a curse and copper in discard pile.
#### Peddler::OnActionPhase() ####
  * Draw card into player’s hand
  * Add 1 action to player’s turn
  * Add 1 coin into player’s turn
#### Peddler::Cost() ####
  * Return max(8 - Sum the number of action cards in “in-play” list 