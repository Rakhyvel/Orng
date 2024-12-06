/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _1082_main(void);
int64_t _1084_$anon104(void);
int64_t _1086_$anon105(void);


/* Function definitions */
int64_t _1082_main(void){
    function0 _1082_t0;
    int64_t _1082_t1;
    int64_t _1082_$retval;
    _1082_t0 = (function0) _1084_$anon104;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:10:11:\n    tempa(149)\n         ^";
    _1082_t1 = _1082_t0();
    $line_idx--;
    _1082_$retval = _1082_t1;
    return _1082_$retval;
}

int64_t _1084_$anon104(void){
    function0 _1084_t1;
    int64_t _1084_t2;
    int64_t _1084_t3;
    int64_t _1084_$retval;
    _1084_t1 = (function0) _1086_$anon105;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:6:11:\n    tempb(n + 1) + 19\n         ^";
    _1084_t2 = _1084_t1();
    $line_idx--;
    _1084_t3 = 19;
    _1084_$retval = $add_int64_t(_1084_t2, _1084_t3, "tests/integration/generics/template-in-template.orng:6:19:\n    tempb(n + 1) + 19\n                 ^");
    return _1084_$retval;
}

int64_t _1086_$anon105(void){
    int64_t _1086_$retval;
    _1086_$retval = 300;
    return _1086_$retval;
}


int main(void) {
  printf("%ld",_1082_main());
  return 0;
}
