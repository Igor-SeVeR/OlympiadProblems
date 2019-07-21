#include <iostream>
#include <cmath>
using namespace std;
main(){
	int m, n, i, j, c;
	cin>>m;
	cin>>n;
	cin>>i;
	cin>>j;
	cin>>c;
	if(m%2==0 or n%2==0){
		cout<<"equal";
	}
	else{
		if((i+j)%2==0){
			if(c==1){
				cout<<"white";
			}
			else{
				cout<<"black";
			}
		}
		else{
			if(c==1){
				cout<<"black";
			}
			else{

				cout<<"white";
			}			
		}
	}
}
