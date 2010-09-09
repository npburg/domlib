#pragma once

#include "Domlib.h"
#include "Card.h"

namespace Domlib
{

enum CARDID;
enum CARDTYPE;
class Player;

typedef std::list<Player*>          PlayerList;
typedef PlayerList::iterator        PlayerListIter;
typedef PlayerList::const_iterator  PlayerListConstIter;

class Player :
    public IPlayer
{
public:
    Player( Engine* pEngine, AI* pAi );
    virtual ~Player( void );

    void PlayTurn( void );

    AI*    GetAI( void );

    bool    AreCardsInHand( ICardList cardList );
    bool    IsCardInHand( ICard* pCard );
    bool    IsCardInHand( CARDID cardId );
    bool    IsCardInDuration( ICard* pCard );
    bool    IsCardInDuration( CARDID cardId );
    bool    IsCardInPlay( CARDID cardId );
    bool    IsCardInPlay( ICard* pCard );

    void    DiscardDrawPile( void );

    void    DiscardFromHand( ICardList cardList );
    void    DiscardFromHand( ICard* pCard );
    void    DiscardFromHandToDrawPile( ICard* pCard );

    void    TrashFromHand( ICardList cardList );
    void    TrashFromHand( ICard* pCard );
    void    TrashFromHand( CARDID cardId );
    void    TrashFromInPlay( ICard* pCard );
    void    TrashFromInPlay( CARDID cardId );
    void    TrashCard( ICard* pCard );
    ICard*     TrashFromDeck();
    
    void    GainCardOnDiscard( ICard* pCard );
    void    GainCardOnDiscard( CARDID cardId );
    void    GainCardOnDeck( ICard* pCard );
    void    GainCardOnDeck( CARDID cardId );
    void    GainCardInHand( ICard* pCard );
    void    GainCardInHand( CARDID cardId );

    void    PutCardInDiscard( ICard* pCard );
    void    PutCardOnDraw( ICard* pCard );
    void    PutCardOnDraw( CARDID cardId );
    void    PutCardInHand( ICard* pCard );

    void    PutCardsInDiscard( ICardList cardList );
    void    PutCardsOnDraw( ICardList cardList );
    void    PutCardsInPlay( ICardList cardList );
    void    PutCardsInHand( ICardList cardList );

    ICard*     RevealCardFromDeck();
    ICardList  RevealCardsFromDeck( int numCards );
    ICardList  RevealHand();

    ICard*     OnGainACard( Treasure cost );
    ICard*     OnGainACardExactly( Treasure cost );

    void    TakeCardFromHand( ICard* pCard );
    void    TakeCardFromInPlay( CARDID cardId );
    void    TakeCardFromInPlay( ICard* pCard );

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
    virtual ICardList  GetHand( void );
    virtual int               HandSize( void );
    virtual int               ActionsPlayed( void );

protected:
    void OnDurationPhase( void );
    void OnActionPhase( void );
    void OnTreasurePhase( void );
    void OnBuyPhase( void );
    void OnCleanUpPhase( void );

private:
    const Engine*           m_pEngine;
    const AI*        m_pAi;

    ICardList        m_DrawPile;
    ICardList        m_Hand;
    ICardList        m_DiscardPile;
    ICardList        m_RevealedList;
    ICardList        m_BoughtList;
    ICardList        m_DurationList;
    ICardList        m_HavenList;
    ICardList        m_InPlayList;
    ICardList        m_IslandMat;
    int                     m_PirateShipMat;
    ICardList        m_NativeVillageMat;
    bool                    m_GolemFlag;
    ICardList        m_PlayerMat;    // Holds Victory tokens from Prosperity
    int                     m_ActionsPlayed;
};

} // namespace Domlib