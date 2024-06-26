                                           //--------->بسم الله<--------//

//problem Link :https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=565

#include<iostream>
#include<vector>
using namespace std ;
vector<int>tracks;
int N , num_of_tracks ;


long long current_size = 0 ;   
vector<int>current_vec;
vector<int>final_vec;
long long final_size=0;


void Construct_tracks()
{
    cin>>num_of_tracks;
   for(int i=0 ;i<num_of_tracks ;i++)
   {
       int track_size ;
       cin>>track_size;
       tracks.push_back(track_size);
   }
}
void solve(int i){
    if(i >num_of_tracks)  
        return;
    if(i==num_of_tracks)
    {
        //updating the result
        if(current_size>final_size)
        {
            final_size =current_size ;
            final_vec = current_vec ;
        }
    }
     
   if(current_size+tracks[i]<=N)
   {
        // take this track 
        current_size+=tracks[i];
        current_vec.push_back(tracks[i]);
        solve(i+1); // after you yake it solve from the next one .
        //bactracking step
        current_size-=tracks[i];
        current_vec.pop_back();
   }
   solve(i+1); // leave this track
}
void print_result()
{
    for(int x  : final_vec)
    {
        cout<<x<<" ";
    }
    cout<<"sum:"<<final_size<<endl;
    
}
void free()
{
    final_vec.clear();
    current_vec.clear();
    tracks.clear();
    final_size =0 ;
    current_size=0;
}
int main(){
   while(cin>>N)
   {
     Construct_tracks();
     solve(0);
     print_result();
     free();
   }
}
