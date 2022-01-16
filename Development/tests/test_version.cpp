#include "lib.h"

#include <gtest/gtest.h>

TEST(LibTest, Version_greater_than_0) {
	EXPECT_TRUE( version() > 0);
}
