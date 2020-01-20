
#include<bits/stdc++.h> 
#define EPSILON 0.001 
#define PI 3.14
using namespace std; 


double func(double x) 
{ 
	return sin(x); 
} 


double derivFunc(double x) 
{ 
	return cos(x); 
} 
 
void newtonRaphson(double x) 
{ 
	double h = func(x) / derivFunc(x); 
	while (abs(h) >= EPSILON) 
	{ 
		h = func(x)/derivFunc(x); 

		 
		x = x - h; 
	} 

	cout << "The value of the root is : " << x; 
} 

 
int main() 
{ 
	double x0 ;
	cin>>x0; 
    newtonRaphson(x0); 
	return 0; 
} 
