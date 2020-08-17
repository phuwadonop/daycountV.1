#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void toLowercase();
int asciivalue();
int main() {

    int dayofmonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int dayinweek = 1, year, month, daycount = 0, n;
    char input[10];
    printf("Choose a day form Monday to Sunday : ");
    scanf("%[^\n]", input);
    toLowercase(input);

    if (asciivalue(input) == 660) n = 7;  //sunday
    if (asciivalue(input) == 648) n = 1;//monday
    if (asciivalue(input) == 767) n = 2;//tuesday
    if (asciivalue(input) == 964) n = 3;//wed
    if (asciivalue(input) == 884) n = 4;//thu
    if (asciivalue(input) == 639) n = 5;// fri
    if (asciivalue(input) == 877) n = 6;// sat

    for (month = 1; month <= 12; month++) {
        dayinweek += (dayofmonth[month - 1] % 7);
        if (dayinweek > 7) {
            dayinweek = dayinweek % 7;
        }
    }
    for (year = 1901; year <= 2000; year++) {
        if ((year % 400 == 0 && year % 100 == 0) || (year % 4 == 0)) {
            dayofmonth[1] = 29;
        }
        else {
            dayofmonth[1] = 28;
        }
        for (month = 1; month <= 12; month++) {
            dayinweek += (dayofmonth[month - 1] % 7);
            if (dayinweek > 7) {
                dayinweek = dayinweek % 7;
            }
            if (dayinweek == n) {
                daycount++;
            }
        }
    }
    printf("%d", daycount);
}
void toLowercase(char x[10]) {
    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] >= 65 && x[i] <= 90) {
            x[i] += 32;
        }
    }
}
int asciivalue(char text[10]) {
    int ascvalue = 0;
    for (int i = 0; text[i] != '\0';i++) {
        ascvalue += text[i];
    }
    return ascvalue;
}