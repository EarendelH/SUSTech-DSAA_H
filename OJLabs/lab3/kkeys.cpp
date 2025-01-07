#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S;

bool valid(const vector<int>& ks, int minLen);
int maximizeMinLength(const string& S);
int maximizeMinLength(const string& S) {
    vector<int> ks;
    if (S.empty()) return 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'K') {
            ks.push_back(i);
        }
    }

    if (ks.empty()) return 0;

    int left = 0, right = S.length(), result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if(valid(ks, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

bool valid(const vector<int>& ks, int minLen) {
    vector<int> len(ks.size());

    if (minLen <= ks[0] + 1) {
        len[0] = ks[0];
    } else {
        len[0] = minLen - 1;
    }
    if(ks.size()>1&&minLen>ks[1])
    {
        return false;
    }
    for (int i = 1; i < ks.size(); i++) {
        int right;
        if (i == ks.size() - 1) {
            right = S.length(); 
        } else {
            right = ks[i + 1]; 
        }

        if (len[i - 1] + minLen <= ks[i]) {
            len[i] = ks[i];
        } else if (len[i - 1] + minLen >= right) {
            return false;
        } else if (len[i - 1] + minLen > ks[i]) {
            len[i] = len[i - 1] + minLen;
        }
    }

    return true;
}

int main() {

    getline(cin, S);

    int result = maximizeMinLength(S);
    cout << result << endl;

    return 0;
}