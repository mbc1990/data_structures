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
      size += 1;
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

    // Remove an item
    void remove(int idx) {
      if (idx > size - 1) {
        return;
      }

      size--;

      if (idx == 0) {
        head = head->next;
        return;
      }
      auto temp = head;
      int counter = 0;
      while (counter < idx) {
        if (counter+1 == idx) {
          temp->next = temp->next->next;
          return;
        } else {
          temp = temp->next;
          counter++;
        }
      }
    }

    // Prints the list
    void print_list() {
      auto temp = head;
      while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
      }
    }

    LinkedList() {
      size = 0;
    }

  private:
    int size;
    shared_ptr<Node<T>> head;
};

int main(int argc, char *argv[]){
  auto ll = LinkedList<string>();
  ll.append("hi");
  ll.append("hello");
  ll.append("bye");
  ll.print_list();
  ll.remove(1);
  ll.print_list();
  return 0;
}
