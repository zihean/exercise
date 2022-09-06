//
//  exercise_2.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/6.
//

#include "exercise_2.hpp"
#include <iostream>

using namespace std;

int getCount_1(int num) {
    int count = 0;
    while (num) {
        if (num % 2) {
            count++;
        }
        
        num /= 2;
    }
    return count;
}

// 位运算
int getCount_2(int num) {
    int count = 0;
    while (num) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

void getCountOfOne() {
    int num;
    while (cin >> num) {
        cout << getCount_2(num) << endl;
    }
}
