#include "base/target.h"

using namespace Base;

TEST(Target, constructor){
    Base::Target target; { 
	Base::Target targetTo;
    }
}

TEST(Target, weakptr){
    Base::Target target;
    Base::TargetPtr<Base::Target> targetPtr(&target);

    EXPECT_TRUE(targetPtr.isNull() == false);
    EXPECT_TRUE(targetPtr.rawPtr() == &target);

    {
	Base::Target target2;
	targetPtr = &target2;
	EXPECT_TRUE(targetPtr.rawPtr() == &target2);
    }

    EXPECT_TRUE(targetPtr.isNull() == true);

    Base::TargetPtr<Base::Target> targetPtr2;
    EXPECT_TRUE(targetPtr2.isNull() == true);
    {
	Base::Target target3;
	targetPtr2 = &target3;
	targetPtr = &target3;
	EXPECT_TRUE(targetPtr2.rawPtr() == targetPtr.rawPtr());

	Base::TargetPtr<Base::Target> targetPtr3;
	EXPECT_TRUE(targetPtr3.rawPtr() != targetPtr2.rawPtr());


	targetPtr3 = targetPtr;
	EXPECT_TRUE(targetPtr3.rawPtr() == targetPtr2.rawPtr());
    }

    EXPECT_TRUE(targetPtr2.rawPtr() == targetPtr.rawPtr());
}

TEST(Target, weakptr_assign){
    Base::Target target;
    Base::TargetPtr<Base::Target> targetPtr(&target);

    EXPECT_TRUE(targetPtr.isNull() == false);
    EXPECT_TRUE(targetPtr.rawPtr() == &target);

    {
	Base::Target target2;
	targetPtr = &target2;
	EXPECT_TRUE(targetPtr.rawPtr() == &target2);
    }
}

TEST(Target, weakptr_target_delete){
    Base::Target *target = new Base::Target();
    Base::TargetPtr<Base::Target> targetPtr(target);

    EXPECT_TRUE(targetPtr.isNull() == false);
    EXPECT_TRUE(targetPtr.rawPtr() == target);

    delete target;

    EXPECT_TRUE(targetPtr.isNull() == true);
    EXPECT_TRUE(targetPtr.rawPtr() == NULL);
}

TEST(Target, weakptr_target_null){
    Base::Target target;

    Base::TargetPtr<Base::Target> targetPtr1(&target);
    Base::TargetPtr<Base::Target> targetPtr2(&target);

    EXPECT_TRUE(targetPtr1.isNull() == false);
    EXPECT_TRUE(targetPtr1.rawPtr() == &target);

    targetPtr2 = NULL;

    EXPECT_TRUE(targetPtr1.isNull() == false);
    EXPECT_TRUE(targetPtr1.rawPtr() == &target);

    EXPECT_TRUE(targetPtr2.isNull() == true);
    EXPECT_TRUE(targetPtr2.rawPtr() == NULL);
}
