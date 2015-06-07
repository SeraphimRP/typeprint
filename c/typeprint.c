#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static int
process(char *name, struct timespec *ts)
{
	FILE *file = fopen(name, "r");

	if (file == 0){
		fprintf(stderr, "[err] you either gave me an invalid file, or no file at all");
		return -1;
	}

	int x;
	while ((x = fgetc(file)) != EOF) {
		printf("%c", x);
		nanosleep(ts, NULL);
	}

	return 0;
}

int
main(int argc, char *argv[])
{
	char *argv0;

	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = 10 * 1000000;

	process(argv[1], &ts);

	return 0;
}