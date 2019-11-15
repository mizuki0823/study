#include <stdio.h>
int keisan(int, int);
int main(void)
{
    int a, b, c;

    printf("入力\n");
    scanf("%d%d%d", &a, &b, &c);
    keisan(a, b);
    printf("%d + %d = %d\n ", a, b, keisan(a, b) );
    printf("%d + %d = %d\n", b, c, keisan(b, c));
     printf("%d + %d = %d\n", a, c, keisan(a, c));
    return 0;

}

int keisan(int x, int y) {
    return x + y;
}