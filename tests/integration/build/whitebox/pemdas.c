/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1632_main(void);

/* Function definitions */
int64_t _1632_main(void){
    int64_t _1633_x;
    int64_t* _1633_y;
    int64_t _1632_t3;
    uint8_t _1632_t5;
    int64_t _1632_t2;
    int64_t _1632_$retval;
    int64_t _1636_z;
    int64_t* _1632_t7;
    int64_t _1632_t10;
    int64_t _1632_t11;
    int64_t _1632_t13;
    int64_t _1632_t14;
    int64_t _1632_t17;
    _1633_x = 0;
    _1633_y = &_1633_x;
    _1632_t3 = 0;
    _1632_t5 = *_1633_y == _1632_t3;
    if (_1632_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1636_z = *_1633_y;
    _1632_t7 = &_1636_z;
    *_1632_t7 = $add_int64_t(_1636_z, _1636_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1636_z = $sub_int64_t(_1636_z, _1636_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1636_z = $mult_int64_t(_1636_z, _1636_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1632_t10 = 1;
    _1632_t11 = $add_int64_t(_1636_z, _1632_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1636_z = $div_int64_t(_1636_z, _1632_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1632_t13 = 1;
    _1632_t14 = $add_int64_t(_1636_z, _1632_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1636_z = $mod_int64_t(_1636_z, _1632_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1632_t17 = -1;
    _1636_z = $mult_int64_t(_1636_z, _1632_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1632_t2 = $mult_int64_t(_1636_z, _1632_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _1632_t2 = 1000;
    goto BB6;
BB6:
    _1632_$retval = _1632_t2;
    return _1632_$retval;
}

int main(void) {
  printf("%ld",_1632_main());
  return 0;
}
