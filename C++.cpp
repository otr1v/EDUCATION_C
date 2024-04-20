

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

конструктор может быть спокойно вынесен за пределы класса, таким образом:
class Person{

};
Person::Person(std::string p_name, unsigned p_age){...}


COPY CONSTRUCTOR 
                              конструктор копирования это конструктор для нового объекта, определяемый через старый
существует такая вещь, как конструктор копирования, которая может быть вызвана по умолчанию
Но в таком случае, если там будет указатель, то скопируется указатель на тот же объект 
Можно строить свой конструктор копирования, где так не будет
Person(const Person &p)
    {
        name = p.name;
        age = p.age + 1;    
    }
также конструктор копирования можно удалить, даже тот который по умолчанию, можно это сделать так:
Person(const Person &p) = delete;

////
CONST OBJECTS OF CLASSES
константные объекты класса:
объекты класса могут быть константными: const Person tom{"Tom", 38}; - нельзя менять его поля
для константых объектов нельзя вызывать любые функции, кроме константных, т.е. таких: void print() const {...}
компилятор не понимает, какие функции не меняют объекты, поэтому это слово обязательно надо указывать
mutable - чтобы даже объекты константного класса можно было менять: mutable unsigned age;  

///
THIS
 
this->...
 can be used if the name of variable is similar to the object of the class
if you want to do like this: 
p1.move(1, 2).move(2, 3);
 you should use :
Point& move(int x, int y)
    {
        this->x += x;
        this->y += y;
        return *this;
    }
ссылка на поинт очень важна, иначе возвращаемый объект будет копией p1, т.е. : 
 Point temp = p1.move(10, 5);
temp.move(10, 10);
если же вот так хочется сделать, т.е. вернуть указатель:
  Point* move(int x, int y)
    {
        this->x += x;
        this->y += y;
        return this;
    }
то надо будет писать так:
p1->move(1, 2)->move(2, 3);

///
FRIEND CLASSES AND FUNCTIONS, OBJECTS
дружественные функции: их прототип находится внутри класса с ключевым словом friend, но определяютяся они вне класса и 
имеют доступ к закрытым полям класса!
 причем их вызов не идет через сам класс, то есть это не методы класса
 а когда нужно обратиться из этих функций к полям класса нужно применять конструкцию вида car.price, если класс имеет название car
 если же мы хотим определить функцию дружественную из другого класса, то нужно писать конструкцию вида friend void car::name(int a, int b)
reference to this feature: https://metanit.com/cpp/tutorial/5.5.php
также существуют и дружественные классы

///
STATIC OBJECTS
static variables doesnt refer to the exact element, they can be used to count different objects - то есть счетчик количества элементов например
static inline нужно указывать ключевое слово inline
static functions is used for wworking with static variables
if static variable is public, we can use Person::max_age , where person is the name of the class, max_age - static var
 or another variant is to type like sam.max_age to print this static value

///
DESTRUCTORS
every class has only one destructor
if there is no destructor compiler uses default destructor
destructor works when:  
scope is ended
array of objects has been deleted
deletes object, where is defined objects of our exact class

///
STRUCTERS
structers are used when we have public objects and functions

///
ENUM

enum class Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}, а создать переменную можно так Day today{Day::Monday}
 нумеровка enum автоматически начинается с нуля, причем чтобы вывести в консоль значение переменной тудей надо написать так:
std::cout << static_cast<int>(today)
в си++ лучше не использовать такой же enum как в С, потому что может вести к ошибкам
в С++20 добавлена функция, чтобы вместо Day::Monday писать using enum Day; or using enum Day::Monday;

///

INHERITANCE

class Employee : public Person    - person - базовый класс, причем идентификатор доступа у нас будет паблик, то есть мы получаем доступ ко всем публичным переменным класса персон
{                                                         если не указать этот идентификатор, то не будет у нас доступа к этим переменным 
public:
    std::string company;    // компания
};

конструкторы не наследуются!!!
 но если наследник имеет переменные типа родительского класса, то обязательно сначала нужно вызвать родительский конструктор сначала, иначе будет ошибка:
 Employee(std::string name, unsigned age, std::string company): Person(name, age)
{
    this->company = company;
}
или списком инициализации: 
Employee(std::string name, unsigned age, std::string company): Person(name, age), company(company)
{
}

если же новых переменных нет в классе-наследнике, то можно подключить конструктор базового класса:
 class Employee: public Person
{
public:
    using Person::Person;   // подключаем конструктор базового класса
};

 copy constructors:
Employee(const Employee& employee): Person(employee)     // u should call constructor of basic class
    { 
        company=employee.company;
    }

in the same time destructors calls in inherited class before basic class, and they both are called

NO INHERITANCE:
when you dont want to be a father(no inherited classes): class Person final  // just write final after the name of the class

PROTECTED:
it's like private class for outside, but public for inheritance, so you can use variable from basic class in inherited class, but cant use from the outside

///
Наследование ролей:
 
если спецификатор базового класса прайват, но мы хотим сделать доступной извне какую-то переменную, то можно применить функцию using Person::print;
но если изначально в классе родительском переменная или функция была private, то мы не можем сделать ее публичной никаким образом

/////
СКРЫТИЕ ФУНКЦИЙ И ПЕРЕМЕННЫХ
С++ позволяет скрывать функции в дочернем классе, а именно если мы попытаемся определить функцию с таким же именем как в базовом классе, то это не будет считаться переопределением
 В таком случае дочерний класс будет использовать свою функцию, если не обращаться к функции базового класса специально, а именно:
 Если надо обратитьяс к функции из базового класса, то надо написать Person::print
Таким же образом можно скрывать и переменные, но очень не рекомендуется

 ////

 МНОЖЕСТВЕННОЕ НАСЛЕДОВАНИЕ :
 Если дочерний класс имеет несколько родителей, то это называется множественным наследованием, и определяется следующим образом: class Smartphone : public Phone, public Camera
Причем если дочерний класс хочет инициализировать переменные родительского класса, то сначала нужно вызвать конструкторы родительских классов через списки инициализации,
причем в том же порядке, что и указывалось при наследовании
 Самое интересное, что при создании классов первым вызывается конструктор базового класса, который был первым указан, а затем остальные. Деструкторы же вызываются в обратном порядке

двойственность при множественном наследовании: если в обоих родительских классах определены функции с одинаковыми названиями и параметрами,
а в дочернем классе такой функции нет, то код не скомпилируется -> тогда нужно указать какую функцию мы хотим вызвать

VIRTUAL: 
Если у нас есть родительский класс Person, дочерний класс Student, Employee, и эти два класса имеют дочерний класс studentEmployee, тогда конструктор Person , будет вызываться дважды
а функция print в классе Person вообще не сможет вызваться, в таком случае нам нужно будет указать при наследовании классов student and employee class student: public virtual person

VIRTUAL FUNCTIONS:

dynamic binding and static blinding - static when a compiler chooses what function the user want to call
and when you have static binding, inherited class hides the function from the basic class
dynamic binding adds virtual functions, and when you define function in inherited class - you redefine the function
class that inherits vitual function names as polymorphic class
if function(inherited) has different args or different type(const and non const) it becomes static function and hides function from basic class
when you definitely need to redefine function you should use word override in inherited class: void print() const override
we need override to make more mistakes(you says to compiler that you need to redefine the func, else -> compiler gives an error)

we need to type final after the func if we dont want to have the same func in inherited class:
virtual void print() const final

TYPE CAST

when we need to make our inherited class object as basic object we can show it for everyone(obviously) like that:
int main()
{
    Employee employee{"Bob"};
    employee.print();    // Person: Bob
 
    // преобразуем в базовый тип
    Person person1{static_cast<Person>(employee)};    // через конструктор копирования
    person1.print();        // Person: Bob
 
    Person person2{"Tom"};
    person2 = static_cast<Person>(employee);   // через операцию присваивания
    person2.print();        // Person: Bob
}

dont try to use cast from basic class to inherited

DYNAMIC CAST

dynamic_cast<тип_в_который_преобразуем>(преобразуемый_объект) calling dynamic cast as static cast


EXCEPTIONS

try
{
    инструкции, которые могут вызвать исключение
}
catch(объявление_исключения) // многоточие в скобках будет означать, что можно будет обработать любое исключение
{
    обработка исключения
}
когда будет словлено исключение, то программа не будет завершаться а просто выведет сообщение об ошибке и пойдет дальше

если же напишем в скобках const char* error_message, то в эту строку будет вставлено сообщение, которое было передано через оператор throw
либо вот так:
throw std::string{"Division by zero!!"}; //  и лучше всего в скобках передавать строку по ссылке, чтобы не создавалась копия!
тогда надо писать в скобках std::string error_message

если же не обработать исключение с помощью трай кетч, то будет вызвана функция  std::terminate, а потом std::abort и завершит программу
поэтому чтобы не столкнуться с тем, что мы не обработали исключение и не писать каждый раз блок трай кетч нам необходимо
указать в функции, которая не может вызвать исключение ключевое слово noexcept.

если же нам нужно обработать несколько каких-то ошибок, то нам необходимо несколько раз вызвать функцию throw
а также нам необходимо спец. функция, которая будет вызывать несколько блоков catch в зависимости от типа в скобках будет обрабатывать исключения
пример:
{
    try
    {
        double result {divide(a, b)};
        std::cout << result << std::endl;
    }
    catch (int code)
    {
        std::cout << "Error code: " << code << std::endl;
    }
    catch (const char* error_message)
    {
        std::cout << error_message << std::endl;
    }
}
если же функция не найдет нужного блока кетч, то это будет расцениваться как необработанное исключение и будет вызвана остановка программы

также если в методе класса будет исключение, то сначала этот класс удаляется, а потом уже обрабатывается ошибка и печатается на экран

еще бывают вложенные исключения, тогда сначала выполняется внутреннее исключение, а потом уже внешнее
причем если будет выполнено внутреннее, то в таком случае внешний кетч не будет ничего печатать

new type of exception :
catch (const AgeException& ex)
{
    std::cout << ex.getMessage() << std::endl;
}
специально создан класс
class AgeException
{
public: 
    AgeException(std::string message): message{message}{} // списки инициализации
    std::string getMessage() const {return message;}
private:
    std::string message;
}; 

//порядок обработки исключений skipped : https://metanit.com/cpp/tutorial/6.5.php

также есть класс exception 
throw std::exception();
пример с ним:
#include <iostream>
 
double divide(int, int);
 
int main()
{
    int x {500};
    int y{};
    try
    {
        double z = divide(x, y);
        std::cout << z << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << "Error!!!" << std::endl;
    }
    std::cout << "The End..." << std::endl;
}
  
double divide(int a, int b)
{
    if (!b)
        throw std::exception();
    return a / b;
}

кроме класса exception есть еще следующие классы:
runtime_error: общий тип исключений, которые возникают во время выполнения

range_error: исключение, которое возникает, когда полученный результат превосходит допустимый диапазон

overflow_error: исключение, которое возникает, если полученный результат превышает допустимый диапазон

underflow_error: исключение, которое возникает, если полученный в вычислениях результат имеет недопустимое отрицательное значение (выход за нижнюю допустимую границу значений)

logic_error: исключение, которое возникает при наличии логических ошибок к коде программы

domain_error: исключение, которое возникает, если для некоторого значения, передаваемого в функцию, не определен результат

invalid_argument: исключение, которое возникает при передаче в функцию некорректного аргумента

length_error: исключение, которое возникает при попытке создать объект большего размера, чем допустим для данного типа

out_of_range: исключение, которое возникает при попытке доступа к элементам вне допустимого диапазона


TEMPLATES
При использовании шаблонов можно явно использовать тип возвращаемый функцией, т.е. например так:
 d  = add<double>(3, 2);
если неизвестно, какого типа возвращаемый объект, то можно написать так:
template <typename T> decltype(auto) average(const T (&data)[], unsigned size)  -- decltype(auto)


так можно вычислить длину массива нестандартным образом: 
template <typename T, size_t N> size_t size(const T (&data)[N]) { return N; }
 
int main()
{
    const int numbers1[]{1, 2, 3, 4, 5};
     
    std::cout << "numbers1 size: " << size(numbers1) << std::endl;
}
вместо шаблонов начиная с С++20 можно писать ключевое слово auto!!
 //шаблоны классов:
Шаблоны классов позволяют в объектах класса указывать разные параметры
 это необходимо сделать до того как определяется класс
 либо же можно указать напрямую, каким типом будет являться один объект из класса следующим образом:
 Person<unsigned> tom{123456, "Tom"}; 123456 - имеет тип ансайнд
 
 если же мы хотим создать класс, а вне класса мы будем задавать методы класса, то нам необходимо сделать так:
   
template <typename T>
class Person {
public:
    Person(T, std::string);             // обычный конструктор
    ~Person();                          // деструктор
    Person& operator=(const Person&);   // оператор присваивания
 
private:
    T id;
    std::string name;
};
template <typename T>
Person<T>::Person(T id, std::string name) : id{id}, name{name} { }
 
// определение деструктора копирования вне шаблона класса
template <typename T>
Person<T>::~Person(){ std::cout << "Person deleted" << std::endl; }
 
// определение оператора присвоения вне шаблона класса
template <typename T>
Person<T>& Person<T>::operator=(const Person& person)
{ 
    if (&person != this)
    {
        name = person.name;
        id = person.id;
    }
    return *this;
}

то есть дважды писать шаблоны необходимо 
даже если метод не содержит в своих параметрах шаблон, то все равно необходимо указать template<typename T>

также можно указывать тип шаблона по умолчанию слпедующим образом:
   
template <typename T=int>
class Person {
public:
    Person(std::string name) : name{name} { }
    void setId(T value) { id = value;}
   
private:
    T id;
    std::string name;
};
с помощью функции setId мы можем указать тип T кроме инта, который нам нужен

для шаблонов можно сделать специализацию, чтобы подставлять конкретный тип иногда, если нужно
для этого необходимо указать так template<>
причем в таком случае будет два раза определен класс, сначала для шаблона, а потом для специализации шаблона
также возможна частичная специализация, когда только один из двух параметров ьудет идти со специальным типом нужным нам

Наследование шаблонных классов:
При наследовании необходимо указать следующим образом:
template <typename T>
class Employee: public Person<T>
причем каждый раз при обращение к функциональности класса мы должны писать следующим образом:
Person<T>{id, name}   // вызов конструктора
Person<T>::print();   // вызов функции print
Person<T>::name       // обращение к переменной name базового класса Person
можно также указать явным образом наследование:
сlass Employee: public Person<unsigned> 
значение в базовом классе будет определяться значением в производном классе employee
 
