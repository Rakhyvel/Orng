/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x6D\x61\x6B\x65\x20\x73\x75\x72\x65\x20\x79\x6F\x75\x20\x73\x61\x6E\x69\x74\x69\x7A\x65\x20\x6D\x65\x21\x0A";

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_f(struct0 _3_x);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/sanitize.orng:3:7:\n    f(\"make sure you sanitize me!\\n\")\n     ^";
    $line_idx--;
    _1_$retval = _3_f((struct0) {(uint8_t*)string_0, 26});
    return _1_$retval;
}

int64_t _3_f(struct0 _3_x) {
    (void)_3_x;
    $lines[$line_idx++] = "tests/integration/whitebox/sanitize.orng:8:16:\n    unreachable\n              ^";
    $panic("reached unreachable code\n");
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
