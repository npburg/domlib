#include "StdAfx.h"
#include "IAI.h"

namespace Domlib
{

IAI::IAI( AI* pAI ) 
{
    m_pAI = pAI;
}

IAI::~IAI( void ) 
{
}

Card* IAI::PlayAction( void )
{
    return m_pAI->PlayAction()->GetCard();
}

Card* IAI::PlayTreasure( void )
{
    return m_pAI->PlayTreasure()->GetCard();
}

Card* IAI::BuyCard( void )
{
    return m_pAI->BuyCard()->GetCard();
}

Card* IAI::OnAttack( Card* pAttackCard )
{
    return m_pAI->OnAttack( &ICard( pAttackCard ) )->GetCard();
}

Card* IAI::OnGainACard( const Treasure* cost )
{
    return m_pAI->OnGainACard( &ITreasure( *cost ) )->GetCard();
}

    
Card* IAI::OnGainACardExactly( const Treasure* cost )
{
    return m_pAI->OnGainACardExactly( &ITreasure( *cost ) )->GetCard();
}

CardList IAI::OnReturnToDrawPile( CardList cardList )
{
    return ICardListToCardList( 
                m_pAI->OnReturnToDrawPile( 
                CardListToICardList( cardList ) ) );
}

Card* IAI::OnTrashCardFromHand( void )
{
    return m_pAI->OnTrashCardFromHand()->GetCard();
}   

Card* IAI::OnBureaucrat( void )
{
    return m_pAI->OnBureaucrat()->GetCard();
}   


CardList IAI::OnCellar( void )
{
    return ICardListToCardList( m_pAI->OnCellar() );
}


ChancellorOpt IAI::OnChancellor( void )
{
    return m_pAI->OnChancellor();
}


CardList IAI::OnChapel( void )
{
    return ICardListToCardList( m_pAI->OnChapel() );
}


LibraryOpt IAI::OnLibrary( Card* pCard )
{
    return m_pAI->OnLibrary( &ICard( pCard ) );
}

CardList IAI::OnMilitia( void )
{
    return ICardListToCardList( m_pAI->OnMilitia() );
}

Card* IAI::OnMineTrash( void )
{
    return m_pAI->OnMineTrash()->GetCard();
}

Card* IAI::OnMineGain( const Treasure* cost )
{
    return m_pAI->OnMineGain( &ITreasure( *cost ) )->GetCard();
}

Card* IAI::OnRemodel( void )
{
    return m_pAI->OnRemodel()->GetCard();
}

SpyOpt IAI::OnSpyOther( Card* pCard )
{
    return m_pAI->OnSpyOther( &ICard( pCard ) );
}

SpyOpt IAI::OnSpySelf( Card* pCard )
{
    return m_pAI->OnSpySelf( &ICard( pCard ) );
}

ThiefOpt IAI::OnThiefGain( Card* pCard )
{
    return m_pAI->OnThiefGain( &ICard( pCard ) );
}

Card* IAI::OnThiefTrash( CardList cardList )
{
    return m_pAI->OnThiefTrash( CardListToICardList( cardList ) )->GetCard();
}

Card* IAI::OnThroneRoom( void )
{
    return m_pAI->OnThroneRoom( void )->GetCard();
}

BaronOpt IAI::OnBaron( void )
{
    return m_pAI->OnBaron();
}

Card* IAI::OnCourtyard( void )
{
    return m_pAI->OnCourtyard()->GetCard();
}

Card* IAI::OnIronworks( const Treasure* cost )
{
    return m_pAI->OnIronworks( &ITreasure( *cost ) )->GetCard();
}

Card* IAI::OnMasqueradePass( void )
{
    return m_pAI->OnMasqueradePass()->GetCard();
}

Card* IAI::OnMasqueradeTrash( void )
{
    return m_pAI->OnMasqueradeTrash()->GetCard();
}

MiningVillageOpt IAI::OnMiningVillage( void )
{
    return m_pAI->OnMiningVillage();
}

MinionOpt IAI::OnMinion( void )
{
    return m_pAI->OnMinion();
}

NoblesOpt IAI::OnNobles( void )
{
    return m_pAI->OnNobles();
}

PawnOptPair IAI::OnPawn( void )
{
    return m_pAI->OnPawn();
}

CardList IAI::OnSecretChamber( void )
{
    return ICardListToCardList( m_pAI->OnSecretChamber() );
}

CardList IAI::OnSecretChamberReaction( void )
{
    return ICardListToCardList( m_pAI->OnSecretChamberReaction() );
}

StewardOpt IAI::OnSteward( void )
{
    return m_pAI->OnSteward();
}

CardList IAI::OnStewardTrash( void )
{
    return ICardListToCardList( m_pAI->OnStewardTrash() );
}

Card* IAI::OnSwindler( Card* pCard )
{
    return m_pAI->OnSwindler( &ICard( pCard ) )->GetCard();
}

CardList IAI::OnTorturer( void )
{
    return ICardListToCardList( m_pAI->OnTorturer() );
}

CardList IAI::OnTradingPost( void )
{
    return ICardListToCardList( m_pAI->OnTradingPost() );
}

Card* IAI::OnUpgrade( void )
{
    return m_pAI->OnUpgrade()->GetCard();
}

Card* IAI::OnWishingWell( void )
{
    return m_pAI->OnWishingWell()->GetCard();
}

Card* IAI::OnAmbassadorReveal( void )
{
    return m_pAI->OnAmbassadorReveal()->GetCard();
}

int IAI::OnAmbassadorPutBack( Card* pCard )
{
    return m_pAI->OnAmbassadorPutBack( &ICard( pCard ) );
}

Card* IAI::OnEmbargo( void )
{
    return m_pAI->OnEmbargo()->GetCard();
}

ExplorerOpt IAI::OnExplorer( void )
{
    return m_pAI->OnExplorer();
}

CardList IAI::OnGhostShip( void )
{
    return ICardListToCardList( m_pAI->OnGhostShip() );
}

Card* IAI::OnHaven( void )
{
    return m_pAI->OnHaven()->GetCard();
}

Card* IAI::OnIsland( void )
{
    return m_pAI->OnIsland()->GetCard();
}

LookoutStruct IAI::OnLookout( CardList cardList )
{
    LookoutStruct lookoutStruct;
    ILookoutStruct iLookoutStruct = m_pAI->OnLookout( CardListToICardList( cardList ) );
    
    lookoutStruct.pCardToDiscard    = iLookoutStruct.pCardToDiscard->GetCard();
    lookoutStruct.PCardToPutBack    = iLookoutStruct.PCardToPutBack->GetCard();
    lookoutStruct.pCardToTrash      = iLookoutStruct.pCardToTrash->GetCard();
    
    return lookoutStruct;
}

NativeVillageOpt IAI::OnNativeVillage( void )
{
    return m_pAI->OnNativeVillage();
}

CardList IAI::OnNavigator( CardList cardList )
{
    return ICardListToCardList( 
                m_pAI->OnNavigator( 
                CardListToICardList( cardList ) ) );
}

PearlDiverOpt IAI::OnPearlDiver( Card* pCard )
{
    return m_pAI->OnPearlDiver( &ICard( pCard ) );
}

PirateShipOpt IAI::OnPirateShip( void )
{
    return m_pAI->OnPirateShip();
}

Card* IAI::OnPirateShipTrash( CardList cardList )
{
    return m_pAI->OnPirateShipTrash( CardListToICardList( cardList ) )->GetCard();
}

Card* IAI::OnSalvager( void )
{
    return m_pAI->OnSalvager()->GetCard();
}

Card* IAI::OnSmugglers( CardList cardList )
{
    return m_pAI->OnSmugglers( CardListToICardList( cardList ) )->GetCard();
}

TreasuryOpt IAI::OnTreasury( void )
{
    return m_pAI->OnTreasury();
}

CardList IAI::OnWarehouse( void )
{
    return ICardListToCardList( m_pAI->OnWarehouse() );
}

AlchemistOpt IAI::OnAlchemist( void )
{
    return m_pAI->OnAlchemist();
}

Card* IAI::OnApprentice( void )
{
    return m_pAI->OnApprentice()->GetCard();
}

CardList IAI::OnGolem( CardList cardList )
{
    return ICardListToCardList( 
                m_pAI->OnGolem( 
                CardListToICardList( cardList ) ) );
}

Card* IAI::OnHerbalist( void )
{
    return m_pAI->OnHerbalist()->GetCard();
}

ScryingPoolOpt IAI::OnScryingPoolOther( Card* pCard )
{
    return m_pAI->OnScryingPoolOther( &ICard( pCard ) );
}

ScryingPoolOpt IAI::OnScryingPoolSelf( Card* pCard )
{
    return m_pAI->OnScryingPoolSelf( &ICard( pCard ) );
}

Card* IAI::OnTransmute( void )
{
    return m_pAI->OnTransmute()->GetCard();
}

Card* IAI::OnUniversity( void )
{
    return m_pAI->OnUniversity()->GetCard();
}

LoanOpt IAI::OnLoan( Card* pCard )
{
    return m_pAI->OnLoan( &ICard( pCard ) );
}

Card* IAI::OnBishopSelf( void )
{
    return m_pAI->OnBishopSelf()->GetCard();
}

Card* IAI::OnBishopOther( void )
{
    return m_pAI->OnBishopOther()->GetCard();
}

Card* IAI::OnContraband( void )
{
    return m_pAI->OnContraband()->GetCard();
}

int IAI::OnCountingHouse( int numCoppersInDiscard )
{
    return m_pAI->OnCountingHouse( numCoppersInDiscard );
}

Card* IAI::OnExpand( void )
{
    return m_pAI->OnExpand()->GetCard();
}

CardList IAI::OnForge( void )
{
    return ICardListToCardList( m_pAI->OnForge() );
}

CardList IAI::OnGoons( void )
{
    return ICardListToCardList( m_pAI->OnGoons() );
}

Card* IAI::OnKingsCourt( void )
{
    return m_pAI->OnKingsCourt()->GetCard();
}

Card* IAI::OnMint( void )
{
    return m_pAI->OnMint()->GetCard();
}

MountebankOpt IAI::OnMountebank( void )
{
    return m_pAI->OnMountebank();
}

RoyalSealOpt IAI::OnRoyalSeal( Card* pCard )
{
    return m_pAI->OnRoyalSeal( &ICard( pCard ) );
}

CardList IAI::OnVaultSelf( void )
{
    return ICardListToCardList( m_pAI->OnVaultSelf() );
}

CardList IAI::OnVaultOther( void )
{
    return ICardListToCardList( m_pAI->OnVaultOther() );
}


} // namespace Domlib