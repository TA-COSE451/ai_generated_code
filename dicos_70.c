/*
I'm trying to build python-kerberos on AIX. kerberospw.c uses a call to asprintf, but from what Google is telling me, asprintf does not exist on AIX.
I saw http://www.koders.com/c/fidAA9B130D588302673A28B568430A83131B7734C0.aspx?s=windows.h, which looks like I could create a stand-in asprintf, but I don't know where this would go or how I would #include it in kerberospw.c.
Is there a way I can use the koders.com example or some other code to "fake" asprintf? Can I just include the asprintf function as shown in kerberospw.c? I am not a C coder, but

asprintf (char **resultp, const char *format, ...)

doesn't look like a valid signature to me with the dots at the end. The relevant line from kerberospw.c is below

asprintf(&message, "%.*s: %.*s", (int) result_code_string.length,
(char *) result_code_string.data,
(int) result_string.length,
(char *) result_string.data);

I realize I could contact the author of python-kerberos, but a) I think it would be helpful to have a potential patch if I did so, and b) there might be other software I run across that uses asprintf, and it would be nice to have a workaround.
*/

#include <stdio.h>
#include <stdarg.h>

int custom_asprintf(char **resultp, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Determine the size needed for the string
    int size = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (size < 0) {
        return -1;  // Error
    }

    // Allocate memory for the string
    *resultp = (char *)malloc(size + 1);
    if (*resultp == NULL) {
        return -1;  // Error
    }

    // Format the string
    va_start(args, format);
    int ret = vsnprintf(*resultp, size + 1, format, args);
    va_end(args);

    return ret;
}
