# Tank
- project 
1, compoment, attachment, rootcompoment
  - ![屏幕截图 2024-09-26 202044](https://github.com/user-attachments/assets/b41cb2ea-141b-433b-a16e-504c509ac466)
2, forward declarartion
  - avoid forgetting to add #include .h file if we just want to add a pointer
  - ![屏幕截图 2024-09-26 201744](https://github.com/user-attachments/assets/076dc30a-dd80-4fb4-85f4-4f9cf603abce)
  - ![屏幕截图 2024-09-26 201756](https://github.com/user-attachments/assets/f9a4129e-afba-487d-bb74-fc3d54347e2d)
  - ![屏幕截图 2024-09-26 202337](https://github.com/user-attachments/assets/fbf24f0a-645e-49fa-8ad1-68eb948adc86)
3, how to use c++ to add capsule compomenet, staticmesh component, projectileSpawnPoint(scenecomponent) to the root compoment
  - ![屏幕截图 2024-09-26 204912](https://github.com/user-attachments/assets/bc5d12fe-b8da-461b-8741-8ab6e7167bb1)
  - ![屏幕截图 2024-09-26 211600](https://github.com/user-attachments/assets/86eae99d-feb1-479f-8485-461a20850b64)
  - ![屏幕截图 2024-09-26 211549](https://github.com/user-attachments/assets/0907af79-2b21-4579-95d1-6eda20e71c8f)
4, visual scripting interface: create a blueprint inheritate the c++ class
  - ![屏幕截图 2024-09-27 200924](https://github.com/user-attachments/assets/af820ba0-13a5-4c9b-a241-11bcd9d0d049)
5, UPROPERTY SPECIFIES and Enable editing in event graph
  - instance: gaming running scene
  - default: default base value of base pawn.
  - ![屏幕截图 2024-09-27 202001](https://github.com/user-attachments/assets/056f67cb-91a6-4b96-ae34-8b25c07b883e)
  - ![屏幕截图 2024-09-27 203648](https://github.com/user-attachments/assets/cfc74573-c15e-4561-95ee-c19e04d7940e)
6, Exposing The Components
  - creating your specific own pannel in your blueprint "Details"
  - ![屏幕截图 2024-09-27 211729](https://github.com/user-attachments/assets/f2408889-1f09-469d-8559-4c74cefb4de4)
  - ![屏幕截图 2024-09-27 211659](https://github.com/user-attachments/assets/c6039ad3-3745-444f-beb6-e951c43988a6)
  - 
7, Deriving a child class
  - purpose: because of child class inheritate from baspawn, but their child has their own specific properties.
  - ![屏幕截图 2024-09-28 200810](https://github.com/user-attachments/assets/8386fea7-33f6-4c8b-b76c-3e21d33b522e)
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
11, Local offset : local vs world direction
  - as we all know, local 's direction is sometimes different than world's direction.
  - ![屏幕截图 2024-09-28 213738](https://github.com/user-attachments/assets/ad173245-caa0-49f3-9639-76fdb73415eb)
  - AddLocalOffset()
  - ![屏幕截图 2024-09-28 214716](https://github.com/user-attachments/assets/22161027-5102-42c4-95e3-02e222ac05f7)







