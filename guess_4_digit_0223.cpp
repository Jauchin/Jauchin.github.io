#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int );        //give random value from 0~total_N
int check_A(int,int);
int check_B(int,int);
int delete_ary(int, int, int, int []);

int main(){
	
	srand((unsigned)time(NULL) );
	
    int guessInput, flagGuessIuput=1;
    printf("請輸入要給電腦猜的4位數字: ");
    scanf("%d", &guessInput);
    
    int b[10000]={0},i,d1,d2,d3,d4,j=0,guessTimes=0;
	for(i=0;i<10000;i++){
		d1=i/1000; d2=(i/100)%10;
		d3=(i/10)%10; d4=i%10;
		if(!(d1==d2||d2==d3||d3==d4||d1==d3||d1==d4||d2==d4)){	
	        	b[j]=i;
	        	j++;
		}
	}
		for(i=0;i<j;i++){
			if(b[i]==guessInput){
			flagGuessIuput=0;
			break;	
			}
    	}
	while(flagGuessIuput){
	 printf("請輸入不重複的4位數字 : ");
	 scanf("%d", &guessInput);
	 for(i=0;i<j;i++){
			if(b[i]==guessInput){
			flagGuessIuput=0;
			break;	
			}
    	}	 
    }
    
    int guess, random_1, guess_times=0;		   
       random_1=random(j-1);
       guess=b[random_1];
    //   random_A=random(j-1);
    //   ans=b[random_A];
       guess_times++;
       
    int inputNumberA, inputNumberB,testA, testB;  
	while (guess!=guessInput){
		int flagA=1, flagB=1;  
		testA = check_A(guessInput, guess); 
        testB = check_B(guessInput, guess); 
     	printf("這是電腦第 %d 次猜 %04d, 目前有%d 種可能性, 請反饋電腦多少A多少B\n", guess_times, guess, j );
        printf("幾A: ");        
        while(flagA){
        	scanf("%d", &inputNumberA);
        	if(inputNumberA==testA){
        		flagA=0;        		
			}else{
				printf("輸入錯誤,電腦幫你輸入%d\n",testA);
				inputNumberA=testA;
				flagA=0;  
			}
		}
        printf("幾B: ");
        while(flagB){
        	scanf("%d", &inputNumberB);
        	if(inputNumberB==testB){
        		flagB=0;        		
			}else{
				printf("輸入錯誤,電腦幫你輸入%d\n", testB);
				inputNumberB=testB;
				flagB=0;  
			}
		}
        j=delete_ary(inputNumberA, inputNumberB, guess, b );
     	random_1=random(j-1);
     	guess=b[random_1];
       	guess_times++;
            
      }
      
      printf("這是電腦第 %d 次猜 %04d, 目前有%d 種可能性, 答案是: %d,總共猜了%d 次: \n", guess_times, guess, j,guess,guess_times );
	   
	  printf("答案是: %d, 總共猜了幾次: %d\n", guess, guess_times ); 
	

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


