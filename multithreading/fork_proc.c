#include <unistd.h>
#include <stdio.h>


// The fork function is defined in unistd.h with the following prototype:
//      pid_t fork(void);
//
// The getpid function is defined in unistd.h with the following prototype:
//      pid_t getpid(void);
//
// where, pid_t, is a posix data type associated with an integer variable
// and it is defined in the header sys/types.h
//
// We can also get the id of the parent of a certain process using the function
// getppid() which is also defined in unistd.h

int main()
{
    fork();
    printf("Hello\n");

    return 0;
}

