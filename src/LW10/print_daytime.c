#include <time.h>
#include <stdio.h>


void sprint_time(char* outstr, struct tm* info)
{
    sprintf(outstr, "%d:%d:%d", info->tm_hour, info->tm_min, info->tm_sec);
    printf("%s", outstr);
}

void sprint_date(char* outstr, struct tm* info)
{
    sprintf(outstr, "%d/%d/%d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);
    printf("%s", outstr);
}

int main()
{
    char* outstr[8];
    time_t current_time = time(NULL);
    struct tm* info = localtime(&current_time);

    // print current time
    info->tm_hour; // hour
    info->tm_min; // minute
    info->tm_sec; // second

    // print current date
    info->tm_mday; // day
    info->tm_mon + 1; // month
    info->tm_year + 1900; // year

    info->tm_wday; // day of the week: 0 -> Sun, 1 -> Mon, ...

    sprint_time(outstr, info);
    printf("\n");
    sprint_date(outstr, info);

    return 0;
}