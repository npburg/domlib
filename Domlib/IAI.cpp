#include "StdAfx.h"
#include "IAI.h"

namespace Domlib
{

IAI::IAI( AI* pAi ) 
{
    m_pAi = pAi;
}

IAI::~IAI( void ) 
{
}

Card* IAI::PlayAction( void )
{
    return m_pAi->PlayAction()->GetCard();
}

Card* IAI::PlayTreasure( void )
{
    return m_pAi->PlayTreasure()->GetCard();
}

Card* IAI::BuyCard( void )
{
    return m_pAi->BuyCard()->GetCard();
}

Card* IAI::OnAttack( Card* pAttackCard )
{
    return m_pAi->OnAttack( &ICard( pAttackCard ) )->GetCard();
}

Card* IAI::OnGainACard( const Treasure* cost )
{
    return m_pAi->OnGainACard( &ITreasure( *cost ) )->GetCard();
}

    
Card* IAI::OnGainACardExactly( const Treasure* cost )
{
    return m_pAi->OnGainACardExactly( &ITreasure( *cost ) )->GetCard();
}

CardList IAI::OnReturnToDrawPile( CardList cardList )
{
    return ICardListToCardList( 
                m_pAi->OnReturnToDrawPile( 
                CardListToICardList( cardList ) ) );
}

Card* IAI::OnTrashCardFromHand( void )
{
    return m_pAi->OnTrashCardFromHand()->GetCard();
}   

Card* IAI::OnBureaucrat( void )
{
    return m_pAi->OnBureaucrat()->GetCard();
}   


CardList IAI::OnCellar( void )
{
    return ICardListToCardList( m_pAi->OnCellar() );
}


ChancellorOpt IAI::OnChancellor( void )
{
    return m_pAi->OnChancellor();
}


CardList IAI::OnChapel( void )
{
    return ICardListToCardList( m_pAi->OnChapel() );
}


LibraryOpt IAI::OnLibrary( Card* pCard )
{
    return m_pAi->OnLibrary( &ICard( pCard ) );
}

CardList IAI::OnMilitia( void )
{
    return ICardListToCardList( m_pAi->OnMilitia() );
}

Card* IAI::OnMineTrash( void )
{
    return m_pAi->OnMineTrash()->GetCard();
}

Card* IAI::OnMineGain( const Treasure* cost )
{
    return m_pAi->OnMineGain( &ITreasure( *cost ) )->GetCard();
}

Card* IAI::OnRemodel( void )
{
    return m_pAi->OnRemodel()->GetCard();
}

SpyOpt IAI::OnSpyOther( Card* pCard )
{
    return m_pAi->OnSpyOther( &ICard( pCard ) );
}

SpyOpt IAI::OnSpySelf( Card* pCard )
{
    return m_pAi->OnSpySelf( &ICard( pCard ) );
}

ThiefOpt IAI::OnThiefGain( Card* pCard )
{
    return m_pAi->OnThiefGain( &ICard( pCard ) );
}

Card* IAI::OnThiefTrash( CardList cardList )
{
    return m_pAi->OnThiefTrash( CardListToICardList( cardList ) )->GetCard();
}

BaronOpt IAI::OnBaron( void )
{
    return m_pAi->OnBaron();
}

Card* IAI::OnCourtyard( void )
{
    return m_pAi->OnCourtyard()->GetCard();
}

Card* IAI::OnIronworks( const Treasure* cost )
{
    return m_pAi->OnIronworks( &ITreasure( *cost ) )->GetCard();
}

Card* IAI::OnMasqueradePass( void )
{
    return m_pAi->OnMasqueradePass()->GetCard();
}

Card* IAI::OnMasqueradeTrash( void )
{
    return m_pAi->OnMasqueradeTrash()->GetCard();
}

MiningVillageOpt IAI::OnMiningVillage( void )
{
    return m_pAi->OnMiningVillage();
}

MinionOpt IAI::OnMinion( void )
{
    return m_pAi->OnMinion();
}

NoblesOpt IAI::OnNobles( void )
{
    return m_pAi->OnNobles();
}

PawnOptPair IAI::OnPawn( void )
{
    return m_pAi->OnPawn();
}

CardList IAI::OnSecretChamber( void )
{
    return ICardListToCardList( m_pAi->OnSecretChamber() );
}

CardList IAI::OnSecretChamberReaction( void )
{
    return ICardListToCardList( m_pAi->OnSecretChamberReaction() );
}

StewardOpt IAI::OnSteward( void )
{
    return m_pAi->OnSteward();
}

CardList IAI::OnStewardTrash( void )
{
    return ICardListToCardList( m_pAi->OnStewardTrash() );
}

Card* IAI::OnSwindler( Card* pCard )
{
    return m_pAi->OnSwindler( &ICard( pCard ) )->GetCard();
}

CardList IAI::OnTorturer( void )
{
    return ICardListToCardList( m_pAi->OnTorturer() );
}

CardList IAI::OnTradingPost( void )
{
    return ICardListToCardList( m_pAi->OnTradingPost() );
}

Card* IAI::OnUpgrade( void )
{
    return m_pAi->OnUpgrade()->GetCard();
}

Card* IAI::OnWishingWell( void )
{
    return m_pAi->OnWishingWell()->GetCard();
}

CardList IAI::OnAmbassador( void )
{
    return ICardListToCardList( m_pAi->OnAmbassador() );
}

Card* IAI::OnEmbargo( void )
{
    return m_pAi->OnEmbargo()->GetCard();
}

ExplorerOpt IAI::OnExplorer( void )
{
    return m_pAi->OnExplorer();
}

Card* IAI::OnHaven( void )
{
    return m_pAi->OnHaven()->GetCard();
}

Card* IAI::OnIsland( void )
{
    return m_pAi->OnIsland()->GetCard();
}

LookoutStruct IAI::OnLookout( CardList cardList )
{
    return m_pAi->OnLookout( CardListToICardList( cardList ) );
}

NativeVillageOpt IAI::OnNativeVillage( void )
{
    return m_pAi->OnNativeVillage();
}

CardList IAI::OnNavigator( CardList cardList )
{
    return ICardListToCardList( 
                m_pAi->OnNavigator( 
                CardListToICardList( cardList ) ) );
}

PearlDiverOpt IAI::OnPearlDiver( void )
{
    return m_pAi->OnPearlDiver();
}

PirateShipOpt IAI::OnPirateShip( void )
{
    return m_pAi->OnPirateShip();
}

Card* IAI::OnSalvager( void )
{
    return m_pAi->OnSalvager()->GetCard();
}

Card* IAI::OnSmugglers( CardList cardList )
{
    return m_pAi->OnSmugglers( CardListToICardList( cardList ) )->GetCard();
}

TreasuryOpt IAI::OnTreasury( void )
{
    return m_pAi->OnTreasury();
}

CardList IAI::OnWarehouse( void )
{
    return ICardListToCardList( m_pAi->OnWarehouse() );
}

AlchemistOpt IAI::OnAlchemist( void )
{
    return m_pAi->OnAlchemist();
}

Card* IAI::OnApprentice( void )
{
    return m_pAi->OnApprentice()->GetCard();
}

CardList IAI::OnGolem( CardList cardList )
{
    return ICardListToCardList( 
                m_pAi->OnGolem( 
                CardListToICardList( cardList ) ) );
}

Card* IAI::OnHerbalist( void )
{
    return m_pAi->OnHerbalist()->GetCard();
}

ScryingPoolOpt IAI::OnScryingPoolOther( Card* pCard )
{
    return m_pAi->OnScryingPoolOther( &ICard( pCard ) );
}

ScryingPoolOpt IAI::OnScryingPoolSelf( Card* pCard )
{
    return m_pAi->OnScryingPoolSelf( &ICard( pCard ) );
}

Card* IAI::OnTransmute( void )
{
    return m_pAi->OnTransmute()->GetCard();
}

Card* IAI::OnUniversity( void )
{
    return m_pAi->OnUniversity()->GetCard();
}

LoanOpt IAI::OnLoan( Card* pCard )
{
    return m_pAi->OnLoan( &ICard( pCard ) );
}

Card* IAI::OnBiship( void )
{
    return m_pAi->OnBiship()->GetCard();
}

Card* IAI::OnContraband( void )
{
    return m_pAi->OnContraband()->GetCard();
}

int IAI::OnCountingHouse( CardList cardList )
{
    return m_pAi->OnCountingHouse( CardListToICardList( cardList ) );
}

Card* IAI::OnExpand( void )
{
    return m_pAi->OnExpand()->GetCard();
}

CardList IAI::OnForge( void )
{
    return ICardListToCardList( m_pAi->OnForge() );
}

CardList IAI::OnGoons( void )
{
    return ICardListToCardList( m_pAi->OnGoons() );
}

Card* IAI::OnKingsCourt( void )
{
    return m_pAi->OnKingsCourt()->GetCard();
}

Card* IAI::OnMint( void )
{
    return m_pAi->OnMint()->GetCard();
}

MountebankOpt IAI::OnMountebank( void )
{
    return m_pAi->OnMountebank();
}

RoyalSealOpt IAI::OnRoyalSeal( Card* pCard )
{
    return m_pAi->OnRoyalSeal( &ICard( pCard ) );
}

CardList IAI::OnVaultSelf( void )
{
    return ICardListToCardList( m_pAi->OnVaultSelf() );
}

CardList IAI::OnValueOther( void )
{
    return ICardListToCardList( m_pAi->OnValueOther() );
}


} // namespace Domlib