/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1629_main(void);

/* Function definitions */
int64_t _1629_main(void){
    int64_t _1630_x;
    int64_t* _1630_y;
    int64_t _1629_t3;
    uint8_t _1629_t5;
    int64_t _1629_t2;
    int64_t _1629_$retval;
    int64_t _1632_z;
    int64_t* _1629_t7;
    int64_t _1629_t10;
    int64_t _1629_t11;
    int64_t _1629_t13;
    int64_t _1629_t14;
    int64_t _1629_t17;
    _1630_x = 0;
    _1630_y = &_1630_x;
    _1629_t3 = 0;
    _1629_t5 = *_1630_y==_1629_t3;
    if (_1629_t5) {
        goto BB1940;
    } else {
        goto BB1944;
    }
BB1940:
    _1632_z = *_1630_y;
    _1629_t7 = &_1632_z;
    *_1629_t7 = $add_int64_t(_1632_z, _1632_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1632_z = $sub_int64_t(_1632_z, _1632_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1632_z = $mult_int64_t(_1632_z, _1632_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1629_t10 = 1;
    _1629_t11 = $add_int64_t(_1632_z, _1629_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1632_z = $div_int64_t(_1632_z, _1629_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1629_t13 = 1;
    _1629_t14 = $add_int64_t(_1632_z, _1629_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1632_z = $mod_int64_t(_1632_z, _1629_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1629_t17 = -1;
    _1632_z = $mult_int64_t(_1632_z, _1629_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1629_t2 = $mult_int64_t(_1632_z, _1629_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB1943;
BB1944:
    _1629_t2 = 1000;
    goto BB1943;
BB1943:
    _1629_$retval = _1629_t2;
    return _1629_$retval;
}

int main(void) {
  printf("%ld",_1629_main());
  return 0;
}
