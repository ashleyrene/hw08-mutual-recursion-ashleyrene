#include "hw08.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s [input]", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Failed to open file: %s\node", argv[1]);
    return EXIT_FAILURE;
  }

  char buf[1024];
  fgets(buf, 1024, fp);

  if (is_valid_expr(buf) == PARSE_SUCCESS) {
    printf("Valid\n");
  } else {
    printf("Invalid\n");
  }

  fclose(fp);

  return 0;
}
