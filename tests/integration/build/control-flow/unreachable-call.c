/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _548_main(void);
int64_t _550_f(void);
int64_t _552_g(void);

/* Function definitions */
int64_t _548_main(void){
    function0 _548_t0;
    int64_t _548_t1;
    int64_t _548_$retval;
    _548_t0 = _550_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _548_t1 = _548_t0();
    $line_idx--;
    _548_$retval = _548_t1;
    return _548_$retval;
}

int64_t _550_f(void){
    function0 _550_t0;
    int64_t _550_t1;
    int64_t _550_$retval;
    _550_t0 = _552_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _550_t1 = _550_t0();
    $line_idx--;
    _550_$retval = _550_t1;
    return _550_$retval;
}

int64_t _552_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_548_main());
  return 0;
}
