 //#----------------------------------------> بسم الله <------------------------------------------------#//

//problem link : https://atcoder.jp/contests/abc165/tasks/abc165_c?lang=en

#include <iostream>
using namespace std;
#include<deque>
#include<cmath>
#include<vector>
#include<set>
#include<unordered_map>
#include <iomanip> 
  


vector<int>vec;
vector<vector<int>>query;
int n, m,q;
long long final_score = 0;

long long get_score(vector<int>currentvector)
{
    long long sum = 0;
    for (vector<int> q : query)
    {
        int b = q[1] - 1;
        int a = q[0] - 1;
        int c = q[2];
        int d = q[3];
        if (currentvector[b] - currentvector[a] == c)
            sum += d;
    }
    return sum;
}
void solve(int i)
{
    //base case
    if (vec.size() > n)
    {
        final_score = max(final_score, get_score(vec)); //maxmize final_result
        return;
    }
    //construct all posibilities
    for (int num = i; num <= m; num++)
    {
        vec.push_back(num);
        solve(num);
        vec.pop_back();
    }
}


int main()
{
    cin >> n >> m >> q;
    vector<int>qe(4);
    for (int i = 0; i < q; i++)
    {
        cin >> qe[0] >> qe[1] >> qe[2] >> qe[3];
        query.push_back(qe);
    }
    solve(1);
    cout << final_score << endl;
}
