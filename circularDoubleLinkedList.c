#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static unsigned int depth;

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head;
struct Node *tail;

void createFirstNode( struct Node **node, int value );
void pushNodeFront( int value );
void pushNodeBack( int value );

int main()
{
  depth = 0;
  struct Node *node = (struct Node *)malloc( sizeof( struct Node ) );
  createFirstNode( &node, 10 );

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

  printf( "List depth = %u\n", depth );
  printf( "\nNode id: %x -> { %d, %x, %x }\n", *node, (*node)->data, (*node)->next, (*node)->prev );
  printf( "\nHead: %x, Tail: %x\n", head, tail );
  printf( "\nList status:\n" );
  
  for (int i=0; i<depth; ++i)
  {
    printf( "%x  %d\n", *node, (*node)->data );
    (*node)=(*node)->next;
  }

  return;
}

void pushNodeFront( int value )
{
  ++depth;

  struct Node *newNode = (struct Node *)malloc(sizeof (struct Node) );
  
  newNode->prev = tail;
  newNode->next = head;

  head->prev = newNode;
  tail->next = newNode;

  head = newNode;
}


void pushNodeBack(int value )
{
}
