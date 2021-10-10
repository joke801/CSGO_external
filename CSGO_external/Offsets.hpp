#pragma once
#include "CommonIncludes.hpp"
#include "Memory.hpp"

struct offsets {

    struct sdk {
        MODULEENTRY32 iClientBaseAddress = { 0 };
        MODULEENTRY32 iEngineBaseAddress = { 0 };
    };
    sdk SDK;

    struct nVars {
        DWORD m_fFlags = 0x104;
        DWORD m_iHealth = 0x100;
        DWORD m_iTeamNum = 0xF4;

        DWORD m_aimPunchAngle = 0x302C;
        DWORD dwClientState_ViewAngles = 0x4D90;

        DWORD m_iGlowIndex = 0x10488;
        DWORD m_bIsDefusing = 0x997C;
        DWORD m_bHasDefuser = 0x113DC;

        DWORD m_bSpottedByMask = 0x980;
        DWORD m_iShotsFired = 0x103E0;
        DWORD m_hActiveWeapon = 0x2F08;
        DWORD m_hMyWeapons = 0x2E08;
        DWORD m_flFallbackWear = 0x31E0;
        DWORD m_nFallbackPaintKit = 0x31D8;
        DWORD m_nFallbackSeed = 0x31DC;
        DWORD m_nFallbackStatTrak = 0x31E4;
        DWORD m_iItemDefinitionIndex = 0x2FBA;
        DWORD m_iAccountID = 0x2FD8;
        DWORD m_OriginalOwnerXuidLow = 0x31D0;
        DWORD m_OriginalOwnerXuidHigh = 0x31D4;
        DWORD m_iItemIDHigh = 0x2FD0;
        DWORD m_iCrosshairId = 0x11438;
        DWORD m_bSpotted = 0x93D;
        DWORD m_clrRender = 0x70;
        DWORD m_flFlashMaxAlpha = 0x1046C;

        DWORD m_flSimulationTime = 0x268;
        DWORD m_dwBoneMatrix = 0x26A8;
        DWORD m_vecOrigin = 0x138;
        DWORD m_vecViewOffset = 0x108;
        DWORD m_nSurvivalTeam = 0xA3B0;
        DWORD m_iClip1 = 0x3274;
        DWORD m_bFreezePeriod = 0x20;
        DWORD  m_fAccuracyPenalty = 0x3340;


        DWORD m_bGunGameImmunity = 0x9990;
        DWORD m_vecVelocity = 0x114;

        DWORD m_SurvivalGameRuleDecisionTypes = 0x1328;//DANGERZONE CHECK

    };
    nVars NVARS;

    struct Sigs {
        DWORD dwForceJump = NULL;
        DWORD dwLocalPlayer = NULL;
        DWORD dwEntityList = NULL;
        DWORD dwGlowObjectManager = NULL;
        DWORD m_bDormant = NULL;
        DWORD dwClientState = NULL;
        DWORD dwForceAttack = NULL;

        DWORD dwbSendPackets = NULL;
        DWORD dwGlobalVars = NULL;
        DWORD clientstate_last_outgoing_command = NULL;
        DWORD dwInput = NULL;
        DWORD dwClientState_ViewAngles = NULL;
        DWORD dwClientState_PlayerInfo = NULL;
        DWORD dwViewMatrix = NULL;
        DWORD dwGameRulesProxy = NULL;

        DWORD dwMouseEnable = NULL;

    };
    Sigs SIGS ;

    bool bSetOffsets();

    enum ItemSchemaIndex_e
    {
        ITEM_NONE = 0,
        WEAPON_DEAGLE = 1,
        WEAPON_DUALS = 2,
        WEAPON_FIVE7 = 3,
        WEAPON_GLOCK = 4,
        WEAPON_AK47 = 7,
        WEAPON_AUG = 8,
        WEAPON_AWP = 9,
        WEAPON_FAMAS = 10,
        WEAPON_G3SG1 = 11,
        WEAPON_GALIL = 13,
        WEAPON_M249 = 14,
        WEAPON_M4A4 = 16,
        WEAPON_MAC10 = 17,
        WEAPON_P90 = 19,
        WEAPON_MP5SD = 23,
        WEAPON_UMP45 = 24,
        WEAPON_XM1014 = 25,
        WEAPON_BIZON = 26,
        WEAPON_MAG7 = 27,
        WEAPON_NEGEV = 28,
        WEAPON_SAWEDOFF = 29,
        WEAPON_TEC9 = 30,
        WEAPON_TASER = 31,
        WEAPON_P2000 = 32,
        WEAPON_MP7 = 33,
        WEAPON_MP9 = 34,
        WEAPON_NOVA = 35,
        WEAPON_P250 = 36,
        WEAPON_SCAR20 = 38,
        WEAPON_SG553 = 39,
        WEAPON_SCOUT = 40,
        WEAPON_KNIFE_T = 42,
        WEAPON_FLASH = 43,
        WEAPON_HE = 44,
        WEAPON_SMOKE = 45,
        WEAPON_MOLOTOV = 46,
        WEAPON_DECOY = 47,
        WEAPON_INC = 48,
        WEAPON_C4 = 49,
        WEAPON_KNIFE_CT = 59,
        WEAPON_M4A1S = 60,
        WEAPON_USPS = 61,
        WEAPON_CZ75 = 63,
        WEAPON_R8REVOLVER = 64,
        WEAPON_MAX = 65,
        WEAPON_KNIFE_BAYONET = 500,         // 0
        WEAPON_KNIFE_FLIP = 505,            // 1
        WEAPON_KNIFE_GUT = 506,             // 2
        WEAPON_KNIFE_KARAMBIT = 507,        // 3
        WEAPON_KNIFE_M9_BAYONET = 508,      // 4
        WEAPON_KNIFE_TACTICAL = 509,        // 5
        WEAPON_KNIFE_FALCHION = 512,        // 6
        WEAPON_KNIFE_SURVIVAL_BOWIE = 514,  // 7
        WEAPON_KNIFE_BUTTERFLY = 515,       // 8
        WEAPON_KNIFE_PUSH = 516,            // 9
        WEAPON_KNIFE_URSUS = 519,           // 10
        WEAPON_KNIFE_GYPSY_JACKKNIFE = 520, // 11
        WEAPON_KNIFE_STILETTO = 522,        // 12
        WEAPON_KNIFE_WIDOWMAKER = 523       // 13
    };

enum ClassIDs {
    CAI_BaseNPC,
    CAK47,
    CBaseAnimating,
    CBaseAnimatingOverlay,
    CBaseAttributableItem,
    CBaseButton,
    CBaseCombatCharacter,
    CBaseCombatWeapon,
    CBaseCSGrenade,
    CBaseCSGrenadeProjectile,
    CBaseDoor,
    CBaseEntity,
    CBaseFlex,
    CBaseGrenade,
    CBaseParticleEntity,
    CBasePlayer,
    CBasePropDoor,
    CBaseTeamObjectiveResource,
    CBaseTempEntity,
    CBaseToggle,
    CBaseTrigger,
    CBaseViewModel,
    CBaseVPhysicsTrigger,
    CBaseWeaponWorldModel,
    CBeam,
    CBeamSpotlight,
    CBoneFollower,
    CBRC4Target,
    CBreachCharge,
    CBreachChargeProjectile,
    CBreakableProp,
    CBreakableSurface,
    CBumpMine,
    CBumpMineProjectile,
    CC4,
    CCascadeLight,
    CChicken,
    CColorCorrection,
    CColorCorrectionVolume,
    CCSGameRulesProxy,
    CCSPlayer,
    CCSPlayerResource,
    CCSRagdoll,
    CCSTeam,
    CDangerZone,
    CDangerZoneController,
    CDEagle,
    CDecoyGrenade,
    CDecoyProjectile,
    CDrone,
    CDronegun,
    CDynamicLight,
    CDynamicProp,
    CEconEntity,
    CEconWearable,
    CEmbers,
    CEntityDissolve,
    CEntityFlame,
    CEntityFreezing,
    CEntityParticleTrail,
    CEnvAmbientLight,
    CEnvDetailController,
    CEnvDOFController,
    CEnvGasCanister,
    CEnvParticleScript,
    CEnvProjectedTexture,
    CEnvQuadraticBeam,
    CEnvScreenEffect,
    CEnvScreenOverlay,
    CEnvTonemapController,
    CEnvWind,
    CFEPlayerDecal,
    CFireCrackerBlast,
    CFireSmoke,
    CFireTrail,
    CFish,
    CFists,
    CFlashbang,
    CFogController,
    CFootstepControl,
    CFunc_Dust,
    CFunc_LOD,
    CFuncAreaPortalWindow,
    CFuncBrush,
    CFuncConveyor,
    CFuncLadder,
    CFuncMonitor,
    CFuncMoveLinear,
    CFuncOccluder,
    CFuncReflectiveGlass,
    CFuncRotating,
    CFuncSmokeVolume,
    CFuncTrackTrain,
    CGameRulesProxy,
    CGrassBurn,
    CHandleTest,
    CHEGrenade,
    CHostage,
    CHostageCarriableProp,
    CIncendiaryGrenade,
    CInferno,
    CInfoLadderDismount,
    CInfoMapRegion,
    CInfoOverlayAccessor,
    CItem_Healthshot,
    CItemCash,
    CItemDogtags,
    CKnife,
    CKnifeGG,
    CLightGlow,
    CMapVetoPickController,
    CMaterialModifyControl,
    CMelee,
    CMolotovGrenade,
    CMolotovProjectile,
    CMovieDisplay,
    CParadropChopper,
    CParticleFire,
    CParticlePerformanceMonitor,
    CParticleSystem,
    CPhysBox,
    CPhysBoxMultiplayer,
    CPhysicsProp,
    CPhysicsPropMultiplayer,
    CPhysMagnet,
    CPhysPropAmmoBox,
    CPhysPropLootCrate,
    CPhysPropRadarJammer,
    CPhysPropWeaponUpgrade,
    CPlantedC4,
    CPlasma,
    CPlayerPing,
    CPlayerResource,
    CPointCamera,
    CPointCommentaryNode,
    CPointWorldText,
    CPoseController,
    CPostProcessController,
    CPrecipitation,
    CPrecipitationBlocker,
    CPredictedViewModel,
    CProp_Hallucination,
    CPropCounter,
    CPropDoorRotating,
    CPropJeep,
    CPropVehicleDriveable,
    CRagdollManager,
    CRagdollProp,
    CRagdollPropAttached,
    CRopeKeyframe,
    CSCAR17,
    CSceneEntity,
    CSensorGrenade,
    CSensorGrenadeProjectile,
    CShadowControl,
    CSlideshowDisplay,
    CSmokeGrenade,
    CSmokeGrenadeProjectile,
    CSmokeStack,
    CSnowball,
    CSnowballPile,
    CSnowballProjectile,
    CSpatialEntity,
    CSpotlightEnd,
    CSprite,
    CSpriteOriented,
    CSpriteTrail,
    CStatueProp,
    CSteamJet,
    CSun,
    CSunlightShadowControl,
    CSurvivalSpawnChopper,
    CTablet,
    CTeam,
    CTeamplayRoundBasedRulesProxy,
    CTEArmorRicochet,
    CTEBaseBeam,
    CTEBeamEntPoint,
    CTEBeamEnts,
    CTEBeamFollow,
    CTEBeamLaser,
    CTEBeamPoints,
    CTEBeamRing,
    CTEBeamRingPoint,
    CTEBeamSpline,
    CTEBloodSprite,
    CTEBloodStream,
    CTEBreakModel,
    CTEBSPDecal,
    CTEBubbles,
    CTEBubbleTrail,
    CTEClientProjectile,
    CTEDecal,
    CTEDust,
    CTEDynamicLight,
    CTEEffectDispatch,
    CTEEnergySplash,
    CTEExplosion,
    CTEFireBullets,
    CTEFizz,
    CTEFootprintDecal,
    CTEFoundryHelpers,
    CTEGaussExplosion,
    CTEGlowSprite,
    CTEImpact,
    CTEKillPlayerAttachments,
    CTELargeFunnel,
    CTEMetalSparks,
    CTEMuzzleFlash,
    CTEParticleSystem,
    CTEPhysicsProp,
    CTEPlantBomb,
    CTEPlayerAnimEvent,
    CTEPlayerDecal,
    CTEProjectedDecal,
    CTERadioIcon,
    CTEShatterSurface,
    CTEShowLine,
    CTesla,
    CTESmoke,
    CTESparks,
    CTESprite,
    CTESpriteSpray,
    CTest_ProxyToggle_Networkable,
    CTestTraceline,
    CTEWorldDecal,
    CTriggerPlayerMovement,
    CTriggerSoundOperator,
    CVGuiScreen,
    CVoteController,
    CWaterBullet,
    CWaterLODControl,
    CWeaponAug,
    CWeaponAWP,
    CWeaponBaseItem,
    CWeaponBizon,
    CWeaponCSBase,
    CWeaponCSBaseGun,
    CWeaponCycler,
    CWeaponElite,
    CWeaponFamas,
    CWeaponFiveSeven,
    CWeaponG3SG1,
    CWeaponGalil,
    CWeaponGalilAR,
    CWeaponGlock,
    CWeaponHKP2000,
    CWeaponM249,
    CWeaponM3,
    CWeaponM4A1,
    CWeaponMAC10,
    CWeaponMag7,
    CWeaponMP5Navy,
    CWeaponMP7,
    CWeaponMP9,
    CWeaponNegev,
    CWeaponNOVA,
    CWeaponP228,
    CWeaponP250,
    CWeaponP90,
    CWeaponSawedoff,
    CWeaponSCAR20,
    CWeaponScout,
    CWeaponSG550,
    CWeaponSG552,
    CWeaponSG556,
    CWeaponShield,
    CWeaponSSG08,
    CWeaponTaser,
    CWeaponTec9,
    CWeaponTMP,
    CWeaponUMP45,
    CWeaponUSP,
    CWeaponXM1014,
    CWeaponZoneRepulsor,
    CWorld,
    CWorldVguiText,
    DustTrail,
    MovieExplosion,
    ParticleSmokeGrenade,
    RocketTrail,
    SmokeTrail,
    SporeExplosion,
    SporeTrail,
};

};
extern offsets Offsets;

