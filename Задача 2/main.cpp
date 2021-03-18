#include <iostream>
#include <fstream>
#include <cstdlib>
// Заголовочные файлы для файлового ввода-вывода

#include <conio.h>   //необходимо для getch()

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

/*создаем объект F1, который создаст файл file.txt
циклом for заполнеяем файл из массива x[10]] */
    cout << "Какой длины будет одна строка в файле: ";
    int k = 0;
    cin >> k;
    ofstream F1("file.txt", ios_base::trunc);
    for ( int i = 0; i < 15; i++) {
        for ( int j = 0; j < k; j++) {
            F1 << rand() % 10;
        }
        F1 << "\n";
    }
    F1.close();

    cout << "Введите номер строки, которую нужно вывести (1-15): ";
    int n = 0;
    cin >> n;
    ifstream file("file.txt");

    if (n > 1)
        file.seekg((n - 1) * (k + 2));
    else
        file.seekg(0);
    char str[k]; // буфер для чтения одной строки
    file.getline (str, k + 1);
    cout << "Строка №" << n << ": " << str << endl;
    file.close();
    return 0;
}
