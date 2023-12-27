/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t* _0;
        int64_t* _1;
} struct1;

typedef uint8_t(*function0)(int64_t*, int64_t*);

/* Function forward definitions */
int64_t _627_main(void);
uint8_t _632_addr_equal(int64_t* _632_x,int64_t* _632_y);

/* Function definitions */
int64_t _627_main(void){
    int64_t _628_x;
    int64_t _628_y;
    function0 _627_t3;
    int64_t* _627_t5;
    int64_t* _627_t6;
    uint8_t _627_t4;
    function0 _627_t7;
    int64_t* _627_t9;
    int64_t* _627_t10;
    uint8_t _627_t8;
    int64_t _627_t2;
    int64_t _627_$retval;
    _628_x = 4;
    _628_y = 4;
    _627_t3 = _632_addr_equal;
    _627_t5 = &_628_x;
    _627_t6 = &_628_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _627_t4 = _627_t3(_627_t5, _627_t6);
    $line_idx--;
    if (_627_t4) {
        goto BB786;
    } else {
        goto BB791;
    }
BB786:
    _627_t7 = _632_addr_equal;
    _627_t9 = &_628_x;
    _627_t10 = &_628_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _627_t8 = _627_t7(_627_t9, _627_t10);
    $line_idx--;
    if (_627_t8) {
        goto BB791;
    } else {
        goto BB787;
    }
BB791:
    _627_t2 = -3;
    goto BB790;
BB787:
    _627_t2 = 236;
    goto BB790;
BB790:
    _627_$retval = _627_t2;
    return _627_$retval;
}

uint8_t _632_addr_equal(int64_t* _632_x,int64_t* _632_y){
    uint8_t _632_t1;
    uint8_t _632_t0;
    uint8_t _632_$retval;
    _632_t1 = _632_x==_632_y;
    if (_632_t1) {
        goto BB781;
    } else {
        goto BB784;
    }
BB781:
    _632_t0 = 1;
    goto BB783;
BB784:
    _632_t0 = 0;
    goto BB783;
BB783:
    _632_$retval = _632_t0;
    return _632_$retval;
}

int main(void) {
  printf("%ld",_627_main());
  return 0;
}
