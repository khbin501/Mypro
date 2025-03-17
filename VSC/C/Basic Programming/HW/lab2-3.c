#include <stdio.h>

int main() {
    float weights, meters,BMI;

printf("pleaes type your weights and meters\n\n");
    scanf("%f %f", &weights, &meters);

    BMI = weights/(meters*meters);

    printf("your BMI is %f\n\n", BMI);

    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal: between 18.5 and 24.9\n");
    printf("Overweight: between 25 and 29.9\n");
    printf("obese: 30 or greater");
    return 0;
}