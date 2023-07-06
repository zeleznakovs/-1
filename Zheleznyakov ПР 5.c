#include <stdio.h>

// Функція приймає ціле число n як вхідний аргумент та повертає кількість шуканих послідовностей довжиною n
// Тут використовується динамічне програмування для побудови масиву dp
int countSequences(int n)
{
   int dp[n + 1];
   dp[0] = 1;
   dp[1] = 2;
   dp[2] = 4;

   for (int i = 3; i <= n; i++)
   {
      dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 12345;
   }

   return dp[n];
}

int main()
{
   int n;

   // Введення числа
   printf("Enter the length of the sequence n (1 < n < 10000): ");
   scanf("%d", &n);

   // Перевірка діапазону, повідомлення про помилку у випадку якщо користувач ввів число, що не задовольняє умову
   if (n > 1 && n < 10000)
   {
      int result = countSequences(n);
      printf("Number of searched sequences: %d\n", result);
   }
   else
   {
      printf("Erorr. Please input correct number");
   }

   return 0;
}
