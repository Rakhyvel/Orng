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
int64_t _923_main(void);
int64_t _925_$anon93(int64_t _925_x);
int64_t _927_apply(function0 _927_f, int64_t _927_x);


/* Function definitions */
int64_t _923_main(void){
    function0 _924_id;
    function1 _923_t2;
    int64_t _923_t4;
    int64_t _923_t3;
    int64_t _923_$retval;
    _924_id = (function0) _925_$anon93;
    _923_t2 = (function1) _927_apply;
    _923_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _923_t3 = _923_t2(_924_id, _923_t4);
    $line_idx--;
    _923_$retval = _923_t3;
    return _923_$retval;
}

int64_t _925_$anon93(int64_t _925_x){
    int64_t _925_$retval;
    _925_$retval = _925_x;
    return _925_$retval;
}

int64_t _927_apply(function0 _927_f, int64_t _927_x){
    int64_t _927_t0;
    int64_t _927_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _927_t0 = _927_f(_927_x);
    $line_idx--;
    _927_$retval = _927_t0;
    return _927_$retval;
}


int main(void) {
  printf("%ld",_923_main());
  return 0;
}
