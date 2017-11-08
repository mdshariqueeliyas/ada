#include<bits/stdc++.h>
using namespace std;

int m[1000][1000],s[1000][1000];

void MCM(vector<int> arr){
	int i, l, j, k, q, n=arr.size()-1;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++){
		for(i=1;i<=(n-l+1);i++){
			j=i+l-1;
			m[i][j]=INT_MAX;
			//s[i][j]=i;
			for(k=i;k<j;k++){
				q=m[i][k]+m[k+1][j];
				q+=(arr[i-1]*arr[k]*arr[j]);
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}

void print(vector<int> arr, int i, int j){	
	if(i==j)
		cout<<"A"<<i;
	else{
		cout<<"(";
		print(arr,i,s[i][j]);
		//cout<<")(";
		print(arr,s[i][j]+1,j);
		cout<<")";
	}
}

int main(){
	vector<int> v;
	int n,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		v.push_back(t);
	}
	MCM(v);
	print(v,1,n-1);
	cout<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
