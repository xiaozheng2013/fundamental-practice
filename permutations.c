//print out all permutations of an array.
#include<stdio.h>
#define L 6
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void per_print(char* a,int i, int j)
{
	if(i==j) 
	 printf("%s\n",a);
	else{
	int k;
	for(k=i;k<=j;k++)
	{
		swap((a+i),(a+k));
		//char tmp = *a;
		//*a = *(a+i);
		//*(a+i) = tmp;
		per_print(a,i+1,j);
		swap((a+k),(a+i));
	}
	}

}

int main()
{
//	char *a = "abcdef";// bus error
	char a[] = "abcdef";
	
	per_print(a,0,5);
	return 0;
}

