#include <iostream>
#include <fstream>
#include <cstdlib>
// ������������ ����� ��� ��������� �����-������

#include <conio.h>   //���������� ��� getch()

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

/*������� ������ F1, ������� ������� ���� file.txt
������ for ���������� ���� �� ������� x[10]] */
    cout << "����� ����� ����� ���� ������ � �����: ";
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

    cout << "������� ����� ������, ������� ����� ������� (1-15): ";
    int n = 0;
    cin >> n;
    ifstream file("file.txt");

    if (n > 1)
        file.seekg((n - 1) * (k + 2));
    else
        file.seekg(0);
    char str[k]; // ����� ��� ������ ����� ������
    file.getline (str, k + 1);
    cout << "������ �" << n << ": " << str << endl;
    file.close();
    return 0;
}
