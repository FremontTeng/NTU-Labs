#include <stdio.h>
#define SIZE 20
/* function prototypes */
int rNumDigits1(int num);
void rNumDigits2(int num, int *result);
int rDigitPos1(int num, int digit);
void rDigitPos2(int num, int digit, int *pos);
int rSquare1(int num);
void rSquare2(int num, int *result);
int rCountArray(int array[], int n, int a);

int main()
{
 int choice;
 int number;
 int digit, result=0;
 int array[SIZE];
 int index, count, target, size;

 do {
    printf("\nPerform the following functions ITERATIVELY:\n");
    printf("1: rNumDigits()\n");
    printf("2: rDigitPos()\n");
    printf("3: rSquare()\n");
    printf("4: rCountArray()\n");
    printf("5: quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("rNumDigits1(): %d\n", rNumDigits1(number));
            rNumDigits2(number, &result);
            printf("rNumDigits2(): %d\n", result);
            break;
        case 2:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("Enter the digit: \n");
            scanf("%d", &digit);
            printf("rDigitPos1(): %d\n", rDigitPos1(number, digit));
            rDigitPos2(number, digit, &result);
            printf("rDigitPos2(): %d\n", result);
            break;
        case 3:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("rSquare1(): %d\n", rSquare1(number));
            rSquare2(number, &result);
            printf("rSquare2(): %d\n", result);
            break;
        case 4:
            printf("Enter array size: \n");
            scanf("%d", &size);
            printf("Enter %d numbers: \n", size);
            for (index = 0; index < size; index++)
                scanf("%d", &array[index]);
            printf("Enter the target number: \n");
            scanf("%d", &target);
            count = rCountArray(array, size, target);
            printf("rCountArray(): %d\n", count);
            break;
        default:
            printf("Program terminating .....\n");
            break;
        }
    } while (choice < 7);

    return 0;
}

int rNumDigits1(int num)
{
    if (num < 10)
        return 1;
    else
        return rNumDigits1(num/10) + 1;
}

void rNumDigits2(int num, int *result)
{
 /* Write your program code here */
    if (num < 10)
        *result = 0;
    else
        rNumDigits2(num/10, result);
        *result = *result + 1;

}

int rDigitPos1(int num, int digit)
{
 int pos;
 /* Write your program code here */
 if (num % 10 == digit)
    return 1;
 else if (num < 10)
    return 0;
 else {
    pos = rDigitPos1(num/10, digit);
    if (pos > 0)
        return pos+1;
    else
        return 0;
    }
}

void rDigitPos2(int num, int digit, int *pos)
{
 if (num % 10 == digit)
    *pos = 1;
 else if (num < 10)
    *pos = 0;
 else {
    rDigitPos2(num/10, digit, pos);
    if (*pos > 0)
        *pos += 1;
    else
        *pos = 0;
    }
}

int rSquare1(int num)
{
 /* Write your program code here */
 if (num == 1){
    return 1;
    }
 else{
    return (2*num -1 + rSquare1(num-1));
 }

}

void rSquare2(int num, int *result)
{
 /* Write your program code here */
  if (num == 1){
    *result = 1;
    }
 else{
    rSquare2(num-1, result);
    *result += (2*num -1);
 }
}

int rCountArray(int array[], int n, int a)
{
 /* Write your program code here */
 if (n == 0){
    return 0;
 }
 else if (array[n-1] == a){
    return 1 + rCountArray(array, n-1, a);
 }
 else{
    return 0 + rCountArray(array, n-1, a);
 }
}
