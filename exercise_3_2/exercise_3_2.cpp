#include "exercise_3_2.hpp"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::add_to_front(std::string name) {
    // create a new unique pointer of type node
    std::unique_ptr<Node> new_node = std::make_unique<Node>();
    // remember that the -> operator is the same as (*a).b
    new_node->name = name;
    // set the new nodes next variable to the previous head pointer of the LL
    new_node->next = std::move(head);
    // set the new head of the LL as this node
    head = std::move(new_node);


    return;
}

void LinkedList::add_to_back(std::string name){
    // create a new pointer to a node
    std::unique_ptr<Node> new_node = std::make_unique<Node>();
    new_node->name = name;
    // since it is the last element we set its next pointer to null
    new_node->next = nullptr;
    // make sure the linked list is not empty
    if (head != nullptr) {
        Node* curr_ptr = head.get();
        // loop through list until we find the last node
        while(curr_ptr->next != nullptr) {
            curr_ptr = curr_ptr->next.get();
        }
        // set the new node as the next one
        curr_ptr->next = std::move(new_node);
    } else {
        // set the new node as the head (given an empty list)
        head = std::move(new_node);
    }
    return;
}

void LinkedList::add_at_index(std::string name, int index) {
    // create a new node
    std::unique_ptr<Node> new_node = std::make_unique<Node>();
    // assign the name
    new_node->name = name;
    if (index != 0) {
        // begin wiht the address of the head
        Node* curr_ptr = head.get();
        //loop until we reach one before the specified item in LL
        for (int i = 0; i < index -1; i++) {
            curr_ptr = curr_ptr->next.get();
        }
        // get the next address of the specified index
        // store it the actual node we are building
        new_node->next = std::move(curr_ptr->next);
        curr_ptr->next = std::move(new_node);   //?
    } else {
        // essentailly adding node at head (index = 0)
        new_node->next = std::move(head);
        head = std::move(new_node);
    }
    return;
}

void LinkedList::remove_from_front() {
    if (head != nullptr) {
        // assign the head to the next item in the LL
        head = std::move(head->next);
    }
    return;
}

void LinkedList::remove_from_back() {
    if (head != nullptr) {
        // see if another node exists
        if (head->next != nullptr) {
            Node* curr_ptr = head.get();
            // trace LL until second from last
            // since we are trying to remove the last one
            while (curr_ptr->next->next != nullptr) {
                curr_ptr = curr_ptr->next.get();
            }
            // safetly remove the memory of the last item in LL
            curr_ptr->next = nullptr;
        } else {
            // safetly remove the memory of the second item in LL
            // knowing there is a head and we want to remove next
            head = nullptr;
        }
    return;
    }
}

void LinkedList::remove_at_index(int index) {
    if( head != nullptr) {
        // check that we are not dealing with head
        if (index != 0) {
            Node* curr_ptr = head.get();
            // itertate right before the target index
            for (int i = 0; i < index - 1; i++) {
                curr_ptr = curr_ptr->next.get();
            }
            // jump over the address given by the index argument
            curr_ptr->next = std::move(curr_ptr->next->next);
        } else {
            // just jump to the next address
            head = std::move(head->next);
        }
    }
    return;
}

void LinkedList::print_names() {
    // create a pointer to the head (notice its not unique)
    Node* curr_ptr = head.get();
    // keep iterating while the address is not null
    while(curr_ptr != nullptr) {
        std::cout << curr_ptr->name << "\t";
        curr_ptr = curr_ptr->next.get();
    }
    std::cout << std::endl;
    return;
}
