//
//  exercise_5.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/7.
//

#include "exercise_5.hpp"
#include <iostream>
#include <string>

using namespace std;

void lenOfLastWord() {
    string str;
    while (getline(cin, str)) {
        int length = str.size();
        // 针对只有一个单词的case初始化
        int indexOfSpace = -1;
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') {
                indexOfSpace = i;
            }
        }
        cout << length - indexOfSpace - 1;
    }
}
