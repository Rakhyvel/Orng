/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _577_main(void);
struct1 _582_f(void);

/* Function definitions */
int64_t _577_main(void){
    function0 _577_t1;
    struct1 _577_t2;
    uint64_t _577_t3;
    uint64_t _577_t4;
    uint8_t _577_t5;
    int64_t _577_$retval;
    uint64_t _577_t6;
    uint64_t _577_t7;
    uint8_t _577_t8;
    _577_t1 = _582_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _577_t2 = _577_t1();
    $line_idx--;
    _577_t3 = 0;
    _577_t4 = _577_t2.tag;
    _577_t5 = _577_t4 == _577_t3;
    if (_577_t5) {
        goto BB724;
    } else {
        goto BB725;
    }
BB724:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB725:
    _577_t6 = 1;
    _577_t7 = _577_t2.tag;
    _577_t8 = _577_t7 == _577_t6;
    if (_577_t8) {
        goto BB727;
    } else {
        goto BB731;
    }
BB727:
    _577_$retval = 238;
    return _577_$retval;
BB731:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _582_f(void){
    struct1 _582_$retval;
    _582_$retval = (struct1) {.tag=1};
    return _582_$retval;
}

int main(void) {
  printf("%ld",_577_main());
  return 0;
}
