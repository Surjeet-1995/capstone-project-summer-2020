#include <iobb.h> 
#include <time.h>  //Time Library   
#include <stdio.h>
#include <unistd.h> //defines miscellaneous symbolic constants and types, and declares miscellaneous functions


long int start, stop, count;

clock_t before, end;



int main(void)  
{  
  iolib_init();  
  iolib_setdir(8, 10, DigitalOut); 
  pin_low(8, 10); 
  iolib_setdir(8, 9, DigitalIn);  
  
  
  iolib_setdir(8, 12, DigitalOut); 
  pin_low(8, 12); 
  iolib_setdir(8, 11, DigitalIn); 
  
  
  printf("STARTED NEW\n");
  iolib_delay_ms(60);
  
  while(1)  
  {  
	printf("TRIGERRING US 1 \n");
    pin_high(8, 10);  
    usleep(10); 
    pin_low(8, 10);
    
    //iolib_delay_ms(1);
    while(is_low(8, 9))
    {		//printf(".");
			count+= 1;
			before = clock();
			
			if(count > 20000)
			{
				printf("Kindly Check Wiring of US 1\n");
				count = 0;
				break;
			}
			
			
	}
	
	count = 0;
	
	while(is_high(8, 9))
	{	
		//printf("_");
		count += 1;
		end = clock();
		if(count > 20000)
			{
				printf("Kindly Check Wiring of US 1 #\n");
				count = 0;
				break;
			}
			
	}
    
    clock_t difference = end - before;
    
    if( count > 0)
    {
    printf("%d    ",before);
    printf("%d    ",end);
    printf("%d    Distance 1: ",difference);
    printf("%d cm. \n",difference/30);
	}
    
    printf("\n");
    pin_low(8, 10);
    iolib_delay_ms(60);
    start = 0;
    count=0;
    
    
    printf("TRIGERRING US 2 \n");
    pin_high(8, 12);  
    usleep(10); 
    pin_low(8, 12);
    
    //iolib_delay_ms(1);
    while(is_low(8, 11))
    {		//printf(".");
			count+= 1;
			before = clock();
			
			if(count > 20000)
			{
				printf("Kindly Check Wiring of US 2\n");
				count = 0;
				break;
			}
			
			
	}
	count = 0;
	while(is_high(8, 11))
	{	
		//printf("_");
		count += 1;
		end = clock();
		if(count > 20000)
			{
				printf("Kindly Check Wiring of US 2 # \n");
				count = 0;
				break;
			}
			
	}
    
    difference = end - before;
    
    if( count > 0)
    {
    printf("%d    ",before);
    printf("%d    ",end);
    printf("%d    Distance 2: ",difference);
    printf("%d cm. \n",difference/30);
	}
    
    printf("\n");
    pin_low(8, 12);
    iolib_delay_ms(60);
    start = 0;
    count=0;
    
    iolib_delay_ms(500);
    iolib_delay_ms(500);
    
    
      
  }  
  iolib_free();  
  return(0);  
  
  
}  



