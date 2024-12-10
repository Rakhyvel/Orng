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
int64_t _957_main(void);
int64_t _959_$anon98(int64_t _959_x);
int64_t _961_apply(function0 _961_f, int64_t _961_x);


/* Function definitions */
int64_t _957_main(void){
    function0 _958_id;
    function1 _957_t2;
    int64_t _957_t4;
    int64_t _957_t3;
    int64_t _957_$retval;
    _958_id = (function0) _959_$anon98;
    _957_t2 = (function1) _961_apply;
    _957_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _957_t3 = _957_t2(_958_id, _957_t4);
    $line_idx--;
    _957_$retval = _957_t3;
    return _957_$retval;
}

int64_t _959_$anon98(int64_t _959_x){
    int64_t _959_$retval;
    goto BB1139;
BB1139:
    _959_$retval = _959_x;
    return _959_$retval;
}

int64_t _961_apply(function0 _961_f, int64_t _961_x){
    int64_t _961_t0;
    int64_t _961_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _961_t0 = _961_f(_961_x);
    $line_idx--;
    _961_$retval = _961_t0;
    return _961_$retval;
}


int main(void) {
  printf("%ld",_957_main());
  return 0;
}
