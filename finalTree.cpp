#include<iostream>
using namespace std;
struct node{
int theNumber;
node *leftChild;
node*rightChild;

};
class binarySearchTree{

    public:
 node *root;//why did we do this by default ?  when ever we are in the instance of thia class we know at 
 //at the beginning root is pointer to the another node . 
 //
  node*  creatNode(int number){
    node* newNode=new node;//here I have created the new node .
    newNode->theNumber=number;
    newNode->rightChild=NULL;
    newNode->leftChild=NULL;
return newNode;
//what is the question right now ?
//I created just one node I am not filling one container as in the array 

 }
 void insertNode(int arr [],int num){
for(int i=0;i<num;i++){
   node *theNewNode=  creatNode(arr[i]);//but here that created node should be collected and inserted in some  sorts 
   //now we do the new node and the pointer pointing to . 
    if(root==NULL){
        root=theNewNode;
        cout<<"now the root is "<<theNewNode->theNumber<<"and sucessfully adde to the node \n";
    }
    //okay having been  finished the root now lets add one more 
    else{
    //now we know that the root is not null it does have the value which is 5 but now we are evaluated to be else statement 
    //what did we come here with 
    // we now we have new node with us ,non null root . but in the node after the root we ae going to trace the things down but in the ninary
    //search tree things go  from the top down checking the right and left for the traversing we use  the traversing  pointer . 
     
    }
}
 }




};
int main(){
int num[]={5,2};

binarySearchTree bst;
bst.insertNode(num,2);
 
}