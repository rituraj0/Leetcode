/*
Task: Find two non-reapeting in an array of repeating elements
Time: 10 Minutes
*/

#include <bits/stdc++.h>

#define sz(in) in.size()
#define mp make_pair
#define pb push_back
using namespace std;

int solve(vector<int> in)// in have all memembers exacly 2 time exxcept one
{
     int all=0;

     for(int i=0;i<sz(in);i++)
         all=(all^in[i]);

     return all;
}


pair<int,int> go( vector<int> in)
{
       int all=0;

       for(int i=0;i<sz(in);i++)
         all=(all^in[i]);

       int bitpos=-1;

       for(int i=0;i<30;i++)
          if( all ^ (1<<i))
       {
           bitpos=i;
           break;
       }


       if( bitpos==-1)
       {
           cout<<" invalid inout";
       }

       vector<int>  A, B;

       for(int i=0;i<sz(in);i++)
          if( in[i] & (1<<bitpos) )
            A.pb( in[i]);
         else
            B.pb( in[i] );

       pair<int,int> ans=mp( solve(A), solve(B))  ;
       return ans;
}


int main()
{
    while(1)
    {
         int n;

        cin>>n;

        vector<int> in(n);

        for(int i=0;i<n;i++)
             cin>>in[i];

        cout<<go(in).first<<"  "<<go(in).second<<endl;
    }
}
