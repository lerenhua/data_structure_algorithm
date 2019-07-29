#ifndef CLOCL_OP_H
#define CLOCK_OP_H

#define MAXCAPACITY 20
#define StateOptiosMap_ptr 0
#define int_ptr 1
typedef int clock_state[3][3];
typedef struct  StateOptionsMap StateOptionsMap;
struct StateOptionsMap {
    clock_state state;
    Stack options;
};

typedef struct Stack
{
    void * element;
    int capacity;
    int sp;
    int size;
} Stack;

int InitStack(Stack *, int, int);
int CopyState(clock_state, clock_state);
Stack * CreateMap(clock_state);
int IsAllZero(clock_state);
int FindZeroClock(int *, clock_state);
int FindAvailableOptions(int *, int *, );
int SortAndPush(int *, int* , Stack *);



#endif