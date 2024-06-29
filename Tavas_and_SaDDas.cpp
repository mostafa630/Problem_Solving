                                    //-------> بسم الله <---------//
//problem Link : https://codeforces.com/problemset/problem/535/B

#include<iostream>
#include <bits/stdc++.h> 
#define ll long long
#define el '\n'
using namespace std ;

int final_order = 0 ;
int target_number=0;
void solve(ll num , int order)
{
    //base cases
    if(num == target_number)
    {
        final_order = order;
        return;
    }
    if(num>target_number)
        return;
    //transctions
    solve(num*10+4 , 2*order+1);
    solve(num*10+7,2*order+2);
}
int main()
{
    cin>>target_number;
    solve(0 ,0);
    cout<<final_order<<el;
}