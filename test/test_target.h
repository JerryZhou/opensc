#include "base/target.h"
#include "core/weakptr.h"

using namespace Base;

TEST(Target, constructor){
    Ptr<Base::Target> target = Base::Target::Create();
}

TEST(Target, weakptr){
    Ptr<Base::Target> target = Base::Target::Create();
    Core::WeakPtr<Base::Target> targetPtr(target);

    EXPECT_TRUE(targetPtr.isNull() == false);
    EXPECT_TRUE(targetPtr.get_unsafe() == target);
    Ptr<Base::Target> target2 = Base::Target::Create();
    targetPtr = target2;
    EXPECT_TRUE(targetPtr.get_unsafe() == target2);
    target2 = NULL;

    EXPECT_TRUE(targetPtr.isNull() == true);

    Core::WeakPtr<Base::Target> targetPtr2;
    EXPECT_TRUE(targetPtr2.isNull() == true);
    {
        Ptr<Base::Target> target3 = Base::Target::Create();
        targetPtr2 = target3;
        targetPtr = target3;
        EXPECT_TRUE(targetPtr2.get_unsafe() == targetPtr.get_unsafe());

        Core::WeakPtr<Base::Target> targetPtr3;
        EXPECT_TRUE(targetPtr3.get_unsafe() != targetPtr2.get_unsafe());

        targetPtr3 = targetPtr;
        EXPECT_TRUE(targetPtr3.get_unsafe() == targetPtr2.get_unsafe());
        target3 = NULL;
    }

    EXPECT_TRUE(targetPtr2.get_unsafe() == targetPtr.get_unsafe());
}

TEST(Target, weakptr_assign){
    Ptr<Base::Target> target = Base::Target::Create();
    Core::WeakPtr<Base::Target> targetPtr(target.get_unsafe());

    EXPECT_TRUE(targetPtr.isNull() == false);
    EXPECT_TRUE(targetPtr.get_unsafe() == target.get_unsafe());

    {
        Ptr<Base::Target> target2 = Base::Target::Create();
        targetPtr = target2.get_unsafe();
        EXPECT_TRUE(targetPtr.get_unsafe() == target2.get_unsafe());
    }
}

TEST(Target, weakptr_target_delete){
    Ptr<Base::Target> target = Base::Target::Create();
    Core::WeakPtr<Base::Target> targetPtr(target);

    EXPECT_TRUE(targetPtr.isNull() == false);
    EXPECT_TRUE(targetPtr.get_unsafe() == target);

    target = NULL;

    EXPECT_TRUE(targetPtr.isNull() == true);
    EXPECT_TRUE(targetPtr.get_unsafe() == NULL);
}

TEST(Target, weakptr_target_null){
    Ptr<Base::Target> target = Base::Target::Create();

    Core::WeakPtr<Base::Target> targetPtr1(target);
    Core::WeakPtr<Base::Target> targetPtr2(target);

    EXPECT_TRUE(targetPtr1.isNull() == false);
    EXPECT_TRUE(targetPtr1.get_unsafe() == target);

    targetPtr2 = NULL;

    EXPECT_TRUE(targetPtr1.isNull() == false);
    EXPECT_TRUE(targetPtr1.get_unsafe() == target);

    EXPECT_TRUE(targetPtr2.isNull() == true);
    EXPECT_TRUE(targetPtr2.get_unsafe() == NULL);
}
