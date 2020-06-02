// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// 示例:

// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, string> dmap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                    {'5', "jkl"}, {'6', "mno"}, {'7', "qprs"},
                                    {'8', "tuv"}, {'9', "wxyz"}};
vector<string> letterCombinations(string digits) {
  int len = digits.size();

  if (!len) {
    return {};
  }

  vector<string> ans;
  if (len == 1) {
    string str = dmap[digits[0]];
    int len = str.size();
    int i;
    string tmp = "";
    for (i = 0; i < len; i++) {
      ans.push_back(tmp + str[i]);
    }
    return ans;
  } else {
    vector<string> last = letterCombinations(digits.substr(1, len - 1));
    string strthis = dmap[digits[0]];
    int lenthis = strthis.size();
    int lenlast = last.size();
    int j, k;
    for (j = 0; j < lenthis; j++) {
      for (k = 0; k < lenlast; k++) {
        ans.push_back(strthis[j] + last[k]);
      }
    }
    return ans;
  }
}

int main() {
  std::string phonenum = "245";
  letterCombinations(phonenum);
}