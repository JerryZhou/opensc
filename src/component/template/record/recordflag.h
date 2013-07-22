//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilArmMagazineFlag)
JEnumValueWith(EAbilArmMagazineFlag,      AutoCastOffOwnerLeave,                0x00000001)
JEnumValueWith(EAbilArmMagazineFlag,      BestUnit,                             0x00000002)
JEnumValueWith(EAbilArmMagazineFlag,      IgnoreUnitCost,                       0x00000004)
JEnumValueWith(EAbilArmMagazineFlag,      Retarget,                             0x00000008)
JEnumEnd(Record, EAbilArmMagazineFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilArmMagazineInfoFlag)
JEnumValueWith(EAbilArmMagazineInfoFlag,  AutoBuild,                            0x00000001)
JEnumValueWith(EAbilArmMagazineInfoFlag,  AutoBuildOn,                          0x00000002)
JEnumValueWith(EAbilArmMagazineInfoFlag,  External,                             0x00000004)
JEnumEnd(Record, EAbilArmMagazineInfoFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilAugmentFlag)
JEnumValueWith(EAbilAugmentFlag,          AutoCast,                             0x00000001)
JEnumValueWith(EAbilAugmentFlag,          AutoCastOffOwnerLeave,                0x00000002)
JEnumValueWith(EAbilAugmentFlag,          AutoCastOn,                           0x00000004)
JEnumValueWith(EAbilAugmentFlag,          BestUnit,                             0x00000008)
JEnumEnd(Record, EAbilAugmentFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilBehaviorFlag)
JEnumValueWith(EAbilBehaviorFlag,         AutoCast,                             0x00000001)
JEnumValueWith(EAbilBehaviorFlag,         AutoCastOffOwnerLeave,                0x00000002)
JEnumValueWith(EAbilBehaviorFlag,         AutoCastOn,                           0x00000004)
JEnumValueWith(EAbilBehaviorFlag,         BestUnit,                             0x00000008)
JEnumValueWith(EAbilBehaviorFlag,         Toggle,                               0x00000010)
JEnumValueWith(EAbilBehaviorFlag,         ToggledOn,                            0x00000020)
JEnumValueWith(EAbilBehaviorFlag,         Transient,                            0x00000040)
JEnumEnd(Record, EAbilBehaviorFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilBuildFlag)
JEnumValueWith(EAbilBuildFlag,            BestUnit,                             0x00000001)
JEnumValueWith(EAbilBuildFlag,            Cancelable,                           0x00000002)
JEnumValueWith(EAbilBuildFlag,            HomogenousInterrupt,                  0x00000004)
JEnumValueWith(EAbilBuildFlag,            IgnoreFood,                           0x00000008)
JEnumValueWith(EAbilBuildFlag,            IgnoreUnitCost,                       0x00000010)
JEnumValueWith(EAbilBuildFlag,            InstantPlacement,                     0x00000020)
JEnumValueWith(EAbilBuildFlag,            Interruptible,                        0x00000040)
JEnumValueWith(EAbilBuildFlag,            NeutralDetachedAddOn,                 0x00000080)
JEnumValueWith(EAbilBuildFlag,            PeonDisableAbils,                     0x00000100)
JEnumValueWith(EAbilBuildFlag,            PeonDisableCollision,                 0x00000200)
JEnumValueWith(EAbilBuildFlag,            PeonFidgetAcross,                     0x00000400)
JEnumValueWith(EAbilBuildFlag,            PeonHide,                             0x00000800)
JEnumValueWith(EAbilBuildFlag,            PeonKillCancel,                       0x00001000)
JEnumValueWith(EAbilBuildFlag,            PeonKillFinish,                       0x00002000)
JEnumValueWith(EAbilBuildFlag,            PeonMaintained,                       0x00004000)
JEnumValueWith(EAbilBuildFlag,            RangeIncludesBuilding,                0x00008000)
JEnumValueWith(EAbilBuildFlag,            ShowProgress,                         0x00010000)
JEnumEnd(Record, EAbilBuildFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilCmdFlags)
JEnumValueWith(EAbilCmdFlags,             Hidden,                               0x00000001)
JEnumValueWith(EAbilCmdFlags,             ShowInGlossary,                       0x00000002)
JEnumValueWith(EAbilCmdFlags,             ToSelection,                          0x00000004)
JEnumEnd(Record, EAbilCmdFlags)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilEffectFlag)
JEnumValueWith(EAbilEffectFlag,           AbortOnAllianceChange,                0x00000001)
JEnumValueWith(EAbilEffectFlag,           AllowMovement,                        0x00000002)
JEnumValueWith(EAbilEffectFlag,           AutoCast,                             0x00000004)
JEnumValueWith(EAbilEffectFlag,           AutoCastOffOwnerLeave,                0x00000008)
JEnumValueWith(EAbilEffectFlag,           AutoCastOn,                           0x00000010)
JEnumValueWith(EAbilEffectFlag,           BestUnit,                             0x00000020)
JEnumValueWith(EAbilEffectFlag,           Chase,                                0x00000040)
JEnumValueWith(EAbilEffectFlag,           NoDeceleration,                       0x00000080)
JEnumValueWith(EAbilEffectFlag,           PassengerAcquireExternal,             0x00000100)
JEnumValueWith(EAbilEffectFlag,           PassengerAcquirePassengers,           0x00000200)
JEnumValueWith(EAbilEffectFlag,           PassengerAcquireTransport,            0x00000400)
JEnumValueWith(EAbilEffectFlag,           ReExecutable,                         0x00000800)
JEnumValueWith(EAbilEffectFlag,           RequireTargetVision,                  0x00001000)
JEnumValueWith(EAbilEffectFlag,           Smart,                                0x00002000)
JEnumValueWith(EAbilEffectFlag,           Transient,                            0x00004000)
JEnumValueWith(EAbilEffectFlag,           TransportAcquirePassengers,           0x00008000)
JEnumEnd(Record, EAbilEffectFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilHarvestFlag)
JEnumValueWith(EAbilHarvestFlag,          BypassResourceQueue,                  0x00000001)
JEnumEnd(Record, EAbilHarvestFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilInteractFlag)
JEnumValueWith(EAbilInteractFlag,         AutoCast,                             0x00000001)
JEnumValueWith(EAbilInteractFlag,         BestUnit,                             0x00000002)
JEnumValueWith(EAbilInteractFlag,         Exclusive,                            0x00000004)
JEnumValueWith(EAbilInteractFlag,         SameCliffLevel,                       0x00000008)
JEnumValueWith(EAbilInteractFlag,         ShareControl,                         0x00000010)
JEnumValueWith(EAbilInteractFlag,         ShareVision,                          0x00000020)
JEnumValueWith(EAbilInteractFlag,         Smart,                                0x00000040)
JEnumEnd(Record, EAbilInteractFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilInventoryFlag)
JEnumValueWith(EAbilInventoryFlag,        ItemDeath,                            0x00000001)
JEnumEnd(Record, EAbilInventoryFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilLearnFlag)
JEnumValueWith(EAbilLearnFlag,            BestUnit,                             0x00000001)
JEnumValueWith(EAbilLearnFlag,            HideOnMaxLevel,                       0x00000002)
JEnumValueWith(EAbilLearnFlag,            HideOnPointsSpent,                    0x00000004)
JEnumEnd(Record, EAbilLearnFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilMergeFlag)
JEnumValueWith(EAbilMergeFlag,            BestUnit,                             0x00000001)
JEnumValueWith(EAbilMergeFlag,            IgnoreUnitCost,                       0x00000002)
JEnumEnd(Record, EAbilMergeFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilMorphFlag)
JEnumValueWith(EAbilMorphFlag,            AutoCast,                             0x00000001)
JEnumValueWith(EAbilMorphFlag,            AutoCastIdleOnly,                     0x00000002)
JEnumValueWith(EAbilMorphFlag,            AutoCastOffOwnerLeave,                0x00000004)
JEnumValueWith(EAbilMorphFlag,            AutoCastOn,                           0x00000008)
JEnumValueWith(EAbilMorphFlag,            Automatic,                            0x00000010)
JEnumValueWith(EAbilMorphFlag,            BestUnit,                             0x00000020)
JEnumValueWith(EAbilMorphFlag,            Birth,                                0x00000040)
JEnumValueWith(EAbilMorphFlag,            DisableAbils,                         0x00000080)
JEnumValueWith(EAbilMorphFlag,            DisableCollision,                     0x00000100)
JEnumValueWith(EAbilMorphFlag,            FastBuild,                            0x00000200)
JEnumValueWith(EAbilMorphFlag,            IgnoreFacing,                         0x00000400)
JEnumValueWith(EAbilMorphFlag,            IgnoreFood,                           0x00000800)
JEnumValueWith(EAbilMorphFlag,            IgnorePlacement,                      0x00001000)
JEnumValueWith(EAbilMorphFlag,            IgnoreUnitCost,                       0x00002000)
JEnumValueWith(EAbilMorphFlag,            Interruptible,                        0x00004000)
JEnumValueWith(EAbilMorphFlag,            MoveBlockers,                         0x00008000)
JEnumValueWith(EAbilMorphFlag,            Produce,                              0x00010000)
JEnumValueWith(EAbilMorphFlag,            Rally,                                0x00020000)
JEnumValueWith(EAbilMorphFlag,            RallyReset,                           0x00040000)
JEnumValueWith(EAbilMorphFlag,            ShowPlaceholder,                      0x00080000)
JEnumValueWith(EAbilMorphFlag,            ShowProgress,                         0x00100000)
JEnumValueWith(EAbilMorphFlag,            SuppressMovement,                     0x00200000)
JEnumValueWith(EAbilMorphFlag,            WaitUntilStopped,                     0x00400000)
JEnumEnd(Record, EAbilMorphFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilOrderDisplayFlag)
JEnumValueWith(EAbilOrderDisplayFlag,     Looped,                               0x00000001)
JEnumEnd(Record, EAbilOrderDisplayFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilPawnFlag)
JEnumValueWith(EAbilPawnFlag,             BestUnit,                             0x00000001)
JEnumValueWith(EAbilPawnFlag,             Smart,                                0x00000002)
JEnumEnd(Record, EAbilPawnFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilQueueFlag)
JEnumValueWith(EAbilQueueFlag,            BestUnit,                             0x00000001)
JEnumValueWith(EAbilQueueFlag,            Hidden,                               0x00000002)
JEnumValueWith(EAbilQueueFlag,            NotifyAddOn,                          0x00000004)
JEnumValueWith(EAbilQueueFlag,            Passive,                              0x00000008)
JEnumEnd(Record, EAbilQueueFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilRallyFlag)
JEnumValueWith(EAbilRallyFlag,            ShowWhileMerging,                     0x00000001)
JEnumValueWith(EAbilRallyFlag,            ShowWhileWarping,                     0x00000002)
JEnumEnd(Record, EAbilRallyFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilRedirectFlag)
JEnumValueWith(EAbilRedirectFlag,         IncludeSelf,                          0x00000001)
JEnumEnd(Record, EAbilRedirectFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilResearchFlag)
JEnumValueWith(EAbilResearchFlag,         BestUnit,                             0x00000001)
JEnumEnd(Record, EAbilResearchFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilReviveFlag)
JEnumValueWith(EAbilReviveFlag,           BestUnit,                             0x00000001)
JEnumEnd(Record, EAbilReviveFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilSpecializeFlag)
JEnumValueWith(EAbilSpecializeFlag,       AutoCastOffOwnerLeave,                0x00000001)
JEnumValueWith(EAbilSpecializeFlag,       BestUnit,                             0x00000002)
JEnumEnd(Record, EAbilSpecializeFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilSpecializeInfoFlag)
JEnumValueWith(EAbilSpecializeInfoFlag,   AutoCast,                             0x00000001)
JEnumValueWith(EAbilSpecializeInfoFlag,   AutoCastOn,                           0x00000002)
JEnumEnd(Record, EAbilSpecializeInfoFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilStopFlag)
JEnumValueWith(EAbilStopFlag,             HoldFire,                             0x00000001)
JEnumEnd(Record, EAbilStopFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilTrainFlag)
JEnumValueWith(EAbilTrainFlag,            BestUnit,                             0x00000001)
JEnumValueWith(EAbilTrainFlag,            DisableCollision,                     0x00000002)
JEnumValueWith(EAbilTrainFlag,            IgnoreUnitCost,                       0x00000004)
JEnumValueWith(EAbilTrainFlag,            KillOnCancel,                         0x00000008)
JEnumValueWith(EAbilTrainFlag,            KillOnFinish,                         0x00000010)
JEnumValueWith(EAbilTrainFlag,            Select,                               0x00000020)
JEnumEnd(Record, EAbilTrainFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilTransportFlag)
JEnumValueWith(EAbilTransportFlag,        AllowPassengerSmartCmd,               0x00000001)
JEnumValueWith(EAbilTransportFlag,        AllowSmartCmd,                        0x00000002)
JEnumValueWith(EAbilTransportFlag,        CargoDeath,                           0x00000004)
JEnumValueWith(EAbilTransportFlag,        IgnoreBlockers,                       0x00000008)
JEnumValueWith(EAbilTransportFlag,        PlayerHold,                           0x00000010)
JEnumValueWith(EAbilTransportFlag,        ShowCargoSize,                        0x00000020)
JEnumValueWith(EAbilTransportFlag,        ShowStatus,                           0x00000040)
JEnumEnd(Record, EAbilTransportFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAbilWarpTrainFlag)
JEnumValueWith(EAbilWarpTrainFlag,        IgnoreUnitCost,                       0x00000001)
JEnumEnd(Record, EAbilWarpTrainFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAchievementFilter)
JEnumValueWith(EAchievementFilter,        MapMelee,                             0x00000001)
JEnumValueWith(EAchievementFilter,        MapSignature,                         0x00000002)
JEnumValueWith(EAchievementFilter,        MatchAnonymous,                       0x00000004)
JEnumValueWith(EAchievementFilter,        MatchFFA,                             0x00000008)
JEnumValueWith(EAchievementFilter,        MatchMulti,                           0x00000010)
JEnumValueWith(EAchievementFilter,        MatchNoHandicaps,                     0x00000020)
JEnumValueWith(EAchievementFilter,        MatchObserver,                        0x00000040)
JEnumValueWith(EAchievementFilter,        MatchParticipant,                     0x00000080)
JEnumValueWith(EAchievementFilter,        MatchRanked,                          0x00000100)
JEnumValueWith(EAchievementFilter,        MatchSingle,                          0x00000200)
JEnumEnd(Record, EAchievementFilter)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAchievementFlag)
JEnumValueWith(EAchievementFlag,          Cloaked,                              0x00000001)
JEnumValueWith(EAchievementFlag,          Finalize,                             0x00000002)
JEnumValueWith(EAchievementFlag,          Hidden,                               0x00000004)
JEnumValueWith(EAchievementFlag,          Local,                                0x00000008)
JEnumValueWith(EAchievementFlag,          Progress,                             0x00000010)
JEnumValueWith(EAchievementFlag,          Victory,                              0x00000020)
JEnumEnd(Record, EAchievementFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAchievementTermFlag)
JEnumValueWith(EAchievementTermFlag,      Hidden,                               0x00000001)
JEnumValueWith(EAchievementTermFlag,      Notify,                               0x00000002)
JEnumValueWith(EAchievementTermFlag,      Persist,                              0x00000004)
JEnumEnd(Record, EAchievementTermFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorActionFlag)
JEnumValueWith(EActorActionFlag,          AlignedImpactsAndDamages,             0x00000001)
JEnumValueWith(EActorActionFlag,          ImpactForceSite,                      0x00000002)
JEnumValueWith(EActorActionFlag,          LaunchForceSite,                      0x00000004)
JEnumEnd(Record, EActorActionFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorDoodadFlag)
JEnumValueWith(EActorDoodadFlag,          FootprintOnly,                        0x00000001)
JEnumValueWith(EActorDoodadFlag,          PauseAnimsWhileFogged,                0x00000002)
JEnumEnd(Record, EActorDoodadFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorFilter)
JEnumValueWith(EActorFilter,              Ally,                                 0x00000001)
JEnumValueWith(EActorFilter,              Enemy,                                0x00000002)
JEnumValueWith(EActorFilter,              Neutral,                              0x00000004)
JEnumValueWith(EActorFilter,              Self,                                 0x00000008)
JEnumEnd(Record, EActorFilter)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorFlag)
JEnumValueWith(EActorFlag,                AddToExternalFinder,                  0x00000001)
JEnumValueWith(EActorFlag,                ScaleToHost,                          0x00000002)
JEnumValueWith(EActorFlag,                SuppressCreationErrors,               0x00000004)
JEnumValueWith(EActorFlag,                SuppressSaveLoad,                     0x00000008)
JEnumEnd(Record, EActorFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorHostedProp)
JEnumValueWith(EActorHostedProp,          BaseModelScale,                       0x00000001)
JEnumValueWith(EActorHostedProp,          CastShadows,                          0x00000002)
JEnumValueWith(EActorHostedProp,          CloakEffect,                          0x00000004)
JEnumValueWith(EActorHostedProp,          Decal,                                0x00000008)
JEnumValueWith(EActorHostedProp,          LocalTintColor,                       0x00000010)
JEnumValueWith(EActorHostedProp,          Opacity,                              0x00000020)
JEnumValueWith(EActorHostedProp,          PhysicsState,                         0x00000040)
JEnumValueWith(EActorHostedProp,          Scale,                                0x00000080)
JEnumValueWith(EActorHostedProp,          TeamColor,                            0x00000100)
JEnumValueWith(EActorHostedProp,          TimeScale,                            0x00000200)
JEnumValueWith(EActorHostedProp,          TintColor,                            0x00000400)
JEnumValueWith(EActorHostedProp,          Visibility,                           0x00000800)
JEnumValueWith(EActorHostedProp,          WarpGroup,                            0x00001000)
JEnumEnd(Record, EActorHostedProp)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorModelFlag)
JEnumValueWith(EActorModelFlag,           AllowHitTest,                         0x00000001)
JEnumValueWith(EActorModelFlag,           IgnoreWalkables,                      0x00000002)
JEnumValueWith(EActorModelFlag,           NeedsVolumeMonitoring,                0x00000004)
JEnumValueWith(EActorModelFlag,           SuppressMissingAttachErrors,          0x00000008)
JEnumValueWith(EActorModelFlag,           SuppressPlayerDecals,                 0x00000010)
JEnumValueWith(EActorModelFlag,           UpdateVisibility,                     0x00000020)
JEnumValueWith(EActorModelFlag,           UseSyncSeed,                          0x00000040)
JEnumEnd(Record, EActorModelFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorRangeFlag)
JEnumValueWith(EActorRangeFlag,           Minimap,                              0x00000001)
JEnumEnd(Record, EActorRangeFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorSelectionFlag)
JEnumValueWith(EActorSelectionFlag,       IsFlash,                              0x00000001)
JEnumValueWith(EActorSelectionFlag,       IsSyncSelection,                      0x00000002)
JEnumValueWith(EActorSelectionFlag,       UseCheapQuadSplat,                    0x00000004)
JEnumValueWith(EActorSelectionFlag,       UseCrescent,                          0x00000008)
JEnumEnd(Record, EActorSelectionFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorTerrainDeformerFlag)
JEnumValueWith(EActorTerrainDeformerFlag, DestroysFoliage,                      0x00000001)
JEnumValueWith(EActorTerrainDeformerFlag, RestoreOnDestroy,                     0x00000002)
JEnumValueWith(EActorTerrainDeformerFlag, RestoreOnMovement,                    0x00000004)
JEnumValueWith(EActorTerrainDeformerFlag, UseUnitFootprint,                     0x00000008)
JEnumEnd(Record, EActorTerrainDeformerFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorTextOption)
JEnumValueWith(EActorTextOption,          ConformToTerrain,                     0x00000001)
JEnumValueWith(EActorTextOption,          UseTerrainHeight,                     0x00000002)
JEnumValueWith(EActorTextOption,          UseWalkableHeight,                    0x00000004)
JEnumEnd(Record, EActorTextOption)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorTransferFlag)
JEnumValueWith(EActorTransferFlag,        Animator,                             0x00000001)
JEnumValueWith(EActorTransferFlag,        AnimProps,                            0x00000002)
JEnumValueWith(EActorTransferFlag,        FOWColor,                             0x00000004)
JEnumValueWith(EActorTransferFlag,        FOWShader,                            0x00000008)
JEnumValueWith(EActorTransferFlag,        Model,                                0x00000010)
JEnumValueWith(EActorTransferFlag,        Position,                             0x00000020)
JEnumValueWith(EActorTransferFlag,        Rotation,                             0x00000040)
JEnumValueWith(EActorTransferFlag,        Status,                               0x00000080)
JEnumValueWith(EActorTransferFlag,        Textures,                             0x00000100)
JEnumEnd(Record, EActorTransferFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EActorUnitFlag)
JEnumValueWith(EActorUnitFlag,            ShowBlobShadow,                       0x00000001)
JEnumValueWith(EActorUnitFlag,            StandAnimBirthVariation,              0x00000002)
JEnumValueWith(EActorUnitFlag,            SuppressCreationErrors,               0x00000004)
JEnumValueWith(EActorUnitFlag,            SuppressStandIntro,                   0x00000008)
JEnumValueWith(EActorUnitFlag,            SuppressWalkIntro,                    0x00000010)
JEnumValueWith(EActorUnitFlag,            SuppressWalkOutro,                    0x00000020)
JEnumEnd(Record, EActorUnitFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAlertAction)
JEnumValueWith(EAlertAction,              Flash,                                0x00000001)
JEnumValueWith(EAlertAction,              Select,                               0x00000002)
JEnumValueWith(EAlertAction,              Target,                               0x00000004)
JEnumValueWith(EAlertAction,              View,                                 0x00000008)
JEnumEnd(Record, EAlertAction)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAlertDisplay)
JEnumValueWith(EAlertDisplay,             Ally,                                 0x00000001)
JEnumValueWith(EAlertDisplay,             Enemy,                                0x00000002)
JEnumValueWith(EAlertDisplay,             Neutral,                              0x00000004)
JEnumValueWith(EAlertDisplay,             Other,                                0x00000008)
JEnumValueWith(EAlertDisplay,             Self,                                 0x00000010)
JEnumEnd(Record, EAlertDisplay)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAlertFlag)
JEnumValueWith(EAlertFlag,                Combine,                              0x00000001)
JEnumValueWith(EAlertFlag,                Hide,                                 0x00000002)
JEnumValueWith(EAlertFlag,                Ping,                                 0x00000004)
JEnumEnd(Record, EAlertFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAMArcTest)
JEnumValueWith(EAMArcTest,                ActionAcquisition,                    0x00000001)
JEnumValueWith(EAMArcTest,                Weapon,                               0x00000002)
JEnumEnd(Record, EAMArcTest)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAnimBracketStartFlag)
JEnumValueWith(EAnimBracketStartFlag,     ClosingFull,                          0x00000001)
JEnumValueWith(EAnimBracketStartFlag,     ContentNonLooping,                    0x00000002)
JEnumValueWith(EAnimBracketStartFlag,     ContentPlayOnce,                      0x00000004)
JEnumValueWith(EAnimBracketStartFlag,     Instant,                              0x00000008)
JEnumValueWith(EAnimBracketStartFlag,     OpeningPlayForever,                   0x00000010)
JEnumEnd(Record, EAnimBracketStartFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAnimFlags)
JEnumValueWith(EAnimFlags,                AssetDrivenLooping,                   0x00000001)
JEnumValueWith(EAnimFlags,                FullMatch,                            0x00000002)
JEnumValueWith(EAnimFlags,                NonLooping,                           0x00000004)
JEnumValueWith(EAnimFlags,                PlayForever,                          0x00000008)
JEnumValueWith(EAnimFlags,                RandomStartOffset,                    0x00000010)
JEnumEnd(Record, EAnimFlags)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAnimGroupApplyFlag)
JEnumValueWith(EAnimGroupApplyFlag,       ClosingFull,                          0x00000001)
JEnumValueWith(EAnimGroupApplyFlag,       Instant,                              0x00000002)
JEnumEnd(Record, EAnimGroupApplyFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAnimSetTimeFlag)
JEnumValueWith(EAnimSetTimeFlag,          Scaled,                               0x00000001)
JEnumValueWith(EAnimSetTimeFlag,          TriggerEventsOnScrub,                 0x00000002)
JEnumEnd(Record, EAnimSetTimeFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAnimTransitionFlag)
JEnumValueWith(EAnimTransitionFlag,       Instant,                              0x00000001)
JEnumEnd(Record, EAnimTransitionFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EAttackPriority)
JEnumValueWith(EAttackPriority,           InRange,                              0x00000001)
JEnumValueWith(EAttackPriority,           InRangeCurrentTarget,                 0x00000002)
JEnumValueWith(EAttackPriority,           IsThreat,                             0x00000004)
JEnumEnd(Record, EAttackPriority)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBeacon)
JEnumValueWith(EBeacon,                   Attack,                               0x00000001)
JEnumValueWith(EBeacon,                   Defend,                               0x00000002)
JEnumValueWith(EBeacon,                   Detect,                               0x00000004)
JEnumValueWith(EBeacon,                   Expand,                               0x00000008)
JEnumValueWith(EBeacon,                   Harass,                               0x00000010)
JEnumValueWith(EBeacon,                   Rally,                                0x00000020)
JEnumValueWith(EBeacon,                   Scout,                                0x00000040)
JEnumEnd(Record, EBeacon)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorBuff)
JEnumValueWith(EBehaviorBuff,             Channeled,                            0x00000001)
JEnumValueWith(EBehaviorBuff,             Channeling,                           0x00000002)
JEnumValueWith(EBehaviorBuff,             Countdown,                            0x00000004)
JEnumValueWith(EBehaviorBuff,             DisableWhileUnderConstruction,        0x00000008)
JEnumValueWith(EBehaviorBuff,             Extend,                               0x00000010)
JEnumValueWith(EBehaviorBuff,             RemoveDamageResponseExhausted,        0x00000020)
JEnumEnd(Record, EBehaviorBuff)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorCategory)
JEnumValueWith(EBehaviorCategory,         Permanent,                            0x00000001)
JEnumValueWith(EBehaviorCategory,         Restorable,                           0x00000002)
JEnumValueWith(EBehaviorCategory,         Temporary,                            0x00000004)
JEnumEnd(Record, EBehaviorCategory)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorDisplay)
JEnumValueWith(EBehaviorDisplay,          Ally,                                 0x00000001)
JEnumValueWith(EBehaviorDisplay,          Enemy,                                0x00000002)
JEnumValueWith(EBehaviorDisplay,          Neutral,                              0x00000004)
JEnumValueWith(EBehaviorDisplay,          Self,                                 0x00000008)
JEnumEnd(Record, EBehaviorDisplay)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorInfoFlag)
JEnumValueWith(EBehaviorInfoFlag,         Hidden,                               0x00000001)
JEnumEnd(Record, EBehaviorInfoFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorPowerUserFlag)
JEnumValueWith(EBehaviorPowerUserFlag,    DisplayPower,                         0x00000001)
JEnumValueWith(EBehaviorPowerUserFlag,    KillIfUnpowered,                      0x00000002)
JEnumValueWith(EBehaviorPowerUserFlag,    LevelFromSourceCount,                 0x00000004)
JEnumEnd(Record, EBehaviorPowerUserFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorResourceFlag)
JEnumValueWith(EBehaviorResourceFlag,     HideHarvesters,                       0x00000001)
JEnumValueWith(EBehaviorResourceFlag,     RemoveWhenEmpty,                      0x00000002)
JEnumEnd(Record, EBehaviorResourceFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorSpawnFlag)
JEnumValueWith(EBehaviorSpawnFlag,        IgnoreMorph,                          0x00000001)
JEnumValueWith(EBehaviorSpawnFlag,        KillSpawnedOnDeath,                   0x00000002)
JEnumEnd(Record, EBehaviorSpawnFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EBehaviorVeterancyFlag)
JEnumValueWith(EBehaviorVeterancyFlag,    CombineNumericModifications,          0x00000001)
JEnumValueWith(EBehaviorVeterancyFlag,    CombineXP,                            0x00000002)
JEnumValueWith(EBehaviorVeterancyFlag,    MaxLevelLeech,                        0x00000004)
JEnumEnd(Record, EBehaviorVeterancyFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ECmdFlags)
JEnumValueWith(ECmdFlags,                 Alternate,                            0x00000001)
JEnumValueWith(ECmdFlags,                 Preempt,                              0x00000002)
JEnumValueWith(ECmdFlags,                 Queued,                               0x00000004)
JEnumValueWith(ECmdFlags,                 SetAutoCast,                          0x00000008)
JEnumValueWith(ECmdFlags,                 SetAutoCastOn,                        0x00000010)
JEnumValueWith(ECmdFlags,                 SmartClick,                           0x00000020)
JEnumValueWith(ECmdFlags,                 SmartRally,                           0x00000040)
JEnumValueWith(ECmdFlags,                 Subgroup,                             0x00000080)
JEnumEnd(Record, ECmdFlags)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EConversationStateFlag)
JEnumValueWith(EConversationStateFlag,    AllowActions,                         0x00000001)
JEnumValueWith(EConversationStateFlag,    AllowConditions,                      0x00000002)
JEnumValueWith(EConversationStateFlag,    Sorted,                               0x00000004)
JEnumEnd(Record, EConversationStateFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ECreatePersistent)
JEnumValueWith(ECreatePersistent,         Channeled,                            0x00000001)
JEnumValueWith(ECreatePersistent,         Channeling,                           0x00000002)
JEnumValueWith(ECreatePersistent,         EffectFailure,                        0x00000004)
JEnumValueWith(ECreatePersistent,         OrphanParams,                         0x00000008)
JEnumValueWith(ECreatePersistent,         PersistUntilDestroyed,                0x00000010)
JEnumValueWith(ECreatePersistent,         RandomEffect,                         0x00000020)
JEnumValueWith(ECreatePersistent,         RandomOffset,                         0x00000040)
JEnumValueWith(ECreatePersistent,         RandomPeriod,                         0x00000080)
JEnumEnd(Record, ECreatePersistent)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ECreateUnit)
JEnumValueWith(ECreateUnit,               Birth,                                0x00000001)
JEnumValueWith(ECreateUnit,               DropOff,                              0x00000002)
JEnumValueWith(ECreateUnit,               Placement,                            0x00000004)
JEnumValueWith(ECreateUnit,               ProvideFood,                          0x00000008)
JEnumValueWith(ECreateUnit,               SetFacing,                            0x00000010)
JEnumValueWith(ECreateUnit,               TechComplete,                         0x00000020)
JEnumValueWith(ECreateUnit,               UseFood,                              0x00000040)
JEnumEnd(Record, ECreateUnit)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EDamageFlag)
JEnumValueWith(EDamageFlag,               Kill,                                 0x00000001)
JEnumValueWith(EDamageFlag,               Live,                                 0x00000002)
JEnumValueWith(EDamageFlag,               NoBehaviorResponse,                   0x00000004)
JEnumValueWith(EDamageFlag,               NoDealtMaximum,                       0x00000008)
JEnumValueWith(EDamageFlag,               NoDealtMinimum,                       0x00000010)
JEnumValueWith(EDamageFlag,               NoFractionDealtBonus,                 0x00000020)
JEnumValueWith(EDamageFlag,               NoGain,                               0x00000040)
JEnumValueWith(EDamageFlag,               NoKillCredit,                         0x00000080)
JEnumValueWith(EDamageFlag,               NoLeech,                              0x00000100)
JEnumValueWith(EDamageFlag,               NoScaledDealtBonus,                   0x00000200)
JEnumValueWith(EDamageFlag,               Notification,                         0x00000400)
JEnumValueWith(EDamageFlag,               NoUnscaledDealtBonus,                 0x00000800)
JEnumValueWith(EDamageFlag,               NoVitalAbsorbEnergy,                  0x00001000)
JEnumValueWith(EDamageFlag,               NoVitalAbsorbLife,                    0x00002000)
JEnumValueWith(EDamageFlag,               NoVitalAbsorbShields,                 0x00004000)
JEnumValueWith(EDamageFlag,               NoVitalGainEnergy,                    0x00008000)
JEnumValueWith(EDamageFlag,               NoVitalGainLife,                      0x00010000)
JEnumValueWith(EDamageFlag,               NoVitalGainShields,                   0x00020000)
JEnumValueWith(EDamageFlag,               NoVitalLeechEnergy,                   0x00040000)
JEnumValueWith(EDamageFlag,               NoVitalLeechLife,                     0x00080000)
JEnumValueWith(EDamageFlag,               NoVitalLeechShields,                  0x00100000)
JEnumEnd(Record, EDamageFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EDetectType)
JEnumValueWith(EDetectType,               Normal,                               0x00000001)
JEnumValueWith(EDetectType,               Radar,                                0x00000002)
JEnumEnd(Record, EDetectType)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEditorFlag)
JEnumValueWith(EEditorFlag,               AmbientOcclusion,                     0x00000001)
JEnumValueWith(EEditorFlag,               BlockStructures,                      0x00000002)
JEnumValueWith(EEditorFlag,               CanRotate,                            0x00000004)
JEnumValueWith(EEditorFlag,               HostileDefault,                       0x00000008)
JEnumValueWith(EEditorFlag,               NeutralDefault,                       0x00000010)
JEnumValueWith(EEditorFlag,               NoAutoRotate,                         0x00000020)
JEnumValueWith(EEditorFlag,               NoPalettes,                           0x00000040)
JEnumValueWith(EEditorFlag,               NoPlacement,                          0x00000080)
JEnumEnd(Record, EEditorFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEffectHealerFlag)
JEnumValueWith(EEffectHealerFlag,         Channeled,                            0x00000001)
JEnumValueWith(EEffectHealerFlag,         Channeling,                           0x00000002)
JEnumEnd(Record, EEffectHealerFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEffectMissile)
JEnumValueWith(EEffectMissile,            Channeled,                            0x00000001)
JEnumValueWith(EEffectMissile,            PointFallback,                        0x00000002)
JEnumValueWith(EEffectMissile,            Retarget,                             0x00000004)
JEnumValueWith(EEffectMissile,            Return,                               0x00000008)
JEnumValueWith(EEffectMissile,            Transfer,                             0x00000010)
JEnumValueWith(EEffectMissile,            TravelValidation,                     0x00000020)
JEnumValueWith(EEffectMissile,            ValidateAbil,                         0x00000040)
JEnumValueWith(EEffectMissile,            ValidateWeapon,                       0x00000080)
JEnumEnd(Record, EEffectMissile)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEffectModify)
JEnumValueWith(EEffectModify,             Copy,                                 0x00000001)
JEnumValueWith(EEffectModify,             Hide,                                 0x00000002)
JEnumValueWith(EEffectModify,             Mimic,                                0x00000004)
JEnumValueWith(EEffectModify,             NullifyMissile,                       0x00000008)
JEnumValueWith(EEffectModify,             Owner,                                0x00000010)
JEnumValueWith(EEffectModify,             Show,                                 0x00000020)
JEnumEnd(Record, EEffectModify)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEffectRevealFlag)
JEnumValueWith(EEffectRevealFlag,         Detect,                               0x00000001)
JEnumValueWith(EEffectRevealFlag,         LoS,                                  0x00000002)
JEnumValueWith(EEffectRevealFlag,         Permanent,                            0x00000004)
JEnumValueWith(EEffectRevealFlag,         Radar,                                0x00000008)
JEnumValueWith(EEffectRevealFlag,         Unfog,                                0x00000010)
JEnumEnd(Record, EEffectRevealFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEffectSearchFlag)
JEnumValueWith(EEffectSearchFlag,         CallForHelp,                          0x00000001)
JEnumValueWith(EEffectSearchFlag,         ExtendByUnitRadius,                   0x00000002)
JEnumValueWith(EEffectSearchFlag,         OffsetByUnitRadius,                   0x00000004)
JEnumValueWith(EEffectSearchFlag,         SameCliff,                            0x00000008)
JEnumEnd(Record, EEffectSearchFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEffectTeleport)
JEnumValueWith(EEffectTeleport,           TestCliff,                            0x00000001)
JEnumValueWith(EEffectTeleport,           TestFog,                              0x00000002)
JEnumValueWith(EEffectTeleport,           TestZone,                             0x00000004)
JEnumEnd(Record, EEffectTeleport)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EEquipmentDisplayFlag)
JEnumValueWith(EEquipmentDisplayFlag,     CollapseBuffed,                       0x00000001)
JEnumValueWith(EEquipmentDisplayFlag,     DisplayRounded,                       0x00000002)
JEnumValueWith(EEquipmentDisplayFlag,     ExpandUpgraded,                       0x00000004)
JEnumEnd(Record, EEquipmentDisplayFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EItemEffectFlag)
JEnumValueWith(EItemEffectFlag,           Transient,                            0x00000001)
JEnumEnd(Record, EItemEffectFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EItemFlag)
JEnumValueWith(EItemFlag,                 CanDrop,                              0x00000001)
JEnumValueWith(EItemFlag,                 DropOnDeath,                          0x00000002)
JEnumValueWith(EItemFlag,                 KillWhenDepleted,                     0x00000004)
JEnumEnd(Record, EItemFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EModelFlag)
JEnumValueWith(EModelFlag,                AOData,                               0x00000001)
JEnumValueWith(EModelFlag,                AutoUnload,                           0x00000002)
JEnumValueWith(EModelFlag,                Facial,                               0x00000004)
JEnumValueWith(EModelFlag,                ForcePortraitModel,                   0x00000008)
JEnumValueWith(EModelFlag,                ForceTextureSearch,                   0x00000010)
JEnumValueWith(EModelFlag,                FOW,                                  0x00000020)
JEnumValueWith(EModelFlag,                FreezeParticlesAndRibbonsOnAnimPause, 0x00000040)
JEnumValueWith(EModelFlag,                GrowBoundsByElements,                 0x00000080)
JEnumValueWith(EModelFlag,                Ignorable,                            0x00000100)
JEnumValueWith(EModelFlag,                IgnoreAspectRatioScale,               0x00000200)
JEnumValueWith(EModelFlag,                Wait,                                 0x00000400)
JEnumEnd(Record, EModelFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ENotifyAreaFlag)
JEnumValueWith(ENotifyAreaFlag,           HelpFriend,                           0x00000001)
JEnumValueWith(ENotifyAreaFlag,           HurtEnemy,                            0x00000002)
JEnumValueWith(ENotifyAreaFlag,           HurtFriend,                           0x00000004)
JEnumValueWith(ENotifyAreaFlag,           OnlyWorkers,                          0x00000008)
JEnumEnd(Record, ENotifyAreaFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EPath)
JEnumValueWith(EPath,                     BlockVision,                          0x00000001)
JEnumValueWith(EPath,                     Creep,                                0x00000002)
JEnumValueWith(EPath,                     DropOff,                              0x00000004)
JEnumValueWith(EPath,                     Fogged,                               0x00000008)
JEnumValueWith(EPath,                     GroundNoSpawn,                        0x00000010)
JEnumValueWith(EPath,                     Masked,                               0x00000020)
JEnumValueWith(EPath,                     NearResources,                        0x00000040)
JEnumValueWith(EPath,                     NoBuild,                              0x00000080)
JEnumValueWith(EPath,                     NoCreep,                              0x00000100)
JEnumEnd(Record, EPath)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EPlane)
JEnumValueWith(EPlane,                    Air,                                  0x00000001)
JEnumValueWith(EPlane,                    Ground,                               0x00000002)
JEnumEnd(Record, EPlane)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EPlayerRelationship)
JEnumValueWith(EPlayerRelationship,       Ally,                                 0x00000001)
JEnumValueWith(EPlayerRelationship,       Enemy,                                0x00000002)
JEnumValueWith(EPlayerRelationship,       Neutral,                              0x00000004)
JEnumValueWith(EPlayerRelationship,       Self,                                 0x00000008)
JEnumEnd(Record, EPlayerRelationship)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ERaceFlag)
JEnumValueWith(ERaceFlag,                 Selectable,                           0x00000001)
JEnumEnd(Record, ERaceFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ERequirementNodeFlag)
JEnumValueWith(ERequirementNodeFlag,      TechTreeCheat,                        0x00000001)
JEnumEnd(Record, ERequirementNodeFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EResourceType)
JEnumValueWith(EResourceType,             Custom,                               0x00000001)
JEnumValueWith(EResourceType,             Minerals,                             0x00000002)
JEnumValueWith(EResourceType,             Terrazine,                            0x00000004)
JEnumValueWith(EResourceType,             Vespene,                              0x00000008)
JEnumEnd(Record, EResourceType)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EResponseFlag)
JEnumValueWith(EResponseFlag,             Acquire,                              0x00000001)
JEnumValueWith(EResponseFlag,             Flee,                                 0x00000002)
JEnumEnd(Record, EResponseFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ERewardFlag)
JEnumValueWith(ERewardFlag,               Allowed,                              0x00000001)
JEnumValueWith(ERewardFlag,               Cloaked,                              0x00000002)
JEnumValueWith(ERewardFlag,               Default,                              0x00000004)
JEnumValueWith(ERewardFlag,               Hidden,                               0x00000008)
JEnumEnd(Record, ERewardFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EScoreResultFlag)
JEnumValueWith(EScoreResultFlag,          Hidden,                               0x00000001)
JEnumEnd(Record, EScoreResultFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EScoreValueFlag)
JEnumValueWith(EScoreValueFlag,           Hidden,                               0x00000001)
JEnumEnd(Record, EScoreValueFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ESoundFlag)
JEnumValueWith(ESoundFlag,                AutoUnload,                           0x00000001)
JEnumValueWith(ESoundFlag,                HideSubtitle,                         0x00000002)
JEnumValueWith(ESoundFlag,                Ignorable,                            0x00000004)
JEnumValueWith(ESoundFlag,                NeedsFXA,                             0x00000008)
JEnumValueWith(ESoundFlag,                NeedsUpdate,                          0x00000010)
JEnumValueWith(ESoundFlag,                Obsolete,                             0x00000020)
JEnumValueWith(ESoundFlag,                Purgable,                             0x00000040)
JEnumValueWith(ESoundFlag,                Rerecord,                             0x00000080)
JEnumValueWith(ESoundFlag,                Stream,                               0x00000100)
JEnumValueWith(ESoundFlag,                Temporary,                            0x00000200)
JEnumValueWith(ESoundFlag,                Unpausable,                           0x00000400)
JEnumValueWith(ESoundFlag,                Wait,                                 0x00000800)
JEnumEnd(Record, ESoundFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ESoundtrackFlag)
JEnumValueWith(ESoundtrackFlag,           Continuous,                           0x00000001)
JEnumEnd(Record, ESoundtrackFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ETargetFindFlag)
JEnumValueWith(ETargetFindFlag,           EvaluateCmd,                          0x00000001)
JEnumEnd(Record, ETargetFindFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ETerrainTileFlag)
JEnumValueWith(ETerrainTileFlag,          Conform,                              0x00000001)
JEnumValueWith(ETerrainTileFlag,          Elevated,                             0x00000002)
JEnumValueWith(ETerrainTileFlag,          Reversed,                             0x00000004)
JEnumEnd(Record, ETerrainTileFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, ETextureVideoPlayFlag)
JEnumValueWith(ETextureVideoPlayFlag,     Looping,                              0x00000001)
JEnumValueWith(ETextureVideoPlayFlag,     Synced,                               0x00000002)
JEnumEnd(Record, ETextureVideoPlayFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EUnitAIFlag)
JEnumValueWith(EUnitAIFlag,               Campaign,                             0x00000001)
JEnumValueWith(EUnitAIFlag,               ForcedToMove,                         0x00000002)
JEnumValueWith(EUnitAIFlag,               ForceUnburrow,                        0x00000004)
JEnumValueWith(EUnitAIFlag,               ScriptControlled,                     0x00000008)
JEnumValueWith(EUnitAIFlag,               SuggestBurrow,                        0x00000010)
JEnumValueWith(EUnitAIFlag,               SuggestUnburrow,                      0x00000020)
JEnumValueWith(EUnitAIFlag,               Suicide,                              0x00000040)
JEnumValueWith(EUnitAIFlag,               WantsToMove,                          0x00000080)
JEnumEnd(Record, EUnitAIFlag)

//-------------------------------------------------------------------------------------------
JEnumBeginWith(Record, EUnitCollide, long long)
JEnumValueWith(EUnitCollide,              Air1,                                 0x00000001)
JEnumValueWith(EUnitCollide,              Air10,                                0x00000002)
JEnumValueWith(EUnitCollide,              Air11,                                0x00000004)
JEnumValueWith(EUnitCollide,              Air12,                                0x00000008)
JEnumValueWith(EUnitCollide,              Air13,                                0x00000010)
JEnumValueWith(EUnitCollide,              Air14,                                0x00000020)
JEnumValueWith(EUnitCollide,              Air15,                                0x00000040)
JEnumValueWith(EUnitCollide,              Air16,                                0x00000080)
JEnumValueWith(EUnitCollide,              Air2,                                 0x00000100)
JEnumValueWith(EUnitCollide,              Air3,                                 0x00000200)
JEnumValueWith(EUnitCollide,              Air4,                                 0x00000400)
JEnumValueWith(EUnitCollide,              Air5,                                 0x00000800)
JEnumValueWith(EUnitCollide,              Air6,                                 0x00001000)
JEnumValueWith(EUnitCollide,              Air7,                                 0x00002000)
JEnumValueWith(EUnitCollide,              Air8,                                 0x00004000)
JEnumValueWith(EUnitCollide,              Air9,                                 0x00008000)
JEnumValueWith(EUnitCollide,              Land1,                                0x00010000)
JEnumValueWith(EUnitCollide,              Land10,                               0x00020000)
JEnumValueWith(EUnitCollide,              Land11,                               0x00040000)
JEnumValueWith(EUnitCollide,              Land12,                               0x00080000)
JEnumValueWith(EUnitCollide,              Land13,                               0x00100000)
JEnumValueWith(EUnitCollide,              Land14,                               0x00200000)
JEnumValueWith(EUnitCollide,              Land15,                               0x00400000)
JEnumValueWith(EUnitCollide,              Land16,                               0x00800000)
JEnumValueWith(EUnitCollide,              Land2,                                0x01000000)
JEnumValueWith(EUnitCollide,              Land3,                                0x02000000)
JEnumValueWith(EUnitCollide,              Land4,                                0x04000000)
JEnumValueWith(EUnitCollide,              Land5,                                0x08000000)
JEnumValueWith(EUnitCollide,              Land6,                                0x10000000)
JEnumValueWith(EUnitCollide,              Land7,                                0x20000000)
JEnumValueWith(EUnitCollide,              Land8,                                0x40000000)
JEnumValueWith(EUnitCollide,              Land9,                                0x80000000)
JEnumEnd(Record, EUnitCollide)

//-------------------------------------------------------------------------------------------
JEnumBeginWith(Record, EUnitFlag, long long)
JEnumValueWith(EUnitFlag,                 AICaster,                             0x0000000000000001)
JEnumValueWith(EUnitFlag,                 AIChangeling,                         0x0000000000000002)
JEnumValueWith(EUnitFlag,                 AIDefense,                            0x0000000000000004)
JEnumValueWith(EUnitFlag,                 AIFleeDamageDisabled,                 0x0000000000000008)
JEnumValueWith(EUnitFlag,                 AIHighPrioTarget,                     0x0000000000000010)
JEnumValueWith(EUnitFlag,                 AILifetime,                           0x0000000000000020)
JEnumValueWith(EUnitFlag,                 AIObservatory,                        0x0000000000000040)
JEnumValueWith(EUnitFlag,                 AIPressForwardDisabled,               0x0000000000000080)
JEnumValueWith(EUnitFlag,                 AISplash,                             0x0000000000000100)
JEnumValueWith(EUnitFlag,                 AISupport,                            0x0000000000000200)
JEnumValueWith(EUnitFlag,                 AIThreatAir,                          0x0000000000000400)
JEnumValueWith(EUnitFlag,                 AIThreatGround,                       0x0000000000000800)
JEnumValueWith(EUnitFlag,                 AlwaysThreatens,                      0x0000000000001000)
JEnumValueWith(EUnitFlag,                 ArmorDisabledWhileConstructing,       0x0000000000002000)
JEnumValueWith(EUnitFlag,                 Bounce,                               0x0000000000004000)
JEnumValueWith(EUnitFlag,                 Buried,                               0x0000000000008000)
JEnumValueWith(EUnitFlag,                 Cloaked,                              0x0000000000010000)
JEnumValueWith(EUnitFlag,                 CreateVisible,                        0x0000000000020000)
JEnumValueWith(EUnitFlag,                 Destructible,                         0x0000000000040000)
JEnumValueWith(EUnitFlag,                 ForceCollisionCheck,                  0x0000000000080000)
JEnumValueWith(EUnitFlag,                 Hero,                                 0x0000000000100000)
JEnumValueWith(EUnitFlag,                 IgnoreTerrainZInit,                   0x0000000000200000)
JEnumValueWith(EUnitFlag,                 IndividualSubgroups,                  0x0000000000400000)
JEnumValueWith(EUnitFlag,                 Invulnerable,                         0x0000000000800000)
JEnumValueWith(EUnitFlag,                 KillCredit,                           0x0000000001000000)
JEnumValueWith(EUnitFlag,                 Missile,                              0x0000000002000000)
JEnumValueWith(EUnitFlag,                 Movable,                              0x0000000004000000)
JEnumValueWith(EUnitFlag,                 NoDeathEvent,                         0x0000000008000000)
JEnumValueWith(EUnitFlag,                 NoDraw,                               0x0000000010000000)
JEnumValueWith(EUnitFlag,                 NoPortraitTalk,                       0x0000000020000000)
JEnumValueWith(EUnitFlag,                 NoScore,                              0x0000000040000000)
JEnumValueWith(EUnitFlag,                 Pawnable,                             0x0000000080000000)
JEnumValueWith(EUnitFlag,                 PenaltyRevealed,                      0x0000000100000000)
JEnumValueWith(EUnitFlag,                 PreventDefeat,                        0x0000000200000000)
JEnumValueWith(EUnitFlag,                 PreventDestroy,                       0x0000000400000000)
JEnumValueWith(EUnitFlag,                 PreventReveal,                        0x0000000800000000)
JEnumValueWith(EUnitFlag,                 ShowResources,                        0x0000001000000000)
JEnumValueWith(EUnitFlag,                 TownAlert,                            0x0000002000000000)
JEnumValueWith(EUnitFlag,                 TownCamera,                           0x0000004000000000)
JEnumValueWith(EUnitFlag,                 Turnable,                             0x0000008000000000)
JEnumValueWith(EUnitFlag,                 TurnBeforeMove,                       0x0000010000000000)
JEnumValueWith(EUnitFlag,                 Unclickable,                          0x0000020000000000)
JEnumValueWith(EUnitFlag,                 Uncloakable,                          0x0000040000000000)
JEnumValueWith(EUnitFlag,                 Uncommandable,                        0x0000080000000000)
JEnumValueWith(EUnitFlag,                 Uncursorable,                         0x0000100000000000)
JEnumValueWith(EUnitFlag,                 Undetectable,                         0x0000200000000000)
JEnumValueWith(EUnitFlag,                 Unhighlightable,                      0x0000400000000000)
JEnumValueWith(EUnitFlag,                 Unradarable,                          0x0000800000000000)
JEnumValueWith(EUnitFlag,                 Unselectable,                         0x0001000000000000)
JEnumValueWith(EUnitFlag,                 Untargetable,                         0x0002000000000000)
JEnumValueWith(EUnitFlag,                 Untooltipable,                        0x0004000000000000)
JEnumValueWith(EUnitFlag,                 UseLineOfSight,                       0x0008000000000000)
JEnumValueWith(EUnitFlag,                 Worker,                               0x0010000000000000)
JEnumEnd(Record, EUnitFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EUnitStatus)
JEnumValueWith(EUnitStatus,               Cargo,                                0x00000001)
JEnumValueWith(EUnitStatus,               Duration,                             0x00000002)
JEnumValueWith(EUnitStatus,               Energy,                               0x00000004)
JEnumValueWith(EUnitStatus,               Life,                                 0x00000008)
JEnumValueWith(EUnitStatus,               Progress,                             0x00000010)
JEnumValueWith(EUnitStatus,               Shields,                              0x00000020)
JEnumEnd(Record, EUnitStatus)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EUpgradeFlag)
JEnumValueWith(EUpgradeFlag,              TechTreeCheat,                        0x00000001)
JEnumValueWith(EUpgradeFlag,              UpgradeCheat,                         0x00000002)
JEnumEnd(Record, EUpgradeFlag)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EWeaponLegacyOption)
JEnumValueWith(EWeaponLegacyOption,       CanRetargetWhileChanneling,           0x00000001)
JEnumValueWith(EWeaponLegacyOption,       KeepChanneling,                       0x00000002)
JEnumValueWith(EWeaponLegacyOption,       LockTurretWhileFiring,                0x00000004)
JEnumValueWith(EWeaponLegacyOption,       NoDeceleration,                       0x00000008)
JEnumValueWith(EWeaponLegacyOption,       Uninterruptible,                      0x00000010)
JEnumValueWith(EWeaponLegacyOption,       UseRangeToCenter,                     0x00000020)
JEnumEnd(Record, EWeaponLegacyOption)

//-------------------------------------------------------------------------------------------
JEnumBegin(Record, EWeaponOption)
JEnumValueWith(EWeaponOption,             CanInitiateAttackOrder,               0x00000001)
JEnumValueWith(EWeaponOption,             ContinuousScan,                       0x00000002)
JEnumValueWith(EWeaponOption,             Disabled,                             0x00000004)
JEnumValueWith(EWeaponOption,             DisplayCooldown,                      0x00000008)
JEnumValueWith(EWeaponOption,             Hidden,                               0x00000010)
JEnumValueWith(EWeaponOption,             LinkedCooldown,                       0x00000020)
JEnumValueWith(EWeaponOption,             Melee,                                0x00000040)
JEnumValueWith(EWeaponOption,             OnlyFireAtAttackOrderTarget,          0x00000080)
JEnumValueWith(EWeaponOption,             OnlyFireWhileInAttackOrder,           0x00000100)
JEnumEnd(Record, EWeaponOption)
