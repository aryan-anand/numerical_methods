#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the product term 
float proterm(int i, float value, float x[]) 
{ 
    float pro = 1; 
    for (int j = 0; j < i; j++) { 
        pro = pro * (value - x[j]); 
    } 
    return pro; 
} 
  
// Function for calculating 
// divided difference table 
void dividedDiffTable(float x[], float y[][10], int n) 
{ 
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            y[j][i] = (y[j][i - 1] - y[j + 1] 
                         [i - 1]) / (x[j] - x[i + j]); 
        } 
    } 
} 
  
// Function for applying Newton's 
// divided difference formula 
float applyFormula(float value, float x[], 
                   float y[][10], int n) 
{ 
    float sum = y[0][0]; 
  
    for (int i = 1; i < n; i++) { 
      sum = sum + (proterm(i, value, x) * y[0][i]); 
    } 
    return sum; 
} 
  
// Function for displaying  
// divided difference table 
void printDiffTable(float y[][10],int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            cout << setprecision(4) <<  
                                 y[i][j] << "\t "; 
        } 
        cout << "\n"; 
    } 
} 
  
// Driver Function 
int main() 
{ 
    // number of inputs given 
    int n ;
    cin>>n; 


    
    float value, sum;
    float y[10][10]; 
    float x[n];

  
    for(int i=0;i<n;i++)
    {  
        cout<<"enter the value of x "<<i<<" ";
        cin>>x[i];
    } 
    cout<<"enter the value of f(x)";
    for(int i=0;i<n;i++)
    {
        
        
            cin>>y[i][0];
            cout<<" ";
        
    }
   
  
    // calculating divided difference table 
    dividedDiffTable(x, y, n); 
  
    // displaying divided difference table 
    printDiffTable(y,n); 
  
    // value to be interpolated 
    cin>>value;
  
    // printing the value 
    cout << "\nValue at " << value << " is "
               << applyFormula(value, x, y, n) << endl; 
    return 0; 
} 