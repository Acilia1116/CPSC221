#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
/* YOUR CODE HERE */
    clear();

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{

/* YOUR CODE HERE */
   Node* newNode = new Node(ndata);
   Node* tail_ = head_;
   while(tail_->next != head_)
    tail_ = tail_ -> next;
   tail_->next = newNode;
   newNode->next = head_;

   length_ ++; 
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
/* YOUR CODE HERE */
    Node* nodei = walk(head_,i-1);
    Node* nodej = walk(head_,j-1);

    Node* temp = nodei->next;
    nodei->next = nodej->next;
    nodej->next = temp;

    nodei = nodei->next;
    nodej = nodej->next;

    temp = nodei->next;
    nodei->next = nodej->next;
    nodej->next = temp;

}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
/* YOUR CODE HERE */
    Node* prev = head_;
    Node* curr = head_->next;
    Node* next = curr->next;

    while(curr != head_) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }

    head_->next = prev;
}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
/* YOUR CODE HERE */
    int num = k;
    for(int i = 1; i<= length_; i++) {
        if(num>1) {
            swap(i,i+1);
            num--;
        } else {
            num = k;
            if(length_ - i < k)
              break;
        }
    }

}

/**
 * Destroys ALL dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
/* YOUR CODE HERE */
    Node* t = head_;
    Node* d = head_;
    while(t->next != head_) {
        t = t->next;
        delete d;
        d = t;
    }
    delete t;

    head_ = NULL;
    length_ = 0;
    height_ = 0;
    width_ = 0;
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
/* YOUR CODE HERE */    
    head_ = NULL;
    length_ = 0;
    width_ = other.width_;
    height_ = other.height_;

    head_ = new Node();
    head_->next = head_;
    Node* otherCurr = other.head_->next;

    while (otherCurr != other.head_){
        insertBack(otherCurr->data);
        otherCurr = otherCurr->next;
    }



}
