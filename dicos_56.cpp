/*
I am trying to understand why the compiler detects a "Bad Memory error" To my understanding (Pointer->next != null) should get me to the end of the tail, but why when it gets to the last node, it detects an error.

void Append(Data* head, char* name, char* lastname) { 
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    // Iretator
    Data* prt = head;
    if ((*name != '\0') && (*lastname != '\0')) {
        // find the last node in the list:
        //Special Case
        if (*head->name == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while ((int*)prt->next != NULL) {
                prt = prt->next;
            }
            prt = _newNode;
        }
    }
}
*/

void Append(Data* head, char* name, char* lastname) { 
    Data* _newNode = (Data*)malloc(sizeof(Data));
    if (_newNode == NULL) {
        // Handle memory allocation failure
        // (e.g., display an error message, free any previously allocated memory)
    }
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    // Iretator
    Data* prt = head;
    if ((*name != '\0') && (*lastname != '\0')) {
        // find the last node in the list:
        //Special Case
        if (*head->name == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while (prt->next != NULL) {
              prt = prt->next;
          }
          prt->next = _newNode;
        }
    }
}

/*
- Request:
Please fix the below C++ program.

- Code to fix:
void Append(Data* head, char* name, char* lastname) { 
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    // Iretator
    Data* prt = head;
    if ((*name != '\0') && (*lastname != '\0')) {
        // find the last node in the list:
        //Special Case
        if (*head->name == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while ((int*)prt->next != NULL) {
                prt = prt->next;
            }
            prt = _newNode;
        }
    }
}

- Error:
I am trying to understand why the compiler detects a "Bad Memory error" To my understanding (Pointer->next != null) should get me to the end of the tail, but why when it gets to the last node, it detects an error.

- Security precautions: Please watch out for the following vulnerabilities.
Missing Release of Memory after Effective Lifetime: The product does not sufficiently track and release allocated memory after it has been used, which slowly consumes remaining memory.

*/
