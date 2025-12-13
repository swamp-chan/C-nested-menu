
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define author "Sambeed Shrestha"

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
void execute_funcion(program_function r); 
void main_loop(Menu_Item *menu);

Menu_Item *finditem(Menu_Item *menu, int opt){
	for(int i = 0; menu[i].id!=0;i++){
		if(menu[i].id == opt){
			return &menu[i];
		}
		if((menu[i+1].type == QUIT || menu[i+1].type == RETURN) && menu[i+1].id == opt){
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
	printf("Enter the value of radius: ",r);
	scanf("%f",&r);
	area = 3.14*r*r;
	cir = 2*3.14*r;
	printf("The area = %.2f and circumference = %.2f", area,cir);
}

void square_n_cube(){
	float n;
	printf("Enter number: ");
	scanf("%f",&n);
	printf("square root: %.2f\ncuberoot: %.2f",sqrt(n),cbrt(n));
}

void SI_amount(){
	float p,t,r,SI,am;
	printf("Enter (p,t,r): ");
	scanf("%f,%f,%f",&p,&t,&r);
	SI = (p*t*r)/100;
	am = p+SI;
	printf("SI = %.2f\nAmount = %.2f",SI,am);
}

void centigrade_to_f(){
	float c,f;
	printf("Enter temperature in Centigrade: ");
	scanf("%f",&c);
	f = 1.8*c+32;
	printf("\nThe temperature in Farenheit: %.2f",f);
}

void displacement(){
	float s,u,a,t;
	printf("Enter u,a,t: ");
	scanf("%f,%f,%f",&u,&a,&t);
	s = u*t + 0.5*a*t*t;
	printf("\nDisplacement: %.2f",s);
}

void TSA_cuboid(){
	float l,b,h,TSA;
	printf("Enter length, breadth, and height: ");
	scanf("%f,%f,%f",&l,&b,&h);
	TSA = 2*(l*b+b*h+l*h);
	printf("The TSA = %.2f",TSA);
}

void km_meter_sum(){
	int km1,m1,km2,m2,km3,m3;
	printf("Enter distance 1(km1,m1): ");
	scanf("%d,%d",&km1,&m1);
	printf("\nEnter distance 2(km2,m2): ");
	scanf("%d,%d",&km2,&m2);
	km3 = km1+km2+(m1+m2)/1000;
	m3 = (m1+m2)%1000;
	printf("\nThe sum of the distances: %dkm and %dm",km3,m3);
}

void final_velocity(){
	float v,u,a,s;
	printf("Enter the values of u,a,s: ");
	scanf("%f,%f,%f",&u,&a,&s);
	v = sqrt(u + 2*a*s);
	printf("The value of v = %.2f",v);
}

void total_seconds(){
	int total_s,sec,min,hr;
	printf("Enter the total seconds: ");
	scanf("%d",&total_s);
	hr = total_s/3600;
	min = (total_s/60)%60;
	sec = (total_s%60);
	printf("%dhr %dmin and %dsec",hr,min,sec);
}

void string_io(){
	char name[16],address[16];
	int grade;
	printf("Enter your name: ");
	scanf("%s",name);
	fflush(stdin);
	printf("Enter address: ");
	gets(address);
	printf("Enter grade: ");
	scanf("%d",&grade);
	printf("\n%s is your name and you live in %s studying in %d",name,address,grade);
}

//labwork 2
void odd_even(){
	printf("Enter number: ");
	int n;
	scanf("%d",&n);
	if(n%2 == 0){
		printf("The number is even");
	}
	else
	{
		printf("The number is odd");
	}
}

void age_eligible(){
	int age;
	printf("Input age: ");
	scanf("%d",&age);
	if(age>=18){
		printf("This person is eligible to vote");
	}
	else{
		printf("This person is not eligible to vote");
	}
}

void positive_negative(){
	int n;
	printf("Input number ");
	scanf("%d",&n);
	if(n>0){
		printf("The number is postive");
	}
	else if(n<0)
	{
		printf("The number is negative");
	}
	else{
		printf("The number is 0");
	}
}

void greater_number(){
	int a,b;
	printf("Enter two numbers a,b: ");
	scanf("%d,%d",&a,&b);
	if(a>b){
		printf("\n%d is the greater number",a);
	}
	else if(a<b){
		printf("\n%d is the greater number",b);
	}
	else{
		printf("They are equal numbers");
	}
}

void middle_number(){
	int a,b,c;
	printf("Enter three numbers: a,b,c: ");
	scanf("%d,%d,%d",&a,&b,&c);
	if((a>b && a<c) || (a<b && a>c)){
		printf("%d is the middle number",a);
	}
	else if((b>a && b<c) || ((b<a) && (b>c))){
		printf("%d is the middle number",b);
	}
	else if((c>a && c<b) || (c<a && c>b)){
		printf("%d is the middle number",c);
	}
	else{
		printf("Equal numbers");
	}
}

void five_subject(){
	int s[5],total;
	float per;
	printf("Enter marks of 5 subjects: \n");
	for(int i = 0; i<5; i++){
		scanf("%d",&s[i]);
		total += s[i];
	}
	
	int failed = 0;
	
	per = (total/500.0)*100.0;
	printf("%.2f PERCENTAGE",per);
	for(int i = 0; i<5; i++){
		if(s[i]<35){
			failed = 1;
		}
	}
	printf("\n");
	if(failed){
		printf("FAILED");
	}
	else if(per>=85){
		printf("FIRST DIVISION");
	}
	else if(per>=75){
		printf("SECOND DIVISION");
	}
	else if(per>=50){
		printf("THIRD DIVISION");
	}
	else if(per>=30){
		printf("FOURTH DIVISION");
	}
	else{
		printf("LAST DIVISION");
	}
}

void profit_loss(){
	int dif,SP,CP;
	printf("Enter SP and CP: ");
	scanf("%d,%d",&SP,&CP);
	dif = CP-SP;
	if(dif>0){
		printf("%d profit",dif);
	}
	else if(dif<0){
		printf("%d loss",-dif);
	}
	else{
		printf("neither loss nor gain");
	}
}

void quadratic_roots(){
	float det,a,b,c,x1,x2;
	float real,imag;
	printf("Enter the value of a,b,c: ");
	scanf("%f,%f,%f",&a,&b,&c);
	det = b*b - 4*a*c;
	if(det>=0){
		x1 = (-b + sqrt(det))/2*a;
		x2 = (-b - sqrt(det))/2*a;
		printf("x = %.2f,%.2f",x1,x2);
	}
	else if(det<0){
		real = (-b/2*a);
		imag = sqrt(-det)/2*a;
		printf("x = %.2f+%.2fi,%.2f-%.2fi",real,imag,real,imag);
	}
}

void electricity_charge(){
	float t_cost, units;
	printf("Enter the electricity consumed: ");
	scanf("%f",&units);
	//if(units<20)
	float cost_80 = 0, cost_100 = 0, cost_101 = 0;
	if(units<=20){
	 	cost_80 = (units/20.0)*80.0;
	}
	else if(units<100){
		cost_80 = (units/20.0)*80.0;
		cost_100 = (units-20.0)*7.26;

	}
	else{
		cost_80 = (units/20.0)*80.0;
		cost_100 = (units-20.0)*7.26;
		cost_101 = (units-120.0)*9.5;
	}
	t_cost = cost_80 + cost_100+cost_101;
	printf("Total cost = %.2f",t_cost);
}

void three_equal(){
	int a,b,c;
	printf("Enter three numbers: ");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a == b){
		if(a == c){
			printf("equal numbers");
		}
		else{
			printf("Not equal numbers");
		}
	}
	else if (b == c){
		if(a == b){
			printf("equal numbers");
		}
		else{
			printf("Not equal numbers");
		}
	}
	else{
		printf("Not equal numbers");
	}
}

void choice(){
	int a,b,choice,result;
	printf("Enter two numbers: ");
	scanf("%d,%d",&a,&b);
	printf("\nInput choice: \n1. SUM\n2. PRODUCT\n3. DIFFERENCE\n5. DIVISION");
	scanf("%d",&choice);
	if(choice == 1){
		result = a+b;
	}
	else if(choice == 2){
		result = a*b;
	}
	else if(choice == 3){
		result = a-b;
	}
	else if(choice == 4){
		result = a/b;
	}
	else{
		printf("Enter proper choice");
		return;
	}
	printf("The result = %d",result);
}
//menu's and menu items
Menu_Item labwork1[] = {
	{1, "Find the sum and average of three numbers", program,{.pfunction = l1_sumandaverage}},
	{2, "Area and circum of circle",program,{.pfunction = l1_area_circumference_circle}},
	{3, "Find the square and cube root",program,{.pfunction = square_n_cube}},
	{4, "Find the SI and net amount",program,{.pfunction = SI_amount}},
	{5, "Centigrade to Farenheit",program,{.pfunction = centigrade_to_f}},
	{6, "Calclate displacement",program,{.pfunction = displacement}},
	{7, "TSA of a cuboid",program,{.pfunction = TSA_cuboid}},
	{8, "Sum of distances(km and m)",program,{.pfunction = km_meter_sum}},
	{9, "Find v",program,{.pfunction = final_velocity}},
	{10,"Convert total seconds to hr,min,s",program,{.pfunction = total_seconds}},
	{11, "String input and output",program,{.pfunction = string_io}},
	{0, "Return",RETURN,{.pfunction = NULL}}
};

Menu_Item labwork2[] = {
	{1,"Odd or even",program,{.pfunction = odd_even}},
	{2,"Check eligibility of age",program,{.pfunction = age_eligible}},
	{3,"Check if number is positive or negativek"},
	{4,"Print the greatest number",program,{.pfunction = greater_number}},
	{5,"Print the middle number",program,{.pfunction = middle_number}},
	{6,"Five subjects",program,{.pfunction = five_subject}},
	{7,"Print profit and loss",program,{.pfunction = profit_loss}},
	{8,"Quadratic roots",program,{.pfunction = quadratic_roots}},
	{9,"Calculate the electric bill",program,{.pfunction = electricity_charge}},
	{10,"Check if three numbers are equal",program,{.pfunction = three_equal}},
	{11,"Menu drive program",program,{.pfunction = choice}},
	{0, "Return",RETURN,{.pfunction = NULL}}
};

Menu_Item labwork3[] = {
	{1, "something",program},
	{0, "Return",RETURN,{.pfunction = NULL}}
};

Menu_Item labwork4[] = {
	{1, "something",program},
	{0, "Return",RETURN,{.pfunction = NULL}}
};

Menu_Item main_menu[] = {
	{1, "Labwork 1",sub_menu,{.submenu = labwork1}},
	{2, "Labwork 2",sub_menu,{.submenu = labwork2}},
	{3, "Labwork 3",sub_menu,{.submenu = labwork3}},
	{4, "Labwork 4",sub_menu,{.submenu = labwork4}},
	{0, "Quit Program.",QUIT,{.submenu = NULL}}
};



int main(){
	main_loop(main_menu);
	return 0;
}

void pre_function(){
	system("cls");
	printf("AUTHOR NAME: %s\n",author);
}

void post_function(){
	printf("\n\n\nPress Enter to return to the submenu...");
	while(getchar() != '\n');
	getchar();
}

void pre_menu(){
	system("cls");
	printf("---MENU---.\nPlease pick which labwork you want to view:\n\n");
}

void execute_funcion(program_function running_program){
	pre_function();
	running_program();
	post_function();
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
				printf("%d. %s\n",curr_menu[i+1].id,curr_menu[i+1].title);
			}
		}	
		printf("\n");
}

