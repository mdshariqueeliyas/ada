#include<iostream>
#include<vector>
using namespace std;

struct LUP{
	vector<vector<int> > LU,P;
};

struct LUP LUP_decomp(vector<vector<int> > A) { //LU decomposition with partial pivoting
  //returns the LU matrix, the permutation matrix of matrix A, and the number of row swaps 
  //This function overwrites A
  int N = A.size(),i,j; 
  struct LUP L;
  vector<vector<int> > P(N,vector<int>(N));
  for(i = 0;i<N;i++)
  {
  	for(j = 0;j<N;j++)
  	{
  		if(i == j)
  		{
  			P[i][i] = 1;
		  }
		  else
		  {
		  	P[i][j] = 0;
		  }
	  }
	} 
  int exchanges = 0,Umax,Uii,r,q,row,tmp; //count the number of row swaps

  for (i=0; i<N; i++) { 

    //start pivot section
    Umax = 0;
    for (r=i; r<N; r++) {
      Uii=A[r][i];
      q = 0;
      while (q<i) {
        Uii -= A[r][q]*A[q][r];
        q++;
      } 
      if (abs(Uii)>Umax) {
        Umax = abs(Uii);
        row = r;
      }
    }
    if (i!=row) {//swap rows
      exchanges++;
      for (q=0; q<N; q++) {
        tmp = P[i][q];
        P[i][q]=P[row][q];
        P[row][q]=tmp;
        tmp = A[i][q];
        A[i][q]=A[row][q];
        A[row][q]=tmp;
      } 
    }
   //end pivot section

    j = i;
    while (j<N) { //Determine U across row i
      q = 0;
      while (q<i) {
        A[i][j] -= A[i][q]*A[q][j];
        q++;
      } 
      j++;
    }
    j = i+1;
    while (j<N) { //Determine L down column i
      q = 0;
      while (q<i) {
        A[j][i] -= A[j][q]*A[q][i];
        q++;
      } 
      A[j][i] = A[j][i]/A[i][i];
      j++;
    } 
  }
  //return {LU:A,P:P,exchanges:exchanges};
  L.LU = A;
  L.P = P;
  return L;
}

void write_matrix(vector<vector<int> > A) {
  int rows = A.size();
  int cols = A[0].size(),i,j;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      cout<<A[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";
}
int main()
{
	int n,i,j,k;
	cin>>n;
	vector<vector<int> > A(n,vector<int>(n));
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	LUP L = LUP_decomp(A);
	//LU_decompose(L.LU);
	int a[10][10],sum=0,l[10][10]={0},u[10][10]={0},p;
	cout<<"\nLU matrix :"<<endl;
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=n;j++)
		{
			a[i][j] = L.LU[i-1][j-1];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	for(k=1;k<=n;k++)
    {   u[k][k]=1;
        for(i=k;i<=n;i++)
        {   sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k];
            l[i][k]=a[i][k]-sum;
        }
        for(j=k+1;j<=n;j++)
        {   sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }
    cout<<"\nL matrix : "<<endl;
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
            cout<<l[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"\nU matrix :"<<endl;
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
            cout<<u[i][j]<<"  ";
        cout<<endl;
    }
	
	cout<<"\nP matrix : \n";
	write_matrix(L.P);
}

