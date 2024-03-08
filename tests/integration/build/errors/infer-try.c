/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _623_main(void);
struct struct1 _629_f(void);
struct struct1 _631_g(void);


/* Function definitions */
int64_t _623_main(void){
    function0 _623_t1;
    struct struct1 _623_t2;
    uint64_t _623_t3;
    uint64_t _623_t4;
    uint8_t _623_t5;
    int64_t _623_$retval;
    uint64_t _623_t6;
    uint64_t _623_t7;
    uint8_t _623_t8;
    _623_t1 = (function0) _629_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _623_t2 = _623_t1();
    $line_idx--;
    _623_t3 = 0;
    _623_t4 = _623_t2.tag;
    _623_t5 = _623_t4==_623_t3;
    if (_623_t5) {
        goto BB738;
    } else {
        goto BB739;
    }
BB738:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB739:
    _623_t6 = 1;
    _623_t7 = _623_t2.tag;
    _623_t8 = _623_t7==_623_t6;
    if (_623_t8) {
        goto BB741;
    } else {
        goto BB745;
    }
BB741:
    _623_$retval = 239;
    return _623_$retval;
BB745:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _629_f(void){
    function0 _629_t0;
    struct struct1 _629_t1;
    uint64_t _629_t2;
    struct struct1 _629_$retval;
    _629_t0 = (function0) _631_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:15:\n    .ok(try g())\n             ^";
    _629_t1 = _629_t0();
    $line_idx--;
    _629_t2 = _629_t1.tag;
    if (_629_t2) {
        goto BB731;
    } else {
        goto BB733;
    }
BB731:
    _629_$retval = _629_t1;
    return _629_$retval;
BB733:
    _629_$retval = (struct struct1) {.tag=0, ._0=(_629_t1._0)};
    return _629_$retval;
}

struct struct1 _631_g(void){
    struct struct1 _631_$retval;
    _631_$retval = (struct struct1) {.tag=1};
    return _631_$retval;
}


int main(void) {
  printf("%ld",_623_main());
  return 0;
}
