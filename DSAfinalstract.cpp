#include<iostream>
#include <stack>
using namespace std;
bool check(string word ){
 //here the algorithm works 
 //where do the algorithim lays ? this is the question right now  I think the algorithm use the stack and  
 stack <char> theStack ;
//okay I need to iterate  over the string   
for(char c:word) {
//now I have iterated over successfully , now I have to generate the algorithm  
     if(c=='('){
        theStack.push(c);
     }
     else if (c==')')
     { if(theStack.empty()){
        return false ;
     }else{
        theStack.pop();
     }
}
if(!theStack.empty()){
    return false;
}
 else{
    return true ;
 }
}
int main(){
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
}