#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll t,n,k,m;
ll ar[100005];
ll bin(ll);
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>m;
		rep(i,0,n)
		cin>>ar[i];
		ll low=0,high=m,mid,ans=-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(bin(mid)==1)
			{
				high=mid-1;
				ans=mid;
			}
			else
				low=mid+1;
		}
		cout<<ans;
	}
}
ll bin(ll num)
{
	cout<<"\n";
	cout<<num<<"     ";
	ll prev=0,idx=0;
	ll last=ar[n-1];
	ll low=0,high=ar[n-1],mid,c=0;;
	while(1)
	{
		c++;
		cout<<prev<<" ";
		if(n-1-idx<=num&&last-prev<=k)
		{
			return (c+1<=k);
		}	
		if(ar[num+idx+1]-1-prev<=k)
		{
			prev=ar[num+idx+1]-1;
			idx=num+idx;
			c++;
			cout<<" B ";
			cout<<"IDX "<<idx<<" "<<prev<<" ";
		}	
		else
		{
			ll i=0;
			while(i<n&&ar[idx+i]-prev<=k)
			{
				i++;
			}
			cout<<" A ";
			idx+=i-1;
			prev+=k;
			cout<<prev<<" "<<idx<<" ";			
		}
	}

}