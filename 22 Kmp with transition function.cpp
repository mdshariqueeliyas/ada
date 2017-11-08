#include<bits/stdc++.h>
using namespace std;
int main()
{
	string txt,pat;
	cout<<"enter txt and pat\n";
	cin>>txt>>pat;
	int m=pat.length();
	int arr[m];
	arr[0]=0;
	int i=1;
	int len=0;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			arr[i]=len;
			i++;
		}
		else
		{
			if(len)
			len=arr[len-1];
			else
			{
				arr[i]=0;
				i++;
			}
		}
	}
	
	i=0;
	int j=0;
	while(i<txt.length())
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"pattern found at: "<<i-m<<endl;
			j=arr[m-1];
		}
		else if(i<txt.length() && txt[i]!=pat[j])
		{
			if(j)
			j=arr[j-1];
			else
			{
				j=0;
				i++;
			}
		}
	}
	cout<<"transition function\n";
	cout<<"state"<<"\t\t"<<"a\tb\tc\n";
	for(int i=0;i<m;i++)
	{
		
		cout<<i<<"\t\t";
		if(pat[i]=='a')
		cout<<i+1<<"\t";
		else
		cout<<arr[i]<<"\t";
		if(pat[i]=='b')
		cout<<i+1<<"\t";
		else
		cout<<arr[i]<<"\t";
		if(pat[i]=='c')
		cout<<i+1<<"\t";
		else
		cout<<arr[i]<<"\t";
		cout<<endl;
	}
	return 0;
}


