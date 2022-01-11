#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int count_lines(FILE* file){
    int prev_symbol, symbol, last_symbol = EOF;
    int num_of_lines = 0;
    while ((symbol = fgetc(file)) != EOF)
    {
        if (symbol == '\n')
        {
            num_of_lines ++;
        }
        if (symbol == EOF && prev_symbol =='\n')
        {
            num_of_lines--;
        }
        prev_symbol = symbol;
        if (symbol != EOF)
        {
            last_symbol = symbol;
        }
    }
    if (last_symbol != '\n' && last_symbol != EOF)
    {
        num_of_lines++;
    }
    return num_of_lines;
}

int count_words(FILE* file){
    int symbol, flag = 0;
    int num_of_words = 0;
    while ((symbol = fgetc(file)) != EOF)
    {
        if (symbol == '\n' || symbol == ' ' || symbol == '\t')
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            flag = 1;
            num_of_words++;
        }
    }
    return num_of_words;
}

int count_file_size(FILE* file){
    int file_size = 0;
    fseek(file, 0, SEEK_END); // перемещаем внутренний указатель в конец файла
    file_size = ftell(file); // получаем номер последнего байта
    return file_size;
}

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[2], "r"); // открываем файл на чтение
    FILE *file_byte = fopen(argv[2], "rb"); // открываем файл на чтение
    if (file == NULL) // проверяем, существует ли такой файл
    {
        printf("\nError: File not found");
    }
    else
    {
        if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--lines") == 0) // сравниваем строки с помощью функции strcmp()
        {
            int num_of_lines;
            num_of_lines = count_lines(file);
            printf("\nNumber of Lines = %d", num_of_lines);
        }
        else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--words") == 0)
        {
            int num_of_words;
            num_of_words = count_words(file);
            printf("\nNumber of Words = %d", num_of_words);
        }
        else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--bytes") == 0)
        {
            int file_size;
            file_size = count_file_size(file_byte);
            printf("\nFile size = %d", file_size);
        }
        else
        {
            printf("\nOption not found or entered incorrectly");
        }
    }
    fclose(file);
}


// Нормальный код)
