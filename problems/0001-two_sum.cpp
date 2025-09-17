/*
 *  https://leetcode.com/problems/two-sum/
 */

#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map{};
    const int size = nums.size();
    for (int i = 0; i < size; ++i) {
      const auto delta = map.find(target - nums[i]);
      if (delta != map.end()) {
        return {delta->second, i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};

TEST(two_sum, leetcode_examples) {
  Solution solution;
  std::vector<int> vec1{2, 7, 11, 15}, vec2{3, 2, 4}, vec3{3, 3};

  EXPECT_EQ(solution.twoSum(vec1, 9), std::vector<int>({0, 1}));
  EXPECT_EQ(solution.twoSum(vec2, 6), std::vector<int>({1, 2}));
  EXPECT_EQ(solution.twoSum(vec3, 6), std::vector<int>({0, 1}));
}