#include "StdAfx.h"
#include "DefaultAI.h"

DefaultAI::DefaultAI( void )
{
}


DefaultAI::~DefaultAI( void )
{
}


Domlib::ICard* DefaultAI::PlayAction( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::PlayTreasure( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::BuyCard( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnAttack( Domlib::ICard* pAttackCard )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnGainACard( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnGainACardExactly( const Domlib::ITreasure* cost )
{
    Domlib::ICardList cardList = m_pEngine->CardsCostingExactly( cost );
    
    if( cardList.size() )
    {
        return (*cardList.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICardList DefaultAI::OnReturnToDrawPile( Domlib::ICardList cardList )
{
    return cardList;
}


Domlib::ICard* DefaultAI::OnTrashCardFromHand( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnBureaucrat( void )
{
    if( m_pPlayer->CardsInHand( Domlib::CARDTYPE::VICTORY ) )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        
        for( Domlib::ICardListIter iter = hand.begin();
             iter != hand.end();
             iter++ )
        {
            if( (*iter)->IsVictoryCard() )
            {
                return (*iter);
            }
        }
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICardList DefaultAI::OnCellar( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::ChancellorOpt DefaultAI::OnChancellor( void )
{
    return Domlib::ChancellorOpt::NO_OP;
}


Domlib::ICardList DefaultAI::OnChapel( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::LibraryOpt DefaultAI::OnLibrary( Domlib::ICard* pCard )
{
    return Domlib::LibraryOpt::DISCARD_ACTION_CARD;
}


Domlib::ICardList DefaultAI::OnMilitia( void )
{
    Domlib::ICardList discardList;
    int numCardsInHand = m_pPlayer->CardsInHand();

    if( numCardsInHand > 3 )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        
        for( Domlib::ICardListIter iter = hand.begin();
             iter != hand.end();
             iter++ )
        {
            discardList.push_back( (*iter) );
            if( numCardsInHand - discardList.size() <= 3 )
            {
                return discardList;
            }
        }
    }
    
    return discardList;
}


Domlib::ICard* DefaultAI::OnMineTrash( void )
{
    if( m_pPlayer->CardsInHand( Domlib::CARDTYPE::TREASURE ) )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        
        for( Domlib::ICardListIter iter = hand.begin();
             iter != hand.end();
             iter++ )
        {
            if( (*iter)->IsTreasureCard() )
            {
                return (*iter);
            }
        }
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnMineGain( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::COPPER );
}


Domlib::ICard* DefaultAI::OnRemodel( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::SpyOpt DefaultAI::OnSpyOther( Domlib::ICard* pCard )
{
    return Domlib::SpyOpt::DISCARD_CARD;
}


Domlib::SpyOpt DefaultAI::OnSpySelf( Domlib::ICard* pCard )
{
    return Domlib::SpyOpt::DISCARD_CARD;
}


Domlib::ThiefOpt DefaultAI::OnThiefGain( Domlib::ICard* pCard )
{
    return Domlib::ThiefOpt::STEAL_TREASURE_CARD;
}


Domlib::ICard* DefaultAI::OnThiefTrash( Domlib::ICardList cardList )
{
    return (*cardList.begin());
}


Domlib::ICard* DefaultAI::OnThroneRoom( void )
{
    if( m_pPlayer->CardsInHand( Domlib::CARDTYPE::ACTION ) )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        
        for( Domlib::ICardListIter iter = hand.begin();
             iter != hand.end();
             iter++ )
        {
            if( (*iter)->IsActionCard() )
            {
                return (*iter);
            }
        }
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::BaronOpt DefaultAI::OnBaron( void )
{
    return Domlib::BaronOpt::DISCARD_ESTATE;
}


Domlib::ICard* DefaultAI::OnCourtyard( void )
{
    Domlib::ICardList hand = m_pPlayer->GetHand();

    if( hand.size() )
    {
        return (*hand.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnIronworks( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnMasqueradePass( void )
{
    Domlib::ICardList hand = m_pPlayer->GetHand();

    if( hand.size() )
    {
        return (*hand.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnMasqueradeTrash( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::MiningVillageOpt DefaultAI::OnMiningVillage( void )
{
    return Domlib::MiningVillageOpt::DO_NOT_TRASH_CARD;
}


Domlib::MinionOpt DefaultAI::OnMinion( void )
{
    return Domlib::MinionOpt::PLUS_2_COINS;
}


Domlib::NoblesOpt DefaultAI::OnNobles( void )
{
    return Domlib::NoblesOpt::PLUS_3_CARDS;
}


Domlib::PawnOptPair DefaultAI::OnPawn( void )
{
    Domlib::PawnOptPair pawnOptPair;

    pawnOptPair.first = Domlib::PawnOpt::PLUS_1_ACTION;
    pawnOptPair.second = Domlib::PawnOpt::PLUS_1_CARD;
    
    return pawnOptPair;
}


Domlib::ICardList DefaultAI::OnSecretChamber( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::ICardList DefaultAI::OnSecretChamberReaction( void )
{
    Domlib::ICardList cardsToReturn;
    Domlib::ICardList hand = m_pPlayer->GetHand();
    
    for( Domlib::ICardListIter iter = hand.begin();
         iter != hand.end();
         iter ++ )
    {
        cardsToReturn.push_back( (*iter) );
        if( cardsToReturn.size() >= 2 )
        {
            break;
        }
    }
    
    return cardsToReturn;
}


Domlib::StewardOpt DefaultAI::OnSteward( void )
{
    return Domlib::StewardOpt::PLUS_2_COINS;
}


Domlib::ICardList DefaultAI::OnStewardTrash( void )
{
    Domlib::ICardList cardsToTrash;
    Domlib::ICardList hand = m_pPlayer->GetHand();
    
    for( Domlib::ICardListIter iter = hand.begin();
         iter != hand.end();
         iter ++ )
    {
        cardsToTrash.push_back( (*iter) );
        if( cardsToTrash.size() >= 2 )
        {
            break;
        }
    }
    
    return cardsToTrash;
}


Domlib::ICard* DefaultAI::OnSwindler( Domlib::ICard* pCard )
{
    Domlib::ICardList cardList = 
        m_pEngine->CardsCostingExactly( &pCard->Cost( m_pEngine ) );
    
    if( cardList.size() )
    {
        return (*cardList.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICardList DefaultAI::OnTorturer( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::ICardList DefaultAI::OnTradingPost( void )
{
    Domlib::ICardList cardsToTrash;
    Domlib::ICardList hand = m_pPlayer->GetHand();
    
    for( Domlib::ICardListIter iter = hand.begin();
         iter != hand.end();
         iter ++ )
    {
        cardsToTrash.push_back( (*iter) );
        if( cardsToTrash.size() >= 2 )
        {
            break;
        }
    }
    
    return cardsToTrash;
}


Domlib::ICard* DefaultAI::OnUpgrade( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnWishingWell( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::COPPER );
}


Domlib::ICard* DefaultAI::OnAmbassadorReveal( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


int DefaultAI::OnAmbassadorPutBack( Domlib::ICard* pCard )
{
    return 0;
}


Domlib::ICard* DefaultAI::OnEmbargo( void )
{
    Domlib::ICardList cardsAvailable = m_pEngine->PilesAvailable();

    if( cardsAvailable.size() )
    {
        return (*cardsAvailable.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ExplorerOpt DefaultAI::OnExplorer( void )
{
    return Domlib::ExplorerOpt::REVEAL_PROVINCE;
}


Domlib::ICardList DefaultAI::OnGhostShip( void )
{
    Domlib::ICardList cardsToReturn;
    int numCardsInHand = m_pPlayer->CardsInHand();

    if( numCardsInHand > 3 )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        
        for( Domlib::ICardListIter iter = hand.begin();
             iter != hand.end();
             iter++ )
        {
            cardsToReturn.push_back( *iter );
            if( numCardsInHand - cardsToReturn.size() <= 3 )
            {
                return cardsToReturn;
            }
        }
    }
    
    return cardsToReturn;
}


Domlib::ICard* DefaultAI::OnHaven( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnIsland( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ILookoutStruct DefaultAI::OnLookout( Domlib::ICardList cardList )
{
    Domlib::ILookoutStruct lookoutStruct;

    Domlib::ICardListIter iter = cardList.begin();

    lookoutStruct.pCardToDiscard = (*iter++);
    lookoutStruct.PCardToPutBack = (*iter++);
    lookoutStruct.pCardToTrash   = (*iter++);
    
    return lookoutStruct;
}


Domlib::NativeVillageOpt DefaultAI::OnNativeVillage( void )
{
    return Domlib::NativeVillageOpt::SET_ASIDE_CARD;
}


Domlib::ICardList DefaultAI::OnNavigator( Domlib::ICardList cardList )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::PearlDiverOpt DefaultAI::OnPearlDiver( Domlib::ICard* pCard )
{
    return Domlib::PearlDiverOpt::BOTTOM_OF_DRAWPILE;
}


Domlib::PirateShipOpt DefaultAI::OnPirateShip( void )
{
    return Domlib::PirateShipOpt::ATTACK;
}


Domlib::ICard* DefaultAI::OnPirateShipTrash( Domlib::ICardList cardList )
{
    if( cardList.size() )
    {
        return (*cardList.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnSalvager( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnSmugglers( Domlib::ICardList cardList )
{
    Domlib::IPlayerOther* pPlayerOther = m_pEngine->GetPreviousPlayer( m_pPlayer );
    Domlib::ICardList gainList = pPlayerOther->GainList();

    if( gainList.size() )
    {
        return (*gainList.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::TreasuryOpt DefaultAI::OnTreasury( void )
{
    return Domlib::TreasuryOpt::PUT_BACK;
}


Domlib::ICardList DefaultAI::OnWarehouse( void )
{
    Domlib::ICardList discardList;
    Domlib::ICardList hand = m_pPlayer->GetHand();

    for( Domlib::ICardListIter iter = hand.begin();
         iter != hand.end();
         iter++ )
    {
        discardList.push_back( *iter );
        if( discardList.size() == 3 )
        {
            break;
        }
    }
    
    return discardList;
}


Domlib::AlchemistOpt DefaultAI::OnAlchemist( void )
{
    return Domlib::AlchemistOpt::PUT_BACK;
}


Domlib::ICard* DefaultAI::OnApprentice( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICardList DefaultAI::OnGolem( Domlib::ICardList cardList )
{
    return cardList;
}


Domlib::ICard* DefaultAI::OnHerbalist( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ScryingPoolOpt DefaultAI::OnScryingPoolOther( Domlib::ICard* pCard )
{
    return Domlib::ScryingPoolOpt::DISCARD_CARD;
}


Domlib::ScryingPoolOpt DefaultAI::OnScryingPoolSelf( Domlib::ICard* pCard )
{
    return Domlib::ScryingPoolOpt::DISCARD_CARD;
}


Domlib::ICard* DefaultAI::OnTransmute( void )
{
    if( m_pPlayer->CardsInHand() )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        return (*hand.begin());
    }
    
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnUniversity( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}

 
Domlib::LoanOpt DefaultAI::OnLoan( Domlib::ICard* pCard )
{
    return Domlib::LoanOpt::DISCARD_CARD;
}


Domlib::ICard* DefaultAI::OnBishopSelf( void )
{
    Domlib::ICardList hand = m_pPlayer->GetHand();

    if( hand.size() )
    {
        return (*hand.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnBishopOther( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnContraband( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


int DefaultAI::OnCountingHouse( int numCoppersInDiscard )
{
    return numCoppersInDiscard;
}


Domlib::ICard* DefaultAI::OnExpand( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICardList DefaultAI::OnForge( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::ICardList DefaultAI::OnGoons( void )
{
    Domlib::ICardList discardList;
    int numCardsInHand = m_pPlayer->CardsInHand();

    if( numCardsInHand > 3 )
    {
        Domlib::ICardList hand = m_pPlayer->GetHand();
        
        for( Domlib::ICardListIter iter = hand.begin();
             iter != hand.end();
             iter++ )
        {
            discardList.push_back( *iter );
            if( numCardsInHand - discardList.size() <= 3 )
            {
                return discardList;
            }
        }
    }
    
    return discardList;
}


Domlib::ICard* DefaultAI::OnKingsCourt( void )
{
    Domlib::ICardList hand = m_pPlayer->GetHand();

    if( hand.size() )
    {
        return (*hand.begin());
    }

    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::ICard* DefaultAI::OnMint( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID::NULLCARD );
}


Domlib::MountebankOpt DefaultAI::OnMountebank( void )
{
    return Domlib::MountebankOpt::DISCARD_CURSE;
}


Domlib::RoyalSealOpt DefaultAI::OnRoyalSeal( Domlib::ICard* pCard )
{
    return Domlib::RoyalSealOpt::PUT_BACK_CARD;
}


Domlib::ICardList DefaultAI::OnVaultSelf( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}


Domlib::ICardList DefaultAI::OnVaultOther( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}