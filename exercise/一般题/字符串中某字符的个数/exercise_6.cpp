//
//  exercise_6.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/7.
//

#include "exercise_6.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// count_if
int getCountOfChar1(string str, char target) {
    char _target = tolower(target);
    return count_if(str.begin(), str.end(), [_target](char c){return tolower(c) == _target;});
}

int getCountOfChar2(string str, char target) {
    int len = str.size();
    char _target = tolower(target);
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (tolower(str[i]) == _target) ++ret;
    }
    return ret;
}

void getCountOfChar() {
    string str;
    char target;
    while (getline(cin, str)) {
        cin >> target;
        cout << getCountOfChar1(str, target) << endl;
    }
}
