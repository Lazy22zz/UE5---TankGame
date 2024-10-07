# Tank
- project
- 
1, compoment, attachment, rootcompoment
  - ![屏幕截图 2024-09-26 202044](https://github.com/user-attachments/assets/b41cb2ea-141b-433b-a16e-504c509ac466)
  - 
2, forward declarartion
  - avoid forgetting to add #include .h file if we just want to add a pointer
  - ![屏幕截图 2024-09-26 201744](https://github.com/user-attachments/assets/076dc30a-dd80-4fb4-85f4-4f9cf603abce)
  - ![屏幕截图 2024-09-26 201756](https://github.com/user-attachments/assets/f9a4129e-afba-487d-bb74-fc3d54347e2d)
  - ![屏幕截图 2024-09-26 202337](https://github.com/user-attachments/assets/fbf24f0a-645e-49fa-8ad1-68eb948adc86)
  - 
3, how to use c++ to add capsule compomenet, staticmesh component, projectileSpawnPoint(scenecomponent) to the root compoment
  - ![屏幕截图 2024-09-26 204912](https://github.com/user-attachments/assets/bc5d12fe-b8da-461b-8741-8ab6e7167bb1)
  - ![屏幕截图 2024-09-26 211600](https://github.com/user-attachments/assets/86eae99d-feb1-479f-8485-461a20850b64)
  - ![屏幕截图 2024-09-26 211549](https://github.com/user-attachments/assets/0907af79-2b21-4579-95d1-6eda20e71c8f)
  - 
4, visual scripting interface: create a blueprint inheritate the c++ class
  - ![屏幕截图 2024-09-27 200924](https://github.com/user-attachments/assets/af820ba0-13a5-4c9b-a241-11bcd9d0d049)
  - 
5, UPROPERTY SPECIFIES and Enable editing in event graph
  - instance: gaming running scene
  - default: default base value of base pawn.
  - ![屏幕截图 2024-09-27 202001](https://github.com/user-attachments/assets/056f67cb-91a6-4b96-ae34-8b25c07b883e)
  - ![屏幕截图 2024-09-27 203648](https://github.com/user-attachments/assets/cfc74573-c15e-4561-95ee-c19e04d7940e)
  - 
6, Exposing The Components
  - creating your specific own pannel in your blueprint "Details"
  - ![屏幕截图 2024-09-27 211729](https://github.com/user-attachments/assets/f2408889-1f09-469d-8559-4c74cefb4de4)
  - ![屏幕截图 2024-09-27 211659](https://github.com/user-attachments/assets/c6039ad3-3745-444f-beb6-e951c43988a6)
  - 
7, Deriving a child class
  - purpose: because of child class inheritate from baspawn, but their child has their own specific properties.
  - ![屏幕截图 2024-09-28 200810](https://github.com/user-attachments/assets/8386fea7-33f6-4c8b-b76c-3e21d33b522e)
  - 
8, creating a child class for tank
  - give a spring arm and camera component
  - ![屏幕截图 2024-09-28 202900](https://github.com/user-attachments/assets/25cf66ac-83ea-4f26-b6be-bed72690ca87)
  - ![屏幕截图 2024-09-28 202916](https://github.com/user-attachments/assets/4afdb403-a746-474b-8bfd-6c93eef4284c)
  - Dont forget to give a constructor!!!!! (ATank())
  - Dont forget to add releverant .h file for components
  - after the coding, you will get a new class setting
  - ![屏幕截图 2024-09-28 203527](https://github.com/user-attachments/assets/a4847161-c17c-430c-9bfb-5bda70fb974e)
  -  Hint: when changing the view, dont move the camera component, just the springarm, cuz springarm will avoid the obstacle.
  -  
9, possessing the pawn
   - enable to pick which pawn that player start, pawn-> auto possess player
   - ![屏幕截图 2024-09-28 205050](https://github.com/user-attachments/assets/fcff0182-e5ba-4740-b96c-592398e28e8c)
-
10, Handling the input : Axix Mapping (of tank)
  - because our basepwan has two childs, one is tank, one is turret, so we dont need turret can access player input,
  - so, we need to move virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override  to tank.h
  - Hint in ue5 , we need super:: for .cpp to clarify the parents' friend virtual function Super::SetupPlayerInputComponent(PlayerInputComponent)
  - Hint: project setting -> input -> Axix Mapping
  -  ![屏幕截图 2024-09-28 211931](https://github.com/user-attachments/assets/7a0f102b-458e-483b-8a5c-dec81d2d6249)
  - PlayerInputComponent -> BindAxis(TEXT("MoveForward"), this, &ATank::Move), this mean this pawn, & means address of the function.
 - 
11, Local offset : local vs world direction
  - as we all know, local 's direction is sometimes different than world's direction.
  - ![屏幕截图 2024-09-28 213738](https://github.com/user-attachments/assets/ad173245-caa0-49f3-9639-76fdb73415eb)
  - AddLocalOffset()
  - ![屏幕截图 2024-09-28 214716](https://github.com/user-attachments/assets/22161027-5102-42c4-95e3-02e222ac05f7)
 - 
12, decide the tank moving speed
  - DeltaTime is different in frame works, based on the working of functions by CPU
  - ![屏幕截图 2024-09-29 200011](https://github.com/user-attachments/assets/e49771f4-7766-4367-b2b5-8aa28e36aef5)
  - so the DeltaLocation = deltaTime * speed * value, (value decided by axix mapping)
  - To find the deltaTime of the pawn, using: UGameplayStatics::GetWorldDeltaSeconds(    )
  - ![屏幕截图 2024-09-29 202541](https://github.com/user-attachments/assets/37eac70f-e578-4554-a943-86c1ac3892dd)
  - ![屏幕截图 2024-09-29 202531](https://github.com/user-attachments/assets/c845a025-6fa6-49bc-8c5d-45fa06fd7fb1)
 - 
13, Sweeping
  - Identify does two object has collision
  - only require the rootcomponent collison is on or off
  - collision -> collision present.
  - in addlocaloffset, addlocalrotation, true means the enable the collision.
 - 
14, decide the tank rotate/turn
  - playerinput component bindaxis
  - Create a TurnRate variable
  - Create Turn function
  - Using FRotator 
  - using AddActorLocalRotation(DeltaRotation, true)
  - ![屏幕截图 2024-09-29 210616](https://github.com/user-attachments/assets/5b58233a-4420-4ae8-beb5-e909c0c85d5c)
 - -
15, Hit result deisplay & cast
  - before to start to show cursor, turret no need controller action, move
  -   protected:
	virtual void BeginPlay() override;
  - to tank.h
  - APlayerController::GetHitResultUnderCursor
  - APawn::GetController
  - issue: APawn:: controller is AController, is parent; APlayerController, is child.
  - cast<a>(b), a: type to change, b: pointer, (the function pointed by parent)
  - ![屏幕截图 2024-09-29 213315](https://github.com/user-attachments/assets/1ddb868f-ff8a-4699-aff6-f6e2842649ef)
  - ![屏幕截图 2024-09-29 213425](https://github.com/user-attachments/assets/1e2db918-edd1-4a31-846b-78349c341f84)
  - move tick function into tank.h, cuz no need it in basepawn
  - check each tick, if click action exist, get info of HitResult
  - ![屏幕截图 2024-09-29 220215](https://github.com/user-attachments/assets/95d35202-abec-4cd4-8466-b80132ab5d7f)
 - ![屏幕截图 2024-09-29 220221](https://github.com/user-attachments/assets/411804da-a77e-4bc4-98fe-863fe793d160)
- if hitresult get, we can show it by DrawDebugSphere
- for the cursor, we can use HitResult.ImpactPoint to display
- reference for more details in ue5: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Chaos/Chaos/FDebugDrawQueue/DrawDebugSphere?application_version=5.4
- ![屏幕截图 2024-09-29 221315](https://github.com/user-attachments/assets/c3b3cee1-3363-4429-af60-9ce400286d3f)
- ![2024-09-29221618-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/c35855e4-6946-4e0f-8875-c7b70b8d4e3f)
- 
16, Enable the turret rotate follow the mouse cursor
  - find the vector: TraceHitLocation - TurretLocation
  - set the rotator: LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f)
  - Hint: why only need the yaw?
  -  ![屏幕截图 2024-09-30 205339](https://github.com/user-attachments/assets/19fc189a-62e3-4d04-a7f9-ccd4b29041e1)
  -  use the new rotation for the turretmesh: TurretMesh->SetWorldRotation(LookAtRotation)
  -  issue 1: wired losing light trace
  -  

https://github.com/user-attachments/assets/22e5c4e2-ac09-4c13-bf25-6e16be3546f6
  - issue 2: fuzzy snapping, 
  - **it looks like ue5.4 fix this issue, so the source code does not use the solution 2's code.**

https://github.com/user-attachments/assets/bc1685ca-825e-4768-bf1c-721007400895
  - solution 1: add blocking volumn to the edge of the world. Place actors panel->volumn->blocking volumn, make the visibility (in collision presents) is block.
  - solution 2: using FMath::RInterpTo(TurretMesh->GetComponentRotation(),LookAtRotation, UGameplayStatics::GetWorldDeltaSeconds(this), 5.f); 5.f can be changed by what you want, to decide the speed of interpto.
  - solution1:
  - 

https://github.com/user-attachments/assets/3f8b62ac-3bc1-4a8f-b583-25b62184caa7


-
17， create tower class, and enable when tank is in its firerange, they will look at tank
- create a tower class, tick function and beginplay function
- in private, create a class ATank* Tank, to eanble to get Tank's location
- find the distance, using FVector::Dist(), and GetWorldLocation()
- in beginplay function, identify the tank first, which is UGamePlayStatics::GetPlayerPawn(this, 0)
- because ATank is a child, so we need to use cast<>()
- create a private property: firerange, editeverywhere
- compare, if less than the range, go for the rotateturret(FVector pointLocation), craeted in Tank.h
- 
18, Draw a fire function
- because tower and tank has same fire() option, create it in basepawn
- using Action Mappings (similiar to the axis mapping), BindAction(TEXT(“Fire”), IE_Pressed
 OR IE_Released, this, callback), {callback which function}
- using the draw debug sphere for fire() function:https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Chaos?application_version=5.1
- 
19, Create a Timers
- Purpose: enable each 2 second, the tower will fire if the tank is in its firerange
- using  GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true); *In the BeginPlay()*
- REF:https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-timers?application_version=4.27
- because we get check tank and wheter the tank is in the firerange, so we need to rearrange a new InFireRange() to avoid duplicated codes.
-
20, set a projectile class & make it a blueprint
- create a new actor class, which is used for projectile
- remeber to set it to 1, blueprintvisible; 2, rootcomponent is it
-
21, spawn the projectile
- using GetWorld()->SpawnActor<>(), SpawnActor<AProjectile>(UClass, Location, Rotation)
- TSubclassOf<class AProjectile> ProjectileClass, is going to create a variable that hold the reference to any subclass of AProjectile, for helping to identify which type of projectile to spawn in the game.
-
22, move the projectile
- create a new component in projectile files, class UProjectileMovementComponent* ProjectileMoveComp;
- give it two initial properties, which are ProjectileMoveComp -> MaxSpeed = 1300.f; ProjectileMoveComp -> InitialSpeed = 1300.f;
- Hints: movement is not part of Root Component!!!!!
-
23, Hit Event
- *Read the ref first!!!* :https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/Components/UPrimitiveComponent/OnComponentHit?application_version=4.27
- using ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
- for the UFunction, we need to call back a function, which holds UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit
- !!!! Hit event is high level, staticmeshcomponent is inherited by UprimitiveComponent, so we can use !!!!!
- ![屏幕截图 2024-10-03 215623](https://github.com/user-attachments/assets/f8662264-7feb-4bd3-9cc7-08a2be50de47)
-  Delegate is a type of event that allows for communication between different parts of your game. Delegates are essentially function pointers that can be bound to one or more functions, enabling event-driven programming. Delegates are used to handle events. When an event occurs, the delegate broadcasts it to all bound functions, which then execute in response
-
24, Health Component
- We need to identify two components :
- UActorComponent : No transform, No attachment
- USceneComponent : Has transform, Support attachment
- ![屏幕截图 2024-10-04 134331](https://github.com/user-attachments/assets/b61051cc-9f48-4d8b-8435-33997619b611)
- 1, So we use UActorComponent for Health Component
- 2, using the OnTakeAnyDamage Delegate, which is OnTakeAnyDamage.AddDynamic(this, callback function)
- 3, create the callback function: DamageTaken(AActor *DamagedActor, float Damage, const UDamageType *DamageType, class AController *Instigator, AActor *DamageCauser)
- 4, then we need to bind the function to which pawn, using: GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken)
- Hint: Because the health component can be multiple objects, so GetOwner() will find which pawn has HealthComponent, if it does, just use it in startGame.
-
25, Apply Damage
- using UGameplayStatics::ApplyDamage(Damaged Actor, Damage Amount, Instigator, Damage Causer, Damage Type)
- use ApplyDamage function under the OnHit()
- Damaged Actor : OtherActor (In clarify in OnHit())
- Damage Amout : Need to be clarify
- Instigator : type of controller, and it will find the projectiles' controllers
- !!! We know that projectiles' nums, location will be changed by player, so we need to setOwner() by each new projectile created!!!
- In Fire() function of BasePawn(), we created the projectile, so we need to record these projectils!
- using: auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation); projectile -> SetOwner(this)
- then in OnHit(), do auto MyOwner = GetOwner(); if (MyOwner == nullptr) return; auto MyOwnerInstigator = MyOwner->GetInstigatorController();
- Damage Cusor: This
- Damage Type: because we didnt create multi damage types, so we just need to use: auto DamageTypeClass = UDamageType::StaticClass();
- Ref :https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/GameFramework/UDamageType/?application_version=4.27
- the :UGameplayStatics::ApplyDamage(OtherActor, Damage_Amount, MyOwnerInstigator, this, DamageTypeClass);
- and using Destory() to remove the shooted-projectile
- also, we can use UE_LOG() in DamageTaken() of Health.h to see the status of tank.
-
26， The Game Mode Class
- We need to identify two classes:
- 1, AGameModeBase : Rules of the game, win condition
- 2, AGameMode : Match state, Multiplayer matches
- ![屏幕截图 2024-10-05 194636](https://github.com/user-attachments/assets/1cfd282a-8c53-4fd1-b563-e8a7d622d8b8)
- create a blueprint base on this c++ class, called ToonBaseGame
- delte the tank in the scene
- change the gamemode to the created one, in project settings.
- let game strater to be the pawn tank appear, change the default pawn class in bp_toonbasegamemode
-
27, Actor died
- ![屏幕截图 2024-10-06 103030](https://github.com/user-attachments/assets/a45c215f-50a5-491f-8393-4e61e1cfe113)
- step 1, create a HandleDestruction() for baseActor() function to handle sound, visula effect
- use super::HandleDestruction() callback in tank.h and tower.h
- for tower, we need destroy() to disappear the tower object
- for tank, we need SetActorHiddenInGame(true) and SetActorTickEnabled(false) to only allow player have a died vision if tank is destroy
- step 2, create a ActorDied(AActor* DeadActor) in the toontankgamemode
- check the deadactor is a tank or not, create class ATank* Tank in private, and create a protected: beginplay() to initialize it. 
- use super::BeginPlay() from the system
- use Tank = Cast<ATank>(UGamePlayStics::GetPlayerPawn(this, 0)) to initialize the Tank. {remember ATank is ACtor, which is inherited by APawn}
- then in ActorDied(AActor* DeadActor), check if deadactor == tank, (no need to check the tank is null)
- if so, tank->handledestruction, and tank -> disableInput
- because we need to use APlayerController *PlayerController in disableInput, go back to Tank.h
- the name PlayerControllerref's name is awful, so select it, use f2 to total rename
- then we need to see does this playercontroller exsit or not, so we need to create a get function {const} to get the private property in tank.h
- then make show mosue cursor disabled
- ![屏幕截图 2024-10-06 115018](https://github.com/user-attachments/assets/6185ac4f-f950-449f-b979-893fc2b5810c)
- for tower, just need else if() and call the handledestruction()
- step 3, enable gamemode in the health component, which is class AToonTanksGameMode* GameMode;
- use actor died if hp is 0 or less
- ![屏幕截图 2024-10-06 142612](https://github.com/user-attachments/assets/3ec2a9e5-456f-41c7-9521-9ee15705d5f9)
-
28， create a player controller class
- purpose: Enable/disable input, Set the mouse cursor type
- step 1, for Enable/disable input
- create a public function :void SetPlayerEnabledState(bool bPlayerEnabled);
- using if bPlayerEnabled, GetPawn()->EnableInput(this); and GetPawn()->DisableInput(this);
- then in gamemode.h, we need to use this new function to replace
- if (Tank->GetTankPlayerController())
        {
            Tank -> DisableInput(Tank->GetTankPlayerController());
            Tank->GetTankPlayerController()->bShowMouseCursor = false;
        }
- ![屏幕截图 2024-10-07 091714](https://github.com/user-attachments/assets/eaef2bec-5a95-4822-9626-8cdc49a11f37)
- create a new class: class AToonTanksPlayerController* ToonTanksPlayerController;
- using UGamePlayStatics::GetPlayerController
- ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this,0));
- replace by
- ![屏幕截图 2024-10-07 092231](https://github.com/user-attachments/assets/266126db-790a-4054-8a40-208a579a3bf2)
- step 2, let :bShowMouseCursor = bPlayerEnabled; in void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
- and in bp_controller, change default mouse cursor to crosshair
-
29, starting the game
- purpose : disable the input when game start, until timer count to be it is.
- create a gamestart() function in gamemode.h
- then put it in beginplay()
- move rest in the gamestrt()
- ![屏幕截图 2024-10-07 094659](https://github.com/user-attachments/assets/c5114ba3-d9f3-4c7a-8125-169a50bdb299)
- set a timer:
- using GetWorldTimerManager().SetTimer(Timer Handle, Timer Delegate, Play Rate, Looping)
- Timer Handle : need to initialize, such as FTimerHandle PlayerEnableTimerHandle;
- Timer Delegate : need to initialize by FTimerDelegate::CreateUObject()
- Play Rate : Time_Start
- Looping : ture or flase
- for FTimerDelegate::CreateUObject(User Object, Callback, Inputs)
- User Object: ToonTanksPlayerController
- Call back: &AToonTanksPlayerController::SetPlayerEnabledState
- Inputs: true
- ![屏幕截图 2024-10-07 100810](https://github.com/user-attachments/assets/abc51625-84e8-463d-8602-812ead4e93e0)
-
30, 






































