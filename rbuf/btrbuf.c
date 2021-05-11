#include <stdio.h>
#include <string.h>
#include "rbuf.h"

int main(int argc, char **argv) {
    RingBuffer rb1, rb2;

    char *lyrics = "make it count, play it straight, don't look back, don't hesitate";

    rb1 = rb_alloc(10);
    for (int i = 0; i < strlen(lyrics); i++)
        rb_write(&rb1, lyrics[i]);

    for (int i = 0; i < 10; i++)
        printf("%c", rb_read(&rb1));
    printf("\n");
    rb_free(rb1);

    rb2 = rb_alloc(64);
    for (int i = 0; i < strlen(lyrics); i++)
        rb_write(&rb2, lyrics[i]);

    for (int i = 0; i < 64; i++)
        printf("%c", rb_read(&rb2));
    printf("\n");
    rb_free(rb2);
}
