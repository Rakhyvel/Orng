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
int64_t _930_main(void);
int64_t _932_$anon93(int64_t _932_x);
int64_t _934_apply(function0 _934_f, int64_t _934_x);


/* Function definitions */
int64_t _930_main(void){
    function0 _931_id;
    function1 _930_t1;
    int64_t _930_t3;
    int64_t _930_t2;
    int64_t _930_$retval;
    _931_id = _932_$anon93;
    _930_t1 = _934_apply;
    _930_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _930_t2 = _930_t1(_931_id, _930_t3);
    $line_idx--;
    _930_$retval = _930_t2;
    return _930_$retval;
}

int64_t _932_$anon93(int64_t _932_x){
    int64_t _932_$retval;
    _932_$retval = _932_x;
    return _932_$retval;
}

int64_t _934_apply(function0 _934_f, int64_t _934_x){
    int64_t _934_t0;
    int64_t _934_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _934_t0 = _934_f(_934_x);
    $line_idx--;
    _934_$retval = _934_t0;
    return _934_$retval;
}


int main(void) {
  printf("%ld",_930_main());
  return 0;
}
