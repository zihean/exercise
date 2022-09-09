//
//  leetcode_3.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/9.
//

#include "leetcode_3.hpp"
#include <unordered_map>
#include <iostream>

int Solution::lengthOfLongestSubstring(string s) {
    {
       int len = s.size();
       int b = -1;
       int maxLen = 0;
       unordered_map<char, int> hashmap;

        // 利用哈希实现滑动窗口
       for (int i = 0; i < len; ++i) {
           auto it = hashmap.find(s[i]);
           if (it != hashmap.end() && it->second > b) {
               b = it->second;
           }
           hashmap[s[i]] = i;
           
           cout << b << i << endl;

           maxLen = i - b > maxLen ? i - b : maxLen;
       }

       return maxLen;
   }
}
