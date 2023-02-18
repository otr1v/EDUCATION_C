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


// информация касательно операций # и ##, одиночная используется для того, чтобы объединить два символа в строку, то есть, к примеру 
//#define PRINT_XN(n) printf ( "х" #n " = %d\n", х ## n), то есть PRINT_XN(1) раскроется в printf("x1 = %d\n", x1), ## - используется для объединения
//двух лексем, то есть когда нужно создать новое имя переменной, например


// #define PR (...) printf(__VA_ARGS__), идея в том, что когда переменное число аргументов, то вместо троеточия подставляется в ва_аргс.
// после троеточия нельзя ставить еще один аргумент!


// #ifdef
//      #include <stdio.h>
// #else 
//      #include <string.h>     
//#endif      - если выполнено одно - выполняем, если нет, выполняем другое


// fscanf и sscanf, отличие, что sscanf читает из строки до первого /0, а fscanf из файла, первый аргумент 
// rewind возвращает указатель на начало файла, если, например rewind(fp) написать
// feof(fp) смотрит, не достигнут ли конец файла, если достигнут то возвращает EOF до тех пор, пока не будет вызвана rewind or fseek


//  const float* pf - значение переменной флоат постоянное, ее нельзя изменить, а указатель pf - можно менять 
//  float * const pt; - pt - указатель const*, то есть значение указателя не может быть модифицировано, то есть он будет всегда
//  ссылаться на один и тот же адрес, а значение переменной может быть модифицировано
//  const float * const ptr, и переменная на которую ссылаются и указатель постоянные
//  float const * pfc == const float * pfc
//  то есть если слева конст от *, то делаются конст данные, а если конст справа от *, то указатель будет постоянным

 
//fseek fseek(file, position connected to the third arg, 3rd)  and ftell(file)
//  3rd can be:
//  SEEK_SET - from the beggining of the file
//  SEEK_CUR - from the current place in the file
//  SEEK_END - from the end of the file
//  fseek ret value is 0 if all is ok, -1 - if not all is ok
//  2nd arg is (long)arg, 1L - 1 byte after our position, 10L - 10 bytes and etc, also can be < 0
//  ftell(fp) tells us where we are now in long type

