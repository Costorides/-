#include <stdio.h>

#define YES  1
#define NO   0

int main()
{   
    int c;         
    int flag;      
    int cnt;       
    int plus_res;  
    
    cnt = 0;
    flag = NO;
    plus_res = NO;
    
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '.' || c == '\n' || c == ',' 
        || c == '!' || c == '?' || c == ';' || c == ':')
        {   
            if(flag == YES)
            {
                if(plus_res == YES)
                {
                    cnt = cnt + 1;
                }
            }
            flag = NO;
            plus_res = NO;
        }
        else
        {   
            flag = YES;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                plus_res = YES;
        }
    }
    
    printf("Число слов, содержащих гласные = %d\n", cnt);
    return 0;
}


//putchar. S->'S'. свапать регистр гласных букв. shrek-> 'S'hrEk