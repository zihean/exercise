//
//  Utils.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/6.
//

#include "Utils.hpp"
#include <iostream>
#include <string>

void printVectorOfInt(vector<int> vec) {
    int len = vec.size();
    for (int i= 0; i < len; ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}
