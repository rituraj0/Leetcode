/*
Task: Find all maximum pair sub-array in which all pairs have their sum greater than k
Time: 10 Minutes
*/

#include <bits/stdc++.h>

#define sz(in) in.size()
#define mp make_pair
#define pb push_back
using namespace std;

int solve(vector<int> in , int k)//
{
    // http://codeforces.com/contest/280/submission/3928188
    // http://assets.codeforces.com/statements/280-281/Tutorial.pdf
    // http://codeforces.com/contest/280/submission/3275542
   assert( sz(in) >=2 );

   cout<<" input is \n";

   for(int i=0;i<sz(in);i++)
    cout<<in[i]<<" ";


    cout<<endl;

   stack<int> st;

   st.push( 0 );

   for(int i=1;i<sz(in);i++)
   {
       int curr=in[i];

       while ( (!st.empty()) &&( in[st.top()] > curr) )
       {
         if( ( in[st.top()] + curr) >= k)
         {
             cout<<st.top()<<"  "<<i<<endl;
         }

         st.pop();
       }

       if( !st.empty())
       {
             if( ( in[st.top()] + curr) >= k)
             {
              cout<<st.top()<<"  "<<i<<endl;
             }
       }

       st.push(i);
   }

   return 0;

}


int main()
{
    while(1)
    {
         int n,k;

        cin>>n>>k;

        vector<int> in(n);

        for(int i=0;i<n;i++)
             cin>>in[i];

        solve(in,k);

        cout<<" now reversing \n";

        reverse( in.begin() , in.end() );

        solve(in,k);
    }
}

/*

10 5
1 5 2 2 6 5 4 2 2 5


10 8
1 5 2 3 6 5 4 2 2 8

*/
