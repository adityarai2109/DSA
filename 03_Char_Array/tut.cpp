#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

string compressString(string s)
{
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        int c = 1;
        while (i < s.size() and s[i] == s[i + 1])
        {
            c++;
            i++;
        }
        ans += s[i] + (c > 1 ? to_string(c) : "");
    }
    return ans;
}

int main()
{
    char a[10] = {'a', 'b', 'c', '\0'}, b[10] = "abc";
    // char temp = cin.get();            get 1 char at a time
    // char temp[100];
    // cin.getline(temp, 100, '.');               3rd parameter tells when to stop
    char c[10];
    strcpy(c, b);
    // cout << strcmpi(a, c);
    // cout << strcat(a, c);
    string s;
    // getline(cin, s, '.');
    // cout << s;
    string ans = compressString("aaaaaaaabbbbbbbbcccccccc");
    cout << ans;
    return 0;
}
