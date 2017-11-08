#include<bits/stdc++.h>
using namespace std;
int main()
{
     string txt,pat;
     int n,m,t;
     cin>>txt;
     n=txt.size();
     cout<<"Enter no of patterns: ";
     cin>>t;
     while(t--)
     {
     cin>>pat;
     m=pat.size();
     int i,j,M=101;
     int pat_hash=0,text_hash=0,h=1;
     for(i=0;i<m-1;i++)
     {
         h=(h*m)%M;
      }
  for (i = 0; i < m; i++)
    {
        pat_hash = (m*pat_hash + pat[i])%M;
        text_hash = (m*text_hash + txt[i])%M;
    }
     for(i=0;i<n-m+1;i++)
     {
        if(pat_hash==text_hash)
        {   
           for(j=0;j<m;j++)
           {
             if(pat[j]!=txt[i+j])
             break;
            }
        if(j==m)
        {
         cout<<"text found = "<<i<<endl;
         return 0;
        } 
      }
    text_hash = (m*(text_hash - txt[i]*h) + txt[i+m])%M;
    if (text_hash < 0)
    text_hash = (text_hash + M);
   }
  }
}
