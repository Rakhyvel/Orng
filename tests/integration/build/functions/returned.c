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
int64_t _990_main(void);
function1 _992_f(void);
int64_t _994_add_four(int64_t _994_x);

/* Function definitions */
int64_t _990_main(void){
    function0 _990_t0;
    function1 _990_t1;
    int64_t _990_t3;
    int64_t _990_t2;
    int64_t _990_$retval;
    _990_t0 = _992_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _990_t1 = _990_t0();
    $line_idx--;
    _990_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _990_t2 = _990_t1(_990_t3);
    $line_idx--;
    _990_$retval = _990_t2;
    return _990_$retval;
}

function1 _992_f(void){
    function1 _992_$retval;
    _992_$retval = _994_add_four;
    return _992_$retval;
}

int64_t _994_add_four(int64_t _994_x){
    int64_t _994_t0;
    int64_t _994_$retval;
    _994_t0 = 4;
    _994_$retval = $add_int64_t(_994_x, _994_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _994_$retval;
}

int main(void) {
  printf("%ld",_990_main());
  return 0;
}
