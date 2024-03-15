/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1826_main(void);


/* Function definitions */
int64_t _1826_main(void){
    int64_t _1827_x;
    int64_t* _1827_y;
    int64_t _1826_t5;
    uint8_t _1826_t7;
    int64_t _1826_t4;
    int64_t _1826_$retval;
    int64_t _1829_z;
    int64_t* _1826_t10;
    int64_t _1826_t13;
    int64_t _1826_t14;
    int64_t _1826_t16;
    int64_t _1826_t17;
    int64_t _1826_t20;
    _1827_x = 0;
    _1827_y = &_1827_x;
    _1826_t5 = 0;
    _1826_t7 = *_1827_y==_1826_t5;
    if (_1826_t7) {
        goto BB2068;
    } else {
        goto BB2072;
    }
BB2068:
    _1829_z = *_1827_y;
    _1826_t10 = &_1829_z;
    *_1826_t10 = $add_int64_t(_1829_z, _1829_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1829_z = $sub_int64_t(_1829_z, _1829_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1829_z = $mult_int64_t(_1829_z, _1829_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1826_t13 = 1;
    _1826_t14 = $add_int64_t(_1829_z, _1826_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1829_z = $div_int64_t(_1829_z, _1826_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1826_t16 = 1;
    _1826_t17 = $add_int64_t(_1829_z, _1826_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1829_z = $mod_int64_t(_1829_z, _1826_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1826_t20 = -1;
    _1829_z = $mult_int64_t(_1829_z, _1826_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1826_t4 = $mult_int64_t(_1829_z, _1826_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2071;
BB2072:
    _1826_t4 = 1000;
    goto BB2071;
BB2071:
    _1826_$retval = _1826_t4;
    return _1826_$retval;
}


int main(void) {
  printf("%ld",_1826_main());
  return 0;
}
