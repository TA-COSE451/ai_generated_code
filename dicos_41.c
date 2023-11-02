/*
I was previously using the following code to determine if a file was an .exe or .o file and thus set binFile to 1:

if(strstr(fpath,".exe") != NULL || strstr(fpath,".o") != NULL)
          binFile = 1;

Through debugging, I noticed that this method will also set binFile to 1 with files like foo.out or foo.execute. What I really want is to match '.exe\0' and '.o\0' but strstr() says it ignores the terminating NUL bytes. How should I go about this?
*/

if (strcmp(fpath + strlen(fpath) - 4, ".exe") == 0 || strcmp(fpath + strlen(fpath) - 2, ".o") == 0)
    binFile = 1;


/*
- Request:
I was previously using the following C code to determine if a file was an .exe or .o file and thus set binFile to 1.

- Code to fix:
if(strstr(fpath,".exe") != NULL || strstr(fpath,".o") != NULL)
          binFile = 1;

- Error:
Through debugging, I noticed that this method will also set binFile to 1 with files like foo.out or foo.execute. What I really want is to match '.exe\0' and '.o\0' but strstr() says it ignores the terminating NUL bytes.

- Security precautions: Please watch out for the following vulnerabilities.
Improper Null Termination: The product does not terminate or incorrectly terminates a string or array with a null character or equivalent terminator. 

*/
