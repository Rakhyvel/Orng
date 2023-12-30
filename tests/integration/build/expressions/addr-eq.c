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
int64_t _639_main(void);
uint8_t _644_addr_equal(int64_t* _644_x, int64_t* _644_y);

/* Function definitions */
int64_t _639_main(void){
    int64_t _640_x;
    int64_t _640_y;
    function0 _639_t3;
    int64_t* _639_t5;
    int64_t* _639_t6;
    uint8_t _639_t4;
    function0 _639_t7;
    int64_t* _639_t9;
    int64_t* _639_t10;
    uint8_t _639_t8;
    int64_t _639_t2;
    int64_t _639_$retval;
    _640_x = 4;
    _640_y = 4;
    _639_t3 = _644_addr_equal;
    _639_t5 = &_640_x;
    _639_t6 = &_640_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _639_t4 = _639_t3(_639_t5, _639_t6);
    $line_idx--;
    if (_639_t4) {
        goto BB796;
    } else {
        goto BB801;
    }
BB796:
    _639_t7 = _644_addr_equal;
    _639_t9 = &_640_x;
    _639_t10 = &_640_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _639_t8 = _639_t7(_639_t9, _639_t10);
    $line_idx--;
    if (_639_t8) {
        goto BB801;
    } else {
        goto BB797;
    }
BB801:
    _639_t2 = -3;
    goto BB800;
BB797:
    _639_t2 = 236;
    goto BB800;
BB800:
    _639_$retval = _639_t2;
    return _639_$retval;
}

uint8_t _644_addr_equal(int64_t* _644_x, int64_t* _644_y){
    uint8_t _644_t1;
    uint8_t _644_t0;
    uint8_t _644_$retval;
    _644_t1 = _644_x==_644_y;
    if (_644_t1) {
        goto BB791;
    } else {
        goto BB794;
    }
BB791:
    _644_t0 = 1;
    goto BB793;
BB794:
    _644_t0 = 0;
    goto BB793;
BB793:
    _644_$retval = _644_t0;
    return _644_$retval;
}

int main(void) {
  printf("%ld",_639_main());
  return 0;
}
