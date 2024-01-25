#include <iostream>
using namespace std;
//LINK LIST NODE
class Node{ //I created a class here.
	public: 
	int data; // data for the value.
	Node* next; //next will point the aaddress of the next node.
};


//PRINT FUNCTION
void print(Node* head1)
{
	while(head1)
	{
		if(head1->next == NULL)
		
			cout<<"["<<head1->data<<"]";
		
		else
		{
			cout<<"["<<head1->data<<"]-->";
			
		}
		head1=head1->next; 
	}
	cout<<endl<<endl;
}


//INSERTING ELEMENT AT THE FRONT OF THE LIST
void push(Node** head, int new_data)
{
	//ALLOCATE THE NODE
	Node* new_node = new Node(); //new Node(): This expression creates a new Node object in memory. The new operator is used to allocate memory dynamically. The newly created node will be an instance of the Node class.
	
	//ASSIGN THE DATA
	new_node->data = new_data;
	
	//MAKE NEXT OF NEW NODE AS HEAD
	new_node->next = (*head);
	
	//MOVE THE HEAD TO POINT TO NEW NODE
	(*head) = new_node;  
}

//INSERTING AFTER A SPECIFIC NODE
void insertafter(Node* prev_node,int new_data)
{
	if(prev_node == NULL)
	{
		cout<<"given previous node can not be null."<<endl;
		return;
	}
	
	
	//ALLOCATE THE NODE
	Node* new_node = new Node();
	
	//ASSIGN THE DATA
	new_node->data = new_data;
	
	//MAKE NEXT OF NEW NODE AS NEXT OF PREVIOUS NODE
	new_node->next = prev_node->next;  //Assigns the pointer to the next node of the new node to the one pointing to the next node of the previous node. This step establishes the connection necessary to place the new node after the previous node.
	
	//MAKE NEXT OF prev_node AS new_node;
	prev_node->next = new_node;  //Assigns the address of the new node to the "next" pointer of the previous node. This step makes the next node of the previous node point to the newly created node.
	
}

//INSERTION AT THE END
void insertend(Node** head, int new_data)
{
	//ALLOCATE A NEW NODE
	Node* new_node = new Node();
	Node* last = *head; // This line defines the temporary pointer 'last', which will be used to traverse to the end of the linked list, and initializes this pointer with the head pointer that points to the beginning of the linked list.
	
	//ASSIGN THE DATA
	new_node->data = new_data;
	new_node->next = NULL;
	
	//if the list is empty given node will be the head node
	if(*head == NULL)
	{
		*head = new_node;
		return;
	}
	
	//to find the last node:
	while(last->next != NULL)
	{
		last=last->next;
	}
	//then new_node will be the last node:
	last->next=new_node;
	return;
}

//DELETE FROM BEGINING
void deletebegin(Node* &head)
{
	//check if the list is empty
	if(head == NULL)
	{
		cout<<"the list is empty. nothing to delete"<<endl;
		return;
	}
	
	//updae the head pointer to the next pointer
	Node* temp=head;
	head=head->next;
	delete temp;
}

//DELETE AFTER A SPECIFIC ELEMENT
void deleteaftervalue(Node* head, int value)
{
	//find the node given
	Node* current = head;
	while(current != NULL && current->data != value)
	{
		current=current->next;
	}
	// Check if the node with the specified value is found and if there is a node after it
	if(current != NULL && current->next != NULL)
	{
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}
	else
	{
		cout<<"Node with the specified data value not found or there is no node after it." << endl;
	}
}

//DELETE FROM END
void deletefromend(Node* &head)
{
	//check if the list is empty
	if(head==NULL)
	{
		cout<<"list is empty."<<endl;
		return;
	}
	
	//check if there is only one node
	if(head->next==NULL)
	{
		delete head;
		head= NULL;
		return;
	}
	
	//traverse to the second to last node
	Node* secondlast= head;
	while(secondlast->next->next != NULL)
	{
		secondlast=secondlast->next;
	}
	
	//if we delete secondlast's address will be delete the last node.
	delete secondlast->next;
	//then secondlast will be point NULL
	secondlast->next=NULL;
}

//SEARCH AN ELEMENT
bool search(Node* head,int value)
{
	//I created a new node called current 
	Node* current = head;
	//this loop will check the list, if the data of node is equal to the "value".
	while(current != NULL)
	{
		if(current->data == value)
		{
			return true;  //if yes it returns true
		}
		current = current->next;
	}
	return false; 
}

int main() {
	
	Node* head = NULL;
    
	push(&head,10);
	push(&head,30);
	push(&head,11);
	push(&head,21);
	push(&head,14);

	
	cout<<"CURRENT LIST: "<<endl;
	print(head);
	
	//INSERT A NEW NODE after node 30

	//find the node with data value 30
	Node* prev_node = head; 
	while(prev_node != NULL && prev_node->data != 30)
	{
		prev_node= prev_node->next;
	}
	cout<<"INSERT A VALUE AFTER A SPECIFIC NODE"<<endl;
	insertafter(prev_node,555);
	cout<<"AFTER INSERT 555 VALUE AFTER VALUE 30"<<endl;
	print(head);
	
	//INSERT AT THE END
	insertend(&head,1111);
	cout<<"INSERT 1111 VALUE AT THE END OF THE LIST"<<endl;
	print(head);
	
	//DELETE FROM BEGINING
	deletebegin(head);
	cout<<"DELETE THE FIRST ELEMENT"<<endl;
	print(head);
	
	//DELETE AFTER A SPECIFIC VALUE
	deleteaftervalue(head,30);
	cout<<"DELETE THE VALUE AFTER 30"<<endl;
	print(head);
	
	//DELETE FROM END
	deletefromend(head);
	cout<<"DELETE THE LAST ELEMENT"<<endl;
	print(head);
	
	//SEARCH FOR AN ELEMENT
	int target=30;
	if(search(head,target))
	{
		cout<<"this element is in the list."<<endl;
	}
	else
	{
		cout<<"this element is not in the list"<<endl;
	}
	return 0;
}
