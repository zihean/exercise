//
//  leetcode_5.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/9.
//

#include "leetcode_5.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string Solution::longestPalindrome(string s) {
    {
        int lenOfStr = s.size();
            
        // 动态规划，使用dp记录i、j之间是否是回文子串
        vector<vector<bool>> dp(lenOfStr, vector<bool>(lenOfStr, false));
        for (int i = 0; i < lenOfStr; ++i) {
            dp[i][i] = true;
        }
        
        int maxB, maxLen;
        if (lenOfStr) {
            maxB = 0;
            maxLen = 1;
        } else {
            return "";
        }
        
        for (int i = 0; i < lenOfStr; ++i) {
            for (int j = 0; j <lenOfStr; ++j) {
                if (j <= i) {
                    continue;
                } else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    } else {
                        continue;
                    }
                } else {
                    if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    } else {
                        continue;
                    }
                }
                
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    maxB = i;
                }
            }
        }
        
        string ret = "";
        int e = maxB + maxLen;
        for (int i = maxB; i < e; ++i) {
            ret += s[i];
        }
        
        return ret;
    }
}


// aacabdkacaa
