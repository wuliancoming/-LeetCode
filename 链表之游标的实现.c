#ifndef _cursor_h
#define _cursor_h
/*1.数据存储在一组结构体中。每个结构体包含有数据以及指向下一个结构体的指针。
2.一个新的机构体可以通过调用malloc从系统全局内存得到，并可调用free释放。
*/

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace();
List MakeEmpty(List l);
int IsEmpty(const List l);
int IsLast(const Position P, const List l);
Position Find(ElementType x, const List l);
void Delete(ElementType x, List l);
Position FindPrevious(ElementType x, const List l);
void Insert(ElementType x, List l, Position p);
void DeleteList(List l);
#endif

struct Node
{
    ElementType Element;
    Position Next;
};
struct Node CursorSpace[SpaceSize];
void InitializeCursorSpace()
{
        int i;
        for (i = 0; i < SpaceSize - 1; i++) {
                CursorSpace[i].Next = i + 1;
        }

        CursorSpace[SpaceSize - 1].Next = 0;
}

static Position CursorAlloc()
{
        Position P;
        P = CursorSpace[0].Next;
        CursorSpace[0].Next = CursorSpace[P].Next;
        return P;
}

static void CursorFree(Position P)
{
        CursorSpace[P].Next = CursorSpace[0].Next;
        CursorSpace[0].Next = P;
}

int IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}
void InitializeCursorSpace()
{
        int i;
        for (i = 0; i < SpaceSize - 1; i++) {
                CursorSpace[i].Next = i + 1;
        }

        CursorSpace[SpaceSize - 1].Next = 0;
}

static Position CursorAlloc()
{
        Position P;
        P = CursorSpace[0].Next;
        CursorSpace[0].Next = CursorSpace[P].Next;
        return P;
}

static void CursorFree(Position P)
{
        CursorSpace[P].Next = CursorSpace[0].Next;
        CursorSpace[0].Next = P;
}

int IsLast(Position P, List L)
{
    return CursorSpace[P].Next == 0;
}
Position Find(ElementType X, List L)
{
     Position P;
    P = CursorSpace[L].Next;
     while (P && CursorSpace[p].Element != X)
        P = CursorSpace[P].Next;
    return P;

}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);

    if (!IsLast(P, L)) {
    TmpCell = CursorSpace[P].Next;
    CursorSpace[P].Next = CursorSpace[TmpCell].Next;
    CursorFree(TmpCell);
    }
}
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = CursorAlloc();
    if (0 == TmpCell)
        FatalError("Out of space!")

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}