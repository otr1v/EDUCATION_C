//here i will add information about C language(my education)

//firstly, about memset func : memset func converts integer to unsigned char, so it can be used to fill
// only with 0 or -1 by integers and any symbol of char 
//in this function it is compulsory to fill lust argument multiplying by sizeof(elem)

// fprintf(FILE* fp, "text like in printf", numbers if there are any identificators (%))

// some info about strings, it is better to work with args of str, not with return value, because c doesnt like temporary strings
// and when arg of func is string you are already work with adress, so convinient

//structers:
typedef struct node {
  struct node* left;
}Node;                    // here node is needed only for structure element, if there is no need to add some args of structure using this type of structure
        // you should use this
typedef struct  {
  int left;
}Node;    
