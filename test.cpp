#include <gtest/gtest.h>
#include <optional>
#include <iostream>
#include <cstdlib>

#include "binarysearch.h"
#include "choicesort.h"


TEST(BinarySearchTest, BasicAssertions) {
    std::vector<uint32_t> nums;
    nums.resize(1 << 20);

    for (uint32_t i = 0; i < nums.size(); ++i) {
        nums[i] = i;
    }
    nums[404] = nums[403];
    std::vector<uint32_t> empty_vector;

    EXPECT_EQ(bs::binary_search(empty_vector, 1), std::nullopt);
    EXPECT_EQ(bs::binary_search(nums, 0), 0);
    EXPECT_EQ(bs::binary_search(nums, 15), 15);
    EXPECT_EQ(bs::binary_search(nums, 20), 20);
    EXPECT_EQ(bs::binary_search(nums, 21), 21);
    EXPECT_EQ(bs::binary_search(nums, 23), 23);
    EXPECT_EQ(bs::binary_search(nums, 24), 24);
    EXPECT_EQ(bs::binary_search(nums, 100), 100);
    EXPECT_EQ(bs::binary_search(nums, 101), 101);
    EXPECT_EQ(bs::binary_search(nums, 404), std::nullopt);
    EXPECT_EQ(bs::binary_search(nums, 10000), 10000);
    EXPECT_EQ(bs::binary_search(nums, 1000000), 1000000);
    EXPECT_EQ(bs::binary_search(nums, 5000000), std::nullopt);
}

TEST(ChoiceSortTest, BasicAssertions) {
    std::vector<uint32_t> nums{1, 7, 3, 0, 19, 347, 3435, 22, 7234, 346, 10, 11, 63, 33};
    std::vector<uint32_t> nums_sorted = nums;
    std::sort(nums_sorted.begin(), nums_sorted.end());

    std::vector<uint32_t> nums_mysorted = choicesort::sort(nums);

    EXPECT_EQ(nums_mysorted, nums_sorted);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}