#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int fnd(char f,vector<char> alp){
	int i;
	for(i=0;i<alp.size();i++)
		if(f==alp[i])
			break;
		return i;
}

void diff(string t, vector<char > &alp){
	int i,j,n= t.length();
	bool f;
	for(i=0;i<n;i++){
		f= true;
		for(j=0;j<alp.size();j++)
			if(t[i]==alp[j])
				f= false;
		if(f==true)
			alp.push_back(t[i]);	
	}
}

void crttbl(string t,vector<vector<int> > &tbl, vector<char> alp){
	int i,j,k,l=0,m= t.length(), n=alp.size();
	for(i=0;i<n;i++)
		tbl[0][i]=0;
	tbl[0][fnd(t[0],alp)]=1;
	for(i=1;i<m;i++){
		k=fnd(t[i],alp);
		for(j=0;j<n;j++)
			tbl[i][j]=tbl[l][j];
		tbl[i][k]=i+1;
		l=tbl[l][k];
	}
	for(j=0;j<n;j++)
		tbl[i][j]=tbl[l][j];
	for(i = 0;i<m;i++){
		for(j = 0;j<n;j++)
			cout<<tbl[i][j]<<" ";
		cout<<"\n";
	}
}

int main(){
	int m,n,i,q,ti;
	vector<char > alp;
	string t, pt,s;
	cin>>t>>pt;
	s=t+pt;
	m=t.length();
	diff(s, alp);
	n=alp.size();
	cout<<n<<"\n";
	vector<vector<int> > tbl(m+1, vector<int>(n,0));
	crttbl(pt,tbl,alp);
	ti=pt.length();
	q=0;
	for(i=0;i<m;i++){
		q=tbl[q][fnd(t[i],alp)];
		if(q==ti)
			cout<<"Pattern occured at "<<i-ti+1<<endl;
	}
}

