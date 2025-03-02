#include "hw08.h"

#include <string.h>

/**
 * Grammar:
 *
 * expr := term expr_rest
 * expr_rest := '+' expr | '-' expr | {}
 *
 * term := factor term_rest
 * term_rest = '*' term | {}
 *
 * factor := int | '(' expr ')'
 */

#ifndef INSTRUCTOR_EXPR
enum parse_result parse_expr(struct stream *s) { return PARSE_SUCCESS; }

enum parse_result parse_expr_rest(struct stream *s) { return PARSE_SUCCESS; }
#endif

#ifndef INSTRUCTOR_TERM
enum parse_result parse_term(struct stream *s) { return PARSE_SUCCESS; }

enum parse_result parse_term_rest(struct stream *s) { return PARSE_SUCCESS; }
#endif

#ifndef INSTRUCTOR_FACTOR
enum parse_result parse_factor(struct stream *s) { return PARSE_FAILURE; }
#endif

// You do NOT need to modify this function!
enum parse_result is_valid_expr(const char *expr) {
  // Create the stream
  struct stream s = {.text = expr, .pos = 0, .length = strlen(expr)};

  // Try to parse an expr and make sure there's nothing left to parse
  if (parse_expr(&s) == PARSE_SUCCESS && next(&s).type == TOK_EOF) {
    return PARSE_SUCCESS;
  }
  return PARSE_FAILURE;
}
