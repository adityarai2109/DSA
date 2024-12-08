#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<int> solve(vector<int> &B, int N)
{
    vector<int> A(N);
    int total_sum = accumulate(B.begin(), B.end(), 0);
    A[0] = total_sum - accumulate(B.begin() + 1, B.end(), 0);
    for (int i = 1; i < N; ++i)
        A[i] = B[i - 1] - A[i - 1];
    return A;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N - 1);
        for (auto &i : A)
            cin >> i;
        for (auto i : solve(A, N))
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}
