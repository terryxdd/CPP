// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

// 必须原地修改，只允许使用额外常数空间。

// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
  int start = 0;
  int end = nums.size() - 1;
  int right = nums.size() - 1;
  while (right > 0) {
    if (nums[right - 1] <
        nums[right]) {  // find the first left value is less than right
      start = right;    // change start
      int i = right;
      while (i < nums.size() && nums[right - 1] < nums[i]) i++;
      int tmp = nums[right - 1];
      nums[right - 1] = nums[i - 1];
      nums[i - 1] = tmp;
      break;
    }
    right--;
  }

  // reverse vector from start to end.
  for (int j = 0; j <= (end - start) / 2; j++) {
    int tmp = nums[start + j];
    nums[start + j] = nums[end - j];
    nums[end - j] = tmp;
  }
}

int main() {
  std::vector<int> nums1 = {1, 3, 2};
  nextPermutation(nums1);

  for (int i = 0; i < nums1.size(); ++i) {
    std::cout << nums1[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
