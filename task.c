#define ALLOCSIZE 10000 //size of stack
#define uint64_t unsigned long int
#define size_t unsigned char 

static char allocbuff[ALLOCSIZE]; // real array to get memory 
static char * allocp = allocbuff;

void *my_malloc(int n)
{
	if(allocbuff + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp -n;
	}
	else
	{
		return 0;
	}
}

void my_free(void *p)
{
	if(p >= allocbuff && p < allocbuff + ALLOCSIZE)
		allocp = p;
}


size_t num_to_str(uint64_t num, char *str, size_t str_size)
{
	int count_bytes = 0;
	if(str_size <= 0)
	{
		return 1;
	}   

	for(int i = str_size-1; i >= 0; i--)
	{	
		*(str+i) = num % 10 >= 1 ?  num % 10+48 : num+48;
		count_bytes += sizeof(*(str+i));
		num = num /10;
	} 
	return count_bytes;
}

uint64_t pow(int base,int degree)  //создавалась  только для  одной функции 
{
	int base_buf =  base;
    if(degree==0)
        return 1;
	else 
		if (degree==1)
			return base;
    for(int i = 1;i < degree;i++)
	{
		base *=base_buf;
	}
    return base;
}

uint64_t len(const char *str)
{
   uint64_t length=0;
   while( *str++ != '\0')
           length+=1;
   return length;
}


uint64_t str_to_num(const char *str, size_t str_len)
{
	int degree = str_len-1;
    uint64_t number=0;
    if(len(str) < str_len)
          return 1;
    for(int i =0; i <=str_len-1;i++)
    {
		if (*(str+i) < 48 || *(str+i) > 57)
		{
			degree--;
			continue;
		}
        number += (*(str+i) - 48) * pow(10,degree);
		degree--;
    }
    return number;
}

int main(int argc, char *argv[])
{
	char* s;
	s = my_malloc(1);
	int x = str_to_num("12e3",4);
	num_to_str(3,s,1);
	return 0;
	
}
