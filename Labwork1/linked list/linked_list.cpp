#include "linked_list.h"

Node::Node(int data){
		this->data=data;
		this->link=NULL;
}

int Node::get_data(){
		return data;
}

void Node:: set_data(int data){
    this->data=data;
}

void Node::set_link(Node* link){
		this->link=link;
}

Node* Node::get_link(){
		return link;
}

Node* Node::get_prev(){
    return prev;
}

//functions of class Linked_list
Linked_list::Linked_list(){
		head=NULL;
}

void Linked_list::create_list(){
		string op;
		int x;
		Node* current;
		current=head;

		do{
			cout<<"Enter the value:";
			cin>>x;
			Node* node=new Node(x);
			if (head==NULL){
				head=node;
				current=head;
			}
			else {

				current->set_link(node);
				current=node;
			}
			cout<<"Do you wanna add number(y/n):";
			cin>>op;
		}while(op=="y");
}

void Linked_list::display(){
		Node* p=head;
		while (p!=NULL){
			cout<<p->get_data()<<endl;
			p=p->get_link();
		}
}

void Linked_list::insert_at_begin(int key){
    Node* node=new Node(key);
    node->set_link(head);
    head = node;
}

void Linked_list::insert_at_end(int key){
    Node* p = head;
    while(p->get_link()!=NULL){
        p = p->get_link();
    }
    Node* node = new Node(key);
    node ->set_link(NULL);
    p->set_link(node);
}

void Linked_list::insert_after_key(int key, int item){
    Node* p = head;
    while(p->get_link()!=NULL && p->get_data()!=key){
        p = p->get_link();
    }
    Node* q = p->get_link();
    Node* node = new Node(item);
    node->set_link(q);
    p->set_link(node);
}

void Linked_list::insert_before_key(int key,int item){
    Node* p = head;
    Node* q = p->get_link();

    while(q->get_data()!=key){
        p = q;
        q = q->get_link();
    }
    if(q==NULL){
        cout<<"Key not found in the list. Unable to insert before key."<<endl;
    }
    Node* node = new Node(item);
    p->set_link(node);
    node->set_link(q);
}

void Linked_list::delete_at_begin(){
    if(head==nullptr){
        cout<<"Key not found in the list."<<endl;
        return;
    }
        Node* temp = head;
        head = head->get_link();
        delete temp;
}

void Linked_list::delete_at_end(){
    if (head == NULL) {
        cout << "List is empty. Unable to delete from the end." << endl;
        return;
    }

    Node* p = head;
    Node* q = p->get_link();
    while(q->get_link()!=NULL){
        p = q;
        q = q->get_link();
    }
    delete p->get_link();
    p->set_link(NULL);
}

void Linked_list::delete_at_key(int key){
    Node* p = head;
    Node* q = p->get_link();
    while(q->get_data()!= key){
        p = q;
        q = q->get_link();
    }
    p->set_link(q->get_link());
    delete q;
}

void Linked_list::concatenate(Linked_list l2){
    if(head == nullptr){
        head = l2.head;
        return;
    }

    Node* current = head; //traverse ig
    while(current->get_link()!=NULL){
        current = current->get_link();
    }
    current->set_link(l2.head);
}

Node* Linked_list::search(int key){
    Node* current = head;
    while(current->get_link()!=NULL){
        if(current->get_data() == key){
            cout<<"Target found: "<<current->get_data()<<endl;
            return current;
        }
        current = current->get_link();
    }
    return nullptr;
}

void Linked_list::reverse_list() {
    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->get_link();
        current->set_link(previous);
        previous = current;
        current = next;
    }

    head = previous;
}

void Linked_list::reverse_traversal(){
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

     while (current != NULL) {
        next = current->get_link();
        current->set_link(prev);
        prev = current;
        current = next;
    }
     head = prev;

     Node* reversedCurrent = head;
    while (reversedCurrent != NULL) {
        cout << reversedCurrent->get_data() << endl;
        reversedCurrent = reversedCurrent->get_link();
    }

}

Node* Linked_list::find_min(Node* start) const {
    if (start == NULL) {
        return NULL;
    }

    Node* minNode = start;
    Node* current = start->get_link();

    while (current != NULL) {
        if (current->get_data() < minNode->get_data()) {
            minNode = current;
        }
        current = current->get_link();
    }

    return minNode;
}

void Linked_list::selection_sort() {
    if (head == NULL || head->get_link() == NULL) {
        cout << "List is already sorted or empty. Nothing to sort." << endl;
        return;
    }

    Node* current = head;

    while (current != NULL) {
        Node* minNode = find_min(current);
        //swap..try to implement the ones you already used
        int temp = current->get_data();
        current->set_data(minNode->get_data());
        minNode->set_data(temp);

        current = current->get_link();
    }

}

/*void traverse(){
    while p->
}*/

