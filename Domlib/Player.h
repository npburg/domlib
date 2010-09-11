#pragma once

#include "Domlib.h"
#include "Card.h"
#include "IAI.h"

namespace Domlib
{

enum CARDID;
enum CARDTYPE;
class Player;

typedef std::list<Player*>          PlayerList;
typedef PlayerList::iterator        PlayerListIter;
typedef PlayerList::const_iterator  PlayerListConstIter;

class Player
{
public:
    Player( Engine* pEngine, IAI* pAi );
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

    void    DiscardDrawPile( void );

    void    DiscardFromHand( CardList cardList );
    void    DiscardFromHand( Card* pCard );
    void    DiscardFromHandToDrawPile( Card* pCard );

    void    TrashFromHand( CardList cardList );
    void    TrashFromHand( Card* pCard );
    void    TrashFromHand( CARDID cardId );
    void    TrashFromInPlay( Card* pCard );
    void    TrashFromInPlay( CARDID cardId );
    void    TrashCard( Card* pCard );
    Card*   TrashFromDeck();
    
    void    GainCardOnDiscard( Card* pCard );
    void    GainCardOnDiscard( CARDID cardId );
    void    GainCardOnDeck( Card* pCard );
    void    GainCardOnDeck( CARDID cardId );
    void    GainCardInHand( Card* pCard );
    void    GainCardInHand( CARDID cardId );

    void    PutCardInDiscard( Card* pCard );
    void    PutCardOnDraw( Card* pCard );
    void    PutCardOnDraw( CARDID cardId );
    void    PutCardInHand( Card* pCard );

    void    PutCardsInDiscard( CardList cardList );
    void    PutCardsOnDraw( CardList cardList );
    void    PutCardsInPlay( CardList cardList );
    void    PutCardsInHand( CardList cardList );

    Card*     RevealCardFromDeck();
    CardList  RevealCardsFromDeck( int numCards );
    CardList  RevealHand();

    Card*     OnGainACard( ITreasure* cost );
    Card*     OnGainACardExactly( ITreasure* cost );

    void    TakeCardFromHand( Card* pCard );
    void    TakeCardFromInPlay( CARDID cardId );
    void    TakeCardFromInPlay( Card* pCard );

    void    DrawCardsToHand( int numCards );
    void    PlusCoins( int numCoins );
    void    PlusActions( int numActions );
    void    PlusBuys( int numBuys );

    int     DrawSize( void );
    int     DiscardSize( void );

    int     GetDeckSize( void );
    int     GetCardCountInDeckId( CARDID cardId );
    int     GetCardCountInDeckType( CARDTYPE cardType );
    int     GetCardCountInHandType( CARDTYPE cardType );

    void    SetGolemFlag( bool );

    // IPlayer Interfaces
    virtual CardList   GetHand( void );
    virtual int         HandSize( void );
    virtual int         ActionsPlayed( void );

protected:
    void OnDurationPhase( void );
    void OnActionPhase( void );
    void OnTreasurePhase( void );
    void OnBuyPhase( void );
    void OnCleanUpPhase( void );

private:
    const Engine*   m_pEngine;
    const IAI*      m_pAi;

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
};

} // namespace Domlib