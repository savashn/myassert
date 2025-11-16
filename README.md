# myassert

This is a single header file type-safe C assertion and testing library.

## Table of Contents

1. [API](#api)
    1. [Basic Assertions](#basic-assertions)
    2. [Boolean](#boolean)
    3. [Integer](#integer)
    4. [Type-Safe Integer](#type-safe-integer)
    5. [Float/Double](#float-double)
    6. [String](#string)
    7. [Memory](#memory)
    8. [Status Code Checking](#status-code-checking)
    9. [Running](#running)
2. [Usage](#usage)

## API

### Basic Assertions

#### `ASSERT(expr)`

Basic assertion that checks if expression is true.

```c
ASSERT(x > 0);  // Fails if x <= 0
```

#### `FATAL(msg)`

Prints fatal error message and terminates program.

```c
FATAL("Critical system failure");
```

### Boolean

#### `ASSERT_TRUE(a)`, `ASSERT_FALSE(a)`

Boolean value assertions.

```c
ASSERT_TRUE(is_valid);
ASSERT_FALSE(has_error);
```

#### `ASSERT_NULL(a)`, `ASSERT_NOT_NULL(a)`

Pointer null checks.

```c
ASSERT_NOT_NULL(buffer);
ASSERT_NULL(freed_ptr);
```

### Integer

Basic integer comparisons using int64_t casting:

- `ASSERT_EQ(a, b)` - Equal (==)
- `ASSERT_NE(a, b)` - Not equal (!=)  
- `ASSERT_LT(a, b)` - Less than (<)
- `ASSERT_LE(a, b)` - Less or equal (<=)
- `ASSERT_GT(a, b)` - Greater than (>)
- `ASSERT_GE(a, b)` - Greater or equal (>=)

```c
ASSERT_EQ(result, 42);
ASSERT_LT(count, MAX_SIZE);
```

### Type-Safe Integer

Type-checked versions that prevent implicit conversions:

#### INT8_T

- `ASSERT_EQ_INT8(a, b)`, `ASSERT_NE_INT8(a, b)`
- `ASSERT_LT_INT8(a, b)`, `ASSERT_LE_INT8(a, b)`  
- `ASSERT_GT_INT8(a, b)`, `ASSERT_GE_INT8(a, b)`

#### UINT8_T

- `ASSERT_EQ_UINT8(a, b)`, `ASSERT_NE_UINT8(a, b)`
- `ASSERT_LT_UINT8(a, b)`, `ASSERT_LE_UINT8(a, b)`
- `ASSERT_GT_UINT8(a, b)`, `ASSERT_GE_UINT8(a, b)`

#### INT16_T, UINT16_T, INT32_T, UINT32_T, INT64_T, UINT64_T

Same pattern as above for all integer types.

#### SIZE_T
- `ASSERT_EQ_SIZE(a, b)`, `ASSERT_NE_SIZE(a, b)`
- `ASSERT_LT_SIZE(a, b)`, `ASSERT_LE_SIZE(a, b)`
- `ASSERT_GT_SIZE(a, b)`, `ASSERT_GE_SIZE(a, b)`

#### CHAR
- `ASSERT_EQ_CHAR(a, b)`, `ASSERT_NE_CHAR(a, b)`
- `ASSERT_EQ_UCHAR(a, b)`, `ASSERT_NE_UCHAR(a, b)`

```c
int8_t a = 10, b = 20;
ASSERT_LT_INT8(a, b);  // OK

uint32_t x = 100;
int32_t y = 100;
ASSERT_EQ_UINT32(x, y);  // COMPILE ERROR: Type mismatch!
```

### Float/Double

Epsilon-based floating point comparisons for precise equality checking:

#### FLOAT

- `ASSERT_FLOAT_EQ(a, b, epsilon)` - Float equality with tolerance
- `ASSERT_FLOAT_NE(a, b, epsilon)` - Float inequality with tolerance

#### DOUBLE  

- `ASSERT_DOUBLE_EQ(a, b, epsilon)` - Double equality with tolerance
- `ASSERT_DOUBLE_NE(a, b, epsilon)` - Double inequality with tolerance

```c
float a = 0.1f + 0.2f;
float b = 0.3f;
ASSERT_FLOAT_EQ(a, b, 1e-6f);

double precise = calculate_pi();
ASSERT_DOUBLE_EQ(precise, 3.14159265, 1e-9);
```

For simple magnitude comparisons without precision concerns, use regular integer assertions:

```c
ASSERT_GT(temperature, 0.0);
```

### String

- `ASSERT_STR_EQ(a, b)` - Strings equal
- `ASSERT_STR_NE(a, b)` - Strings not equal
- `ASSERT_STR_EQ_LEN(a, b, len)` - First len chars equal
- `ASSERT_STR_NE_LEN(a, b, len)` - First len chars not equal

```c
ASSERT_STR_EQ(name, "John");
ASSERT_STR_EQ_LEN(prefix, "test_", 5);
```

### Memory

- `ASSERT_MEM_EQ(a, b, len)` - Memory blocks equal
- `ASSERT_MEM_NE(a, b, len)` - Memory blocks not equal

```c
ASSERT_MEM_EQ(buffer1, buffer2, sizeof(buffer1));
```

### Status Code Checking

#### `ASSERT_OK(a)`

Checks if return code is 0 (success).

```c
ASSERT_OK(function_call());  // Fails if non-zero returned
```

### Running

#### Test Status

```c
enum TestStatus {
    TEST_OK = 0,
    TEST_SKIP = 1
};
```

#### Test Control

- `RETURN_OK()` - Mark test as passed
- `RETURN_SKIP(explanation)` - Skip test with reason
- `RUN_TEST(test_func)` - Execute and report test result

```c
int test_example() {
    ASSERT_EQ(2 + 2, 4);
    RETURN_OK();
}

int main() {
    RUN_TEST(test_example);
    return 0;
}
```

## Usage

```c
#include "myassert.h"

int test_function() {
    uint32_t size = 100;
    ASSERT_GT_UINT32(size, 0);
    
    char* buffer = malloc(size);
    ASSERT_NOT_NULL(buffer);
    
    ASSERT_STR_EQ(get_name(), "expected");
    
    free(buffer);
    RETURN_OK();
}
```

## License

Lisences under [MIT](/LICENSE).
