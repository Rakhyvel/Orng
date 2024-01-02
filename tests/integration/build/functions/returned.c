/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function1)(int64_t);

typedef function1(*function0)(void);

/* Function forward definitions */
int64_t _993_main(void);
function1 _995_f(void);
int64_t _997_add_four(int64_t _997_x);

/* Function definitions */
int64_t _993_main(void){
    function0 _993_t0;
    function1 _993_t1;
    int64_t _993_t3;
    int64_t _993_t2;
    int64_t _993_$retval;
    _993_t0 = _995_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _993_t1 = _993_t0();
    $line_idx--;
    _993_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _993_t2 = _993_t1(_993_t3);
    $line_idx--;
    _993_$retval = _993_t2;
    return _993_$retval;
}

function1 _995_f(void){
    function1 _995_$retval;
    _995_$retval = _997_add_four;
    return _995_$retval;
}

int64_t _997_add_four(int64_t _997_x){
    int64_t _997_t0;
    int64_t _997_$retval;
    _997_t0 = 4;
    _997_$retval = $add_int64_t(_997_x, _997_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _997_$retval;
}

int main(void) {
  printf("%ld",_993_main());
  return 0;
}
