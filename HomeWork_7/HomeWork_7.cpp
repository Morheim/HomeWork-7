#include <iostream>
#include "MyLib.h"
#include <fstream>

#define TRUE_OR_FALSE(entered_number, last_number) (entered_number >= 0 && entered_number < last_number) //ко 2-рому заданию
#define SwapINT(a, b)int temp = a; a = b; b = temp;

using namespace std;

void DZ1()
{
    cout << "//=================================================[DZ_1,5]==================================================//\n\n";
}
void DZ2()
{
    cout << "\n//===================================================[DZ2]===================================================//\n\n";
}
void DZ3()
{
    cout << "\n//===================================================[DZ3]===================================================//\n\n";
}
void DZ4()
{
    cout << "\n//===================================================[DZ4]===================================================//\n\n";
}
void END()
{
    cout << "\n\n//===================================================[END]===================================================//\n\n";
}

#pragma pack(push, 1)
struct PERSONAL //структура для 4-того задания.
{
    char FullName[255];   //ФИО сотрудника
    char Street[255];     //Улица сотрудника
    short House;          //Номер дома сотрудника
    short Flat;           //Номер квартиры сотрудника
    char Phone;           //Телефон сотрудника
};
#pragma pack(pop)


int main()
{
    setlocale(LC_ALL, "Rus");
    {
        /* DZ_1,5
          Создайте проект из 2х cpp файлов и заголовочного (main.cpp,
          mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
          для инициализации массива (типа float), печати его на экран и
          подсчета количества отрицательных и положительных
          элементов. Вызывайте эти 3-и функции из main для работы с
          массивом.
        */
        DZ1();
        float* M = MyLib::CreateArray(10);
        MyLib::count(M, 10);
        MyLib::Print(M, 10);

    }

    {
        /* DZ2
          Описать макрокоманду (через директиву define),
          проверяющую, входит ли переданное ей число (введенное с
          клавиатуры) в диапазон от нуля (включительно) до переданного
          ей второго аргумента (исключительно) и возвращает true или
          false, вывести на экран «true» или «false».
        */
        DZ2();

        int entered_number;
        const int last_number = 3434;
        cout << boolalpha; //стандартная команда, которая благодаря вызову bool выводит тебе тру, либо фалс.
        cout << "Enter the number you want to check: " << endl;
        cin >> entered_number;
        bool result = TRUE_OR_FALSE(entered_number, last_number);
        cout << "Your result: " << result << endl;
    }

    {
        /* DZ3
          Задайте массив типа int. Пусть его размер задается через
          директиву препроцессора #define. Инициализируйте его через
          ввод с клавиатуры. Напишите для него свою функцию
          сортировки (например Пузырьком). Реализуйте перестановку
          элементов как макрокоманду SwapINT(a, b). Вызывайте ее из
          цикла сортировки.
        */
        DZ3();

        int* Array;
        int n;
        cout << "array size ";
        cin >> n;
        Array = new int[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Array[" << i << "] = ";
            cin >> Array[i];
        }

        int temp;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (Array[j] > Array[j + 1])
                {
                    SwapINT(Array[j], Array[j + 1])
                }
            }
        }

        for (int i = 0; i < n; i++) 
        {
            cout << Array[i] << " ";
        }
        cout << endl;
        delete[] Array;
    }

    {
        /* DZ4
        Объявить структуру Сотрудник с различными полями.
        Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
        Выделите динамически переменную этого типа. Инициализируйте ее.
        Выведите ее на экран и ее размер с помощью sizeof.
        Сохраните эту структуру в текстовый файл.
        */
        DZ4();

        auto company = new PERSONAL;
        cout << "Your file size: " << sizeof(PERSONAL) << " bytes" << endl;

        string path = "PERSONAL.txt";
        ofstream fout;
        fout.open(path);
        if (!fout.is_open())
        {
            cout << "File open ERROR!" << endl;
        }
        else
        {
            string SOTRUDNIK;
            fout.write ((char*)company, sizeof(company));
        }
        fout.close();
        delete company;
        END();
    }
    return 0;
}