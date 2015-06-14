/* vypr's typeprint */
/* https://github.com/vypr/typeprint */

#include <err.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

static int process(char *name);

static int
process(char *name)
{
        FILE *file = fopen(name, "r");
        struct timespec ts;

        ts.tv_sec = 0;
        ts.tv_nsec = 10 * 1000000;

        if (access(name, F_OK) == -1) {
            errx(ENOENT, "[err] no such file or directory\n");
        }

        if (access(name, R_OK) == -1) {
            errx(EACCES, "[err] can't read file, permission denied\n");
        }

        int x;
        while ((x = fgetc(file)) != EOF) {
            printf("%c", x);

            /* flush stdout, because it won't look like typing without. */
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
