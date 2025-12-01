#include <stdio.h>
#include <stdlib.h>

#define author "NAME"

typedef void (*program_function)();

typedef enum{
	RETURN,
	sub_menu,
	program,
}itemtype;

typedef struct{
	int id;
	char *title;
	itemtype type;
	union{
		program_function pfunction;
		struct Menu_Item *submenu;
	}action;
}Menu_Item;

void pre_function();
void post_function();
void execute_funcion(program_function running_program){
	pre_function();
	running_program();
	post_function();
}

//main question functions
//Labwork 1
void l1_sumandaverage(){
	float sum,avg a,b,c;
	printf("Enter three numbers(a,b,c): ");
	scanf("%f,%f,%f",&a,&b,&c);
	sum = a+b+c;
	avg = sum/3;
	printf("The sum = %.2f and average = %.2f",sum,avg);
}

void l1_area_circumference_circle(){
	float r,area,cir;
	printf("Enter the value of radius: ",&r);
	scanf("%f",r);
	area = 3.14*r*r;
	cir = 2*3.14*r;
	printf("The area = %.2f and circumference = %.2f", area,cir);
}


//menu items
//
int main(){
	getchar();
	return 0;
}

void pre_function(){
	system("cls");
	printf("%s\n",author);
}

void post_function(){
	printf("\n\nPress Enter to return to the submenu...");
	while(getchar() != '\n');
	getchar();
}
