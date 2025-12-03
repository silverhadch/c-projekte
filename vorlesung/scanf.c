#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void demo_correct() {
    printf("\nCORRECT USAGE\n");

    char buf[32];

    printf("Type: hello<Enter>\n");
    if (fgets(buf, sizeof(buf), stdin)) {
        printf("Stored: \"%s\"\n", buf);
    }
}

void demo_leftover_newline() {
    printf("\nLEFTOVER NEWLINE\n");

    char buf[4];

    printf("Type: test<Enter>\n");
    fgets(buf, sizeof(buf), stdin);
    printf("First read (buffer too small): \"%s\"\n", buf);

    fgets(buf, sizeof(buf), stdin);
    printf("Second read (gets only leftover '\\n'): \"%s\"\n", buf);
}

void demo_long_line() {
    printf("\nLONG LINE SPLIT\n");

    char buf[8];

    printf("Type: this_is_a_very_long_line<Enter>\n");

    while (1) {
        char *r = fgets(buf, sizeof(buf), stdin);
        if (!r) break;
        printf("Chunk: \"%s\"\n", buf);
        if (strchr(buf, '\n')) break;
    }
}

void demo_scanf_mix() {
    printf("\nSCANF + FGETS MIX = PROBLEM\n");

    int x;
    char buf[32];

    printf("Type: 42<Enter>\n");
    scanf("%d", &x);
    printf("Number read: %d\n", x);

    // leftover '\n' remains in stdin
    printf("Now fgets() will read leftover newline.\n");
    fgets(buf, sizeof(buf), stdin);
    printf("fgets got: \"%s\"\n", buf);
}

void demo_eof_behavior() {
    printf("\nEOF BEHAVIOR\n");
    printf("Pipe an empty file or press Ctrl-D on Unix.\n");

    char buf[32];
    char *r = fgets(buf, sizeof(buf), stdin);

    if (!r) {
        printf("fgets returned NULL. Buffer is untouched.\n");
    } else {
        printf("Unexpected data: %s\n", buf);
    }
}

void demo_actual_segfault() {
    printf("\nSEGFAULT\n");
    printf("This will crash NOW.\n");

    char *buf = NULL;     // no memory allocated
    // Using fgets on a NULL pointer is undefined behavior → segfault
    fgets(buf, 10, stdin);
}

int main() {
    demo_correct();
    demo_leftover_newline();
    demo_long_line();
    demo_scanf_mix();
    demo_eof_behavior();

    // demo_actual_segfault();

    return 0;
}
