#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    if (nums.size() == 1) {
      return false;
    }
    std::unordered_map<int, size_t> occurences = {};
    for (auto x : nums) {
      if (occurences[x]) {
        return true;
      }
      occurences[x] = 1;
    }
    return false;
  }
};

TEST(contains_duplicate, leetcode_examples) {
  Solution solution;
  std::vector<int> vec1{1, 2, 3, 1}, vec2{1, 2, 3, 4},
      vec3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  EXPECT_TRUE(solution.containsDuplicate(vec1));
  EXPECT_FALSE(solution.containsDuplicate(vec2));
  EXPECT_TRUE(solution.containsDuplicate(vec3));
}
