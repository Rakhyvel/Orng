/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function1)(int64_t);

typedef function1(*function0)(void);

/* Function forward definitions */
int64_t _1010_main(void);
function1 _1012_f(void);
int64_t _1014_add_four(int64_t _1014_x);

/* Function definitions */
int64_t _1010_main(void){
    function0 _1010_t0;
    function1 _1010_t1;
    int64_t _1010_t3;
    int64_t _1010_t2;
    int64_t _1010_$retval;
    _1010_t0 = _1012_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1010_t1 = _1010_t0();
    $line_idx--;
    _1010_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1010_t2 = _1010_t1(_1010_t3);
    $line_idx--;
    _1010_$retval = _1010_t2;
    return _1010_$retval;
}

function1 _1012_f(void){
    function1 _1012_$retval;
    _1012_$retval = _1014_add_four;
    return _1012_$retval;
}

int64_t _1014_add_four(int64_t _1014_x){
    int64_t _1014_t0;
    int64_t _1014_$retval;
    _1014_t0 = 4;
    _1014_$retval = $add_int64_t(_1014_x, _1014_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1014_$retval;
}

int main(void) {
  printf("%ld",_1010_main());
  return 0;
}
