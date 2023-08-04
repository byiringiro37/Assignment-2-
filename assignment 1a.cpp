#include <iostream>
#include <vector>
using namespace std;



   int main () {
   	int i,j,d;
   	int sumd,sumc=0,sumr=0;
   	bool boole=false;
	   cout<<"Input the number of rows and columns:"<<endl;
   	    cin>>i;
   	     j=i;
  
    vector<vector<int>> m(i, vector<int>(j));
   
   	for(int x=0; x<i ;x++){
   		for(int y=0; y<j; y++) {
   				cout<<"input elements of row "<<x<<""<<"column "<<y<<":"<<endl;
   				cin>>m[x][y];
   			}
		    }
		    
		
	for(int x=0; x<i ;x++){
   		for(int y=0; y<j; y++) {
   			sumr=sumr+m[x][y];
   		}
   	}

	 	for(int y=0; y<j; y++) {
	 		for(int x=0; x<i ;x++){
	 			sumc=sumc+m[x][y];
			 }
		 }
	 
	     for(int x=0; x<i ;x++) {
	     sumd=sumd+m[x][x];
		 }
	
	sumr=sumr/i;
	sumc=sumc/j;
		 
		
	   
	   
	   if(sumd==sumc && sumc==sumr) {
	   
	      cout<<"the matrix is a square matrix"<<endl;
   }
	    else {
       	cout<<"the matrix is not a square matrix"<<endl;
	   }


   
   
   	return 0;
   }
