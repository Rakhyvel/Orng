/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct1;

typedef struct {
    uint64_t tag;
    union {
        struct1 _0;
        int64_t _1;
    };
} struct0;

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct1 _1_main();
struct0 _3_fizzbuzz(int64_t _3_n);

/* Function definitions */
struct1 _1_main() {
    struct0 _1_t0;
    struct1 _1_$retval;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _1_t0 = _3_fizzbuzz(30);
    $line_idx--;
    _1_$retval = _1_t0._0;
    return _1_$retval;
}

struct0 _3_fizzbuzz(int64_t _3_n) {
    int64_t _3_t1;
    struct0 _3_t0;
    struct0 _3_$retval;
    _3_t1 = 0;
    if (_3_n % 15) {
        goto BB7;
    } else {
        goto BB4;
    }
BB7:
    if (_3_t1 == _3_n % 5) {
        goto BB10;
    } else {
        goto BB11;
    }
BB4:
    _3_t0 = (struct0) {.tag=0, ._0=(struct1) {string_0, 9}};
    goto BB6;
BB10:
    _3_t0 = (struct0) {.tag=0, ._0=(struct1) {string_1, 5}};
    goto BB6;
BB11:
    if (_3_t1 == _3_n % 3) {
        goto BB14;
    } else {
        goto BB16;
    }
BB6:
    _3_$retval = _3_t0;
    return _3_$retval;
BB14:
    _3_t0 = (struct0) {.tag=0, ._0=(struct1) {string_2, 5}};
    goto BB6;
BB16:
    _3_t0 = (struct0) {.tag=1, ._1=_3_n};
    goto BB6;
}

int main()
{
  printf("%s",_1_main()._0);
  return 0;
}
