#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter dimensions of matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    // DP table
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    // Chain length
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications = " << m[1][n] << endl;
    return 0;
}
