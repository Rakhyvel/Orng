/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _388_main(void);
int64_t _390_f(void);
int64_t _392_g(void);

/* Function definitions */
int64_t _388_main(void){
    function0 _388_t0;
    int64_t _388_t1;
    int64_t _388_$retval;
    _388_t0 = _390_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _388_t1 = _388_t0();
    $line_idx--;
    _388_$retval = _388_t1;
    return _388_$retval;
}

int64_t _390_f(void){
    function0 _390_t0;
    int64_t _390_t1;
    int64_t _390_$retval;
    _390_t0 = _392_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _390_t1 = _390_t0();
    $line_idx--;
    _390_$retval = _390_t1;
    return _390_$retval;
}

int64_t _392_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_388_main());
  return 0;
}
