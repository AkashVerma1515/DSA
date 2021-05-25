#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int q,sum = 0, c = 0;
	cin>>q;
	while(q--)
	{
		int p;
		cin>>p;
		for(int i=0;i<n;i++)
		{
			if(a[i] <= p)
			{
				c++;
				sum += a[i];
			}
		}
		cout<<c<<" "<<sum<<endl;
		sum = 0;
		c = 0;
	}

	return 0;
}