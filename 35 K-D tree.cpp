#include <stdio.h>
#include <conio.h>
#include<malloc.h>
#include <stdlib.h>
typedef int ElementType;
typedef ElementType ItemType[2];
struct KdNode;
typedef struct KdNode *Position;
typedef struct KdNode *KdTree;
struct KdNode
{
ItemType Data;
KdTree Left;
KdTree Right;
};
static KdTree RecursiveInsert( ItemType Item, KdTree T, int Level )
{
if( T == NULL )
{
T = (struct KdNode *)malloc( sizeof( struct KdNode ) );
if( T == NULL )
{
printf( "Out of space!!!" );
return 0;
}
T->Left = T->Right = NULL;
T->Data[ 0 ] = Item[ 0 ];
T->Data[ 1 ] = Item[ 1 ];
}
else
if( Item[ Level ] < T->Data[ Level ] )
T->Left = RecursiveInsert( Item, T->Left, !Level );
else
T->Right = RecursiveInsert( Item, T->Right, !Level );
return T;
}
KdTree Insert( ItemType Item, KdTree T )
{
return RecursiveInsert( Item, T, 0 );
}
static void RecPrintRange( ItemType Low, ItemType High, KdTree T, int Level )
{
if( T != NULL )
{
if( Low[ 0 ] <= T->Data[ 0 ] &&
T->Data[ 0 ] <= High[ 0 ] &&
Low[ 1 ] <= T->Data[ 1 ] &&
T->Data[ 1 ] <= High[ 1 ] )
printf( "(%d,%d)\n",
T->Data[ 0 ], T->Data[ 1 ] );
if( Low[ Level ] <= T->Data[ Level ] )
RecPrintRange( Low, High, T->Left, !Level );
if( High[ Level ] >= T->Data[ Level ] )
RecPrintRange( Low, High, T->Right, !Level );
}
}
void PrintRange( ItemType Low, ItemType High, KdTree T )
{
RecPrintRange( Low, High, T, 0 );
}
int main( )
{
KdTree T;
ItemType It, L, H;
int i;
printf( "Starting program\n" );
T = NULL;
for( i = 300; i < 370; i++ )
{
It[ 0 ] = i; It[ 1 ] = 2500 - i;
T = Insert( It, T );
}
printf( "Insertions complete\n" );
i = 1;
L[ 0 ] = 70; L[ 1 ] = 2186; H[ 0 ] = 1200; H[ 1 ] = 2200;
PrintRange( L, H, T );
printf( "Done...\n" ) ;
getch();
return 0;
}
