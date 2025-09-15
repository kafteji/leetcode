/*
 * https://leetcode.com/problems/find-a-peak-element-ii/
 */
#include <gtest/gtest.h>
#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
    const int num_rows = mat.size();
    const int num_columns = mat[0].size();
    int right_column = mat[0].size() - 1;
    int left_column = 0;
    int row = 0;
    int mid_column = 0;
    while (left_column <= right_column) {
      auto max = std::numeric_limits<int>::min();
      mid_column = left_column + (right_column - left_column) / 2;
      for (auto i = 0; i < num_rows; ++i) {
        if (max < mat[i][mid_column]) {
          max = mat[i][mid_column];
          row = i;
        }
      }
      if ((mid_column > 0) and (mat[row][mid_column - 1] > max)) {
        right_column = mid_column - 1;
      } else if ((mid_column < num_columns - 1) and
                 (mat[row][mid_column + 1] > max)) {
        left_column = mid_column + 1;
      } else {
        break;
      }
    }
    return {row, mid_column};
  }
};

TEST(find_peak_element_2d, test_2_x_2_matrix) {
  Solution s;
  std::vector<std::vector<int>> matrix = {{1, 4}, {3, 2}};
  auto result = s.findPeakGrid(matrix);
  std::vector<std::vector<int>> expected_values = {{0, 1}, {1, 0}};
  EXPECT_TRUE((std::find(expected_values.cbegin(), expected_values.cend(),
                         result) != expected_values.cend()));
}

TEST(find_peak_element_2d, test_3_x_3_matrix) {
  Solution s;
  std::vector<std::vector<int>> matrix = {
      {10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
  auto result = s.findPeakGrid(matrix);
  std::vector<std::vector<int>> expected_values = {{1, 1}, {2, 2}};
  EXPECT_TRUE((std::find(expected_values.cbegin(), expected_values.cend(),
                         result) != expected_values.cend()));
}

TEST(find_peak_element_2d, test_2_x_5_matrix) {
  Solution s;
  std::vector<std::vector<int>> matrix = {{10, 50, 40, 30, 20},
                                          {1, 500, 2, 3, 4}};
  auto result = s.findPeakGrid(matrix);
  std::vector<int> expected_value = {1, 1};
  EXPECT_EQ(expected_value, result);
}
