//
//  main.m
//  exercise
//
//  Created by 安子和 on 2022/9/6.
//

#include "Utils.hpp"
#include "leetcode_1.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    Solution *solution = new Solution();
    vector<int> vec = {2, 3, 4, 6};
    solution->twoSum(vec, 7);
    return 0;
}
