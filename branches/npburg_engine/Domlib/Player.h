#pragma once

#include "Domlib.h"
#include "Card.h"
#include "IAI.h"

namespace Domlib
{

class Player;

typedef std::list<Player*>          PlayerList;
typedef PlayerList::iterator        PlayerListIter;
typedef PlayerList::const_iterator  PlayerListConstIter;

class Player
{
public:
    Player( Engine* pEngine, IAI* pAI );
    virtual ~Player( void );

    void PlayTurn( void );

    IAI*    GetAI( void );

    bool    AreCardsInHand( CardList cardList );
    bool    IsCardInHand( Card* pCard );
    bool    IsCardInHand( CARDID cardId );
    bool    IsCardInDuration( Card* pCard );
    bool    IsCardInDuration( CARDID cardId );
    bool    IsCardInPlay( CARDID cardId );
    bool    IsCardInPlay( Card* pCard );
    bool    IsCardInBuyList( Card* pCard );
    bool    IsCardInBuyList( CARDTYPE cardType );

    void    DiscardDrawPile( void );

    void    DiscardHand( void );
    void    DiscardFromHand( CardList cardList );
    void    DiscardFromHand( Card* pCard );
    void    DiscardFromHand( CARDID cardId );
    void    DiscardFromHandToDrawPile( Card* pCard );
    void    DiscardFromDraw( int numCards );

    void    TrashFromHand( CardList cardList );
    void    TrashFromHand( Card* pCard );
    void    TrashFromHand( CARDID cardId );
    void    TrashFromInPlay( Card* pCard );
    void    TrashFromInPlay( CARDID cardId );
    void    TrashFromInPlay( CARDTYPE cardType );
    void    TrashCard( Card* pCard );
    Card*   TrashCardFromDeck();
    
    void    GainCardOnDiscard( Card* pCard );
    void    GainCardOnDiscard( CARDID cardId );
    void    GainCardOnDeck( Card* pCard );
    void    GainCardOnDeck( CARDID cardId );
    void    GainCardInHand( Card* pCard );
    void    GainCardInHand( CARDID cardId );

    void    PutCardInDiscard( Card* pCard );
    void    PutCardOnDraw( Card* pCard );
    void    PutCardOnDraw( CARDID cardId );
    void    PutCardUnderDraw( Card* pCard );
    void    PutCardInHand( Card* pCard );
    void    PutCardInHand( CARDID cardId );
    void    PutCardInHaven( Card* pCard );
    void    PutCardOnIsland( Card* pCard );
    void    PutCardInPlay( Card* pCard );

    void    PutCardsInDiscard( CardList cardList );
    void    PutCardsOnDraw( CardList cardList );
    void    PutCardsInPlay( CardList cardList );
    void    PutCardsInHand( CardList cardList );

    CardList    SetAside( int numCards );
    Card*       SetAsideCardFromUnderDraw();

    Card*     RevealCardFromDeck();
    CardList  RevealCardsFromDeck( int numCards );
    CardList  RevealHand();

    Card*   OnGainACard( Treasure* cost );
    Card*   OnGainACardExactly( Treasure* cost );

    void    TakeCardFromHand( Card* pCard );
    Card*   TakeCardFromHaven( void );
    void    TakeCardFromInPlay( CARDID cardId );
    void    TakeCardFromInPlay( Card* pCard );
    void    TakeCardFromDiscard( CARDID cardId );

    void    TakeCardsFromHand( CardList cardList );

    void    DrawCardToNativeVillage();
    void    DrawCardsFromNativeVillage();
    void    DrawCardsToHand( int numCards );
    void    PlusCoins( int numCoins );
    void    PlusActions( int numActions );
    void    PlusBuys( int numBuys );
    void    PlusPirateCoin( void );
    void    PlusVictoryTokens( int numTokens );

    int     DrawSize( void );
    int     DiscardSize( void );

    int     GetDeckSize( void );
    int     GetCardCountInDeckId( CARDID cardId );
    int     GetCardCountInDeckType( CARDTYPE cardType );
    int     GetCardCountInHandType( CARDTYPE cardType );

    void    SetGolemFlag( bool flag );
    void    SetTacticianFlag( bool flag );
    
    bool    TacticianFlag( void );

    void    MinusQuarry( void );
    void    MinusRoyalSeal( void );
    
    void    PlusCoppersmith( void );
    void    PlusBridge( void );
    void    PlusQuarry( void );
    void    PlusRoyalSeal( void );

    int     CardsInDiscard( CARDID cardId );

    // IPlayer Interfaces
    virtual CardList    GetHand( void );
    virtual CardList    GetBuyList( void );
    virtual int         CardsInHand( void );
    virtual int         CardsInHand( Card* pCard );
    virtual int         CardsInHand( CARDID cardId );
    virtual int         CardsInHand( CARDTYPE cardType );
    virtual int         CardsInPlay( CARDTYPE cardType );
    virtual int         CardsBought( CARDTYPE cardType );
    virtual int         ActionsPlayed( void );
    virtual int         PirateCoins( void );
    virtual CardList    GainList( void );

protected:
    void OnDurationPhase( void );
    void OnActionPhase( void );
    void OnTreasurePhase( void );
    void OnBuyPhase( void );
    void OnCleanUpPhase( void );

private:
    const Engine*   m_pEngine;
    const IAI*      m_pAI;

    CardList        m_DrawPile;
    CardList        m_Hand;
    CardList        m_DiscardPile;
    CardList        m_RevealedList;
    CardList        m_BoughtList;
    CardList        m_DurationList;
    CardList        m_HavenList;
    CardList        m_InPlayList;
    CardList        m_IslandMat;
    int             m_PirateShipMat;
    CardList        m_NativeVillageMat;
    bool            m_GolemFlag;
    CardList        m_PlayerMat;    // Holds Victory tokens from Prosperity
    int             m_ActionsPlayed;
    bool            m_TacticianFlag;
    int             m_VictoryTokens;
    
    int             m_CoppersmithCount;
    int             m_BridgeCount;
    int             m_QuarryCount;
    bool            m_RoyalSealFlag;
};

} // namespace Domlib