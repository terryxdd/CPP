// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"

#include <algorithm>
#include <iostream>
#include <string>

using namespace std; 

int expand_center(string s, int left, int right) {
  int L = left, R = right;
  while (L >= 0 && R < s.length() && s[L] == s[R]) {
    L--;
    R++;
  }
  return R - L - 1;
}

string longestPalindrome(string s) {
  if (s.length() < 1) {
    return "";
  }
  int start = 0, end = 0;
  for (int i = 0; i < s.length(); i++) {
    int len1 = expand_center(s, i, i);
    int len2 = expand_center(s, i, i + 1);
    int len = max(len1, len2);
    if (len > end - start) {
      start = i - (len - 1) / 2;
      end = i + len / 2;
    }
  }
  return s.substr(start, end - start + 1);
}

int main() {
  string pal_str = "abba";
  std::string res = longestPalindrome(pal_str);
  std::cout << res << std::endl;
}