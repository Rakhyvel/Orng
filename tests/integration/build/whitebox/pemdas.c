/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1637_main(void);

/* Function definitions */
int64_t _1637_main(void){
    int64_t _1638_x;
    int64_t* _1638_y;
    int64_t _1637_t3;
    uint8_t _1637_t5;
    int64_t _1637_t2;
    int64_t _1637_$retval;
    int64_t _1640_z;
    int64_t* _1637_t7;
    int64_t _1637_t10;
    int64_t _1637_t11;
    int64_t _1637_t13;
    int64_t _1637_t14;
    int64_t _1637_t17;
    _1638_x = 0;
    _1638_y = &_1638_x;
    _1637_t3 = 0;
    _1637_t5 = *_1638_y==_1637_t3;
    if (_1637_t5) {
        goto BB1936;
    } else {
        goto BB1940;
    }
BB1936:
    _1640_z = *_1638_y;
    _1637_t7 = &_1640_z;
    *_1637_t7 = $add_int64_t(_1640_z, _1640_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1640_z = $sub_int64_t(_1640_z, _1640_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1640_z = $mult_int64_t(_1640_z, _1640_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1637_t10 = 1;
    _1637_t11 = $add_int64_t(_1640_z, _1637_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1640_z = $div_int64_t(_1640_z, _1637_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1637_t13 = 1;
    _1637_t14 = $add_int64_t(_1640_z, _1637_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1640_z = $mod_int64_t(_1640_z, _1637_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1637_t17 = -1;
    _1640_z = $mult_int64_t(_1640_z, _1637_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1637_t2 = $mult_int64_t(_1640_z, _1637_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB1939;
BB1940:
    _1637_t2 = 1000;
    goto BB1939;
BB1939:
    _1637_$retval = _1637_t2;
    return _1637_$retval;
}

int main(void) {
  printf("%ld",_1637_main());
  return 0;
}
