#include <iostream>
using namespace std;

void DP(int we ,int ws[],int vs[],string names[],int n) {
    int dp[50][50];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= we; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (ws[i - 1] <= w) dp[i][w] = max(vs[i-1]+dp[i-1][w-ws[i-1]],dp[i-1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << "you should select :\n";
    while (n != 0) {
        if (dp[n][we] != dp[n - 1][we]) {
            cout << "\titem " << names[n-1] << " with W = " << ws[n - 1] << " and Value = " << vs[n - 1] << endl;

            we = we - ws[n - 1];
        }

        n--;
    }


}

int main()
{
    int val[] = {14, 5, 8, 3, 6, 28, 10, 27};
    int wt[] = { 8, 3, 5, 1, 4, 20, 7, 22 };
    string names[] = { "Gaming PC", "Apple Watch", "Iphone 12", "DVD - Set", "Samsung Galaxy S12+" , "Apple Mac Box Air", "Mac Pro" };
    int W = 30;
    DP(W, wt, val,names,8);

    return 0;

}
