#include <iostream>
using namespace std;

int main(){
	int max,n,x[100],i;
	cout<<"Banyak elemen : "; cin>>n;
	for (int i=0; i<n;){
		cout<<"Input elemen ke -"<<++i<<" : "; cin>>x[i];
	}
	max=x[1];
	i=2;
	do{
		if(x[i]>max){
			max=x[i];
		}
		i=i+1;
	}while(i<=n);
	cout<<"Nilai maksimum : "<<max;
}
