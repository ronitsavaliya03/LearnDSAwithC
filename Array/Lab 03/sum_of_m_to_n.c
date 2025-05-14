#include <stdio.h>

int main() {
    int m, n, sum = 0;
    printf("Enter start value (m): ");
    scanf("%d", &m);
    printf("Enter end value (n): ");
    scanf("%d", &n);

    if(m>n){
        int temp=m;
        m=n;
        n=temp;
    }

    for (int i = m; i <= n; i++)
        sum += i;

    printf("Sum from %d to %d = %d\n", m, n, sum);
    return 0;
}
