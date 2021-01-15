#include<bits/stdc++.h>
#define ll long long 
using namespace std;

//あきらめない。                                                                        // Never Give up
//信じれば何事も可狽ﾅある                                                              // If you believe everything is possible

ll max(ll a,ll b){
	if(a>b)
		return a;
	else
		return b;
}
double max(double  a,double b){
	if(a>b)
		return a;
	else
		return b;
}



bool bin_search(vector<ll> A,ll val){
		int low=0;
		int high=A.size()-1;
		while(low<=high){
			int mid=low+(high-low)/2;
			if(A[mid]==val)
				return true;
			else if(A[mid]>val)
				high=mid-1;
			else
				low=mid+1;
				
			
		}
		return false;
}

void swap(ll& x,ll &y){
	ll temp=x;
	x=y;
	y=temp;
}
	
int part(vector<ll>& A,int low,int high){
		int pivot=A[high];
		int start=low-1;
		for(int i=low;i<=high-1;i++){
			if(A[i]<pivot){
				++start;
				swap(A[i],A[start]);
			}
		}
		swap(A[start+1],A[high]);
		return (start+1);
				
				
	
}

void quick_sort(vector<ll>& A,int low,int high){
	if(low<high){
			int r=part(A,low,high);
			quick_sort(A,low,r-1);
			quick_sort(A,r,high);
		
	} 

}


int Knp(vector<ll> W,vector<ll> P,ll S){
		ll dp[W.size()+1][S+1];
		for(int i=0;i<=W.size();i++){
			for(int j=0;j<=S;j++){
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(W[i-1]>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i-1]]+P[i-1]);
			}
		}
		return dp[W.size()][S];
		
}

int coin_change(vector<ll> C,int S){
		ll dp[S+1];
		dp[0]=0;
		for(int i=1;i<=S;i++){
			dp[i]=INT_MAX;
			for(auto x:C){
				if(i-x>=0)
					dp[i]=min(dp[i],dp[i-x]+1);
			}
		}
		return dp[S];

}
int upper(vector<ll> A,int val){
		int low=0;
		int high=A.size()-1;
		while(low<high){
				int mid=low+(high-low)/2;
				if(A[mid]<=val)
					low=mid;
				else 
					high=mid;
					
		}
		return low;
}
ll calc(ll n){
		return ((n*(n+1))/2);
	
}
void SOD(vector<ll> A,int i,int j,ll& cnt,ll K){
		if(i<j){
			if(abs(A[i]-A[j])>=K){
				++cnt;
			}
			
			SOD(A,i+1,j-1,cnt,K);
	 }
	 return;
}
ll maxEle(vector<ll> A,int low,int high){
		if(low<high){
			if(low==high-1)
				return max(A[low],A[high]);
			int mid=low+(high-low)/2;
			ll a=maxEle(A,low,mid);
			ll b=maxEle(A,mid+1,high);
			return max(a,b);
		}
		return -1;
}
ll minEle(vector<ll> A,int low,int high){
		if(low<high){
				if(low=high-1)
					return min(A[low],A[high]);
				
				int mid=low+(high-low)/2;
				ll a=minEle(A,low,mid);
				ll b=minEle(A,mid+1,high);
				return min(a,b);
		}
		return -1;
		
	
}
void test_case(vector<ll>& A){
		ll n=A.size();
		ll lst=A[n-1];
		ll temp=A[0];
		A[0]=lst;
		for(int i=1;i<n;i++){
				ll k=A[i];
				A[i]=temp;
				temp=k;
		}
} 
ll next_gap(ll m){
		if(m<=1)
			return 0;
		return (m+1)/2;
	
}
bool is_prime(ll n){
		ll i=2;
		ll k=ceil(sqrt(n));
		while(i<=k){
				if(n%i==0)
					return false;
				k+=1;
		}
		return true;
}
ll test(unordered_map<ll,ll> M,vector<pair<ll,ll>> P){
		ll n=P.size();
		ll c=INT_MAX;
		for(int i=0;i<n;i++){
				ll ans=M[P[i].first]-1;
				if(P[i].first!=P[0].first)
					ans++;
				if(P[i].first!=P[n-1].first)
					ans++;
				c=min(c,ans);
			
		}
		return c;
	
}
void test_case(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	vector<ll> A(n);
	vector<ll> B(m);
	for(auto& x:A)	
		scanf("%lld",&x);
	for(auto& x:B)
		scanf("%lld",&x);
	sort(A.rbegin(),A.rend());
	ll cnt=0;
	ll j=0;
	for(int i=0;i<n;i++){
			if(j<m && B[j]<=B[A[i]-1]){
					cnt+=B[j];
					++j;
			}
			else{
				cnt+=B[A[i]-1];
			}
	}
	printf("%lld\n",cnt);
	
}

int main(){
		int t;
		scanf("%d",&t);
		while(t--){
				test_case();
				
		}
		
			
			
}

