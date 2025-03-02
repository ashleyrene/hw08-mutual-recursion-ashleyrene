#ifndef HW08
#define HW08

#include <stddef.h>

enum parse_result { PARSE_SUCCESS, PARSE_FAILURE };
enum token_type { TOK_LPAREN, TOK_RPAREN, TOK_BINOP, TOK_LITERAL, TOK_EOF };

struct stream {
  const char *text; // raw text stream being parsed
  int pos;          // current position in `text`
  size_t length;    // total length of `text`
};

struct token {
  enum token_type type; // type of token
  const char *start;    // pointer into the stream to the start of the token
  size_t length;        // length of the token
};

struct token peek(struct stream *s); // return the next token without advancing the stream
struct token next(struct stream *s); // return the next token and advance the stream

void skip_whitespace(struct stream *s); // advance the stream past any whitespace

// These are the functions you should implement
enum parse_result parse_expr(struct stream *s);
enum parse_result parse_expr_rest(struct stream *s);
enum parse_result parse_term(struct stream *s);
enum parse_result parse_term_rest(struct stream *s);
enum parse_result parse_factor(struct stream *s);

// This is implemented for you!
enum parse_result is_valid_expr(const char *expr);
#endif
