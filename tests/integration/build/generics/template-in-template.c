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
int64_t _1095_main(void);
int64_t _1097_$anon106(void);
int64_t _1099_$anon107(void);


/* Function definitions */
int64_t _1095_main(void){
    function0 _1095_t0;
    int64_t _1095_t1;
    int64_t _1095_$retval;
    _1095_t0 = (function0) _1097_$anon106;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:10:11:\n    tempa(149)\n         ^";
    _1095_t1 = _1095_t0();
    $line_idx--;
    _1095_$retval = _1095_t1;
    return _1095_$retval;
}

int64_t _1097_$anon106(void){
    function0 _1097_t1;
    int64_t _1097_t2;
    int64_t _1097_t3;
    int64_t _1097_$retval;
    _1097_t1 = (function0) _1099_$anon107;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:6:11:\n    tempb(n + 1) + 19\n         ^";
    _1097_t2 = _1097_t1();
    $line_idx--;
    _1097_t3 = 19;
    _1097_$retval = $add_int64_t(_1097_t2, _1097_t3, "tests/integration/generics/template-in-template.orng:6:19:\n    tempb(n + 1) + 19\n                 ^");
    return _1097_$retval;
}

int64_t _1099_$anon107(void){
    int64_t _1099_$retval;
    _1099_$retval = 300;
    return _1099_$retval;
}


int main(void) {
  printf("%ld",_1095_main());
  return 0;
}
