/*Team 3 : 
	Member team 
	1. Pal Chev
	2. Ourng Limeng
	3. Lay Uodom
	4. Nan Sokheang
	5. Meas Net
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
struct Employee{
	int id;
	char firstname[20];
	char lastname[20];
	char fullname[30];
	char sex;
	char birthday[30];
	float salary;
}Em[10],em[10],temp;
int n;
int i,j,t=5,r=5;
float netSalary[10],temp1;
void updatetable(struct Employee em);
void gotoxy1(int n);
void rectangle(int l,int j);
void rectangle1(int l,int j);
void rectangle2(int l,int j);
void rectangle3(int l,int j);
void backgroundred(){
	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                           FOREGROUND_INTENSITY | 
                                                            BACKGROUND_RED
                          );
}
void backgroundgreen(){
	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                           FOREGROUND_INTENSITY | 
                                                            BACKGROUND_GREEN
                          );
}
void white(){
	printf("\033[0;37m");
}
void red(){
  printf("\033[1;31m");
}
void yellow(){
  printf("\033[1;33m");
}
void purple(){
	printf("\033[0;35m");
}
void blue(){
	printf("\033[0;34m");
}
void green(){
	printf("\033[0;32m");
}
void listemployee(int r);
void table();
void tablesort();
void H_line(int x, int y, int n);
void gotoxy(short x, short y);
void findnetsalary();
void Deleting();
void fullname();
void AddEmployee();
void savetofile();
void loading();
void main(){
	short x,y;
    system("cls");
	printf("\n%c Enter the number of employees : ", 5);
	fflush(stdin);	againn:	scanf("%d", &n);	system("cls");
	if(n>10){
		blue();	printf("%c ",30);
		red();	printf("\aYou can not enter more than 10 employees.\n");	white();
		printf("\nEnter again: ");
		rectangle1(13,1);
		gotoxy(17,2);	white();	goto againn;
	}
	else{
		for(i=0;i<n;i++){
			green();	rectangle(1,0);	gotoxy(3,1);	purple();	printf(" %c  Employee #%d ", 2,(i+1));	white();
			fflush(stdin);
			printf("\n\n%c Enter ID : ", 16);	again1:	scanf("%d", &Em[i].id);
			for(j=1;j<=n;j++){
				if(Em[i].id==Em[i-j].id){
					red();	printf("This ID is the ID of the employee #%d, please enter a different ID.\n",i-j+1);
					white();	printf("\a%c Input another ID: ", 16);
					goto again1;
				}
			}
			fflush(stdin);
			printf("%c Enter Firstname : ", 16);	gets(Em[i].firstname);
			fflush(stdin);
			printf("%c Enter Lastname : ", 16);	gets(Em[i].lastname);
			printf("%c Enter Sex : ", 16);	scanf("%c", &Em[i].sex);
			fflush(stdin);
			printf("%c Enter Birthday : ", 16);	gets(Em[i].birthday);
			fflush(stdin);
			printf("%c Enter Salary (KHR) : ", 16);	scanf("%f", &Em[i].salary);
			system("cls");
		}
		savetofile();
		loading();
		table();
		fullname();
		int m;
		char sid,idnotfound,yn;
		int s_id,ch;
		char fullnamefors[30];
		printf("\n\n%c Do you want to update employee's information?", 254); 
		purple();
		rectangle1(1,7+2*n);	
		gotoxy(2,8+2*n);	green();	printf("Yes = Y,y");
		gotoxy(13,8+2*n);	white();	printf("OR");	purple();
		rectangle1(16,7+2*n);	
		gotoxy(17,8+2*n);	red();	printf(" No = N,n");	white();
		printf("\n\n%c Input : ", 26);	ny1:	fflush(stdin);	scanf("%c", &yn);
		if(yn=='Y' || yn=='y'){
			again6:
			system("cls");
			table();
			gotoxy(1,5+2*n);	printf("%c Do you want to search employee's ID or employee's name for update", 254);
			blue();	rectangle2(1,6+2*n);
			gotoxy(2,7+2*n);	white();	printf("Press 1 for search by ID");
			blue();	rectangle2(31,6+2*n);
			gotoxy(32,7+2*n);	white();	printf("Press 2 for search by Name");	white();
		//	fflush(stdin);
			printf("\n\n%c Input : ", 26);
			input2:	fflush(stdin);	scanf("%d", &ch);
			system("cls");
			switch(ch){
				case 1:
					table();
					printf("\n\n%c Enter ID of employee that you want to find : ", 6);
					rectangle1(47,5+2*n);	white();
					gotoxy(48,6+2*n);	again:	fflush(stdin);	scanf("%d", &s_id);
					system("cls");
					for(i=0;i<n;i++){
						if(Em[i].id==s_id){
							updatetable(Em[i]);
							gotoxy(38,7);	
							printf("%c Choose your option for update\n", 16);
							green();
							rectangle(20,9);
							rectangle(43,9);
							rectangle(66,9);
							rectangle(31,12);
							rectangle(54,12);
							rectangle(42,15);
							white();
							gotoxy(22,10);	printf("1 %c Firstname\n", 26);
							gotoxy(45,10);	printf("2 %c Lastname\n", 26);
							gotoxy(68,10);	printf("3 %c Sex\n", 26);
							gotoxy(33,13);	printf("4 %c Birthday\n", 26);
							gotoxy(56,13);	printf("5 %c Salary\n", 26);
							gotoxy(44,16);	printf("6 %c All information\n", 26);
							gotoxy(44,18);	printf("Input : ");
							number:	fflush(stdin);	scanf("%d", &m);
							white();
							switch(m){
								case 1:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Firstname : ");	gets(Em[i].firstname);
									break;
								case 2:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Lastname : ");	gets(Em[i].lastname);
									break;
								case 3:
									fflush(stdin);
									gotoxy(42,20);	printf("Enter new Sex : ");	scanf("%c", &Em[i].sex);
									break;
								case 4:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Birthday : ");	gets(Em[i].birthday);
									break;
								case 5:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Salary : ");	scanf("%f", &Em[i].salary);
									break;
								case 6:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Firstname : ");	gets(Em[i].firstname);
									fflush(stdin);
									gotoxy(39,21);	printf("Enter new Lastname : ");	gets(Em[i].lastname);
									gotoxy(39,22);	printf("Enter new Sex : ");	scanf("%c", &Em[i].sex);
									fflush(stdin);
									gotoxy(39,23);	printf("Enter new Birthday : ");	gets(Em[i].birthday);
									fflush(stdin);
									gotoxy(39,24);	printf("Enter new salary : ");	scanf("%f", &Em[i].salary);
									break;
								default:
									gotoxy(44,19);	red(); printf("Input again : ");	white();
									gotoxy(58,19);	goto number;
							}
							system("cls");
							idnotfound='t';
							break;
						}
						else{
							idnotfound='f';
						}
					}
					if(idnotfound=='f'){
						table();	
						printf("\a\n                                              ");	backgroundred();	printf("ID not found!!!\n\n");
						gotoxy(2,7+2*n); white();	printf("Please input ID again: ");	rectangle1(25,6+2*n);
						gotoxy(26,7+2*n);	white();	goto again;
					}
					table();
					for(i=0;i<n;i++){
						fflush(stdin);
						printf("\n                                           ");	backgroundgreen();	printf("Update Successfully.");
						white();	printf("\n\n%c Do you want to find other employees for Update?", 16);	
						rectangle1(1,8+2*n);	
						gotoxy(2,9+2*n);	green();	printf("Yes = Y,y");
						gotoxy(13,9+2*n);	yellow(); printf("OR");
						rectangle1(16,8+2*n);	
						gotoxy(17,9+2*n);	red();	printf(" No = N,n");	white();
						printf("\n\nInput : ");
						input:	fflush(stdin);	scanf("%c", &sid);
						system("cls");
						if(sid=='Y' || sid=='y' ){
							fullname();
							goto again6;
						}
						else if(sid=='N' || sid=='n' ){
							table();
						}
						else{
							system("cls");	table();
							red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	white();
							printf("%c Input again: ", 16);
							goto input;
						}
					}
					break;
				case 2:
					system("cls");
					table();
					printf("\n\n%c Enter Name of employee that you want to find : ", 16);	
					blue();	rectangle(50,5+2*n);	white();
					gotoxy(51,6+2*n);	again4:	fflush(stdin);	white();	gets(fullnamefors);
					system("cls");
					for(i=0;i<n;i++){
						if(strcmp(fullnamefors,Em[i].fullname)==0){
							updatetable(Em[i]);
							fflush(stdin);
							gotoxy(38,7);	printf("%c Choose your option for update\n", 16);
							green();
							rectangle(20,9);
							rectangle(43,9);
							rectangle(66,9);
							rectangle(31,12);
							rectangle(54,12);
							rectangle(42,15);
							white();
							gotoxy(22,10);	printf("1 %c Firstname\n", 26);
							gotoxy(45,10);	printf("2 %c Lastname\n", 26);
							gotoxy(68,10);	printf("3 %c Sex\n", 26);
							gotoxy(33,13);	printf("4 %c Birthday\n", 26);
							gotoxy(56,13);	printf("5 %c Salary\n", 26);
							gotoxy(44,16);	printf("6 %c All information\n", 26);
							gotoxy(44,18);	printf("Input : ");
							number1:	fflush(stdin);	scanf("%d", &m);
							white();
							switch(m){
								case 1:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Firstname : ");	gets(Em[i].firstname);
									break;
								case 2:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Lastname : ");	gets(Em[i].lastname);
									break;
								case 3:
									fflush(stdin);
									gotoxy(42,20);	printf("Enter new Sex : ");	scanf("%c", &Em[i].sex);
									break;
								case 4:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Birthday : ");	gets(Em[i].birthday);
									break;
								case 5:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Salary : ");	scanf("%f", &Em[i].salary);
									break;
								case 6:
									fflush(stdin);
									gotoxy(39,20);	printf("Enter new Firstname : ");	gets(Em[i].firstname);
									fflush(stdin);
									gotoxy(39,21);	printf("Enter new Lastname : ");	gets(Em[i].lastname);
									gotoxy(39,22);	printf("Enter new Sex : ");	scanf("%c", &Em[i].sex);
									fflush(stdin);
									gotoxy(39,23);	printf("Enter new Birthday : ");	gets(Em[i].birthday);
									fflush(stdin);
									gotoxy(39,24);	printf("Enter new salary : ");	scanf("%f", &Em[i].salary);
									break;
								default:
									gotoxy(44,19);	red();	printf("Input again : ");	white();
									gotoxy(58,19);	goto number1;
							}
							system("cls");
							idnotfound='t';
							break;
						}
						else{
							idnotfound='f';
						}
					}
					if(idnotfound=='f'){
						system("cls");
						table();	
						printf("\a\n                                              ");	backgroundred();	printf("Name not found!!\n\n");	white();	
						printf("Enter Name again: ");
						green();	rectangle2(19,6+2*n);	
						gotoxy(20,7+2*n);	goto again4;
					}
					table();
					for(i=0;i<n;i++){
						fflush(stdin);
						printf("\n                                           ");	backgroundgreen();	printf("Update Successfully.");
						white();	printf("\n\n%c Do you want to find other employees for Update?",16);	
						rectangle1(1,8+2*n);	
						gotoxy(2,9+2*n);	green();	printf("Yes = Y,y");
						gotoxy(13,9+2*n);	yellow(); printf("OR");
						rectangle1(16,8+2*n);	
						gotoxy(17,9+2*n);	red();	printf(" No = N,n"); white();
						printf("\n\nInput : ");	
						input3:	fflush(stdin);	scanf("%c", &sid);
						system("cls");
						if(sid=='Y' || sid=='y' ){
							fullname(); 
							goto again6;
						}
						else if(sid=='N' || sid=='n' ){
							table();
						}
						else{
							system("cls");	table();
							red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	white();
							printf("%c Input again: ", 16);
							goto input3;
						}
					}
					break;
				default:
					system("cls");	table();
					red();	printf("\a\n\nWe can not accept any number, except 1 and 2 \n");	white();
					printf("%c Input again: ", 16);
					goto input2;
			}
		}
		else if(yn=='N' || yn=='n'){
			system("cls");
			table();
		}
		else{
			system("cls");	table();
			red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	white();
			printf("%c Input again: ", 16);
			goto ny1;
		}
		savetofile();
		loading();
		char s1,s2,s3;
		printf("\n\n%c Do you want to sort list of employee?", 254);	
		rectangle1(1,7+2*n);	
		gotoxy(2,8+2*n);	green();	printf("Yes = Y,y");
		gotoxy(13,8+2*n);	white();	printf("OR");
		rectangle1(16,7+2*n);	
		gotoxy(17,8+2*n);	red();	printf(" No = N,n"); white();
		printf("\n\n%c Input : ", 26);
		sort1:	fflush(stdin);	scanf("%c", &s1);	white();	system("cls");	
		if(s1=='Y' || s1=='y'){
			table();
			sortagain:
			printf("\n\n%c Do You want to sort by Name or Salary?", 254);
			purple();
			rectangle(1,7+2*n);	
			gotoxy(2,8+2*n);	white();	printf("Sort by Name %c N", 29);
			gotoxy(23,8+2*n);	white();	printf("OR");	yellow();
			rectangle(26,7+2*n);	
			gotoxy(27,8+2*n);	white();	printf("Sort by Salary %c S", 29);
			printf("\n\n%c Input : ", 254);	
			sort2:	fflush(stdin);	scanf("%c", &s2);
			system("cls");
			if(s2=='N'){
				table();
				printf("\n\n%c Do you want to sort ascending or decending?", 30);
				//printf("Input -> a <- for ascending or -> d <- for deceding : ");	
				purple();
				rectangle(1,7+2*n);	
				gotoxy(5,8+2*n);	white();	printf("Ascending %c a",26);
				gotoxy(23,8+2*n);	white();	printf("OR");	yellow();
				rectangle(26,7+2*n);	
				gotoxy(29,8+2*n);	white();	printf("Descending %c d",26);
				printf("\n\n%c Input : ", 254);
				sorta3:	fflush(stdin);	scanf("%c", &s3);	system("cls");
				system("color F");
				if(s3=='a'){
					for(i=0;i<n;i++){
						for(j=1+i;j<n;j++){
							if(strcmp(Em[i].firstname,Em[j].firstname)==1){
								temp=Em[j];
								Em[j]=Em[i];
								Em[i]=temp;
								temp1=netSalary[j];
								netSalary[j]=netSalary[i];
								netSalary[i]=temp1;
							}
						}
					}
					blue();	
					gotoxy(37,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(71,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					purple();
					gotoxy(45,1);	printf("Emplyee's List after sort");
					tablesort();
				}
				else if(s3=='d'){
					for(i=0;i<n;i++){
						for(j=1+i;j<n;j++){
							if(strcmp(Em[i].firstname,Em[j].firstname)==-1){
								temp=Em[j];
								Em[j]=Em[i];
								Em[i]=temp;
								temp1=netSalary[j];
								netSalary[j]=netSalary[i];
								netSalary[i]=temp1;
							}
						}
					}
					blue();	
					gotoxy(37,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(71,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					purple();
					gotoxy(45,1);	printf("Emplyee's List after sort");
					tablesort();
				}
				else{
					system("cls");	table();
					red();	printf("\a\n\nWe can not accept any character, except a=ascending, d=decending \n");	white();
					printf("%c Input again : ", 16);
					goto sorta3;	
				}
			}
			else if(s2=='S'){
				table();
				printf("\n\n%c Do you want to sort ascending or decending?", 254);	purple();
				rectangle(1,7+2*n);	
				gotoxy(5,8+2*n);	white();	printf("Ascending %c a",26);
				gotoxy(23,8+2*n);	white();	printf("OR");	yellow();
				rectangle(26,7+2*n);	
				gotoxy(29,8+2*n);	white();	printf("Descending %c d",26);
				printf("\n\n%c Input : ", 254);	
				sortd3:	fflush(stdin);	scanf("%c", &s3);	system("cls");
				if(s3=='a'){
					for(i=0;i<n;i++){
						for(j=1+i;j<n;j++){
							if(Em[i].salary>Em[j].salary){
								temp=Em[j];
								Em[j]=Em[i];
								Em[i]=temp;
								temp1=netSalary[j];
								netSalary[j]=netSalary[i];
								netSalary[i]=temp1;
							}
						}
					}
					blue();
					gotoxy(37,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(71,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					purple();
					gotoxy(45,1);	printf("Emplyee's List after sort");
					tablesort();
				}
				else if(s3=='d'){
					for(i=0;i<n;i++){
						for(j=1+i;j<n;j++){
							if(Em[i].salary<Em[j].salary){
								temp=Em[j];
								Em[j]=Em[i];
								Em[i]=temp;
								temp1=netSalary[j];
								netSalary[j]=netSalary[i];
								netSalary[i]=temp1;
							}
						}
					}
					blue();	
					gotoxy(37,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(71,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					purple();
					gotoxy(45,1);	printf("Emplyee's List after sort");
					tablesort();
				}
				else{
					system("cls");	table();
					red();	printf("\a\n\nWe can not accept any character, except a=ascending, d=decending \n");	white();
					printf("%c Input again : ", 16);
					goto sortd3;	
				}
			}
			else{
				system("cls");	table();
				red();	printf("\a\n\nWe can not accept any character, except N=name, S=Salary \n");	white();
				printf("%c Input again : ", 16);
				goto sort2;
			}	
		}
		else if(s1=='N' || s1=='n'){
			system("cls");
			table();
		}
		else{
			system("cls");	table();
			red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	white();
			printf("%c Input again: ", 16);
			goto sort1;
		}
		char s_again;
		printf("\n\n%c Do you want to sort employee's list again?", 31);
		rectangle1(1,7+2*n);	
		gotoxy(2,8+2*n);	green();	printf("Yes = Y,y");
		gotoxy(13,8+2*n);	white();	printf("OR");
		rectangle1(16,7+2*n);	
		gotoxy(17,8+2*n);	red();	printf(" No = N,n"); white();
		printf("\n\n%c Input : ", 26);	s_again1:	fflush(stdin);	scanf("%c", &s_again);
		if(s_again=='Y' || s_again=='y'){
			system("cls");	
			blue();	
			gotoxy(37,1);	
			for(i=0;i<7;i++){
				printf("%c", 4);
			}
			gotoxy(71,1);	
			for(i=0;i<7;i++){
				printf("%c", 4);
			}
			purple();
			gotoxy(45,1);	printf("Emplyee's List after sort");
			tablesort();
			goto sortagain;
		}
		else if(s_again=='N' || s_again=='n'){
			system("cls");	
			blue();	
			gotoxy(37,1);	
			for(i=0;i<7;i++){
				printf("%c", 4);
			}
			gotoxy(71,1);	
			for(i=0;i<7;i++){
				printf("%c", 4);
			}
			purple();
			gotoxy(45,1);	printf("Emplyee's List after sort");
			tablesort();	
		}
		else{
			system("cls");	table();
			red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	white();
			printf("%c Input again: ", 16);
			goto s_again1;
		}
		savetofile();
		loading();
		Deleting();
		savetofile();
		AddEmployee();
		savetofile();
		getch();
	}
}
void findnetsalary(){
	for(i=0;i<n;i++){
		if(Em[i].salary<=500000)	netSalary[i]=Em[i].salary;
		else if(Em[i].salary>500000 && 1250000>=Em[i].salary)	netSalary[i]=Em[i].salary-(Em[i].salary-500000)*0.05;
		else if(Em[i].salary>1250000 && 8500000>=Em[i].salary)	netSalary[i]=Em[i].salary-(Em[i].salary-1250000)*0.1;
		else if(Em[i].salary>8500000 && 12500000>=Em[i].salary)	netSalary[i]=Em[i].salary-(Em[i].salary-8500000)*0.15;
		else	netSalary[i]=Em[i].salary-(Em[i].salary-12500000)*0.2;
	}
}
void gotoxy1(int n){
	short x,y;
	int c;
	x=2;
	y=2;
	blue();
	for(j=0;j<=n+1;j++){
		for(c=0;c<=102;c++){
			gotoxy(x+c,y);
			printf("%c" ,196);
		}
		y=y+2;
	}
	green();
	H_line(1,3,n);
	H_line(6,3,n);
	H_line(18,3,n);
	H_line(35,3,n);
	H_line(50,3,n);
	H_line(57,3,n);
	H_line(70,3,n);
	H_line(87,3,n);
	H_line(105,3,n);
	for(c=4;c<=n*2+1;c+=2){
		for(j=1;j<=102;j++){
			gotoxy(j,c);
			if(j==6)	printf(" ");
			if(j==18)	printf(" ");
			if(j==35)	printf(" ");
			if(j==50)	printf(" ");
			if(j==57)	printf(" ");
			if(j==70)	printf(" ");
			if(j==87)	printf(" ");
		}
	}
	red();
	for(j=1;j<=102;j++){
		gotoxy(j,2);
		if(j==6)	printf("%c", 194);
		if(j==18)	printf("%c", 194);
		if(j==35)	printf("%c", 194);
		if(j==50)	printf("%c", 194);
		if(j==57)	printf("%c", 194);
		if(j==70)	printf("%c", 194);	
		if(j==87)	printf("%c", 194);
	}
	yellow();
	for(c=4;c<=n*2+2;c+=2){
		for(j=1;j<=102;j++){
			gotoxy(j,c);
			if(j==6)	printf("%c", 197);
			if(j==18)	printf("%c", 197);
			if(j==35)	printf("%c", 197);
			if(j==50)	printf("%c", 197);
			if(j==57)	printf("%c", 197);
			if(j==70)	printf("%c", 197);
			if(j==87)	printf("%c", 197);
		}
	}
	red();
	for(j=1;j<=102;j++){
		gotoxy(j,n*2+4);
		if(j==6)	printf("%c", 193);
		if(j==18)	printf("%c", 193);
		if(j==35)	printf("%c", 193);
		if(j==50)	printf("%c", 193);
		if(j==57)	printf("%c", 193);
		if(j==70)	printf("%c", 193);
		if(j==87)	printf("%c", 193);
	}
	green();
	for(j=2;j<=n*2+4;j+=2){
		for(c=2;c<n+2;c++){
			gotoxy(1,j);
			if(j==2)	printf("%c", 218);
			if(j==c*2)	printf("%c", 195);
			if(j==n*2+4)	printf("%c", 192);	
		}
	}
	for(j=2;j<=n*2+4;j+=2){
		for(c=2;c<n+2;c++){
			gotoxy(105,j);
			if(j==2)	printf("%c", 191);
			if(j==c*2)	printf("%c", 180);
			if(j==n*2+4)	printf("%c", 217);	
		}
	}
	white();
}
void rectangle(int l,int j){
	short x,y;
	int m1,z;
	int c;
	x=l;
	y=j;
	m1=x;
	z=y;
	for(j=0;j<2;j++){
		for(c=0;c<=20;c++){
			gotoxy(x+c,y);
			printf("%c" ,205);
		}
		y=y+2;
	}
	gotoxy(m1-1,z);	printf("%c", 201);
	gotoxy(m1-1,z+1);	printf("%c", 186);
	gotoxy(m1-1,z+2);	printf("%c", 200);
	gotoxy(m1+21,z);	printf("%c", 187);	
	gotoxy(m1+21,z+1);	printf("%c", 186);
	gotoxy(m1+21,z+2);	printf("%c", 188);
}
void rectangle1(int l,int j){
	blue();
	short x,y;
	int m1,z;
	int c;
	x=l;
	y=j;
	m1=x;
	z=y;
	for(j=0;j<2;j++){
		for(c=0;c<=10;c++){
			gotoxy(x+c,y);
			printf("%c" ,205);
		}
		y=y+2;
	}
	gotoxy(m1-1,z);	printf("%c", 201);
	gotoxy(m1-1,z+1);	printf("%c", 186);
	gotoxy(m1-1,z+2);	printf("%c", 200);
	gotoxy(m1+11,z);	printf("%c", 187);	
	gotoxy(m1+11,z+1);	printf("%c", 186);
	gotoxy(m1+11,z+2);	printf("%c", 188);
}
void rectangle2(int l,int j){
	short x,y;
	int m1,z;
	int c;
	x=l;
	y=j;
	m1=x;
	z=y;
	for(j=0;j<2;j++){
		for(c=0;c<=26;c++){
			gotoxy(x+c,y);
			printf("%c" ,205);
		}
		y=y+2;
	}
	gotoxy(m1-1,z);	printf("%c", 201);
	gotoxy(m1-1,z+1);	printf("%c", 186);
	gotoxy(m1-1,z+2);	printf("%c", 200);
	gotoxy(m1+27,z);	printf("%c", 187);	
	gotoxy(m1+27,z+1);	printf("%c", 186);
	gotoxy(m1+27,z+2);	printf("%c", 188);
}
void rectangle3(int l,int j){
	purple();
	short x,y;
	int m,n,c;
	x=l;
	y=j;
	m=x;
	n=y;
	for(j=0;j<2;j++){
		for(c=0;c<=30;c++){
			gotoxy(x+c,y);
			printf("%c" ,205);
		}
		y=y+3;
	}
	gotoxy(m-1,n);	printf("%c", 201);
	gotoxy(m-1,n+1);	printf("%c", 186);
	gotoxy(m-1,n+2);	printf("%c", 186);
	gotoxy(m-1,n+3);	printf("%c", 200);
	gotoxy(m+31,n);	printf("%c", 187);	
	gotoxy(m+31,n+1);	printf("%c", 186);
	gotoxy(m+31,n+2);	printf("%c", 186);
	gotoxy(m+31,n+3);	printf("%c", 188);
}
void listemployee(int r){
	findnetsalary();
	green();
	gotoxy(3,3);	printf("No");
	gotoxy(11,3);	printf("ID");
	gotoxy(22,3);	printf("Firstname");
	gotoxy(39,3);	printf("Lastname");
	gotoxy(52,3);	printf("Sex");
	gotoxy(60,3);	printf("Birthday");
	gotoxy(73,3);	printf("Salary(KHR)");
	gotoxy(89,3);	printf("Netsalary(KHR)");
	white();
	for(i=0;i<n;i++){
		gotoxy(3,r);	printf("%d", (i+1));
		gotoxy(10,r);	printf("%d", Em[i].id);
		gotoxy(21,r);	printf("%s", Em[i].firstname);
		gotoxy(38,r);	printf("%s", Em[i].lastname);
		gotoxy(53,r);	printf("%c", Em[i].sex);
		gotoxy(59,r);	printf("%s", Em[i].birthday);
		gotoxy(75,r);	printf("%0.f", Em[i].salary);
		gotoxy(91,r);	printf("%.0f", netSalary[i]);
		r+=2;
	}
}
void updatetable(struct Employee em){	
	int u;
	if(em.salary<=500000)	netSalary[i]=em.salary;
	else if(em.salary>500000 && 1250000>=em.salary)	netSalary[i]=em.salary-(em.salary-500000)*0.05;
	else if(em.salary>1250000 && 8500000>=em.salary)	netSalary[i]=em.salary-(em.salary-1250000)*0.1;
	else if(em.salary>8500000 && 12500000>=em.salary)	netSalary[i]=em.salary-(em.salary-8500000)*0.15;
	else	netSalary[i]=em.salary-(em.salary-12500000)*0.2;
	red();
	gotoxy(35,1);	
	for(u=0;u<7;u++){
		printf("\3");
	}
	gotoxy(65,1);	
	for(u=0;u<7;u++){
		printf("\3");
	}
	yellow();	gotoxy(43,1);	printf("Emplyee's information");
	blue();
	gotoxy(3,3);	printf("No");
	gotoxy(11,3);	printf("ID");
	gotoxy(22,3);	printf("Firstname");
	gotoxy(39,3);	printf("Lastname");
	gotoxy(52,3);	printf("Sex");
	gotoxy(60,3);	printf("Birthday");
	gotoxy(73,3);	printf("Salary(KHR)");
	gotoxy(89,3);	printf("Netsalary(KHR)");
	white();
	gotoxy(3,5);	printf("%d", (i+1));
	gotoxy(10,5);	printf("%d", em.id);
	gotoxy(21,5);	printf("%s", em.firstname);
	gotoxy(38,5);	printf("%s", em.lastname);
	gotoxy(53,5);	printf("%c", em.sex);
	gotoxy(59,5);	printf("%s", em.birthday);
	gotoxy(75,5);	printf("%0.f", em.salary);
	gotoxy(91,5);	printf("%.0f", netSalary[i]);
	gotoxy1(1);
}
void table(){
	purple();
	gotoxy(38,1);	
	for(i=0;i<7;i++){
		printf("%c", 4);
	}
	gotoxy(61,1);	
	for(i=0;i<7;i++){
		printf("%c", 4);
	}
	yellow();	gotoxy(46,1);	printf("Emplyee's List");
	listemployee(t);
	gotoxy1(n);
}
void H_line(int x,int y,int n){
	int c;
	for(c=0;c<=n*2;c++){
		gotoxy(x,y+c);
		printf("%c" ,179);
	}
}
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void fullname(){
	for(i=0;i<n;i++){
		strcpy(Em[i].fullname,Em[i].firstname);	
		strcat(Em[i].fullname, " ");	
		strcat(Em[i].fullname, Em[i].lastname);
	}
}
void tablesort(){
	gotoxy1(n);
	listemployee(t);
}
void Deleting(){
	char Dem;
	char Emfullname[30];
	int Del=0,idorname,idfordelete;
	struct Employee temp2;
	for(i=0;i<n;i++){
		strcpy(Em[i].fullname,Em[i].firstname);	
		strcat(Em[i].fullname, " ");	
		strcat(Em[i].fullname, Em[i].lastname);
	}
	printf("\n\n%c Do you want to Delete any employee?", 30);
	rectangle1(1,7+2*n);	
	gotoxy(2,8+2*n);	green();	printf("Yes = Y,y");
	gotoxy(13,8+2*n);	white();	printf("OR");
	rectangle1(16,7+2*n);	
	gotoxy(17,8+2*n);	red();	printf(" No = N,n"); white();
	printf("\n\n%c Input : ", 26);
	sort4:	fflush(stdin);	scanf("%c", &Dem);
	if(Dem=='Y' || Dem=='y'){
		system("cls");
		again_:
		table();
		printf("\n\n%c Choose option : ", 31);
		purple();
		rectangle(1,7+2*n);	
		gotoxy(2,8+2*n);	white();	printf("1%c Delete by Name", 29);
		gotoxy(23,8+2*n);	white();	printf("OR");	purple();
		rectangle(26,7+2*n);	
		gotoxy(27,8+2*n);	white();	printf("2%c Delete by ID", 29);
		printf("\n\n%c Input : ", 254);	
		fflush(stdin);	again5:	scanf("%d", &idorname);
		switch(idorname){
			case 1:
				system("cls");
				table();
				printf("\n\n%c Enter employee's fullname that you want to delete : ", 16);	blue();	rectangle2(54,5+2*n);	white();
				gotoxy(55,6+2*n);	entername:	fflush(stdin);	gets(Emfullname);
				for(i=0;i<n;i++){
					system("color F");
					if(strcmp(Em[i].fullname,Emfullname)==0){
						Del=1;
						for(j=i;j<n-1;j++){
							temp2=Em[j];
							Em[j]=Em[j+1];
							Em[j+1]=temp2;
						}
						n--;
						break;
					}
				}
				if(Del==0){
					system("cls");
					table();	
					printf("\a\n                                              "); backgroundred();	printf("Name not found!!\n\n");	white();	
					printf("Enter Name again: ");
					green();	rectangle2(19,6+2*n);	
					gotoxy(20,7+2*n);	white();	goto entername;
				}
				else{
					system("cls");
					blue();
					gotoxy(37,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(75,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(45,1);	yellow();	printf("Employee's list after Deleting");
					tablesort();
					printf("\n\n                                               "); backgroundgreen();	printf("Delete Successfully");	white();
				}
				break;
			case 2:
				//system("color F");
				system("cls");
				table();
				printf("\n\n%c Enter employee's ID that you want to delete : ", 16);	rectangle1(48,5+2*n);	
				gotoxy(49,6+2*n);	enterID:	fflush(stdin);	white();	scanf("%d", &idfordelete);
				system("color F");
				for(i=0;i<n;i++){
					if(Em[i].id==idfordelete){
						Del=1;
						for(j=i;j<n-1;j++){
							temp2=Em[j];
							Em[j]=Em[j+1];
							Em[j+1]=temp2;
						}
						n--;
						break;
					}
				}
				if(Del==0){
					system("cls");
					table();	
					printf("\a\n                                              "); backgroundred();	printf("ID not found!!\n\n");
					gotoxy(2,7+2*n); white();	printf("Please input ID again: ");	rectangle1(25,6+2*n);
					gotoxy(26,7+2*n);
					white();	goto enterID;
				}
				else{
					system("cls");
					blue();
					gotoxy(37,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(75,1);	
					for(i=0;i<7;i++){
						printf("%c", 4);
					}
					gotoxy(45,1);	red();	printf("Employee's list after Deleting");
					tablesort();
					printf("\n\n                                               "); backgroundgreen();	printf("Delete Successfully");	white();
				}
				break;
			default:
				system("cls");	table();
				red();	printf("\a\n\nWe can not accept any number, except 1 and 2 \n");	white();
				printf("%c Input again: ", 16);
				goto again5;
		}
	}
	else if(Dem=='N' || Dem=='n'){
		system("cls");
		red();
		gotoxy(37,1);	
		for(i=0;i<7;i++){
			printf("%c", 4);
		}
		gotoxy(75,1);	
		for(i=0;i<7;i++){
			printf("%c", 4);
		}
		gotoxy(45,1);	blue();	printf("Employee's list after Deleting");
		tablesort();
	}
	else{
		system("cls");	table();
		red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	white();
		printf("%c Input again: ", 16);
		goto sort4;
	}
	if(Del==0){
		printf("\n");
	}
	else{
		char name1;
		for(i=0;i<n;i++){
			fflush(stdin);
			printf("\n%c Do you want to find other employees for Delete?", 31);	
			rectangle1(1,7+2*n);	
			gotoxy(2,8+2*n);	green();	printf("Yes = Y,y");
			gotoxy(13,8+2*n);	white();	printf("OR");
			rectangle1(16,7+2*n);	
			gotoxy(17,8+2*n);	red();	printf(" No = N,n"); white();	printf("\n\n%c Input : ", 30);
			input1:	fflush(stdin);	scanf("%c", &name1);
			if(name1=='Y' || name1=='y' ){
				system("cls");
				Del=0;
				goto again_;
			}
			else if(name1=='N' || name1=='n'){
				system("cls");
				red();
				gotoxy(37,1);	
				for(i=0;i<7;i++){
					printf("%c", 4);
				}
				gotoxy(75,1);	
				for(i=0;i<7;i++){
					printf("%c", 4);
				}
				gotoxy(45,1);	blue();	printf("Employee's list after Deleting");
				tablesort();
				break;
			}
			else{
				system("cls");	table();	
				red();	printf("\a\n\nWe can not accept any character, except Y=yes,N=no \n");	
				printf("%c Input again: ", 16);
				white();	goto input1;
			}
		}
	}
}
void AddEmployee(){
	system("cls");
	blue();
	gotoxy(37,1);	
	for(i=0;i<7;i++){
		printf("%c", 4);
	}
	gotoxy(75,1);	
	for(i=0;i<7;i++){
		printf("%c", 4);
	}
	gotoxy(45,1);	red();	printf("Employee's list after Deleting");
	tablesort();
	char add;
	int ne,k,q;
	int w=n;
	printf("\n\n%c Do you want to add Employee? ", 31);	
	rectangle1(1,7+2*n);	
	gotoxy(2,8+2*n);	green();	printf("Yes = Y,y");
	gotoxy(13,8+2*n);	white();	printf("OR");
	rectangle1(16,7+2*n);	
	gotoxy(17,8+2*n);	red();	printf(" No = N,n"); white();	
	printf("\n\n%c Input : ", 30);
	fflush(stdin);	inputs:	scanf("%c", &add);
	if(add=='Y' || add=='y'){
		system("cls");
		table();
		printf("\n\nHow many employee that you want to add?");	
		rectangle1(1,7+2*n);
		white();	gotoxy(2,8+2*n);	addem:	fflush(stdin);	scanf("%d", &ne);
		system("cls");
		if(ne+n>10){
			table();
			white();	printf("\n\n%c You can not enter ",16);	red();	printf("%d", ne);	white();	printf(" because it makes more than 10 employees.");
			printf("\n\n%c Enter again: ", 31);	rectangle1(16,7+2*n);	white();
			gotoxy(17,8+2*n);	goto addem;
		}
		else{
			n=w+ne;
		//	q=ne;
			for(k=0;k<ne;k++){
				green();	rectangle(1,0);	gotoxy(3,1);	purple();	printf(" %c  Employee #%d ", 2,(w+1+k));	white();
				fflush(stdin);
				printf("\n\n%c Enter ID : ", 16);	again1_:	scanf("%d", &Em[w+k].id);
				i=w+k;
				for(j=1;j<=w+k;j++){
					if(Em[w+k].id==Em[i-j].id){
						backgroundred();	printf("This ID is the ID of the employee #%d, please enter a different ID.\n", i-j+1);
						white();	printf("\a%c Input another ID: ", 16);
						goto again1_;
					}
				}
				fflush(stdin);
				printf("%c Enter Firstname : ", 16);	gets(Em[w+k].firstname);
				fflush(stdin);
				printf("%c Enter Lastname : ", 16);	gets(Em[w+k].lastname);
				fflush(stdin);
				printf("%c Enter Sex : ", 16);	scanf("%c", &Em[w+k].sex);
				fflush(stdin);
				printf("%c Enter Birthday : ", 16);	gets(Em[w+k].birthday);
				fflush(stdin);
				printf("%c Enter Salary (KHR) : ", 16);	scanf("%f", &Em[w+k].salary);
				system("cls");
			}
			findnetsalary();
			red();
			gotoxy(35,1);	
			for(i=0;i<7;i++){
				printf("%c", 4);
			}
			gotoxy(72,1);	
			for(i=0;i<7;i++){
				printf("%c", 4);
			}
			blue();
			gotoxy(43,1);	printf("Employee's list after Adding");
			tablesort();
		}
	}
	else if(add=='N' || add=='n'){
		system("cls");
		blue();
		gotoxy(37,1);	
		for(i=0;i<7;i++){
			printf("%c", 4);
		}
		gotoxy(75,1);	
		for(i=0;i<7;i++){
			printf("%c", 4);
		}
		green();
		gotoxy(45,1);	printf("Employee's list after Deleting");
		tablesort();
	}
	else{
		system("cls");	table();
		red(); printf("\a\n\nWe can not accept any character, except Y,y=yes,N,n=no \n");
		white();	printf("%c Input again: ", 16);
		goto inputs;
	}
}
void savetofile(){
	FILE *fp;
	fp = fopen("employee.txt", "wb");
	for(i=0;i<n;i++){
		fwrite(&Em[i], sizeof(struct Employee), 1, fp);
	}
	/*if(fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");*/
	fclose(fp);
}
void loading(){
	FILE *fp;
	fp = fopen("employee.txt", "r");
	i=0;
	while(fread(&em, sizeof(struct Employee), 1, fp)){
		i++;
	}
	
	fclose(fp);
}

