/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _66_main(void);
int64_t _68_f(uint8_t _68_b);


/* Function definitions */
int64_t _66_main(void){
    int64_t _67_x;
    int64_t* _67_y;
    function0 _66_t4;
    int64_t _66_t6;
    uint8_t _66_t8;
    uint8_t _66_t7;
    uint8_t _66_t9;
    int64_t _66_t5;
    int64_t _66_$retval;
    _67_x = 0;
    _67_y = &_67_x;
    _66_t4 = (function0) _68_f;
    _66_t6 = 1;
    _66_t8 = *_67_y==_66_t6;
    if (_66_t8) {
        goto BB110;
    } else {
        goto BB113;
    }
BB110:
    _66_t7 = 1;
    goto BB111;
BB113:
    _66_t7 = 0;
    goto BB111;
BB111:
    _66_t9 = !_66_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _66_t5 = _66_t4(_66_t9);
    $line_idx--;
    _66_$retval = _66_t5;
    return _66_$retval;
}

int64_t _68_f(uint8_t _68_b){
    uint8_t _68_t0;
    uint8_t _68_t1;
    int64_t _68_t2;
    int64_t _68_$retval;
    _68_t0 = !_68_b;
    _68_b = _68_t0;
    _68_t1 = !_68_t0;
    _68_b = _68_t1;
    if (_68_t0) {
        goto BB107;
    } else {
        goto BB103;
    }
BB107:
    _68_t2 = 10;
    goto BB106;
BB103:
    _68_t2 = 31;
    goto BB106;
BB106:
    _68_$retval = _68_t2;
    return _68_$retval;
}


int main(void) {
  printf("%ld",_66_main());
  return 0;
}
