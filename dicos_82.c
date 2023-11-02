/*
Here is the demo code I am using to construct string from char arrays, Is there any better way to construct String *RV200# *FV200# ??


int main()
{    
char String4H1[10] = "*FV";
char String4H3[10] = "*RV";
char String4H2[10] = "#";

char data1[10];
char data2[10];

snprintf(data1,4, "%03d", 200); //Convert integer to string function
snprintf(data2,4, "%03d", 200); //Convert integer to string function

ConvertToString(String4H1,data1, 3);     //*FV200
ConvertToString(String4H3,data2, 3);     //*RV200

ConvertToString(String4H1,String4H2,6);   //*FV200#
ConvertToString(String4H3,String4H2,6);   //*RV200#

//Display String4H1 And String 4H3 
}

void ConvertToString(char subject[], const char insert[], int pos) 
{
char buf[100] = {};  
strncpy(buf, subject, pos);               // copy at most first pos characters
int len = strlen(buf);
strcpy(buf+len, insert);                 // copy all of insert[] at the end
len += strlen(insert);                  // increase the length by length of insert[]
strcpy(buf+len, subject+pos);          // copy the rest

strcpy(subject, buf);                 // copy it back to subject
                                 // deallocate buf[] here, if used malloc()
}


The number 200 is not known at the start of the program, it is fetched from memory using the IDE function to get value from particular memory address. like this :-


unsigned short BUF = GetWord(@FrontVIB@,0);    
unsigned short BUF1 = GetWord(@RearVIB@,0);

//BUF and BUF1 stores the value of address @FrontVIB@ and @RearVIB@ respectively

**structure** :-
unsigned short GetWord( @Address Alias@, Address Offset );

*/

#include <stdio.h>
#include <string.h>

void ConvertToString(char subject[], const char insert[], int pos) {
    char buf[100] = {};
    strncpy(buf, subject, pos); // copy at most first pos characters
    int len = strlen(buf);
    strcpy(buf + len, insert); // copy all of insert[] at the end
    len += strlen(insert); // increase the length by length of insert[]
    strcpy(buf + len, subject + pos); // copy the rest
    strcpy(subject, buf); // copy it back to subject
}

int main() {
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    char data1[10];
    char data2[10];

    snprintf(data1, 4, "%03d", 200); // Convert integer to string function
    snprintf(data2, 4, "%03d", 200); // Convert integer to string function

    ConvertToString(String4H1, data1, 3); // *FV200
    ConvertToString(String4H3, data2, 3); // *RV200

    ConvertToString(String4H1, String4H2, 6); // *FV200#
    ConvertToString(String4H3, String4H2, 6); // *RV200#

    // Display String4H1 and String4H3
    printf("%s\n", String4H1);
    printf("%s\n", String4H3);

    return 0;
}
