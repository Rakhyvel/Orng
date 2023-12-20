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
int64_t _977_main(void);
function1 _979_f(void);
int64_t _981_add_four(int64_t _981_x);

/* Function definitions */
int64_t _977_main(void){
    function0 _977_t0;
    function1 _977_t1;
    int64_t _977_t3;
    int64_t _977_t2;
    int64_t _977_$retval;
    _977_t0 = _979_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _977_t1 = _977_t0();
    $line_idx--;
    _977_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _977_t2 = _977_t1(_977_t3);
    $line_idx--;
    _977_$retval = _977_t2;
    return _977_$retval;
}

function1 _979_f(void){
    function1 _979_$retval;
    _979_$retval = _981_add_four;
    return _979_$retval;
}

int64_t _981_add_four(int64_t _981_x){
    int64_t _981_t0;
    int64_t _981_$retval;
    _981_t0 = 4;
    _981_$retval = $add_int64_t(_981_x, _981_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _981_$retval;
}

int main(void) {
  printf("%ld",_977_main());
  return 0;
}
