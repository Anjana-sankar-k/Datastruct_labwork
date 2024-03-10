#include<iostream>
using namespace std;

class Node{

    int data;
    Node* link;
    Node* prev;

    public:
    Node(int);
    int get_data();
    void set_data(int data);
    Node* get_link();
    void set_link (Node*);
    Node* get_prev();
};

class Linked_list{
    Node* head;

    public:
    Linked_list();
    void create_list();
    void display();
    void traverse();
    void insert_at_begin(int);
    void insert_at_end(int);
    void insert_after_key(int, int);
    void insert_before_key(int,int);
    void delete_at_begin();
    void delete_at_end();
    void delete_at_key(int);
    void concatenate(Linked_list);
    Node* search(int);
    void reverse_list();
    void reverse_traversal();
    void selection_sort();
    Node* find_min(Node*)const;



};

