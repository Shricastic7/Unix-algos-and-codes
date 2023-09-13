#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;

void setDateTime(int date, int month, int year, int hour, int min, int sec)
{
    unsigned char buff[32] = { 0 };
    printf("New System Time:\n");
    sprintf((char*)buff, (const char*)"date -s \"%02d/%02d/%04d %02d:%02d:%02d\"", month, date, year, hour, min, sec);
    
    system((const char*)buff);
}
int main(int argc, char *argv[])
{
    int month, day, hour, minute, year;
    unsigned char buff[32] = { 0 };
    if (argc == 1)
    {
        printf("Current Time:\n");
        sprintf((char*)buff, (const char*)"date");
        system((const char*)buff);
        cout << endl;
        exit(0);
    }
    if (argc > 2)
    {
        printf("Wrong Number of Arguments!!! \n Correct Format: ./a.out argument_1");
        exit(0);
    }
    if (strlen(argv[1]) != 12 || sscanf(argv[1], "%2d%2d%2d%2d%4d", &month, &day, &hour, &minute, &year) != 5)
    {
        printf("Invalid Date Format!!! \n Correct Format: ./a.out MMddhhmmyyyy\n");
        exit(0);
    }
    setDateTime(day , month , year , hour , minute , 00);
    cout << endl;
    return 0;
}
