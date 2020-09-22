/*
This is set 9 Question 3. A stack is a data structure which can be represented
as a linked list. A stack is a constrained version of a linked list because it
is a last in first out (LIFO) data structure. Nodes can only be added or removed
at the top of the stack. Modify the C Program Linked List given in the lecture
and on Moodle to create a stack. The same functions for adding, removing,
printing nodes should be present.


This is the work of Ahmed Jouda (Student Number 18329393)
Created on 12/04/2019
*/

/* Operating and maintaining a linked list */
#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct listNode {
char data; /* each listNode contains a character */
struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */


typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, char value );
void delete( ListNodePtr *sPtr);
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );

int main( void )
{
ListNodePtr startPtr = NULL; /* initially there are no nodes */
int choice; /* user's choice */
char item; /* char entered by user */
instructions(); /* display the menu */
printf( "? " );
scanf( "%d", &choice );

/* loop while user does not choose 3 */
while ( choice != 3 ) {
switch ( choice ) {
case 1:
printf( "Enter a character: " );
scanf( "\n%c", &item );
insert( &startPtr, item ); /* insert item in list */
printList( startPtr );
break;
case 2: /* delete an element */
/* if list is not empty */
if ( !isEmpty( startPtr ) ) {
/* remove element from top of stack*/
printf("\nElement at top of stack deleted.\n");
delete( &startPtr); /* remove item */
printList( startPtr );
/* end if */
} /* end if */
else {
printf( "List is empty.\n\n" );
} /* end else */

break;
default:
printf( "Invalid choice.\n\n" );
instructions();
break;
} /* end switch */

printf( "? " );
scanf( "%d", &choice );
} /* end while */

printf( "End of run.\n" );
return 0; /* indicates successful termination */
} /* end main */

/* display program instructions to user */
void instructions( void )
{
printf( "Enter your choice:\n"
" 1 to insert an element into the list.\n"
" 2 to delete an element from the list.\n"
" 3 to end.\n" );
} /* end function instructions */

/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value )
{

  ListNodePtr newPtr = malloc(sizeof(ListNode));

  if (newPtr != NULL) { // is space available?
    newPtr->data = value; // place value in node
    newPtr->nextPtr = NULL; // node does not link to another node

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *sPtr;

    while(currentPtr != NULL) {
      previousPtr = currentPtr; //walk to...
      currentPtr = currentPtr->nextPtr; // next node...
    }

    // insert new node at beginning of list
    if(previousPtr == NULL){
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
    }
    else {// insert new node between previousPtr and
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }
  }
  else {
    printf("%c not inserted. No memory available.\n", value);
  }
} /* end function insert */

/* Delete a list element */
void delete(ListNodePtr *sPtr)
{
//check if this is the last element inserted by checking that its nextPtr ==NULL
//if thats true assign the pointer NULL and free it
if ( ( *sPtr )->nextPtr == NULL )
{
*sPtr = NULL;
free(*sPtr);
}

else
{
ListNodePtr previousPtr = *sPtr;
ListNodePtr currentPtr = ( *sPtr )->nextPtr;

/* loop to find the last location in the list where the last element is*/
while ( currentPtr->nextPtr != NULL) {
previousPtr = currentPtr; /* walk to ... */
currentPtr = currentPtr->nextPtr; /* ... next node */
} /* end while */

/* delete node at currentPtr (Top of stack)*/
if ( currentPtr != NULL ) {
ListNodePtr tempPtr = currentPtr;
previousPtr->nextPtr = currentPtr->nextPtr;
free(tempPtr);
} /* end if */
}
} /* end function delete */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
return sPtr == NULL;
} /* end function isEmpty */

/* Print the list */
void printList( ListNodePtr currentPtr )
{
/* if list is empty */
if ( currentPtr == NULL ) {
printf( "List is empty.\n\n" );
} /* end if */
else {
printf( "The list is:\n" );

/* while not the end of the list */
while ( currentPtr != NULL ) {
printf( "%c --> ", currentPtr->data );
currentPtr = currentPtr->nextPtr;
} /* end while */

printf( "NULL\n\n" );
} /* end else */
} /* end function printList */
