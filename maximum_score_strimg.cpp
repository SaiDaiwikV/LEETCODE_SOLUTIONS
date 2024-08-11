/*You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.*/

// solution : 

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        int ac = 0;
        int bc = 0;
        int lesser = std::min(x, y);
        int res = 0;

        for (char c : s) {
            if (c > 'b') {
                res += std::min(ac, bc) * lesser;
                ac = 0;
                bc = 0;
            } else if (c == 'a') {
                if (x < y && bc > 0) {
                    bc--;
                    res += y;
                } else {
                    ac++;
                }
            } else {
                if (x > y && ac > 0) {
                    ac--;
                    res += x;
                } else {
                    bc++;
                }
            }
        }
        res += std::min(ac, bc) * lesser;
        return res;
    }
};

int main() {
    Solution solution;
    std::string s = "abacb";
    int x = 4, y = 6;
    std::cout << "Maximum gain: " << solution.maximumGain(s, x, y) << std::endl;
    return 0;
}
