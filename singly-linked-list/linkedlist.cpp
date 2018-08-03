#include<iostream>
#include<memory>
using namespace std;

template<class T>
class Node {
  public:
    T data;
    shared_ptr<Node<T>> next;
    Node(T i) {
      data = i;
    }
};

template<class T>
class LinkedList {
  public:
    // Adds to the end of the list
    void append(T val) {
      if (head == NULL) {
        head = shared_ptr<Node<T>>(new Node<T>(val));
        return;
      }
      auto temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = shared_ptr<Node<T>>(new Node<T>(val));
    }

    // Prints the list
    void print_list() {
      auto temp = head;
      while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
      }
    }

  private:
    shared_ptr<Node<T>> head;
};

int main(int argc, char *argv[]){
  auto ll = LinkedList<int>();
  ll.append(4);
  ll.append(5);
  ll.print_list();
  return 0;
}
