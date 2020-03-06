
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <cstring> 
#include <cctype>
#include<stdio.h> 
#include<stdlib.h> 
#include <stack>
#include <string>  
using namespace std;
//all of the functions that are used for the post fix
float opperation(string charachter, float num1, float num2);
bool checkOpperation(string opperation);
bool checkchar(string find);
string parse(string  &line);


int main(){



//this is for the program to end when it hits one
int x=0;
//the orig string 
string num;
//the answer to the post fix equation ,variable
float answer;
//this is a float that holds the conversion 
float convert;
char expression;
bool quit=false;




 //the beginning while loop for the program
while(quit==false){
    // here is where i delcared the stack
    stack <float> mystack;
    //checks if answers are valid or invalid
bool valid=true;
    //the initial cout statment  and user input for the equation
    cout<<"Enter a postfix expression or quit to exit:"; 
    
    
   
    //reading in a line
    getline(cin, num);
    if(num == "quit"){
        quit = true;
    }
    else{
    //the second while loop letting while the string is not empty continue
    while(num!=""){
        
        
        
   
       string parsed=parse(num);
       
   //here is where we use the check operation function to check to see if there is an operation, if so we carry on with preforming it. we also push and pop from the stack here
    
  if (checkOpperation(parsed)==true){
      
      if(mystack.size()< 2){
         valid = false;
     }
     else{
      float  numberone=mystack.top();
      mystack.pop();
      float numbertwo=mystack.top();
      mystack.pop();
     answer =opperation( parsed ,numbertwo, numberone);
     mystack.push(answer);
     
     
     }
     //cout<<answer<<endl;
    
     
  }
      //here we preform conversions 
    else if(checkchar(parsed)==true){
         convert=stof(parsed);
       mystack.push(convert);
       
    }
    
  else if(checkchar(parsed)==false){
     valid=false;
       
  }
    
   
    
    }
    if(mystack.size()>1){
        valid=false;
    }
    if(valid==true){
        cout<<mystack.top()<<endl;
    }
    
    else if(valid==false){
         cout<<"Invalid Expression!"<<endl;
      
    }
    
}
}
return 0;
}

//checks if there is an operation 
bool checkOpperation(string opperation){
    if(opperation == "+"|| opperation== "-"||opperation== "/"|| opperation=="*"|| opperation== "^"){
        return true;
    }
    else{
        return false;
    }
}

//does the operations for addition, subtraction, multiplcation, division and exponent 

float opperation(string charachter, float num1, float num2){
if(charachter=="+"){
    float plus=num1+num2;
    return plus; 
}
else if(charachter=="-"){
    float minus =num1-num2;
    return minus;
}
else if(charachter=="/"){
    float divide= num1/num2;
    return divide;
}
else if(charachter=="^"){
    
    float exponent= pow(num1, num2);
    return exponent;
}
else if(charachter=="*"){
    float times= num1*num2;
    return times;
}
}

//this function checks if there is a charachter, checks if there is a digit and checks for periods
bool checkchar(string find){
    for(int i=0; i<find.size(); i++){
        if(isdigit(find[i])==false && find[i]!='.'&&find[i]!='-'){
            return false;
        }

    
    }
    return true;
}

//this function allows you to parse a sting line
string parse(string &line){
    string temp;
      
  if(line.find(" ")==string::npos) {
       
     temp=line;
    line="";
    
   } 
  else {
       int index= line.find(" ");
   temp = line.substr(0, index);
   line.erase(0, index+1);
  }
 
    
    return temp;
    
}




