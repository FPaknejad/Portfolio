//
//  main.cpp
//  testTaskManagerCLI
//
//  Created by Fatemeh Paknejad on 23.07.25.
//

#include <gtest/gtest.h>
#include "Task.h"

TEST(TaskTest, MarksDoneCorrectly) {
    Task t("Read a book", false);
    t.markDone();
    EXPECT_TRUE(t.isDone());
}
