#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int failed=0;

struct course {
	char name[25];
	int credits;
	int priority;
}courses[10];

struct student {
	char name[25];
	char username[25];
	char password[25];
	struct course courses[5];
}students[5];

void initialisedb() {
	strcpy(students[0].name, "Jeremy");
	strcpy(students[0].username, "16bce1367");
	strcpy(students[0].password, "jerry1998");

	strcpy(students[1].name, "\0Vishhvak");
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

	strcpy(courses[0].name, "CHY");
	courses[0].credits = 5;

	strcpy(courses[1].name, "DLD");
	courses[1].credits = 4;

	strcpy(courses[2].name, "DSA");
	courses[2].credits = 4;

	strcpy(courses[3].name, "IWP");
	courses[3].credits = 4;

	strcpy(courses[4].name, "GER");
	courses[4].credits = 2;

	strcpy(courses[5].name, "MGMT");
	courses[5].credits = 2;

	strcpy(courses[6].name, "OS");
	courses[6].credits = 4;
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

void view_courses() {
	system("clear");
	line(80, true);
	line(15, false);
	printf("\t\t\tAvailable Courses\t\t");
	line(16, true);
	line(80, true);
	for(int i=0; i<6; i++) {
		printf("\n\t%d) %s | %d credits", i+1, courses[i].name, courses[i].credits);
	}
	int blackhole;
	printf("\n\nEnter anything to go back (preferably numbers) ");
	scanf("%d", &blackhole);
}

void add_course(int session_id) {
	int err=0;
	int course_index, credits=0;
	printf("Which course would you like to add: ");
	scanf("%d", &course_index);
	int iterator=0;
	while(students[session_id].courses[iterator].name[0]!='\0') {
		if(strcmp(courses[course_index-1].name, students[session_id].courses[iterator].name)==0) {
			printf("\n\t\t\tYou have already added that course!");
			err=1;
			break;
		}
		iterator++;
		credits+=students[session_id].courses[iterator].credits;
	}
	if(credits+courses[course_index].credits<=16) {
		students[session_id].courses[iterator] = courses[course_index-1];
	}
	else if(credits+courses[course_index].credits>16) {
		printf("\n\t\t\tYou are exceeding your credits!");
		err=1;
	}
	if(err) {
		int blackhole;
		printf("\n\nEnter anything to try again (preferably numbers) ");
		scanf("%d", &blackhole);
	}
} 

void delete_course(int session_id) {

}

int choose_courses(int session_id) {
	while(true) {
		system("clear");
		line(80, true);
		line(15, false);
		printf("\t\t\tAvailable Courses\t\t");
		line(16, true);
		line(80, true);
		for(int i=0; i<6; i++) {
			printf("\n\t%d) %s | %d credits", i+1, courses[i].name, courses[i].credits);
		}
		printf("\n\n");
		line(18, true);
		printf("## Wishlist\n");
		line(18, true);
		printf("\n");
		int choice, iterator=0, credits=0;
		while(students[session_id].courses[iterator].name[0]!='\0') {
			credits+=students[session_id].courses[iterator].credits;
			printf("\t%c) %s\n", iterator+65, students[session_id].courses[iterator].name);
			iterator++;
		}
		printf("\tCredits: %d\n", credits);
		printf("\n\t1) Add a course");
		printf("\n\t2) Delete a course");
		printf("\n\t3) Go back to dashboard");
		printf("\n\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				add_course(session_id);
				break;
			case 2:
				delete_course(session_id);
				break;
			case 3:
				return 0;
		}
	}
}

int dashboard(int session_id) {
	while(true) {
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
		int choice;
		printf("\n\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				view_courses();
				break;
			case 2:
				choose_courses(session_id);
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
		failed = 0;
		dashboard(is_authenticated);
	}
	else {
		failed = 1;
	}
}

int main() {
	system("clear");
	initialisedb();
	while(true) {
		welcome(failed);
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