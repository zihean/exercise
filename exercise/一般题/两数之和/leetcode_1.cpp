//
//  leetcode_1.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/8.
//

#include "leetcode_1.hpp"
#include <unordered_map>
#include <iostream>

// 利用哈希，降低时间复杂度
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    int count = nums.size();
    for (int i = 0; i < count; ++i) {
        auto it = hashmap.find(target - nums[i]);
        if (it != hashmap.end()) {
            return {it->second, i};
        }
        
        hashmap[nums[i]] = i;
    }
    
    return {};
}
