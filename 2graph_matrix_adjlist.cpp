#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, u, v, e;
	cout << "\nEnter the number of nodes: ";
	cin >> n;
	vector< vector<int> > alist(n), amat(n, vector<int>(n, 0));
	cout << "\nEnter the number of edges: ";
	cin >> e;
	cout << "\n\n";
	for(int i=0; i<e; i++)
	{
		cout << "\nEnter u and v: ";
		cin >> u >> v;
		amat[u][v] = 1;
		amat[v][u] = 1;
		alist[u].push_back(v);
		alist[v].push_back(u);
	}
	
	cout << "\n\n\t\t**Adjacency Matrix**\n\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<"\n";
		sort(alist[i].begin(), alist[i].end());
		for(int j=0; j<n; j++)
		{
			cout << amat[i][j] << " ";
		}
	}
	
	cout << "\n\n\t\t**Adjacency List**\n\n";
	
	vector<int>::iterator k;
	for(int i=0; i<n; i++)
	{
		cout << i << ": ";
		for(k=alist[i].begin(); k!=alist[i].end()-1; k++)
		{
			cout << *k << "->";
		}
		cout << *k << endl;
	}
	cout << endl;
}
