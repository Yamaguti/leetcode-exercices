#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        return vector<string>({"0:00"});
    }
};

int main() {
    string line;
    getline(cin, line);

    vector<string> result = Solution().readBinaryWatch(stoi(line));
    for (auto s = result.begin(); s != result.end(); s++) {
        cout << *s;
    }

    return 0;
}
