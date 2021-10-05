     /*                         
							 ------     ------   |--|    |    |\    |    |----     |----
							 |            |      |  |    |    | \   |    |         |
							 |-----|      |      |--|    |	  |  \  |    |         |----|
							       |      |      |\      |    |   \ |    |   --|        |
							  -----|      |      | \     |    |    \|    |-----|    ----|
							 
							 
	 Strings are defined as an array of characters. The difference between a character array 
	   and a string is the string is terminated with a special null character .
	   
	   Basic Syntax :-      char str_name[size]    ( in C language)
	   
	   */
	   
	   
	   // THIS IS A CODE IN C++ FOR COMPARING 2 STRINGS
	   
	   
	   
	   
	   
#include<iostream>
using namespace std;

void comparing2strings(string a, string b){     //Declaring comparison function
    int x,y;
    x=a.length();
    y=b.length();

    if(x==y){
        cout<<"Both are Equal"<<endl;

    }else if(x>y){
        cout<<a<<" is greater"<<endl;
    }else{
        cout<<b<<" is greater"<<endl;
    }

}

int main(){      //Driver function
    string a,b;
    cout<<"Enter 1st string:- "<<endl;
    cin>>a;
    cout<<"Enter 2nd string:- "<<endl;
    cin>>b;

    comparing2strings(a,b);   //calling comparison function created above.
    return 0;
}



/* Input:- Hactoberfest
           github

/*The output will be:-

	Hactoberfest is greater.
	
	*/


