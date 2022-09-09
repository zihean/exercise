//
//  lc_547.hpp
//  exercise
//
//  Created by 安子和 on 2022/9/9.
//

#ifndef lc_547_hpp
#define lc_547_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected);
    
private:
    unordered_map<int, int> hashmap;
    vector<int> rootArr;
    
    void _union(int a, int b);
    int _getRoot(int n);
};

#endif /* lc_547_hpp */
