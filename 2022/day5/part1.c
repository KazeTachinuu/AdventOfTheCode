#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity);
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return '-';
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
void peek(struct Stack *stack)
{
    if (isEmpty(stack))
        printf("None");
    printf("%c", stack->array[stack->top]);
}

int main(void)
{
    FILE *f = fopen("input", "r");

    struct Stack *stack1 = createStack(50);
    struct Stack *stack2 = createStack(50);
    struct Stack *stack3 = createStack(50);
    struct Stack *stack4 = createStack(50);
    struct Stack *stack5 = createStack(50);
    struct Stack *stack6 = createStack(50);
    struct Stack *stack7 = createStack(50);
    struct Stack *stack8 = createStack(50);
    struct Stack *stack9 = createStack(50);

    printf("===== Pushing Stack 1 =====\n");

    push(stack1, 'D');
    push(stack1, 'H');
    push(stack1, 'N');
    push(stack1, 'Q');
    push(stack1, 'T');
    push(stack1, 'W');
    push(stack1, 'V');
    push(stack1, 'B');

    printf("===== Pushing Stack 2 =====\n");

    push(stack2, 'D');
    push(stack2, 'W');
    push(stack2, 'B');

    printf("===== Pushing Stack 3 ====\n=");

    push(stack3, 'T');
    push(stack3, 'S');
    push(stack3, 'Q');
    push(stack3, 'W');
    push(stack3, 'J');
    push(stack3, 'C');

    printf("===== Pushing Stack 4 =====\n");

    push(stack4, 'F');
    push(stack4, 'J');
    push(stack4, 'R');
    push(stack4, 'N');
    push(stack4, 'Z');
    push(stack4, 'T');
    push(stack4, 'P');

    printf("===== Pushing Stack 5 =====\n");

    push(stack5, 'G');
    push(stack5, 'P');
    push(stack5, 'V');
    push(stack5, 'J');
    push(stack5, 'M');
    push(stack5, 'S');
    push(stack5, 'T');

    printf("===== Pushing Stack 6 =====\n");

    push(stack6, 'B');
    push(stack6, 'W');
    push(stack6, 'F');
    push(stack6, 'T');
    push(stack6, 'N');

    printf("===== Pushing Stack 7 =====\n");

    push(stack7, 'B');
    push(stack7, 'L');
    push(stack7, 'D');
    push(stack7, 'Q');
    push(stack7, 'F');
    push(stack7, 'H');
    push(stack7, 'V');
    push(stack7, 'N');

    printf("===== Pushing Stack 8 =====\n");

    push(stack8, 'H');
    push(stack8, 'P');
    push(stack8, 'F');
    push(stack8, 'R');

    printf("===== Pushing Stack 9 =====\n");

    push(stack9, 'Z');
    push(stack9, 'S');
    push(stack9, 'M');
    push(stack9, 'B');
    push(stack9, 'L');
    push(stack9, 'N');
    push(stack9, 'P');
    push(stack9, 'H');

    char line[300];
    while (fgets(line, sizeof(line), f) != NULL)
    {
        int i = 0;
        while (line[i] != ' ')
        {
            i++;
        }

        i++;
        char nums[3];
        int j = 0;
        while (line[i] != ' ')
        {
            nums[j] = line[i];
            i++;
            j++;
        }
        nums[j] = '\0';
        int num = atoi(nums);
        i++;
        while (line[i] != ' ')
        {
            i++;
        }
        i++;
        int from = line[i] - 48;
        int to = line[i + 5] - 48;

        printf("move %d from %d to %d\n", num, from, to);
        while (num > 0)
        {
            int val;
            switch (from)
            {
            case 1:
                val = pop(stack1);
                break;
            case 2:
                val = pop(stack2);
                break;
            case 3:
                val = pop(stack3);
                break;
            case 4:
                val = pop(stack4);
                break;
            case 5:
                val = pop(stack5);
                break;
            case 6:
                val = pop(stack6);
                break;
            case 7:
                val = pop(stack7);
                break;
            case 8:
                val = pop(stack8);
                break;
            case 9:
                val = pop(stack9);
                break;
            }

            switch (to)
            {
            case 1:
                push(stack1, val);
                break;
            case 2:
                push(stack2, val);
                break;
            case 3:
                push(stack3, val);
                break;
            case 4:
                push(stack4, val);
                break;
            case 5:
                push(stack5, val);
                break;
            case 6:
                push(stack6, val);
                break;
            case 7:
                push(stack7, val);
                break;
            case 8:
                push(stack8, val);
                break;
            case 9:
                push(stack9, val);
                break;
            }
            num--;
        }
    }
    peek(stack1);
    peek(stack2);
    peek(stack3);
    peek(stack4);
    peek(stack5);
    peek(stack6);
    peek(stack7);
    peek(stack8);
    peek(stack9);
    fclose(f);
}
