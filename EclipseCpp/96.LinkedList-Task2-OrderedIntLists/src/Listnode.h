// Exercise 20.6 Solution: ListNode.h
// ListNode class template definition
#ifndef LISTNODE_H
#define LISTNODE_H

template< typename T > class List; // forward declaration

template< typename NODETYPE >
class ListNode 
{
   friend class List< NODETYPE >; // make List a friend
public:
   ListNode( const NODETYPE & ); // constructor
   NODETYPE getData() const; // return the data in the node

   // set nextPtr to nPtr
   void setNextPtr( ListNode *nPtr ) 
   { 
      nextPtr = nPtr; 
   } // end function setNextPtr
   
   // return nextPtr
   ListNode *getNextPtr() const 
   { 
      return nextPtr; 
   } // end function getNextPtr

private:
   NODETYPE data; // data
   ListNode *nextPtr; // next node in the list
}; // end class ListNode

// constructor
template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
{
   data = info;
   nextPtr = 0;
} // end constructor

// return a copy of the data in the node
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
} // end function getData

#endif

