//
//  Utils.hpp
//  exercise
//
//  Created by 安子和 on 2022/9/6.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <vector>

using namespace std;

void printVectorOfInt(vector<int> vec);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif /* Utils_hpp */
