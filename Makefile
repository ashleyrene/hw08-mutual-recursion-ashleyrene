CFLAGS = -std=c99 -g -Wall -Wshadow -Wvla -Werror -Wunreachable-code
OBJS = main.o tokenizer.o hw08.o
HEADERS = hw08.h
APP = hw08

VALID = $(foreach f, $(wildcard tests/valid/*.txt), test_valid_$(basename $(notdir $f)))
INVALID = $(foreach f, $(wildcard tests/invalid/*.txt), test_invalid_$(basename $(notdir $f)))

.PHONY: clean

$(APP): $(OBJS)
	$(CC) $(CFLAGS) *.o -o $(APP)

clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(APP)


test_valid_%: tests/valid/%.txt $(APP)
	@echo $@
	@bash -c "diff <(./$(APP) $<) <(echo Valid)"

test_invalid_%: tests/invalid/%.txt $(APP)
	@echo $@
	@bash -c "diff <(./$(APP) $<) <(echo Invalid)"

test_valid: $(VALID)

test_invalid: $(INVALID)

test: test_valid test_invalid	

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)
