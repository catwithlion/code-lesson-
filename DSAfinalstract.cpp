#include<iostream>

using namespace std;
class stack {
 //what does tis class supoosed to have ? this is great question  
/*
stack has reference to  the top 
also has its container to push .
*/
//to get absolute reference  we need to use  int  also from -1 to get initial 0
int top=-1;
char  stackstore[100];
public:
 stack(){

}
void push (int number){
    if(top<100){
    top++;
    stackstore[top]=number;
    }
    else{
        cout<<"stack overflow\n";
    }
}
int pop(){
    if(top>-1){
        return stackstore[top];
        top--;
        
    } else{
cout<<"stack under flow \n ";
return -1;
    }
}
bool empty(){
    if (top==-1){
        return true;
    }
    else{
        return false;
    }
}
};
bool check(string word ){
    stack thestack;
 //here the algorithm works 
 //where do the algorithim lays ? this is the question right now  I think the algorithm use the stack and  
//okay I need to iterate  over the string   
for(char c:word) {
//now I have iterated over successfully , now I have to generate the algorithm  
     if(c=='('){
  thestack.push(c);
     }
     else if (c==')')
     { if(thestack.empty()){
        return false ;
     }else{
        thestack.pop();
     }
}
if(!thestack.empty()){
    return false;
}
 else{
    return true ;
 }
}}
int main()
{
    //stack implementation for string problem the problem string is stated as follows 
    //in the stream of string identify whether beacket is closed well or not 
cout<<"enter the word wich character within \n";
//the main point is about undersatanding the importance of the stack
    string theWord;
    getline(cin,theWord);
if(check(theWord)){
    //how does the algorithm work right now 
cout<<"the string has succesfully closed the bracket \n";
}
else{
    cout<<"the  bracket wasn't closed well \n";
}
return 0;
}