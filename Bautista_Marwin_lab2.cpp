#include <iostream>
 
using namespace std;
#include <iostream>
using namespace std;

char stack[20];
int top = -1;

string stackOutput = "";

void push(char val){
    stack[++top] = val;
    stackOutput +=val;
}

char pop(){
    stackOutput.erase(top, 1);
    char val = stack[top--];
    return val;
}

char peek(){
    return stack[top];
}

int checklevel(char operation){
    int level;
    
    if(operation == '(' || operation == ')'){
        level = 0;
    }else if(operation == '^'){
        level = 1;
    }else if(operation == '/' || operation == '*'){
        level = 2;
    }else if(operation == '+' || operation == '-'){
        level = 3;
    }else{
        level = 0;
    }
    
    return level;
}

void convertToPostfix(string input){
    string output ="";

    cout << "| input | Stack | Output |" <<endl;
    cout << "|------------------------|" <<endl;

    for(int i = 0; i < input.length(); i++){
        
        if (isdigit(input[i])){
            output += input[i];
            
        }else{
            
            if(top == -1){
                push(input[i]);
                
            }else{
                
                if(input[i] == '(' || peek() == '('){
                    push(input[i]);
                }else{
                    if (input[i] == ')'){
                        while(top >= 0 && peek() != '('){
                            output += pop();
                        }
                        
                        if(top >= 0 && peek() == '('){
                            pop();
                        }
                    }else{
                        
                        while(checklevel(peek()) <= checklevel(input[i])){
                            output += pop();
                        }
                        
                        push(input[i]);
                    }
                }
            }
        }

        cout << "|   " << input[i] << "   | " << stackOutput <<" | " << output  << " |" <<endl;
        cout << "|------------------------|" <<endl;
    }
    
    while(top >= 0){
        output += pop();
    }
    
    cout << "The equivalent postfix is: " << output <<endl;
}

int main() {
    string input = "(2+3)-5*4/5";
    string input2 = "(5+5) * (8-2)";
    string input3 = "5+5+3*4-7";
    string input4 = "(5+6)*2+1";
    string input5 = "(5+6)*(2+1)";
   
    convertToPostfix(input);
    convertToPostfix(input2);
    convertToPostfix(input3);
    convertToPostfix(input4);
    convertToPostfix(input5);

    return 0;
}

 typedef struct Node{
    string songName;
    Node *link;
 }node;

 Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
 }

 void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode; 
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
        temp = temp->link; 
    }
    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}
 
Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning\n" <<endl;

    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new node has been added after " + after + "\n";
}
int main(){
    
    Node *head = createNode("Satuary bu Joji");

    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    traverse(head);

    
    return 0;
}
    















