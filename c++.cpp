метод - функция, которая находится внутри класса
инициализация вектора
доступ к классу через двоеточие
явное объявление функции


 int a {10};
    int *pa {&a};
    std::cout << "pa: address=" << pa << "\tvalue=" << *pa << std::endl;
    int b {(*pa)++};      // инкремент значения по адресу указателя
      makes ub when you write like this : *pa++(разыменование после прибавления)     

    ///
 
    const int a {10};
    const int *pa {&a}; тут нельзя изменить переменную а ни через указатель, ни через саму переменную

   ///
int a {10};
    const int *pa {&a}; // а тут уже можно изменить переменную а, но через указатель по-прежнему нельзя ее менять 

   ///

const int a {10};
const int *pa {&a};     // указатель указывает на константу a
const int b {45};
pa = &b;  тут можно поменять на что указывает указатель pa, но нельзя поменять переменную на которую он указывает

  ///

  nt *const pa {&a}; - тут можно изменить значение переменной а через указатель, но нельзя изменить адрес переменной а

///
  
  int nums[] {1, 2, 3, 4, 5};
nums++;         // так сделать нельзя
int b {8};
nums = &b;          // так тоже сделать нельзя

///

при указателе char* ао будет выводиться строка ао, если же нкжно вывести указатель на начало массива, то его нужно привести к типу void*

        ///
char langs[][20] { "C++", "Python", "JavaScript"}; при таком объявлении у нас каждая строка будет занимать до 20 байт, в то время как С++
имеет всего 4 символа (включая нулевой в конце), так что определять лучше так, чтобы не аллоцировать лишнее место char* langs[]

  ///

  при вызове функции можно указать аргументы по умолчанию, если не будет принято это значение, то значение по умолчанию будет равно ранее указанному
///
  
void increment(int *x) тут если изменять сам х, то будет это видно в мейне, а если изменить указатель, то он в мейне останется тем же
То есть передается копия указателя(ссылка на указатель будет другой, но объект тот же)
ссылка не может ссылаться на ничего, обязательно должен быть объект, на который она ссылается, в то же время - указатель может иметь значение nullptr
так что указатель надо обязательно проверять, не ноль ли он

/// 
void print(int (*numbers)[3]);   - двумерный массив
  void print(int *numbers[3])   - массив указателей, причем обязательно при передаче либо первого, либо второго - второй параметр размера должен быть определен

  ///

  перегрузка - одинаковое название функций, но разное количество параметров или разный тип
  при перегрузке функций передача константного параметра отличается только по ссылке или указателю

////

int main()
{
    void (*message)();  // определение указателя на функцию   != void* message(не указатель на функцию, а прототип функции, которая возвращает void*)
      
    message=hello;
    message();
    message = goodbye;
    message();
}

int operation(int(*op)(int, int), int a, int b), можно сделать так: operation(add, a, b), где add - функция, складывающая два числа
callback function - function add, which called from function operation, при этом не нужно указывать аргументы функции, когда функция callback передается в параметрах
оператор  auto может заменить длинное название функции

using BinaryOp = int (*)(int, int);
int sum(int, int);
int subtract(int, int);
void do_operation(int, int, BinaryOp); BinaryOp - указатель на функцию , которая вернет int, и принимает аргументы в виде двух интов
 
//
void(*message(unsigned hour))()
{
    if (hour > 15)
        return goodevening;    //goodevening - function, returns void
    else                        // message - name of func
        return goodmorning;
}

////

std::string message {"Hello"};
extern std::string message; extern - key word to include in file with constans, you should compile two files together

////
dynamic objects :

dynamic memory int* ptr = new int(); - value of *ptr is 0 int* ptr = new int(5);
dangling pointer -  висящий указатель, которыйй даже после операции delete имеет функцию обращения к нему
 обнулять указетель после операции delete!!
аналогично, вроде, и в языке С

///
 dynamic arrays:
int *numbers1 {new int[4]{}}; - each element of numbers1 equals 1;
int *numbers2 {new int[4]{ 1, 2, 3, 4 }};
C++ 20 подразумевает, что можно не писать количество элементов при инициализации массива, он сам все поймет!
 delete [] p; - how to make free array p -> after it p = nullptr
int (*a)[2] = new int[n][2]; - фиксированно количество столбцов

 как объявить память под двумерный массив: 
 int** numbers{new int*[rows]{}}; 
    for (unsigned i{}; i < rows; i++)
    {
        numbers[i] = new int[columns]{};
    }
///

smart pointers:   (#include <memory>)
unique_ptr - it cant be two different ptrs, those are pointers for the same object, and no need for delete and dangling pointer
default value for unique ptr is nullptr
 if ptr is unique ptr -> and we need to get simple pointer from ptr we should use ptr.get()
 after standard c++20 we can use just ptr to print the value of ptr
initialization is like std::unique_ptr<int> ptr { std::make_unique<int>(125) }; - using func make after c++14 standard
 if we need to use unique ptr for arrays:
unsigned n{5};   // размер массива
auto pnumbers { std::make_unique<int[]>(n) }; all elems equals to zero

ptr.reset(new int{254}); // сразу же выделяем память под новый объект, освобождая память под старый

shared_ptr:
default value is nullptr, counting references, those are pointers for the same objects
std::shared_ptr<int> ptr {std::make_shared<int>(22)};  IT MEANS THAT *ptr == 22
 shared ptr can be pointer to array since C++20


////

 OOP:
classes: 
i can use this construction to define different classes:   // it names delegation of constructor
    Person(std::string p_name, unsigned p_age)
    {
        name = p_name;
        age = p_age;
        std::cout << "First constructor" << std::endl;
    }
    Person(std::string p_name): Person(p_name, 18) // вызов первого конструктора
    {
        std::cout << "Second constructor" << std::endl;
    }
    Person(): Person(std::string("Undefined")) // вызов второго конструктора
    { 
        std::cout << "Third constructor" << std::endl;
    }

списки инициализации для констант!

 
class Person 
{
    const std::string name;
    unsigned age{};
public:
    void print() 
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
    Person(std::string p_name, unsigned p_age) : name{p_name}    // or like this : name (p_name), compulsory to use it with constants
    {                                                            // but can be used for simple variables
        age = p_age;                                             //  order make sense!!!
    }
};
int main()
{
    Person tom{"Tom", 38};
    tom.print();    // Name: Tom    Age: 38
}
