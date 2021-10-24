#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
typedef int ElementType;

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType* Elements;
};

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int isFull(PriorityQueue H);

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    H = (PriorityQueue) malloc(sizeof(struct HeapStruct));
    H -> Capacity = MaxElements;
    H -> Size = 0;
    H -> Elements = (ElementType*) malloc( sizeof(ElementType) * (MaxElements + 1) );
    H -> Elements[0] = INT_MIN;
    return H;
}
void Destroy(PriorityQueue H)
{
    free(H -> Elements);
    free(H);
}
void MakeEmpty(PriorityQueue H)
{
    H -> Size = 0;
}
void Insert(ElementType X,PriorityQueue H)
{
    if(isFull(H)) {
        printf("FULL!!!!!!!!!\n");
    }
    else {
        int i;
        for(i = ++H -> Size; X < H -> Elements[i / 2]; i /= 2) {
            H -> Elements[i] = H -> Elements[i / 2];
        }
        H -> Elements[i] = X;
    }
}
ElementType DeleteMin(PriorityQueue H)
{
    if(isEmpty(H)) {
        printf("EMPTY!!!!!!!!!!!\n");
    }
    else {
        ElementType Min,Last;
        int Child,Parent;
        Min = H -> Elements[1];
        Last = H -> Elements[H -> Size--];
        for(Parent = 1; Parent * 2 <= H -> Size; Parent = Child) {
            Child = Parent * 2;
            if(Child != H -> Size && H -> Elements[Child + 1] < H -> Elements[Child] ) {
                Child++;
            }
            if(Last > H -> Elements[Child]) {
                H -> Elements[Parent] = H -> Elements[Child];
            }
            else break;
        }
        H -> Elements[Parent] = Last;
        return Min;
    }
}
ElementType FindMin(PriorityQueue H)
{
    if(isEmpty(H)) {
        printf("EMPTY!!!!!!!!!!!\n");
    }
    else {
        return H -> Elements[1];
    }
}
int isFull(PriorityQueue H)
{
    return H -> Size == H -> Capacity;
}
int isEmpty(PriorityQueue H)
{
    return H -> Size == 0;
}
int main(void)
{
    PriorityQueue H = Initialize(100);
    int a[] = {80, 40, 30, 60, 90, 70, 10, 50, 20};
    int i;
    for(i = 0; i < sizeof(a) / sizeof(int); i++) {
        Insert(a[i],H);
    }
    for(i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d\n",DeleteMin(H));
    }
    return 0;
}
