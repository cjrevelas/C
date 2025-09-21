// Headers
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


// Data declarations
static unsigned int depth;

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head;
struct Node *tail;


// Forward function declarations
void createFirstNode( struct Node **node, int value );
void pushNodeFront( int value );
void pushNodeBack( int value );
void printList( );
void printListReversed( );


//Function implementations
int main()
{
  depth = 0;
  struct Node *node = (struct Node *)malloc( sizeof( struct Node ) );
  createFirstNode( &node, 10 );
  printList();

  printf( "--------------------------------------------------------------------\n" );
  pushNodeFront(20);
  printList();
  printf( "\nHead: %x, Tail: %x\n", head, tail );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeBack(30);
  printList();
  printf( "\nHead: %x, Tail: %x\n", head, tail );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeFront(50);
  printList();
  printf( "\nHead: %x, Tail: %x\n", head, tail );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeBack(80);
  printList();
  printf( "\nHead: %x, Tail: %x\n", head, tail );
  printf( "--------------------------------------------------------------------\n" );

  printf( "head->prev: %x, head->next: %x\n", head->prev, head->next );
  printf( "tail->prev: %x, tail->next: %x\n", tail->prev, tail->next );
  printf( "--------------------------------------------------------------------\n" );

  return 0;
}


void createFirstNode( struct Node **node, int value )
{
  ++depth;

  (*node)->data = value;
  (*node)->next = *node; // Points at itself
  (*node)->prev = *node; // Points at itself

  //
  // Update head and tail pointers
  //
  head = *node;
  tail = *node;

  printf( "\n--------------------------------------------------------------------\n" );
  printf( "List depth = %u\n", depth );
  printf( "\nNode id: %x -> { %d, %x, %x }\n", *node, (*node)->data, (*node)->next, (*node)->prev );
  printf( "\nHead: %x, Tail: %x\n", head, tail );
  printf( "\nList status:\n" );

  return;
}


void printList( )
{
  struct Node *tempNode = (struct Node *)malloc( sizeof( struct Node ) );

  tempNode = head;

  for (int i=0; i<depth; ++i)
  {
    printf( "%x %d\n", tempNode, tempNode->data );

    tempNode = tempNode->next;
  }

  return;
}


void pushNodeFront( int value )
{
  ++depth;

  struct Node *newNode = (struct Node *)malloc(sizeof (struct Node) );

  newNode->prev = tail;
  newNode->next = head;
  newNode->data = value;

  head->prev = newNode;
  tail->next = newNode;

  head = newNode;
}


void pushNodeBack( int value )
{
  ++depth;

  struct Node *newNode = (struct Node *)malloc(sizeof (struct Node) );

  newNode->prev = tail;
  newNode->next = head;
  newNode->data = value;

  head->prev = newNode;
  tail->next = newNode;

  tail = newNode;
}
