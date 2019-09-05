#include <stdio.h>
#include <math.h>
#include <cs50.h>

int checkeven(long,int);
int checkodd(long,int);
int checklength(long);
void checkcard(long);

int main(void)
{
    long num = 0;
    int totaldigits = 0;
    num = get_long("Enter credit card number \n"); 
    totaldigits = checklength(num);
    if(totaldigits < 13 || totaldigits > 16 || totaldigits == 14){
        printf("INVALID \n");
    }
    int addeven = checkeven(num,totaldigits);
    int addodd = checkodd(num,totaldigits);
    int  total = addeven + addodd;
    printf("%i\n", total);
    if(total % 10 != 0){
        printf("INVALID \n");
    } else{
        switch(totaldigits){
            case 13 :
                printf("VISA\n");
                break;
            case 15 :
                printf("AMEX\n");
                break;
            case 16 :
                checkcard(num);
        }
    }
           
}   

int checklength(long num){
    int totaldigits = 0;
    long dig = num;
    while( dig != 0) {
    dig = dig / 10;
    totaldigits ++;
    }
    return totaldigits;
}

int checkeven(long num, int dig){
    int total = 0;
    int tol = dig / 2;
    int initial;
    for(int i = 1; i <= tol; i++){
        long n;
        int first = 0;
        long d = pow(100,i);
        n = num % d;
        if(n < d / 10 ){
            initial = 0;
        } else{
            while(n >= 10){
                n = n / 10;
            }
            initial = n;
        }
        
        initial = initial*2;
        if(initial >= 10){
            total += initial % 10;
            total += 1;
        } else{
            total += initial;
        }
    }
    return total;
}    

int checkodd(long num, int dig){
    int total = 0;
    int tol = dig / 2;
    if(dig % 2 != 0){
      tol ++;  
    }
    for(int i = 0; i <= tol-1; i++){
        long n;
        long d = pow(100,i) * 10;
        if(i == 0){
            d = 10;
        }
        n = num % d;
        if(n < d / 10 ){
            total += 0;
        } else{
            while(n >= 10){
                n = n / 10;
            }
        total += n;
        }
        
    }
    return total;
}   

void checkcard(long num){
    while(num >= 10){
            num = num / 10;
    }
    if(num == 4){
        printf("VISA\n");
    } else{
        printf("MASTERCARD\n");
    }
}
