#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int process(char *name);

static int
process(char *name)
{
        FILE *file = fopen(name, "r");
        struct timespec ts;

        ts.tv_sec = 0;
        ts.tv_nsec = 10 * 1000000;

        if (file == 0) {
            fprintf(stderr, "[err] no such file or directory\n");
            return ENOENT;
        }

        int x;
        while ((x = fgetc(file)) != EOF) {
            printf("%c", x);
            fflush(stdout);
            nanosleep(&ts, NULL);
        }

        fclose(file);
        return 0;
}

int
main(int argc, char *argv[])
{
        return process(argv[1]);
}
