#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"


bool  match( string a,  string b)
  {

  int contA[27],contB[27];

  memset(contA,0,sizeof(contA) );
   memset(contB,0,sizeof(contB) );

   int n=a.size() , m=b.size();

    if(n!=m)
          {
            cout<<" Not possible to match";

            return 0;
          }

    for(int i=0;i<n;i++)
         {
           contA[ a[i]-'a']++;
           contB[ b[i]-'a']++;
          }

  //vector<int> A, B;

    map<int, int > mapA , mapB;

  for(int i=0;i<=25;i++)
    {
      if( contA[i])
         mapA[ contA[i]  ]++;

      if( contB[i] )
          mapB[ contB[i]  ]++;
    }

  //match using hash

 for( map<int,int>::iterator it=mapA.begin() ; it!=mapA.end() ; it++)
       if(it->second != mapB[ it->first])
           {
             cout<<" not possible to match -";
              return 0;
         }

  //turn std::equal( mapA.begin() , mapA.end() , mapB.begin() )  ;

  cout<<" Psoosible  ";


  return true;

}
// step 1: create hash
// step 2: store the counter for the lettet in the hash...

int main()
{

   string a="foo", b="app";

  cout<<a<<"  "<<b<<"  "<<match(a,b)<<endl;


   a="foo", b="bar";

  cout<<a<<"  "<<b<<"  "<<match(a,b)<<endl;

   a="turtle", b="tletur";

  cout<<a<<"  "<<b<<"  "<<match(a,b)<<endl;


     a="foo", b="aaa";

  cout<<a<<"  "<<b<<"  "<<match(a,b)<<endl;

   a="xyz" , b="abc";

   cout<<a<<"  "<<b<<"  "<<match(a,b)<<endl;



  return 0;
}



//    given "foo", "app"; returns true


//     given "bar", "foo"; returns false

//     given "turtle", "tletur"; returns true

//     given "foo", "aaa"; returns false




