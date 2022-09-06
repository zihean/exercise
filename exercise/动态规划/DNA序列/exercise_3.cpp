//
//  exercise_3.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/6.
//

#include "exercise_3.hpp"
#include <string>
#include <iostream>

/**
 一个 DNA 序列由 A/C/G/T 四个字母的排列组合组成。 G 和 C 的比例（定义为 GC-Ratio ）是序列中 G 和 C 两个字母的总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的 GC-Ratio 可能是基因的起始点。
 给定一个很长的 DNA 序列，以及限定的子串长度 N ，请帮助研究人员在给出的 DNA 序列中从左往右找出 GC-Ratio 最高且长度为 N 的第一个子串。
 输入的字符串只包含 A/C/G/T 字母
 */

using namespace std;

bool isMatch(char c) {
    return c == 'G' || c == 'C';
}


// 滑动窗口
void getSubstrOfDNA() {
    string str;
    int lenOfSub, lenOfStr;
    while (cin >> str) {
        cin >> lenOfSub;
        lenOfStr = str.size();
        
        int realLen = lenOfSub >= lenOfStr ? lenOfStr : lenOfSub;
        int front = realLen;
        int behind = 0;
        int count = 0;
        int maxCount = 0;
        int index = 0;
        
        for (int i = 0; i < realLen; ++i) {
            if (isMatch(str[i])) {
                count++;
            }
        }
        // 注意maxCount也要初始化
        maxCount = count;
        
        while (front < lenOfStr) {
            bool frontMatch = isMatch(str[front]);
            bool behindMatch = isMatch(str[behind]);
            if (!frontMatch && behindMatch) {
                count--;
            }
            if (frontMatch && !behindMatch) {
                count++;
                if (count > maxCount) {
                    maxCount = count;
                    index = behind + 1;
                }
            }
            front++;
            behind++;
        }
        
        for (int i = index; i < index + realLen; ++i) {
            cout << str[i];
        }
        cout << endl;
    }
}
