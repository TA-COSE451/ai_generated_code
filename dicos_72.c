/*
I'm working in C, and I have to concatenate a few things.
Right now I have this:

message = strcat("TEXT ", var);

message2 = strcat(strcat("TEXT ", foo), strcat(" TEXT ", bar));


Now if you have experience in C I'm sure you realize that this gives you a segmentation fault when you try to run it. So how do I work around that?
*/

char message[100];  // Assuming a maximum length for the concatenated string

strcpy(message, "TEXT ");
strcat(message, var);

char message2[100];  // Assuming a maximum length for the concatenated string

strcpy(message2, "TEXT ");
strcat(message2, foo);
strcat(message2, " TEXT ");
strcat(message2, bar);
