#include <iostream>
using namespace std;

string lcs(string a, string b)
{
    int lenA = a.length();
    int lenB = b.length();
    int dp[lenA + 1][lenB + 1];

    // Filling the dp table
    for (int i = 0; i <= lenA; i++)
    {
        for (int j = 0; j <= lenB; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Constructing the LCS from the dp table
    string lcs = "";
    int i = lenA, j = lenB;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs = a[i - 1] + lcs; // Add character to LCS
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return lcs;
}

int main()
{
    string a, b;
    cout << "Enter 1st string: ";
    cin >> a;
    cout << "Enter 2nd string: ";
    cin >> b;

    cout << "Longest common subsequence is: " << lcs(a, b) << endl;
}
