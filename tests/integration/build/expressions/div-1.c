/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _673_main(void);
uint8_t _678_f(double _678_x);


/* Function definitions */
int64_t _673_main(void){
    function0 _673_t1;
    double _673_t3;
    uint8_t _673_t2;
    int64_t _673_t0;
    int64_t _673_$retval;
    _673_t1 = _678_f;
    _673_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _673_t2 = _673_t1(_673_t3);
    $line_idx--;
    if (_673_t2) {
        goto BB816;
    } else {
        goto BB820;
    }
BB816:
    _673_t0 = 190;
    goto BB819;
BB820:
    _673_t0 = 4;
    goto BB819;
BB819:
    _673_$retval = _673_t0;
    return _673_$retval;
}

uint8_t _678_f(double _678_x){
    uint8_t _678_t3;
    uint8_t _678_t2;
    uint8_t _678_$retval;
    _678_t3 = _678_x==_678_x;
    if (_678_t3) {
        goto BB811;
    } else {
        goto BB814;
    }
BB811:
    _678_t2 = 1;
    goto BB813;
BB814:
    _678_t2 = 0;
    goto BB813;
BB813:
    _678_$retval = _678_t2;
    return _678_$retval;
}


int main(void) {
  printf("%ld",_673_main());
  return 0;
}
