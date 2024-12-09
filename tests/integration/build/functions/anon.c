/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    function0 _0;
    int64_t _1;
};

typedef int64_t(*function1)(function0, int64_t);

/* Function forward definitions */
int64_t _942_main(void);
int64_t _944_$anon95(int64_t _944_x);
int64_t _946_apply(function0 _946_f, int64_t _946_x);


/* Function definitions */
int64_t _942_main(void){
    function0 _943_id;
    function1 _942_t2;
    int64_t _942_t4;
    int64_t _942_t3;
    int64_t _942_$retval;
    _943_id = (function0) _944_$anon95;
    _942_t2 = (function1) _946_apply;
    _942_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _942_t3 = _942_t2(_943_id, _942_t4);
    $line_idx--;
    _942_$retval = _942_t3;
    return _942_$retval;
}

int64_t _944_$anon95(int64_t _944_x){
    int64_t _944_$retval;
    goto BB1123;
BB1123:
    _944_$retval = _944_x;
    return _944_$retval;
}

int64_t _946_apply(function0 _946_f, int64_t _946_x){
    int64_t _946_t0;
    int64_t _946_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _946_t0 = _946_f(_946_x);
    $line_idx--;
    _946_$retval = _946_t0;
    return _946_$retval;
}


int main(void) {
  printf("%ld",_942_main());
  return 0;
}
