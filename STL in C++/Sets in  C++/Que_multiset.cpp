// Monk and the Magical Candy Bags  (hackerearth.com)
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T ;
	cin>> T ;
	while(T--){
		int N, K ;>
		cin>> N >> K ;

		multiset<long long> bag ;
		for(int i=0 ; i<N ; i++){
			long long  val ;
			cin>> val ;
			bag.insert(val) ;
		}

		long long max = 0 ;
		
		while(K != 0){
			auto it = (--(bag.end()));
			//cout<<(*it) ;
			max += (*it) ;
			long long new_val = (*it) / 2;
			bag.erase(it) ;
			bag.insert(new_val) ;
			K-- ;
		}

		cout<<max<<endl;
	}
}