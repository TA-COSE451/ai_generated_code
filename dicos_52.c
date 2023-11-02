/*
This has been pending for a long time in my list now. In brief - I need to run mocked_dummy() in the place of dummy() ON RUN-TIME, without modifying factorial(). I do not care on the entry point of the software. I can add up any number of additional functions (but cannot modify code within "// ---- do not modify ---- //").

Why do I need this?
To do unit tests of some legacy C modules. I know there are a lot of tools available around, but if run-time mocking is possible I can change my UT approach (add reusable components) make my life easier :).

Platform / Environment?
Linux, ARM, gcc.

Approach that I'm trying with?

I know GDB uses trap/illegal instructions for adding up breakpoints (gdb internals).
Make the code self modifiable.
Replace dummy() code segment with illegal instruction, and return as immediate next instruction.
Control transfers to trap handler.
Trap handler is a reusable function that reads from a unix domain socket.
Address of mocked_dummy() function is passed (read from map file).
Mock function executes.
There are problems going ahead from here. I also found the approach is tedious and requires good amount of coding, some in assembly too.

I also found, under gcc each function call can be hooked / instrumented, but again not very useful since the the function is intended to be mocked will anyway get executed.

Is there any other approach that I could use?


#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n",__func__);
}

// ---- do not modify ---- //
void dummy(void)
{
    printf("__%s__()\n",__func__);
}

int factorial(int num) 
{
    int                      fact = 1;
    printf("__%s__()\n",__func__);
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    dummy();
    return fact;
}
// ---- do not modify ---- //

int main(int argc, char * argv[])
{
    int (*fp)(int) = atoi(argv[1]);
    printf("fp = %x\n",fp);
    printf("factorial of 5 is = %d\n",fp(5));
    printf("factorial of 5 is = %d\n",factorial(5));
    return 1;
}
*/

void (*dummy_ptr)(void) = dummy;

dummy_ptr = mocked_dummy;

int factorial(int num) 
{
    int fact = 1;
    printf("__%s__()\n", __func__);
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    dummy_ptr(); // Call the function through the function pointer
    return fact;
}

int main(int argc, char* argv[])
{
    // Initialize with dummy function
    void (*fp)(void) = dummy_ptr;

    // Check command line arguments and switch to mocked_dummy if needed
    if (argc > 1 && atoi(argv[1]) == 1) {
        fp = mocked_dummy;
    }

    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
