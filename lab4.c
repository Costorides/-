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
    fgets(line,MAXLINE,stdin);
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

    flag = NO;
    word_length = 0;
    start = 0;
    i = 0;
    pos = 0;

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
                    for (j = start; j < i; j++)
                        buffer[pos++] = buffer[j];
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
}
