#include "linked_list.cpp"

int main(){
	Linked_list l1;
	Linked_list l2;
	cout<<"Linked list 1: "<<endl;
	l1.create_list();
    l1.insert_at_end(3);
    l1.insert_after_key(3,8);
	l1.delete_at_begin();
	l1.delete_at_end();
	l1.delete_at_key(9);
	cout<<"Linked list 2: "<<endl;
	l2.create_list();
	l2.insert_at_begin(10);
	l2.insert_before_key(3,2);
	l1.concatenate(l2);
	cout<<"concatenated list"<<endl;
	l1.display();
	cout<<"search"<<endl;
	l1.search(2);
	cout<<"reverse"<<endl;
	l1.reverse_list();
	l1.display();
	cout<<"Traversal"<<endl;
	l1.reverse_traversal();
	cout<<"Sorting"<<endl;
	l1.selection_sort();
	l1.display();
	return 0;
}
