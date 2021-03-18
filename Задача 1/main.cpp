#include <iostream>
#include <cstdio>
#include <string>

void find_comment(int c);
void in_comment(void);
void in_short_comment(void);
FILE *in, *out;

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    int c;
    char file_name[20];
    char out_file_name[20];

    cout << "Введите имя входного файла: ";
    gets(file_name);
    in = fopen(file_name,"rb");//Открыть файл для чтения
    if((in = fopen(file_name, "rb")) == NULL)
    {
        cerr << "Can not open: " << in << endl;
        return EXIT_FAILURE;
    }
    cout << "Введите имя выходного файла: ";
    gets(out_file_name);
    out = fopen(out_file_name, "wb");//открыть файл для записи
    while((c = fgetc(in)) != EOF)
    {
        find_comment(c);
    }
    fclose(in);
    fclose(out);
    return 0;
}

/*поиск коментариев*/
void find_comment(int c)
{
    int d;
    if (c=='/')
        if ((d = fgetc(in)) =='*')
            in_comment();
        else if (d=='/')
            in_short_comment();
        else
        {
            fputc(c, out);
            fputc(d, out);
        }
    else
        fputc(c, out);
}

/*внутри длинного комментария*/
void in_comment(void)
{
    int c, d;
    c = fgetc(in);
    d = fgetc(in);
    while (c != '*' || d != '/')
    {
        c = d;
        d = fgetc(in);
    }
}

/*внутри короткого комментария*/
void in_short_comment(void)
{
    int c;
    c = fgetc(in);
    while (c != '\n')
        c = fgetc(in);
}
