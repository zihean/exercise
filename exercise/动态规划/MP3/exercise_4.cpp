//
//  exercise_4.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/7.
//

#include "exercise_4.hpp"
#include <string>
#include <iostream>

using namespace std;

void mp3() {
    int countOfSong, countOfInstructios;
    string instructions;
    int indexInScreen, indexInList;
    while (cin >> countOfSong) {
        cin >> instructions;
        countOfInstructios = instructions.size();
        indexInScreen = 1;
        indexInList = 1;
        for (int i = 0; i < countOfInstructios; ++i) {
            if (instructions[i] == 'U') {
                if (indexInList == 1) {
                    // 是第一首
                    indexInList = countOfSong;
                    indexInScreen = countOfSong < 4 ? countOfSong : 4;
                } else {
                    // 上移一首
                    indexInScreen = indexInScreen == 1 ? 1 : indexInScreen - 1;
                    indexInList--;
                }
            } else if (instructions[i] == 'D') {
                if (indexInList == countOfSong) {
                    // 是最后一首歌 回到第一首
                    indexInList = 1;
                    indexInScreen = 1;
                } else {
                    // 下移一首
                    indexInScreen = indexInScreen == 4 ? 4 : indexInScreen + 1;
                    indexInList++;
                }
            }
        }
        
        int b = indexInList - indexInScreen + 1;
        int e = countOfSong <= 4 ? countOfSong : indexInList + (4 - indexInScreen);
        for (int i = b; i <= e; ++i) {
            cout << i << ' ';
        }
        cout << endl << indexInList << endl << indexInScreen;
    }
}
