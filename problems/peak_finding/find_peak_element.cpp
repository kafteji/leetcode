// https://leetcode.com/problems/find-peak-element/

#include <gtest/gtest.h>
#include <limits>
#include <vector>

class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    size_t right_edge = nums.size() - 1;
    size_t left_edge = 0;
    size_t mid = 0;
    while (left_edge <= right_edge) {
      mid = left_edge + (right_edge - left_edge) / 2;
      if ((mid != 0) && (nums[mid - 1] > nums[mid])) {
        right_edge = mid - 1;
      } else if ((mid != nums.size() - 1) && (nums[mid] < nums[mid + 1])) {
        left_edge = mid + 1;
      } else {
        break;
      }
    }
    return mid;
  }
};

TEST(find_peak_element, test_normal_array) {
  Solution s;
  std::vector<int> v{1, 2, 3, 1};
  auto result = s.findPeakElement(v);
  EXPECT_EQ(result, 2);
}

TEST(find_peak_element, test_array_with_one_elemnt) {
  Solution s;
  std::vector<int> v{std::numeric_limits<int>::min() + 500};
  auto result = s.findPeakElement(v);
  EXPECT_EQ(result, 0);
}

TEST(find_peak_element, test_array_with_peak_on_left_side) {
  Solution s;
  std::vector<int> v{3, 4, 3, 2, 1};
  auto result = s.findPeakElement(v);
  EXPECT_EQ(result, 1);
}

TEST(find_peak_element, test_array_with_peak_on_right_edge) {
  Solution s;
  std::vector<int> v{1, 2};
  auto result = s.findPeakElement(v);
  EXPECT_EQ(result, 1);
}
