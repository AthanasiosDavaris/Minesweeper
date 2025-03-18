#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int con(char str[], int giw, int* rgo);

void exitt(int **board , int **board2);

int open(int r,int ci, int **board, int **board2, int rows, int cols);

void cheat(int **board2, int **board, int x, int y);

void mark(int x, int y, int **board, int **board2);

int main (void)
{
    srand(time(NULL));
    int **board , **board2;
    int ci, i, flag=0, j, x, y, rows, cols, dif, mameki, uif, r, *c, max=0, row ,q ;
    int col, n=0, amount, a, f, blocks=0;
    char str[20]={0}, str2[20], str3[20], str4[20];
    c=&ci;
    do
    {
        printf("how many collumns do you want the board to be?(min 8/ max 16)\n");
        scanf("%d", &cols);
        if (((cols<8) || (cols>16)))
        {
            printf("Invalid input: Illegal size of collumns.\nPlease try again:\n");
        }
    }while((cols<8) || (cols>16));
    do
    {
        printf("how many rows do you want the board to be?(min 8/ max 16)\n");
        scanf("%d", &rows);
        if (((rows<8) || (rows>16)))
        {
            printf("Invalid input: Illegal size of rows.\nPlease try again:\n");
            
        }
    }while((rows<8) || (rows>16));
    board=(int**)malloc(rows*sizeof(int*));
	if(board==NULL)
	{
		printf("Error not available memeory\n");
		exit(EXIT_FAILURE);
	}
    for(i=0;i<rows;i++)
    {
		board[i]=(int*)malloc(cols*sizeof(int));
        if(board==NULL)
        {
            printf("Error not available memeory\n");
            exit(EXIT_FAILURE);
        }
	}
	board2=(int**)malloc(rows*sizeof(int*));
	if(board2==NULL)
	{
		printf("Error not available memeory\n");
		exit(EXIT_FAILURE);
	}
    for(i=0;i<rows;i++)
    {
		board2[i]=(int*)malloc(cols*sizeof(int));
        if(board2==NULL)
        {
            printf("Error not available memeory\n");
            exit(EXIT_FAILURE);
        }
	}
	for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            board2[i][j]=0;
        }
    }
	printf("please select difficulty:\n");
	printf("easy=1\nmedium=2\nhard=3\nimpossible=4\n");
	scanf("%d", &dif);
	getchar();
	if ((dif<1) || (dif>4))
	{
	    printf("Invalid input: Incorrect difficulty.\nPlease try again:\n");
	    scanf("%d", &dif);
	    getchar();
	}
	printf("%d", blocks);
	do
	{   
	    if(i + 1<10)
        {
		    printf("  ");
        }
        else
        {
            printf("   ");
        }
        mameki= 5+5*dif;
        uif=cols*rows*mameki/100;
        for(i=0;i<cols;i++)
        {
            if(i + 1<10)
            {
			    printf("%d ", i + 1);
            }
            else
            {
                printf("%d", i + 1);
            }
        }
        printf("\n");
        printf("----");
        for(i=0;i<cols;i++)
        {
            printf("--");
        }
		printf("\n");
        for(i=0;i<cols;i++)
        {   
            if(i + 1 < 10)
            {
			    printf("%d |", i + 1);
            }
            else
            {
                printf("%d|", i + 1);
            }
            for(j=0;j<rows;j++)
            {
			    printf("# ");
            }
            printf("\n");
        }
        while(blocks<=rows*cols-uif)
        {
            START:
            flag=0;
            printf("\n%d blocks are open\n" ,blocks);
            printf("to open a keybind type open(x,y)\n");
            printf("to  get help type cheat(x,y)\n");
            printf("to mark a keybind type mark(x,y)\n");
            printf("to exit game type exit\n");
            printf("make your move: ");
            read_text(str, sizeof(str), 1);
            if(strncmp(str,"exit",4)==0)
            {
                exitt(board,board2);
            }
            str2[0]='o';
            str2[1]='p';
            str2[2]='e';
            str2[3]='n';
            str2[4]='\0';
            q=0;
            for(i=0;i<4;i++)
            {
                if(str[i]==str2[i])
                {
                    q++;
                }
            }
            if(q==4)
            {
                r=con(str, 4, c);
                if ((r < 1) || (r > rows)) 
                {
                    printf("Invalid input: x must be between 1 and %d.\n", rows);
                    goto START;
                }
                if ((ci < 1) || (ci > cols))
                {
                    printf("Invalid input: y must be between 1 and %d.\n", rows);
                    goto START;
                }
                if(blocks==0)
                {
                    
                    for(i=0;i<rows;i++)
                    {
                        for(j=0;j<cols;j++)   
                        {
                            board[i][j]=0;
                        }
                    }
                    while(n<uif)
                    {
                        row=0+rand()%rows;
                        col=0+rand()%cols;
                        if((board[row][col]==0) && ((r)!=row) && (ci!=col))
                        {
                            board[row][col]=69;
                            n++;
                        }
                    }
                    for (i = 0; i < rows; i++) 
                    {
                        for (j = 0; j < cols; j++) 
                        {
                            if (board[i][j] != 69) 
                            {
                                amount = 0;
                                for ( a = i - 1; a <= i + 1; a++) 
                                {
                                    for (f = j - 1; f <= j + 1; f++) 
                                    {
                                        if ((a >= 0) && (a < rows) && (f >= 0) && (f < cols) && (board[a][f] == 69)) 
                                        {
                                            amount++;
                                        }
                                    }
                                }
                                board[i][j] = amount;
                            }
                        }
                    }
                    blocks=open(ci - 1, r - 1, board, board2, rows, cols); 
                }
                else
                {
                    blocks=open(ci - 1, r - 1, board, board2, rows, cols); 
                }
                flag=1;
            }
            str3[0]='m';
            str3[1]='a';
            str3[2]='r';
            str3[3]='k';
            str3[4]='\0';
            q=0;
            for(i=0;i<4;i++)
            {
                if(str[i]==str3[i])
                {
                    q++;
                }
            }
            if(q==4)
            {
                r=con(str, 4, c);
                if ((r < 1) || (r > rows)) 
                {
                    printf("Invalid input: x must be between 1 and %d.\n", rows);
                    goto START;
                }
                if ((ci < 1) || (ci > cols))
                {
                    printf("Invalid input: y must be between 1 and %d.\n", rows);
                    goto START;
                }
                mark( ci - 1, r - 1, board, board2);
                flag=1;
            }
            str4[0]='c';
            str4[1]='h';
            str4[2]='e';
            str4[3]='a';
            str4[4]='t';
            str4[5]='\0';
            q=0;
            for(i=0;i<5;i++)
            {
                if(str[i]==str4[i])
                {
                    q++;
                }
            }
            if(q==5)
            {
                r=con(str, 5, c);
                if ((r < 1) || (r > rows)) 
                {
                    printf("Invalid input: x must be between 1 and %d.\n", rows);
                    goto START;
                }
                if ((ci < 1) || (ci > cols))
                {
                    printf("Invalid input: y must be between 1 and %d.\n", rows);
                    goto START;
                }
                cheat( board2, board, ci - 1, r - 1);
                flag=1;
            }
            if (flag==0)
            {
                printf("Invalid input: input must be in the format 'open(x,y)', 'mark(x,y)', 'cheat(x,y)', or 'exit'.\n");
                goto START;
            }
            printf("\n");
            if(i + 1<10)
            {
                printf("  ");
            }
            else
            {
                printf("   ");
            }
            for(i=0;i<cols;i++)
            {
                if(i + 1<10)
                {
                    printf("%d ", i + 1);
                }
                else
                {
                    printf("%d", i + 1);
                }
			}
			printf("\n");
            printf("----");
            for(i=0;i<cols;i++)
            {
                printf("--");
            }
            printf("\n");
            for (i=0; i<rows; i++)
            {
                if( i + 1 <10)
                {
                    printf("%d |", i + 1);
                }
                else
                {
                    printf("%d|", i + 1 );
                }
                for (j=0; j<cols; j++)
                {
                    if (board2[i][j]==1)
                    {
                        if ((board[i][j]==0) || (board[i][j]==69))
                        {
                            printf(". ");
                        }
                        else if(board[i][j]==70)
                        {
                            printf("@ ");
                        }
                        else
                        {
                            printf("%d ", board[i][j]);
                        }
                    }
                    else
                    {
                        printf("# ");
                    }
                }
                printf("\n");
            }
        }
    }while((rows<=30) && (cols<=30));
}
    

void exitt(int **board, int **board2)
{
    printf("Thank you for playing");
    free(board);
    free(board2);
    exit(EXIT_SUCCESS);
}



#include <stdlib.h>
#include <string.h>
int con(char str[], int giw, int *rgo)
{
    int i,f ;
    char x[6], y[6];
    char *a, *b, *c;
    a = strchr(str, '(');
    b = strchr(str, ',');
    c = strchr(str, ')');
    f=b-a-1;
    strncpy(x, a+1, f);
    x[f]='\0';
    f=c-b-1;
    strncpy(y, b+1, f);
    y[f]='\0';
    *rgo= atoi(x);
    i= atoi(y);
    return i;
}



#include <stdlib.h>
int open(int r, int ci, int **board, int **board2, int rows, int cols)
{
    int a, b, i, j, blocks=0;
    a=r;
    b=ci;
    if (board[a][b]==69)
    {
        printf("you were bombed(kaboom!)\n");
        exitt(board,board2);
    }
    else if (board[a][b]==70)
    {
        printf("this block is flagged, and cannot be opened. Please try another one");
    }
    else if (board[a][b]==0)
    {
        board2[a][b]=1;
        for (i = r - 1; i <= r + 1; i++)
        {
            for (j = ci - 1; j <= ci + 1; j++)
            {
                if ((i >= 0) && (i < rows) && (j >= 0) && (j < cols) && (board[i][j] != 69) && (board2[i][j]==0))
                {
                    open(i, j, board, board2, rows, cols);
                }
            }
        }
    }
    else
    {
        board2[a][b]=1;
    }
    for (i=0;i<rows;i++)
    {
        for (j=0;j<rows;j++)
        {
            if (board2[i][j]==1)
            {
                blocks++;
            }
        }
    }
    return blocks;
}

int read_text(char str[], int size, int flag)
{
    int len;
    
    if (fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed\n");
        exit(EXIT_FAILURE);
    }
    len = strlen(str);
    if(len > 0)
    {
        if(flag && (str[len-1] == '\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}



void mark(int x, int y, int **board, int **board2)
{
    if (board2[x][y]==1)
    {
        printf("this cage is already open. Please insert a cage that is not opened");
    }
    else
    {
        board[x][y]=70;
        board2[x][y]=1;
    }
}

void cheat(int **board2, int **board, int x, int y)
{
    if (board[x][y]==69)
    {
        printf("The cage has a bomb\n");
    }
    else if (board[x][y]==70)
    {
        printf("this cage is marked. Please insert a cage that is not marked");
    }
    else
    {
        printf("The cage has the number %d inside\n" ,board[x][y]);
    }
}