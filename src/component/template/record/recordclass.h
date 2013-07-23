//ClassName, BaseClass, Kind
//----------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
JTemplateClass(Abil, TemplateRecord, Abil)
JTemplateValue(NAME,              AbilSetId)
JTemplateValue(EAbilAlignment,    Alignment)
JTemplateValue(INT32,             InfoTooltipPriority)
JTemplateArray(SAbilOrderDisplay, OrderArray, UNKNOWN_SIZE)
JTemplateValue(NAME,              TargetMessage)
JTemplateArray(NAME,              TechAliasArray, UNKNOWN_SIZE)
JTemplateValue(EAbilTechPlayer,   TechPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilQueue, Abil, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilQueueCmd)
JTemplateValue(EAbilQueueFlag, Flags)
JTemplateValue(INT32,          QueueCount)
JTemplateValue(INT32,          QueueSize)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilQueueable, Abil, Abil)
JTemplateValue(NAME,        Activity)
JTemplateValue(TID,         ErrorAlert)
JTemplateValue(SCostFactor, RefundFraction)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilArmMagazine, AbilQueueable, Abil)
JTemplateValue(TID,                    Alert)
JTemplateValue(TID,                    CalldownEffect)
JTemplateEnumA(TID,                    EffectArray, EAbilArmMagazineEffects)
JTemplateArray(FIXF32,                 ExternalAngle, UNKNOWN_SIZE)
JTemplateValue(EAbilArmMagazineFlag,   Flags)
JTemplateEnumA(SAbilArmMagazineInfo,   InfoArray, EAbilArmMagazineCmd)
JTemplateValue(EAbilArmMagazineLaunch, Launch)
JTemplateValue(FIXF32,                 Leash)
JTemplateValue(FIXF32,                 ReturnLifeFraction)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilAttack, Abil, Abil)
JTemplateValue(STargetFilters, AcquireFilters)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilAttackCmd)
JTemplateValue(FIXF32,         MaxAttackSpeedMultiplier)
JTemplateValue(FIXF32,         MinAttackSpeedMultiplier)
JTemplateValue(STargetFilters, SmartFilters)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilAugment, Abil, Abil)
JTemplateValue(NAMEDICTIONARY, AbilCmd)
JTemplateValue(STargetFilters,      AutoCastFilters)
JTemplateArray(TID,                 AutoCastValidatorArray, UNKNOWN_SIZE)
JTemplateEnumA(SAbilCmdButton,      CmdButtonArray, EAbilAugmentCmd)
JTemplateValue(SCost,               Cost)
JTemplateValue(TID,                 Effect)
JTemplateValue(EAbilAugmentFlag,    Flags)
JTemplateValue(EEffectLocationType, TargetType)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilBattery, Abil, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilBatteryCmd)
JTemplateValue(TID,            Effect)
JTemplateValue(STargetFilters, EnumFilters)
JTemplateValue(FIXF32,         EnumRange)
JTemplateValue(FIXF32,         Range)
JTemplateValue(STargetFilters, TargetFilters)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilBeacon, Abil, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilBeaconCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilBehavior, Abil, Abil)
JTemplateArray(TID,               AutoCastValidatorArray, UNKNOWN_SIZE)
JTemplateArray(TID,               BehaviorArray, UNKNOWN_SIZE)
JTemplateEnumA(SAbilCmdButton,    CmdButtonArray, EAbilBehaviorCmd)
JTemplateValue(SCost,             Cost)
JTemplateValue(EAbilBehaviorFlag, Flags)
JTemplateArray(NAME,              LevelButtonOffImage, UNKNOWN_SIZE)
JTemplateArray(NAME,              LevelButtonOffName, UNKNOWN_SIZE)
JTemplateArray(NAME,              LevelButtonOffTooltip, UNKNOWN_SIZE)
JTemplateArray(NAME,              LevelButtonOnImage, UNKNOWN_SIZE)
JTemplateArray(NAME,              LevelButtonOnName, UNKNOWN_SIZE)
JTemplateArray(NAME,              LevelButtonOnTooltip, UNKNOWN_SIZE)
JTemplateArray(TID,               ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilBuild, Abil, Abil)
JTemplateValue(TID,            Alert)
JTemplateValue(TID,            BuildMorphAbil)
JTemplateValue(TID,            ConstructionMover)
JTemplateValue(TID,            ErrorAlert)
JTemplateValue(FIXF32,         FidgetDelayMax)
JTemplateValue(FIXF32,         FidgetDelayMin)
JTemplateValue(EAbilBuildFlag, FlagArray)
JTemplateValue(SAbilCmdButton, HaltCmdButton)
JTemplateEnumA(SAbilBuildInfo, InfoArray, EAbilBuildCmd)
JTemplateValue(FIXF32,         Range)
JTemplateValue(SCostFactor,    RefundFraction)
JTemplateValue(EAbilBuildType, Type)
JTemplateValue(TID,            UnlinkMorphAbil)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilProgress, Abil, Abil)
JTemplateValue(NAME,   Activity)
JTemplateValue(bool,   Cancelable)
JTemplateEnumA(FIXF32, VitalStartFactor, EUnitVital)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilBuildable, AbilProgress, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilBuildableCmd)
JTemplateValue(INT32,          MaxBuilders)
JTemplateValue(FIXF32,         PowerBuildBonusRate)
JTemplateValue(FIXF32,         PowerBuildCostFactor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilEffect, Abil, Abil)
JTemplateValue(NAME,             Activity)
JTemplateValue(TID,              AINotifyEffect)
JTemplateEnumA(TID,              AlertArray, EAbilEffectStage)
JTemplateValue(FIXF32,           Arc)
JTemplateValue(FIXF32,           ArcSlop)
JTemplateValue(EAcquireLevel,    AutoCastAcquireLevel)
JTemplateValue(STargetFilters,   AutoCastFilters)
JTemplateValue(FIXF32,           AutoCastRange)
JTemplateArray(TID,              AutoCastValidatorArray, UNKNOWN_SIZE)
JTemplateValue(TID,              CalldownEffect)
JTemplateValue(EAbilEffectStage, CancelableArray)
JTemplateArray(FIXF32,           CastIntroTime, UNKNOWN_SIZE)
JTemplateArray(FIXF32,           CastOutroTime, UNKNOWN_SIZE)
JTemplateArray(SCost,            Cost, UNKNOWN_SIZE)
JTemplateArray(TID,              CursorEffect, UNKNOWN_SIZE)
JTemplateValue(SError,           DefaultError)
JTemplateArray(TID,              Effect, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,     EffectRange)
JTemplateValue(TID,              ErrorAlert)
JTemplateArray(FIXF32,           FinishTime, UNKNOWN_SIZE)
JTemplateValue(EAbilEffectFlag,  Flags)
JTemplateValue(UNKNOWN_TYPE,     InheritAttackPriorityArray)
JTemplateArray(NAME,             LevelButtonImage, UNKNOWN_SIZE)
JTemplateArray(NAME,             LevelButtonName, UNKNOWN_SIZE)
JTemplateArray(NAME,             LevelButtonTooltip, UNKNOWN_SIZE)
JTemplateValue(SMarker,          Marker)
JTemplateValue(TID,              Placeholder)
JTemplateArray(FIXF32,           PrepTime, UNKNOWN_SIZE)
JTemplateArray(TID,              ProducedUnitArray, UNKNOWN_SIZE)
JTemplateEnumA(TID,              ProgressButtonArray, EAbilEffectStage)
JTemplateArray(FIXF32,           Range, UNKNOWN_SIZE)
JTemplateValue(FIXF32,           RangeSlop)
JTemplateValue(SCostFactor,      RefundFraction)
JTemplateValue(EAbilEffectStage, ShowProgressArray)
JTemplateArray(TID,              SmartValidatorArray, UNKNOWN_SIZE)
JTemplateValue(STargetFilters,   TargetFilters)
JTemplateValue(STargetSorts,     TargetSorts)
JTemplateValue(EAbilEffectStage, UninterruptibleArray)
JTemplateValue(EAbilEffectStage, UseMarkerArray)
JTemplateValue(EAbilEffectStage, ValidatedArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilEffectInstant, AbilEffect, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilEffectInstantCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilEffectTarget, AbilEffect, Abil)
JTemplateValue(bool,           AcquireAttackers)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilEffectTargetCmd)
JTemplateValue(FIXF32,         FollowRange)
JTemplateValue(TID,            PlaceUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilHarvest, Abil, Abil)
JTemplateValue(FIXF32,            AcquireRadius)
JTemplateValue(EAbilHarvestStage, CancelableArray)
JTemplateEnumA(SAbilCmdButton,    CmdButtonArray, EAbilHarvestCmd)
JTemplateValue(EAbilHarvestFlag,  FlagArray)
JTemplateValue(FIXF32,            Range)
JTemplateValue(SMarker,           ReservedMarker)
JTemplateValue(EResourceType,     ResourceAcquire)
JTemplateValue(EResourceType,     ResourceAllowed)
JTemplateEnumA(INT32,             ResourceAmountBonus, EResourceType)
JTemplateEnumA(FIXF32,            ResourceAmountMultiplier, EResourceType)
JTemplateValue(EResourceType,     ResourceDestroy)
JTemplateEnumA(FIXF32,            ResourceTimeBonus, EResourceType)
JTemplateEnumA(FIXF32,            ResourceTimeMultiplier, EResourceType)
JTemplateValue(EAbilHarvestStage, UninterruptibleArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilInteract, Abil, Abil)
JTemplateValue(STargetFilters,    AutoCastFilters)
JTemplateValue(FIXF32,            AutoCastRange)
JTemplateArray(TID,               AutoCastValidatorArray, UNKNOWN_SIZE)
JTemplateEnumA(SAbilCmdButton,    CmdButtonArray, EAbilInteractCmd)
JTemplateValue(EAbilInteractFlag, Flags)
JTemplateValue(FIXF32,            Range)
JTemplateArray(TID,               SmartValidatorArray, UNKNOWN_SIZE)
JTemplateValue(STargetFilters,    TargetFilters)
JTemplateArray(TID,               ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilInventory, Abil, Abil)
JTemplateEnumA(SAbilCmdButton,     CmdButtonArray, EAbilInventoryCmd)
JTemplateValue(EAbilInventoryFlag, Flags)
JTemplateArray(SAbilInventoryInfo, InfoArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,             MaxDropRange)
JTemplateValue(FIXF32,             Range)
JTemplateValue(STargetFilters,     TargetFilters)
JTemplateArray(TID,                ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilLearn, AbilQueueable, Abil)
JTemplateValue(EAbilLearnFlag, Flags)
JTemplateEnumA(SAbilLearnInfo, InfoArray, EAbilLearnCmd)
JTemplateValue(INT32,          Points)
JTemplateValue(INT32,          PointsPerLevel)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilMerge, Abil, Abil)
JTemplateValue(TID,            Alert)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilMergeCmd)
JTemplateValue(TID,            Effect)
JTemplateValue(EAbilMergeFlag, Flags)
JTemplateValue(SAbilMergeInfo, Info)
JTemplateValue(FIXF32,         Range)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilMergeable, AbilProgress, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilMergeableCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilMorph, Abil, Abil)
JTemplateValue(EClassIdCAbil,  AbilClassDisableArray)
JTemplateValue(EClassIdCAbil,  AbilClassEnableArray)
JTemplateValue(NAME,           Activity)
JTemplateValue(NAME,           ActorKey)
JTemplateValue(TID,            Alert)
JTemplateValue(EAcquireLevel,  AutoCastAcquireLevel)
JTemplateValue(INT32,          AutoCastCountMax)
JTemplateValue(INT32,          AutoCastCountMin)
JTemplateValue(STargetFilters, AutoCastFilters)
JTemplateValue(FIXF32,         AutoCastRange)
JTemplateArray(TID,            AutoCastValidatorArray, UNKNOWN_SIZE)
JTemplateValue(TID,            CancelUnit)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilMorphCmd)
JTemplateValue(SCost,          Cost)
JTemplateValue(TID,            ErrorAlert)
JTemplateValue(TID,            FinishGlobalAlert)
JTemplateValue(EAbilMorphFlag, Flags)
JTemplateArray(SAbilMorphInfo, InfoArray, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,   ProgressButton)
JTemplateValue(SCostFactor,    RefundFraction)
JTemplateValue(TID,            StartGlobalAlert)
JTemplateArray(TID,            ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilMorphPlacement, AbilMorph, Abil)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilMove, Abil, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilMoveCmd)
JTemplateValue(FIXF32,         FleeRange)
JTemplateValue(FIXF32,         FleeTime)
JTemplateValue(FIXF32,         FollowAcquireRange)
JTemplateValue(FIXF32,         FollowRangeSlop)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilPawn, Abil, Abil)
JTemplateValue(EAbilPawnFlag, Flags)
JTemplateEnumA(SAbilPawnInfo, InfoArray, EAbilPawnCmd)
JTemplateValue(FIXF32,        Range)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilRally, Abil, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilRallyCmd)
JTemplateValue(EAbilRallyFlag, Flags)
JTemplateEnumA(SAbilRallyInfo, InfoArray, EAbilRallyCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilRedirect, Abil, Abil)
JTemplateValue(TID,               Abil)
JTemplateValue(EAbilRedirectFlag, Flags)
JTemplateValue(INT32,             Index)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilRedirectInstant, AbilRedirect, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilRedirectInstantCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilRedirectTarget, AbilRedirect, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilRedirectTargetCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilResearch, AbilQueueable, Abil)
JTemplateValue(EAbilResearchFlag, Flags)
JTemplateEnumA(SAbilResearchInfo, InfoArray, EAbilResearchCmd)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilRevive, AbilQueueable, Abil)
JTemplateValue(NAME,             ActorKey)
JTemplateValue(TID,              Alert)
JTemplateValue(SAbilReviveInfo,  BaseInfo)
JTemplateValue(SCostFactor,      BaseUnitCostFactor)
JTemplateEnumA(SAbilCmdButton,   CmdButtonArray, EAbilReviveCmd)
JTemplateValue(TID,              Effect)
JTemplateValue(EAbilReviveFlag,  Flags)
JTemplateValue(SAbilReviveInfo,  LevelInfo)
JTemplateValue(SCostFactor,      LevelUnitCostFactor)
JTemplateValue(NAME,             NameOverride)
JTemplateValue(FIXF32,           Range)
JTemplateEnumA(EAbilReviveVital, VitalArray, EVitalType)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilSpecialize, AbilQueueable, Abil)
JTemplateValue(TID,                 Alert)
JTemplateValue(EAbilSpecializeFlag, Flags)
JTemplateEnumA(SAbilSpecializeInfo, InfoArray, EAbilSpecializeCmd)
JTemplateValue(INT32,               MaxCount)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilStop, Abil, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilStopCmd)
JTemplateValue(EAbilStopFlag,  Flags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilTrain, AbilQueueable, Abil)
JTemplateValue(NAME,           ActorKey)
JTemplateValue(TID,            Alert)
JTemplateValue(EAbilTrainFlag, Flags)
JTemplateEnumA(SAbilTrainInfo, InfoArray, EAbilTrainCmd)
JTemplateValue(TID,            MorphUnit)
JTemplateArray(SVector2,       Offset, UNKNOWN_SIZE)
JTemplateValue(FIXF32,         Range)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilTransport, Abil, Abil)
JTemplateValue(TID,                CalldownEffect)
JTemplateEnumA(SAbilCmdButton,     CmdButtonArray, EAbilTransportCmd)
JTemplateValue(TID,                DeathUnloadEffect)
JTemplateValue(TID,                ErrorAlert)
JTemplateValue(EAbilTransportFlag, Flags)
JTemplateValue(FIXF32,             InitialLoadDelay)
JTemplateValue(FIXF32,             InitialUnloadDelay)
JTemplateValue(TID,                LoadCargoBehavior)
JTemplateValue(FIXF32,             LoadPeriod)
JTemplateValue(TID,                LoadTransportBehavior)
JTemplateArray(TID,                LoadValidatorArray, UNKNOWN_SIZE)
JTemplateValue(INT32,              MaxCargoCount)
JTemplateValue(INT32,              MaxCargoSize)
JTemplateValue(FIXF32,             MaxUnloadRange)
JTemplateValue(FIXF32,             Range)
JTemplateValue(FIXF32,             SearchRadius)
JTemplateValue(STargetFilters,     TargetFilters)
JTemplateValue(STargetSorts,       TargetSorts)
JTemplateValue(INT32,              TotalCargoSpace)
JTemplateValue(TID,                UnloadCargoBehavior)
JTemplateValue(FIXF32,             UnloadPeriod)
JTemplateValue(TID,                UnloadTransportBehavior)
JTemplateArray(TID,                UnloadValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilWarpable, AbilProgress, Abil)
JTemplateEnumA(SAbilCmdButton, CmdButtonArray, EAbilWarpableCmd)
JTemplateValue(TID,            PowerUserBehavior)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AbilWarpTrain, Abil, Abil)
JTemplateValue(TID,                Alert)
JTemplateValue(EAbilWarpTrainFlag, Flags)
JTemplateEnumA(SAbilWarpTrainInfo, InfoArray, EAbilWarpTrainCmd)
JTemplateValue(SCostFactor,        RefundFraction)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Achievement, TemplateRecord, Achievement)
JTemplateValue(NAME,               Category)
JTemplateValue(NAME,               Description)
JTemplateValue(EAchievementFilter, Filters)
JTemplateValue(EAchievementFlag,   Flags)
JTemplateValue(TID,                Icon)
JTemplateValue(INT32,              MinTermCount)
JTemplateValue(INT32,              Points)
JTemplateValue(TID,                Race)
JTemplateArray(TID,                RewardTable, UNKNOWN_SIZE)
JTemplateValue(TID,                Supersedes)
JTemplateValue(UNKNOWN_TYPE,       Tags)
JTemplateArray(TID,                TermTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTerm, TemplateRecord, Achievement)
JTemplateValue(EValueCompare,            Compare)
JTemplateValue(NAME,                     Description)
JTemplateValue(EAchievementTermEvaluate, Evaluate)
JTemplateValue(EAchievementTermFlag,     Flags)
JTemplateValue(INT32,                    Quantity)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermAbil, AchievementTerm, Achievement)
JTemplateValue(NAMEDICTIONARY,      AbilCmd)
JTemplateArray(TID,                ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermAbilInteract, AchievementTermAbil, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermAbilLoad, AchievementTermAbil, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermAbilUse, AchievementTermAbil, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermAchievement, AchievementTerm, Achievement)
JTemplateValue(TID, Child)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermBehavior, AchievementTerm, Achievement)
JTemplateValue(TID, Behavior)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermBehaviorCount, AchievementTermBehavior, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermBehaviorState, AchievementTermBehavior, Achievement)
JTemplateValue(bool, State)
JTemplateArray(TID,  ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermCombine, AchievementTerm, Achievement)
JTemplateArray(TID,                     ChildTable, UNKNOWN_SIZE)
JTemplateValue(EAchievementTermCombine, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffect, AchievementTerm, Achievement)
JTemplateValue(TID,                Effect)
JTemplateArray(TID,                ValidatorArray, UNKNOWN_SIZE)
JTemplateValue(SEffectWhichPlayer, WhichPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffectAbsorbed, AchievementTermEffect, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffectDamaged, AchievementTermEffect, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffectDodged, AchievementTermEffect, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffectHealed, AchievementTermEffect, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffectKilled, AchievementTermEffect, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermEffectUse, AchievementTermEffect, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermGeneric, AchievementTerm, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermReplay, AchievementTerm, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermScoreValue, AchievementTerm, Achievement)
JTemplateValue(TID, ScoreValue)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermTime, AchievementTerm, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermUnit, AchievementTerm, Achievement)
JTemplateValue(TID, Unit)
JTemplateArray(TID, ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermUnitBirth, AchievementTermUnit, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermUnitDeath, AchievementTermUnit, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermUnitKills, AchievementTermUnit, Achievement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermUnitRegen, AchievementTermUnit, Achievement)
JTemplateValue(EUnitVital, Vital)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AchievementTermUnitSupplyLoss, AchievementTermUnit, Achievement)
JTemplateValue(FIXF32, Period)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Actor, TemplateRecord, Actor)
JTemplateValue(EActorHostedProp,            AcceptedHostedPropTransfers)
JTemplateValue(EActorTransferFlag,          AcceptedTransfers)
JTemplateArray(SActorKey,                   Aliases, UNKNOWN_SIZE)
JTemplateValue(SActorKey,                   CopySource)
JTemplateValue(EActorFilter,                Filter)
JTemplateValue(EActorFlag,                  Flags)
JTemplateValue(EFogVisibility,              FogVisibility)
JTemplateValue(EActorHostedProp,            Inherits)
JTemplateValue(EActorHostedPropInheritType, InheritType)
JTemplateArray(SActorKey,                   Macros, UNKNOWN_SIZE)
JTemplateValue(EActorRequestCreateSharing,  Sharing)
JTemplateValue(SActorRequest,               Supporter)
JTemplateArray(SActorTerm,                  Terms, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorBase, Actor, Actor)
JTemplateValue(UNKNOWN_TYPE, On)
JTemplateArray(SActorEvent,  Remove, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorAction, ActorBase, Actor)
JTemplateValue(FIXF32,                AccuracyHalfArc)
JTemplateValue(FIXF32,                AcquisitionPitchHalfArc)
JTemplateValue(FIXF32,                AcquisitionYawHalfArc)
JTemplateValue(EActorActionFlag,      ActionFlags)
JTemplateValue(SActorKey,             Beam)
JTemplateValue(EActorEffectScope,     BeamScope)
JTemplateValue(SActorAVPair,          ContainerAssets)
JTemplateValue(SAttachQuery,          ContainerAttachQuery)
JTemplateValue(SActorKey,             ContainerModel)
JTemplateValue(SActorKey,             ContainerSite)
JTemplateValue(SActorSiteOpsData,     ContainerSiteOps)
JTemplateValue(SActorKey,             ContainerSound)
JTemplateValue(SAttachQuery,          DamageAttachQuery)
JTemplateEnumA(SActorAVCluster,       DamageMap, ESquibType)
JTemplateValue(SActorKey,             DamageModel)
JTemplateValue(SActorKey,             DamageModelReaction)
JTemplateValue(SAttachQuery,          DamageReattachQuery)
JTemplateValue(SActorKey,             DamageSite)
JTemplateValue(SActorSiteOpsData,     DamageSiteOps)
JTemplateValue(SActorSiteOpsData,     DamageSiteOpsReaction)
JTemplateValue(SActorKey,             DamageSound)
JTemplateValue(SAttachQuery,          ImpactAttachQuery)
JTemplateValue(SActorKey,             ImpactGuideAlias)
JTemplateEnumA(SActorAVCluster,       ImpactMap, ESquibType)
JTemplateValue(SActorKey,             ImpactModel)
JTemplateValue(SActorKey,             ImpactModelReaction)
JTemplateValue(SActorKey,             ImpactPointSite)
JTemplateValue(SActorSiteOpsData,     ImpactPointSiteOps)
JTemplateValue(SAttachQuery,          ImpactReattachQuery)
JTemplateValue(SActorKey,             ImpactSite)
JTemplateValue(SActorKey,             ImpactSiteFallback)
JTemplateValue(SActorSiteOpsData,     ImpactSiteOps)
JTemplateValue(SActorSiteOpsData,     ImpactSiteOpsReaction)
JTemplateValue(SActorKey,             ImpactSound)
JTemplateValue(SActorAVPair,          LaunchAssets)
JTemplateValue(SAttachQuery,          LaunchAttachQuery)
JTemplateValue(SActorKey,             LaunchGuideAlias)
JTemplateValue(SActorKey,             LaunchModel)
JTemplateValue(SActorRequest,         LaunchRequest)
JTemplateValue(SActorKey,             LaunchSite)
JTemplateValue(SActorKey,             LaunchSiteFallback)
JTemplateValue(SActorSiteOpsData,     LaunchSiteOps)
JTemplateValue(SActorKey,             LaunchSound)
JTemplateValue(FIXF32,                Lifetime)
JTemplateValue(SActorKey,             Missile)
JTemplateValue(EActorShieldFlashType, ShieldFlashType)
JTemplateValue(FIXF32,                ShieldRippleScaleFactor)
JTemplateValue(FIXF32,                WeaponFireTrackingTimeWindow)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorBearings, ActorBase, Actor)
JTemplateValue(bool,              AddToProximitySystem)
JTemplateValue(SActorRequest,     Host)
JTemplateValue(SActorRequest,     HostForProps)
JTemplateValue(SActorSiteOpsData, HostSiteOps)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorModel, ActorBearings, Actor)
JTemplateValue(FIXF32,              AnimBlendTime)
JTemplateValue(FIXF32,              AutoScaleFactor)
JTemplateValue(UNKNOWN_TYPE,        AutoScaleFromSelectionFactor)
JTemplateArray(SEventDataFootprint, EventDataFootprint, UNKNOWN_SIZE)
JTemplateValue(SActorKey,           EventDataFootprintActor)
JTemplateArray(SEventDataSound,     EventDataSound, UNKNOWN_SIZE)
JTemplateValue(SActorKey,           EventDataSoundActor)
JTemplateArray(SActorHostedAttach,  HostedAttaches, UNKNOWN_SIZE)
JTemplateValue(SVector3,            LocalOffsetFor2ndVisibilityTest)
JTemplateValue(TID,                 Model)
JTemplateValue(EActorModelFlag,     ModelFlags)
JTemplateValue(EActorProximity,     ProximityPosition)
JTemplateValue(SVector3,            Scale)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorBeam, ActorModel, Actor)
JTemplateValue(SActorRequest,     HostImpact)
JTemplateValue(SActorSiteOpsData, HostImpactSiteOps)
JTemplateValue(SActorRequest,     HostLaunch)
JTemplateValue(SActorSiteOpsData, HostLaunchSiteOps)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorBeamSimple, ActorBeam, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorBeamStandard, ActorBeam, Actor)
JTemplateValue(TID, Beam)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorDoodad, ActorModel, Actor)
JTemplateValue(EActorDoodadFlag, DoodadFlags)
JTemplateArray(EAnimProp,        EditorAnim, UNKNOWN_SIZE)
JTemplateValue(EEditorFlag,      EditorFlags)
JTemplateValue(NAME,             EditorIcon)
JTemplateValue(TID,              EditorModel)
JTemplateValue(FIXF32,           Facing)
JTemplateValue(TID,              Footprint)
JTemplateValue(NAME,             MinimapIcon)
JTemplateValue(UNKNOWN_TYPE,     MinimapRenderPriority)
JTemplateValue(FIXF32,           OccludeHeight)
JTemplateValue(FIXF32,           Radius)
JTemplateValue(SFloatRange,      RandomScaleRange)
JTemplateArray(TID,              TexSets, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorDoodadPreserver, ActorModel, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorEditorCamera, ActorModel, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorEditorPoint, ActorModel, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorEventMacro, ActorBase, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorFoliageFXSpawner, ActorBearings, Actor)
JTemplateValue(FIXF32,    Radius)
JTemplateValue(SActorKey, SpawnTarget)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorGlobalConfig, ActorBase, Actor)
JTemplateValue(SActorKey,             ActorUnitFallback)
JTemplateValue(TID,                   CloakModel)
JTemplateValue(TID,                   CloakModelLow)
JTemplateEnumA(SActorCloakTransition, CloakTransitionArray, EActorCloakEffect)
JTemplateValue(SActorKey,             CommandUIActor)
JTemplateArray(SActorKey,             DeathCustomPriorityList, UNKNOWN_SIZE)
JTemplateValue(SActorKey,             MainActor)
JTemplateValue(FIXF32,                MaxSpeedForSound)
JTemplateValue(UNKNOWN_TYPE,          MinimapRenderPriorityList)
JTemplateValue(SActorKey,             MissileActor)
JTemplateValue(FIXF32,                MissileBoundsOptSpeedThreshold)
JTemplateValue(INT32,                 PopulationLimitModel)
JTemplateValue(UNKNOWN_TYPE,          RevealTint)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorList, ActorBase, Actor)
JTemplateValue(bool, IsAutoDestroy)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorLookAt, ActorBase, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorPortrait, ActorModel, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorPower, ActorBase, Actor)
JTemplateValue(TID,       PowerSource)
JTemplateArray(SActorKey, VisualArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorProgress, ActorBase, Actor)
JTemplateArray(SActorProgressStage, StageArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorQueryResponse, ActorBase, Actor)
JTemplateArray(SActorQueryResponse, OnResponse, UNKNOWN_SIZE)
JTemplateValue(SActorQuerySubject,  Subject)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRange, ActorBearings, Actor)
JTemplateValue(SActorRangeAbil, Abil)
JTemplateValue(FIXF32,          Arc)
JTemplateValue(TID,             Behavior)
JTemplateValue(NAME,            Icon)
JTemplateValue(FIXF32,          IconArcLength)
JTemplateValue(FIXF32,          Range)
JTemplateValue(EActorRangeFlag, RangeFlags)
JTemplateValue(TID,             Sight)
JTemplateValue(TID,             Weapon)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegion, ActorBearings, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegionCircle, ActorRegion, Actor)
JTemplateValue(FIXF32, Radius)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegionCombine, ActorRegion, Actor)
JTemplateArray(SActorKey, ChildArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegionGame, ActorRegion, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegionPolygon, ActorRegion, Actor)
JTemplateArray(SVector2, PointArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegionQuad, ActorRegion, Actor)
JTemplateValue(NAME, Quad)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorRegionWater, ActorRegion, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSetQueried, ActorBase, Actor)
JTemplateValue(SAttachQuery,  AttachQuery)
JTemplateValue(SActorRequest, Host)
JTemplateValue(SActorKey,     SpawnTarget)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorShield, ActorModel, Actor)
JTemplateValue(FIXF32,    RadiusMax)
JTemplateValue(FIXF32,    RadiusMin)
JTemplateValue(SActorKey, Ripple)
JTemplateValue(FIXF32,    ScaleDamageMax)
JTemplateValue(FIXF32,    ScaleDamageMin)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorShieldImpact, ActorBase, Actor)
JTemplateValue(INT32,     MaxCountLarge)
JTemplateValue(INT32,     MaxCountMedium)
JTemplateValue(INT32,     MaxCountSmall)
JTemplateValue(FIXF32,    RadiusLarge)
JTemplateValue(FIXF32,    RadiusMedium)
JTemplateValue(SActorKey, VisualDirectionalFacer)
JTemplateValue(SActorKey, VisualDirectionalHeader)
JTemplateValue(SActorKey, VisualDirectionless)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSimple, ActorBase, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSite, ActorBearings, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteBillboard, ActorSite, Actor)
JTemplateValue(EActorSiteBillboardType, BillboardType)
JTemplateValue(FIXF32,                  TowardsCameraDistance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteMover, ActorSite, Actor)
JTemplateValue(FIXF32, Acceleration)
JTemplateValue(FIXF32, Deceleration)
JTemplateValue(FIXF32, Speed)
JTemplateValue(FIXF32, SpeedMax)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOp, ActorBase, Actor)
JTemplateValue(bool, HoldPosition)
JTemplateValue(bool, HoldRotation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOp2DRotation, ActorSiteOp, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpAction, ActorSiteOp, Actor)
JTemplateValue(EActorSiteOpActionLocation, Location)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpAttach, ActorSiteOp, Actor)
JTemplateValue(SAttachQuery,             AttachQuery)
JTemplateValue(bool,                     ForceSoftAttach)
JTemplateValue(SAttachQuery,             ReattachQuery)
JTemplateValue(EActorSiteOpAttachSource, Source)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpAttachVolume, ActorSiteOp, Actor)
JTemplateValue(SActorRequest,     HostIncoming)
JTemplateValue(SActorSiteOpsData, HostIncomingSiteOps)
JTemplateValue(bool,              UpwardVisibilityEnhancement)
JTemplateValue(FIXF32,            UpwardVisibilityEnhancementVarianceDown)
JTemplateValue(FIXF32,            UpwardVisibilityEnhancementVarianceUp)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpBanker, ActorSiteOp, Actor)
JTemplateValue(FIXF32, RollAngleMax)
JTemplateValue(FIXF32, RollInRate)
JTemplateValue(FIXF32, RollOutRate)
JTemplateValue(FIXF32, RollOutRemainderFractionForLevelOff)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpBankerUnit, TemplateRecord, Actor)
JTemplateValue(UNKNOWN_TYPE, RollInActivationAngle)
JTemplateValue(UNKNOWN_TYPE, RollInArc)
JTemplateValue(UNKNOWN_TYPE, RollMax)
JTemplateValue(UNKNOWN_TYPE, RollOutDuration)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpBase, ActorSiteOp, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpBasic, ActorSiteOp, Actor)
JTemplateValue(EActorSiteOpBasicType, BasicType)
JTemplateValue(SVector3,              WorldPosition)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpEffect, ActorSiteOp, Actor)
JTemplateValue(EActorEffectLocation, Location)
JTemplateValue(bool,                 ZOnly)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpForward, ActorSiteOp, Actor)
JTemplateValue(SVector3,          Forward)
JTemplateValue(SActorRequest,     HostForward)
JTemplateValue(SActorSiteOpsData, HostForwardSiteOps)
JTemplateValue(bool,              Invert)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpHeight, ActorSiteOp, Actor)
JTemplateValue(EActorHeightSourceType, HeightSourceType)
JTemplateValue(SActorRequest,          HostHeight)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpHostBearings, ActorSiteOp, Actor)
JTemplateValue(SActorRequest,     HostBearings)
JTemplateValue(SActorSiteOpsData, HostBearingsSiteOps)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpLocalOffset, ActorSiteOp, Actor)
JTemplateValue(SVector3, LocalOffset)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpPatch, ActorSiteOp, Actor)
JTemplateValue(EActorRadialDistribution, Distribution)
JTemplateValue(FIXF32,                   Mean)
JTemplateValue(FIXF32,                   PatchAngle)
JTemplateValue(FIXF32,                   PatchRadius)
JTemplateValue(FIXF32,                   Variance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpRandomPointInCircle, ActorSiteOp, Actor)
JTemplateValue(EActorRadialDistribution, Distribution)
JTemplateValue(FIXF32,                   Mean)
JTemplateValue(FIXF32,                   Radius)
JTemplateValue(FIXF32,                   Variance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpRotationExplicit, ActorSiteOp, Actor)
JTemplateValue(SVector3, Forward)
JTemplateValue(bool,     IsLocal)
JTemplateValue(SVector3, Up)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpRotationSmooth, ActorSiteOp, Actor)
JTemplateValue(FIXF32, Acceleration)
JTemplateValue(FIXF32, Deceleration)
JTemplateValue(FIXF32, MaxSpeed)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpRotationVariancer, ActorSiteOp, Actor)
JTemplateValue(FIXF32, ForwardAngle)
JTemplateValue(FIXF32, UpAngle)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpSelectionOffset, TemplateRecord, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpShadow, ActorSiteOp, Actor)
JTemplateArray(SVector2,               CliffTests, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                 HeightOffset)
JTemplateValue(FIXF32,                 HeightOffsetOnCliff)
JTemplateValue(EActorHeightSourceType, HeightSourceType)
JTemplateArray(SVector2,               HeightTests, UNKNOWN_SIZE)
JTemplateValue(EActorHeightTestType,   HeightTestType)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpTipability, ActorSiteOp, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteOpUp, ActorSiteOp, Actor)
JTemplateValue(SActorRequest,     HostUp)
JTemplateValue(SActorSiteOpsData, HostUpSiteOps)
JTemplateValue(bool,              Invert)
JTemplateValue(SVector3,          Up)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSiteRocker, ActorSite, Actor)
JTemplateValue(SBaseRange, Elevation)
JTemplateValue(SBaseRange, ElevationPeriod)
JTemplateValue(SBaseRange, Pitch)
JTemplateValue(SBaseRange, PitchPeriod)
JTemplateValue(SBaseRange, Roll)
JTemplateValue(SBaseRange, RollPeriod)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSnapshot, ActorModel, Actor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSound, ActorBearings, Actor)
JTemplateValue(TID,          Sound)
JTemplateValue(UNKNOWN_TYPE, SoundFlags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSplat, ActorBearings, Actor)
JTemplateValue(FIXF32,            AutoScaleFactor)
JTemplateValue(UNKNOWN_TYPE,      AutoScaleFromSelectionFactor)
JTemplateValue(SColor,            Color)
JTemplateValue(FIXF32,            FadeIn)
JTemplateValue(FIXF32,            FadeOut)
JTemplateValue(EActorSplatHeight, Height)
JTemplateValue(FIXF32,            HoldTime)
JTemplateValue(ESplatLayer,       Layer)
JTemplateValue(TID,               Model)
JTemplateValue(SVector3,          Scale)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSelection, ActorSplat, Actor)
JTemplateValue(SVector3,            Alpha)
JTemplateValue(FIXF32,              Attenuation)
JTemplateValue(FIXF32,              FallOff)
JTemplateValue(FIXF32,              HalfHeight)
JTemplateValue(FIXF32,              HostRadiusPercent)
JTemplateValue(FIXF32,              InnerBoundaryFallOffRatio)
JTemplateValue(FIXF32,              InnerBoundaryRatio)
JTemplateValue(FIXF32,              InnerOffsetRatio)
JTemplateValue(FIXF32,              InnerWidth)
JTemplateValue(FIXF32,              OuterWidth)
JTemplateValue(FIXF32,              RotationSpeed)
JTemplateValue(INT32,               SegmentCount)
JTemplateValue(FIXF32,              SegmentPercentSolid)
JTemplateValue(EActorSelectionFlag, SelectionFlags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorShadow, ActorSplat, Actor)
JTemplateValue(SVector3, Alpha)
JTemplateValue(FIXF32,   Attenuation)
JTemplateValue(FIXF32,   FallOff)
JTemplateValue(FIXF32,   HalfHeight)
JTemplateValue(FIXF32,   HostRadiusPercent)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorSquib, ActorBearings, Actor)
JTemplateValue(SActorKey,    HarnessModel)
JTemplateValue(SActorKey,    HarnessSound)
JTemplateEnumA(SActorAVPair, Map, ESquibType)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorStateMonitor, ActorBase, Actor)
JTemplateArray(SActorStateInfo, StateArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,          StateThinkInterval)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorTerrainDeformer, ActorBearings, Actor)
JTemplateValue(FIXF32,                    BlendTime)
JTemplateValue(SActorKey,                 FoliageFXDeathSpawnTarget)
JTemplateValue(TID,                       Footprint)
JTemplateValue(FIXF32,                    HeightDelta)
JTemplateValue(FIXF32,                    InfluenceRange)
JTemplateValue(EActorTerrainDeformerFlag, TerrainDeformerFlags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorText, ActorBearings, Actor)
JTemplateValue(EActorTextAlignment, AlignH)
JTemplateValue(EActorTextAlignment, AlignV)
JTemplateValue(SColor,              Color)
JTemplateValue(INT32,               FixedSize)
JTemplateValue(FIXF32,              HeightOffset)
JTemplateValue(SVector2,            MaxSize)
JTemplateValue(EActorTextOption,    Options)
JTemplateValue(NAME,                Text)
JTemplateValue(FIXF32,              TextScale)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorTurret, ActorBase, Actor)
JTemplateValue(SAttachQuery,  PitchQuery)
JTemplateValue(SActorRequest, TurretBody)
JTemplateValue(SAttachQuery,  YawQuery)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorUnit, ActorModel, Actor)
JTemplateArray(SUnitAbilSound,            AbilSoundArray, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,              AddonIndicator)
JTemplateValue(INT32,                     BarDistance)
JTemplateValue(INT32,                     BarHeight)
JTemplateValue(INT32,                     BarOffset)
JTemplateValue(INT32,                     BarWidth)
JTemplateEnumA(SActorBaseline,            Baselines, EActorBaselineType)
JTemplateValue(TID,                       BuildModel)
JTemplateArray(TID,                       CooldownDisplay, UNKNOWN_SIZE)
JTemplateValue(SActorKey,                 DeathActorModel)
JTemplateValue(SActorKey,                 DeathActorModelLow)
JTemplateValue(SActorKey,                 DeathActorSound)
JTemplateValue(SActorKey,                 DeathActorVoice)
JTemplateEnumA(SActorDeathData,           DeathArray, EDeathType)
JTemplateArray(SActorDeathDataCustom,     DeathCustoms, UNKNOWN_SIZE)
JTemplateArray(EAnimProp,                 EditorAnim, UNKNOWN_SIZE)
JTemplateValue(TID,                       EditorModel)
JTemplateArray(SErrorOverride,            ErrorArray, UNKNOWN_SIZE)
JTemplateValue(NAME,                      GlossaryAnim)
JTemplateValue(NAME,                      GroupIcon)
JTemplateArray(SIconVariation,            GroupIconVariations, UNKNOWN_SIZE)
JTemplateEnumA(TID,                       GroupSoundArray, EUnitSound)
JTemplateValue(INT32,                     GroupSoundThreshold)
JTemplateValue(NAME,                      HeroIcon)
JTemplateArray(SLayerIconVariation,       HeroIconVariations, UNKNOWN_SIZE)
JTemplateValue(NAME,                      HighlightTooltip)
JTemplateValue(NAME,                      InfoText)
JTemplateValue(NAME,                      LifeArmorIcon)
JTemplateValue(NAME,                      MinimapIcon)
JTemplateValue(UNKNOWN_TYPE,              MinimapRenderPriority)
JTemplateValue(INT32,                     NameOffset)
JTemplateValue(UNKNOWN_TYPE,              PlaceholderActorModel)
JTemplateValue(SActorKey,                 PlacementActorModel)
JTemplateValue(TID,                       PlacementModel)
JTemplateValue(TID,                       PlacementSound)
JTemplateValue(SActorKey,                 PortraitActor)
JTemplateValue(TID,                       PortraitModel)
JTemplateValue(SFloatRange,               RandomScaleRange)
JTemplateValue(TID,                       SelectAbilCmd)
JTemplateValue(NAME,                      ShieldArmorIcon)
JTemplateValue(SActorKey,                 SnapshotActor)
JTemplateEnumA(TID,                       SoundArray, EUnitSound)
JTemplateValue(FIXF32,                    StandAnimTurnTime)
JTemplateValue(FIXF32,                    StandAnimTurnTimeScaleMin)
JTemplateValue(EUnitStatus,               StatusBarFlags)
JTemplateValue(UNKNOWN_TYPE,              StatusBarGroups)
JTemplateEnumA(SStatusColor,              StatusColors, EUnitStatus)
JTemplateValue(SColor,                    UnitBorderNormalColor)
JTemplateValue(SColor,                    UnitBorderSubgroupColor)
JTemplateValue(EActorUnitFlag,            UnitFlags)
JTemplateValue(NAME,                      UnitIcon)
JTemplateArray(SLayerIconVariation,       UnitIconVariations, UNKNOWN_SIZE)
JTemplateArray(SUnitKillRank,             UnitKillRank, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                    VarianceWindowStand)
JTemplateValue(FIXF32,                    VarianceWindowStandIntro)
JTemplateValue(FIXF32,                    VarianceWindowWalk)
JTemplateValue(FIXF32,                    VarianceWindowWalkIntro)
JTemplateValue(FIXF32,                    VarianceWindowWalkOutro)
JTemplateValue(FIXF32,                    WalkAnimMoveSpeed)
JTemplateArray(NAME,                      Wireframe, UNKNOWN_SIZE)
JTemplateArray(NAME,                      WireframeShield, UNKNOWN_SIZE)
JTemplateArray(SLayerIconShieldVariation, WireframeShieldVariations, UNKNOWN_SIZE)
JTemplateArray(SIconVariation,            WireframeVariations, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ActorMissile, ActorUnit, Actor)
JTemplateValue(SActorRequest,     HostReturn)
JTemplateValue(SActorSiteOpsData, HostReturnSiteOps)
JTemplateValue(bool,              IsTentacle)
JTemplateValue(SActorKey,         PreHost)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Alert, TemplateRecord, Alert)
JTemplateValue(EAlertDisplay,    Display)
JTemplateValue(FIXF32,           Fade)
JTemplateValue(EAlertFlag,       Flags)
JTemplateValue(NAME,             Icon)
JTemplateValue(FIXF32,           Life)
JTemplateValue(FIXF32,           OverlapDuration)
JTemplateValue(INT32,            OverlapGlobalCount)
JTemplateValue(INT32,            OverlapLocalCount)
JTemplateValue(FIXF32,           OverlapLocalRadius)
JTemplateValue(EAlertPeripheral, Peripheral)
JTemplateValue(SColor,           PingColor)
JTemplateValue(TID,              PingModel)
JTemplateValue(FIXF32,           PingTime)
JTemplateValue(EAlertAction,     PrimaryActions)
JTemplateValue(FIXF32,           QueueTime)
JTemplateValue(EAlertAction,     SecondaryActions)
JTemplateValue(TID,              Sound)
JTemplateValue(NAME,             Text)
JTemplateValue(NAME,             Tooltip)
JTemplateValue(EUnitSound,       Voice)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethod, TemplateRecord, AttachMethod)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodArcTest, AttachMethod, AttachMethod)
JTemplateValue(EAMArcTest,     Tests)
JTemplateValue(EAMArcTestType, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodFilter, AttachMethod, AttachMethod)
JTemplateValue(EAMFilterAttachType, AttachType)
JTemplateValue(EAMFilterType,       FilterType)
JTemplateArray(SAttachKey,          Keys, UNKNOWN_SIZE)
JTemplateValue(EAMFilterLogic,      Logic)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodLeastDeflection, AttachMethod, AttachMethod)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodNodeOccupancy, AttachMethod, AttachMethod)
JTemplateValue(EAMOccupancyLogic, Logic)
JTemplateArray(NAME,              Targets, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodNumericField, AttachMethod, AttachMethod)
JTemplateValue(EAMNumericField,   Field)
JTemplateValue(EAMNumericFieldOp, Operator)
JTemplateValue(FIXF32,            Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodPattern, AttachMethod, AttachMethod)
JTemplateValue(NAME,           Base)
JTemplateValue(NAME,           Driver)
JTemplateValue(EAttachKeyword, Keyword)
JTemplateValue(INT32,          Multiplier)
JTemplateValue(INT32,          Offset)
JTemplateValue(EAMPatternType, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodPortAllocator, AttachMethod, AttachMethod)
JTemplateValue(INT32, PortLimit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodProximity, AttachMethod, AttachMethod)
JTemplateValue(FIXF32,               DistanceMax)
JTemplateValue(SEffectWhichLocation, Location)
JTemplateValue(INT32,                RequestCount)
JTemplateValue(bool,                 SortResults)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodRandom, AttachMethod, AttachMethod)
JTemplateValue(EAMRandomDistribution, Distribution)
JTemplateValue(FIXF32,                ExponentialMean)
JTemplateValue(INT32,                 RequestCount)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodReduction, AttachMethod, AttachMethod)
JTemplateValue(EAMReductionType, ReductionType)
JTemplateValue(INT32,            RequestCount)
JTemplateValue(FIXF32,           RequestPercentage)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodVolumesRequery, AttachMethod, AttachMethod)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodVolumesTargets, AttachMethod, AttachMethod)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(AttachMethodVolumesWeightedPick, AttachMethod, AttachMethod)
JTemplateValue(FIXF32, ProximityFactorFar)
JTemplateValue(FIXF32, ProximityFactorNear)
JTemplateValue(FIXF32, VolumeFactor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Beam, TemplateRecord, Beam)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BeamAsync, Beam, Beam)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BeamAsyncLinear, BeamAsync, Beam)
JTemplateValue(FIXF32, Duration)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BeamAsyncShadow, BeamAsync, Beam)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BeamSync, Beam, Beam)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BeamSyncSweeper, BeamSync, Beam)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Behavior, TemplateRecord, Behavior)
JTemplateValue(EBehaviorAlignment, Alignment)
JTemplateValue(EBehaviorCategory,  BehaviorCategories)
JTemplateValue(SCost,              Cost)
JTemplateValue(EBehaviorInfoFlag,  InfoFlags)
JTemplateValue(NAME,               InfoIcon)
JTemplateValue(INT32,              InfoTooltipPriority)
JTemplateValue(TID,                Requirements)
JTemplateArray(NAME,               TechAliasArray, UNKNOWN_SIZE)
JTemplateValue(NAME,               Tooltip)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorAttribute, Behavior, Behavior)
JTemplateValue(INT32,         MaxPoints)
JTemplateValue(INT32,         MinPoints)
JTemplateValue(SModification, Modification)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorBuff, Behavior, Behavior)
JTemplateValue(SEffectWhichPlayer,    AcquirePlayer)
JTemplateValue(TID,                   AINotifyEffect)
JTemplateValue(EBehaviorBuff,         BuffFlags)
JTemplateValue(SDamageResponse,       DamageResponse)
JTemplateArray(TID,                   DisableValidatorArray, UNKNOWN_SIZE)
JTemplateValue(EBehaviorDisplay,      DisplayDuration)
JTemplateValue(EBehaviorDisplay,      DisplayShield)
JTemplateValue(FIXF32,                Duration)
JTemplateValue(FIXF32,                DurationBonusMax)
JTemplateValue(FIXF32,                DurationBonusMin)
JTemplateValue(FIXF32,                DurationRandomMax)
JTemplateValue(FIXF32,                DurationRandomMin)
JTemplateValue(FIXF32,                DurationShield)
JTemplateEnumA(FIXF32,                DurationVitalArray, EUnitVital)
JTemplateEnumA(FIXF32,                DurationVitalMaxArray, EUnitVital)
JTemplateValue(TID,                   ExpireEffect)
JTemplateValue(TID,                   FinalEffect)
JTemplateValue(TID,                   InitialEffect)
JTemplateValue(SEffectWhichUnit,      KillCredit)
JTemplateValue(INT32,                 MaxStackCount)
JTemplateValue(INT32,                 MaxStackCountPerCaster)
JTemplateValue(SModification,         Modification)
JTemplateValue(FIXF32,                Period)
JTemplateValue(INT32,                 PeriodCount)
JTemplateValue(TID,                   PeriodicEffect)
JTemplateValue(SEffectWhichPlayer,    Player)
JTemplateValue(TID,                   RefreshEffect)
JTemplateArray(TID,                   RemoveValidatorArray, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,          Replace)
JTemplateValue(UNKNOWN_TYPE,          ReplaceLocation)
JTemplateValue(SEffectWhichTimeScale, TimeScaleSource)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorClickResponse, Behavior, Behavior)
JTemplateValue(FIXF32,              Chance)
JTemplateValue(INT32,               Count)
JTemplateValue(FIXF32,              CountDelay)
JTemplateValue(TID,                 CountEffect)
JTemplateValue(EPlayerRelationship, Relationship)
JTemplateValue(FIXF32,              ResetDelay)
JTemplateValue(TID,                 ResetEffect)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorConjoined, Behavior, Behavior)
JTemplateValue(FIXF32, Radius)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorCreepSource, Behavior, Behavior)
JTemplateValue(TID,    Birth)
JTemplateValue(TID,    Build)
JTemplateValue(FIXF32, Delay)
JTemplateArray(TID,    DisableValidatorArray, UNKNOWN_SIZE)
JTemplateValue(TID,    Grown)
JTemplateValue(FIXF32, Period)
JTemplateArray(TID,    RemoveValidatorArray, UNKNOWN_SIZE)
JTemplateValue(TID,    Start)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorJump, Behavior, Behavior)
JTemplateValue(FIXF32, DurationMoveOut)
JTemplateValue(FIXF32, DurationPostLand)
JTemplateValue(FIXF32, DurationPreLaunch)
JTemplateValue(FIXF32, InitiateRangeDown)
JTemplateValue(FIXF32, InitiateRangeUp)
JTemplateValue(FIXF32, JumpRangeMax)
JTemplateValue(FIXF32, LandAdjustmentDown)
JTemplateValue(FIXF32, LandAdjustmentUp)
JTemplateValue(FIXF32, LandArrivalRange)
JTemplateValue(FIXF32, LandCheckRadius)
JTemplateValue(TID,    Mover)
JTemplateValue(TID,    MoverDown)
JTemplateValue(TID,    MoverUp)
JTemplateValue(TID,    Placeholder)
JTemplateValue(FIXF32, TriggerHeightDeltaMax)
JTemplateValue(FIXF32, TriggerHeightDeltaMin)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorPowerSource, Behavior, Behavior)
JTemplateValue(INT32,  PowerLevel)
JTemplateValue(NAME,   PowerLink)
JTemplateValue(FIXF32, Radius)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorPowerUser, Behavior, Behavior)
JTemplateValue(EBehaviorPowerUserFlag, Flags)
JTemplateValue(INT32,                  PlacementMinPowerLevel)
JTemplateValue(bool,                   PoweredWhileUnderConstruction)
JTemplateValue(NAME,                   PowerLink)
JTemplateArray(SPowerStage,            PowerStageArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorResource, Behavior, Behavior)
JTemplateValue(INT32,                 Capacity)
JTemplateValue(TID,                   CarryResourceBehavior)
JTemplateValue(INT32,                 Contents)
JTemplateValue(TID,                   DepletionAlert)
JTemplateValue(INT32,                 DepletionThreshold)
JTemplateValue(INT32,                 DepletionVariationCount)
JTemplateValue(INT32,                 EmptyHarvestAmount)
JTemplateValue(TID,                   EmptyUnit)
JTemplateValue(TID,                   ExhaustedAlert)
JTemplateValue(EBehaviorResourceFlag, Flags)
JTemplateValue(INT32,                 HarvestAmount)
JTemplateValue(FIXF32,                HarvestTime)
JTemplateValue(EAllianceId,           RequiredAlliance)
JTemplateValue(FIXF32,                ReturnDelay)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorReveal, Behavior, Behavior)
JTemplateValue(FIXF32, Duration)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorSpawn, Behavior, Behavior)
JTemplateValue(SVector2,           Center)
JTemplateValue(EBehaviorDisplay,   DisplayDuration)
JTemplateValue(TID,                Effect)
JTemplateValue(EBehaviorSpawnFlag, Flags)
JTemplateArray(SSpawnInfo,         InfoArray, UNKNOWN_SIZE)
JTemplateValue(INT32,              Limit)
JTemplateArray(SVector2,           Offset, UNKNOWN_SIZE)
JTemplateValue(FIXF32,             Range)
JTemplateValue(FIXF32,             Slop)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorVeterancy, Behavior, Behavior)
JTemplateValue(EBehaviorVeterancyFlag,   Flags)
JTemplateEnumA(FIXF32,                   SharedXPFraction, EBehaviorVeterancyXP)
JTemplateEnumA(FIXF32,                   SharedXPRadius, EBehaviorVeterancyXP)
JTemplateEnumA(TARGETFILTERDICTIONARY, ShareFilters, EBehaviorVeterancyXP)
JTemplateEnumA(TARGETFILTERDICTIONARY, TargetFilters, EBehaviorVeterancyXP)
JTemplateArray(SVeterancyLevel,          VeterancyLevelArray, UNKNOWN_SIZE)
JTemplateEnumA(FIXF32,                   XPFraction, EBehaviorVeterancyXP)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(BehaviorWander, Behavior, Behavior)
JTemplateValue(FIXF32, Delay)
JTemplateValue(bool,   Leash)
JTemplateValue(FIXF32, Range)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Button, TemplateRecord, Button)
JTemplateValue(NAME,         AlertIcon)
JTemplateValue(NAME,         AlertName)
JTemplateValue(NAME,         AlertTooltip)
JTemplateValue(NAME,         Hotkey)
JTemplateValue(UNKNOWN_TYPE, HotkeyAlias)
JTemplateValue(UNKNOWN_TYPE, HotkeySet)
JTemplateValue(NAME,         Icon)
JTemplateValue(bool,         TintRacially)
JTemplateValue(NAME,         Tooltip)
JTemplateValue(UNKNOWN_TYPE, Universal)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Camera, TemplateRecord, Camera)
JTemplateValue(INT32,         BorderSizeX)
JTemplateValue(INT32,         BorderSizeY)
JTemplateValue(FIXF32,        DistanceIncrement)
JTemplateValue(FIXF32,        DistanceMax)
JTemplateValue(FIXF32,        DistanceMin)
JTemplateValue(FIXF32,        FieldOfViewIncrement)
JTemplateValue(FIXF32,        FieldOfViewMax)
JTemplateValue(FIXF32,        FieldOfViewMin)
JTemplateValue(FIXF32,        FollowScrollLimit)
JTemplateEnumA(FIXF32,        ForwardScale, ECameraMode)
JTemplateValue(FIXF32,        HeightDisplacementFactor)
JTemplateValue(FIXF32,        HeightDisplacementMax)
JTemplateValue(FIXF32,        HeightDisplacementPitchMax)
JTemplateValue(FIXF32,        HeightDisplacementPitchMin)
JTemplateEnumA(FIXF32,        MaxScrollDistance, ECameraMode)
JTemplateEnumA(FIXF32,        MaxScrollRate, ECameraMode)
JTemplateEnumA(FIXF32,        ParamInitial, ECameraParam)
JTemplateEnumA(SCameraSmooth, ParamSmooth, ECameraParam)
JTemplateValue(FIXF32,        PitchIncrement)
JTemplateValue(FIXF32,        PitchMax)
JTemplateValue(FIXF32,        PitchMin)
JTemplateValue(FIXF32,        RotateScale)
JTemplateEnumA(FIXF32,        ScrollAccelerationPeriod, ECameraMode)
JTemplateEnumA(FIXF32,        ScrollDecelerationPeriod, ECameraMode)
JTemplateValue(FIXF32,        SmartPanJumpDistance)
JTemplateValue(FIXF32,        SmartPanSkipDistance)
JTemplateEnumA(FIXF32,        StrafeScale, ECameraMode)
JTemplateValue(SCameraSmooth, TargetSmooth)
JTemplateEnumA(FIXF32,        VerticalScrollRateMultiplier, ECameraMode)
JTemplateValue(FIXF32,        YawIncrement)
JTemplateValue(FIXF32,        YawLeft)
JTemplateValue(FIXF32,        YawMax)
JTemplateValue(FIXF32,        YawMin)
JTemplateValue(FIXF32,        YawRight)
JTemplateValue(INT32,         ZoomDefault)
JTemplateArray(SCameraZoom,   ZoomTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Cliff, TemplateRecord, Cliff)
JTemplateValue(NAME, CliffMaterial)
JTemplateValue(TID,  CliffMesh)
JTemplateValue(NAME, EditorIcon)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(CliffMesh, TemplateRecord, Cliff)
JTemplateArray(FIXF32, CliffHeights, UNKNOWN_SIZE)
JTemplateValue(NAME,   ModelPath)
JTemplateValue(bool,   WeldNormals)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Conversation, TemplateRecord, Conversation)
JTemplateValue(INT32,                     AnimBlendOut)
JTemplateArray(SConversationChoice,       Choices, UNKNOWN_SIZE)
JTemplateArray(SConversationComment,      Comments, UNKNOWN_SIZE)
JTemplateArray(SConversationFacialAnim,   FacialAnims, UNKNOWN_SIZE)
JTemplateValue(SConversationActionSet,    FixedActions)
JTemplateValue(SConversationConditionSet, FixedConditions)
JTemplateArray(SConversationGroup,        Groups, UNKNOWN_SIZE)
JTemplateArray(SConversationJump,         Jumps, UNKNOWN_SIZE)
JTemplateArray(SConversationLine,         Lines, UNKNOWN_SIZE)
JTemplateArray(TID,                       ObjectStates, UNKNOWN_SIZE)
JTemplateArray(SConversationGroup,        RootItems, UNKNOWN_SIZE)
JTemplateArray(SConversationRunActions,   RunActions, UNKNOWN_SIZE)
JTemplateArray(SConversationWait,         Waits, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ConversationState, TemplateRecord, Conversation)
JTemplateArray(SColor,                    CustomColors, UNKNOWN_SIZE)
JTemplateValue(EConversationStateFlag,    Flags)
JTemplateArray(SConversationStateIndex,   Indices, UNKNOWN_SIZE)
JTemplateEnumA(SConversationStateInfoIds, InfoIds, EConversationStateInfo)
JTemplateValue(SIntRange,                 ValueRange)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Cursor, TemplateRecord, Cursor)
JTemplateValue(INT32, HotspotX)
JTemplateValue(INT32, HotspotY)
JTemplateValue(NAME,  Texture)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSP, TemplateRecord, DSP)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPChorus, DSP, DSP)
JTemplateValue(FIXF32, Delay)
JTemplateValue(FIXF32, Depth)
JTemplateValue(FIXF32, DryMix)
JTemplateValue(FIXF32, Feedback)
JTemplateValue(FIXF32, Rate)
JTemplateValue(FIXF32, WetMix1)
JTemplateValue(FIXF32, WetMix2)
JTemplateValue(FIXF32, WetMix3)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPCompressor, DSP, DSP)
JTemplateValue(FIXF32, Attack)
JTemplateValue(FIXF32, GainMakeUp)
JTemplateValue(FIXF32, Release)
JTemplateValue(FIXF32, Threshold)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPDistortion, DSP, DSP)
JTemplateValue(FIXF32, Level)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPEcho, DSP, DSP)
JTemplateValue(FIXF32, DecayRatio)
JTemplateValue(FIXF32, Delay)
JTemplateValue(FIXF32, DryMix)
JTemplateValue(FIXF32, MaxChannels)
JTemplateValue(FIXF32, WetMix)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPFlange, DSP, DSP)
JTemplateValue(FIXF32, Depth)
JTemplateValue(FIXF32, DryMix)
JTemplateValue(FIXF32, Rate)
JTemplateValue(FIXF32, WetMix)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPHighPass, DSP, DSP)
JTemplateValue(FIXF32, Cutoff)
JTemplateValue(FIXF32, Resonance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPLowPass, DSP, DSP)
JTemplateValue(FIXF32, Cutoff)
JTemplateValue(FIXF32, Resonance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPLowPassSimple, DSP, DSP)
JTemplateValue(FIXF32, Cutoff)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPNormalize, DSP, DSP)
JTemplateValue(FIXF32, FadeTime)
JTemplateValue(FIXF32, MaxAmp)
JTemplateValue(FIXF32, Threshhold)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPOscillator, DSP, DSP)
JTemplateValue(FIXF32,      Rate)
JTemplateValue(EOscillator, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPParamEQ, DSP, DSP)
JTemplateValue(FIXF32, Bandwidth)
JTemplateValue(FIXF32, Center)
JTemplateValue(FIXF32, Gain)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPPitchShift, DSP, DSP)
JTemplateValue(INT32,  FFTSize)
JTemplateValue(FIXF32, MaxChannels)
JTemplateValue(FIXF32, Pitch)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(DSPReverb, DSP, DSP)
JTemplateValue(FIXF32, DecayHFRatio)
JTemplateValue(FIXF32, DecayTime)
JTemplateValue(FIXF32, Density)
JTemplateValue(FIXF32, Diffusion)
JTemplateValue(FIXF32, DryLevel)
JTemplateValue(FIXF32, HFReference)
JTemplateValue(FIXF32, LFReference)
JTemplateValue(FIXF32, ReflectionsDelay)
JTemplateValue(FIXF32, ReflectionsLevel)
JTemplateValue(FIXF32, ReverbDelay)
JTemplateValue(FIXF32, ReverbLevel)
JTemplateValue(FIXF32, Room)
JTemplateValue(FIXF32, RoomHF)
JTemplateValue(FIXF32, RoomLF)
JTemplateValue(FIXF32, RoomRolloffFactor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Effect, TemplateRecord, Effect)
JTemplateValue(ENotifyAreaFlag, AINotifyFlags)
JTemplateValue(FIXF32,          Chance)
JTemplateValue(SMarker,         Marker)
JTemplateArray(NAME,            TechAliasArray, UNKNOWN_SIZE)
JTemplateArray(TID,             ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectResponse, Effect, Effect)
JTemplateValue(EResponseFlag, ResponseFlags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectApplyBehavior, EffectResponse, Effect)
JTemplateValue(TID,              Behavior)
JTemplateValue(INT32,            Count)
JTemplateValue(bool,             KillHallucination)
JTemplateValue(SEffectWhichUnit, WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectApplyForce, EffectResponse, Effect)
JTemplateValue(FIXF32,                Amount)
JTemplateValue(FIXF32,                MassFraction)
JTemplateValue(SEffectWhichTimeScale, TimeScaleSource)
JTemplateValue(SEffectWhichLocation,  WhichLocation)
JTemplateValue(SEffectWhichUnit,      WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectCreateHealer, EffectResponse, Effect)
JTemplateEnumA(FIXF32,            DrainResourceCostFactor, EResourceType)
JTemplateValue(EUnitVital,        DrainVital)
JTemplateValue(FIXF32,            DrainVitalCostFactor)
JTemplateValue(EEffectHealerFlag, Flags)
JTemplateValue(SEffectWhichUnit,  ImpactUnit)
JTemplateValue(SEffectWhichUnit,  LaunchUnit)
JTemplateValue(TID,               PeriodicEffect)
JTemplateValue(TID,               PeriodicValidator)
JTemplateValue(EUnitVital,        RechargeVital)
JTemplateValue(FIXF32,            RechargeVitalRate)
JTemplateValue(FIXF32,            TimeFactor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectCreatePersistent, EffectResponse, Effect)
JTemplateValue(TID,                   AINotifyEffect)
JTemplateValue(STargetFilters,        DetectFilters)
JTemplateValue(FIXF32,                ExpireDelay)
JTemplateValue(TID,                   ExpireEffect)
JTemplateValue(SVector3,              ExpireOffset)
JTemplateValue(TID,                   FinalEffect)
JTemplateValue(SVector3,              FinalOffset)
JTemplateValue(ECreatePersistent,     Flags)
JTemplateValue(EHeightMap,            HeightMap)
JTemplateValue(FIXF32,                InitialDelay)
JTemplateValue(TID,                   InitialEffect)
JTemplateValue(SVector3,              InitialOffset)
JTemplateValue(SEffectWhichLocation,  OffsetFacingFallback)
JTemplateValue(SEffectWhichLocation,  OffsetVectorEndLocation)
JTemplateValue(SEffectWhichLocation,  OffsetVectorStartLocation)
JTemplateValue(INT32,                 PeriodCount)
JTemplateArray(TID,                   PeriodicEffectArray, UNKNOWN_SIZE)
JTemplateArray(SVector3,              PeriodicOffsetArray, UNKNOWN_SIZE)
JTemplateArray(FIXF32,                PeriodicPeriodArray, UNKNOWN_SIZE)
JTemplateValue(TID,                   PeriodicValidator)
JTemplateValue(STargetFilters,        RadarFilters)
JTemplateValue(EEffectRevealFlag,     RevealFlags)
JTemplateValue(FIXF32,                RevealRadius)
JTemplateValue(SEffectWhichTimeScale, TimeScaleSource)
JTemplateValue(SEffectWhichLocation,  WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectCreateUnit, EffectResponse, Effect)
JTemplateValue(ECreateUnit,          CreateFlags)
JTemplateValue(SEffectWhichLocation, Origin)
JTemplateValue(INT32,                SpawnCount)
JTemplateValue(TID,                  SpawnEffect)
JTemplateValue(SEffectWhichPlayer,   SpawnOwner)
JTemplateValue(FIXF32,               SpawnRange)
JTemplateValue(TID,                  SpawnUnit)
JTemplateValue(SEffectWhichLocation, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectDamage, EffectResponse, Effect)
JTemplateValue(FIXF32,                Amount)
JTemplateArray(SEffectDamageArea,     AreaArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                ArmorReduction)
JTemplateEnumA(FIXF32,                AttributeBonus, EUnitAttributes)
JTemplateEnumA(FIXF32,                AttributeFactor, EUnitAttributes)
JTemplateValue(EDeathType,            Death)
JTemplateValue(EEquipmentDisplayFlag, DisplayFlags)
JTemplateArray(SEffectWhichUnit,      ExcludeArray, UNKNOWN_SIZE)
JTemplateValue(EDamageFlag,           Flags)
JTemplateValue(SEffectWhichLocation,  ImpactLocation)
JTemplateValue(TID,                   ImpactUnitValidator)
JTemplateArray(SEffectWhichUnit,      IncludeArray, UNKNOWN_SIZE)
JTemplateValue(bool,                  KillHallucination)
JTemplateValue(EDamageKind,           Kind)
JTemplateValue(SEffectWhichLocation,  LaunchLocation)
JTemplateEnumA(FIXF32,                LeechFraction, EUnitVital)
JTemplateValue(INT32,                 MaxCount)
JTemplateValue(INT32,                 MinCount)
JTemplateValue(SError,                MinCountError)
JTemplateValue(FIXF32,                Random)
JTemplateValue(INT32,                 RecycleCount)
JTemplateValue(STargetFilters,        SearchFilters)
JTemplateValue(EEffectSearchFlag,     SearchFlags)
JTemplateValue(FIXF32,                ShieldBonus)
JTemplateValue(FIXF32,                ShieldFactor)
JTemplateValue(STargetSorts,          TargetSorts)
JTemplateValue(EDamageTotal,          Total)
JTemplateValue(EDamageVisibility,     Visibility)
JTemplateEnumA(FIXF32,                VitalBonus, EUnitVital)
JTemplateEnumA(FIXF32,                VitalFractionCurrent, EUnitVital)
JTemplateEnumA(FIXF32,                VitalFractionMax, EUnitVital)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectDestroyHealer, EffectResponse, Effect)
JTemplateValue(INT32,                Count)
JTemplateValue(TID,                  Effect)
JTemplateValue(FIXF32,               Radius)
JTemplateValue(SEffectWhichLocation, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectDestroyPersistent, EffectResponse, Effect)
JTemplateValue(INT32,                Count)
JTemplateValue(TID,                  Effect)
JTemplateValue(FIXF32,               Radius)
JTemplateValue(SEffectWhichLocation, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectEnumArea, EffectResponse, Effect)
JTemplateArray(SEffectEnumArea,      AreaArray, UNKNOWN_SIZE)
JTemplateArray(SEffectWhichUnit,     ExcludeArray, UNKNOWN_SIZE)
JTemplateValue(SEffectWhichLocation, ImpactLocation)
JTemplateArray(SEffectWhichUnit,     IncludeArray, UNKNOWN_SIZE)
JTemplateValue(SEffectWhichLocation, LaunchLocation)
JTemplateValue(INT32,                MaxCount)
JTemplateValue(INT32,                MinCount)
JTemplateValue(SError,               MinCountError)
JTemplateValue(INT32,                RecycleCount)
JTemplateValue(STargetFilters,       SearchFilters)
JTemplateValue(EEffectSearchFlag,    SearchFlags)
JTemplateValue(STargetSorts,         TargetSorts)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectEnumTransport, EffectResponse, Effect)
JTemplateValue(bool,             CheckOuter)
JTemplateValue(TID,              Effect)
JTemplateValue(INT32,            MaxCount)
JTemplateValue(STargetFilters,   SearchFilters)
JTemplateValue(SEffectWhichUnit, WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectIssueOrder, EffectResponse, Effect)
JTemplateValue(TID,                  Abil)
JTemplateValue(INT32,                AbilCmdIndex)
JTemplateValue(ECmdFlags,            CmdFlags)
JTemplateValue(SEffectWhichPlayer,   Player)
JTemplateValue(SEffectWhichLocation, Target)
JTemplateValue(SEffectWhichUnit,     WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectLaunchMissile, EffectResponse, Effect)
JTemplateValue(FIXF32,               AmmoLife)
JTemplateValue(TID,                  AmmoUnit)
JTemplateValue(EDeathType,           DeathType)
JTemplateValue(TID,                  FinishEffect)
JTemplateValue(EEffectMissile,       Flags)
JTemplateValue(TID,                  ImpactEffect)
JTemplateValue(SEffectWhichLocation, ImpactLocation)
JTemplateValue(SVector3,             ImpactOffset)
JTemplateValue(FIXF32,               ImpactRange)
JTemplateValue(TID,                  LaunchEffect)
JTemplateValue(SEffectWhichLocation, LaunchLocation)
JTemplateValue(SVector3,             LaunchOffset)
JTemplateValue(INT32,                MoverExecuteJump)
JTemplateValue(EMoverPatternType,    MoverExecutePattern)
JTemplateValue(FIXF32,               MoverExecuteRange)
JTemplateValue(FIXF32,               MoverRollingJump)
JTemplateValue(EMoverPatternType,    MoverRollingPattern)
JTemplateArray(SEffectMover,         Movers, UNKNOWN_SIZE)
JTemplateValue(TID,                  PlaceholderUnit)
JTemplateValue(STargetFilters,       RetargetFilters)
JTemplateValue(FIXF32,               RetargetRange)
JTemplateValue(FIXF32,               ReturnDelay)
JTemplateArray(SEffectMover,         ReturnMovers, UNKNOWN_SIZE)
JTemplateValue(TID,                  TransferBehavior)
JTemplateValue(INT32,                TransferCount)
JTemplateValue(EDamageVisibility,    Visibility)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectModifyPlayer, Effect, Effect)
JTemplateEnumA(INT32,              Resources, EResourceType)
JTemplateValue(SEffectWhichPlayer, WhichPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectModifyUnit, EffectResponse, Effect)
JTemplateValue(SEffectModifyCost,  Cost)
JTemplateValue(FIXF32,             Height)
JTemplateValue(FIXF32,             HeightTime)
JTemplateValue(SEffectWhichUnit,   ImpactUnit)
JTemplateValue(SEffectWhichUnit,   KillCreditUnit)
JTemplateValue(bool,               KillHallucination)
JTemplateValue(SEffectWhichUnit,   LaunchUnit)
JTemplateValue(EEffectModify,      ModifyFlags)
JTemplateValue(INT32,              ResourceRestoreBonus)
JTemplateValue(FIXF32,             ResourceRestoreFraction)
JTemplateValue(INT32,              Resources)
JTemplateValue(INT32,              ResourcesHarvestedBonus)
JTemplateValue(FIXF32,             ResourcesHarvestedFraction)
JTemplateValue(SEffectWhichUnit,   TransferUnit)
JTemplateEnumA(SEffectModifyVital, VitalArray, EUnitVital)
JTemplateValue(FIXF32,             XP)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectReleaseMagazine, EffectResponse, Effect)
JTemplateValue(TID,              MagazineEffect)
JTemplateValue(SEffectWhichUnit, WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectRemoveBehavior, EffectResponse, Effect)
JTemplateValue(EBehaviorCategory, BehaviorCategories)
JTemplateValue(EClassIdCBehavior, BehaviorClass)
JTemplateValue(TID,               BehaviorLink)
JTemplateValue(INT32,             Count)
JTemplateValue(bool,              KillHallucination)
JTemplateValue(SEffectWhichUnit,  WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectSet, Effect, Effect)
JTemplateArray(TID,                 EffectArray, UNKNOWN_SIZE)
JTemplateValue(INT32,               MaxCount)
JTemplateValue(INT32,               MinCount)
JTemplateValue(bool,                Random)
JTemplateValue(EEffectLocationType, TargetLocationType)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectSwitch, Effect, Effect)
JTemplateArray(SEffectSwitchCase,   CaseArray, UNKNOWN_SIZE)
JTemplateValue(TID,                 CaseDefault)
JTemplateValue(EEffectLocationType, TargetLocationType)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectTeleport, EffectResponse, Effect)
JTemplateValue(bool,                 ClearQueuedOrders)
JTemplateValue(FIXF32,               MinDistance)
JTemplateValue(FIXF32,               PlacementArc)
JTemplateValue(SEffectWhichLocation, PlacementAround)
JTemplateValue(FIXF32,               PlacementRange)
JTemplateValue(FIXF32,               Range)
JTemplateValue(SEffectWhichLocation, SourceLocation)
JTemplateValue(SEffectWhichLocation, TargetLocation)
JTemplateValue(EEffectTeleport,      TeleportFlags)
JTemplateValue(SEffectWhichUnit,     WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectTransferBehavior, EffectResponse, Effect)
JTemplateValue(TID,              Behavior)
JTemplateValue(bool,             Copy)
JTemplateValue(INT32,            Count)
JTemplateValue(SEffectWhichUnit, ImpactUnit)
JTemplateValue(SEffectWhichUnit, LaunchUnit)
JTemplateValue(bool,             Preserve)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectUseCalldown, EffectResponse, Effect)
JTemplateValue(INT32,                CalldownCount)
JTemplateValue(TID,                  CalldownEffect)
JTemplateValue(SEffectWhichLocation, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(EffectUseMagazine, EffectResponse, Effect)
JTemplateValue(TID,              AmmoEffect)
JTemplateValue(TID,              AmmoUnit)
JTemplateValue(SEffectWhichUnit, WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Footprint, TemplateRecord, Footprint)
JTemplateArray(SFootprintLayer, Layers, UNKNOWN_SIZE)
JTemplateArray(SFootprintShape, Shape, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(FoW, TemplateRecord, FoW)
JTemplateValue(SColor, Color)
JTemplateValue(bool,   Hidden)
JTemplateValue(FIXF32, UnhideRadius)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Game, TemplateRecord, Game)
JTemplateValue(FIXF32,              AcquireLeashRadius)
JTemplateValue(FIXF32,              AcquireLeashResetRadius)
JTemplateArray(SAIDescription,      AI, UNKNOWN_SIZE)
JTemplateEnumA(INT32,               AIResourceRequest, EResourceType)
JTemplateValue(FIXF32,              AirFormationDiameter)
JTemplateValue(TID,                 AttackRevealBehavior)
JTemplateValue(FIXF32,              AttackRevealTime)
JTemplateEnumA(SBeaconInfo,         BeaconInfoArray, EBeacon)
JTemplateValue(FIXF32,              CallForHelpPeriod)
JTemplateValue(FIXF32,              CallForHelpRadius)
JTemplateValue(NAME,                CameraMargin)
JTemplateArray(SAspectMargin,       CameraMarginAspectAdjust, UNKNOWN_SIZE)
JTemplateArray(NAME,                CampaignBanks, UNKNOWN_SIZE)
JTemplateValue(FIXF32,              CreepBlendTime)
JTemplateValue(TID,                 CreepDecaySound)
JTemplateValue(FIXF32,              CreepDecayTime)
JTemplateValue(TID,                 CreepGrowSound)
JTemplateValue(FIXF32,              DamageMinimum)
JTemplateValue(INT32,               DifficultyDefault)
JTemplateArray(SDifficultyLevel,    DifficultyLevels, UNKNOWN_SIZE)
JTemplateArray(STargetFilterResult, FilterResults, UNKNOWN_SIZE)
JTemplateArray(SHandicap,           HandicapValues, UNKNOWN_SIZE)
JTemplateArray(SMapSize,            MapSizes, UNKNOWN_SIZE)
JTemplateValue(FIXF32,              MixedFormationDiameter)
JTemplateValue(FIXF32,              PenaltyRevealTime)
JTemplateValue(TID,                 SplashDamageEffect)
JTemplateValue(UNKNOWN_TYPE,        StalemateTestTime)
JTemplateValue(UNKNOWN_TYPE,        StalemateWarningTime)
JTemplateValue(TID,                 TauntAbil)
JTemplateArray(STeamColor,          TeamColors, UNKNOWN_SIZE)
JTemplateArray(STriggerLib,         TriggerLibs, UNKNOWN_SIZE)
JTemplateValue(FIXF32,              UncontestedCombatPeriod)
JTemplateValue(FIXF32,              UnitSightRangeDead)
JTemplateValue(FIXF32,              UnitSightRangeUnderConstruction)
JTemplateValue(NAME,                UnpathableMargin)
JTemplateValue(UNKNOWN_TYPE,        VeterancySearchFilters)
JTemplateValue(UNKNOWN_TYPE,        VeterancySearchRadius)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(GameUI, TemplateRecord, Game)
JTemplateValue(UNKNOWN_TYPE,        AchievementTags)
JTemplateValue(FIXF32,              AlertPanMaxDuration)
JTemplateValue(FIXF32,              AlertPanMaxVelocity)
JTemplateValue(FIXF32,              AlertPanMinDuration)
JTemplateValue(SDefaultGameVariant, AutoVariant)
JTemplateValue(NAME,                BeaconMinimapIcon)
JTemplateValue(UNKNOWN_TYPE,        BeaconMinimapRenderPriority)
JTemplateEnumA(SColor,              BehaviorBorderColors, EBehaviorAlignment)
JTemplateEnumA(SColor,              BehaviorIconColors, EBehaviorAlignment)
JTemplateArray(SCampaignData,       Campaign, UNKNOWN_SIZE)
JTemplateValue(INT32,               CampaignIntroMovie)
JTemplateValue(TID,                 CancelPlacementModeButtonFace)
JTemplateValue(TID,                 CancelTargetModeButtonFace)
JTemplateArray(SChallengeCategory,  ChallengeCategory, UNKNOWN_SIZE)
JTemplateArray(TID,                 ChallengeMasterAchievement, UNKNOWN_SIZE)
JTemplateEnumA(SColor,              CostDisplayColor, ECostDisplay)
JTemplateValue(FIXF32,              CostDisplayFade)
JTemplateValue(INT32,               CostDisplayHeight)
JTemplateValue(FIXF32,              CostDisplayHeightOffset)
JTemplateValue(FIXF32,              CostDisplaySpeed)
JTemplateValue(FIXF32,              CostDisplayTime)
JTemplateValue(TID,                 CreditsMusic)
JTemplateValue(UNKNOWN_TYPE,        CustomLayoutFileArray)
JTemplateValue(NAME,                DefaultInfoTooltipTypes)
JTemplateValue(TID,                 DefaultUIRace)
JTemplateArray(SDefaultGameVariant, DefaultVariants, UNKNOWN_SIZE)
JTemplateArray(TID,                 DSPArray, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,        FontStyleFileArray)
JTemplateArray(SGameCategory,       GameCategories, UNKNOWN_SIZE)
JTemplateValue(INT32,               GlowCycleLength)
JTemplateValue(SVector3,            GlowPeakMultiplier)
JTemplateValue(SVector3,            GlowStartMultiplier)
JTemplateValue(UNKNOWN_TYPE,        HotkeyInfoArray)
JTemplateValue(SColor,              InfoColorBuffed)
JTemplateValue(SColor,              InfoColorDebuffed)
JTemplateValue(SColor,              InfoColorUpgraded)
JTemplateValue(TID,                 IntroMusic)
JTemplateArray(SListenerRolloff,    ListenerAngleRolloff, UNKNOWN_SIZE)
JTemplateArray(SListenerRolloff,    ListenerDistanceRolloff, UNKNOWN_SIZE)
JTemplateArray(SLoadingBar,         LoadingBars, UNKNOWN_SIZE)
JTemplateArray(SLoadingScreenHelp,  LoadingScreenHelp, UNKNOWN_SIZE)
JTemplateArray(SLookAtType,         LookAtTypes, UNKNOWN_SIZE)
JTemplateValue(TID,                 LoopAmbience)
JTemplateValue(FIXF32,              MinCooldownDisplayDuration)
JTemplateValue(SMinimapData,        MinimapData)
JTemplateValue(FIXF32,              MinTimeDisplayDuration)
JTemplateArray(SUnitSpeedText,      MovementSpeedArray, UNKNOWN_SIZE)
JTemplateArray(SMovieConfig,        MovieArray, UNKNOWN_SIZE)
JTemplateArray(TID,                 MusicArray, UNKNOWN_SIZE)
JTemplateArray(SObjectGroupData,    ObjectGroupData, UNKNOWN_SIZE)
JTemplateEnumA(STeamColor,          OverrideColors, EOverrideColor)
JTemplateValue(INT32,               PlacementDisplayBonusRadius)
JTemplateValue(INT32,               PlacementDisplayMinimumRadius)
JTemplateValue(SColor,              PlacementErrorColor)
JTemplateValue(SVector2,            PlacementGridDimensions)
JTemplateValue(TID,                 PlanetPanelDefaultBackground)
JTemplateEnumA(SPointModel,         PointModels, EPointType)
JTemplateValue(INT32,               RadarAlpha)
JTemplateValue(NAME,                RandomRaceIcon)
JTemplateValue(INT32,               RegionNameSize)
JTemplateValue(SColor,              RequirementsSatisfiedColor)
JTemplateValue(SColor,              RequirementsUnsatisfiedColor)
JTemplateValue(INT32,               ScreenModeTransitionDuration)
JTemplateEnumA(SColor,              SelectionColors, ESelectionColor)
JTemplateValue(SSelectionData,      SelectionData)
JTemplateEnumA(SSoundData,          SoundData, ESoundCategory)
JTemplateArray(SSoundQuality,       SoundQuality, UNKNOWN_SIZE)
JTemplateValue(INT32,               StartupCampaign)
JTemplateValue(INT32,               StartupMovie)
JTemplateValue(INT32,               StartupMusic)
JTemplateValue(FIXF32,              TransmissionSoundDepth)
JTemplateValue(NAME,                TransmissionSoundRect)
JTemplateArray(STutorialConfig,     TutorialArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,              UnitDamageFlashDuration)
JTemplateValue(SCooldown,           UnitDamageNotificationCooldown)
JTemplateValue(FIXF32,              UnitDamageNotificationDelay)
JTemplateArray(SUnitKillRank,       UnitKillRank, UNKNOWN_SIZE)
JTemplateEnumA(SVitalColor,         VitalColors, EVitalColor)
JTemplateValue(FIXF32,              WayPointLineWidth)
JTemplateValue(FIXF32,              WayPointMultiUnitFadeAlpha)
JTemplateValue(FIXF32,              WayPointMultiUnitFadePoint)
JTemplateValue(FIXF32,              WayPointTileLength)
JTemplateArray(SWeaponSpeedText,    WeaponSpeedArray, UNKNOWN_SIZE)
JTemplateArray(SColor,              WireframeColorArray, UNKNOWN_SIZE)
JTemplateValue(INT32,               WorldConsoleBottom)
JTemplateValue(INT32,               WorldConsoleTop)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Item, TemplateRecord, Item)
JTemplateArray(TID,             CarryBehaviorArray, UNKNOWN_SIZE)
JTemplateArray(SUnitWeaponData, CarryWeaponArray, UNKNOWN_SIZE)
JTemplateValue(TID,             Class)
JTemplateValue(TID,             Container)
JTemplateArray(TID,             EquipBehaviorArray, UNKNOWN_SIZE)
JTemplateArray(SUnitWeaponData, EquipWeaponArray, UNKNOWN_SIZE)
JTemplateValue(TID,             Face)
JTemplateValue(EItemFlag,       Flags)
JTemplateValue(INT32,           Level)
JTemplateValue(TID,             Requirements)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ItemAbil, TemplateRecord, Item)
JTemplateValue(UNKNOWN_TYPE, Abil)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ItemClass, TemplateRecord, Item)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ItemContainer, TemplateRecord, Item)
JTemplateValue(TID,                Model)
JTemplateValue(INT32,              ModelHeight)
JTemplateValue(INT32,              ModelWidth)
JTemplateArray(SItemContainerSlot, Slots, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ItemEffect, Item, Item)
JTemplateValue(TID,             Effect)
JTemplateValue(SCost,           EffectCost)
JTemplateValue(EItemEffectFlag, EffectFlags)
JTemplateValue(FIXF32,          Range)
JTemplateValue(SCostFactor,     RefundFraction)
JTemplateValue(STargetFilters,  TargetFilters)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ItemEffectInstant, ItemEffect, Item)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ItemEffectTarget, ItemEffect, Item)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Light, TemplateRecord, Light)
JTemplateArray(STimeEvent,   TimeEventArray, UNKNOWN_SIZE)
JTemplateValue(STimeOfDay,   TimePerDay)
JTemplateValue(STimeOfDay,   TimePerLoop)
JTemplateValue(STimeOfDay,   TimeStart)
JTemplateValue(UNKNOWN_TYPE, ToDInfoArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Loot, TemplateRecord, Loot)
JTemplateArray(TID, ValidatorArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(LootEffect, Loot, Loot)
JTemplateValue(TID, Effect)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(LootSpawn, Loot, Loot)
JTemplateValue(EEffectLocation, SpawnLocation)
JTemplateValue(EEffectPlayer,   SpawnOwner)
JTemplateValue(FIXF32,          SpawnRange)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(LootItem, LootSpawn, Loot)
JTemplateArray(TID,   ClassArray, UNKNOWN_SIZE)
JTemplateValue(INT32, MaxLevel)
JTemplateValue(INT32, MinLevel)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(LootSet, Loot, Loot)
JTemplateArray(SLootChoice, ChildArray, UNKNOWN_SIZE)
JTemplateValue(INT32,       MaxCount)
JTemplateValue(INT32,       MinCount)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(LootUnit, Loot, Loot)
JTemplateValue(TID, Unit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Model, TemplateRecord, Model)
JTemplateValue(FIXF32,                 AnimBlendTime)
JTemplateValue(FIXF32,                 AnimSpeed)
JTemplateArray(SAttachProps,           AttachProps, UNKNOWN_SIZE)
JTemplateArray(SModelDataEvent,        Events, UNKNOWN_SIZE)
JTemplateValue(NAME,                   FacialController)
JTemplateValue(EModelFlag,             Flags)
JTemplateValue(NAME,                   Image)
JTemplateValue(TID,                    Lighting)
JTemplateValue(TID,                    LowQualityModel)
JTemplateValue(NAME,                   ModelLink)
JTemplateValue(EOcclusion,             Occlusion)
JTemplateArray(NAME,                   OptionalAnims, UNKNOWN_SIZE)
JTemplateValue(EModelPhysicsType,      PhysicsType)
JTemplateValue(NAME,                   PlanetPanelCamera)
JTemplateValue(INT32,                  Priority)
JTemplateValue(INT32,                  Quality)
JTemplateValue(FIXF32,                 Radius)
JTemplateValue(FIXF32,                 RadiusLoose)
JTemplateArray(NAME,                   RequiredAnims, UNKNOWN_SIZE)
JTemplateValue(SVector3,               ScaleMax)
JTemplateValue(SVector3,               ScaleMin)
JTemplateValue(INT32,                  SelectionLayer)
JTemplateValue(SVector3,               SelectionOffset)
JTemplateValue(FIXF32,                 SelectionRadius)
JTemplateValue(FIXF32,                 ShadowRadius)
JTemplateValue(ESquibType,             SquibTypeDefault)
JTemplateValue(NAME,                   TechPurchaseCamera)
JTemplateValue(FIXF32,                 TechPurchaseSpeed)
JTemplateArray(ETextureProp,           TextureAppliedGroups, UNKNOWN_SIZE)
JTemplateArray(STextureDeclare,        TextureDeclares, UNKNOWN_SIZE)
JTemplateArray(STextureExpressionSpec, TextureExpressionsForEditor, UNKNOWN_SIZE)
JTemplateArray(STextureInfo,           TextureInfos, UNKNOWN_SIZE)
JTemplateArray(STextureMatchSpec,      TextureMatchesForEditor, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                 Tipability)
JTemplateValue(FIXF32,                 TipabilityLength)
JTemplateValue(FIXF32,                 TipabilityWidth)
JTemplateValue(NAME,                   UnitGlossaryCamera)
JTemplateValue(INT32,                  UnitGlossaryVariation)
JTemplateValue(INT32,                  VariationCount)
JTemplateArray(SModelVariation,        Variations, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                 WaterHitDamping)
JTemplateValue(FIXF32,                 WaterHitFriction)
JTemplateValue(FIXF32,                 WaterHitMaxLinearVelocity)
JTemplateValue(FIXF32,                 WaterHitRestitution)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ModelFoliage, Model, Model)
JTemplateValue(FIXF32,        DragCoefficient)
JTemplateValue(FIXF32,        Flexibility)
JTemplateValue(bool,          ForceNormalsUp)
JTemplateValue(EFoliageLayer, Layer)
JTemplateValue(FIXF32,        RandomDeviation)
JTemplateValue(FIXF32,        SpringDampening)
JTemplateValue(FIXF32,        SpringStrength)
JTemplateValue(FIXF32,        WindInfluence)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Mover, TemplateRecord, Mover)
JTemplateValue(EHeightMap, HeightMap)
JTemplateValue(EPathMode,  PathMode)
JTemplateEnumA(EPath,      PlacementArray, EPlacement)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(MoverAvoid, Mover, Mover)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(MoverFlock, Mover, Mover)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(MoverMissile, Mover, Mover)
JTemplateArray(SMotionOverlay, MotionOverlays, UNKNOWN_SIZE)
JTemplateArray(SMotionPhase,   MotionPhases, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(MoverNull, Mover, Mover)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Race, TemplateRecord, Race)
JTemplateValue(NAME,          AttributeId)
JTemplateValue(TID,           DefeatSound)
JTemplateValue(ERaceFlag,     Flags)
JTemplateValue(INT32,         FoodCeiling)
JTemplateValue(TID,           GameMusic)
JTemplateValue(INT32,         GlossaryTeamColorIndex)
JTemplateValue(NAME,          Icon)
JTemplateValue(SColor,        MiniMapBorderColor)
JTemplateValue(EResourceType, ShowResource)
JTemplateEnumA(INT32,         StartingResource, EResourceType)
JTemplateValue(TID,           StartingUnitArray)
JTemplateValue(TID,           StartLocationAlert)
JTemplateValue(TID,           VictorySound)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Requirement, TemplateRecord, Requirement)
JTemplateArray(SRequirementNode, NodeArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementNode, TemplateRecord, Requirement)
JTemplateValue(ERequirementNodeFlag, Flags)
JTemplateValue(NAME,                 Tooltip)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementAllowAbil, RequirementNode, Requirement)
JTemplateValue(INT32, Index)
JTemplateValue(TID,   Link)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementAllowBehavior, RequirementNode, Requirement)
JTemplateValue(TID, Link)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementAllowUnit, RequirementNode, Requirement)
JTemplateValue(TID, Link)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementAllowUpgrade, RequirementNode, Requirement)
JTemplateValue(TID, Link)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementAnd, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementConst, RequirementNode, Requirement)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementCountAbil, RequirementNode, Requirement)
JTemplateValue(SRequirementCount, Count)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementCountBehavior, RequirementNode, Requirement)
JTemplateValue(SRequirementCount, Count)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementCountEffect, RequirementNode, Requirement)
JTemplateValue(SRequirementCount, Count)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementCountUnit, RequirementNode, Requirement)
JTemplateValue(SRequirementCount, Count)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementCountUpgrade, RequirementNode, Requirement)
JTemplateValue(SRequirementCount, Count)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementDiv, TemplateRecord, Requirement)
JTemplateValue(UNKNOWN_TYPE, OperandArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementEq, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementGT, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementGTE, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementLT, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementLTE, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementMod, TemplateRecord, Requirement)
JTemplateValue(UNKNOWN_TYPE, OperandArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementMul, TemplateRecord, Requirement)
JTemplateValue(UNKNOWN_TYPE, OperandArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementNE, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementNot, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementOdd, TemplateRecord, Requirement)
JTemplateValue(UNKNOWN_TYPE, OperandArray)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementOr, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementSum, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RequirementXor, RequirementNode, Requirement)
JTemplateArray(TID, OperandArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Reverb, TemplateRecord, Reverb)
JTemplateValue(FIXF32, DecayHFRatio)
JTemplateValue(FIXF32, DecayTime)
JTemplateValue(FIXF32, Density)
JTemplateValue(FIXF32, Diffusion)
JTemplateValue(FIXF32, HFReference)
JTemplateValue(FIXF32, LFReference)
JTemplateValue(INT32,  Reflections)
JTemplateValue(FIXF32, ReflectionsDelay)
JTemplateValue(INT32,  ReverbCount)
JTemplateValue(FIXF32, ReverbDelay)
JTemplateValue(INT32,  Room)
JTemplateValue(INT32,  RoomHF)
JTemplateValue(INT32,  RoomLF)
JTemplateValue(FIXF32, RoomRolloffFactor)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Reward, TemplateRecord, Reward)
JTemplateValue(SRewardCategory, Category)
JTemplateValue(ERewardFlag,     Flags)
JTemplateValue(INT32,           IconCols)
JTemplateValue(NAME,            IconFile)
JTemplateValue(INT32,           IconRows)
JTemplateValue(INT32,           IconSlot)
JTemplateValue(TID,             Race)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RewardDecal, Reward, Reward)
JTemplateValue(TID, Texture)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RewardIcon, Reward, Reward)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RewardModel, Reward, Reward)
JTemplateValue(TID, Model)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(RewardPortrait, Reward, Reward)
JTemplateValue(TID, Model)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreResult, TemplateRecord, ScoreResult)
JTemplateValue(EScoreResultFlag, Flags)
JTemplateValue(NAME,             Icon)
JTemplateValue(NAME,             PublishName)
JTemplateValue(INT32,            SortValue)
JTemplateValue(NAME,             Tooltip)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreResultBuildOrder, TemplateRecord, ScoreResult)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreResultGraph, TemplateRecord, ScoreResult)
JTemplateArray(TID, ValueTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreResultPane, TemplateRecord, ScoreResult)
JTemplateArray(TID, ValueTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreResultRoot, TemplateRecord, ScoreResult)
JTemplateArray(TID, HeaderTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreResultScore, TemplateRecord, ScoreResult)
JTemplateArray(TID, ValueTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreValue, TemplateRecord, ScoreValue)
JTemplateValue(EScoreValueFlag,   Flags)
JTemplateValue(NAME,              Icon)
JTemplateValue(NAME,              PublishName)
JTemplateValue(EScoreValueReport, Report)
JTemplateValue(EScoreSort,        Sort)
JTemplateValue(NAME,              Tooltip)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreValueCustom, ScoreValue, ScoreValue)
JTemplateValue(EScoreValueType, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreValueCombine, ScoreValueCustom, ScoreValue)
JTemplateValue(EScoreValueOperation, Operation)
JTemplateArray(TID,                  ValueTable, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ScoreValueStandard, ScoreValue, ScoreValue)
JTemplateValue(EScoreValue, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Sound, TemplateRecord, Sound)
JTemplateArray(SSoundAsset,       AssetArray, UNKNOWN_SIZE)
JTemplateValue(ESoundCategory,    Category)
JTemplateValue(INT32,             Chance)
JTemplateValue(SFloatRange,       ConeAngle)
JTemplateValue(SVector3,          ConeOrientation)
JTemplateValue(SFloatRange,       ConeVolume)
JTemplateValue(FIXF32,            DopplerLevel)
JTemplateValue(INT32,             DupeDestroyCount)
JTemplateValue(ESoundBlend,       DupeFadeBlend)
JTemplateArray(SVolumeFade,       DupeFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,       DupeFadeOut, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,      DupeHistoryCount)
JTemplateValue(ESoundDupe,        DupeMaximumMethod)
JTemplateValue(INT32,             DupeMuteCount)
JTemplateValue(INT32,             DupeRepeatCount)
JTemplateValue(INT32,             DupeThresholdFadeTime)
JTemplateArray(SVolumeThreshold,  DupeThresholdPoints, UNKNOWN_SIZE)
JTemplateValue(SIntRange,         DupeWait)
JTemplateValue(ESoundFlag,        Flags)
JTemplateValue(ESoundBlend,       FogFadeBlend)
JTemplateArray(SVolumeFade,       FogFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,       FogFadeOut, UNKNOWN_SIZE)
JTemplateValue(SSoundLocaleFlags, LocaleFlags)
JTemplateValue(INT32,             LoopCount)
JTemplateValue(FIXF32,            LowPassGain)
JTemplateValue(ESoundMode,        Mode)
JTemplateValue(ESoundBlend,       MuteFadeBlend)
JTemplateArray(SVolumeFade,       MuteFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,       MuteFadeOut, UNKNOWN_SIZE)
JTemplateValue(SFloatRange,       OcclusionDirect)
JTemplateValue(SFloatRange,       OcclusionReverb)
JTemplateValue(ESoundBlend,       OffsetFadeBlend)
JTemplateArray(SVolumeFade,       OffsetFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,       OffsetFadeOut, UNKNOWN_SIZE)
JTemplateValue(ESoundBlend,       OffsetShiftBlend)
JTemplateArray(SPitchShift,       OffsetShiftIn, UNKNOWN_SIZE)
JTemplateArray(SPitchShift,       OffsetShiftOut, UNKNOWN_SIZE)
JTemplateValue(FIXF32,            OverlapPitchDelta)
JTemplateValue(INT32,             OverlapTimeDelta)
JTemplateValue(SFloatRange,       Pan)
JTemplateValue(FIXF32,            PanLevel)
JTemplateValue(SFloatRange,       Pitch)
JTemplateValue(TID,               Race)
JTemplateValue(INT32,             ResourcePriority)
JTemplateValue(SReverbBalance,    ReverbBalance)
JTemplateValue(ESoundBlend,       ReverbRolloffBlend)
JTemplateArray(SReverbRolloff,    ReverbRolloffPoints, UNKNOWN_SIZE)
JTemplateValue(ESoundSelect,      Select)
JTemplateEnumA(FIXF32,            SpeakerMix, ESpeaker)
JTemplateValue(FIXF32,            Spread)
JTemplateArray(SVolumeFade,       SustainFade, UNKNOWN_SIZE)
JTemplateValue(ESoundBlend,       SustainFadeBlend)
JTemplateValue(INT32,             VariationMinimum)
JTemplateValue(SFloatRange,       Volume)
JTemplateValue(ESoundBlend,       VolumeRolloffBlend)
JTemplateValue(ESoundBlend,       VolumeRolloffFadeBlend)
JTemplateArray(SVolumeFade,       VolumeRolloffFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,       VolumeRolloffFadeOut, UNKNOWN_SIZE)
JTemplateArray(SVolumeRolloff,    VolumeRolloffPoints, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Soundtrack, TemplateRecord, Sound)
JTemplateArray(SSoundtrackCue,  CueArray, UNKNOWN_SIZE)
JTemplateValue(SIntRange,       Delay)
JTemplateValue(ESoundtrackFlag, Flags)
JTemplateValue(TID,             Next)
JTemplateValue(ESoundSelect,    Select)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Tactical, TemplateRecord, Tactical)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TacticalOrder, Tactical, Tactical)
JTemplateValue(TID,     Abil)
JTemplateValue(INT32,   AbilCmdIndex)
JTemplateValue(SMarker, Marker)
JTemplateValue(bool,    Retreat)
JTemplateValue(TID,     TargetFind)
JTemplateValue(TID,     Validator)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TacticalSet, Tactical, Tactical)
JTemplateArray(TID, Array, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFind, TemplateRecord, TargetFind)
JTemplateValue(TID,             CasterValidator)
JTemplateValue(ETargetFindFlag, Flags)
JTemplateValue(STargetFilters,  TargetFilters)
JTemplateValue(TID,             TargetValidator)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindBestPoint, TargetFind, TargetFind)
JTemplateValue(EUnitAttributes, BonusAttri)
JTemplateValue(FIXF32,          DamageBase)
JTemplateValue(TID,             Effect)
JTemplateValue(INT32,           MinCount)
JTemplateValue(FIXF32,          MinScore)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindEffect, TargetFind, TargetFind)
JTemplateValue(TID,          Effect)
JTemplateValue(FIXF32,       ExtendRadius)
JTemplateValue(STargetSorts, TargetSorts)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindEnumArea, TargetFind, TargetFind)
JTemplateValue(TID,                  Abil)
JTemplateArray(STargetFindEnumArea,  AreaArray, UNKNOWN_SIZE)
JTemplateArray(SEffectWhichUnit,     ExcludeArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,               ExtendRadius)
JTemplateValue(SEffectWhichLocation, ImpactLocation)
JTemplateArray(SEffectWhichUnit,     IncludeArray, UNKNOWN_SIZE)
JTemplateValue(SEffectWhichLocation, LaunchLocation)
JTemplateValue(INT32,                MaxCount)
JTemplateValue(INT32,                MinCount)
JTemplateValue(SError,               MinCountError)
JTemplateValue(INT32,                RecycleCount)
JTemplateValue(STargetFilters,       SearchFilters)
JTemplateValue(EEffectSearchFlag,    SearchFlags)
JTemplateValue(STargetSorts,         TargetSorts)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindLastAttacker, TargetFind, TargetFind)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindOffset, TargetFind, TargetFind)
JTemplateValue(FIXF32,      Angle)
JTemplateValue(SFloatRange, Distance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindOrder, TargetFind, TargetFind)
JTemplateValue(TID,   Abil)
JTemplateValue(INT32, AbilCmdIndex)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindRallyPoint, TargetFind, TargetFind)
JTemplateValue(INT32, CommandIndex)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindSet, TargetFind, TargetFind)
JTemplateArray(TID,            Array, UNKNOWN_SIZE)
JTemplateValue(ETargetFindSet, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetFindWorkerRallyPoint, TargetFind, TargetFind)
JTemplateValue(INT32, CommandIndex)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSort, TemplateRecord, TargetSort)
JTemplateValue(bool,             Descending)
JTemplateValue(SEffectWhichUnit, WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortAlliance, TargetSort, TargetSort)
JTemplateValue(EAllianceId,        Alliance)
JTemplateValue(SEffectWhichPlayer, WithPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortAngle, TargetSort, TargetSort)
JTemplateValue(SEffectWhichLocation, ImpactLocation)
JTemplateValue(SEffectWhichLocation, LaunchLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortBehaviorCount, TargetSort, TargetSort)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortBehaviorDuration, TargetSort, TargetSort)
JTemplateValue(TID,    Behavior)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortChargeCount, TargetSort, TargetSort)
JTemplateValue(TID,    Ability)
JTemplateArray(NAME,   Charge, UNKNOWN_SIZE)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortChargeRegen, TargetSort, TargetSort)
JTemplateValue(TID,    Ability)
JTemplateArray(NAME,   Charge, UNKNOWN_SIZE)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortCooldown, TargetSort, TargetSort)
JTemplateValue(TID,    Ability)
JTemplateArray(NAME,   Cooldown, UNKNOWN_SIZE)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortDistance, TargetSort, TargetSort)
JTemplateValue(SEffectWhichLocation, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortField, TargetSort, TargetSort)
JTemplateValue(NAME, Field)
JTemplateValue(NAME, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortMarker, TargetSort, TargetSort)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortPowerSourceLevel, TargetSort, TargetSort)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortPowerUserLevel, TargetSort, TargetSort)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortPriority, TargetSort, TargetSort)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortRandom, TargetSort, TargetSort)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortVeterancy, TargetSort, TargetSort)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortVital, TargetSort, TargetSort)
JTemplateValue(FIXF32,     Value)
JTemplateValue(EUnitVital, Vital)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TargetSortVitalFraction, TargetSort, TargetSort)
JTemplateValue(FIXF32,     Value)
JTemplateValue(EUnitVital, Vital)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Terrain, TemplateRecord, Terrain)
JTemplateValue(TID,                      Ambience)
JTemplateArray(TID,                      BlendTextures, UNKNOWN_SIZE)
JTemplateValue(TID,                      Camera)
JTemplateArray(TID,                      CliffSets, UNKNOWN_SIZE)
JTemplateValue(NAME,                     CreepBaseSpecularMap)
JTemplateValue(NAME,                     CreepBaseTexture)
JTemplateValue(NAME,                     CreepEdgeNormalMap)
JTemplateValue(NAME,                     CreepHeightMap)
JTemplateValue(NAME,                     CreepNoiseMap)
JTemplateEnumA(SCreepSettings,           CreepSettingsArray, EGraphicsLevel)
JTemplateEnumA(TID,                      DSPArray, ESoundCategory)
JTemplateValue(NAME,                     EnvironmentMap)
JTemplateValue(TID,                      FixedSkyboxModel)
JTemplateValue(SColor,                   FogColor)
JTemplateValue(FIXF32,                   FogDensity)
JTemplateValue(FIXF32,                   FogDistanceFalloff)
JTemplateValue(bool,                     FogEnabled)
JTemplateValue(FIXF32,                   FogFalloff)
JTemplateValue(FIXF32,                   FogFarPlane)
JTemplateValue(FIXF32,                   FogNearPlane)
JTemplateValue(FIXF32,                   FogStartingHeight)
JTemplateEnumA(SFoliageSimulationConfig, FoliageSettingsArray, EGraphicsLevel)
JTemplateValue(FIXF32,                   Gravity)
JTemplateArray(TID,                      HardTiles, UNKNOWN_SIZE)
JTemplateValue(bool,                     HideLowestLevel)
JTemplateValue(TID,                      Lighting)
JTemplateValue(NAME,                     LoadingScreen)
JTemplateValue(SColor,                   MinimapBackgroundColor)
JTemplateValue(TID,                      NonFixedSkyboxModel)
JTemplateValue(FIXF32,                   POMScale)
JTemplateValue(TID,                      ReverbAmbient)
JTemplateValue(TID,                      ReverbGlobal)
JTemplateValue(FIXF32,                   SoundDistanceFactor)
JTemplateValue(FIXF32,                   SoundDopplerFactor)
JTemplateValue(FIXF32,                   SoundRolloffFactor)
JTemplateValue(FIXF32,                   TilingFreq)
JTemplateValue(FIXF32,                   WindAngleHorizontal)
JTemplateValue(FIXF32,                   WindAngleVertical)
JTemplateValue(FIXF32,                   WindSpeed)
JTemplateValue(FIXF32,                   WindTurbulencePower)
JTemplateValue(FIXF32,                   WindTurbulenceSpeed)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TerrainObject, TemplateRecord, Terrain)
JTemplateValue(FIXF32,      EditorCursorOffset)
JTemplateValue(EEditorFlag, EditorFlags)
JTemplateValue(NAME,        EditorIcon)
JTemplateValue(TID,         EditorModel)
JTemplateValue(TID,         Footprint)
JTemplateValue(TID,         Model)
JTemplateValue(FIXF32,      OccludeHeight)
JTemplateValue(FIXF32,      Radius)
JTemplateArray(TID,         TexSets, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(CliffDoodad, TerrainObject, Cliff)
JTemplateValue(TID,   CliffSet)
JTemplateArray(NAME,  HeightCodes, UNKNOWN_SIZE)
JTemplateValue(INT32, NumCellsAcross)
JTemplateValue(INT32, NumCellsDown)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(TerrainTex, TemplateRecord, Terrain)
JTemplateValue(SVector2,       AnimRate)
JTemplateArray(STerrainDoodad, DoodadEntry, UNKNOWN_SIZE)
JTemplateValue(NAME,           EditorIcon)
JTemplateValue(NAME,           Normalmap)
JTemplateValue(EPath,          Pathing)
JTemplateValue(NAME,           Texture)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Texture, TemplateRecord, Texture)
JTemplateValue(NAME,         File)
JTemplateValue(TID,          MovieSoundSettings)
JTemplateValue(NAME,         Prefix)
JTemplateArray(ETextureProp, PropsAdd, UNKNOWN_SIZE)
JTemplateArray(ETextureProp, PropsRemove, UNKNOWN_SIZE)
JTemplateArray(ETextureProp, PropsSet, UNKNOWN_SIZE)
JTemplateValue(NAME,         Slot)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Tile, TemplateRecord, Tile)
JTemplateValue(FIXF32,           CapLength)
JTemplateValue(FIXF32,           DefaultSplineWidth)
JTemplateValue(FIXF32,           DefaultWingWidth)
JTemplateValue(NAME,             EditorIcon)
JTemplateValue(ETerrainTileFlag, Flags)
JTemplateValue(NAME,             Material)
JTemplateValue(FIXF32,           TesselationDistance)
JTemplateValue(INT32,            TileHeightRepetitions)
JTemplateValue(FIXF32,           TileWidthDistance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Turret, TemplateRecord, Turret)
JTemplateValue(SFidget,     Fidget)
JTemplateValue(ETurretIdle, Idle)
JTemplateValue(FIXF32,      YawArc)
JTemplateValue(FIXF32,      YawIdleRate)
JTemplateValue(FIXF32,      YawRate)
JTemplateValue(FIXF32,      YawStart)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Unit, TemplateRecord, Unit)
JTemplateArray(SUnitAbilData,         AbilArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                Acceleration)
JTemplateArray(SAddedOnData,          AddedOnArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                AddOnOffsetX)
JTemplateValue(FIXF32,                AddOnOffsetY)
JTemplateValue(FIXF32,                AIEvalConstant)
JTemplateValue(FIXF32,                AIEvalFactor)
JTemplateValue(TID,                   AIEvaluateAlias)
JTemplateValue(TID,                   AINotifyEffect)
JTemplateValue(INT32,                 AIOverideTargetPriority)
JTemplateValue(INT32,                 AttackTargetPriority)
JTemplateValue(EUnitAttributes,       Attributes)
JTemplateArray(SUnitBehaviorData,     BehaviorArray, UNKNOWN_SIZE)
JTemplateValue(EBuildCategoryAI,      BuildCatAI)
JTemplateValue(TID,                   BuiltOn)
JTemplateArray(SCardLayout,           CardLayouts, UNKNOWN_SIZE)
JTemplateValue(INT32,                 CargoSize)
JTemplateValue(EUnitCollide,          Collide)
JTemplateValue(ECostCategory,         CostCategory)
JTemplateEnumA(INT32,                 CostResource, EResourceType)
JTemplateValue(INT32,                 DamageDealtXP)
JTemplateValue(INT32,                 DamageTakenXP)
JTemplateValue(TID,                   DeadFootprint)
JTemplateValue(FIXF32,                DeadRadius)
JTemplateValue(FIXF32,                DeathRevealDuration)
JTemplateValue(FIXF32,                DeathRevealRadius)
JTemplateValue(UNKNOWN_TYPE,          DeathRevealType)
JTemplateValue(FIXF32,                DeathTime)
JTemplateValue(FIXF32,                Deceleration)
JTemplateValue(EAcquireLevel,         DefaultAcquireLevel)
JTemplateValue(NAME,                  Description)
JTemplateValue(EEditorFlag,           EditorFlags)
JTemplateEnumA(FIXF32,                EnergyDamageGain, EDamageKind)
JTemplateEnumA(FIXF32,                EnergyDamageLeech, EDamageKind)
JTemplateValue(FIXF32,                EnergyMax)
JTemplateValue(FIXF32,                EnergyRegenDelay)
JTemplateValue(FIXF32,                EnergyRegenRate)
JTemplateValue(FIXF32,                EnergyStart)
JTemplateArray(SUnitEquipment,        EquipmentArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                Facing)
JTemplateValue(SFidget,               Fidget)
JTemplateValue(EUnitFlag,             FlagArray)
JTemplateValue(EFogVisibility,        FogVisibility)
JTemplateValue(FIXF32,                Food)
JTemplateValue(TID,                   Footprint)
JTemplateValue(TID,                   GlossaryAlias)
JTemplateValue(NAME,                  GlossaryCategory)
JTemplateValue(INT32,                 GlossaryPriority)
JTemplateArray(TID,                   GlossaryStrongArray, UNKNOWN_SIZE)
JTemplateArray(TID,                   GlossaryWeakArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                Height)
JTemplateValue(UNKNOWN_TYPE,          HotkeyAlias)
JTemplateValue(UNKNOWN_TYPE,          HotkeyCategory)
JTemplateValue(INT32,                 InfoTooltipPriority)
JTemplateValue(FIXF32,                InnerRadius)
JTemplateValue(TID,                   Item)
JTemplateValue(EKillDisplay,          KillDisplay)
JTemplateEnumA(INT32,                 KillResource, EResourceType)
JTemplateValue(INT32,                 KillXP)
JTemplateValue(FIXF32,                LateralAcceleration)
JTemplateValue(TID,                   LeaderAlias)
JTemplateValue(FIXF32,                LifeArmor)
JTemplateValue(EEquipmentDisplayFlag, LifeArmorDisplayFlags)
JTemplateValue(INT32,                 LifeArmorLevel)
JTemplateValue(NAME,                  LifeArmorName)
JTemplateEnumA(FIXF32,                LifeDamageGain, EDamageKind)
JTemplateEnumA(FIXF32,                LifeDamageLeech, EDamageKind)
JTemplateValue(FIXF32,                LifeMax)
JTemplateValue(FIXF32,                LifeRegenDelay)
JTemplateValue(FIXF32,                LifeRegenRate)
JTemplateValue(FIXF32,                LifeStart)
JTemplateArray(TID,                   LootArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                Mass)
JTemplateValue(FIXF32,                MinimapRadius)
JTemplateValue(EUnitMob,              Mob)
JTemplateValue(TID,                   Mover)
JTemplateValue(FIXF32,                OccludeHeight)
JTemplateValue(FIXF32,                PawnItemReduction)
JTemplateValue(TID,                   PlacementFootprint)
JTemplateValue(EPlane,                PlaneArray)
JTemplateValue(SCost,                 PowerupCost)
JTemplateValue(TID,                   PowerupEffect)
JTemplateValue(STargetFilters,        PowerupFilters)
JTemplateValue(FIXF32,                PushPriority)
JTemplateValue(TID,                   Race)
JTemplateValue(FIXF32,                Radius)
JTemplateValue(FIXF32,                RepairTime)
JTemplateValue(EResourceType,         ResourceDropOff)
JTemplateValue(EResourceState,        ResourceState)
JTemplateValue(EResourceType,         ResourceType)
JTemplateValue(EUnitResponse,         Response)
JTemplateValue(FIXF32,                ReviveDelay)
JTemplateValue(FIXF32,                ReviveTime)
JTemplateValue(TID,                   ReviveType)
JTemplateValue(INT32,                 ScoreKill)
JTemplateValue(INT32,                 ScoreLost)
JTemplateValue(INT32,                 ScoreMake)
JTemplateValue(TID,                   ScoreResult)
JTemplateValue(TID,                   SelectAlias)
JTemplateValue(FIXF32,                SeparationRadius)
JTemplateValue(FIXF32,                ShieldArmor)
JTemplateValue(EEquipmentDisplayFlag, ShieldArmorDisplayFlags)
JTemplateValue(INT32,                 ShieldArmorLevel)
JTemplateValue(NAME,                  ShieldArmorName)
JTemplateEnumA(FIXF32,                ShieldDamageGain, EDamageKind)
JTemplateEnumA(FIXF32,                ShieldDamageLeech, EDamageKind)
JTemplateValue(FIXF32,                ShieldRegenDelay)
JTemplateValue(FIXF32,                ShieldRegenRate)
JTemplateValue(FIXF32,                ShieldsMax)
JTemplateValue(FIXF32,                ShieldsStart)
JTemplateValue(FIXF32,                Sight)
JTemplateEnumA(FIXF32,                SightBonus, ESightType)
JTemplateValue(FIXF32,                Speed)
JTemplateValue(FIXF32,                SpeedBonusCreep)
JTemplateValue(EEquipmentDisplayFlag, SpeedDisplayFlags)
JTemplateValue(FIXF32,                SpeedMultiplierCreep)
JTemplateValue(FIXF32,                StationaryTurningRate)
JTemplateValue(FIXF32,                StrafeRadius)
JTemplateValue(TID,                   SubgroupAlias)
JTemplateValue(INT32,                 SubgroupPriority)
JTemplateValue(NAME,                  SyncModelData)
JTemplateValue(TID,                   TacticalAI)
JTemplateValue(NAME,                  TacticalAIChannel)
JTemplateValue(STargetFilters,        TacticalAIFilters)
JTemplateValue(NAME,                  TacticalAIRange)
JTemplateValue(NAME,                  TacticalAIThink)
JTemplateEnumA(FIXF32,                TauntDuration, EUnitTaunt)
JTemplateArray(NAME,                  TechAliasArray, UNKNOWN_SIZE)
JTemplateArray(TID,                   TechTreeUnlockedUnitArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                TurningRate)
JTemplateArray(TID,                   TurretArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                VisionHeight)
JTemplateArray(SUnitWeaponData,       WeaponArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Upgrade, TemplateRecord, Upgrade)
JTemplateArray(TID,                  AffectedUnitArray, UNKNOWN_SIZE)
JTemplateValue(TID,                  Alert)
JTemplateArray(SUpgradeEffect,       EffectArray, UNKNOWN_SIZE)
JTemplateValue(EUpgradeFlag,         Flags)
JTemplateValue(NAME,                 Icon)
JTemplateValue(INT32,                InfoTooltipPriority)
JTemplateValue(INT32,                MaxLevel)
JTemplateValue(TID,                  Race)
JTemplateValue(INT32,                ScoreAmount)
JTemplateValue(EScoreValue,          ScoreCount)
JTemplateValue(EClassIdCScoreResult, ScoreResult)
JTemplateValue(EScoreValue,          ScoreValue)
JTemplateArray(NAME,                 TechAliasArray, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,         WebPriority)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Validator, TemplateRecord, Validator)
JTemplateValue(INT32,  IgnoreWhileChanneling)
JTemplateValue(SError, ResultFailed)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorCombine, Validator, Validator)
JTemplateArray(TID,              CombineArray, UNKNOWN_SIZE)
JTemplateValue(bool,             Negate)
JTemplateValue(EValidateCombine, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorCondition, Validator, Validator)
JTemplateValue(TID,                 Else)
JTemplateArray(SValidatorCondition, IfArray, UNKNOWN_SIZE)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorFunction, Validator, Validator)
JTemplateArray(SValidatorFunction, Line, UNKNOWN_SIZE)
JTemplateValue(SError,             ResultFallback)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorGameCompareTerrain, Validator, Validator)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(TID,           Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorGameCompareTimeOfDay, Validator, Validator)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(STimeOfDay,    Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocation, Validator, Validator)
JTemplateValue(SEffectWhichLocation, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationArc, ValidatorLocation, Validator)
JTemplateValue(FIXF32,               Arc)
JTemplateValue(bool,                 Find)
JTemplateValue(SEffectWhichLocation, OtherLocation)
JTemplateValue(SEffectWhichLocation, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationCompareCliffLevel, ValidatorLocation, Validator)
JTemplateValue(EValueCompare,        Compare)
JTemplateValue(SEffectWhichLocation, OtherLocation)
JTemplateValue(INT32,                Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationComparePower, ValidatorLocation, Validator)
JTemplateValue(EValueCompare,      Compare)
JTemplateValue(NAME,               PowerLink)
JTemplateArray(TID,                PowerSource, UNKNOWN_SIZE)
JTemplateValue(INT32,              Value)
JTemplateValue(SEffectWhichPlayer, WhichPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationCompareRange, ValidatorLocation, Validator)
JTemplateValue(EValueCompare,        Compare)
JTemplateValue(bool,                 Pathing)
JTemplateValue(FIXF32,               Range)
JTemplateValue(SEffectWhichLocation, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationCreep, ValidatorLocation, Validator)
JTemplateValue(bool, Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationCrossCliff, TemplateRecord, Validator)
JTemplateValue(UNKNOWN_TYPE, Find)
JTemplateValue(UNKNOWN_TYPE, OtherLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationEnumArea, ValidatorLocation, Validator)
JTemplateArray(SValidatorEnumArea,   AreaArray, UNKNOWN_SIZE)
JTemplateValue(NAME,                 CachedSearch)
JTemplateValue(EUnitVital,           CombinedVital)
JTemplateValue(EValueCompare,        CombinedVitalCompare)
JTemplateValue(SEffectWhichUnit,     CombinedVitalUnit)
JTemplateValue(INT32,                CombinedVitalValue)
JTemplateValue(EValueCompare,        Compare)
JTemplateValue(INT32,                Count)
JTemplateArray(SEffectWhichUnit,     ExcludeArray, UNKNOWN_SIZE)
JTemplateArray(SEffectWhichUnit,     IncludeArray, UNKNOWN_SIZE)
JTemplateValue(SEffectWhichLocation, LaunchLocation)
JTemplateValue(STargetFilters,       SearchFilters)
JTemplateValue(EEffectSearchFlag,    SearchFlags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationPathable, ValidatorLocation, Validator)
JTemplateValue(bool, Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationPlacement, ValidatorLocation, Validator)
JTemplateValue(SEffectWhichUnit, FromUnit)
JTemplateValue(SEffectWhichUnit, OtherUnit)
JTemplateValue(FIXF32,           Range)
JTemplateValue(TID,              Unit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationType, ValidatorLocation, Validator)
JTemplateValue(TID, None)
JTemplateValue(TID, Point)
JTemplateValue(TID, Unit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorLocationVision, ValidatorLocation, Validator)
JTemplateValue(bool,               Find)
JTemplateValue(SEffectWhichPlayer, WhichPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayer, Validator, Validator)
JTemplateValue(SEffectWhichPlayer, OtherPlayer)
JTemplateValue(SError,             ResultNoPlayer)
JTemplateValue(SEffectWhichPlayer, WhichPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerAlliance, ValidatorPlayer, Validator)
JTemplateValue(bool,               Find)
JTemplateValue(EAllianceId,        Value)
JTemplateValue(SEffectWhichPlayer, WithPlayer)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompare, ValidatorPlayer, Validator)
JTemplateValue(EValueCompare, Compare)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareDifficulty, ValidatorPlayerCompare, Validator)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareFoodAvailable, ValidatorPlayerCompare, Validator)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareFoodMade, ValidatorPlayerCompare, Validator)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareFoodUsed, ValidatorPlayerCompare, Validator)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareRace, ValidatorPlayerCompare, Validator)
JTemplateValue(TID, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareResource, ValidatorPlayerCompare, Validator)
JTemplateValue(EResourceType, Resource)
JTemplateValue(INT32,         Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareResult, ValidatorPlayerCompare, Validator)
JTemplateValue(EGameResult, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerCompareType, ValidatorPlayerCompare, Validator)
JTemplateValue(EPlayerType, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorPlayerRequirement, ValidatorPlayer, Validator)
JTemplateValue(bool, Find)
JTemplateValue(TID,  Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnit, Validator, Validator)
JTemplateValue(SEffectWhichUnit, OtherUnit)
JTemplateValue(SError,           ResultNoUnit)
JTemplateValue(SEffectWhichUnit, WhichUnit)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitAbil, ValidatorUnit, Validator)
JTemplateValue(EClassIdCAbil, AbilClass)
JTemplateValue(TID,           AbilLink)
JTemplateValue(bool,          Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitAI, ValidatorUnit, Validator)
JTemplateValue(bool,        Find)
JTemplateValue(EUnitAIFlag, Flag)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitBehaviorState, ValidatorUnit, Validator)
JTemplateValue(EBehaviorState, BehaviorState)
JTemplateValue(bool,           Enabled)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCombatAI, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompare, ValidatorUnit, Validator)
JTemplateValue(EValueCompare, Compare)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareAIAreaEvalRatio, ValidatorUnitCompare, Validator)
JTemplateValue(FIXF32, Radius)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareAttackPriority, ValidatorUnitCompare, Validator)
JTemplateValue(SEffectWhichUnit, Attacker)
JTemplateValue(TID,              AttackerAlternateType)
JTemplateValue(EAttackPriority,  Flags)
JTemplateValue(INT32,            Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareBehaviorCount, ValidatorUnitCompare, Validator)
JTemplateValue(TID,           Behavior)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(INT32,         Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareCargo, ValidatorUnitCompare, Validator)
JTemplateValue(ECargoSpace, Type)
JTemplateValue(INT32,       Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareDamageTakenTime, ValidatorUnitCompare, Validator)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareDeath, ValidatorUnitCompare, Validator)
JTemplateValue(EDeathType, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareDetectRange, ValidatorUnitCompare, Validator)
JTemplateValue(bool,   Radar)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareField, ValidatorUnitCompare, Validator)
JTemplateValue(NAME, Field)
JTemplateValue(NAME, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareMarkerCount, ValidatorUnitCompare, Validator)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareMoverPhase, ValidatorUnitCompare, Validator)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareOrderCount, ValidatorUnitCompare, Validator)
JTemplateValue(INT32, AbilCmdIndex)
JTemplateValue(TID,   AbilLink)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareOrderTargetRange, ValidatorUnitCompare, Validator)
JTemplateValue(INT32,  AbilCmdIndex)
JTemplateValue(TID,    AbilLink)
JTemplateValue(bool,   Pathing)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitComparePowerSourceLevel, ValidatorUnitCompare, Validator)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitComparePowerUserLevel, ValidatorUnitCompare, Validator)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareRallyPointCount, ValidatorUnitCompare, Validator)
JTemplateValue(TID,   AbilLink)
JTemplateValue(INT32, Point)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareResourceContents, ValidatorUnitCompare, Validator)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareResourceHarvesters, ValidatorUnitCompare, Validator)
JTemplateValue(bool,  Active)
JTemplateValue(TID,   Behavior)
JTemplateValue(bool,  Queued)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareSpeed, ValidatorUnitCompare, Validator)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareVeterancyLevel, ValidatorUnitCompare, Validator)
JTemplateValue(TID,   Behavior)
JTemplateValue(INT32, Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareVital, ValidatorUnitCompare, Validator)
JTemplateValue(EVitalType, Type)
JTemplateValue(FIXF32,     Value)
JTemplateValue(EUnitVital, Vital)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitCompareVitality, ValidatorUnitCompare, Validator)
JTemplateValue(EVitalType, Type)
JTemplateValue(FIXF32,     Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitDetected, ValidatorUnit, Validator)
JTemplateValue(bool,        Detected)
JTemplateValue(EDetectType, Flags)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitFilters, ValidatorUnit, Validator)
JTemplateValue(STargetFilters, Filters)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitLastDamagePlayer, ValidatorUnit, Validator)
JTemplateValue(EPlayerRelationship, Relationship)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitMissileNullified, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitMover, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateValue(TID,  Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitOrder, ValidatorUnit, Validator)
JTemplateValue(INT32,                AbilCmdIndex)
JTemplateValue(TID,                  AbilLink)
JTemplateValue(SEffectWhichLocation, Target)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitOrderQueue, ValidatorUnit, Validator)
JTemplateValue(INT32,                AbilCmdIndex)
JTemplateValue(TID,                  AbilLink)
JTemplateValue(bool,                 Find)
JTemplateValue(bool,                 Queued)
JTemplateValue(SEffectWhichLocation, Target)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitOrderTargetPathable, ValidatorUnit, Validator)
JTemplateValue(INT32,  AbilCmdIndex)
JTemplateValue(TID,    AbilLink)
JTemplateValue(bool,   Find)
JTemplateValue(FIXF32, MaxDistance)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitOrderTargetType, ValidatorUnit, Validator)
JTemplateValue(INT32,               AbilCmdIndex)
JTemplateValue(TID,                 AbilLink)
JTemplateValue(bool,                Find)
JTemplateValue(EEffectLocationType, Type)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitPathable, TemplateRecord, Validator)
JTemplateValue(UNKNOWN_TYPE, Find)
JTemplateValue(UNKNOWN_TYPE, MaxDistance)
JTemplateValue(UNKNOWN_TYPE, Range)
JTemplateValue(UNKNOWN_TYPE, WhichLocation)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitPathing, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitScanning, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitType, ValidatorUnit, Validator)
JTemplateValue(bool,      Find)
JTemplateValue(EUnitType, Type)
JTemplateValue(TID,       Value)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitWeaponAnimating, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateValue(TID,  Weapon)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitWeaponFiring, ValidatorUnit, Validator)
JTemplateValue(bool, Find)
JTemplateValue(TID,  Weapon)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(ValidatorUnitWeaponPlane, ValidatorUnit, Validator)
JTemplateValue(bool,   Find)
JTemplateValue(EPlane, Plane)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Water, TemplateRecord, Water)
JTemplateValue(TID,             BeachShoreline)
JTemplateValue(FIXF32,          CausticsFPS)
JTemplateValue(SVector2,        CausticsTilingFreq)
JTemplateValue(TID,             CliffShoreline)
JTemplateArray(SWaterDoodad,    Doodads, UNKNOWN_SIZE)
JTemplateValue(FIXF32,          FramesPerSec)
JTemplateValue(bool,            IsLava)
JTemplateValue(TID,             LavaModel)
JTemplateValue(bool,            ReceiveShadows)
JTemplateValue(SVector4,        ScrollVectors)
JTemplateValue(TID,             Sound)
JTemplateValue(SWaterStateDesc, State)
JTemplateValue(NAME,            TextureKey)
JTemplateValue(FIXF32,          TilingFreq)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(Weapon, TemplateRecord, Weapon)
JTemplateValue(STargetFilters,        AcquireFilters)
JTemplateValue(EWeaponPrioritization, AcquirePrioritization)
JTemplateValue(STargetSorts,          AcquireTargetSorts)
JTemplateValue(FIXF32,                Arc)
JTemplateValue(FIXF32,                ArcSlop)
JTemplateValue(FIXF32,                Backswing)
JTemplateValue(STargetFilters,        ChaseFilters)
JTemplateValue(SCost,                 Cost)
JTemplateValue(FIXF32,                DamagePoint)
JTemplateValue(INT32,                 DisplayAttackCount)
JTemplateValue(TID,                   DisplayEffect)
JTemplateValue(NAME,                  Icon)
JTemplateValue(INT32,                 InfoTooltipPriority)
JTemplateValue(INT32,                 Level)
JTemplateValue(SMarker,               Marker)
JTemplateValue(FIXF32,                MinimumRange)
JTemplateValue(FIXF32,                MinScanRange)
JTemplateValue(EWeaponOption,         Options)
JTemplateValue(FIXF32,                Period)
JTemplateValue(EEquipmentDisplayFlag, PeriodDisplayFlags)
JTemplateValue(FIXF32,                Range)
JTemplateValue(EEquipmentDisplayFlag, RangeDisplayFlags)
JTemplateValue(FIXF32,                RangeSlop)
JTemplateValue(STargetFilters,        TargetFilters)
JTemplateValue(NAME,                  Tip)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(WeaponLegacy, Weapon, Weapon)
JTemplateValue(EWeaponLegacyMovement, AllowedMovement)
JTemplateValue(TID,                   Effect)
JTemplateValue(EWeaponLegacyOption,   LegacyOptions)
JTemplateValue(TID,                   PathingAmmoUnit)
JTemplateValue(FIXF32,                RandomDelayMax)
JTemplateValue(FIXF32,                RandomDelayMin)
JTemplateValue(FIXF32,                ReloadDuration)
JTemplateEnd()

//-------------------------------------------------------------------------------------
JTemplateClass(WeaponStrafe, Weapon, Weapon)
JTemplateValue(TID,    Effect)
JTemplateValue(FIXF32, LoiterRadius)
JTemplateEnd()
