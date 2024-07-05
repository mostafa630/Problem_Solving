 //#----------------------------------------> بسم الله <------------------------------------------------#//

//problem link : https://codeforces.com/problemset/problem/476/B

#include <iostream>
using namespace std;
#include<deque>
#include<cmath>
#include<vector>
#include<set>
#include<unordered_map>
#include <iomanip> 
  



int correct_sum = 0;
int current_sum = 0;
int num_of_un_knowns = 0;

int num_of_correct_results = 0;
void solve(int cnt , int  un_known_sum)
{
    if (cnt > num_of_un_knowns)
    {
        if (current_sum + un_known_sum == correct_sum)
            num_of_correct_results++;
        return;
    }

    solve(cnt + 1 , un_known_sum +1);
    solve(cnt + 1 , un_known_sum-1);
    
}

pair<int,int> get_signal_info(string signal)
{
    int sum = 0, un_known = 0;
    for (char puls : signal)
    {
        if (puls == '+')
            sum++;
        else if (puls == '-')
            sum--;
        else
            un_known++;
    }   
    return { sum ,un_known };
}
int main()
{
    string correct_signal  , delivered_singal;
    cin >> correct_signal>>delivered_singal;

    correct_sum= get_signal_info(correct_signal).first;

    pair<int, int>delivered_singal_info = get_signal_info(delivered_singal);
    current_sum = delivered_singal_info.first;
    num_of_un_knowns = delivered_singal_info.second;
    
    solve(1,0);

    double total_possibilites = pow(2, num_of_un_knowns);
    double probability = (double)num_of_correct_results / total_possibilites;

    cout << setprecision(12) << fixed << double(probability) << endl;

    
}
