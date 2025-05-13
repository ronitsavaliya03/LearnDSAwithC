#include <stdio.h>

int main() {
    int total_days, years, weeks, days;

    printf("Enter total number of days: ");
    scanf("%d", &total_days);
    
    int store_days=total_days;

    years = total_days / 365;            
    total_days %= 365;                   

    weeks = total_days / 7;             
    days = total_days % 7;               

    printf("%d days is equivalent to %d year(s), %d week(s), and %d day(s).\n", store_days, years, weeks, days);

    return 0;
}
