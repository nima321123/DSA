#include <stdio.h>

typedef struct {
    char name[50];
    int yearOfBirth;
} CEO;

typedef struct {
    char name[50];
    CEO ceo;
} Company;

int main() {
    Company company;
    
    // Assigning values
    strcpy(company.name, "Tech Corp");
    strcpy(company.ceo.name, "John Doe");
    company.ceo.yearOfBirth = 1980;

    printf("Company: %s\n", company.name);
    printf("CEO: %s\n", company.ceo.name);
    printf("Year of Birth: %d\n", company.ceo.yearOfBirth);

    return 0;
}