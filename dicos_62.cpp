/*
All my program crashes because of delete [] meanings;, delete [] meanings;, delete [] temp_meaning; , when I remove these 3 lines it works fine, so probably I am using the delete wrongly ... can anybody enlighten me here please?

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {

    char *word_with_several_meanings; // like "bank", "class"
    char **meanings; // a pointer to a pointer stores all meanings
    int meanings_ctr; // meanings counter

    //-----------FUNCTIONS------------------------------------------------
public:
    void word(const char* = NULL );
    void add_meaning(char * = NULL);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0); // CTOR
    ~Expression(); // DTOR
};

Expression::Expression(int mctr ) {
    meanings_ctr = mctr;    // Setting the counter to 0
    meanings = new char * [meanings_ctr]; // Allocate Space for meanings
}

Expression::~Expression() {

    while(meanings_ctr-->0){
    delete meanings[meanings_ctr];
    }
    delete [] meanings; // Deleting the memory we allocated
    delete [] word_with_several_meanings; // Deleting the memory we allocated
}

void Expression::word(const char *p2c )
{

    word_with_several_meanings = new char[strlen(p2c)+1];
    // copy the string, DEEP copy
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning( char  * p2c)
{

    //meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    //strcpy(meanings[ meanings_ctr++ ] , p2c);
    // temp 
    if (meanings_ctr < 1){
    meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    strcpy(meanings[ meanings_ctr++ ] , p2c);
    }
    else {
int temp_ctr;
    char **temp_meaning;
    temp_meaning = new char * [meanings_ctr-1];
    for(temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
        temp_meaning[temp_ctr] = new char [strlen(meanings[ temp_ctr ]) + 1];
            strcpy(temp_meaning[temp_ctr], meanings[ temp_ctr ]);
    }
    for (temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
            delete meanings[temp_ctr];

    }
    delete [] meanings;

    meanings = new char * [meanings_ctr];
    for(temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
        meanings[ temp_ctr ] = new char [strlen(temp_meaning[temp_ctr]) + 1];
            strcpy(meanings[ temp_ctr ], temp_meaning[temp_ctr]);
    }
    meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    strcpy(meanings[ meanings_ctr ] , p2c);
            for (temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
            delete temp_meaning[temp_ctr];
    }
    delete [] temp_meaning;
            meanings_ctr++;
    }


}

char * Expression::get_meaning( int meanx )
{

    return *(meanings+meanx);

}

char * Expression::get_word()
{

    return word_with_several_meanings;

}

int Expression::get_total_number_of_meanings()
{
    return meanings_ctr;
}


int main(void) {
    int i;
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("b place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");
    cout << expr.get_word() << endl;

    for(int i = 0; i<expr.get_total_number_of_meanings(); i++)
            cout << " " << expr.get_meaning(i)  << endl;
    Expression expr2;
    expr2.word("class");
    expr2.add_meaning("a school class");
    expr2.add_meaning("a classification for a hotel");
    expr2.add_meaning("Starts with C");
    cout << expr2.get_word() << endl;
    for( i = 0; i<expr2.get_total_number_of_meanings(); i++)
            cout << " " << expr2.get_meaning(i) << endl;

    Expression expr3;
    expr3.word("A very long test");
    char str[] = "Meaning_    ";
    for(int kx =0; kx<31; kx++){
            str[8] = ('A'+kx);
            expr3.add_meaning(str);
    }

    cout << expr3.get_word() << endl;
    for( int i = 0; i<expr3.get_total_number_of_meanings(); i++)
            cout << " " << expr3.get_meaning(i) << endl;
    return 0;
}
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {

    char *word_with_several_meanings; // like "bank", "class"
    char **meanings; // a pointer to a pointer stores all meanings
    int meanings_ctr; // meanings counter

    //-----------FUNCTIONS------------------------------------------------
public:
    void word(const char* = NULL );
    void add_meaning(char * = NULL);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0); // CTOR
    ~Expression(); // DTOR
};

Expression::Expression(int mctr ) {
    meanings_ctr = mctr;    // Setting the counter to 0
    meanings = new char * [meanings_ctr]; // Allocate Space for meanings
}

Expression::~Expression() {

    while(meanings_ctr-->0){
    delete meanings[meanings_ctr];
    }
    delete [] meanings; // Deleting the memory we allocated
    delete [] word_with_several_meanings; // Deleting the memory we allocated
}

void Expression::word(const char *p2c )
{

    word_with_several_meanings = new char[strlen(p2c)+1];
    // copy the string, DEEP copy
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning( char  * p2c)
{

    //meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    //strcpy(meanings[ meanings_ctr++ ] , p2c);
    // temp 
    if (meanings_ctr < 1){
    meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    strcpy(meanings[ meanings_ctr++ ] , p2c);
    }
    else {
int temp_ctr;
    char **temp_meaning;
    temp_meaning = new char * [meanings_ctr-1];
    for(temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
        temp_meaning[temp_ctr] = new char [strlen(meanings[ temp_ctr ]) + 1];
            strcpy(temp_meaning[temp_ctr], meanings[ temp_ctr ]);
    }
    for (temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
            delete meanings[temp_ctr];

    }
    delete [] meanings;

    meanings = new char * [meanings_ctr];
    for(temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
        meanings[ temp_ctr ] = new char [strlen(temp_meaning[temp_ctr]) + 1];
            strcpy(meanings[ temp_ctr ], temp_meaning[temp_ctr]);
    }
    meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    strcpy(meanings[ meanings_ctr ] , p2c);
            for (temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
            delete temp_meaning[temp_ctr];
    }
    delete [] temp_meaning;
            meanings_ctr++;
    }


}

char * Expression::get_meaning( int meanx )
{

    return *(meanings+meanx);

}

char * Expression::get_word()
{

    return word_with_several_meanings;

}

int Expression::get_total_number_of_meanings()
{
    return meanings_ctr;
}


int main(void) {
    int i;
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("b place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");
    cout << expr.get_word() << endl;

    for(int i = 0; i<expr.get_total_number_of_meanings(); i++)
            cout << " " << expr.get_meaning(i)  << endl;
    Expression expr2;
    expr2.word("class");
    expr2.add_meaning("a school class");
    expr2.add_meaning("a classification for a hotel");
    expr2.add_meaning("Starts with C");
    cout << expr2.get_word() << endl;
    for( i = 0; i<expr2.get_total_number_of_meanings(); i++)
            cout << " " << expr2.get_meaning(i) << endl;

    Expression expr3;
    expr3.word("A very long test");
    char str[] = "Meaning_    ";
    for(int kx =0; kx<31; kx++){
            str[8] = ('A'+kx);
            expr3.add_meaning(str);
    }

    cout << expr3.get_word() << endl;
    for( int i = 0; i<expr3.get_total_number_of_meanings(); i++)
            cout << " " << expr3.get_meaning(i) << endl;
    return 0;
}

/*
- Request:
Please fix the below C++ program.

- Code to fix:
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {

    char *word_with_several_meanings; // like "bank", "class"
    char **meanings; // a pointer to a pointer stores all meanings
    int meanings_ctr; // meanings counter

    //-----------FUNCTIONS------------------------------------------------
public:
    void word(const char* = NULL );
    void add_meaning(char * = NULL);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0); // CTOR
    ~Expression(); // DTOR
};

Expression::Expression(int mctr ) {
    meanings_ctr = mctr;    // Setting the counter to 0
    meanings = new char * [meanings_ctr]; // Allocate Space for meanings
}

Expression::~Expression() {

    while(meanings_ctr-->0){
    delete meanings[meanings_ctr];
    }
    delete [] meanings; // Deleting the memory we allocated
    delete [] word_with_several_meanings; // Deleting the memory we allocated
}

void Expression::word(const char *p2c )
{

    word_with_several_meanings = new char[strlen(p2c)+1];
    // copy the string, DEEP copy
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning( char  * p2c)
{

    //meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    //strcpy(meanings[ meanings_ctr++ ] , p2c);
    // temp 
    if (meanings_ctr < 1){
    meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    strcpy(meanings[ meanings_ctr++ ] , p2c);
    }
    else {
int temp_ctr;
    char **temp_meaning;
    temp_meaning = new char * [meanings_ctr-1];
    for(temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
        temp_meaning[temp_ctr] = new char [strlen(meanings[ temp_ctr ]) + 1];
            strcpy(temp_meaning[temp_ctr], meanings[ temp_ctr ]);
    }
    for (temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
            delete meanings[temp_ctr];

    }
    delete [] meanings;

    meanings = new char * [meanings_ctr];
    for(temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
        meanings[ temp_ctr ] = new char [strlen(temp_meaning[temp_ctr]) + 1];
            strcpy(meanings[ temp_ctr ], temp_meaning[temp_ctr]);
    }
    meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
    strcpy(meanings[ meanings_ctr ] , p2c);
            for (temp_ctr =0; temp_ctr<meanings_ctr;temp_ctr++){
            delete temp_meaning[temp_ctr];
    }
    delete [] temp_meaning;
            meanings_ctr++;
    }
}

char * Expression::get_meaning( int meanx )
{
    return *(meanings+meanx);
}

char * Expression::get_word()
{
    return word_with_several_meanings;
}

int Expression::get_total_number_of_meanings()
{
    return meanings_ctr;
}

int main(void) {
    int i;
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("b place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");
    cout << expr.get_word() << endl;

    for(int i = 0; i<expr.get_total_number_of_meanings(); i++)
            cout << " " << expr.get_meaning(i)  << endl;
    Expression expr2;
    expr2.word("class");
    expr2.add_meaning("a school class");
    expr2.add_meaning("a classification for a hotel");
    expr2.add_meaning("Starts with C");
    cout << expr2.get_word() << endl;
    for( i = 0; i<expr2.get_total_number_of_meanings(); i++)
            cout << " " << expr2.get_meaning(i) << endl;

    Expression expr3;
    expr3.word("A very long test");
    char str[] = "Meaning_    ";
    for(int kx =0; kx<31; kx++){
            str[8] = ('A'+kx);
            expr3.add_meaning(str);
    }

    cout << expr3.get_word() << endl;
    for( int i = 0; i<expr3.get_total_number_of_meanings(); i++)
            cout << " " << expr3.get_meaning(i) << endl;
    return 0;
}

- Error:
All my program crashes because of delete [] meanings;, delete [] meanings;, delete [] temp_meaning; , when I remove these 3 lines it works fine, so probably I am using the delete wrongly.

- Security precautions: Please watch out for the following vulnerabilities.
Buffer Copy without Checking Size of Input ('Classic Buffer Overflow'): The product copies an input buffer to an output buffer without verifying that the size of the input buffer is less than the size of the output buffer, leading to a buffer overflow.

*/
