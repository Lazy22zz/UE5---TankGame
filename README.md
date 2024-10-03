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
21, 



























