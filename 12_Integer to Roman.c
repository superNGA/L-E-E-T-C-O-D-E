#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
*/

char* intToRoman(int num)
{
	int spliter[4];
	int level = 3, positionTOalter = 0,numCURRENT;
	char* answer = (char*)malloc(100*sizeof(char));

	//splitting num
	while (level >= 0)
	{
	    spliter[level] = num%10;
		num /= 10;
		level--;
	}

	for(int j =3; j>=0; j--)
    {
        numCURRENT = spliter[3-j];

        printf("%d\n", numCURRENT);

        if(j == 0)
        {
            if(numCURRENT == 4)
            {
                answer[positionTOalter] = 'I';
                positionTOalter++;
                answer[positionTOalter] = 'V';
                positionTOalter++;
            }else if(numCURRENT == 9)
            {
                answer[positionTOalter] = 'I';
                positionTOalter++;
                answer[positionTOalter] = 'X';
                positionTOalter++;
            }else if(numCURRENT == 5)
            {
                answer[positionTOalter] = 'V';
                positionTOalter++;
            }else
            {
                //adjusting for adding 'I' to answer
                if(numCURRENT > 5)
                {
                    answer[positionTOalter]='V';
                    positionTOalter++;
                    numCURRENT -=5;
                }
                for(int i=0; i<numCURRENT; i++)
                {
                    answer[positionTOalter] = 'I';
                    positionTOalter++;
                }
            }
        }
        else if(j == 1)
        {
            if(numCURRENT == 4)
            {
                answer[positionTOalter] = 'X';
                positionTOalter++;
                answer[positionTOalter] = 'L';
                positionTOalter++;
            }else if(numCURRENT == 9)
            {
                answer[positionTOalter] = 'X';
                positionTOalter++;
                answer[positionTOalter] = 'C';
                positionTOalter++;
            }else if(numCURRENT == 5)
            {
                answer[positionTOalter] = 'L';
                positionTOalter++;
            }else
            {
                //adjusting for adding 'I' to answer
                if(numCURRENT > 5)
                {
                    answer[positionTOalter]='L';
                    positionTOalter++;
                    numCURRENT -=5;
                }
                for(int i=0; i<numCURRENT; i++)
                {
                    answer[positionTOalter] = 'X';
                    positionTOalter++;
                }
            }
        }
        else if(j == 2)
        {
            if(numCURRENT == 4)
            {
                answer[positionTOalter] = 'C';
                positionTOalter++;
                answer[positionTOalter] = 'D';
                positionTOalter++;
            }else if(numCURRENT == 9)
            {
                answer[positionTOalter] = 'C';
                positionTOalter++;
                answer[positionTOalter] = 'M';
                positionTOalter++;
            }else if(numCURRENT == 5)
            {
                answer[positionTOalter] = 'D';
                positionTOalter++;
            }else
            {
                //adjusting for adding 'I' to answer
                if(numCURRENT > 5)
                {
                    answer[positionTOalter]='D';
                    positionTOalter++;
                    numCURRENT -=5;
                }
                for(int i=0; i<numCURRENT; i++)
                {
                    answer[positionTOalter] = 'C';
                    positionTOalter++;
                }
            }
        }
        else if(j == 3)
        {
            for(int i =0; i<numCURRENT; i++)
            {
                answer[positionTOalter] = 'M';
                positionTOalter++;
            }
        }
        else
        {
            printf("you FUCKED up something\n");
        }

    }

    //locking string
    answer[positionTOalter] = '\0';

    return answer;
}

int main(void)
{
	printf("%s", intToRoman(3749));

	return 0;
}
