#include "hw08.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void skip_whitespace(struct stream *s) {
  while (s->pos < s->length && isspace(s->text[s->pos]))
    s->pos++;
}

// mac sucks lmao
int _isnumber(int c) { return '0' <= c && c <= '9'; }

struct token peek(struct stream *s) {
  skip_whitespace(s);
  if (s->pos == s->length)
    return (struct token){.type = TOK_EOF, .start = NULL, .length = 0};
  switch (s->text[s->pos]) {
  case '(':
    return (struct token){
        .type = TOK_LPAREN, .start = s->text + s->pos, .length = 1};
  case ')':
    return (struct token){
        .type = TOK_RPAREN, .start = s->text + s->pos, .length = 1};
  case '+':
  case '-':
  case '*':
    return (struct token){
        .type = TOK_BINOP, .start = s->text + s->pos, .length = 1};
  default:
    if (!_isnumber(s->text[s->pos])) {
      fprintf(stderr, "Unrecognized symbol at position %d: %s\n", s->pos,
              s->text + s->pos);
      exit(1);
    }

    int i;
    for (i = 0; _isnumber(s->text[s->pos + i]); i++)
      ;
    return (struct token){
        .type = TOK_LITERAL, .start = s->text + s->pos, .length = i};
  }
}

struct token next(struct stream *s) {
  struct token tok = peek(s);
  s->pos += tok.length;
  return tok;
}
