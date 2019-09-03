.PHONY: tests clean

tests: testrunner
	@./testrunner

testrunner: tests.h *_test.c
	cc -o testrunner *_test.c

clean:
	rm -f testrunner

