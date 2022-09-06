//
//  exercise_1.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/6.
//

#include "exercise_1.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 描述

 Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

 输入描述：
 数据共2行，第1行先输入数组的个数，第2行再输入梅花桩的高度
 
 输出描述：
 输出一个结果
 
 6
 2 5 1 5 4 5

 3
 */

// 通过二分法找到对应的位置
// arr对应升序序列
int findPosition(vector<int> arr, int lenght, int target) {
    int left = 0, right = lenght - 1;
    while (left <= right) {
        int mid = (left + right + 1) / 2;
        if (arr[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// dp 用于记录最长升序子序列
// 当target找到位置后，其前面的元素一定比他小，且出现比他早
// 当所有元素满足其前面的元素比他小还出现的更早时，那么dp就是一个升序子序列
int maxLen(vector<int> arr) {
    int length = arr.size();
    vector<int> dp(length);
    int lenOfDp = 0;
    for (int i = 0; i < length; ++i) {
        int position = findPosition(dp, lenOfDp, arr[i]);
        dp[position] = arr[i];
        lenOfDp = position + 1 > lenOfDp ? position + 1 : lenOfDp;
        printVectorOfInt(dp);
    }
    return lenOfDp;
}

// 3 6 9 12 7 4 1 8 9
int lengthOfLengthesSequence() {
    int len;
    cin >> len;
    vector<int> arr(len);
    for (int i; i < len; ++i) {
        cin >> arr[i];
    }
    return maxLen(arr);
}
