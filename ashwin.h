//revised on 15 May 2017
//basic data structures: linked list and stack operations, bubble sort on linked list
//hex and ascii conversions
//random number and random prime generation
//simple reversal (reduction) functions for rainbow tables


/*basic struct, modify as needed */
#include <stdlib.h>
#include <cstdlib>

struct test
{
    int value;
    struct test *next;
};

/*pass value and address of head and tail*/
void addToList(struct test **head, struct test **tail, int val)
{
    struct test *temp;
    if((*head)==NULL)
    {
        (*head) = malloc(sizeof(struct test));
        (*head)->value = val;
        (*head)->next = NULL;
        (*tail) = (*head);
    }
    
    else
    {  
        temp = malloc(sizeof(struct test));
        temp->value = val;
        temp->next = NULL;
        (*tail)->next = temp;
        (*tail) = temp;
    }
}

/*pass head*/
void printList(struct test *head)
{
    struct test *temp;
    if(head==NULL)
        printf("Head NULL\n");
    else
	{
        //printf("printing list\n");
    	for(temp=head;temp!=NULL;temp=temp->next)
        	printf("%d ",temp->value);
    	printf("\n");
	}
}

/*pass address of head*/
void deleteList(struct test **head)
{
    struct test *temp1, *temp2;
    temp1=(*head);
    while(temp1!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
        free(temp2);
    }
    printf("Deleted the list\n");
}

/*pass address of top pointer and value*/
void push(struct test **top, int val)
{
    struct test *temp = malloc(sizeof(struct test));
    temp->value = val;
    temp->next = (*top);
    (*top) = temp;
}

/*pass addresses of top pointer and status flag*/
int pop(struct test **top, int *flag)
{
    if((*top)==NULL)
    {
        printf("Stack empty\n");
        (*flag) = 0;
        return (*flag);
    }
    else
    {
        (*flag) = 1;
        int temp = (*top)->value;
        struct test *temp1 = (*top);
        (*top) = (*top)->next;
        free(temp1);
        return temp;
    }
}

/*pass top pointer*/
void printStack(struct test *top)
{
    struct test *temp = top;
    if(temp == NULL)
        printf("Empty stack\n");
    else
    {
        for(;temp!=NULL;temp=temp->next)
        {
            printf("%d ",temp->value);
        }
        printf("\n");
    }
}

/*pass address of top pointer*/
void deleteStack(struct test **top)
{
    if((*top) == NULL)
        printf("Empty stack\n");
    else
    {
        int status;
        //printf("Deleting stack\n");
        struct test *temp = (*top);
        while(temp!=NULL)
        {
            //prinint map1(int x)
{
    int temp = x % 62;
    int result;
    if(temp < 10)
        result = temp + 48;
    else if(temp < 36)
        result = temp + 65;
    else
        result = temp + 97;
    return result;
}

int map2(int x)
{
    int temp = x % 62;
    int result;
    if(temp < 10)
        result = 57 - temp;
    else if(temp < 36)
        result = 90 - temp;
    else
        result = 122 - temp;
    return result;
}tf("%d ",pop(&temp,&status));
            pop(&temp,&status);
        }
        //printf("\n");
    }
}

/*reads a string like "ABCD" and returns numerical ascii value*/
int ascii2hex(char buf[4])
{
    int hex = 0;
    hex += ((int) buf[3]);
    hex += ((int) buf[2]) * 0x100;
    hex += ((int) buf[1]) * 0x100*0x100;
    hex += ((int) buf[0]) * 0x100*0x100*0x100;
    return hex;
    
}

void hex2ascii(char *buf, int hex)
{
    int rem = 0x0;
    //printf("hex = %x\n",hex);
    int i = 0;
    for(i = 0; i < 8; i++)
    {
        rem = hex%(0x100);
        *(buf+3-i) = (char) rem;
        hex = hex/0x100;
        //printf("rem = %x hex = %x\n",rem,hex);
    }
}

/*swap two nodes in a linked list; pass addresses of pointers of the two nodes*/
void swapNodeValues (struct test **node1, struct test **node2)
{
    int temp = (*node1)->value;
    (*node1) -> value = (*node2) -> value;
    (*node2) -> value = temp;
}

/*pass head pointer and mode (0 for ascending and 1 for descending) - bubble sort*/

void sortList (struct test *head, int mode)
{
    
    struct test *temp = NULL;

    if(head == NULL)
        printf("Error - empty list\n");
    else
    {
        if(mode == 0)
            printf("Sorting in ascending order\n");
        else
            printf("Sorting in descending order\n");
        
        int len = 0;
        int i,j;
        for(i=0,temp=head; temp!=NULL; temp=temp->next,i++);
        len = i;
        //printf("Len = %d\n",len);
        for(i=0;i<len-1;i++)    //number of pairs to be compared
        {
            for(temp=head,j=0;j<len-i-1;j++,temp = temp->next)
            {
                if(mode == 0)
                {
                    if (temp->value > temp->next->value)
                    swapNodeValues(&temp,&temp->next);
                }
                else
                {
                    if (temp->value < temp->next->value)
                    swapNodeValues(&temp,&temp->next);
                }
            }
            
        }
      }
}

int map1(int x)
{
    int temp = x % 62;
    int result;
    if(temp < 10)
        result = temp + 48;
    else if(temp < 36)
        result = temp + 65;
    else
        result = temp + 97;
    return result;
}

int map2(int x)
{
    int temp = x % 62;
    int result;
    if(temp < 10)
        result = 57 - temp;
    else if(temp < 36)
        result = 90 - temp;
    else
        result = 122 - temp;
    return result;
}(mode == 0)
                {
                    if (temp->value > temp->next->value)
                    swapNodeValues(&temp,&temp->next);
                }
                else
                {
                    if (temp->value < temp->next->value)
                    swapNodeValues(&temp,&temp->next);
                }
            }
            
        }
    }
}

/*removes all occurences of n from a list. pass address of pointers of head and tail of the list
  returns the number of occurences of n found and removed*/
int removeFromList(struct test **head, struct test **tail, int n)
{
    struct test *temp1 = (*head), *temp2 = NULL;
    int flag = 0;
    while(temp1 != NULL)
    {
        if(temp1->value == n)
        {
            //printf("Found an instance of %d\n",n);
            //there are three cases
            /*1. if the value is found at the head*/
            flag ++;
            if(temp1 == (*head))
            {
                (*head) = temp1->next;
                free(temp1);
                temp1 = (*head);
                
                
            }
            /*2. if the value is found at the tail*/
            else if(temp1 == (*tail))
            {
                free(temp1);
                (*tail) = temp2;
                temp2->next = NULL;
            }
            /*3. if the value is found somewhere inside the list*/
            else
            {
                temp2 ->next = temp1->next;
                free(temp1);
            }
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    return flag;
}

/*inserts a value into a list at a defined position (starts counting position from 0). returns 1 if successful*/
int insertInList(struct test **head, struct test **tail, int n, int position)
{
    int flag = 0;
    int len;
    struct test *temp;
    struct test *temp2 = malloc(sizeof(struct test));
    temp2->value = n;

    /*case 1: insert at head*/
    if(position == 0)
    {
        printf("insert at head\n");
        temp2->next = (*head);
        (*head) = temp2;
        return 1;
    }

    for(len = 0, temp = (*head);temp != NULL; temp = temp->next, len++);
    //printf("Length = %d\n",len);

    if(position > len)
    {
        printf("Invalid position\n");
        return flag;
    }

    /*case 2: insert at tail*/
    if(position == len)
    {
        printf("insert at tail\n");
        (*tail)->next = temp2;
        temp2->next = NULL;
        (*tail) = temp2;
        
        return 1;
    }
    
    /*case 3: insert somewhere in the list*/
    temp = (*head);
    for(int i=0;i<position-1 ; i++)    //traverse to the position
    {
        temp = temp->next;
    }
    
    //now create the new links
    printf("insert inside list\n");
    temp2->next = temp->next;
    temp->next = temp2;
    return 1;
}

/*Generates a random number in the specified range*/
int randInRange(int min, int max)
{
    return min + rand() % (max+1 - min);
}

/*Checks if a number is prime*/
int isPrime (int n)
{
    int i;
    int flag = 0;
    for(i=2;i<n/2;i++)
    {
        if(n%i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
        return 1;
    else
        return 0;
}

/*Generates a random prime number in the specified range*/
int randPrimeInRange(int min, int max)
{
    int flag = 0;
    int counter = 0;
    int random;
    while(1)
    {
        random = randInRange(min,max);
        if(isPrime(random)==1)
        {
            flag = 1;
            break;
        }
        counter++;
        if(counter >= 30000)
            break;
    }
    if(flag)
        return random;
    else
        return 0;
}

/*Rev1 - a simple reversal (reduction) function for rainbow tables. It maps takes modulo 62 of a hex number (hash) and maps it to
  an alphabet or a number. Please also use map1() with this.*/

int rev1(int hex)
{
    int temp1 = hex;
    int rem = 0;
    int result = 0;
    rem = temp1 % 100;
    temp1 /= 100;
    result += map1(rem);

    rem = temp1 % 100;
    temp1 /= 100;
    result += 100 * map1(rem);

    rem = temp1 % 100;
    temp1 /= 100;
    result += 100 * 100 * map1(rem);

    rem = temp1 % 100;
    temp1 /= 100;
    result += 100 * 100 * 100 * map1(rem);

    return result;
}
/*map1() - maps a number (from 0 to 61) to a number or an alphabet. please refer to an ASCII table. http://www.asciitable.com/
 0-9   --> numerical 0-9
 10-35 --> alphabets A-Z
 36-61 --> alphabets a-z
*/
int map1(int x)
{
    int temp = x % 62;
    int result;
    if(temp < 10)
        result = temp + 48;
    else if(temp >= 10 && temp < 36)
        result = temp + 65;
    else
        result = temp + 97;
    return result;
}

/*Rev2 - a simple reversal (reduction) function for rainbow tables. It maps takes modulo 62 of a hex number (hash) and maps it to
  an alphabet or a number. Please also use map2() with this.*/
int rev2(int hex)
{
    int temp1 = hex;
    int rem = 0;
    int result = 0;
    rem = temp1 % 100;
    temp1 /= 100;
    result += map2(rem);

    rem = temp1 % 100;
    temp1 /= 100;
    result += 100 * map2(rem);

    rem = temp1 % 100;
    temp1 /= 100;
    result += 100 * 100 * map2(rem);

    rem = temp1 % 100;
    temp1 /= 100;
    result += 100 * 100 * 100 * map1(rem);

    return result;
}

/*map2() - maps a number (from 0 to 61) to a number or an alphabet. please refer to an ASCII table. http://www.asciitable.com/
 0-9   --> numerical 9-0
 10-35 --> alphabets Z-A
 36-61 --> alphabets z-a
*/
int map2(int x)
{
    int temp = x % 62;
    int result;
    if(temp < 10)
        result = 57 - temp;
    else if(temp < 36)
        result = 90 - temp;
    else
        result = 122 - temp;
    return result;
}
