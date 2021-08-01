#include<iostream> 
#include<stdio.h> 
#include<unistd.h> 
#include<sys/wait.h> 
#include<stdlib.h>
using namespace std; 

 
int main() 
{ 
 int inp[2], inp2[2]; 
 int p1[2], p2[2], p3[2], p4[2]; 
 int pid1; 
 int arr[2], arr1[2], arr2[2], arr3[2]; 
 pipe(p1); 
 pipe(p2); 
 pipe(p3); 
 pipe(p4); 
 pid1 = fork(); 
 if (pid1 == 0) 
 { 
  int pid3 = fork(); 
  if (pid3 == 0) 
  { 
   close(p3[1]); 
   read(p3[0], arr1, sizeof(arr1)); 
   cout << " Sum of Numbers is: " << arr1[0] << endl; 
   cout << "Subtraction is: " << arr1[1] << endl; 
   close(p3[0]); 
   close(p4[1]); 
   read(p4[0], arr2, sizeof(arr2)); 
   close(p4[0]); 
   cout << "Multiplication is: " << arr2[0] << endl; 
   cout << "Division is: " << arr2[1] << endl; 
   exit(1); 
  } 
  else 
  { 
 
   close(p1[1]); 
   read(p1[0], arr, sizeof(arr)); 
   int add = arr[0] + arr[1]; 
   int sub = arr[0] - arr[1]; 
   close(p1[0]); 
   arr[0] = add; 
   arr[1] = sub; 
   close(p3[0]); 
   write(p3[1], arr, sizeof(arr)); 
   close(p3[1]); 
   exit(1); 
  } 
 } 
 else 
 { 
  int pid2 = fork(); 
  if (pid2 == 0) 
  { 
 
   close(p2[1]); 
   read(p2[0], arr3, sizeof(arr3)); 
   int mul = arr3[0] * arr3[1]; 
   int div = arr3[0] / arr3[1]; 
   close(p2[0]); 
   arr3[0] = mul; 
   arr3[1] = div; 
   close(p4[0]); 
   write(p4[1], arr3, sizeof(arr3)); 
   close(p4[1]); 
   exit(1); 
  } 
  else 
  { 
 
   cout << "Entre first number : "; 
   cin >> inp[0]; 
   cout << "Entre second number : "; 
   cin >> inp[1]; 
 
   cout << "Entre first number : "; 
   cin >> inp2[0]; 
   cout << "Entre second number : "; 
   cin >> inp2[1]; 
                        cout<<endl<<endl; 
   close(p1[0]); 
   write(p1[1], inp, sizeof(inp)); 
   close(p1[1]); 
   close(p2[0]); 
   write(p2[1], inp2, sizeof(inp2)); 
   close(p2[1]); 
  } 
 } 
 return 0; 
}

