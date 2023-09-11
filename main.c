#include <stdio.h>
#include <time.h>
#include <string.h>

// type definitions
struct entry {
	char *label;
	struct tm date;
};

// global variable definitions
struct entry list[100];
int list_length = 0;

// function definitions
void welcome_message() {
	printf("\n");
	printf("\n");
	printf("X days since Y\n");
	printf("==============\n");
	printf("\n");
};

struct tm getDate() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm;
};

void new_entry(char* entry_label, struct entry* list, int* list_length) {
	struct entry temp_entry;
	temp_entry.label = entry_label;
	temp_entry.date = getDate();
	list[*list_length] = temp_entry;
	*list_length = *list_length + 1;
}; 

void print_list(struct entry* list, int* list_length) {
	printf("==============\n");
	for (int i = 0; i < *list_length; i++) {
		printf("[%d] days since ", i);
		printf("%s\n", list[i].label);
	}
	printf("==============\n");
};

void prompt_user() {
	char input_text[40];
	printf("> ");
	fgets(input_text, 40, stdin);
		printf("input_text: %s\n", input_text);
	if (input_text[0] == '/') {
		// run command function
		print_list(list, &list_length);
	} else {
		// printf("run new entry function\n");
		// run new entry function
		new_entry(input_text, list, &list_length);
	}
	prompt_user();
};


int main(int argc, char *argv[]) {

	char input_text[40];
	welcome_message();
	prompt_user();
	print_list(list, &list_length);
  // time_t t = time(NULL);
  // struct tm tm = *localtime(&t);
  // printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
};
