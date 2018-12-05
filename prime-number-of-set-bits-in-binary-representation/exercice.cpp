#include <iostream>
#include <math.h>

using namespace std;


class Solution {
    // value is garanteed to be less than 19 due to problem constraints
    bool isPrime(int value) {
        switch(value) {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
                return true;
        }

        return false;
    }

    int getAmountOnesOnBinaryConversion(int value) {
        int count = 0;

        while (value != 0) {
            count += value %2;
            value /= 2;
        }

        return count;
    }

public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;

        for (int value = L; value <= R; value ++) {
            int amountOnes = getAmountOnesOnBinaryConversion(value);
            if (isPrime(amountOnes)) {
                count++;
            }
        }

        return count;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);

        int ret = Solution().countPrimeSetBits(L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
