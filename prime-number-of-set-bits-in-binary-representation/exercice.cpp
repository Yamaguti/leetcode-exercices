#include <iostream>
#include <math.h>

using namespace std;


class Solution {
    bool isPrime(int value) {
        if (value == 1 || (value != 2 && value % 2 == 0))
            return false;

        for (int test = 3; test < value; test+=2) {
            if (value % test == 0) {
                return false;
            }
        }

        return true;
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
