#include <criterion/criterion.h>
#include "../include/core.hpp"
#include "../include/factory.hpp"
#include "../include/Error.hpp"

Test(core, core_tests)
{
    std::unique_ptr<Factory> factory = std::make_unique<Factory>();
    std::unique_ptr<Core> core = std::make_unique<Core>();
    std::vector<std::string> lines;

    IOperand *tmp = factory->createOperand(Int8, "20");
    IOperand *tmp2 = factory->createOperand(Int8, "30");
    cr_assert_eq(tmp2->toString(), "30");
    IOperand *tmp3 = *tmp + *tmp2;
    std::cout << tmp3->getType()<< " " << tmp3->toString() << std::endl;
    cr_assert_eq(stoi(tmp3->toString()), 50);
    core->stackPush(Int16, "300");
    core->stackPush(Int32, "400");
    cr_assert_eq(core->stackAssert(Int32, "400"), 0);
    core->regStore(Int32, "10");
    cr_assert_eq(core->stackAssert(Int16, "300"), 0);
    core->regLoad(Int32, "10");
    cr_assert_eq(core->stackAssert(Int32, "400"), 0);
    core->stackPush(Float, "40.50");
    core->stackPush(Float, "50.50");
    core->stackSwap(Float, "");
    cr_assert_eq(core->stackAssert(Float, "40.50"), 0);
    core->stackPush(Double, "100.550");
    core->stackPush(Double, "100.500");
    core->stackSub(Int8, "");
    cr_assert_eq(core->stackAssert(Double, "0.05"), 0);
    core->stackPush(Int32, "33");
    core->stackPush(Int32, "42");
    core->stackAdd(Int32, "");
    core->stackPush(Float, "44.55");
    core->stackMul(Int8, "");
    cr_assert_eq(core->stackAssert(Float, "3341.25"), 0);
}

Test(Int, int_operations)
{
    std::unique_ptr<Factory> factory = std::make_unique<Factory>();
    std::unique_ptr<Core> core = std::make_unique<Core>();

    core->stackPush(Int8, "100");
    core->stackPush(Int8, "20");
    core->stackAdd(Int8, "");
    cr_assert_eq(core->stackAssert(Int8, "120"), 0);
    core->stackPush(Int16, "50");
    core->stackSub(Int8, "");
    cr_assert_eq(core->stackAssert(Int8, "70"), 0);
    core->stackPush(Int16, "2");
    core->stackMul(Int8, "");
    cr_assert_eq(core->stackAssert(Int16, "140"), 0);
    core->stackPush(Int32, "2");
    core->stackDump(Int8, "");
    core->stackDiv(Int8, "");
    cr_assert_eq(core->stackAssert(Int16, "70"), 0);
}

Test(Float, float_operations)
{
    std::unique_ptr<Factory> factory = std::make_unique<Factory>();
    std::unique_ptr<Core> core = std::make_unique<Core>();

    core->stackPush(Float, "50.50");
    core->stackPush(Float, "20.20");
    core->stackAdd(Int8, "");
    cr_assert_eq(core->stackAssert(Float, "70.7"), 0);
    core->stackPush(Float, "50.50");
    core->stackSwap(Int8, "");
    core->stackSub(Int8, "");
    core->stackDump(Int8, "");
    core->stackPush(Float, "-1");
    core->stackMul(Int8, "");
    core->stackDup(Int8, "");
    core->stackDump(Int8, "");
    core->stackDiv(Int8, "");
}

