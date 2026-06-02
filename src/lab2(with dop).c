float function (float s, float a, float b, int n, int i, int sign) {
   do {
    s = s + sign*(a/b); 
    if (i > 10 && i < 20){
        a = a + 3;
        b = b + 1;}  
    
    else if (i == 25 || i % 26 == 0) {
        sign = -100*sign;
        a = a + 3;
        b = b + 1;}
    
    else if (i > 10000) {
        sign = 0.5*sign
    }
    
    else {
        sign = -1*sign; 
        a = a + 1;
        b = b + 3;}
    i = i + 1;
   } 
   while (i < n);
   return s;
}


int main (void) { 
    float s;
    float a; 
    float b;  
    int n;
    int i; 
    int sign; 
    
    scanf("%d", &n); 
    printf("n = %d\n",n); 

    s = function(0,3,1,n,0,1);

    printf("s = %f\n", s); 
    return 0; 
}

//реализовать цикл do while в функции,  с несколькими условиями || &&
