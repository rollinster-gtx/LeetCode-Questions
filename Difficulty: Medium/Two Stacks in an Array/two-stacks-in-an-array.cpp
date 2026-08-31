class twoStacks {
    int arr[100];
    int size = 100;
    int top1, top2;

  public:
    twoStacks() {
        // Initialize the top pointers of both stacks
    top1=-1;
    top2=size;
    }

    void push1(int x) {
        // Insert the given element at the top of the first stack
        if(top1+1==top2)
        return;
        top1++;
        arr[top1]=x;
    }

    void push2(int x) {
        // Insert the given element at the top of the second stack
        if(top2-1==top1)
        return;
        top2--;
        arr[top2]=x;
    }

    int pop1() {
        // Remove and return the top element of the first stack
        // Return -1 if the stack is empty
        if(top1==-1)
        return -1;
        int element=arr[top1];
        top1--;
        return element;
    }

    int pop2() {
        // Remove and return the top element of the second stack
        // Return -1 if the stack is emptyif(top1==-1)
        if (top2==size)
        return -1;
        int element=arr[top2];
        top2++;
        return element;
    }
};