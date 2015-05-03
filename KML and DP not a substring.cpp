#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */


vector<int> fail_array( string in)
{
    int n = sz(in);
    vector<int> ans( n+1, -1 );

    for(int i=1; i<=n ; i++)
    {
        int pos = ans[i-1];

        while( (pos != -1) && ( in[pos] != in[i-1] ) )
             pos = ans[pos];

        ans[i]= pos +1;
    }

    return ans;
}


vector<int> kmp( string text , string pat)
{
    vector<int> fail = fail_array(pat);

    vector<int> ans;

    int n = sz(text);
    int m= sz(pat);

    int pat_po = 0;


    for(int text_po = 0; text_po < n ; text_po++)
    {
        while( (pat_po != -1)&&(pat_po == m || pat[pat_po] != text[text_po] ) )
        {
            pat_po = fail[ pat_po];
        }

        pat_po++;

        if( pat_po == m)
            ans.pb( text_po +1 - m);
    }

    return ans;

}


vector<int> KMP(string S, string K)
{
        vector<int> T(K.size() + 1, -1);
	vector<int> matches;

        if(K.size() == 0)
        {
            matches.push_back(0);
            return matches;
        }
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;
	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) matches.push_back(sp - K.size());
	}

	return matches;
}


int main()
{


    int n;

    ios_base::sync_with_stdio(0);

    string pat,text;

    while( cin>>n)
    {
        cin>>pat>>text;

        vector<int> ans=kmp(text,pat);

        for(int i=0;i<sz(ans);i++)
            cout<<ans[i]<<endl;

        cout<<endl;


    }

    return 0;
}
