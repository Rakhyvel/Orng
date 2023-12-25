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
    function0 _627_t4;
    int64_t* _627_t6;
    int64_t* _627_t7;
    uint8_t _627_t5;
    function0 _627_t8;
    int64_t* _627_t10;
    int64_t* _627_t11;
    uint8_t _627_t9;
    int64_t _627_t2;
    int64_t _627_$retval;
    _628_x = 4;
    _628_y = 4;
    _627_t4 = _632_addr_equal;
    _627_t6 = &_628_x;
    _627_t7 = &_628_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _627_t5 = _627_t4(_627_t6, _627_t7);
    $line_idx--;
    if (_627_t5) {
        goto BB812;
    } else {
        goto BB818;
    }
BB812:
    _627_t8 = _632_addr_equal;
    _627_t10 = &_628_x;
    _627_t11 = &_628_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _627_t9 = _627_t8(_627_t10, _627_t11);
    $line_idx--;
    if (_627_t9) {
        goto BB818;
    } else {
        goto BB814;
    }
BB818:
    _627_t2 = -3;
    goto BB817;
BB814:
    _627_t2 = 236;
    goto BB817;
BB817:
    _627_$retval = _627_t2;
    return _627_$retval;
}

uint8_t _632_addr_equal(int64_t* _632_x,int64_t* _632_y){
    uint8_t _632_t1;
    uint8_t _632_t0;
    uint8_t _632_$retval;
    _632_t1 = _632_x==_632_y;
    if (_632_t1) {
        goto BB807;
    } else {
        goto BB810;
    }
BB807:
    _632_t0 = 1;
    goto BB809;
BB810:
    _632_t0 = 0;
    goto BB809;
BB809:
    _632_$retval = _632_t0;
    return _632_$retval;
}

int main(void) {
  printf("%ld",_627_main());
  return 0;
}
