#include <stdio.h>

// Функция для зеркального отражения битов
unsigned long Zerkalo(unsigned long n) {
    unsigned long result = 0;  // Результат (начинаем с нуля)

    // Пока число не станет равно нулю
    while (n != 0) {
        result <<= 1;        // Сдвигаем результат влево (освобождаем место)
        result |= (n & 1);   // Берём младший бит n и добавляем его к результату
        n >>= 1;             // Сдвигаем n вправо (переходим к следующему биту)
    }

    return result;  // Возвращаем число с перевёрнутыми битами
}

int main() {
    unsigned long n;  // Исходное число

    // Ввод числа в шестнадцатеричном формате
    printf("n: ");
    scanf("%lx", &n);

    // Вывод исходного числа
    printf("n:  0x%lx\n", n);

    // Вывод двоичного представления исходного числа
    printf("2vid: ");
    for (int i = sizeof(unsigned long) * 8 - 1; i >= 0; i--) {
        printf("%lu", (n >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" "); // Группируем по 4 бита
    }
    printf("\n");

    // Получаем перевёрнутое число
    unsigned long reversed = Zerkalo(n);

    // Вывод результата
    printf("Zerkalo:      0x%lx\n", reversed);

    // Вывод двоичного представления результата
    printf("2vid: ");
    for (int i = sizeof(unsigned long) * 8 - 1; i >= 0; i--) {
        printf("%lu", (reversed >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" "); // Группируем по 4 бита
    }
    printf("\n");

    return 0;
}
