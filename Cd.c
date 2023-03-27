#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

char input[MAX_LENGTH];
int index;

bool parse_S();
bool parse_aSb();
bool parse_bSa();
bool parse_c();

bool parse_S() {
  if (parse_aSb() || parse_bSa() || parse_c()) {
    return true;
  }
  return false;
}

bool parse_aSb() {
  int saved_index = index;
  if (input[index] == 'a') {
    index++;
    if (parse_S() && input[index] == 'b') {
      index++;
      return true;
    }
  }
  index = saved_index;
  return false;
}

bool parse_bSa() {
  int saved_index = index;
  if (input[index] == 'b') {
    index++;
    if (parse_S() && input[index] == 'a') {
      index++;
      return true;
    }
  }
  index = saved_index;
  return false;
}

bool parse_c() {
  if (input[index] == 'c') {
    index++;
    return true;
  }
  return false;
}

int main() {
  printf("Enter input string: ");
  fgets(input, MAX_LENGTH, stdin);
  input[strcspn(input, "\n")] = '\0';  // Remove trailing newline
  index = 0;

  if (parse_S() && index == strlen(input)) {
    printf("Parsing successful!\n");
  } else {
    printf("Parsing failed.\n");
  }

  return 0;
}
