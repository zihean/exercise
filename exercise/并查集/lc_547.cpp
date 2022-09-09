//
//  lc_547.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/9.
//

#include "lc_547.hpp"
#include "Utils.hpp"
#include <unordered_set>

int Solution::_getRoot(int n) {
    int root = rootArr[n];
    
    if (root == -1 || root == n) {
        rootArr[n] = n;
        return n;
    }
    
    root = _getRoot(root);
    rootArr[n] = root;
    
    return root;
}

void Solution::_union(int a, int b) {
    int rootA = _getRoot(a);
    int rootB = _getRoot(b);
    
    rootArr[rootB] = rootA;
}

int Solution::findCircleNum(vector<vector<int>>& isConnected) {
    {
        int count = isConnected.size();
        rootArr = vector<int>(count, -1);
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count; ++j) {
                if (isConnected[i][j] && i < j) _union(i, j);
            }
        }
        
        unordered_set<int> set = unordered_set<int>();
        for (int i = 0; i < count; ++i) {
            set.insert(_getRoot(i));
        }
        
        return set.size();
    }
}
