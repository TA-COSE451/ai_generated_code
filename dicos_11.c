/*
I'm filling an array of struct within a code and inside it another array of the struct but I get stuck in the loop. I tested every branch and loop: it works. But the loop doesn't work.

In service_data _func I try to analyze text and add it to the struct.

I call it in the main function and pass text to it and try to print a value stored I use the print command in each step in the loop it works but getting out of it it doesn't work.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5];
};
struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[5];
    struct service_charge charge_arr[10];
};
struct service serv_data[8];
char text[1000]="{\"success\": true,\"language\": \"en\",\"action\":
                \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":
                [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC
                AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\":
                10000,\"sort_order\": 2,\"inquiry_required\":
                true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\":
                1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\":
                54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},,
                {\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\":
                5,\"percentage\": true2}]}";

void service_data_func (char text[]) {

    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[19]= {0x20};
    char name1[19]= {0x20};
    int menunum=0;
    int len;
    len=strlen(text);
    int menunum_charge=0;

    while (1)//while ALL
    {
        if(i>=len) {
            break;
        }
        if(text[i] == '"' && text[i+1] == 'i'&&
                text[i+2] == 'd') {
            while (1) { //while "id
                if(text[i] == ':') {
                    Wstart=i+1;
                    Wend=0;
                    i++;
                } else if(text[i] == ',' || text[i] == '}' ) {
                    Wend=i;
                    strncpy(name,text+Wstart,Wend-Wstart);
                    serv_data[menunum].id=atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                } else {
                    i=i+1;
                }
            }//while id
        } else if(text[i] == 's' && text[i+1] == 'e'&&
                  text[i+2] == 'r'&& text[i+3] == 'v'&& text[i+4] == 'i'&&
                  text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& text[i+8]
                  == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] ==
                  'r'&& text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&&
                  text[i+15] == 'l'&& text[i+16] == 'i'&& text[i+17] == 's'&&
                  text[i+18] == 't') {
            while (1)//while ALL
            {
                if(i>=len) {
                    break;
                }
                if(text[i] == 'f' && text[i+1] == 'r'&&
                        text[i+2] == 'o'&& text[i+3] == 'm') {
                    while (1) { //while from
                        if(text[i] == ':') {
                            Wstart=i+1;
                            Wend=0;
                            i++;
                        } else if(text[i] == ',' || text[i] == '}' ) {
                            Wend=i;
                            strncpy(name,text+Wstart,Wend-Wstart);
                            serv_data[menunum].charge_arr[menunum_charge].from=atoi(name);
                            memset(name, 0, sizeof(name));
                            i++;
                            break;
                        } else {
                            i=i+1;
                        }
                    }
                } else {
                    i++;
                }
            }
        } else {
            i++;
        }
    }
}

int main()
{
    service_data_func(text);
    printf("%d\n",serv_data[0].charge_arr[0].from);
    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5];
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[5];
    struct service_charge charge_arr[10];
};

struct service serv_data[1];
char text[1000] = "{\"success\": true, \"language\": \"en\", \"action\": \"GetServiceList\", \"version\": 1, \"data\": {\"service_list\": [{\"id\": 4806, \"provider_id\": 581, \"name\": \"Bill Payment (MG SC AC)\", \"price_type\": 0, \"min_value\": 30, \"max_value\": 10000, \"sort_order\": 2, \"inquiry_required\": 1, \"service_charge_list\": [{\"from\": 1, \"to\": 547, \"charge\": 1, \"slap\": 1, \"percentage\": 1}, {\"from\": 2, \"to\": 54875, \"charge\": 4, \"slap\": 5, \"percentage\": 1}, {\"from\": 2, \"to\": 68945, \"charge\": 4, \"slap\": 5, \"percentage\": 2}]}}}";

void service_data_func(char text[]) {
    int i = 0;
    int Wstart = 0;
    int Wend = 0;
    char name[19] = {0x20};
    int len = strlen(text);
    int menunum = 0;
    int menunum_charge = 0;

    while (1) //while ALL
    {
        if (i >= len) {
            break;
        }
        if (text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            while (1) { //while "id
                if (text[i] == ':') {
                    Wstart = i + 1;
                    Wend = 0;
                    i++;
                } else if (text[i] == ',' || text[i] == '}') {
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum].id = atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                } else {
                    i++;
                }
            } //while id
        } else if (strncmp(text + i, "service_charge_list", strlen("service_charge_list")) == 0) {
            i += strlen("service_charge_list") + 1;
            while (1) //while ALL
            {
                if (i >= len || text[i] == ']') {
                    break;
                }
                if (text[i] == '{' && text[i + 1] == '"') {
                    menunum_charge++;
                    i += 2;
                } else if (text[i] == 'f' && text[i + 1] == 'r' && text[i + 2] == 'o' && text[i + 3] == 'm') {
                    while (1) { //while from
                        if (text[i] == ':') {
                            Wstart = i + 1;
                            Wend = 0;
                            i++;
                        } else if (text[i] == ',' || text[i] == '}') {
                            Wend = i;
                            strncpy(name, text + Wstart, Wend - Wstart);
                            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
                            memset(name, 0, sizeof(name));
                            i++;
                            break;
                        } else {
                            i++;
                        }
                    }
                } else {
                    i++;
                }
            }
        } else {
            i++;
        }
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    return 0;
}

/*
- Request:
Please fix the below C program.
In service_data _func I try to analyze text and add it to the struct.
I call it in the main function and pass text to it and try to print a value stored.

- Code to fix:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5];
};
struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[5];
    struct service_charge charge_arr[10];
};
struct service serv_data[8];
char text[1000]="{\"success\": true,\"language\": \"en\",\"action\":
                \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":
                [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC
                AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\":
                10000,\"sort_order\": 2,\"inquiry_required\":
                true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\":
                1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\":
                54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},,
                {\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\":
                5,\"percentage\": true2}]}";

void service_data_func (char text[]) {

    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[19]= {0x20};
    char name1[19]= {0x20};
    int menunum=0;
    int len;
    len=strlen(text);
    int menunum_charge=0;

    while (1)//while ALL
    {
        if(i>=len) {
            break;
        }
        if(text[i] == '"' && text[i+1] == 'i'&&
                text[i+2] == 'd') {
            while (1) { //while "id

                if(text[i] == ':') {
                    Wstart=i+1;
                    Wend=0;
                    i++;
                } else if(text[i] == ',' || text[i] == '}' ) {

                    Wend=i;

                    strncpy(name,text+Wstart,Wend-Wstart);
                    serv_data[menunum].id=atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                } else {
                    i=i+1;
                }

            }//while id
        } else if(text[i] == 's' && text[i+1] == 'e'&&
                  text[i+2] == 'r'&& text[i+3] == 'v'&& text[i+4] == 'i'&&
                  text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& text[i+8]
                  == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] ==
                  'r'&& text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&&
                  text[i+15] == 'l'&& text[i+16] == 'i'&& text[i+17] == 's'&&
                  text[i+18] == 't') {
            while (1)//while ALL
            {
                if(i>=len) {
                    break;
                }
                if(text[i] == 'f' && text[i+1] == 'r'&&
                        text[i+2] == 'o'&& text[i+3] == 'm') {
                    while (1) { //while from

                        if(text[i] == ':') {
                            Wstart=i+1;
                            Wend=0;
                            i++;
                        } else if(text[i] == ',' || text[i] == '}' ) {

                            Wend=i;

                            strncpy(name,text+Wstart,Wend-Wstart);

                            serv_data[menunum].charge_arr[menunum_charge].from=atoi(name);
                            memset(name, 0, sizeof(name));
                            i++;
                            break;
                        } else {
                            i=i+1;
                        }

                    }
                } else {
                    i++;
                }

            }
        } else {
            i++;
        }

    }

}

int main()
{
    service_data_func(text);
    printf("%d\n",serv_data[0].charge_arr[0].from);


    return 0;
}

- Error:
I use the print command in each step in the loop it works but getting out of it it doesn't work.

- Security precautions: Please watch out for the following vulnerabilities.
Loop with Unreachable Exit Condition ('Infinite Loop'): The product contains an iteration or loop with an exit condition that cannot be reached, i.e., an infinite loop.

*/