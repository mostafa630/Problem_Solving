                                     //-------> بسم الله <---------//
//problem Link : 

#include<iostream>
#include <bits/stdc++.h> 
using namespace std ;

int num_of_items=0 ,max_capacity=0 ;
vector<int>weights , values;

void take_input()
{
    cin>>num_of_items>>max_capacity;
    weights.resize(num_of_items);
    values.resize(num_of_items);
    for(int i=0 ;i<num_of_items ;i++)
    {
        cin>>weights[i]>>values[i];
    }
}

int solve(int index , int current_capacity)
{
    //base case
    if(index>=num_of_items)
        return 0 ;
    
    //option1 : if the current item doesn't fit leave it .
    if(weights[index]>current_capacity)
    {
        return solve(index+1 , current_capacity);
    }
    else //option2: if current item fit return max(leave it , take it)
    {
        int take = solve(index+1 , current_capacity-weights[index])+values[index];
        int leave = solve(index+1 , current_capacity);
        return std::max(take , leave);
    }
    
}
int main(){
   take_input();
   int max_profit = solve(0 , max_capacity);
   cout<<max_profit<<endl;
}