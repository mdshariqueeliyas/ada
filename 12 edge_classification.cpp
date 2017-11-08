#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define ll long long int
vector<int>v[1005];
int vis[1005];
vector<pair<int, int> >forwar,back,cross;
void dfs(int s, vector<int>&tmp)
{
   vis[s]=1;
   tmp.push_back(s);
   for(auto i : v[s])
   {
       if(i==s) continue;
       if(!vis[i])
       {
          forwar.push_back(make_pair(s , i));
          dfs(i,tmp);
	   }
	   else
	   {
	      int f=0;
	      for(auto it : tmp)
	      {
	         if(it==i)
	         {
	           f=1;
	           break;
			 }
		  }
		  if(f)
		  back.push_back(make_pair(s , i));
		  else
		  cross.push_back(make_pair(s,i));
	   }
   }
}
int main()
{
  int n,e,a,b;
  cin>>n>>e;
  rep(i,n)
  {
    cin>>a>>b;
    v[a].push_back(b);
  }
  repp(i,1,n)
  {
    if(!vis[i])
    {
	 vector<int>tmp;
     dfs(i,tmp);
    }
  }
  cout<<endl;
  cout<<"Forward edges : "<<endl;
  rep(i,forwar.size())
  cout<<forwar[i].first<<" "<<forwar[i].second<<endl;
  cout<<"Backward edges : "<<endl;
  rep(i,back.size())
  cout<<back[i].first<<" "<<back[i].second<<endl;
  cout<<"Cross edges :"<<endl;
  rep(i,cross.size())
  cout<<cross[i].first<<" "<<cross[i].second<<endl; 
}


