#include<iostream>

using namespace std;

class Solution {
public:
    int amountOfInSubArray(string S, int start, int end, char value) {
        int amount = 0;
        for (int index = start; index < end; index ++) {
            if (S[index] == value) amount++;
        }

        return amount;
    }

    int minFlipsMonoIncr(string S) {
        int minimunAnswer = S.size();

        // aproach n^2
        // int amountOnes;
        // int amountZeros;
        // int answer;
        // for (int index = 0; index < S.size(); index++) {
        //     amountOnes  = amountOfInSubArray(S, 0, index, '1');
        //     amountZeros = amountOfInSubArray(S, index+1, S.size(), '0');
        //     answer = amountOnes + amountZeros;

        //     if (minimunAnswer > answer) {
        //         minimunAnswer = answer;
        //     }
        // }

        int amountZerosAfterIndex = amountOfInSubArray(S, 0, S.size(), '0');
        int amountOnesBeforeIndex = 0;
        int answer;

        for (int index = 0; index < S.size(); index++) {
            if (S[index] == '0') {
                amountZerosAfterIndex = amountZerosAfterIndex-1;
            }

            answer = amountOnesBeforeIndex + amountZerosAfterIndex;
            if (minimunAnswer > answer) {
                minimunAnswer = answer;
            }

            if (S[index] == '1') {
                amountOnesBeforeIndex = amountOnesBeforeIndex+1;
            }
        }

        return minimunAnswer;
    }
};

int main () {
    Solution s = Solution();
    int amount = s.minFlipsMonoIncr("1111100000000000000011111111111011101000110");

    cout << "Answer: ";
    cout << amount << endl;

    return 0;
}
