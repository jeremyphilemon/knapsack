#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course {
	char name;
	char credits;
};

struct student {
	char name[25];
	char username[25];
	char password[25];
	struct course courses[];
}students[5];

void initialisedb() {
	strcpy(students[0].name, "Jeremy");
	strcpy(students[0].username, "16bce1367");
	strcpy(students[0].password, "jerry1998");
	strcpy(students[1].name, "Vishhvak");
	strcpy(students[1].username, "16bce1269");
	strcpy(students[1].password, "vish1998");
	strcpy(students[2].name, "Raghu");
	strcpy(students[2].username, "16bce1300");
	strcpy(students[2].password, "password1");
	strcpy(students[3].name, "Rutu");
	strcpy(students[3].username, "16bce1102");
	strcpy(students[3].password, "abc123456");
	strcpy(students[4].name, "Eshaan");
	strcpy(students[4].username, "15bme2341");
	strcpy(students[4].password, "vit123456");
}

void line(int width, bool endl) {
	for(int i=0; i<width; i++) {
		printf("#");
	}
	if(endl)
		printf("\n");
}

void welcome(int err=0) {
	system("clear");
	line(80, true);
	line(15, false);
	printf("\t\t\tCourse Registration\t\t");
	line(16, true);
	line(80, true);
	printf("\n\t1) Login");
	printf("\n\t2) Quit");
	if(err==1) {
		printf("\n\nError: Authentication failed. Please try again.");
	}
}

int authenticate(char username[], char password[]) {
	for(int i=0; i<5; i++) {
		if(strcmp(students[i].username, username)==0) {
			if(strcmp(students[i].password, password)==0) {
				return i;
			}
		}
	}
	return -1;
}

int dashboard(int session_id) {
	system("clear");
	line(80, true);
	line(15, false);
	printf("\t\t\tStudent Dashboard\t\t");
	line(16, true);
	line(80, true);
	printf("\n\tWelcome %s, \n", students[session_id].name);
	printf("\n\t1) View available courses");
	printf("\n\t2) Choose courses");
	printf("\n\t3) Generate timetable");
	printf("\n\t4) Log out");
	while(true) {
		int choice;
		printf("\n\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
					break;
			case 2:
					break;
			case 3:
					break;
			case 4:
					return 0;
		}
	}
}

void login() {
	system("clear");
	char username[25];
	char password[25];
	system("clear");
	line(80, true);
	line(25, false);
	printf("\t\tLogin\t\t");
	line(24, true);
	line(80, true);
	printf("\n\tUsername: ");
	scanf(" %s", &username[0]);
	printf("\tPassword: ");
	scanf(" %s", &password[0]);
	int is_authenticated = authenticate(username, password);
	if(is_authenticated!=-1) {
		dashboard(is_authenticated);
	}
	else {
		welcome(1);
	}
}

int main() {
	system("clear");
	initialisedb();
	while(true) {
		welcome();
		int choice;
		printf("\n\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
					login();
					break;
			case 2:
					return 0;
		}
	}
	return 0;
}