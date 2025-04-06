#include <vector>
using namespace std;

class Solution {
public:
  // ["a", "bc", "def"] gets encoded as
  // 1,2,3,#abcdef
  string encode(vector<string> &strs) {
    if (strs.empty())
      return "";
    string res = "";
    for (string &str : strs) {
      res += to_string(str.length());
      res += ",";
    }
    res += "#";
    for (string str : strs) {
      res += str;
    }
    return res;
  }

  vector<string> decode(string s) {
    if (s == "")
      return {};
    vector<int> sizes;

    int i = 0;
    while (s[i] != '#') {
      string size = "";
      while (s[i] != ',') {
        size += s[i];
        i++;
      }
      sizes.push_back(stoi(size));
      i++;
    }
    i++;

    vector<string> res;
    for (int size : sizes) {
      res.push_back(s.substr(i, size));
      i += size;
    }
    return res;
  }
};
