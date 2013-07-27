
//----------------------------------------------------------------------------------------
JTemplateStruct(SCameraParam)
JTemplateValue(bool,   Modify)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SBlendStop)
JTemplateValue(SBaseRange, Blend)
JTemplateValue(SBaseRange, Stop)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationAction)
JTemplateValue(NAME,         FixedId)
JTemplateValue(INT32,        Index)
JTemplateValue(UNKNOWN_TYPE, Operation)
JTemplateValue(TID,          State)
JTemplateValue(FIXF32,       Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationActionSet)
JTemplateArray(SConversationAction, Actions, UNKNOWN_SIZE)
JTemplateValue(NAME,                Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationCondition)
JTemplateValue(NAME,         FixedId)
JTemplateValue(INT32,        Index)
JTemplateValue(UNKNOWN_TYPE, Operation)
JTemplateValue(TID,          State)
JTemplateValue(INT32,        Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateInfoValue)
JTemplateValue(NAME,   Id)
JTemplateValue(FIXF32, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateVariation)
JTemplateValue(UNKNOWN_TYPE, DefaultCategories)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateInfoUpgrade)
JTemplateValue(NAME, Id)
JTemplateValue(TID,  Upgrade)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateInfoModel)
JTemplateValue(NAME, Id)
JTemplateValue(TID,  Model)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateInfoText)
JTemplateValue(NAME, Id)
JTemplateValue(NAME, Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationWait)
JTemplateArray(SConversationCondition, Conditions, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                 Duration)
JTemplateValue(NAME,                   Id)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCreepSettings)
JTemplateValue(SVector2, CreepBaseNormalMapTileValue)
JTemplateValue(SVector2, CreepBaseTextureTileValue)
JTemplateValue(FIXF32,   CreepEdgeNormalMapMinRampThreshold)
JTemplateValue(SVector2, CreepEdgeNormalMapTileValue)
JTemplateValue(FIXF32,   CreepHeightMapStrength)
JTemplateValue(FIXF32,   CreepNoiseSpeed)
JTemplateValue(FIXF32,   CreepNoiseStrength)
JTemplateValue(FIXF32,   CreepNoiseTiling)
JTemplateValue(FIXF32,   CreepOpaqueAlphaThreshold)
JTemplateValue(FIXF32,   CreepTextureRotation)
JTemplateValue(FIXF32,   CreepTranslucentMaxThreshold)
JTemplateValue(FIXF32,   CreepTranslucentMinThreshold)
JTemplateValue(SVector3, CreepTranslucentPassEmissiveFactor)
JTemplateValue(SVector3, CreepTranslucentPassTint)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDamageKind)
JTemplateEnumA(FIXF32, KindArray, EDamageKind)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCharge)
JTemplateValue(FIXF32,          CountMax)
JTemplateValue(FIXF32,          CountStart)
JTemplateValue(FIXF32,          CountUse)
JTemplateValue(bool,            HideCount)
JTemplateValue(TID,             Link)
JTemplateValue(EChargeLocation, Location)
JTemplateValue(FIXF32,          TimeStart)
JTemplateValue(FIXF32,          TimeUse)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCostFactor)
JTemplateValue(FIXF32, Charge)
JTemplateValue(FIXF32, Cooldown)
JTemplateEnumA(FIXF32, Resource, EResourceType)
JTemplateEnumA(FIXF32, Vital, EUnitVital)
JTemplateEnumA(FIXF32, VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCooldown)
JTemplateValue(TID,               Link)
JTemplateValue(ECooldownLocation, Location)
JTemplateValue(FIXF32,            TimeStart)
JTemplateValue(FIXF32,            TimeUse)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCost)
JTemplateValue(SCharge,      Charge)
JTemplateValue(SCooldown,    Cooldown)
JTemplateValue(ECostDisplay, Display)
JTemplateEnumA(FIXF32,       Resource, EResourceType)
JTemplateEnumA(FIXF32,       Vital, EUnitVital)
JTemplateEnumA(FIXF32,       VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationFacialAnim)
JTemplateValue(UNKNOWN_TYPE, AnimAtts)
JTemplateValue(UNKNOWN_TYPE, AnimTag)
JTemplateValue(NAME,         Id)
JTemplateValue(UNKNOWN_TYPE, SpeechAtts)
JTemplateValue(UNKNOWN_TYPE, SpeechTag)
JTemplateValue(NAME,         Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationConditionSet)
JTemplateArray(SConversationCondition, Conditions, UNKNOWN_SIZE)
JTemplateValue(NAME,                   Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationGroup)
JTemplateValue(UNKNOWN_TYPE,                 Children)
JTemplateValue(UNKNOWN_TYPE,                 ChoiceCamera)
JTemplateValue(EConversationSelectionMethod, ChoiceSelection)
JTemplateValue(NAME,                         Comment)
JTemplateValue(SConversationConditionSet,    Conditions)
JTemplateValue(NAME,                         Id)
JTemplateValue(EConversationSelectionMethod, LineSelection)
JTemplateValue(INT32,                        MaxChoices)
JTemplateValue(INT32,                        MaxLines)
JTemplateValue(NAME,                         Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationComment)
JTemplateValue(NAME, Id)
JTemplateValue(NAME, Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationJump)
JTemplateArray(SConversationCondition, Conditions, UNKNOWN_SIZE)
JTemplateValue(NAME,                   Id)
JTemplateValue(NAME,                   Location)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateInfoAbilCmd)
JTemplateValue(TID,  Abil)
JTemplateValue(NAME, Cmd)
JTemplateValue(NAME, Id)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateInfoIds)
JTemplateArray(NAME, Id, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationStateIndex)
JTemplateValue(SColor,                        Color)
JTemplateValue(NAME,                          EditorPrefix)
JTemplateValue(NAME,                          EditorSuffix)
JTemplateValue(NAME,                          Id)
JTemplateValue(EAttachmentID,                 ImageAttach)
JTemplateValue(ETextTagEdge,                  ImageEdge)
JTemplateValue(NAME,                          ImagePath)
JTemplateArray(SConversationStateInfoAbilCmd, InfoAbilCmd, UNKNOWN_SIZE)
JTemplateArray(SConversationStateInfoModel,   InfoModel, UNKNOWN_SIZE)
JTemplateArray(SConversationStateInfoText,    InfoText, UNKNOWN_SIZE)
JTemplateArray(SConversationStateInfoUpgrade, InfoUpgrade, UNKNOWN_SIZE)
JTemplateArray(SConversationStateInfoValue,   InfoValue, UNKNOWN_SIZE)
JTemplateValue(NAME,                          MoviePath)
JTemplateValue(NAME,                          Name)
JTemplateValue(UNKNOWN_TYPE,                  Variations)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationLine)
JTemplateValue(SConversationActionSet, Actions)
JTemplateValue(UNKNOWN_TYPE,           AnimBlendIn)
JTemplateValue(UNKNOWN_TYPE,           AnimBlendOut)
JTemplateValue(UNKNOWN_TYPE,           AnimProps)
JTemplateValue(UNKNOWN_TYPE,           Comment)
JTemplateArray(SConversationCondition, Conditions, UNKNOWN_SIZE)
JTemplateValue(UNKNOWN_TYPE,           CustomSpeaker)
JTemplateValue(UNKNOWN_TYPE,           FacialAnim)
JTemplateValue(UNKNOWN_TYPE,           FacialAsVoiceDir)
JTemplateValue(UNKNOWN_TYPE,           FacialBlend)
JTemplateValue(FIXF32,                 FixedDuration)
JTemplateValue(NAME,                   Id)
JTemplateValue(UNKNOWN_TYPE,           LookAtAttach)
JTemplateValue(UNKNOWN_TYPE,           LookAtType)
JTemplateValue(UNKNOWN_TYPE,           NoWait)
JTemplateValue(UNKNOWN_TYPE,           Objects)
JTemplateValue(UNKNOWN_TYPE,           OverlapPrevious)
JTemplateValue(TID,                    Sound)
JTemplateValue(INT32,                  SoundIndex)
JTemplateValue(NAME,                   Text)
JTemplateValue(UNKNOWN_TYPE,           Variations)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationRunActions)
JTemplateValue(SConversationActionSet, Actions)
JTemplateArray(SConversationCondition, Conditions, UNKNOWN_SIZE)
JTemplateValue(NAME,                   Id)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDamageResponse)
JTemplateValue(FIXF32,          Chance)
JTemplateValue(FIXF32,          ClampMaximum)
JTemplateValue(FIXF32,          ClampMinimum)
JTemplateValue(SCost,           Cost)
JTemplateArray(TID,             ExcludeEffectArray, UNKNOWN_SIZE)
JTemplateValue(TID,             Exhausted)
JTemplateValue(bool,            Fatal)
JTemplateValue(TID,             Handled)
JTemplateEnumA(FIXF32,          Ignore, EUnitVital)
JTemplateValue(EDamageKind,     Kind)
JTemplateValue(EDamageLocation, Location)
JTemplateValue(FIXF32,          Maximum)
JTemplateValue(FIXF32,          Minimum)
JTemplateValue(FIXF32,          ModifyAmount)
JTemplateValue(FIXF32,          ModifyFraction)
JTemplateValue(FIXF32,          ModifyLimit)
JTemplateValue(bool,            ModifyMinimumDamage)
JTemplateArray(TID,             RequireEffectArray, UNKNOWN_SIZE)
JTemplateValue(STargetFilters,  TargetFilters)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectWhichTimeScale)
JTemplateValue(TID,              Effect)
JTemplateValue(EEffectTimeScale, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectWhichUnit)
JTemplateValue(TID,         Effect)
JTemplateValue(EEffectUnit, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectWhichPlayer)
JTemplateValue(TID,           Effect)
JTemplateValue(EEffectPlayer, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectSwitchCase)
JTemplateValue(TID,  Effect)
JTemplateValue(bool, FallThrough)
JTemplateValue(TID,  Validator)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectWhichLocation)
JTemplateValue(TID,             Effect)
JTemplateValue(EEffectLocation, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SErrorOverride)
JTemplateValue(SError, Error)
JTemplateValue(TID,    GroupSound)
JTemplateValue(TID,    Sound)
JTemplateValue(NAME,   Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFoliageSimulationConfig)
JTemplateValue(EFoliageLayers, AcceptWorldForces)
JTemplateEnumA(FIXF32,         SamplingDistance, EFoliageLayers)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFootprintBitSet)
JTemplateValue(UNKNOWN_TYPE, Character)
JTemplateValue(UNKNOWN_TYPE, Negative)
JTemplateValue(UNKNOWN_TYPE, Positive)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFidget)
JTemplateEnumA(INT32,        ChanceArray, EFidget)
JTemplateValue(FIXF32,       DelayMax)
JTemplateValue(FIXF32,       DelayMin)
JTemplateValue(UNKNOWN_TYPE, DistanceMax)
JTemplateValue(UNKNOWN_TYPE, DistanceMin)
JTemplateValue(FIXF32,       TurnAngle)
JTemplateValue(FIXF32,       TurningRate)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEventDataFootprint)
JTemplateValue(SActorKey, Actor)
JTemplateValue(TID,       Model)
JTemplateValue(SActorKey, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEventDataSound)
JTemplateValue(SActorKey, Actor)
JTemplateValue(SActorKey, Name)
JTemplateValue(TID,       Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDirectionalLight)
JTemplateValue(SColor,       Color)
JTemplateValue(UNKNOWN_TYPE, ColorMultiplier)
JTemplateValue(UNKNOWN_TYPE, Direction)
JTemplateValue(UNKNOWN_TYPE, SpecColorMultiplier)
JTemplateValue(SColor,       SpecularColor)
JTemplateValue(UNKNOWN_TYPE, UseAmbientOcclusion)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDSPArray)
JTemplateValue(UNKNOWN_TYPE, LinkArray)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDifficultyLevel)
JTemplateValue(INT32, ActionsPerMinute)
JTemplateValue(NAME,  AttributeId)
JTemplateValue(INT32, DefaultRebuildStructure)
JTemplateValue(INT32, DefaultRebuildUnit)
JTemplateValue(bool,  Enabled)
JTemplateValue(NAME,  Name)
JTemplateValue(NAME,  NameCampaign)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDeathResponse)
JTemplateValue(FIXF32,              Chance)
JTemplateValue(SCost,               Cost)
JTemplateValue(TID,                 Effect)
JTemplateValue(EPlayerRelationship, Relationship)
JTemplateValue(EDeathType,          Type)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SDefaultGameVariant)
JTemplateValue(UNKNOWN_TYPE,       AchievementTags)
JTemplateValue(INT32,              AIDifficulty)
JTemplateValue(INT32,              CategoryId)
JTemplateValue(NAME,               Description)
JTemplateValue(INT32,              MaxPlayers)
JTemplateValue(INT32,              MinPlayers)
JTemplateValue(INT32,              ModeId)
JTemplateValue(NAME,               Name)
JTemplateValue(EGameVariantOption, Options)
JTemplateValue(INT32,              PlayersPerTeam)
JTemplateValue(INT32,              TeamCount)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectArea)
JTemplateValue(FIXF32,       Arc)
JTemplateValue(INT32,        MaxCount)
JTemplateValue(FIXF32,       Radius)
JTemplateValue(UNKNOWN_TYPE, RadiusBonus)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectModifyVital)
JTemplateValue(FIXF32, Change)
JTemplateValue(FIXF32, ChangeFraction)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectMover)
JTemplateValue(FIXF32, IfRangeLTE)
JTemplateValue(TID,    Link)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectModifyCost)
JTemplateValue(TID,                Abil)
JTemplateValue(FIXF32,             ChargeCountUse)
JTemplateValue(FIXF32,             ChargeTimeUse)
JTemplateValue(FIXF32,             CooldownTimeUse)
JTemplateValue(SCostFactor,        Fraction)
JTemplateValue(SEffectWhichPlayer, Player)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectDamageArea)
JTemplateValue(FIXF32, Arc)
JTemplateValue(FIXF32, Bonus)
JTemplateValue(FIXF32, Fraction)
JTemplateValue(INT32,  MaxCount)
JTemplateValue(FIXF32, Radius)
JTemplateValue(FIXF32, RadiusBonus)
JTemplateValue(TID,    Validator)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SEffectEnumArea)
JTemplateValue(FIXF32, Arc)
JTemplateValue(TID,    Effect)
JTemplateValue(INT32,  MaxCount)
JTemplateValue(FIXF32, Radius)
JTemplateValue(FIXF32, RadiusBonus)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermSubName)
JTemplateValue(NAME, SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermTaunt)
JTemplateValue(UNKNOWN_TYPE, Taunt)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermStateValid)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermSquib)
JTemplateValue(UNKNOWN_TYPE, Squib)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermStateChanged)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermTextureSlotSatisfiesExpression)
JTemplateValue(UNKNOWN_TYPE, Expression)
JTemplateValue(UNKNOWN_TYPE, Slot)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermWeaponTargetAngle)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(UNKNOWN_TYPE,  Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermWeaponTargetDistance)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(UNKNOWN_TYPE,  Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermViewerTreatsUnitAs)
JTemplateValue(UNKNOWN_TYPE, Test)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermTimerName)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermValidateBase)
JTemplateValue(UNKNOWN_TYPE, ValidatorLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermMsg)
JTemplateValue(UNKNOWN_TYPE, Spec)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermOption)
JTemplateValue(UNKNOWN_TYPE, Level)
JTemplateValue(UNKNOWN_TYPE, Setting)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermMoverLink)
JTemplateValue(UNKNOWN_TYPE, MoverLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermMorphTo)
JTemplateValue(UNKNOWN_TYPE, UnitLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermMotionPhase)
JTemplateValue(INT32, Index)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermPassChance)
JTemplateValue(UNKNOWN_TYPE, PassChance)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermScope)
JTemplateValue(UNKNOWN_TYPE, ScopeType)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermScopeContains)
JTemplateValue(NAME, ActorName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermPortraitModel)
JTemplateValue(UNKNOWN_TYPE, ModelLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermPlayerHasReward)
JTemplateValue(UNKNOWN_TYPE, Reward)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermPortraitActor)
JTemplateValue(NAME, ActorKey)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermWeaponTargetElevation)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(UNKNOWN_TYPE,  Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCardLayoutButton)
JTemplateValue(TID,             AbilCmd)
JTemplateValue(TID,             Behavior)
JTemplateValue(INT32,           Column)
JTemplateValue(TID,             Face)
JTemplateValue(TID,             Requirements)
JTemplateValue(INT32,           Row)
JTemplateValue(UNKNOWN_TYPE,    SubmenuAbilState)
JTemplateValue(INT32,           SubmenuCardId)
JTemplateValue(TID,             SubmenuFullSubCmdValidation)
JTemplateValue(bool,            SubmenuIsSticky)
JTemplateValue(ECardButtonType, Type)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCardLayout)
JTemplateValue(INT32,             CardId)
JTemplateArray(SCardLayoutButton, LayoutButtons, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCardButton)
JTemplateValue(TID,             AbilCmd)
JTemplateValue(TID,             Behavior)
JTemplateValue(TID,             Face)
JTemplateValue(TID,             Requirements)
JTemplateValue(UNKNOWN_TYPE,    SubmenuAbilState)
JTemplateValue(INT32,           SubmenuCardId)
JTemplateValue(TID,             SubmenuFullSubCmdValidation)
JTemplateValue(bool,            SubmenuIsSticky)
JTemplateValue(ECardButtonType, Type)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCameraZoom)
JTemplateEnumA(SCameraParam, Param, ECameraParam)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCampaignData)
JTemplateValue(NAME, Description)
JTemplateValue(NAME, Id)
JTemplateValue(NAME, ImagePath)
JTemplateValue(NAME, LaunchMap)
JTemplateValue(NAME, Name)
JTemplateValue(TID,  ProgressAchievement)
JTemplateValue(NAME, SaveName)
JTemplateValue(NAME, TutorialMap)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SChallenge)
JTemplateArray(TID,  Achievement, UNKNOWN_SIZE)
JTemplateValue(NAME, Description)
JTemplateValue(NAME, Id)
JTemplateValue(NAME, MapPath)
JTemplateValue(NAME, Name)
JTemplateValue(NAME, Score)
JTemplateValue(NAME, ThumbnailImagePath)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SConversationChoice)
JTemplateValue(UNKNOWN_TYPE, Actions)
JTemplateValue(UNKNOWN_TYPE, Children)
JTemplateValue(UNKNOWN_TYPE, Comment)
JTemplateValue(UNKNOWN_TYPE, Conditions)
JTemplateValue(NAME,         Id)
JTemplateValue(UNKNOWN_TYPE, Permanent)
JTemplateValue(UNKNOWN_TYPE, RequiresPrevious)
JTemplateValue(NAME,         Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SChallengeCategory)
JTemplateArray(SChallenge, Challenge, UNKNOWN_SIZE)
JTemplateValue(NAME,       Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAttachKey)
JTemplateValue(INT32,          Index)
JTemplateValue(EAttachKeyword, Keyword)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAttachProps)
JTemplateValue(EAttachmentID, Id)
JTemplateEnumA(INT32,         Keys, EAttachKeyword)
JTemplateValue(FIXF32,        RadiusShield)
JTemplateValue(FIXF32,        RadiusTarget)
JTemplateValue(ESquibType,    SquibType)
JTemplateValue(FIXF32,        WeightExplicit)
JTemplateValue(FIXF32,        WeightFactor)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAspectMargin)
JTemplateValue(INT32, AspectHeight)
JTemplateValue(INT32, AspectWidth)
JTemplateValue(NAME,  Margin)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAddedOnData)
JTemplateValue(TID, BehaviorLink)
JTemplateValue(TID, UnitLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAIDescription)
JTemplateValue(NAME, File)
JTemplateValue(NAME, Id)
JTemplateValue(NAME, Name)
JTemplateValue(NAME, Suffix)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAttachQuery)
JTemplateValue(EAttachKeyword, Fallback)
JTemplateValue(UNKNOWN_TYPE,   Methods)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SCameraSmooth)
JTemplateValue(FIXF32, DisplacementMin)
JTemplateValue(FIXF32, SmoothTimeMax)
JTemplateValue(FIXF32, SmoothTimeMin)
JTemplateValue(FIXF32, VelocityMax)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SBehaviorResponse)
JTemplateValue(UNKNOWN_TYPE, Chance)
JTemplateValue(SCost,        Cost)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAttributeChange)
JTemplateValue(TID,   Attribute)
JTemplateValue(INT32, Points)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SBeaconInfo)
JTemplateValue(TID,     Alert)
JTemplateValue(EBeacon, Clear)
JTemplateValue(NAME,    Tooltip)
JTemplateValue(TID,     Unit)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFootprintLayer)
JTemplateValue(UNKNOWN_TYPE, Area)
JTemplateValue(UNKNOWN_TYPE, Rows)
JTemplateValue(UNKNOWN_TYPE, Sets)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STeamColor)
JTemplateValue(NAME,     AttributeId)
JTemplateValue(FIXF32,   HDRMultiplier)
JTemplateValue(INT32,    MinPlayerCount)
JTemplateValue(NAME,     Name)
JTemplateValue(bool,     UserChoice)
JTemplateEnumA(SVector4, Value, ETeamColor)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STechCost)
JTemplateEnumA(INT32, Resource, EResourceType)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STargetSorts)
JTemplateValue(INT32,  RequestCount)
JTemplateValue(FIXF32, RequestPercentage)
JTemplateArray(TID,    SortArray, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STargetFilterResult)
JTemplateValue(STargetFilters, Filter)
JTemplateValue(UNKNOWN_TYPE,   Result)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STargetFindEnumArea)
JTemplateValue(FIXF32, Arc)
JTemplateValue(INT32,  MaxCount)
JTemplateValue(FIXF32, Radius)
JTemplateValue(FIXF32, RadiusBonus)
JTemplateValue(TID,    Validator)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STerrainDoodad)
JTemplateValue(TID,    Model)
JTemplateValue(FIXF32, PlacementRadius)
JTemplateValue(FIXF32, Probability)
JTemplateValue(bool,   RandomRotation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STextureMatchSpec)
JTemplateValue(NAME, Slot)
JTemplateValue(NAME, Source)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STextureNameAdaption)
JTemplateValue(bool,         AppliesToFile)
JTemplateValue(bool,         AppliesToInnate)
JTemplateArray(ETextureProp, PropsAdd, UNKNOWN_SIZE)
JTemplateArray(ETextureProp, PropsRemove, UNKNOWN_SIZE)
JTemplateArray(ETextureProp, PropsSet, UNKNOWN_SIZE)
JTemplateValue(NAME,         Slot)
JTemplateValue(NAME,         TriggerOnSubstring)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STextureDeclare)
JTemplateArray(STextureNameAdaption, Adaptions, UNKNOWN_SIZE)
JTemplateValue(NAME,                 Prefix)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STextureInfo)
JTemplateValue(NAME,  Expression)
JTemplateValue(INT32, Probability)
JTemplateValue(NAME,  Slot)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STextureExpressionSpec)
JTemplateValue(NAME, Expression)
JTemplateValue(NAME, Slot)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundQuality)
JTemplateValue(INT32,           AutoDetectCPUCoreMaximum)
JTemplateValue(INT32,           Channels)
JTemplateValue(ESoundFormat,    Format)
JTemplateValue(NAME,            Name)
JTemplateValue(ESoundResampler, Resampler)
JTemplateValue(INT32,           SampleRate)
JTemplateValue(ESpeakerMode,    SpeakerMode)
JTemplateEnumA(INT32,           VariationMaximum, ESoundCategory)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundtrackMasterLayer)
JTemplateValue(TID, Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundLocaleFlags)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, Locale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundAsset)
JTemplateValue(NAME,        FacialAnim)
JTemplateValue(NAME,        FacialGroup)
JTemplateValue(NAME,        File)
JTemplateValue(INT32,       LoopCount)
JTemplateValue(SIntRange,   LoopTime)
JTemplateValue(SIntRange,   Offset)
JTemplateValue(SFloatRange, Pitch)
JTemplateValue(NAME,        PortraitAnim)
JTemplateValue(TID,         PortraitModel)
JTemplateValue(NAME,        Speaker)
JTemplateValue(NAME,        Subtitle)
JTemplateArray(INT32,       SyncPoints, UNKNOWN_SIZE)
JTemplateValue(SFloatRange, Volume)
JTemplateValue(INT32,       Weight)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SVolumeFade)
JTemplateValue(INT32,  Time)
JTemplateValue(FIXF32, Volume)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SReverbRolloff)
JTemplateValue(FIXF32, Direct)
JTemplateValue(FIXF32, Distance)
JTemplateValue(FIXF32, Room)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SVolumeThreshold)
JTemplateValue(INT32,  Count)
JTemplateValue(FIXF32, Volume)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SVolumeRolloff)
JTemplateValue(FIXF32, Distance)
JTemplateValue(FIXF32, Volume)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundData)
JTemplateArray(TID,              DSPArray, UNKNOWN_SIZE)
JTemplateValue(ESoundBlend,      DupeFadeBlend)
JTemplateArray(SVolumeFade,      DupeFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,      DupeFadeOut, UNKNOWN_SIZE)
JTemplateValue(ESoundBlend,      FogFadeBlend)
JTemplateArray(SVolumeFade,      FogFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,      FogFadeOut, UNKNOWN_SIZE)
JTemplateValue(ESoundBlend,      MuteFadeBlend)
JTemplateArray(SVolumeFade,      MuteFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,      MuteFadeOut, UNKNOWN_SIZE)
JTemplateValue(ESoundBlend,      ReverbRolloffBlend)
JTemplateArray(SReverbRolloff,   ReverbRolloffPoints, UNKNOWN_SIZE)
JTemplateValue(INT32,            ThresholdFadeTime)
JTemplateArray(SVolumeThreshold, ThresholdPoints, UNKNOWN_SIZE)
JTemplateValue(FIXF32,           Volume)
JTemplateValue(ESoundBlend,      VolumeRolloffBlend)
JTemplateValue(ESoundBlend,      VolumeRolloffFadeBlend)
JTemplateArray(SVolumeFade,      VolumeRolloffFadeIn, UNKNOWN_SIZE)
JTemplateArray(SVolumeFade,      VolumeRolloffFadeOut, UNKNOWN_SIZE)
JTemplateArray(SVolumeRolloff,   VolumeRolloffPoints, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SStartingUnit)
JTemplateValue(INT32,        Count)
JTemplateValue(UNKNOWN_TYPE, Offset)
JTemplateValue(FIXF32,       Range)
JTemplateValue(TID,          Unit)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SStatusColor)
JTemplateValue(SColor, BackgroundColor)
JTemplateArray(SColor, ColorArray, UNKNOWN_SIZE)
JTemplateValue(SColor, EmptyColor)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundtrackSection)
JTemplateValue(FIXF32, Chance)
JTemplateValue(TID,    Sound)
JTemplateValue(INT32,  Start)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSpawnInfo)
JTemplateValue(INT32,  Count)
JTemplateValue(FIXF32, Delay)
JTemplateValue(TID,    Effect)
JTemplateValue(TID,    Requirements)
JTemplateValue(TID,    Unit)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundtrackSlaveLayer)
JTemplateArray(SSoundtrackSection, Sections, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSoundtrackCue)
JTemplateValue(SSoundtrackMasterLayer, MasterLayer)
JTemplateArray(SSoundtrackSlaveLayer,  SlaveLayers, UNKNOWN_SIZE)
JTemplateValue(INT32,                  Weight)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STimeEvent)
JTemplateValue(NAME,       Name)
JTemplateValue(STimeOfDay, Time)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SVitalColor)
JTemplateArray(SColor, ColorArray, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SVariationConfig)
JTemplateValue(UNKNOWN_TYPE, Command)
JTemplateValue(UNKNOWN_TYPE, Region)
JTemplateValue(UNKNOWN_TYPE, Sensitivity)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SValidatorEnumArea)
JTemplateValue(FIXF32,        Arc)
JTemplateValue(EValueCompare, Compare)
JTemplateValue(INT32,         Count)
JTemplateValue(FIXF32,        Radius)
JTemplateValue(FIXF32,        RadiusBonus)
JTemplateValue(TID,           Validator)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SValidatorFunction)
JTemplateValue(bool, Break)
JTemplateValue(TID,  Failure)
JTemplateValue(TID,  Ignored)
JTemplateValue(TID,  Return)
JTemplateValue(TID,  Success)
JTemplateValue(TID,  Test)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SWaterStateDesc)
JTemplateValue(FIXF32, CausticsFallOff)
JTemplateValue(SColor, Color)
JTemplateValue(FIXF32, ColorFallOff)
JTemplateValue(FIXF32, Height)
JTemplateValue(FIXF32, MeshRoughness)
JTemplateValue(FIXF32, MinReflection)
JTemplateValue(NAME,   Name)
JTemplateValue(FIXF32, ReflectionDistortion)
JTemplateValue(FIXF32, ReflectivityPower)
JTemplateValue(FIXF32, RefractionDistortion)
JTemplateValue(FIXF32, ShadowDistortion)
JTemplateValue(FIXF32, Specularity)
JTemplateValue(FIXF32, SpecularScaler)
JTemplateValue(FIXF32, TextureRoughness)
JTemplateValue(FIXF32, UvRate)
JTemplateValue(FIXF32, UvRotate)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SWeaponSpeedText)
JTemplateValue(FIXF32, MinSpeed)
JTemplateValue(NAME,   Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SWaterDoodad)
JTemplateValue(FIXF32, Density)
JTemplateValue(INT32,  Lifetime)
JTemplateValue(FIXF32, MaxSize)
JTemplateValue(FIXF32, MinSize)
JTemplateValue(TID,    Model)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitAbilSound)
JTemplateValue(TID, AbilCmd)
JTemplateValue(TID, GroupSound)
JTemplateValue(TID, Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitBehaviorData)
JTemplateValue(UNKNOWN_TYPE, Link)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitAbilData)
JTemplateValue(UNKNOWN_TYPE, Link)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STriggerLib)
JTemplateValue(NAME, Id)
JTemplateValue(NAME, IncludePath)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(STutorialConfig)
JTemplateValue(NAME, Description)
JTemplateValue(NAME, Icon)
JTemplateValue(NAME, Movie)
JTemplateValue(NAME, Title)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitEquipment)
JTemplateValue(TID,  Effect)
JTemplateValue(NAME, Icon)
JTemplateValue(NAME, Name)
JTemplateValue(NAME, Tooltip)
JTemplateValue(TID,  Weapon)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUpgradeEffect)
JTemplateValue(EUpgradeOperation, Operation)
JTemplateValue(UNKNOWN_TYPE,      Reference)
JTemplateValue(UNKNOWN_TYPE,      Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SValidatorCondition)
JTemplateValue(TID, Return)
JTemplateValue(TID, Test)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitWeaponData)
JTemplateValue(TID, Link)
JTemplateValue(TID, Turret)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitKillRank)
JTemplateValue(INT32, MinKills)
JTemplateValue(NAME,  Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SUnitSpeedText)
JTemplateValue(FIXF32, MinSpeed)
JTemplateValue(NAME,   Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLightInfo)
JTemplateValue(SColor,       AmbientColor)
JTemplateValue(UNKNOWN_TYPE, Colorize)
JTemplateValue(UNKNOWN_TYPE, CorrectGamma)
JTemplateValue(UNKNOWN_TYPE, DirectionalLight)
JTemplateValue(UNKNOWN_TYPE, Id)
JTemplateValue(UNKNOWN_TYPE, OperatorHDR)
JTemplateValue(UNKNOWN_TYPE, Param)
JTemplateValue(UNKNOWN_TYPE, TerrainUseBackLight)
JTemplateValue(UNKNOWN_TYPE, TimeOfDay)
JTemplateValue(UNKNOWN_TYPE, TriggerTransition)
JTemplateValue(UNKNOWN_TYPE, UseSeparateDetailSSAO)
JTemplateValue(UNKNOWN_TYPE, Variations)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SListenerRolloff)
JTemplateValue(FIXF32, CameraValue)
JTemplateValue(FIXF32, ListenerFactor)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLayerIconVariation)
JTemplateValue(NAME,  Image)
JTemplateValue(INT32, Number)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLayerIconShield)
JTemplateValue(UNKNOWN_TYPE, Image)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLayerIconShieldVariation)
JTemplateArray(NAME,  Image, UNKNOWN_SIZE)
JTemplateValue(INT32, Number)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLoadingBar)
JTemplateValue(NAME, FrameSuffix)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLootChoice)
JTemplateValue(INT32, Chance)
JTemplateValue(TID,   Child)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMapSize)
JTemplateValue(INT32, MaxCells)
JTemplateValue(NAME,  Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLookAtTypeInfo)
JTemplateValue(UNKNOWN_TYPE, Group)
JTemplateValue(INT32,        Time)
JTemplateValue(FIXF32,       Weight)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLoadingScreenHelp)
JTemplateValue(TID,  Race)
JTemplateValue(NAME, Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLookAtType)
JTemplateValue(NAME,            Id)
JTemplateValue(NAME,            Name)
JTemplateArray(SLookAtTypeInfo, Start, UNKNOWN_SIZE)
JTemplateArray(SLookAtTypeInfo, Stop, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SGameModeInfo)
JTemplateValue(bool,  CanOverrideText)
JTemplateValue(NAME,  Description)
JTemplateValue(INT32, Id)
JTemplateValue(NAME,  Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SGameCategory)
JTemplateValue(SGameModeInfo, Info)
JTemplateArray(SGameModeInfo, Modes, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFootprintTileGrid)
JTemplateValue(UNKNOWN_TYPE, Grid)
JTemplateValue(UNKNOWN_TYPE, Resolution)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFootprintPlacement)
JTemplateValue(UNKNOWN_TYPE, Area)
JTemplateValue(UNKNOWN_TYPE, Have)
JTemplateValue(UNKNOWN_TYPE, Mask)
JTemplateValue(UNKNOWN_TYPE, Test)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SFootprintShape)
JTemplateValue(UNKNOWN_TYPE, Borders)
JTemplateValue(UNKNOWN_TYPE, Mode)
JTemplateValue(UNKNOWN_TYPE, Offsets)
JTemplateValue(FIXF32,       Radius)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SHandicap)
JTemplateValue(INT32, Percent)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SItemContainerSlot)
JTemplateArray(TID,   Classes, UNKNOWN_SIZE)
JTemplateValue(INT32, Column)
JTemplateValue(TID,   EmptyFace)
JTemplateValue(bool,  Equip)
JTemplateValue(TID,   Requirements)
JTemplateValue(INT32, Row)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SLayerIcon)
JTemplateValue(UNKNOWN_TYPE, Image)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SItemContainer)
JTemplateValue(UNKNOWN_TYPE, Classes)
JTemplateValue(UNKNOWN_TYPE, EmptyFace)
JTemplateValue(TID,          Requirements)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SHotkeyInfo)
JTemplateValue(UNKNOWN_TYPE, Category)
JTemplateValue(UNKNOWN_TYPE, Name)
JTemplateValue(UNKNOWN_TYPE, Tooltip)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SIconVariation)
JTemplateArray(NAME,  Image, UNKNOWN_SIZE)
JTemplateValue(INT32, Number)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMarker)
JTemplateValue(INT32,        Count)
JTemplateValue(TID,          Link)
JTemplateValue(EMarkerMatch, MatchFlags)
JTemplateValue(EMarkerMatch, MismatchFlags)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SRequirementCount)
JTemplateArray(NAME,              Link, UNKNOWN_SIZE)
JTemplateValue(ERequirementState, State)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SPointModel)
JTemplateValue(FIXF32,   HeightOffset)
JTemplateValue(NAME,     Model)
JTemplateValue(INT32,    NameSize)
JTemplateValue(FIXF32,   Scale)
JTemplateValue(SVector3, SelectionOffset)
JTemplateValue(FIXF32,   SelectionRadius)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SPitchShift)
JTemplateValue(UNKNOWN_TYPE, Pitch)
JTemplateValue(FIXF32,       Time)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SPlacementBits)
JTemplateValue(UNKNOWN_TYPE, Negative)
JTemplateValue(UNKNOWN_TYPE, Positive)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SRequirementNode)
JTemplateValue(TID, Link)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSelectionData)
JTemplateValue(SVector3, PreselectionAlpha)
JTemplateValue(FIXF32,   PreselectionFallOff)
JTemplateValue(FIXF32,   PreselectionRotationSpeed)
JTemplateValue(INT32,    PreselectionSegmentCount)
JTemplateValue(FIXF32,   PreselectionSegmentPercentSolid)
JTemplateValue(SVector3, PreselectionTiming)
JTemplateValue(FIXF32,   PreselectionWidth)
JTemplateValue(SVector3, SelectionAlpha)
JTemplateValue(FIXF32,   SelectionFallOff)
JTemplateValue(FIXF32,   SelectionInnerBoundaryFallOffRatio)
JTemplateValue(FIXF32,   SelectionInnerBoundaryRatio)
JTemplateValue(FIXF32,   SelectionInnerOffsetRatio)
JTemplateValue(FIXF32,   SelectionRotationSpeed)
JTemplateValue(INT32,    SelectionSegmentCount)
JTemplateValue(FIXF32,   SelectionSegmentPercentSolid)
JTemplateValue(SVector3, SelectionTiming)
JTemplateValue(FIXF32,   SelectionWidth)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SSharedLightInfo)
JTemplateValue(UNKNOWN_TYPE, LightInfo)
JTemplateValue(INT32,        VariationCount)
JTemplateValue(UNKNOWN_TYPE, Variations)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SRewardCategory)
JTemplateValue(NAME, File)
JTemplateValue(NAME, Tag)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SReverbBalance)
JTemplateValue(INT32, Direct)
JTemplateValue(INT32, Room)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SModelVariation)
JTemplateValue(INT32,                  Number)
JTemplateValue(INT32,                  Probability)
JTemplateValue(FIXF32,                 Radius)
JTemplateValue(FIXF32,                 RadiusLoose)
JTemplateArray(ETextureProp,           TextureAppliedGroups, UNKNOWN_SIZE)
JTemplateArray(STextureExpressionSpec, TextureExpressionsForEditor, UNKNOWN_SIZE)
JTemplateArray(STextureMatchSpec,      TextureMatchesForEditor, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SModification)
JTemplateValue(EClassIdCAbil,     AbilClassDisableArray)
JTemplateValue(EClassIdCAbil,     AbilClassEnableArray)
JTemplateArray(TID,               AbilLinkDisableArray, UNKNOWN_SIZE)
JTemplateArray(TID,               AbilLinkEnableArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,            AccelerationBonus)
JTemplateValue(FIXF32,            AccelerationMultiplier)
JTemplateValue(FIXF32,            AttackSpeedMultiplier)
JTemplateArray(SAttributeChange,  AttributeChangeArray, UNKNOWN_SIZE)
JTemplateValue(EBehaviorCategory, BehaviorCategoriesDisable)
JTemplateValue(EBehaviorCategory, BehaviorCategoriesEnable)
JTemplateValue(EClassIdCBehavior, BehaviorClassDisableArray)
JTemplateValue(EClassIdCBehavior, BehaviorClassEnableArray)
JTemplateArray(TID,               BehaviorLinkDisableArray, UNKNOWN_SIZE)
JTemplateArray(TID,               BehaviorLinkEnableArray, UNKNOWN_SIZE)
JTemplateEnumA(FIXF32,            DamageDealtFraction, EDamageKind)
JTemplateEnumA(FIXF32,            DamageDealtMaximum, EDamageKind)
JTemplateEnumA(FIXF32,            DamageDealtMinimum, EDamageKind)
JTemplateEnumA(FIXF32,            DamageDealtScaled, EDamageKind)
JTemplateEnumA(FIXF32,            DamageDealtUnscaled, EDamageKind)
JTemplateValue(SDeathResponse,    DeathResponse)
JTemplateValue(FIXF32,            DecelerationBonus)
JTemplateValue(FIXF32,            DecelerationMultiplier)
JTemplateValue(FIXF32,            Detect)
JTemplateValue(FIXF32,            DetectArc)
JTemplateValue(FIXF32,            DetectBonus)
JTemplateValue(STargetFilters,    DetectFilters)
JTemplateValue(FIXF32,            Food)
JTemplateValue(FIXF32,            Height)
JTemplateEnumA(FIXF32,            HeightTime, EBehaviorHeight)
JTemplateValue(FIXF32,            LifeArmorBonus)
JTemplateValue(FIXF32,            LifeArmorMultiplier)
JTemplateValue(EBehaviorModify,   ModifyFlags)
JTemplateValue(FIXF32,            MoveSpeedBonus)
JTemplateValue(FIXF32,            MoveSpeedMaximum)
JTemplateValue(FIXF32,            MoveSpeedMinimum)
JTemplateValue(FIXF32,            MoveSpeedMultiplier)
JTemplateEnumA(INT32,             PlaneDelta, EPlane)
JTemplateValue(INT32,             QueueCount)
JTemplateValue(INT32,             QueueSize)
JTemplateValue(FIXF32,            Radar)
JTemplateValue(FIXF32,            RadarArc)
JTemplateValue(STargetFilters,    RadarFilters)
JTemplateEnumA(FIXF32,            RateMultiplierArray, EBehaviorRate)
JTemplateEnumA(INT32,             ResourceHarvestAmountBonus, EResourceType)
JTemplateEnumA(FIXF32,            ResourceHarvestAmountMultiplier, EResourceType)
JTemplateEnumA(FIXF32,            ResourceHarvestTimeBonus, EResourceType)
JTemplateEnumA(FIXF32,            ResourceHarvestTimeMultiplier, EResourceType)
JTemplateValue(INT32,             ScoreKillBonus)
JTemplateValue(INT32,             ScoreLostBonus)
JTemplateValue(FIXF32,            ShieldArmorBonus)
JTemplateValue(FIXF32,            ShieldArmorMultiplier)
JTemplateValue(FIXF32,            SightBonus)
JTemplateValue(FIXF32,            SightMaximum)
JTemplateValue(FIXF32,            SightMinimum)
JTemplateValue(FIXF32,            SnareMultiplier)
JTemplateEnumA(TID,               SoundArray, EUnitSound)
JTemplateValue(EBehaviorState,    StateFlags)
JTemplateValue(FIXF32,            TimeScale)
JTemplateArray(TID,               TurretDisableArray, UNKNOWN_SIZE)
JTemplateArray(TID,               TurretEnableArray, UNKNOWN_SIZE)
JTemplateEnumA(SDamageKind,       VitalDamageGainArray, EUnitVital)
JTemplateEnumA(SDamageKind,       VitalDamageLeechArray, EUnitVital)
JTemplateEnumA(FIXF32,            VitalMaxArray, EUnitVital)
JTemplateEnumA(FIXF32,            VitalMaxFractionArray, EUnitVital)
JTemplateEnumA(FIXF32,            VitalRegenArray, EUnitVital)
JTemplateArray(SUnitWeaponData,   WeaponArray, UNKNOWN_SIZE)
JTemplateArray(TID,               WeaponDisableArray, UNKNOWN_SIZE)
JTemplateArray(TID,               WeaponEnableArray, UNKNOWN_SIZE)
JTemplateValue(FIXF32,            WeaponMinRange)
JTemplateValue(FIXF32,            WeaponRange)
JTemplateValue(FIXF32,            WeaponScanBonus)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SVeterancyLevel)
JTemplateValue(NAME,          InfoIcon)
JTemplateValue(INT32,         MinVeterancyXP)
JTemplateValue(SModification, Modification)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SPowerStage)
JTemplateValue(INT32,         MaxStackCount)
JTemplateValue(INT32,         MinPowerLevel)
JTemplateValue(SModification, Modification)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SModelEventData)
JTemplateValue(UNKNOWN_TYPE, Actor)
JTemplateValue(NAME,         Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMinimapData)
JTemplateValue(SColor, BackGroundColor)
JTemplateValue(SColor, BlipUnitColor)
JTemplateValue(FIXF32, BorderSize)
JTemplateValue(SColor, FrustumColor)
JTemplateValue(SColor, InnerBorderColor)
JTemplateValue(FIXF32, MinUnitDotSize)
JTemplateValue(SColor, OuterBorderColor)
JTemplateValue(INT32,  RadarAlpha)
JTemplateValue(SColor, ResourceUnitColor)
JTemplateValue(FIXF32, SelectedBorderSize)
JTemplateValue(SColor, SelectedUnitBorderColor)
JTemplateValue(SColor, SelectedUnitColor)
JTemplateValue(SColor, UnderAttackUnitColor)
JTemplateValue(SColor, UnitBorderColor)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SModelDataEvent)
JTemplateArray(EAnimProp,     Anim, UNKNOWN_SIZE)
JTemplateValue(EAttachmentID, Attachment)
JTemplateValue(EModelQuality, ModelQuality)
JTemplateValue(NAME,          Name)
JTemplateValue(NAME,          Payload)
JTemplateValue(FIXF32,        Time)
JTemplateValue(EModelEvent,   Type)
JTemplateValue(INT32,         Variation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMotionOverlay)
JTemplateValue(SVector3,               Axis)
JTemplateValue(EMotionOverlayPolarity, Polarity)
JTemplateValue(NAME,                   PolarityDriver)
JTemplateValue(FIXF32,                 RevolverAccel)
JTemplateValue(FIXF32,                 RevolverAccelRange)
JTemplateValue(UNKNOWN_TYPE,           RevolverMaxSpeed)
JTemplateValue(FIXF32,                 RevolverMaxSpeedRange)
JTemplateValue(UNKNOWN_TYPE,           RevolverSpeed)
JTemplateValue(FIXF32,                 RevolverSpeedRange)
JTemplateValue(EMotionOverlayType,     Type)
JTemplateValue(SBaseRange,             Wavelength)
JTemplateValue(FIXF32,                 WavelengthChangeProbability)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SObjectGroupData)
JTemplateValue(NAME,  MinimapIcon)
JTemplateValue(INT32, MinLevel)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SPathingData)
JTemplateValue(UNKNOWN_TYPE, Bits)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMovieConfig)
JTemplateValue(NAME, Name)
JTemplateValue(NAME, Path)
JTemplateValue(NAME, Source)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMotionOverlayPhase)
JTemplateValue(SBaseRange, Scale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SMotionPhase)
JTemplateValue(FIXF32,                         Acceleration)
JTemplateValue(FIXF32,                         AccelerationRange)
JTemplateValue(EMotionActorTrackingType,       ActorTracking)
JTemplateEnumA(FIXF32,                         AdaptableParabolaAccels, EMotionAdaptableParabolaSeg)
JTemplateValue(SBaseRange,                     AdaptableParabolaClearance)
JTemplateEnumA(FIXF32,                         AdaptableParabolaDistances, EMotionAdaptableParabolaHotspot)
JTemplateValue(bool,                           AdaptableParabolaIsUpright)
JTemplateValue(EMotionArrivalTestType,         ArrivalTestType)
JTemplateValue(FIXF32,                         AttachReacquireDeflection)
JTemplateValue(EMotionBlendType,               BlendType)
JTemplateValue(FIXF32,                         Clearance)
JTemplateValue(FIXF32,                         ClearanceLookahead)
JTemplateValue(EMotionDriverType,              Driver)
JTemplateValue(SBaseRange,                     FlightTime)
JTemplateValue(FIXF32,                         Gravity)
JTemplateValue(bool,                           IgnoresTerrain)
JTemplateValue(FIXF32,                         MaxSpeed)
JTemplateValue(FIXF32,                         MinSpeed)
JTemplateValue(SBlendStop,                     Outro)
JTemplateValue(SBlendStop,                     OutroAltitude)
JTemplateArray(SMotionOverlayPhase,            Overlays, UNKNOWN_SIZE)
JTemplateValue(FIXF32,                         PowerslideAngle)
JTemplateValue(FIXF32,                         PowerslideDecel)
JTemplateValue(EMotionRotationActorType,       RotationActorType)
JTemplateValue(EMotionRotationLaunchActorType, RotationLaunchActorType)
JTemplateValue(EMotionRotationLaunchType,      RotationLaunchType)
JTemplateValue(FIXF32,                         Speed)
JTemplateValue(FIXF32,                         SpeedRange)
JTemplateValue(SFloatRangeMirror,              ThrowBandPitch)
JTemplateValue(SFloatRangeMirror,              ThrowBandYaw)
JTemplateValue(SVector3,                       ThrowForward)
JTemplateValue(EMotionThrowRotationType,       ThrowRotationType)
JTemplateValue(SVector3,                       ThrowVector)
JTemplateValue(FIXF32,                         Timeout)
JTemplateValue(EMotionTurnType,                TurnType)
JTemplateValue(SRotator,                       YawPitchRoll)
JTemplateValue(SRotator,                       YawPitchRollAccel)
JTemplateValue(SRotator,                       YawPitchRollAccelRange)
JTemplateValue(SRotator,                       YawPitchRollRange)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermMorphFrom)
JTemplateValue(UNKNOWN_TYPE, UnitLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgCreate)
JTemplateValue(UNKNOWN_TYPE, Content)
JTemplateValue(NAME,         Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgCreateCopy)
JTemplateValue(UNKNOWN_TYPE, CreateKey)
JTemplateValue(UNKNOWN_TYPE, SourceKey)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgClearTintColor)
JTemplateValue(FIXF32,       BlendOutDuration)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgClearScale)
JTemplateValue(FIXF32,       BlendOutDuration)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgClearTeamColor)
JTemplateValue(FIXF32,       BlendOutDuration)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgDeathCustomize)
JTemplateValue(NAME, SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgHostSiteOpsSet)
JTemplateValue(bool, HoldPosition)
JTemplateValue(bool, HoldRotation)
JTemplateValue(NAME, HostName)
JTemplateValue(TID,  Ops)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgModelEventSuppress)
JTemplateValue(UNKNOWN_TYPE, Event)
JTemplateValue(UNKNOWN_TYPE, Suppress)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgHostedPropDumpAll)
JTemplateValue(UNKNOWN_TYPE, IncludeChildren)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgDestroy)
JTemplateValue(UNKNOWN_TYPE, Type)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgHostedPropDump)
JTemplateValue(UNKNOWN_TYPE, IncludeChildren)
JTemplateValue(UNKNOWN_TYPE, Type)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachMethods)
JTemplateValue(UNKNOWN_TYPE, AttachMethods)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachSetBearings)
JTemplateValue(UNKNOWN_TYPE, Bearings)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetTimeScaleGlobal)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Scale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetTime)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(FIXF32,       Time)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetTimeScale)
JTemplateValue(UNKNOWN_TYPE, Scale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachSetBearingsFrom)
JTemplateValue(NAME,         Name)
JTemplateValue(UNKNOWN_TYPE, SiteOps)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachSetRotationFrom)
JTemplateValue(NAME,         Name)
JTemplateValue(UNKNOWN_TYPE, SiteOps)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgClearOpacity)
JTemplateValue(FIXF32,       BlendOutDuration)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachSetRotation)
JTemplateValue(UNKNOWN_TYPE, Rotation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachSetPosition)
JTemplateValue(UNKNOWN_TYPE, Position)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAttachSetPositionFrom)
JTemplateValue(NAME,         Name)
JTemplateValue(UNKNOWN_TYPE, SiteOps)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgModelSwap)
JTemplateValue(TID,          Model)
JTemplateValue(UNKNOWN_TYPE, Variation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgQueryRegion)
JTemplateValue(UNKNOWN_TYPE, IntersectType)
JTemplateValue(UNKNOWN_TYPE, Region)
JTemplateValue(UNKNOWN_TYPE, Response)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefName)
JTemplateValue(NAME, RefName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgQueryRadius)
JTemplateValue(UNKNOWN_TYPE, IntersectType)
JTemplateValue(FIXF32,       Radius)
JTemplateValue(UNKNOWN_TYPE, Response)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgPrint)
JTemplateValue(UNKNOWN_TYPE, String)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgQueryPersistent)
JTemplateValue(UNKNOWN_TYPE, EnterResponse)
JTemplateValue(UNKNOWN_TYPE, IntersectType)
JTemplateValue(UNKNOWN_TYPE, LeaveResponse)
JTemplateValue(FIXF32,       RefreshPeriod)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefNotify)
JTemplateValue(NAME, SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefSetFromRequest)
JTemplateValue(UNKNOWN_TYPE, Actor)
JTemplateValue(TID,          Effect)
JTemplateValue(UNKNOWN_TYPE, Scope)
JTemplateValue(UNKNOWN_TYPE, Subject)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefSetRefreshName)
JTemplateValue(NAME, RefreshName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefSetFromMsg)
JTemplateValue(UNKNOWN_TYPE, RefMsg)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefSet)
JTemplateValue(UNKNOWN_TYPE, RefSource)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefSetFromActor)
JTemplateValue(UNKNOWN_TYPE, RefPrimary)
JTemplateValue(UNKNOWN_TYPE, RefSecondary)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetDestinationH)
JTemplateValue(UNKNOWN_TYPE, Height)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetDestinationZ)
JTemplateValue(UNKNOWN_TYPE, Z)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetDestination2D)
JTemplateValue(UNKNOWN_TYPE, Destination2D)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetAcceleration)
JTemplateValue(FIXF32, Acceleration)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetDeceleration)
JTemplateValue(FIXF32, Deceleration)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetSpeed)
JTemplateValue(UNKNOWN_TYPE, Speed)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgPortraitAnimSetTimeFrom)
JTemplateValue(UNKNOWN_TYPE, Source)
JTemplateValue(UNKNOWN_TYPE, TriggerEventsOnScrub)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgPortraitCustomize)
JTemplateValue(UNKNOWN_TYPE, Actor)
JTemplateValue(TID,          Model)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgPlayUnitSound)
JTemplateValue(TID, Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgMoverSetSpeedMax)
JTemplateValue(UNKNOWN_TYPE, SpeedMax)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgName)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilCmdButton)
JTemplateValue(TID,           DefaultButtonFace)
JTemplateValue(EAbilCmdFlags, Flags)
JTemplateValue(TID,           Requirements)
JTemplateValue(EAbilCmdState, State)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilTrainInfo)
JTemplateValue(TID,                Alert)
JTemplateValue(SAbilCmdButton,     Button)
JTemplateValue(SCharge,            Charge)
JTemplateValue(SCooldown,          Cooldown)
JTemplateValue(ECostDisplay,       Display)
JTemplateValue(TID,                Effect)
JTemplateValue(EAbilTrainLocation, Location)
JTemplateEnumA(INT32,              Resource, EResourceType)
JTemplateValue(FIXF32,             Time)
JTemplateValue(TID,                Unit)
JTemplateEnumA(FIXF32,             Vital, EUnitVital)
JTemplateEnumA(FIXF32,             VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilWarpTrainInfo)
JTemplateValue(TID,            Alert)
JTemplateValue(SAbilCmdButton, Button)
JTemplateValue(SCharge,        Charge)
JTemplateValue(SCooldown,      Cooldown)
JTemplateValue(ECostDisplay,   Display)
JTemplateEnumA(INT32,          Resource, EResourceType)
JTemplateValue(FIXF32,         Time)
JTemplateValue(TID,            Unit)
JTemplateEnumA(FIXF32,         Vital, EUnitVital)
JTemplateEnumA(FIXF32,         VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilSpecializeInfo)
JTemplateValue(TID,                     Alert)
JTemplateValue(SAbilCmdButton,          Button)
JTemplateValue(SCharge,                 Charge)
JTemplateValue(SCooldown,               Cooldown)
JTemplateValue(ECostDisplay,            Display)
JTemplateValue(TID,                     Effect)
JTemplateValue(EAbilSpecializeInfoFlag, Flags)
JTemplateEnumA(INT32,                   Resource, EResourceType)
JTemplateValue(FIXF32,                  Time)
JTemplateEnumA(FIXF32,                  Vital, EUnitVital)
JTemplateEnumA(FIXF32,                  VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilResearchInfo)
JTemplateValue(TID,            Alert)
JTemplateValue(SAbilCmdButton, Button)
JTemplateValue(SCharge,        Charge)
JTemplateValue(SCooldown,      Cooldown)
JTemplateValue(ECostDisplay,   Display)
JTemplateEnumA(INT32,          Resource, EResourceType)
JTemplateValue(FIXF32,         Time)
JTemplateValue(TID,            Upgrade)
JTemplateEnumA(FIXF32,         Vital, EUnitVital)
JTemplateEnumA(FIXF32,         VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilReviveInfo)
JTemplateValue(TID,          Alert)
JTemplateValue(SCharge,      Charge)
JTemplateValue(SCooldown,    Cooldown)
JTemplateValue(ECostDisplay, Display)
JTemplateEnumA(INT32,        Resource, EResourceType)
JTemplateValue(FIXF32,       Time)
JTemplateEnumA(FIXF32,       Vital, EUnitVital)
JTemplateEnumA(FIXF32,       VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAchievementTag)
JTemplateValue(UNKNOWN_TYPE, Check)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorBaseline)
JTemplateArray(EAnimProp, AnimProps, UNKNOWN_SIZE)
JTemplateValue(FIXF32,    BlendIn)
JTemplateValue(FIXF32,    BlendOut)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorCloakState)
JTemplateArray(EAnimProp, Enter, UNKNOWN_SIZE)
JTemplateArray(EAnimProp, Loop, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorAVCluster)
JTemplateArray(EAnimProp, AnimProps, UNKNOWN_SIZE)
JTemplateArray(EAnimProp, AnimPropsReaction, UNKNOWN_SIZE)
JTemplateValue(TID,       Model)
JTemplateValue(TID,       ModelReaction)
JTemplateValue(SVector3,  Scale)
JTemplateValue(SVector3,  ScaleReaction)
JTemplateValue(TID,       Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorAVPair)
JTemplateArray(EAnimProp, AnimProps, UNKNOWN_SIZE)
JTemplateValue(TID,       Model)
JTemplateValue(SVector3,  Scale)
JTemplateValue(TID,       Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilRallyInfo)
JTemplateValue(STargetFilters, SetFilters)
JTemplateValue(bool,           SetOnGround)
JTemplateArray(TID,            SetValidators, UNKNOWN_SIZE)
JTemplateValue(STargetFilters, UseFilters)
JTemplateArray(TID,            UseValidators, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilMorphSection)
JTemplateEnumA(FIXF32, DurationArray, EAbilMorphPhase)
JTemplateEnumA(TID,    EffectArray, EAbilMorphEffect)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilLearnInfo)
JTemplateValue(TID,            Abil)
JTemplateValue(TID,            Alert)
JTemplateValue(SAbilCmdButton, Button)
JTemplateValue(SCharge,        Charge)
JTemplateValue(SCooldown,      Cooldown)
JTemplateValue(ECostDisplay,   Display)
JTemplateEnumA(INT32,          Resource, EResourceType)
JTemplateValue(FIXF32,         Time)
JTemplateEnumA(FIXF32,         Vital, EUnitVital)
JTemplateEnumA(FIXF32,         VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilInventoryInfo)
JTemplateValue(EAbilInventoryAlignment, Alignment)
JTemplateArray(TID,                     Classes, UNKNOWN_SIZE)
JTemplateValue(TID,                     Container)
JTemplateValue(TID,                     EmptyFace)
JTemplateValue(TID,                     Item)
JTemplateValue(TID,                     Requirements)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilArmMagazineInfo)
JTemplateValue(TID,                      Alert)
JTemplateValue(SAbilCmdButton,           Button)
JTemplateValue(SCharge,                  Charge)
JTemplateValue(SCooldown,                Cooldown)
JTemplateValue(INT32,                    Count)
JTemplateValue(INT32,                    CountStart)
JTemplateValue(ECostDisplay,             Display)
JTemplateValue(FIXF32,                   Distance)
JTemplateValue(EAbilArmMagazineInfoFlag, Flags)
JTemplateValue(EAbilArmMagazineManage,   Manage)
JTemplateEnumA(FIXF32,                   Resource, EResourceType)
JTemplateValue(FIXF32,                   Time)
JTemplateValue(TID,                      Unit)
JTemplateEnumA(FIXF32,                   Vital, EUnitVital)
JTemplateEnumA(FIXF32,                   VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilBuildInfo)
JTemplateValue(INT32,          AddOnParentCmdPriority)
JTemplateValue(TID,            Alert)
JTemplateValue(SAbilCmdButton, Button)
JTemplateValue(SCharge,        Charge)
JTemplateValue(SCooldown,      Cooldown)
JTemplateValue(FIXF32,         Delay)
JTemplateValue(ECostDisplay,   Display)
JTemplateEnumA(FIXF32,         Resource, EResourceType)
JTemplateValue(FIXF32,         Time)
JTemplateValue(TID,            Unit)
JTemplateArray(TID,            ValidatorArray, UNKNOWN_SIZE)
JTemplateEnumA(FIXF32,         Vital, EUnitVital)
JTemplateEnumA(FIXF32,         VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilMergeInfo)
JTemplateValue(SCharge,      Charge)
JTemplateValue(SCooldown,    Cooldown)
JTemplateValue(ECostDisplay, Display)
JTemplateEnumA(INT32,        Resource, EResourceType)
JTemplateValue(FIXF32,       Time)
JTemplateValue(TID,          Unit)
JTemplateEnumA(FIXF32,       Vital, EUnitVital)
JTemplateEnumA(FIXF32,       VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilPawnInfo)
JTemplateValue(SAbilCmdButton, Button)
JTemplateValue(SCharge,        Charge)
JTemplateValue(SCooldown,      Cooldown)
JTemplateValue(ECostDisplay,   Display)
JTemplateEnumA(FIXF32,         RefundFraction, EResourceType)
JTemplateEnumA(INT32,          Resource, EResourceType)
JTemplateValue(STargetFilters, TargetFilters)
JTemplateArray(TID,            ValidatorArray, UNKNOWN_SIZE)
JTemplateEnumA(FIXF32,         Vital, EUnitVital)
JTemplateEnumA(FIXF32,         VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilQueueableInfo)
JTemplateValue(TID,            Alert)
JTemplateValue(SAbilCmdButton, Button)
JTemplateValue(SCharge,        Charge)
JTemplateValue(SCooldown,      Cooldown)
JTemplateValue(ECostDisplay,   Display)
JTemplateEnumA(INT32,          Resource, EResourceType)
JTemplateValue(FIXF32,         Time)
JTemplateEnumA(FIXF32,         Vital, EUnitVital)
JTemplateEnumA(FIXF32,         VitalFraction, EUnitVital)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilMorphInfo)
JTemplateValue(FIXF32,            CollideRange)
JTemplateValue(FIXF32,            RandomDelayMax)
JTemplateValue(FIXF32,            RandomDelayMin)
JTemplateValue(bool,              Score)
JTemplateEnumA(SAbilMorphSection, SectionArray, EAbilMorphSection)
JTemplateValue(TID,               Unit)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SAbilOrderDisplay)
JTemplateValue(SColor,                Color)
JTemplateValue(EAbilOrderDisplayFlag, FlagArray)
JTemplateValue(NAME,                  LineTexture)
JTemplateValue(NAME,                  Model)
JTemplateValue(FIXF32,                Scale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorCloakTransition)
JTemplateEnumA(SActorCloakState, StateArray, EActorCloakEffect)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimPlay)
JTemplateValue(UNKNOWN_TYPE, BlendIn)
JTemplateValue(UNKNOWN_TYPE, BlendOut)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, Props)
JTemplateValue(UNKNOWN_TYPE, TimeType)
JTemplateValue(UNKNOWN_TYPE, TimeVariant)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimPlaySequence)
JTemplateValue(NAME, SequenceName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimGroupRemove)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, TimeType)
JTemplateValue(UNKNOWN_TYPE, TimeVariant)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimClearTimeScaleGlobal)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimGroupApply)
JTemplateValue(UNKNOWN_TYPE, AtApply)
JTemplateValue(UNKNOWN_TYPE, AtRemove)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, TimeType)
JTemplateValue(UNKNOWN_TYPE, TimeVariant)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimProps)
JTemplateValue(UNKNOWN_TYPE, Props)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetPaused)
JTemplateValue(UNKNOWN_TYPE, Paused)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetPausedAll)
JTemplateValue(UNKNOWN_TYPE, Paused)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetLockedAll)
JTemplateValue(UNKNOWN_TYPE, Locked)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetCompletion)
JTemplateValue(UNKNOWN_TYPE, Percent)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimSetDuration)
JTemplateValue(FIXF32, Duration)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorSiteOpsData)
JTemplateValue(bool, HoldPosition)
JTemplateValue(bool, HoldRotation)
JTemplateValue(TID,  Ops)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorRequest)
JTemplateValue(EActorRequestActor, Actor)
JTemplateValue(TID,                Effect)
JTemplateValue(bool,               FailOnNoHost)
JTemplateValue(EActorRequestScope, Scope)
JTemplateValue(SActorKey,          Subject)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorHostedAttach)
JTemplateValue(SAttachQuery,      AttachQuery)
JTemplateValue(SActorRequest,     Host)
JTemplateValue(SActorSiteOpsData, HostSiteOps)
JTemplateValue(SActorKey,         Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnim)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorEvent)
JTemplateValue(UNKNOWN_TYPE, Send)
JTemplateValue(UNKNOWN_TYPE, Target)
JTemplateValue(UNKNOWN_TYPE, Terms)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorDeathData)
JTemplateArray(EAnimProp,   AnimProps, UNKNOWN_SIZE)
JTemplateValue(TID,         ModelLink)
JTemplateValue(SFloatRange, PhysicsDelay)
JTemplateValue(TID,         SoundLink)
JTemplateValue(TID,         VoiceLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorDeathDataCustom)
JTemplateArray(EAnimProp,   AnimProps, UNKNOWN_SIZE)
JTemplateValue(TID,         ModelLink)
JTemplateValue(SActorKey,   Name)
JTemplateValue(SFloatRange, PhysicsDelay)
JTemplateValue(TID,         SoundLink)
JTemplateValue(TID,         VoiceLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimBlendTimeApply)
JTemplateValue(FIXF32, BlendTime)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimClear)
JTemplateValue(UNKNOWN_TYPE, BlendOut)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimClearAllBut)
JTemplateValue(UNKNOWN_TYPE, BlendOut)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimBracketStop)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, TimeType)
JTemplateValue(UNKNOWN_TYPE, TimeVariant)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimBracketResume)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, TimeType)
JTemplateValue(UNKNOWN_TYPE, TimeVariant)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgAnimBracketStart)
JTemplateValue(UNKNOWN_TYPE, Closing)
JTemplateValue(UNKNOWN_TYPE, Content)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, Opening)
JTemplateValue(UNKNOWN_TYPE, TimeType)
JTemplateValue(UNKNOWN_TYPE, TimeVariant)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgRefTableDump)
JTemplateValue(UNKNOWN_TYPE, Space)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorRangeAbil)
JTemplateValue(INT32, Index)
JTemplateValue(TID,   Link)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorQueryResponse)
JTemplateValue(EActorResponseScope, Scope)
JTemplateValue(UNKNOWN_TYPE,        Send)
JTemplateValue(SActorKey,           Target)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorQuerySubject)
JTemplateValue(NAME,         Filters)
JTemplateValue(UNKNOWN_TYPE, Terms)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorStateInfo)
JTemplateValue(SActorKey,  Name)
JTemplateArray(SActorTerm, Terms, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAge)
JTemplateValue(UNKNOWN_TYPE, Age)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAnimBaselineState)
JTemplateValue(UNKNOWN_TYPE, State)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAbilTransport)
JTemplateValue(NAME, OtherName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAbilKey)
JTemplateValue(UNKNOWN_TYPE, Key)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAbilTrainProduced)
JTemplateValue(TID, Unit)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureVideoSetPaused)
JTemplateValue(UNKNOWN_TYPE, Paused)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureVideoSetTime)
JTemplateValue(FIXF32, Time)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureVideoSetFrame)
JTemplateValue(UNKNOWN_TYPE, Frame)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureVideoEnableTimeOverride)
JTemplateValue(UNKNOWN_TYPE, Enabled)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureVideoPlay)
JTemplateValue(UNKNOWN_TYPE, AttachMethods)
JTemplateValue(UNKNOWN_TYPE, Flags)
JTemplateValue(UNKNOWN_TYPE, FPS)
JTemplateValue(UNKNOWN_TYPE, SoundType)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureVideoSetTimeAll)
JTemplateValue(FIXF32, Time)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgUIStatusFlagSet)
JTemplateValue(UNKNOWN_TYPE, FlagType)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorProgressStage)
JTemplateArray(EAnimProp, AnimProps, UNKNOWN_SIZE)
JTemplateValue(FIXF32,    BlendTime)
JTemplateValue(TID,       Sound)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTransition)
JTemplateValue(FIXF32,       Duration)
JTemplateValue(UNKNOWN_TYPE, Type)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTimerKill)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTimerSet)
JTemplateValue(FIXF32, Duration)
JTemplateValue(NAME,   Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAnimFinished)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermKeys)
JTemplateValue(UNKNOWN_TYPE, Keys)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermKilledBy)
JTemplateValue(UNKNOWN_TYPE, UnitLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermIsStatus)
JTemplateValue(UNKNOWN_TYPE, Level)
JTemplateValue(NAME,         SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermHasScopeFlag)
JTemplateValue(UNKNOWN_TYPE, Flag)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermHasStatus)
JTemplateValue(NAME, SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermLevel)
JTemplateValue(UNKNOWN_TYPE, Level)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermModelSwapTo)
JTemplateValue(UNKNOWN_TYPE, ModelLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermModelVariation)
JTemplateValue(UNKNOWN_TYPE, Variation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermModelSwapFrom)
JTemplateValue(UNKNOWN_TYPE, ModelLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermModelEventName)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermModelName)
JTemplateValue(UNKNOWN_TYPE, ModelLink)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermCap)
JTemplateValue(UNKNOWN_TYPE, Cap)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermCompareField)
JTemplateValue(UNKNOWN_TYPE, Field)
JTemplateValue(UNKNOWN_TYPE, Operator)
JTemplateValue(UNKNOWN_TYPE, Target)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAt)
JTemplateValue(UNKNOWN_TYPE, At)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAnimName)
JTemplateValue(NAME, Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermAnimPlaying)
JTemplateValue(UNKNOWN_TYPE, AnimProps)
JTemplateValue(NAME,         Name)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermDeath)
JTemplateValue(UNKNOWN_TYPE, Death)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermFlyerHelper)
JTemplateValue(ECostDisplay, Display)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermGame)
JTemplateValue(UNKNOWN_TYPE, Game)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermEffectPeriodIndex)
JTemplateValue(INT32, Index)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermEffectExecuteIndex)
JTemplateValue(INT32, Index)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorTermEffectParent)
JTemplateValue(NAME, ParentName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetRotation)
JTemplateValue(UNKNOWN_TYPE, Rotation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetScale)
JTemplateValue(FIXF32,       BlendInDuration)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Scale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetRenderToTextureEnabled)
JTemplateValue(UNKNOWN_TYPE, Enabled)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetPosition2DH)
JTemplateValue(UNKNOWN_TYPE, Position2D)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetPositionH)
JTemplateValue(UNKNOWN_TYPE, h)
JTemplateValue(UNKNOWN_TYPE, Position2D)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetScaleAbsolute)
JTemplateValue(UNKNOWN_TYPE, Scale)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetTeamColorBlendPair)
JTemplateValue(FIXF32,       BlendInDuration)
JTemplateValue(UNKNOWN_TYPE, BlendType)
JTemplateValue(UNKNOWN_TYPE, DiffuseStart)
JTemplateValue(UNKNOWN_TYPE, DiffuseStop)
JTemplateValue(UNKNOWN_TYPE, EmissiveStart)
JTemplateValue(UNKNOWN_TYPE, EmissiveStop)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Priority)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetText)
JTemplateValue(NAME, Text)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetTeamColor)
JTemplateValue(FIXF32,       BlendInDuration)
JTemplateValue(UNKNOWN_TYPE, BlendType)
JTemplateValue(UNKNOWN_TYPE, Diffuse)
JTemplateValue(UNKNOWN_TYPE, Emissive)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Priority)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetShowStatusBar)
JTemplateValue(UNKNOWN_TYPE, ShowStatusBar)
JTemplateValue(UNKNOWN_TYPE, Status)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetSoundSuffix)
JTemplateValue(UNKNOWN_TYPE, Suffix)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetFacing)
JTemplateValue(UNKNOWN_TYPE, Facing)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetHeight)
JTemplateValue(UNKNOWN_TYPE, Height)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetCastShadows)
JTemplateValue(UNKNOWN_TYPE, CastShadows)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetBearings)
JTemplateValue(UNKNOWN_TYPE, Bearings)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetBearingsH)
JTemplateValue(UNKNOWN_TYPE, h)
JTemplateValue(UNKNOWN_TYPE, Position2D)
JTemplateValue(UNKNOWN_TYPE, Rotation)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetLocalTintColor)
JTemplateValue(FIXF32, BlendDuration)
JTemplateValue(SColor, Color)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetPosition)
JTemplateValue(UNKNOWN_TYPE, Position)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetPosition2D)
JTemplateValue(UNKNOWN_TYPE, Position2D)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetPhysicsState)
JTemplateValue(FIXF32,       Delay)
JTemplateValue(UNKNOWN_TYPE, State)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetMinimapVisibility)
JTemplateValue(UNKNOWN_TYPE, Show)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetOpacity)
JTemplateValue(FIXF32,       BlendInDuration)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Opacity)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetTextColor)
JTemplateValue(SColor, Color)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetVolume)
JTemplateValue(ESoundBlend, Blend)
JTemplateArray(SVolumeFade, ValueArray, UNKNOWN_SIZE)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgStatus)
JTemplateValue(NAME, SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetReverbBalanceRoom)
JTemplateValue(UNKNOWN_TYPE, ValueArray)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetPitch)
JTemplateValue(UNKNOWN_TYPE, Blend)
JTemplateValue(UNKNOWN_TYPE, ValueArray)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetReverbBalanceDirect)
JTemplateValue(UNKNOWN_TYPE, ValueArray)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgStatusSet)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureSelectByMatch)
JTemplateValue(UNKNOWN_TYPE, Source)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureSelectBySlot)
JTemplateValue(UNKNOWN_TYPE, Expression)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureSelectById)
JTemplateValue(UNKNOWN_TYPE, Id)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTexture)
JTemplateValue(UNKNOWN_TYPE, Slot)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgTextureProps)
JTemplateValue(UNKNOWN_TYPE, Props)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetVisibility)
JTemplateValue(UNKNOWN_TYPE, Visible)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetWalkAnimMoveSpeed)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetTransferOverrideAnim)
JTemplateValue(UNKNOWN_TYPE, AnimProps)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetTintColor)
JTemplateValue(FIXF32,       BlendInDuration)
JTemplateValue(UNKNOWN_TYPE, BlendType)
JTemplateValue(SColor,       Color)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Priority)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetTintColorBlendPair)
JTemplateValue(FIXF32,       BlendInDuration)
JTemplateValue(UNKNOWN_TYPE, BlendType)
JTemplateValue(UNKNOWN_TYPE, ColorStart)
JTemplateValue(UNKNOWN_TYPE, ColorStop)
JTemplateValue(UNKNOWN_TYPE, Label)
JTemplateValue(UNKNOWN_TYPE, Priority)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSetZ)
JTemplateValue(UNKNOWN_TYPE, Z)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetOffset)
JTemplateValue(UNKNOWN_TYPE, Value)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetPaused)
JTemplateValue(UNKNOWN_TYPE, Fade)
JTemplateValue(UNKNOWN_TYPE, State)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundSetMuted)
JTemplateValue(UNKNOWN_TYPE, Fade)
JTemplateValue(UNKNOWN_TYPE, State)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSignal)
JTemplateValue(UNKNOWN_TYPE, Bearings)
JTemplateValue(NAME,         SubName)
JTemplateEnd()

//----------------------------------------------------------------------------------------
JTemplateStruct(SActorMsgSoundAddDSP)
JTemplateValue(UNKNOWN_TYPE, DSP)
JTemplateEnd()
