#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define N 10000
#define M 8942

int check_A(int,int);
int check_B(int,int);
int random(int);
int delete_ary(int, int, int, int []);

int main()
 {
/*	int x;
	int testCount=0;
	for(x=0;x<N;x++){
	
*/	
	srand((unsigned)time(NULL) );
	int b[10000]={0},i,d1,d2,d3,d4,j=0,guessTimes=0;
	for(i=0;i<10000;i++){
		d1=i/1000; d2=(i/100)%10;
		d3=(i/10)%10; d4=i%10;
		if(!(d1==d2||d2==d3||d3==d4||d1==d3||d1==d4||d2==d4)){	
	        	b[j]=i;
	        	j++;
		}
	}
    

	 int guess, random_A, random_1, ans, Num_A, Num_B, sec_number, guess_times=0;
	 int first_A, first_B;	   
       random_1=random(j-1);
       guess=b[random_1];
       random_A=random(j-1);
       ans=b[random_A];
       guess_times++;
       
     first_A = check_A(ans, guess); 
     first_B = check_B(ans, guess); 
     
    
   //  ans=M; 
     	printf("這是第%d次猜, 有%d種可能, 猜%04d ,正確答案是%04d, %dA, %dB\n",guess_times, j, guess,ans, first_A, first_B);
       
 	  
   while (guess!=ans){
     	
        Num_A=check_A(ans,guess);
	    Num_B=check_B(ans,guess);
     	sec_number=delete_ary(Num_A, Num_B, guess, b );
     	random_1=random(sec_number-1);
     	guess=b[random_1];
       	guess_times++;
       	Num_A=check_A(ans,guess);
	    Num_B=check_B(ans,guess);
       	
       	
        printf("這是第%d次猜, 有%d種可能, 猜%04d ,正確答案是%04d, %dA, %dB\n",guess_times,sec_number ,guess,ans,Num_A, Num_B);
      
      }
     
   	printf("answer is %d, totol guess= %d\n", guess, guess_times );
	 
      
   //   printf("%d ,%d, %d, %d ,%d " , ans, guess, random_1, guess_times,sec_number);
      
      
  /*   
     ans=b[random_A];
     guess=b[random_1];
     guessTimes++;
     
      int c[j]={0}, c_count=0;
     
     while(ans!=guess){
	
   	 c_count=0;
	 Num_A=check_A(ans,guess);
	 Num_B=check_B(ans,guess);
	 	 
	 
	 for(i=0;i<j;i++){
	 	if((check_A(ans, b[i])==Num_A)&&(check_B(ans, b[i])==Num_B)){
	 	     c[i]=b[i];	
    
	 	     j=c_count++;
		 }
	 }
	 for(i=0;i<j;i++){
	 	b[i]=0;
	 	b[i]=c[i];
	    c[i]=0;
	 }
	 srand((unsigned)time(NULL) );	   
     random_1=(rand()%(j+1));
	 guess=b[random_1];
	 guessTimes++;
     }
	

    int a,b;
    scanf("%d",&a);
    b=check(a);
    printf("%d",b );
   
    printf("%d, %d, %d, %d\n" , ans ,random_1, b[random_1], j);
    printf("%d, %d\n", Num_A, Num_B);
    printf("%d\n", c_count);
    printf("%d\n", guessTimes); 
    

         testCount+=guess_times;
 }
         printf("執行%d次,猜中的平均次數為%d \n", N,testCount/N);
         */
      
         
	 return 0;
}

int random(int total_N){          //give random value from 0~total_N

	return (rand()%(total_N+1));
}

int delete_ary(int a, int b, int assume, int bt[] ){
	   int i, c[10000]={0}, temp=0;
	    
	for(i=0;i<10000;i++){
		if(bt[i]!=0){	
	 	if(!((check_A(assume, bt[i])==a)&&(check_B(assume, bt[i])==b))){
	 	     bt[i]=0;	
	 	 }	 	 
	   }
  }
  for(i=0;i<10000;i++){
    if(bt[i]!=0){
	    c[temp]=bt[i];
   		temp++;
    }
}
   for(i=0;i<10000;i++){
   	  bt[i]=c[i];
   }
	 return temp;
}



int check_A(int ans, int b){
	int ans_d1, ans_d2, ans_d3, ans_d4;
	int b_d1, b_d2, b_d3, b_d4;
	    ans_d1=ans/1000; ans_d2=(ans/100)%10;
		ans_d3=(ans/10)%10; ans_d4=ans%10;
		
		b_d1=b/1000; b_d2=(b/100)%10;
		b_d3=(b/10)%10; b_d4=b%10;
	int j=0;
	if(ans_d1==b_d1){
		j++;
	}if(ans_d2==b_d2){
		j++;
	}if(ans_d3==b_d3){
		j++;
	}if(ans_d4==b_d4){
		j++;
	}

	 return j;
}


int check_B(int ans, int b){
	int ans_d1, ans_d2, ans_d3, ans_d4;
	int b_d1, b_d2, b_d3, b_d4;
	    ans_d1=ans/1000; ans_d2=(ans/100)%10;
		ans_d3=(ans/10)%10; ans_d4=ans%10;
		
		b_d1=b/1000; b_d2=(b/100)%10;
		b_d3=(b/10)%10; b_d4=b%10;
	
	int j=0;
	if(ans_d1==b_d2){
		j++;
	}if(ans_d1==b_d3){
		j++;
	}if(ans_d1==b_d4){
		j++;
		
	}if(ans_d2==b_d1){
		j++;
	}if(ans_d2==b_d3){
		j++;
	}if(ans_d2==b_d4){
		j++;
		
	}if(ans_d3==b_d1){
		j++;
	}if(ans_d3==b_d2){
		j++;
	}if(ans_d3==b_d4){
		j++;
	
	
	}if(ans_d4==b_d1){
		j++;
	}if(ans_d4==b_d2){
		j++;
	}if(ans_d4==b_d3){
		j++;
	}

	 return j;
}

