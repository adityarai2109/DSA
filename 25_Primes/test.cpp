#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
vector<int> sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
    vector<int> primes;
    for (int i = 0; i < n; i++)
        if (prime[i])
            primes.push_back(i);
    return primes;
}

vector<int> primeFactors(int n)
{
    vector<int> p;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            p.push_back(i);
            n = n / i;
        }
    }
    if (n > 1)
        p.push_back(n);
    return p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto i : primeFactors(10000))
        cout << i << " ";
    return 0;
}
