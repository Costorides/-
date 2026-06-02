#include <stdio.h>
#define YES  1
#define NO   0
#define MAXLINE 1000

void process_line(char buffer[], int N);

int main(void)
{
    char line[MAXLINE];
    int N;

    printf("N: ");
    scanf("%d", &N);
    getchar();
    fgets(line, MAXLINE, stdin);
    process_line(line, N);
    puts(line);

    return 0;
}

void process_line(char buffer[], int N)
{
    char c;           // текущий символ
    int flag;         // признак слова
    int word_length;  // длина текущего слова
    int i;            // позиция текущего символа исходной строки
    int pos;          // позиция текущего символа результирующей строки
    int start;        // позиция начала слова
    int j;
    FILE *file;       // файл для записи удаленных слов

    flag = NO;
    word_length = 0;
    start = 0;
    i = 0;
    pos = 0;

    // Открываем файл для записи удаленных слов
    file = fopen("deleted_words.txt", "w");
    if (file == NULL)
    {
        printf("Ошибка при открытии файла!\n");
        return;
    }

    do
    {
        c = buffer[i]; // взять текущий символ из буфера

        if (c == ' ' || c == '.' || c == ',' ||
            c == '\n' || c == '\0')
        {
            if (flag == YES)
            {
                if (word_length <= N)
                {
                    // Копируем слово, если его длина не превышает N
                    for (j = start; j < i; j++)
                        buffer[pos++] = buffer[j];
                }
                else
                {
                    // Слово удаляется - записываем его в файл
                    for (j = start; j < i; j++)
                        fputc(buffer[j], file);

                    // Добавляем разделитель между словами в файле
                    if (c == ' ')
                        fputc('\n', file);
                    else if (c == '.' || c == ',' || c == '\n')
                        fputc(c, file);
                    else
                        fputc(' ', file);
                }
            }

            flag = NO;
            word_length = 0;
            buffer[pos++] = c;
        }
        else
        {
            if (flag == NO)
            {
                start = i;
                flag = YES;
            }
            word_length++;
        }

        i++;
    }
    while (c != '\0');

    // Закрываем файл
    fclose(file);
}
