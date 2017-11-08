#include<bits/stdc++.h>
using namespace std;
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define fill(a,x) memset(a,x,sizeof(a))
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define reff(i,a,b) for(int i=a;i>=b;i--)
ll lps[100005];
ll n,m;
string txt,pat;

void prefixKMP()
{
    int len = 0; 
    int i=1;
    lps[0] = 0; 
    while (i < m)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else 
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else 
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

void KMPSearch()
{
	int i = 0;
    int j = 0;
	int f=0;        
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
         printf("Found pattern at index %d \n", i-j);
         f=1;
         j = lps[j-1];
        }
       else if (i < n && pat[j] != txt[i])
       {
        if (j != 0)
        j = lps[j-1];
        else
        i++;
      }
    }
    if(!f)
    cout<<"Pattern Not found "<<endl;
}
int main()
{
	fastScan;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>txt>>pat;
		n=txt.size();
		m=pat.size();
		prefixKMP();
		KMPSearch();
	}
}
