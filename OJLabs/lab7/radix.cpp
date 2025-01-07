
#include <iostream>
using namespace std;
void zimusort(string arr[], int l, int index) {
    string b[l];
    int zimu[26] = {0};

    for (int i = 0; i < l; i++)
        zimu[arr[i][index] - 'a']++;

    for (int i = 1; i < 26; i++)
        zimu[i] += zimu[i - 1];

    for (int i = l - 1; i >= 0; i--) {
        b[zimu[arr[i][index] - 'a'] - 1] = arr[i];
        zimu[arr[i][index] - 'a']--;
    }

    for (int i = 0; i < l; i++)
        arr[i] = b[i];
}
int main() {
    int n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = m - 1; i >= 0; i--)
        zimusort(arr, n, i);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}