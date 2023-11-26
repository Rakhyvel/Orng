/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _71_main(void);

/* Function definitions */
int64_t _71_main(void) {
    int64_t _72_x;
    int64_t* _72_y;
    int64_t _71_t3;
    uint8_t _71_t5;
    uint8_t _71_t4;
    int64_t _74_z;
    int64_t* _71_t7;
    int64_t _71_t10;
    int64_t _71_t11;
    int64_t _71_t13;
    int64_t _71_t14;
    int64_t _71_t17;
    int64_t _71_t2;
    int64_t _71_$retval;
    _72_x = 0;
    _72_y = &_72_x;
    _71_t3 = 0;
    _71_t5 = *_72_y == _71_t3;
    if (_71_t5) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _71_t4 = 1;
    goto BB2;
BB9:
    _71_t4 = 0;
    goto BB2;
BB2:
    if (_71_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _74_z = *_72_y;
    _71_t7 = &_74_z;
    *_71_t7 = $add_int64_t(_74_z, _74_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _74_z = $sub_int64_t(_74_z, _74_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _74_z = $mult_int64_t(_74_z, _74_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _71_t10 = 1;
    _71_t11 = $add_int64_t(_74_z, _71_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _74_z = $div_int64_t(_74_z, _71_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _71_t13 = 1;
    _71_t14 = $add_int64_t(_74_z, _71_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _74_z = $mod_int64_t(_74_z, _71_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _71_t17 = -1;
    _74_z = $mult_int64_t(_74_z, _71_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _71_t2 = $mult_int64_t(_74_z, _71_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _71_t2 = 1000;
    goto BB6;
BB6:
    _71_$retval = _71_t2;
    return _71_$retval;
}

int main(void) {
  printf("%ld",_71_main());
  return 0;
}
