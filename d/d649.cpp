#include <bits/stdc++.h>
using namespace std;
#define int long long  



signed main(){
	int n;
	while(cin>>n and n!=0){
		for(int i=1; i<=n; i++){
			for(int j=n-i; j>0; j--){
				cout<<"_";
			}
			for(int j=1; j<=i; j++){
				cout<<"+";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}
