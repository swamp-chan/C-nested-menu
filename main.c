#include <stdio.h>
#include <stdlib.h>

#define author "NAME"

typedef void (*program_function)();

typedef enum{
	RETURN,
	sub_menu,
	program,
	QUIT,
}itemtype;

typedef struct Menu_Item_tag{
	int id;
	char *title;
	itemtype type;
	union{
		program_function pfunction;
		struct Menu_Item_tag *submenu;
	}action;
}Menu_Item;

void pre_menu();
void pre_function();
void post_function();
void print_menu(Menu_Item *a);
void execute_funcion(program_function running_program){
	pre_function();
	running_program();
	post_function();
}
void main_loop(Menu_Item *menu);

Menu_Item *finditem(Menu_Item *menu, int opt){
	for(int i = 0; menu[i].id!=0;i++){
		if(menu[i].id == opt){
			return &menu[i];
		}
		if(menu[i+1].type == QUIT || menu[i+1].type == RETURN){
			return &menu[i+1];
		}
	}
	return NULL;
}


//main question functions
//Labwork 1
void l1_sumandaverage(){
	float sum,avg,a,b,c;
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
Menu_Item labwork1[] = {
	{1, "Find the sum and average of three numbers", program, .action = {.pfunction = l1_sumandaverage}},
	{0, "Return",RETURN,.action = {.pfunction = NULL}}
};

Menu_Item main_menu[] = {
	{1, "Labwork 1",sub_menu,.action = {.submenu = labwork1}},
	{0, "Quit Program.",QUIT,.action = {.submenu = NULL}}
};



int main(){
	main_loop(main_menu);
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

void pre_menu(){
	system("cls");
	printf("---MENU---.\nPlease pick which labwork you want to view:\n\n");
}

void main_loop(Menu_Item *curr_menu){
	int opt;
	Menu_Item *selected_obj;
	do{
		pre_menu();
		print_menu(curr_menu);
		printf("\nEnter option: ");
		scanf("%d",&opt);

		selected_obj = finditem(curr_menu, opt);

		if(selected_obj == NULL){
			system("cls");
			printf("\nINVALID SELECTION!!");
			while(getchar()!='\n');
			getchar();
		}
		else{
			switch(selected_obj->type){
				case program:
					execute_funcion(selected_obj->action.pfunction);
					break;
				case sub_menu:
					main_loop(selected_obj->action.submenu);
					break;
				case RETURN:
					return;
					break;
				case QUIT:
					exit(0);
					break;
			}
		}

	}while(1);
}

void print_menu(Menu_Item *curr_menu){
		for(int i = 0; curr_menu[i].id != 0; i++){
			printf("%d. %s\n",curr_menu[i].id,curr_menu[i].title);
			if(curr_menu[i+1].type == RETURN || curr_menu[i+1].type == QUIT){
				printf("%d. %s\n",curr_menu[i+1],curr_menu[i+1].title);
			}
		}	
		printf("\n");
}
