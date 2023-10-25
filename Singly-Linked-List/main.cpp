#include <iostream>
#include <memory>


struct Node{
   int data;

   std::shared_ptr<Node> next;

   Node() : data(0), next(nullptr) {;}
   Node(int value): data(value), next(nullptr) {;}

};


int main()
{
   std::shared_ptr<Node> head;
   

   if(!head){
      std::shared_ptr<Node> newNode = std::make_shared<Node>(10);
      newNode->next = nullptr;
      head = newNode;
   }

   head->next = std::make_shared<Node>(20);
   head->next->next = nullptr;

   std::shared_ptr<Node> current = head;
   
   while(current != nullptr){
      std::cout << current->data << " -> ";
      current = current->next;
   }

   std::cout << "nullptr" << std::endl;

   return 0;
}
