#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>

//converting string to int
int myAtoi(char* s)
{
    bool countingSTARTED = false, stopper = false,sign_occurance = false, neg = false, leadingSPACE = false, anystarter = false;
    long long int counter = 0;
    int temp = 0;

    int helper(char s, bool* countingSTARTED, bool* stopper, bool* sign_occurance, bool* neg, bool* anystarter)
    {
        switch(s)
        {
        case '0':
            (*anystarter) = true;
            if(*countingSTARTED == true)
            {
                return 0;
            }else
            {
                return 100;
            }
        case '1':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 1;
        case '2':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 2;
        case '3':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 3;
        case '4':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 4;
        case '5':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 5;
        case '6':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 6;
        case '7':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 7;
        case '8':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 8;
        case '9':
            (*anystarter) = true;
            (*countingSTARTED) = true;
            return 9;
        default:
            printf("( %c )\n", s);
            if(isalpha(s) || s=='.')
            {
                printf("setting stopper \n");
                (*stopper) = true; //stopping at char
            }
            else if(s == '-' && (*sign_occurance) == false && (*anystarter) == false) //checking for sign reappearence
            {
                (*anystarter) = true;
                (*neg) = true;
                (*sign_occurance) = true;
            }
            else if(s == '+' && (*sign_occurance) == false && (*anystarter) == false) //checking for sign reappearence
            {
                (*anystarter) = true;
                (*neg) = false;
                (*sign_occurance) = true;
            }
            else if(s == '-' && (*sign_occurance) == true) //checking for sign reappearence
            {
                printf("setting stopper \n");
                (*stopper) = true;
            }
            else if(s == '+' && (*sign_occurance) == true) //checking for sign reappearence
            {
                printf("setting stopper \n");
                (*stopper) = true;
            }
            else if(s == '-' && (*countingSTARTED) == true || s == '-' && (*anystarter) == true)
            {
                printf("setting stopper \n");
                (*stopper) = true;
            }
            else if(s == '+' && (*countingSTARTED) == true || s == '+' && (*anystarter) == true)
            {
                printf("setting stopper \n");
                (*stopper) = true;
            }
            else if(s == '-' && (*anystarter) == true)
            {
                printf("setting stopper \n");
                (*stopper) = true;
            }
            else if(s == '+' && (*anystarter) == true)
            {
                printf("setting stopper \n");
                (*stopper) = true;
            }
            return 100;
        }
    }

    //main loop
    for(int i =0 ;i< strlen(s); i++)
    {
        //managing leading spaces
        if(s[i] == ' ' && leadingSPACE == false)
        {
            continue;
        }else if(anystarter == true && s[i] == ' ')
        {
            break;
        }
        else
        {
            leadingSPACE = true;
        }

        //getting value from helper function
        temp = helper(s[i], &countingSTARTED, &stopper, &sign_occurance, &neg, &anystarter);

        //incrementing values into counter
        if(temp != 100)
        {
            counter += temp;
            counter *= 10;
        }

        //managing size
        if(counter/10 >= (long long int)2147483647 && neg == false)
        {
            counter = (long long int)2147483647;
            return counter;
        }else if(counter/10 >= 2147483648 && neg == true)
        {
            counter = (long long int)-2147483648;
            return counter;
        }
        printf("%d   <->   %d  <->  \n", anystarter, stopper);
        //stopping at flag
        if(stopper == true || i >= 1 && isalnum(s[i-1]) && s[i] == '-')
        {
            break;
        }
    }

    counter /=10;

    //managing size
    if(neg == true)
    {
        printf("answer : %lld\n", counter);
        counter *= (long long int)-1;
        printf("answer : %lld\n", counter);
    }

    return counter;
}

int main(void)
{
    printf("%lld", myAtoi("000+123"));

    return 0;
}
