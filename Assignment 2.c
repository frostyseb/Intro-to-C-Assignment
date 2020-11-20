#include<stdio.h>
#include<math.h>

int test1(int,int,int,int);
int test2(int,int,int,int,char);
int minus1(int,int);
int minus1(int,int);
int diffx(int,int);
int diffy(int,int);
double hypotenuse(int,int);

void main(void){
	
int x1, y1, x2, y2;
char pattern;


printf("Coordinates X1 and Y1 : ");
scanf("%d%d", &x1, &y1);

printf("Coordinates X2 and Y2 : ");
scanf("%d%d", &x2, &y2);

if(x1<0 || y1<0 || x2<0 || y2<0)	//to test the condition whether the coordinates are positive or not
	test1(x1, y1, x2, y2);
else
	test2(x1, y1, x2, y2,pattern);
	}

/*if the coordinates entered are negative, then user is prompted to reenter again*/
int test1(int a, int b, int c, int d){
	char pattern;
	  	while(a<0 || b<0 || c<0 || d<0){	//the loop continues until four positive coordinates are entered
  	  	printf("\tReenter coordinates again!");
  	  	
  	 	printf("\nCoordinates X1 and Y1 : ");
		scanf("%d%d", &a, &b);

		printf("Coordinates X2 and Y2 : ");
		scanf("%d%d", &c, &d);
		}
  	test2(a,b,c,d,pattern);
return 0;
}
	
/*if the coordinates entered are positive at first time input, then the plotting of points begin*/
int test2(int a,int b,int c,int d,char pattern){
	printf("Pick a pattern (#,%%,^,@,$): ");
	scanf(" %c", &pattern);
	
	if(pattern!='#'  && pattern!='%' && pattern!='^' && pattern!='@' && pattern!='$'){
		printf("\nIncorrect choice!\nProgram ends here!\n");
	}
	
	else{
		if(b==d){		//if both coordinates have the same y-coordinate
			printf("%c", pattern);
			minus1(a, c);
			printf("%c", pattern);
			
			printf("\nCoordinates X1 and Y1 : ");
			scanf("%d%d", &a, &b);

			printf("Coordinates X2 and Y2 : ");
			scanf("%d%d", &c, &d);
			
			test1(a,b,c,d);
		}
		else if(a==c){		//if both coordinates have the same x-coordinate
			printf("%c", pattern);
			minus2(b, d);
			printf("%c", pattern);
			
			printf("\nCoordinates X1 and Y1 : ");
			scanf("%d%d", &a, &b);

			printf("Coordinates X2 and Y2 : ");
			scanf("%d%d", &c, &d);
			
			test1(a,b,c,d);
		}
		
		/*when coordinates do not have the same x-coordinate or y-coordinate*/
		else{		
			if(d>b){		//when y2 is larger than y1, y1 is printed first
				int i,n,t;
				for(i=0;i<a;i++)
					printf("%c", pattern);
				for(n=0;n<diffy(b,d);n++)
					printf("\n");
				for(t=0;t<c;t++)
					printf("%c", pattern);
			}
			else if(b>d){		//when y1 is larger than y2, y2 is printed first
				int i,n,t;
				for(i=0;i<c;i++)
					printf("%c", pattern);
				for(n=0;n<diffy(b,d);n++)
					printf("\n");
				for(t=0;t<a;t++)
					printf("%c", pattern);
			}
		printf("\nAt coordinates (%d,%d),(%d,%d)> Hypotenuse : %.2f", a, b, c, d, hypotenuse(diffx(a,c),diffy(b,d)));
		}
	}
	
return 0;
}

/*calculate the number of spaces needed to be printed between coordinates with the same y-coordinate*/
int minus1(int e,int f){
	int w;
	if(e>f){
		for(w=0;w<e-f;w++)
			printf(" ");
	}
	else{
		for(w=0;w<f-e;w++)
			printf(" ");
	}
	
	return 0;
}

/*calculate the number of \n needed to be printed between coordinates with the same x-coordinate*/
int minus2(int e,int f){
	int w;
	if(e>f){
		for(w=0;w<e-f;w++)
			printf("\n");
	}
	else{
		for(w=0;w<f-e;w++)
			printf("\n");
	}
	
	return 0;
}

/*calculate the difference between the two x-coordinates*/
int diffx(int a, int c){
	if(a>c)
		return a-c;
	else
		return c-a;

}

/*calculate the difference between the two y-coordinates*/
int diffy(int b, int d){
	if(b>d)
		return b-d;
	else
		return d-b;
}

/*calculate the hypotenuse*/
double hypotenuse(int diffx, int diffy){ return hypot(diffx, diffy);}
