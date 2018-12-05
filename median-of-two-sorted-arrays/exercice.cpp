
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:

    int binarySearchIndex(vector<int>& vec, int value) {
        int i = 0;
        int j = vec.size() - 1;

        while (1) {
            if (i == j || i == j-1 || i > j) return i;
            int k = (i + j)/2;

            if (vec[k] < value) {
                i = k;
            } else if (vec[k] > value) {
                j = k;
            } else {
                return k;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int AmountNumbersSmallerThanI = 0;
        int AmountNumbersSmallerThanJ = 0;

        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int final_i = m-1;

        int j = 0;
        int final_j = n-1;

        while(1) {
            int mid_i = (i + final_i)/2;
            int mid_j = (j + final_j)/2;

            cout << "here we are again" << endl;
            cout << "mid_i: " << mid_i << endl;
            cout << "mid_j: " << mid_j << endl;

            if (mid_i < m) {
                AmountNumbersSmallerThanI = m - mid_i;
                AmountNumbersSmallerThanI += binarySearchIndex(nums2, nums1[mid_i]);
            }

            if (mid_j < n) {
                AmountNumbersSmallerThanJ = n - mid_j;
                AmountNumbersSmallerThanJ += binarySearchIndex(nums1, nums2[mid_j]);
            }

            // breaking conditions
            if (AmountNumbersSmallerThanI == (n + m)/2 && mid_i < m) {
                cout << "here" << endl;
                cout << mid_i << endl;

                std::stringstream res;
                std::copy(nums1.begin(), nums1.end(), std::ostream_iterator<int>(res, " "));
                cout << res.str() << endl;
                cout << "done" << endl;

                return nums1[mid_i];
            } else if (AmountNumbersSmallerThanJ == (n + m)/2 && mid_j < n) {
                cout << "there" << endl;
                return nums2[mid_j];
            }

            // binary search update
            if (AmountNumbersSmallerThanI > (n + m)/2) {
                final_i = mid_i;
            } else {
                i = mid_i;
            }

            if (AmountNumbersSmallerThanJ > (n + m)/2) {
                final_j = mid_j;
            } else {
                j = mid_j;
            }
        }

        return 0.f;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
