/******************************************************************************
 * ============================================================================
 *  THE DEFINITIVE C PROGRAMMING LANGUAGE — COMPLETE REFERENCE
 * ============================================================================
 *
 *  A single-file, exhaustive, program-heavy guide to every topic in C.
 *  Each section has:
 *    1. THEORY as detailed block comments
 *    2. REAL-WORLD ANALOGY to make concepts intuitive
 *    3. WORKING CODE demonstrating the concept
 *
 *  Compile:
 *    gcc -std=c11 -Wall -Wextra -Wpedantic -lm -pthread -o c_master c_master.c
 *
 *  Run:
 *    ./c_master
 *
 * ============================================================================
 ******************************************************************************/

#include <stdio.h>      /* Standard I/O: printf, fprintf, fopen, fclose, etc. */
#include <stdlib.h>     /* General utilities: malloc, free, exit, qsort, etc. */
#include <string.h>     /* String handling: strlen, strcpy, memcpy, etc. */
#include <stdint.h>     /* Fixed-width integers: int32_t, uint64_t, etc. */
#include <stddef.h>     /* Common definitions: size_t, ptrdiff_t, NULL, offsetof */
#include <stdbool.h>    /* Boolean type: bool, true, false (C99) */
#include <limits.h>     /* Integer limits: INT_MAX, CHAR_BIT, etc. */
#include <float.h>      /* Floating-point limits: FLT_MAX, DBL_EPSILON, etc. */
#include <math.h>       /* Math functions: sin, cos, sqrt, pow, etc. */
#include <ctype.h>      /* Character classification: isalpha, isdigit, etc. */
#include <errno.h>      /* Error codes: errno, EDOM, ERANGE, etc. */
#include <assert.h>     /* Assertions: assert(), _Static_assert */
#include <stdarg.h>     /* Variadic functions: va_list, va_start, va_arg, va_end */
#include <setjmp.h>     /* Non-local jumps: setjmp, longjmp */
#include <signal.h>     /* Signal handling: signal, raise */
#include <time.h>       /* Date/time: time, clock, strftime */
#include <fenv.h>       /* Floating-point environment: rounding, exceptions */
#include <complex.h>    /* Complex numbers (C99): complex, I, creal, cimag */
#include <tgmath.h>     /* Type-generic math (C99): generic sin, cos, etc. */
#include <wchar.h>      /* Wide character I/O */
#include <wctype.h>     /* Wide character classification */
#include <locale.h>     /* Localization: setlocale */
#include <inttypes.h>   /* Integer format macros: PRId64, PRIu32, etc. */
#include <stdatomic.h>  /* Atomics (C11): atomic_int, atomic_store, etc. */
#include <pthread.h>    /* POSIX threads (not standard C, but ubiquitous) */

/* ============================================================================
 *  SECTION 1: PROGRAM STRUCTURE & COMPILATION MODEL
 * ============================================================================
 *
 * THEORY:
 * -------
 * Every C program begins execution at the `main` function. Before main runs,
 * the C Runtime (CRT) performs critical setup:
 *   1. The operating system loader maps the executable into memory
 *   2. The CRT's _start function is called (not main!)
 *   3. _start initializes the stack pointer
 *   4. .bss section is zeroed (uninitialized globals)
 *   5. .data section is copied from ROM/flash to RAM (initialized globals)
 *   6. atexit() handlers are set up
 *   7. main(argc, argv) is called
 *   8. After main returns, exit() flushes streams and calls atexit handlers
 *
 * COMPILATION PIPELINE:
 *   Source (.c) → Preprocessor (.i) → Compiler (.s) → Assembler (.o) → Linker (executable)
 *
 * TRANSLATION PHASES (ISO C defines 8):
 *   Phase 1: Map physical source file characters
 *   Phase 2: Splice lines ending with backslash-newline
 *   Phase 3: Tokenize (replace comments with single space)
 *   Phase 4: Execute preprocessor directives (#include, #define, #if)
 *   Phase 5: Map characters to execution character set
 *   Phase 6: Concatenate adjacent string literals
 *   Phase 7: Convert preprocessing tokens to actual tokens
 *   Phase 8: Resolve external references (linkage — done by linker)
 *
 * REAL-WORLD ANALOGY:
 *   Think of compilation like manufacturing a car:
 *   - Preprocessor = Reading the blueprint, expanding all references
 *   - Compiler = Converting blueprint into individual part specifications
 *   - Assembler = Manufacturing each part from specifications
 *   - Linker = Assembling all parts into a working car
 *   - Loader = Driving the car off the factory line onto the road (memory)
 *
 * HOW TO USE:
 *   gcc -std=c11 -Wall -Wextra -O2 -o program source.c -lm
 *   -std=c11    : Use C11 standard
 *   -Wall -Wextra : Enable most warnings
 *   -O2         : Optimization level 2
 *   -lm         : Link math library
 * ============================================================================
 */

/* atexit handler — called after main returns, in REVERSE registration order */
static void cleanup_handler_1(void) {
    /* printf("[atexit] Handler 1: First registered, last to run\n"); */
}

static void cleanup_handler_2(void) {
    /* printf("[atexit] Handler 2: Second registered, second-to-last\n"); */
}

/* GCC/Clang constructor — runs BEFORE main (not standard C, but widely supported) */
__attribute__((constructor))
static void before_main(void) {
    /* This runs before main — useful for library initialization */
}

/* GCC/Clang destructor — runs AFTER main and atexit handlers */
__attribute__((destructor))
static void after_main(void) {
    /* Cleanup after everything else */
}

static void section_01_program_structure(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 1: PROGRAM STRUCTURE & COMPILATION\n");
    printf("============================================================\n\n");

    /* Register atexit handlers — they execute in REVERSE order */
    atexit(cleanup_handler_1);
    atexit(cleanup_handler_2);

    printf("  Program execution flow:\n");
    printf("    OS Loader → _start → CRT init → main() → exit() → atexit handlers\n\n");

    /* main can have two standard signatures: */
    /* int main(void) { ... }                  */
    /* int main(int argc, char *argv[]) { ... } */

    printf("  main() return values:\n");
    printf("    return 0;          → success (same as EXIT_SUCCESS)\n");
    printf("    return EXIT_FAILURE; → failure (typically 1)\n");
    printf("    return EXIT_SUCCESS; → success (typically 0)\n\n");

    printf("  Compilation pipeline:\n");
    printf("    .c → [cpp] → .i → [cc1] → .s → [as] → .o → [ld] → executable\n\n");

    printf("  Key compiler flags:\n");
    printf("    -std=c11          Use C11 standard\n");
    printf("    -Wall -Wextra     Enable warnings\n");
    printf("    -Wpedantic        Strict ISO compliance\n");
    printf("    -O0/-O1/-O2/-O3   Optimization levels\n");
    printf("    -g                Debug symbols\n");
    printf("    -fsanitize=address Memory error detection\n");
    printf("    -fsanitize=undefined UB detection\n");
    printf("    -fsanitize=thread  Data race detection\n");
}


/* ============================================================================
 *  SECTION 2: LEXICAL ELEMENTS — TOKENS, KEYWORDS, IDENTIFIERS
 * ============================================================================
 *
 * THEORY:
 * -------
 * A C program is composed of TOKENS — the smallest meaningful units.
 * Six token categories:
 *   1. Keywords    : Reserved words (int, return, if, while, etc.)
 *   2. Identifiers : User-defined names (variables, functions, types)
 *   3. Constants   : Numeric values (42, 3.14, 'A', 0xFF)
 *   4. Strings     : "hello world"
 *   5. Operators   : +, -, *, /, ==, !=, etc.
 *   6. Punctuators : ; , { } [ ] ( )
 *
 * KEYWORDS BY STANDARD:
 *   C89 (32): auto break case char const continue default do double else enum
 *             extern float for goto if int long register return short signed
 *             sizeof static struct switch typedef union unsigned void volatile while
 *   C99 (+5): _Bool _Complex _Imaginary inline restrict
 *   C11 (+7): _Alignas _Alignof _Atomic _Generic _Noreturn _Static_assert _Thread_local
 *   C23 (+14): alignas alignof bool constexpr false true nullptr nullptr_t
 *              static_assert thread_local typeof typeof_unqual _BitInt
 *
 * IDENTIFIER RULES:
 *   - Must begin with letter (a-z, A-Z) or underscore (_)
 *   - Subsequent characters: letters, digits (0-9), underscores
 *   - Case-sensitive: myVar ≠ myvar ≠ MYVAR
 *   - Significant characters: 31 (internal), 6 (external) minimum in C99+
 *   - Cannot be a keyword
 *   - Convention: snake_case for variables/functions, UPPER_CASE for macros
 *
 * REAL-WORLD ANALOGY:
 *   Tokens are like words in a sentence. Just as English has nouns (identifiers),
 *   verbs (operators), and punctuation (punctuators), C has its own grammar.
 *   The compiler is like a strict English teacher — every token must follow rules.
 *
 * TRIGRAPHS (removed in C23):
 *   ??= → #    ??/ → \    ??' → ^    ??( → [    ??) → ]
 *   ??! → |    ??< → {    ??> → }    ??- → ~
 *
 * DIGRAPHS (still valid):
 *   <: → [    :> → ]    <% → {    %> → }    %: → #    %:%: → ##
 * ============================================================================
 */

static void section_02_lexical_elements(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 2: LEXICAL ELEMENTS\n");
    printf("============================================================\n\n");

    /* --- Integer constants in different bases --- */
    int decimal     = 42;         /* Decimal: no prefix */
    int octal       = 052;        /* Octal: leading 0 → 5*8 + 2 = 42 */
    int hex         = 0x2A;       /* Hexadecimal: leading 0x → 2*16 + 10 = 42 */
    /* int binary = 0b101010;     /* Binary (C23): leading 0b → 42 */

    printf("  Integer bases: decimal=%d, octal=%d, hex=%d (all equal 42)\n",
           decimal, octal, hex);

    /* Integer suffixes control the type of the constant */
    unsigned long long ull = 18446744073709551615ULL; /* ULL = unsigned long long */
    long long          ll  = 9223372036854775807LL;   /* LL = long long */
    unsigned int       ui  = 42u;                      /* u = unsigned */
    long               l   = 42L;                      /* L = long */
    printf("  Suffixes: ULL=%llu, LL=%lld, u=%u, L=%ld\n", ull, ll, ui, l);

    /* --- Floating-point constants --- */
    double      d  = 3.14;               /* double (default) */
    float       f  = 3.14f;              /* float suffix: f */
    long double ld = 3.14L;              /* long double suffix: L */
    double      sc = 314e-2;             /* Scientific: 314 × 10^-2 = 3.14 */
    double      hexf = 0x1.921fb5p+1;    /* Hex float (C99): pi ≈ 3.14159 */
    printf("  Floats: double=%f, float=%f, long double=%Lf\n", d, f, ld);
    printf("  Scientific: 314e-2 = %f\n", sc);
    printf("  Hex float: 0x1.921fb5p+1 = %.10f\n", hexf);

    /* --- Character constants and escape sequences --- */
    printf("\n  Escape sequences:\n");
    printf("    \\n  = newline       \\t  = tab\n");
    printf("    \\\\  = backslash     \\'  = single quote\n");
    printf("    \\\" = double quote   \\0  = null character\n");
    printf("    \\a  = alert(bell)   \\b  = backspace\n");
    printf("    \\f  = form feed     \\r  = carriage return\n");
    printf("    \\v  = vertical tab  \\?  = literal question mark\n");
    printf("    \\101 = octal 'A'    \\x41 = hex 'A'\n");
    printf("    \\u00E9 = Unicode é   \\U0001F600 = Unicode 😀\n");

    char oct_char = '\101';   /* Octal 101 = 65 = 'A' */
    char hex_char = '\x41';   /* Hex 0x41 = 65 = 'A' */
    printf("    \\101 = '%c', \\x41 = '%c'\n", oct_char, hex_char);

    /* --- String literals --- */
    printf("\n  String literals:\n");
    char *s1 = "Hello";                    /* Ordinary string */
    /* wchar_t *s2 = L"Wide";              /* Wide string */
    /* char *s3 = u8"UTF-8";               /* UTF-8 string (C11) */
    /* char16_t *s4 = u"UTF-16";           /* UTF-16 string (C11) */
    /* char32_t *s5 = U"UTF-32";           /* UTF-32 string (C11) */

    /* Adjacent string literals are concatenated at translation phase 6 */
    char *concat = "Hello, " "world" "! "
                   "These are " "concatenated.";
    printf("    Concatenated: \"%s\"\n", concat);
    printf("    sizeof(\"Hello\") = %zu (5 chars + \\0 = 6 bytes)\n", sizeof("Hello"));
    (void)s1;

    /* --- Digraphs --- */
    printf("\n  Digraphs (alternative spellings):\n");
    printf("    <: = [    :> = ]    <%% = {    %%> = }\n");
    printf("    %%: = #    %%:%%: = ##\n");
    int digraph_arr<:5:> = <:10, 20, 30, 40, 50:>;
    printf("    digraph_arr<:2:> = %d (same as digraph_arr[2])\n", digraph_arr<:2:>);

    /* --- Predefined macros --- */
    printf("\n  Predefined macros:\n");
    printf("    __FILE__          = %s\n", __FILE__);
    printf("    __LINE__          = %d\n", __LINE__);
    printf("    __DATE__          = %s\n", __DATE__);
    printf("    __TIME__          = %s\n", __TIME__);
    printf("    __STDC__          = %d\n", __STDC__);
    printf("    __STDC_VERSION__  = %ldL\n", __STDC_VERSION__);
    printf("    __func__          = %s\n", __func__);
    printf("    sizeof(int)       = %zu bytes\n", sizeof(int));
    printf("    sizeof(void*)     = %zu bytes\n", sizeof(void*));
}


/* ============================================================================
 *  SECTION 3: DATA TYPES — THE FOUNDATION
 * ============================================================================
 *
 * THEORY:
 * -------
 * C has a rich type system organized into categories:
 *
 *   OBJECT TYPES:
 *     Scalar types:
 *       Integer types:
 *         - char, signed char, unsigned char
 *         - short, unsigned short
 *         - int, unsigned int
 *         - long, unsigned long
 *         - long long, unsigned long long (C99)
 *         - _Bool / bool (C99/C23)
 *         - _BitInt(N) (C23)
 *         - Enumerations
 *       Floating types:
 *         - float, double, long double
 *         - _Float16, _Float32, _Float64, _Float128 (C23 optional)
 *         - _Decimal32, _Decimal64, _Decimal128 (C23 optional)
 *       Complex types (C99):
 *         - float _Complex, double _Complex, long double _Complex
 *       Pointer types:
 *         - int*, char*, void*, struct Foo*, function pointers
 *     Aggregate types:
 *       - Arrays: int arr[10]
 *       - Structures: struct Point { int x; int y; };
 *     Union types:
 *       - union Value { int i; float f; char c; };
 *
 *   TYPE QUALIFIERS:
 *     - const:     Read-only after initialization
 *     - volatile:  May change unexpectedly (hardware, signals)
 *     - restrict:  No aliasing (C99, optimization hint)
 *     - _Atomic:   Thread-safe operations (C11)
 *
 *   STORAGE CLASS SPECIFIERS:
 *     - auto:      Default for local variables (C23: type inference)
 *     - register:  Hint to store in CPU register
 *     - static:    Persistent storage / internal linkage
 *     - extern:    External linkage
 *     - _Thread_local: Thread-local storage (C11)
 *
 * TYPE SIZES (typical LP64 system — Linux/macOS 64-bit):
 *   char: 1 byte    short: 2    int: 4    long: 8    long long: 8
 *   float: 4        double: 8   long double: 16     void*: 8
 *
 * TYPE SIZES (typical LLP64 system — Windows 64-bit):
 *   char: 1 byte    short: 2    int: 4    long: 4    long long: 8
 *   float: 4        double: 8   long double: 8      void*: 8
 *
 * REAL-WORLD ANALOGY:
 *   Data types are like containers of different sizes in a warehouse:
 *   - char is a small box (1 byte) — holds a single character or small number
 *   - int is a medium box (4 bytes) — the workhorse for most numbers
 *   - double is a precision instrument case (8 bytes) — for decimal numbers
 *   - void* is a label that says "contents at this address" — a pointer
 *   - struct is a shipping container holding multiple boxes together
 *   - union is a single box that can hold ONE of several different items
 *   - array is a row of identical boxes in a warehouse aisle
 *
 *   Just as you wouldn't store a car in a shoebox (overflow) or use a
 *   shipping container for a single marble (waste), choosing the right
 *   type matters for memory efficiency and correctness.
 * ============================================================================
 */

static void section_03_data_types(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 3: DATA TYPES\n");
    printf("============================================================\n\n");

    /* --- Integer types and their properties --- */
    printf("  --- Integer Types ---\n");
    printf("  %-20s %5s %20s %20s\n", "Type", "Size", "Min", "Max");
    printf("  %-20s %5s %20s %20s\n", "----", "----", "---", "---");

    printf("  %-20s %3zu B %20d %20d\n",
           "char", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("  %-20s %3zu B %20d %20d\n",
           "signed char", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("  %-20s %3zu B %20d %20u\n",
           "unsigned char", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("  %-20s %3zu B %20d %20d\n",
           "short", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("  %-20s %3zu B %20d %20u\n",
           "unsigned short", sizeof(unsigned short), 0, USHRT_MAX);
    printf("  %-20s %3zu B %20d %20u\n",
           "int", sizeof(int), INT_MIN, INT_MAX);
    printf("  %-20s %3zu B %20d %20u\n",
           "unsigned int", sizeof(unsigned int), 0, UINT_MAX);
    printf("  %-20s %3zu B %20ld %20lu\n",
           "long", sizeof(long), LONG_MIN, LONG_MAX);
    printf("  %-20s %3zu B %20d %20lu\n",
           "unsigned long", sizeof(unsigned long), 0, ULONG_MAX);
    printf("  %-20s %3zu B %20lld %20llu\n",
           "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("  %-20s %3zu B %20d %20llu\n",
           "unsigned long long", sizeof(unsigned long long), 0, ULLONG_MAX);

    /* --- Signedness of plain char --- */
    printf("\n  Plain 'char' signedness: ");
    char c = -1;
    printf("%s (char c = -1 → %d)\n", (c < 0) ? "SIGNED" : "UNSIGNED", c);

    /* --- Exact-width integers (<stdint.h>) --- */
    printf("\n  --- Exact-Width Integers (<stdint.h>) ---\n");
    int8_t   i8  = INT8_MAX;
    int16_t  i16 = INT16_MAX;
    int32_t  i32 = INT32_MAX;
    int64_t  i64 = INT64_MAX;
    uint8_t  u8  = UINT8_MAX;
    uint16_t u16 = UINT16_MAX;
    uint32_t u32 = UINT32_MAX;
    uint64_t u64 = UINT64_MAX;

    printf("  int8_t   max: %d\n", i8);
    printf("  int16_t  max: %d\n", i16);
    printf("  int32_t  max: %d\n", i32);
    printf("  int64_t  max: %" PRId64 "\n", i64);
    printf("  uint8_t  max: %u\n", u8);
    printf("  uint16_t max: %u\n", u16);
    printf("  uint32_t max: %" PRIu32 "\n", u32);
    printf("  uint64_t max: %" PRIu64 "\n", u64);

    /* --- Minimum-width and fastest types --- */
    printf("\n  --- Minimum-Width & Fastest Types ---\n");
    printf("  int_least32_t  max: %" PRIdLEAST32 " (size=%zu)\n",
           INT_LEAST32_MAX, sizeof(int_least32_t));
    printf("  int_fast32_t   max: %" PRIdFAST32 " (size=%zu)\n",
           INT_FAST32_MAX, sizeof(int_fast32_t));
    printf("  intmax_t       max: %" PRIdMAX " (size=%zu)\n",
           INTMAX_MAX, sizeof(intmax_t));
    printf("  intptr_t       max: %" PRIdPTR " (size=%zu)\n",
           INTPTR_MAX, sizeof(intptr_t));
    printf("  size_t         max: %zu (size=%zu)\n",
           SIZE_MAX, sizeof(size_t));

    /* --- Boolean type --- */
    printf("\n  --- Boolean Type ---\n");
    _Bool b1 = 1;
    bool  b2 = true;
    bool  b3 = false;
    bool  b4 = 42;  /* Any non-zero → 1 */
    printf("  _Bool b1=%d, bool true=%d, false=%d, 42→%d\n", b1, b2, b3, b4);

    /* --- Floating-point types --- */
    printf("\n  --- Floating-Point Types ---\n");
    printf("  %-12s %3zu B  digits=%-2d max=%-12e eps=%e\n",
           "float", sizeof(float), FLT_DIG, FLT_MAX, FLT_EPSILON);
    printf("  %-12s %3zu B  digits=%-2d max=%-12e eps=%e\n",
           "double", sizeof(double), DBL_DIG, DBL_MAX, DBL_EPSILON);
    printf("  %-12s %3zu B  digits=%-2d max=%-12Le eps=%Le\n",
           "long double", sizeof(long double), LDBL_DIG, LDBL_MAX, LDBL_EPSILON);

    /* --- Special floating-point values --- */
    printf("\n  --- Special Float Values ---\n");
    double inf  = INFINITY;
    double ninf = -INFINITY;
    double nan  = NAN;
    double nzero = -0.0;
    printf("  INFINITY:     %f\n", inf);
    printf("  -INFINITY:    %f\n", ninf);
    printf("  NAN:          %f\n", nan);
    printf("  -0.0:         %f (== 0.0? %s)\n", nzero, (nzero == 0.0) ? "yes" : "no");
    printf("  NAN == NAN:   %s (NaN is not equal to anything!)\n",
           (nan == nan) ? "true" : "false");
    printf("  isinf(INF):   %d\n", isinf(inf));
    printf("  isnan(NAN):   %d\n", isnan(nan));
    printf("  isfinite(1.0):%d\n", isfinite(1.0));

    /* --- Precision loss --- */
    printf("\n  --- Precision Loss ---\n");
    double sum = 0.1 + 0.2;
    printf("  0.1 + 0.2 = %.20f\n", sum);
    printf("  0.1 + 0.2 == 0.3? %s (ALWAYS use epsilon comparison!)\n",
           (sum == 0.3) ? "true" : "FALSE");
    double eps = 1e-15;
    printf("  fabs(0.1+0.2 - 0.3) < 1e-15? %s\n",
           (fabs(sum - 0.3) < eps) ? "true" : "false");

    /* --- Complex numbers (C99) --- */
    printf("\n  --- Complex Numbers (C99) ---\n");
    double complex z = 3.0 + 4.0 * I;
    printf("  z = %f + %fi\n", creal(z), cimag(z));
    printf("  |z| = %f\n", cabs(z));
    printf("  z * conj(z) = %f\n", creal(z * conj(z)));

    /* --- Integer representation --- */
    printf("\n  --- Integer Representation ---\n");
    printf("  Most systems use two's complement (mandated in C23)\n");
    printf("  CHAR_BIT = %d bits per byte\n", CHAR_BIT);
    int val = -42;
    printf("  -42 in two's complement (32-bit): ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i % 8 == 0 && i > 0) printf(" ");
    }
    printf("\n");

    /* --- Endianness --- */
    printf("\n  --- Endianness ---\n");
    union { uint32_t word; uint8_t bytes[4]; } endian;
    endian.word = 0x01020304;
    printf("  0x01020304 in memory: %02X %02X %02X %02X → %s\n",
           endian.bytes[0], endian.bytes[1], endian.bytes[2], endian.bytes[3],
           (endian.bytes[0] == 0x04) ? "Little-Endian" : "Big-Endian");

    /* --- Alignment --- */
    printf("\n  --- Alignment ---\n");
    printf("  alignof(char)   = %zu\n", _Alignof(char));
    printf("  alignof(short)  = %zu\n", _Alignof(short));
    printf("  alignof(int)    = %zu\n", _Alignof(int));
    printf("  alignof(double) = %zu\n", _Alignof(double));
    printf("  alignof(void*)  = %zu\n", _Alignof(void*));
}


/* ============================================================================
 *  SECTION 4: OPERATORS — COMPLETE REFERENCE
 * ============================================================================
 *
 * THEORY:
 * -------
 * C has operators organized into 15 precedence levels (highest to lowest):
 *
 *   Level  Operators                          Associativity
 *   ─────  ─────────────────────────────────  ─────────────
 *   1      () [] . ->                         Left to right
 *   2      ++ -- (postfix) sizeof _Alignof    Right to left
 *          (type) {} typeof (C23)
 *   3      ++ -- (prefix) + - ! ~ * &         Right to left
 *          (unary)
 *   4      * / %                              Left to right
 *   5      + -                                Left to right
 *   6      << >>                              Left to right
 *   7      < > <= >=                          Left to right
 *   8      == !=                              Left to right
 *   9      &                                  Left to right
 *   10     ^                                  Left to right
 *   11     |                                  Left to right
 *   12     &&                                 Left to right (short-circuit)
 *   13     ||                                 Left to right (short-circuit)
 *   14     ?:                                 Right to left
 *   15     = += -= *= /= %= <<= >>= &= ^= |= Right to left
 *   16     ,                                  Left to right
 *
 * SEQUENCE POINTS:
 *   Points where all previous side effects are complete:
 *   - End of full expression (statement semicolon)
 *   - && || ?: , operators
 *   - Before function call (after argument evaluation)
 *
 * REAL-WORLD ANALOGY:
 *   Operators are like tools in a toolbox. Each has a specific purpose:
 *   - Arithmetic (+, -, *, /) = basic measuring tools (ruler, calculator)
 *   - Bitwise (&, |, ^, ~) = precision micro-tools for individual bits
 *   - Logical (&&, ||, !) = decision-making flowchart symbols
 *   - Assignment (=, +=) = labeling and updating inventory tags
 *   - Comparison (==, !=, <) = quality inspection checkpoints
 *   - sizeof = measuring tape (how big is this in memory?)
 *
 *   Precedence is like the order of operations in math class:
 *   "Please Excuse My Dear Aunt Sally" (Parentheses, Exponents, etc.)
 *   In C: always use parentheses when in doubt!
 *
 * CRITICAL GOTCHA:
 *   Bitwise operators (&, |, ^) have LOWER precedence than == and !=
 *   This means: a & b == c  parses as  a & (b == c)  NOT  (a & b) == c
 *   ALWAYS use explicit parentheses with bitwise operators!
 * ============================================================================
 */

static void section_04_operators(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 4: OPERATORS\n");
    printf("============================================================\n\n");

    /* --- Arithmetic operators --- */
    printf("  --- Arithmetic ---\n");
    int a = 17, b = 5;
    printf("  %d + %d = %d (addition)\n", a, b, a + b);
    printf("  %d - %d = %d (subtraction)\n", a, b, a - b);
    printf("  %d * %d = %d (multiplication)\n", a, b, a * b);
    printf("  %d / %d = %d (integer division: truncates toward zero)\n", a, b, a / b);
    printf("  %d %% %d = %d (modulo: sign follows dividend)\n", a, b, a % b);
    printf("  -17 / 5 = %d (truncates toward zero, not -4)\n", -17 / 5);
    printf("  -17 %% 5 = %d (sign follows dividend)\n", -17 % 5);

    /* --- Increment/Decrement --- */
    printf("\n  --- Increment/Decrement ---\n");
    int i = 5;
    printf("  i = %d\n", i);
    printf("  i++ returns %d (post-increment: returns THEN increments), i becomes %d\n", i++, i);
    printf("  ++i returns %d (pre-increment: increments THEN returns)\n", ++i);
    printf("  i-- returns %d (post-decrement), i becomes %d\n", i--, i);
    printf("  --i returns %d (pre-decrement)\n", --i);

    /* --- Bitwise operators --- */
    printf("\n  --- Bitwise Operators ---\n");
    unsigned int x = 0xABCD1234, y = 0x00FF00FF;
    printf("  x     = 0x%08X\n", x);
    printf("  y     = 0x%08X\n", y);
    printf("  x & y = 0x%08X (AND:  both bits must be 1)\n", x & y);
    printf("  x | y = 0x%08X (OR:   at least one bit is 1)\n", x | y);
    printf("  x ^ y = 0x%08X (XOR:  bits are different)\n", x ^ y);
    printf("  ~x    = 0x%08X (NOT:  flip all bits)\n", ~x);
    printf("  x<<4  = 0x%08X (shift left 4: multiply by 16)\n", x << 4);
    printf("  x>>4  = 0x%08X (shift right 4: divide by 16)\n", x >> 4);

    /* --- Bit manipulation idioms --- */
    printf("\n  --- Bit Manipulation Idioms ---\n");
    unsigned int flags = 0;
    flags |= (1U << 3);   printf("  Set bit 3:      0x%08X\n", flags);
    flags |= (1U << 7);   printf("  Set bit 7:      0x%08X\n", flags);
    flags &= ~(1U << 3);  printf("  Clear bit 3:    0x%08X\n", flags);
    flags ^= (1U << 7);   printf("  Toggle bit 7:   0x%08X\n", flags);
    printf("  Test bit 7:     %d\n", (flags >> 7) & 1);
    printf("  Test bit 3:     %d\n", (flags >> 3) & 1);

    unsigned int v = 0b10110100;
    printf("  v = 0x%02X\n", v);
    printf("  v & (v-1)       = 0x%02X (clear lowest set bit)\n", v & (v - 1));
    printf("  v & -v          = 0x%02X (isolate lowest set bit)\n", v & (unsigned)(-(int)v));

    /* --- Logical operators with short-circuit --- */
    printf("\n  --- Logical Operators (Short-Circuit) ---\n");
    int p = 0, q = 5;
    /* Short-circuit: if p is false, q++ is NEVER evaluated */
    if (p && (q++)) {
        printf("  Both true\n");
    } else {
        printf("  p=%d is false → q++ NOT evaluated, q still =%d\n", p, q);
    }
    p = 1;
    if (p || (q++)) {
        printf("  p=%d is true → q++ NOT evaluated, q still =%d\n", p, q);
    }

    /* --- Ternary operator --- */
    printf("\n  --- Ternary Operator ---\n");
    int val = 42;
    const char *parity = (val % 2 == 0) ? "even" : "odd";
    printf("  %d is %s\n", val, parity);

    /* Nested ternary */
    int n = 0;
    const char *sign = (n > 0) ? "positive" : (n < 0) ? "negative" : "zero";
    printf("  %d is %s\n", n, sign);

    /* --- Comma operator --- */
    printf("\n  --- Comma Operator ---\n");
    int c, d;
    c = (1, 2, 3, 4, 5);  /* Evaluates all, returns rightmost */
    printf("  c = (1, 2, 3, 4, 5) = %d\n", c);
    printf("  Comma in for loop: ");
    for (d = 0, c = 10; d < 5; d++, c--) {
        printf("(%d,%d) ", d, c);
    }
    printf("\n");

    /* --- sizeof operator --- */
    printf("\n  --- sizeof Operator ---\n");
    int arr[10];
    int *ptr = arr;
    char str[] = "hello";
    printf("  sizeof(int)    = %zu\n", sizeof(int));
    printf("  sizeof(arr)    = %zu (10 ints = 40 bytes)\n", sizeof(arr));
    printf("  sizeof(ptr)    = %zu (pointer, NOT array size)\n", sizeof(ptr));
    printf("  sizeof(str)    = %zu (5 chars + \\0 = 6)\n", sizeof(str));
    printf("  sizeof(char)   = %zu (always 1 by definition)\n", sizeof(char));
    /* sizeof does NOT evaluate its operand (except VLAs) */
    int e = 5;
    printf("  sizeof(e++)    = %zu, e still = %d (e++ not evaluated!)\n",
           sizeof(e++), e);

    /* --- Operator precedence gotcha --- */
    printf("\n  --- CRITICAL: Precedence Gotcha ---\n");
    printf("  a & b == c  parses as  a & (b == c)  NOT  (a & b) == c\n");
    printf("  a | b & c  parses as  a | (b & c)   NOT  (a | b) & c\n");
    printf("  *p++       parses as  *(p++)         NOT  (*p)++\n");
    printf("  ALWAYS USE PARENTHESES when mixing bitwise and comparison!\n");
}


/* ============================================================================
 *  SECTION 5: CONTROL FLOW
 * ============================================================================
 *
 * THEORY:
 * -------
 * C has three categories of control flow:
 *
 *   SELECTION (branching):
 *     if / else if / else — conditional execution
 *     switch / case / default — multi-way branching on integer value
 *
 *   ITERATION (loops):
 *     while  — pre-test loop (check condition before body)
 *     do-while — post-test loop (execute body at least once)
 *     for — counter-controlled loop (init; condition; update)
 *
 *   JUMPS:
 *     break — exit innermost loop or switch
 *     continue — skip to next loop iteration
 *     goto — unconditional jump to label (function-scoped)
 *     return — exit function, optionally returning a value
 *
 * REAL-WORLD ANALOGY:
 *   Control flow is like the decision-making process in daily life:
 *
 *   if/else = Traffic lights:
 *     "If the light is green, go. Else if yellow, slow down. Else stop."
 *
 *   switch = A restaurant menu:
 *     "Switch on your choice: case 'burger': ..., case 'salad': ..., default: water"
 *     (Fall-through is like ordering a combo meal — you get multiple items)
 *
 *   while = A while loop is like "keep eating slices while you're hungry"
 *     (Check condition first — might eat zero slices if already full)
 *
 *   do-while = "Take a bite, then check if you want more"
 *     (Always executes at least once — like trying a free sample)
 *
 *   for = "For each of the 12 months, record the temperature"
 *     (Known count, with initialization, condition, and update)
 *
 *   break = "Stop eating immediately when you feel full"
 *   continue = "Skip the broccoli, move to the next food item"
 *   goto = "Emergency exit — jump directly to the exit sign"
 *     (Legitimate uses: breaking out of nested loops, centralized cleanup)
 * ============================================================================
 */

static void section_05_control_flow(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 5: CONTROL FLOW\n");
    printf("============================================================\n\n");

    /* --- if/else --- */
    printf("  --- if/else ---\n");
    int temp = 25;
    if (temp > 30) {
        printf("  %d°C: Hot! Turn on AC\n", temp);
    } else if (temp > 20) {
        printf("  %d°C: Comfortable\n", temp);
    } else if (temp > 10) {
        printf("  %d°C: Cool, wear a jacket\n", temp);
    } else {
        printf("  %d°C: Cold! Bundle up\n", temp);
    }

    /* Dangling else attaches to nearest unmatched if */
    int a = 1, b = 0;
    if (a)
        if (b)
            printf("  a and b\n");
        else  /* This else belongs to "if (b)", NOT "if (a)" */
            printf("  a=%d is true, b=%d is false\n", a, b);

    /* --- switch --- */
    printf("\n  --- switch ---\n");
    int day = 3;
    switch (day) {
        case 1: printf("  Monday\n");    break;
        case 2: printf("  Tuesday\n");   break;
        case 3: printf("  Wednesday\n"); break;
        case 4: printf("  Thursday\n");  break;
        case 5: printf("  Friday\n");    break;
        case 6: /* Fall-through: cases 6 and 7 share code */
        case 7: printf("  Weekend\n");   break;
        default: printf("  Invalid\n");  break;
    }

    /* Switch on character */
    char grade = 'B';
    switch (grade) {
        case 'A': printf("  Grade A: Excellent\n"); break;
        case 'B': printf("  Grade B: Good\n");      break;
        case 'C': printf("  Grade C: Average\n");   break;
        default:  printf("  Grade %c\n", grade);    break;
    }

    /* --- while loop --- */
    printf("\n  --- while loop ---\n");
    printf("  Powers of 2: ");
    int w = 1;
    while (w <= 256) {
        printf("%d ", w);
        w *= 2;
    }
    printf("\n");

    /* --- do-while loop --- */
    printf("\n  --- do-while loop ---\n");
    printf("  Halving 100: ");
    int dw = 100;
    do {
        printf("%d ", dw);
        dw /= 2;
    } while (dw > 0);
    printf("\n");

    /* do-while(0) idiom for safe multi-statement macros */
    #define SAFE_ACTION(x) do { \
        printf("  Action on %d\n", (x)); \
        printf("  Done\n"); \
    } while(0)
    if (1) SAFE_ACTION(42);

    /* --- for loop --- */
    printf("\n  --- for loop ---\n");
    printf("  Squares: ");
    for (int fi = 1; fi <= 10; fi++) {
        printf("%d ", fi * fi);
    }
    printf("\n");

    /* Multiple variables in for loop */
    printf("  Parallel: ");
    for (int fi = 0, fj = 10; fi < fj; fi++, fj--) {
        printf("(%d,%d) ", fi, fj);
    }
    printf("\n");

    /* Infinite loop with break */
    int iter = 0;
    for (;;) {
        if (iter++ >= 3) break;
        printf("  Infinite loop iteration %d\n", iter);
    }

    /* --- break and continue --- */
    printf("\n  --- break & continue ---\n");
    printf("  Break at 5: ");
    for (int bi = 0; bi < 100; bi++) {
        if (bi == 5) break;
        printf("%d ", bi);
    }
    printf("\n");

    printf("  Skip odd: ");
    for (int ci = 0; ci < 10; ci++) {
        if (ci % 2 != 0) continue;
        printf("%d ", ci);
    }
    printf("\n");

    /* --- goto for nested loop exit --- */
    printf("\n  --- goto (nested loop exit) ---\n");
    printf("  Finding (i,j) where i*j > 20:\n");
    for (int gi = 1; gi <= 10; gi++) {
        for (int gj = 1; gj <= 10; gj++) {
            if (gi * gj > 20) {
                printf("    Found: i=%d, j=%d, i*j=%d\n", gi, gj, gi * gj);
                goto found;
            }
        }
    }
found:
    printf("  (jumped out of nested loops via goto)\n");

    /* --- goto-based cleanup pattern --- */
    printf("\n  --- goto Cleanup Pattern ---\n");
    printf("  (The idiomatic C error-handling pattern)\n");
    printf("  FILE *f = NULL; char *buf = NULL;\n");
    printf("  f = fopen(...); if (!f) goto cleanup;\n");
    printf("  buf = malloc(...); if (!buf) goto cleanup;\n");
    printf("  // ... do work ...\n");
    printf("  cleanup:\n");
    printf("    free(buf);\n");
    printf("    if (f) fclose(f);\n");
    printf("    return err;\n");
}


/* ============================================================================
 *  SECTION 6: ARRAYS
 * ============================================================================
 *
 * THEORY:
 * -------
 * An array is a contiguous block of memory holding elements of the same type.
 *
 * KEY PROPERTIES:
 *   - Zero-indexed: arr[0] is the first element
 *   - Size must be known at compile time (C89) or can be VLA (C99)
 *   - Array name "decays" to pointer to first element in most expressions
 *   - Exceptions to decay: sizeof, _Alignof, & (address-of), string literal init
 *   - No bounds checking — accessing out of bounds is UNDEFINED BEHAVIOR
 *   - Stored in row-major order for multidimensional arrays
 *
 * INITIALIZATION:
 *   int a[5] = {1,2,3,4,5};          Full initialization
 *   int a[5] = {1,2};                Partial (rest are 0)
 *   int a[5] = {0};                  All zeros
 *   int a[] = {1,2,3};               Size deduced (3 elements)
 *   int a[10] = {[2]=10, [9]=20};    Designated initializers (C99)
 *   char s[] = "hello";              Char array (size 6, includes \\0)
 *
 * REAL-WORLD ANALOGY:
 *   An array is like a row of numbered mailboxes in an apartment building:
 *   - Each mailbox (element) has the same size and type
 *   - They're physically adjacent (contiguous in memory)
 *   - You access them by number (index): mailbox[0], mailbox[1], ...
 *   - The building name (array name) tells you where the first mailbox is
 *   - There's no fence to stop you from checking mailbox[999] even if
 *     only 10 exist — that's an out-of-bounds access (UB)
 *
 *   A 2D array is like a spreadsheet:
 *   - Rows and columns, stored row by row in memory
 *   - matrix[row][col] = *(matrix[0] + row*NUM_COLS + col)
 *
 *   A VLA (Variable-Length Array) is like a flexible parking lot:
 *   - The number of spaces is determined at runtime
 *   - Allocated on the stack (fast but limited size)
 * ============================================================================
 */

static void section_06_arrays(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 6: ARRAYS\n");
    printf("============================================================\n\n");

    /* --- Declaration and initialization --- */
    printf("  --- Initialization ---\n");
    int full[5] = {10, 20, 30, 40, 50};
    int partial[5] = {1, 2};           /* → {1, 2, 0, 0, 0} */
    int zeros[5] = {0};                /* → {0, 0, 0, 0, 0} */
    int deduced[] = {5, 10, 15, 20};   /* size = 4 */
    int design[10] = {[0]=1, [5]=50, [9]=100}; /* designated (C99) */

    printf("  Full:      ");
    for (int i = 0; i < 5; i++) printf("%d ", full[i]);
    printf("\n  Partial:   ");
    for (int i = 0; i < 5; i++) printf("%d ", partial[i]);
    printf("\n  Zeros:     ");
    for (int i = 0; i < 5; i++) printf("%d ", zeros[i]);
    printf("\n  Deduced:   %zu elements: ", sizeof(deduced)/sizeof(deduced[0]));
    for (size_t i = 0; i < sizeof(deduced)/sizeof(deduced[0]); i++) printf("%d ", deduced[i]);
    printf("\n  Designated:");
    for (int i = 0; i < 10; i++) printf(" %d", design[i]);
    printf("\n");

    /* --- Array decay to pointer --- */
    printf("\n  --- Array Decay ---\n");
    int arr[] = {100, 200, 300, 400, 500};
    printf("  sizeof(arr) = %zu (total: 5*4=20 bytes)\n", sizeof(arr));
    int *ptr = arr;  /* arr decays to &arr[0] */
    printf("  sizeof(ptr) = %zu (pointer size, NOT array size)\n", sizeof(ptr));
    printf("  arr[2]     = %d\n", arr[2]);
    printf("  *(arr + 2) = %d (pointer arithmetic: same thing)\n", *(arr + 2));
    printf("  ptr[2]     = %d (subscript on pointer: same thing)\n", ptr[2]);

    /* --- 2D arrays (row-major) --- */
    printf("\n  --- 2D Arrays (Row-Major) ---\n");
    int matrix[3][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12}
    };
    printf("  matrix[1][2] = %d\n", matrix[1][2]);
    printf("  *(*(matrix+1)+2) = %d (pointer equivalent)\n", *(*(matrix + 1) + 2));
    printf("  *((int*)matrix + 1*4+2) = %d (flat index)\n", *((int*)matrix + 1*4 + 2));
    printf("  Memory layout (row-major): ");
    for (int i = 0; i < 12; i++) printf("%d ", ((int*)matrix)[i]);
    printf("\n");

    /* --- Char arrays vs string literal pointers --- */
    printf("\n  --- Char Array vs String Pointer ---\n");
    char modifiable[] = "Hello";  /* Stack array, modifiable */
    const char *literal = "Hello"; /* Points to read-only memory */
    modifiable[0] = 'h';  /* OK: modifying array */
    /* literal[0] = 'h';  /* UB: modifying string literal! */ */
    printf("  Array:   \"%s\" (modifiable, sizeof=%zu)\n", modifiable, sizeof(modifiable));
    printf("  Pointer: \"%s\" (read-only, sizeof=%zu)\n", literal, sizeof(literal));

    /* --- VLA (Variable-Length Array, C99) --- */
    printf("\n  --- Variable-Length Arrays (C99) ---\n");
    int vn = 7;
    int vla[vn];  /* size determined at runtime */
    for (int i = 0; i < vn; i++) vla[i] = i * 10;
    printf("  VLA (n=%d): ", vn);
    for (int i = 0; i < vn; i++) printf("%d ", vla[i]);
    printf("\n  sizeof(vla) = %zu (evaluated at runtime!)\n", sizeof(vla));
    printf("  Caveats: no initialization, no static, stack-allocated, overflow risk\n");

    /* --- Pointer-based traversal --- */
    printf("\n  --- Pointer Traversal ---\n");
    printf("  Forward:  ");
    for (int *p = arr; p < arr + 5; p++) printf("%d ", *p);
    printf("\n  Backward: ");
    for (int *p = arr + 4; p >= arr; p--) printf("%d ", *p);
    printf("\n");

    /* --- Array reversal --- */
    printf("\n  --- In-Place Reversal ---\n");
    int rev[] = {1, 2, 3, 4, 5};
    int *lo = rev, *hi = rev + 4;
    while (lo < hi) {
        int tmp = *lo; *lo++ = *hi; *hi-- = tmp;
    }
    printf("  Reversed: ");
    for (int i = 0; i < 5; i++) printf("%d ", rev[i]);
    printf("\n");
}


/* ============================================================================
 *  SECTION 7: POINTERS — THE HEART OF C
 * ============================================================================
 *
 * THEORY:
 * -------
 * A pointer is a variable that stores a MEMORY ADDRESS. Pointers are C's most
 * powerful and dangerous feature — they give direct access to hardware memory.
 *
 * POINTER TYPES:
 *   int *p;           → pointer to int
 *   char *p;          → pointer to char
 *   void *p;          → generic pointer (any object pointer)
 *   int **pp;         → pointer to pointer to int
 *   int (*p)[10];     → pointer to array of 10 ints
 *   int *p[10];       → array of 10 pointers to int
 *   int (*fp)(int);   → pointer to function taking int, returning int
 *
 * POINTER ARITHMETIC:
 *   p + n   → advances by n * sizeof(*p) bytes
 *   p - n   → decrements by n * sizeof(*p) bytes
 *   p1 - p2 → difference in elements (type ptrdiff_t)
 *   p++     → advance to next element
 *   One-past-the-end pointer is valid to compute but not dereference
 *
 * CONST WITH POINTERS (read right to left):
 *   const int *p      → "p is a pointer to int that is const" (data const)
 *   int * const p     → "p is a const pointer to int" (pointer const)
 *   const int * const p → both const
 *   int const *p      → same as const int *p (const applies to int)
 *
 * NULL POINTERS:
 *   NULL is defined as ((void*)0) or 0 or 0L
 *   C23 introduces nullptr (type nullptr_t, not implicitly integer)
 *   Dereferencing NULL is UNDEFINED BEHAVIOR
 *   Always check: if (p == NULL) or if (!p)
 *
 * REAL-WORLD ANALOGY:
 *   A pointer is like a HOME ADDRESS written on a piece of paper:
 *
 *   - The paper (pointer variable) has an address written on it
 *   - The address tells you where the house (data) is located
 *   - *p means "go to the address on the paper and look at the house"
 *   - &x means "what is the address of house x?"
 *   - p = &x means "write x's address on the paper"
 *   - NULL means the paper is blank — no valid address
 *
 *   Pointer arithmetic is like walking down a street:
 *   - p + 1 means "walk to the next house" (not next byte!)
 *   - Houses (elements) are spaced sizeof(*p) apart
 *   - Walking past the last house (one-past-the-end) is OK to stand at
 *     but you can't look inside (can't dereference)
 *
 *   A double pointer (int **) is like a piece of paper with the address
 *   of ANOTHER piece of paper, which in turn has the address of a house.
 *   Used when a function needs to modify where a pointer points.
 *
 *   Dangling pointer = a piece of paper with an address of a demolished house
 *   Wild pointer = a piece of paper with random scribbles (uninitialized)
 * ============================================================================
 */

/* Function that modifies a pointer — needs pointer-to-pointer */
static void allocate_int(int **out, int value) {
    *out = malloc(sizeof(int));
    if (*out) **out = value;
}

/* Swap two integers via pointers */
static void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Callback function type */
typedef int (*compare_fn)(const void *, const void *);

static int int_compare(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

static void section_07_pointers(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 7: POINTERS\n");
    printf("============================================================\n\n");

    /* --- Basic pointer operations --- */
    printf("  --- Basic Pointers ---\n");
    int x = 42;
    int *px = &x;  /* px now holds the address of x */
    printf("  x     = %d\n", x);
    printf("  &x    = %p (address of x)\n", (void*)&x);
    printf("  px    = %p (value of px = address of x)\n", (void*)px);
    printf("  *px   = %d (dereference: go to address, read value)\n", *px);
    *px = 100;  /* Modify through pointer */
    printf("  After *px = 100: x = %d\n", x);

    /* --- Null pointers --- */
    printf("\n  --- Null Pointers ---\n");
    int *np = NULL;
    printf("  NULL = %p\n", (void*)np);
    if (!np) printf("  Pointer is null (can't dereference safely)\n");
    /* *np; would be UNDEFINED BEHAVIOR */

    /* --- Pointer arithmetic --- */
    printf("\n  --- Pointer Arithmetic ---\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    printf("  p       = %p, *p = %d\n", (void*)p, *p);
    printf("  p + 1   = %p, *(p+1) = %d (advanced %zu bytes)\n",
           (void*)(p + 1), *(p + 1), sizeof(int));
    printf("  p + 4   = %p, *(p+4) = %d\n", (void*)(p + 4), *(p + 4));

    /* Pointer difference */
    ptrdiff_t diff = &arr[4] - &arr[0];
    printf("  &arr[4] - &arr[0] = %td elements\n", diff);

    /* One-past-the-end */
    int *end = arr + 5;
    printf("  arr + 5 = %p (one-past-the-end: valid pointer, can't dereference)\n",
           (void*)end);

    /* --- Const with pointers --- */
    printf("\n  --- Const Pointers ---\n");
    int a = 10, b = 20;

    const int *pci = &a;     /* pointer to const int: data is const */
    /* *pci = 30; */         /* ERROR: can't modify data */
    pci = &b;                /* OK: can change what it points to */
    printf("  const int *pci → %d (can change target, can't modify data)\n", *pci);

    int * const cpi = &a;    /* const pointer to int: pointer is const */
    *cpi = 30;               /* OK: can modify data */
    /* cpi = &b; */          /* ERROR: can't change pointer */
    printf("  int * const cpi → %d (can modify data, can't change target)\n", *cpi);

    const int * const cpci = &b; /* both const */
    printf("  const int * const cpci → %d (neither can change)\n", *cpci);

    /* --- Void pointer --- */
    printf("\n  --- void* (Generic Pointer) ---\n");
    int vi = 42;
    float vf = 3.14f;
    void *vp = &vi;
    printf("  void* → int: %d\n", *(int*)vp);  /* must cast back */
    vp = &vf;
    printf("  void* → float: %f\n", *(float*)vp);
    /* In C (not C++), void* implicitly converts to/from other pointer types */

    /* --- Double pointer demo --- */
    printf("\n  --- Double Pointer (pointer to pointer) ---\n");
    int val = 42;
    int *pp1 = &val;
    int **pp2 = &pp1;
    printf("  val  = %d (address: %p)\n", val, (void*)&val);
    printf("  *pp1 = %d (address: %p)\n", *pp1, (void*)pp1);
    printf("  **pp2= %d (address: %p)\n", **pp2, (void*)*pp2);
    **pp2 = 100;
    printf("  After **pp2 = 100: val = %d\n", val);

    /* Double pointer for dynamic allocation */
    int *heap_int = NULL;
    allocate_int(&heap_int, 999);
    printf("  allocate_int: %d at %p\n", *heap_int, (void*)heap_int);
    free(heap_int);
    heap_int = NULL;  /* Good practice: avoid dangling pointer */

    /* --- Swap via pointers --- */
    printf("\n  --- Pass by Pointer (Simulated Pass by Reference) ---\n");
    int sa = 10, sb = 20;
    printf("  Before swap: a=%d, b=%d\n", sa, sb);
    swap_int(&sa, &sb);
    printf("  After swap:  a=%d, b=%d\n", sa, sb);

    /* --- Function pointers --- */
    printf("\n  --- Function Pointers ---\n");
    int nums[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    compare_fn cmp = int_compare;  /* function pointer variable */
    qsort(nums, n, sizeof(int), cmp);
    printf("  qsort with function pointer: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");

    /* Function pointer syntax explained */
    printf("  Syntax: return_type (*name)(param_types)\n");
    printf("  Example: int (*fp)(const void*, const void*) = int_compare;\n");
    printf("  Array of function pointers: int (*fpa[N])(...);\n");
    printf("  typedef: typedef int (*cmp_fn)(const void*, const void*);\n");

    /* --- Pointer to array vs array of pointers --- */
    printf("\n  --- Pointer to Array vs Array of Pointers ---\n");
    int arr2[5] = {1, 2, 3, 4, 5};
    int (*parr)[5] = &arr2;     /* pointer to array of 5 ints */
    printf("  (*parr)[2] = %d (pointer to array)\n", (*parr)[2]);

    int *aptr[5];               /* array of 5 pointers to int */
    for (int i = 0; i < 5; i++) aptr[i] = &arr2[i];
    printf("  *aptr[3]   = %d (array of pointers)\n", *aptr[3]);

    /* --- Dangling pointer warning --- */
    printf("\n  --- Dangling Pointer Warnings ---\n");
    printf("  NEVER return address of local variable:\n");
    printf("    int *bad(void) { int x = 5; return &x; } // UB!\n");
    printf("  NEVER use pointer after free:\n");
    printf("    free(p); *p = 1; // UB!\n");
    printf("  ALWAYS set to NULL after free:\n");
    printf("    free(p); p = NULL;\n");
}


/* ============================================================================
 *  SECTION 8: FUNCTIONS
 * ============================================================================
 *
 * THEORY:
 * -------
 * ALL C parameters are PASS BY VALUE — a copy of the argument is made.
 * To modify the caller's variable, pass a pointer to it (pass by reference simulation).
 * Array parameters decay to pointers (the array itself is not copied).
 *
 * FUNCTION SIGNATURES:
 *   int foo(int x, double y);          ANSI prototype (preferred)
 *   int foo();                          K&R style (no prototype, deprecated in C23)
 *   int foo(void);                      Explicit "no parameters"
 *   int printf(const char *fmt, ...);   Variadic function
 *
 * VARIADIC FUNCTIONS (<stdarg.h>):
 *   va_list ap;           — declare argument list
 *   va_start(ap, last);   — initialize (last = last named parameter)
 *   va_arg(ap, type);     — get next argument of given type
 *   va_end(ap);           — cleanup
 *   va_copy(dest, src);   — copy va_list (C99)
 *   At least one named parameter is required.
 *   Default promotions: float→double, char/short→int
 *
 * INLINE FUNCTIONS (C99):
 *   static inline int square(int x) { return x * x; }
 *   Suggests inlining but doesn't guarantee it.
 *   static inline in headers avoids ODR issues.
 *
 * _Noreturn (C11):
 *   _Noreturn void fatal(const char *msg);
 *   Tells compiler the function never returns (e.g., exit, abort, longjmp).
 *
 * REAL-WORLD ANALOGY:
 *   A function is like a recipe in a cookbook:
 *
 *   - The function name is the recipe title ("Chocolate Cake")
 *   - Parameters are the ingredients list (flour, sugar, eggs)
 *   - Pass by value: you get a COPY of the ingredients
 *     (if the recipe burns the sugar, your original sugar is fine)
 *   - Pass by pointer: you give the recipe a REFERENCE to your pantry
 *     (the recipe can go to your pantry and take/modify ingredients)
 *   - Return value: the finished dish you get back
 *   - void return: the recipe has side effects but no dish to return
 *     (like a recipe that just cleans the kitchen)
 *
 *   Variadic functions are like a recipe that says "add any spices you want":
 *   - printf("format", arg1, arg2, ...) handles any number of arguments
 *   - The format string is like the recipe instructions
 *   - va_arg is like reaching into the spice rack one jar at a time
 *
 *   Recursion is like Russian nesting dolls:
 *   - Each doll (function call) contains a smaller doll (recursive call)
 *   - The smallest doll (base case) has no more dolls inside
 *   - Then you reassemble from smallest to largest (return from recursion)
 *
 *   Function pointers are like speed-dial buttons on a phone:
 *   - You store a function's address in a variable
 *   - You can call it later: fp(args) or (*fp)(args)
 *   - You can change which function is on speed-dial
 *   - Arrays of function pointers = dispatch tables = switchboards
 * ============================================================================
 */

/* Variadic function: sum of N integers */
static int sum_variadic(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

/* Variadic printf-like function */
static void my_log(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    printf("  [LOG] ");
    vprintf(fmt, args);
    va_end(args);
}

/* Inline function */
static inline int square(int x) { return x * x; }

/* Recursive function */
static unsigned long long factorial(unsigned n) {
    if (n <= 1) return 1;  /* base case */
    return n * factorial(n - 1);  /* recursive case */
}

/* Function pointer and dispatch table */
typedef int (*math_op)(int, int);
static int add(int a, int b) { return a + b; }
static int mul(int a, int b) { return a * b; }
static int sub(int a, int b) { return a - b; }

/* Callback-based iteration */
typedef void (*item_cb)(int index, int value, void *ctx);
static void for_each_cb(const int *arr, int n, item_cb cb, void *ctx) {
    for (int i = 0; i < n; i++) cb(i, arr[i], ctx);
}
static void print_item(int idx, int val, void *ctx) {
    printf("  %s[%d]=%d\n", (const char*)ctx, idx, val);
}

/* Return struct by value */
typedef struct { double x, y; } Point;
static Point make_point(double x, double y) {
    return (Point){x, y};  /* compound literal, returned by value */
}

static void section_08_functions(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 8: FUNCTIONS\n");
    printf("============================================================\n\n");

    /* --- Pass by value vs pointer --- */
    printf("  --- Pass by Value vs Pointer ---\n");
    int v = 42;
    printf("  Before: v = %d\n", v);
    /* by_value(v);  → modifies local copy only */
    swap_int(&v, &(int){99});  /* pass pointer to modify */
    printf("  After swap with 99: v = %d\n", v);

    /* --- Variadic functions --- */
    printf("\n  --- Variadic Functions ---\n");
    printf("  sum(3, 10, 20, 30) = %d\n", sum_variadic(3, 10, 20, 30));
    printf("  sum(5, 1,2,3,4,5)  = %d\n", sum_variadic(5, 1, 2, 3, 4, 5));
    my_log("User %s connected from %s:%d\n", "alice", "192.168.1.1", 8080);

    /* --- Inline function --- */
    printf("\n  --- Inline Function ---\n");
    printf("  square(7) = %d (may be inlined by compiler)\n", square(7));

    /* --- Recursion --- */
    printf("\n  --- Recursion ---\n");
    for (unsigned r = 0; r <= 10; r++) {
        printf("  factorial(%u) = %llu\n", r, factorial(r));
    }

    /* --- Function pointers and dispatch table --- */
    printf("\n  --- Function Pointers & Dispatch Table ---\n");
    math_op ops[] = {add, sub, mul};
    const char *names[] = {"add", "sub", "mul"};
    int la = 100, lb = 30;
    for (int i = 0; i < 3; i++) {
        printf("  %s(%d, %d) = %d\n", names[i], la, lb, ops[i](la, lb));
    }

    /* --- Callbacks --- */
    printf("\n  --- Callback Pattern ---\n");
    int items[] = {10, 20, 30, 40, 50};
    for_each_cb(items, 5, print_item, "item");

    /* --- Return struct by value --- */
    printf("\n  --- Return Struct by Value ---\n");
    Point pt = make_point(3.5, 7.2);
    printf("  Point: (%.1f, %.1f)\n", pt.x, pt.y);

    /* --- Function declaration best practices --- */
    printf("\n  --- Best Practices ---\n");
    printf("  1. Always use prototypes (ANSI style)\n");
    printf("  2. Use 'void' for no-parameter functions: int f(void)\n");
    printf("  3. Use const for input-only pointer parameters\n");
    printf("  4. Use restrict for non-aliasing pointer parameters\n");
    printf("  5. Keep functions short and focused (single responsibility)\n");
    printf("  6. Document preconditions and postconditions\n");
}


/* ============================================================================
 *  SECTION 9: STRUCTURES, UNIONS, AND ENUMS
 * ============================================================================
 *
 * THEORY:
 * -------
 * STRUCTURES (struct):
 *   - Group related data of different types into one unit
 *   - Members laid out in declaration order with possible padding
 *   - sizeof includes padding for alignment
 *   - Assignment copies all members (shallow copy)
 *   - Cannot compare with == (must compare member by member)
 *   - Can be passed to/returned from functions (by value, copied)
 *   - Self-referential via pointer: struct Node { int data; struct Node *next; };
 *   - Flexible array member (C99): last member with [] size
 *   - Anonymous structs/unions (C11): nested without names
 *   - Bit-fields: unsigned int flag : 1; (implementation-defined layout)
 *
 * UNIONS (union):
 *   - All members share the same memory location
 *   - Size = size of largest member
 *   - Only one member is "active" at a time
 *   - Used for: tagged unions, type punning, memory-efficient variants
 *
 * ENUMS (enum):
 *   - Define named integer constants
 *   - Default starts at 0, auto-increments
 *   - Can specify explicit values: enum { A = 10, B = 20 }
 *   - Underlying type is implementation-defined (typically int)
 *   - C23: can specify underlying type: enum Color : uint8_t { ... }
 *
 * REAL-WORLD ANALOGY:
 *
 *   A STRUCT is like a FILING CABINET:
 *   - Each drawer (member) holds a specific type of document
 *   - All drawers exist simultaneously
 *   - You can access any drawer: cabinet.salary, cabinet.name
 *   - Copying the cabinet copies ALL drawers
 *   - Padding is like empty space between drawers for structural integrity
 *
 *   A UNION is like a TRANSFORMER TOY:
 *   - It can be a car, a robot, or a plane — but only ONE at a time
 *   - All forms share the same physical material (memory)
 *   - You need a label (tag) to know which form it's currently in
 *   - Much smaller than having separate car + robot + plane
 *
 *   A TAGGED UNION (struct with enum + union) is like a labeled transformer:
 *   - enum tells you what form it's in (car/robot/plane)
 *   - union holds the actual data for that form
 *
 *   An ENUM is like a MENU at a restaurant:
 *   - Each item has a name and a number
 *   - SMALL=0, MEDIUM=1, LARGE=2
 *   - You order by name, the kitchen uses the number
 *   - Much clearer than using raw numbers everywhere
 * ============================================================================
 */

/* --- Struct examples --- */
typedef struct {
    double x, y;
} Vec2;

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

/* Self-referential struct (linked list) */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Flexible array member (C99) */
typedef struct {
    int count;
    int data[];  /* must be last member */
} FlexArray;

/* Bit-fields */
typedef struct {
    unsigned int bold      : 1;  /* 1 bit: 0 or 1 */
    unsigned int italic    : 1;
    unsigned int underline : 1;
    unsigned int color     : 4;  /* 4 bits: 0-15 */
    unsigned int size      : 8;  /* 8 bits: 0-255 */
} TextFormat;

/* --- Union examples --- */
typedef union {
    int i;
    float f;
    char str[20];
} Value;

/* Tagged union (discriminated union) */
typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_STRING } ValueType;
typedef struct {
    ValueType type;
    union {
        int i;
        float f;
        char str[20];
    } as;
} TaggedValue;

static void print_tagged(const TaggedValue *tv) {
    switch (tv->type) {
        case TYPE_INT:    printf("int: %d\n", tv->as.i); break;
        case TYPE_FLOAT:  printf("float: %f\n", tv->as.f); break;
        case TYPE_STRING: printf("string: \"%s\"\n", tv->as.str); break;
    }
}

/* --- Enum examples --- */
typedef enum {
    RED,       /* = 0 */
    GREEN,     /* = 1 */
    BLUE,      /* = 2 */
    ALPHA = 255
} Color;

typedef enum {
    HTTP_OK          = 200,
    HTTP_NOT_FOUND   = 404,
    HTTP_SERVER_ERROR = 500
} HttpStatus;

/* Anonymous struct/union (C11) */
typedef struct {
    union {
        struct { int x, y; };  /* anonymous struct */
        int coords[2];         /* same memory, different access */
    };
} Point2D;

static void section_09_structs_unions_enums(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 9: STRUCTURES, UNIONS, AND ENUMS\n");
    printf("============================================================\n\n");

    /* --- Struct basics --- */
    printf("  --- Struct Basics ---\n");
    Student s1 = {"Alice", 20, 3.9f};
    Student s2 = {.name="Bob", .age=22, .gpa=3.5f};  /* designated (C99) */
    Student s3 = s1;  /* member-wise copy */
    printf("  s1: %s, age %d, GPA %.1f\n", s1.name, s1.age, s1.gpa);
    printf("  s2: %s, age %d, GPA %.1f\n", s2.name, s2.age, s2.gpa);
    printf("  s3 = s1 copy: %s\n", s3.name);

    /* Compound literal (C99) */
    Vec2 v = (Vec2){3.0, 4.0};
    printf("  Compound literal: (%.1f, %.1f)\n", v.x, v.y);

    /* --- Struct memory layout --- */
    printf("\n  --- Struct Memory Layout ---\n");
    struct Layout {
        char a;     /* 1 byte + 3 padding */
        int b;      /* 4 bytes */
        char c;     /* 1 byte + 3 padding */
        double d;   /* 8 bytes */
    };
    printf("  sizeof(Layout) = %zu\n", sizeof(struct Layout));
    printf("  offsetof(a) = %zu\n", offsetof(struct Layout, a));
    printf("  offsetof(b) = %zu\n", offsetof(struct Layout, b));
    printf("  offsetof(c) = %zu\n", offsetof(struct Layout, c));
    printf("  offsetof(d) = %zu\n", offsetof(struct Layout, d));
    printf("  (Padding inserted for alignment — compiler-dependent)\n");

    /* --- Bit-fields --- */
    printf("\n  --- Bit-Fields ---\n");
    TextFormat fmt = {0};
    fmt.bold = 1;
    fmt.italic = 0;
    fmt.underline = 1;
    fmt.color = 9;
    fmt.size = 14;
    printf("  sizeof(TextFormat) = %zu\n", sizeof(TextFormat));
    printf("  bold=%u, italic=%u, underline=%u, color=%u, size=%u\n",
           fmt.bold, fmt.italic, fmt.underline, fmt.color, fmt.size);
    printf("  (Cannot take address of bit-field: &fmt.bold is an error)\n");

    /* --- Flexible array member --- */
    printf("\n  --- Flexible Array Member (C99) ---\n");
    int fc = 5;
    FlexArray *fa = malloc(sizeof(FlexArray) + fc * sizeof(int));
    fa->count = fc;
    for (int i = 0; i < fc; i++) fa->data[i] = (i + 1) * 100;
    printf("  FlexArray: ");
    for (int i = 0; i < fa->count; i++) printf("%d ", fa->data[i]);
    printf("\n");
    free(fa);

    /* --- Linked list --- */
    printf("\n  --- Linked List (Self-Referential Struct) ---\n");
    Node n3 = {3, NULL};
    Node n2 = {2, &n3};
    Node n1 = {1, &n2};
    printf("  List: ");
    for (Node *curr = &n1; curr; curr = curr->next)
        printf("%d → ", curr->data);
    printf("NULL\n");

    /* --- Unions --- */
    printf("\n  --- Unions ---\n");
    Value val;
    printf("  sizeof(Value) = %zu (size of largest member)\n", sizeof(Value));
    val.i = 42;
    printf("  as int: %d\n", val.i);
    val.f = 3.14f;
    printf("  as float: %f (int value now INVALID)\n", val.f);
    strcpy(val.str, "hello");
    printf("  as string: \"%s\" (int/float now INVALID)\n", val.str);

    /* --- Tagged union --- */
    printf("\n  --- Tagged Union (Discriminated) ---\n");
    TaggedValue tv1 = {.type=TYPE_INT,    .as.i=42};
    TaggedValue tv2 = {.type=TYPE_FLOAT,  .as.f=2.718f};
    TaggedValue tv3 = {.type=TYPE_STRING, .as.str="world"};
    print_tagged(&tv1);
    print_tagged(&tv2);
    print_tagged(&tv3);

    /* --- Type punning via union --- */
    printf("\n  --- Type Punning via Union ---\n");
    union { float f; unsigned u; } pun;
    pun.f = 1.0f;
    printf("  float 1.0f as unsigned: 0x%08X (IEEE 754 encoding)\n", pun.u);

    /* --- Anonymous struct/union (C11) --- */
    printf("\n  --- Anonymous Struct/Union (C11) ---\n");
    Point2D pt;
    pt.x = 10; pt.y = 20;  /* via anonymous struct */
    printf("  Named: (%d, %d)\n", pt.x, pt.y);
    printf("  Array: [%d, %d] (same memory)\n", pt.coords[0], pt.coords[1]);

    /* --- Enums --- */
    printf("\n  --- Enums ---\n");
    printf("  RED=%d, GREEN=%d, BLUE=%d, ALPHA=%d\n", RED, GREEN, BLUE, ALPHA);
    Color c = RED;
    printf("  color = %d\n", c);

    switch (HTTP_OK) {
        case 200: printf("  HTTP 200 OK\n"); break;
        case 404: printf("  HTTP 404 Not Found\n"); break;
        case 500: printf("  HTTP 500 Server Error\n"); break;
    }

    printf("\n  C does NOT support struct == struct comparison\n");
    printf("  Must compare member by member or use memcmp (careful with padding)\n");
}


/* ============================================================================
 *  SECTION 10: DYNAMIC MEMORY MANAGEMENT
 * ============================================================================
 *
 * THEORY:
 * -------
 * C gives programmers direct control over heap memory:
 *
 *   malloc(size)        — allocate `size` bytes, UNINITIALIZED, returns NULL on fail
 *   calloc(n, size)     — allocate n*size bytes, ZERO-INITIALIZED, overflow-safe
 *   realloc(ptr, size)  — resize allocation, may MOVE the block
 *   free(ptr)           — deallocate, free(NULL) is a no-op
 *   aligned_alloc(a, s) — allocate with alignment (C11)
 *
 * MEMORY LAYOUT OF A C PROGRAM:
 *   ┌──────────────────┐ High address
 *   │     Stack         │ ← grows downward (local variables, return addresses)
 *   │       ↓           │
 *   │                   │
 *   │       ↑           │
 *   │     Heap          │ ← grows upward (malloc, calloc, realloc)
 *   ├──────────────────┤
 *   │     .bss          │ ← uninitialized globals (zeroed at startup)
 *   ├──────────────────┤
 *   │     .data         │ ← initialized globals
 *   ├──────────────────┤
 *   │     .text         │ ← program code (read-only)
 *   └──────────────────┘ Low address
 *
 * COMMON MEMORY BUGS:
 *   Memory leak:      malloc without free
 *   Double free:      free(ptr); free(ptr);  → UB
 *   Use-after-free:   free(ptr); *ptr = 1;   → UB
 *   Buffer overflow:  arr[10] on a 5-element array → UB
 *   Wild pointer:     int *p; *p = 42; (uninitialized) → UB
 *   Dangling pointer: pointer to freed memory
 *
 * REAL-WORLD ANALOGY:
 *   Dynamic memory is like renting storage units:
 *
 *   malloc(100) = "Rent me a 100-byte storage unit"
 *     → Returns the unit number (address), contents are whatever the last
 *       renter left (uninitialized — could be anything!)
 *
 *   calloc(10, sizeof(int)) = "Rent me space for 10 ints, cleaned out"
 *     → Returns a freshly cleaned unit (zero-initialized)
 *     → Also checks that 10 * sizeof(int) won't overflow
 *
 *   realloc(ptr, 200) = "I need a bigger unit"
 *     → May give you a new, bigger unit (and move your stuff)
 *     → Or may extend your current unit in-place
 *     → Old address may become invalid!
 *
 *   free(ptr) = "I'm done with this unit, return the key"
 *     → The storage company reclaims the space
 *     → Your key (pointer) still exists but the unit is gone
 *     → Using the key after return = use-after-free (UB!)
 *
 *   free(NULL) = "I have no unit to return" → no-op, perfectly safe
 *
 *   Memory leak = "You forgot to return the key" → storage fills up
 *   Double free = "Returning the same key twice" → chaos
 *   Buffer overflow = "Writing past the edge of your unit into your neighbor's"
 * ============================================================================
 */

/* Dynamic array (growable) */
typedef struct {
    int *data;
    size_t len;
    size_t cap;
} DynArr;

static DynArr darr_new(void) { return (DynArr){NULL, 0, 0}; }

static void darr_push(DynArr *a, int x) {
    if (a->len >= a->cap) {
        size_t nc = a->cap ? a->cap * 2 : 4;
        int *nd = realloc(a->data, nc * sizeof(int));
        if (!nd) { fprintf(stderr, "OOM!\n"); exit(1); }
        a->data = nd;
        a->cap = nc;
    }
    a->data[a->len++] = x;
}

static void darr_free(DynArr *a) { free(a->data); *a = darr_new(); }

/* 2D dynamic allocation */
static int **alloc_2d(int rows, int cols) {
    int **m = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) m[i] = calloc(cols, sizeof(int));
    return m;
}
static void free_2d(int **m, int rows) {
    for (int i = 0; i < rows; i++) free(m[i]);
    free(m);
}

static void section_10_dynamic_memory(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 10: DYNAMIC MEMORY MANAGEMENT\n");
    printf("============================================================\n\n");

    /* --- malloc --- */
    printf("  --- malloc (uninitialized) ---\n");
    int *p = malloc(5 * sizeof(int));
    if (!p) { perror("malloc"); return; }
    for (int i = 0; i < 5; i++) p[i] = i * 10;
    printf("  malloc: ");
    for (int i = 0; i < 5; i++) printf("%d ", p[i]);
    printf("\n");
    free(p);

    /* --- calloc (zero-initialized) --- */
    printf("\n  --- calloc (zero-initialized) ---\n");
    int *c = calloc(5, sizeof(int));
    printf("  calloc: ");
    for (int i = 0; i < 5; i++) printf("%d ", c[i]);
    printf(" (all zeros)\n");
    free(c);

    /* --- realloc --- */
    printf("\n  --- realloc (resize) ---\n");
    int *r = malloc(3 * sizeof(int));
    r[0] = 10; r[1] = 20; r[2] = 30;
    printf("  Before (3): ");
    for (int i = 0; i < 3; i++) printf("%d ", r[i]);
    printf("\n");

    r = realloc(r, 6 * sizeof(int));
    r[3] = 40; r[4] = 50; r[5] = 60;
    printf("  After (6):  ");
    for (int i = 0; i < 6; i++) printf("%d ", r[i]);
    printf("\n");
    free(r);

    /* realloc(NULL) = malloc */
    int *rn = realloc(NULL, 5 * sizeof(int));
    if (rn) { rn[0] = 999; printf("  realloc(NULL)[0] = %d\n", rn[0]); free(rn); }

    /* --- Dynamic array --- */
    printf("\n  --- Dynamic Array (Growable) ---\n");
    DynArr da = darr_new();
    for (int i = 0; i < 20; i++) darr_push(&da, i * i);
    printf("  DynArr (%zu/%zu): ", da.len, da.cap);
    for (size_t i = 0; i < da.len; i++) printf("%d ", da.data[i]);
    printf("\n");
    darr_free(&da);

    /* --- 2D dynamic allocation --- */
    printf("\n  --- 2D Dynamic Array ---\n");
    int **mat = alloc_2d(3, 4);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            mat[i][j] = i * 4 + j + 1;
    printf("  2D array:\n");
    for (int i = 0; i < 3; i++) {
        printf("    ");
        for (int j = 0; j < 4; j++) printf("%3d ", mat[i][j]);
        printf("\n");
    }
    free_2d(mat, 3);

    /* --- aligned_alloc (C11) --- */
    printf("\n  --- aligned_alloc (C11) ---\n");
    int *al = aligned_alloc(64, 64 * sizeof(int));
    if (al) {
        printf("  Address: %p (mod 64 = %zu)\n", (void*)al, (size_t)(void*)al % 64);
        free(al);
    }

    /* --- Memory safety rules --- */
    printf("\n  --- Memory Safety Rules ---\n");
    printf("  1. Always check malloc/calloc/realloc return (NULL = failure)\n");
    printf("  2. Always free what you allocate\n");
    printf("  3. Never use memory after free (use-after-free)\n");
    printf("  4. Never free the same pointer twice (double free)\n");
    printf("  5. Set pointer to NULL after free\n");
    printf("  6. Allocate strlen(s)+1 for string copies\n");
    printf("  7. Check for integer overflow: nmemb * size could overflow\n");
    printf("  8. Use Valgrind, ASan, MSan to detect bugs\n");
}


/* ============================================================================
 *  SECTION 11: STRINGS
 * ============================================================================
 *
 * THEORY:
 * -------
 * C strings are NULL-TERMINATED BYTE ARRAYS:
 *   char s[] = "hello"  →  {'h','e','l','l','o','\0'}  (6 bytes)
 *   strlen(s) = 5  (excludes \0)
 *   sizeof(s) = 6  (includes \0)
 *
 * STRING FUNCTIONS (<string.h>):
 *   strlen(s)              — length (excluding \0)
 *   strcpy(dest, src)      — copy (UNSAFE: no bounds check)
 *   strncpy(dest, src, n)  — bounded copy (may NOT null-terminate!)
 *   strcat(dest, src)      — concatenate (UNSAFE)
 *   strncat(dest, src, n)  — bounded concatenate
 *   strcmp(s1, s2)         — compare (<0, 0, >0)
 *   strncmp(s1, s2, n)     — bounded compare
 *   strstr(haystack, needle) — find substring
 *   strchr(s, c)           — find first occurrence of c
 *   strrchr(s, c)          — find last occurrence of c
 *   strtok(s, delim)       — tokenize (DESTRUCTIVE, NOT reentrant)
 *   memcpy(dest, src, n)   — copy n bytes (NO overlap)
 *   memmove(dest, src, n)  — copy n bytes (HANDLES overlap)
 *   memset(dest, c, n)     — fill n bytes with c
 *   memcmp(s1, s2, n)      — compare n bytes
 *
 * SAFE ALTERNATIVES:
 *   snprintf instead of sprintf
 *   fgets instead of gets (gets removed in C11!)
 *   strncat with proper size calculation
 *
 * REAL-WORLD ANALOGY:
 *   A C string is like a sentence written on a tape:
 *   - The tape has letters followed by a special "end" marker (\0)
 *   - strlen counts letters until the end marker
 *   - sizeof measures the entire tape including the end marker
 *   - strcpy is like a photocopier with no paper limit — it copies
 *     everything, even if the destination paper is too small (OVERFLOW!)
 *   - strncpy is like a photocopier with a page limit — safer, but
 *     might not include the "end" marker if the source is too long
 *   - strcmp is like a dictionary comparison: letter by letter
 *   - strtok is like cutting a tape at delimiter marks (destructive!)
 *   - memcpy is like a precise copy machine (no overlap allowed)
 *   - memmove is like a careful relocation service (handles overlap)
 * ============================================================================
 */

static void section_11_strings(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 11: STRINGS\n");
    printf("============================================================\n\n");

    /* --- String basics --- */
    printf("  --- String Basics ---\n");
    char greeting[] = "Hello";  /* char[6]: H,e,l,l,o,\0 */
    const char *literal = "World";
    printf("  greeting: \"%s\" (sizeof=%zu, strlen=%zu)\n",
           greeting, sizeof(greeting), strlen(greeting));
    printf("  literal:  \"%s\" (sizeof=%zu = pointer size)\n",
           literal, sizeof(literal));

    /* --- snprintf (safe formatting) --- */
    printf("\n  --- Safe Formatting (snprintf) ---\n");
    char buf[100];
    int n = snprintf(buf, sizeof(buf), "Name: %s, Age: %d, Pi: %.4f",
                     "Alice", 30, 3.14159);
    printf("  snprintf (%d chars): \"%s\"\n", n, buf);

    char small[10];
    int m = snprintf(small, sizeof(small), "This is a very long string");
    printf("  Truncated (%d wanted): \"%s\"\n", m, small);

    /* --- strcpy / strncpy --- */
    printf("\n  --- strcpy / strncpy ---\n");
    char dest[20];
    strcpy(dest, "Hello");
    printf("  strcpy: \"%s\" (DANGEROUS: no bounds check)\n", dest);

    char nd[6];
    strncpy(nd, "Hello, World!", sizeof(nd) - 1);
    nd[sizeof(nd) - 1] = '\0';  /* MUST add null terminator! */
    printf("  strncpy: \"%s\" (truncated, manually null-terminated)\n", nd);

    /* --- strcat / strncat --- */
    printf("\n  --- strcat / strncat ---\n");
    char path[100] = "/home/";
    strcat(path, "user/");
    strcat(path, "file.txt");
    printf("  strcat: \"%s\"\n", path);

    char bounded[20] = "Hello";
    strncat(bounded, ", World!!!", sizeof(bounded) - strlen(bounded) - 1);
    printf("  strncat: \"%s\"\n", bounded);

    /* --- strcmp --- */
    printf("\n  --- strcmp ---\n");
    printf("  strcmp(\"abc\", \"abc\") = %d (equal)\n", strcmp("abc", "abc"));
    printf("  strcmp(\"abc\", \"abd\") = %d (a < b)\n", strcmp("abc", "abd"));
    printf("  strcmp(\"abd\", \"abc\") = %d (b > a)\n", strcmp("abd", "abc"));

    /* --- Search functions --- */
    printf("\n  --- Search Functions ---\n");
    const char *text = "Hello, World! Hello, C!";
    printf("  strchr('H'):  \"%s\"\n", strchr(text, 'H'));
    printf("  strrchr('H'): \"%s\"\n", strrchr(text, 'H'));
    printf("  strstr(\"World\"): \"%s\"\n", strstr(text, "World"));
    printf("  strstr(\"xyz\"):   %s\n", strstr(text, "xyz") ?: "(null)");

    /* --- strtok --- */
    printf("\n  --- strtok (destructive, not reentrant) ---\n");
    char input[] = "one,two,,four,five";
    char *tok = strtok(input, ",");
    printf("  Tokens: ");
    while (tok) { printf("[%s] ", tok); tok = strtok(NULL, ","); }
    printf("\n");

    /* --- Memory functions --- */
    printf("\n  --- memcpy / memmove / memset / memcmp ---\n");
    int src[] = {1, 2, 3, 4, 5}, dst[5];
    memcpy(dst, src, sizeof(src));
    printf("  memcpy: ");
    for (int i = 0; i < 5; i++) printf("%d ", dst[i]);
    printf("\n");

    int ov[] = {1, 2, 3, 4, 5, 6, 7, 8};
    memmove(&ov[0], &ov[2], 5 * sizeof(int));  /* overlapping! */
    printf("  memmove (overlap): ");
    for (int i = 0; i < 8; i++) printf("%d ", ov[i]);
    printf("\n");

    char filled[11];
    memset(filled, 'A', 10);
    filled[10] = '\0';
    printf("  memset: \"%s\"\n", filled);

    printf("  memcmp(\"abc\",\"abd\",3) = %d\n", memcmp("abc", "abd", 3));

    /* --- String-to-number --- */
    printf("\n  --- String-to-Number ---\n");
    printf("  atoi(\"42\") = %d (no error detection)\n", atoi("42"));

    char *end;
    long lv = strtol("12345", &end, 10);
    printf("  strtol(\"12345\") = %ld\n", lv);
    lv = strtol("0xFF", &end, 16);
    printf("  strtol(\"0xFF\", base=16) = %ld\n", lv);

    double dv = strtod("3.14159", &end);
    printf("  strtod(\"3.14159\") = %f\n", dv);

    /* --- Character classification --- */
    printf("\n  --- Character Classification (<ctype.h>) ---\n");
    const char *ch = "Aa1! ";
    for (const char *cp = ch; *cp; cp++) {
        unsigned char uc = (unsigned char)*cp;
        printf("  '%c': alpha=%d digit=%d upper=%d lower=%d space=%d punct=%d\n",
               *cp, isalpha(uc), isdigit(uc), isupper(uc),
               islower(uc), isspace(uc), ispunct(uc));
    }
    printf("  toupper('a')='%c', tolower('Z')='%c'\n", toupper('a'), tolower('Z'));
}


/* ============================================================================
 *  SECTION 12: PREPROCESSOR
 * ============================================================================
 *
 * THEORY:
 * -------
 * The preprocessor runs BEFORE the compiler. It performs textual transformations:
 *
 *   #include "file" / <file>  — textual inclusion
 *   #define NAME value         — object-like macro
 *   #define FUNC(a,b) expr     — function-like macro
 *   #undef NAME               — undefine macro
 *   #if / #ifdef / #ifndef / #elif / #else / #endif — conditional compilation
 *   #error "message"          — compile-time error
 *   #pragma                   — implementation-specific directive
 *   #line linenum "file"      — set line number and filename
 *   #embed "file" (C23)       — binary resource inclusion
 *
 * SPECIAL OPERATORS:
 *   ## (token pasting): CONCAT(a,b) → a##b → ab
 *   #  (stringification): STR(x) → #x → "x"
 *   __VA_ARGS__ : variadic macro arguments
 *   __VA_OPT__  : handle empty variadic args (C23)
 *
 * PREDEFINED MACROS:
 *   __FILE__, __LINE__, __DATE__, __TIME__, __STDC__, __STDC_VERSION__
 *   __func__ (not a macro — implicit local variable)
 *   __VA_ARGS__, __VA_OPT__ (C23)
 *
 * REAL-WORLD ANALOGY:
 *   The preprocessor is like a SMART COPY MACHINE that runs before printing:
 *
 *   #include = "Insert this entire page here" (like mail merge)
 *   #define  = "Find and replace: replace all X with Y"
 *   #if      = "If this condition, print this page; otherwise, skip it"
 *   ##       = "Glue these two words together" (paste tokens)
 *   #        = "Put quotes around this" (stringify)
 *
 *   The copy machine runs FIRST, then the result goes to the compiler.
 *   Macros are NOT functions — they're text substitutions!
 *   This means:
 *   - Arguments may be evaluated multiple times (side effects!)
 *   - No type checking at macro definition
 *   - Prefer const/enum/inline over #define when possible
 * ============================================================================
 */

/* Object-like macros */
#define PI 3.14159265358979
#define MAX_BUF 1024

/* Function-like macros (parenthesize arguments!) */
#define MAX(a, b)       ((a) > (b) ? (a) : (b))
#define MIN(a, b)       ((a) < (b) ? (a) : (b))
#define ABS(x)          ((x) < 0 ? -(x) : (x))
#define CLAMP(v, lo, hi) MIN(MAX((v), (lo)), (hi))
#define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof((arr)[0]))

/* do-while(0) idiom for multi-statement macros */
#define SWAP(a, b) do { typeof(a) _t = (a); (a) = (b); (b) = _t; } while(0)

/* Token pasting */
#define MAKE_VAR(prefix, num) prefix##_##num

/* Stringification */
#define STRINGIFY(x) #x
#define PRINT_VAR(var) printf("  " #var " = %d\n", var)

/* Variadic macros */
#define LOG(fmt, ...) fprintf(stderr, "[LOG %s:%d] " fmt "\n", \
                              __FILE__, __LINE__, ##__VA_ARGS__)

/* X-Macro pattern */
#define COLOR_TABLE(X) \
    X(RED,   0xFF0000) \
    X(GREEN, 0x00FF00) \
    X(BLUE,  0x0000FF)

enum Colors {
    #define X_ENUM(name, val) name##_COLOR = val,
    COLOR_TABLE(X_ENUM)
    #undef X_ENUM
};

/* Compile-time assertion */
_Static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

static void section_12_preprocessor(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 12: PREPROCESSOR\n");
    printf("============================================================\n\n");

    /* --- Object-like macros --- */
    printf("  --- Object-Like Macros ---\n");
    printf("  PI = %f\n", PI);
    printf("  MAX_BUF = %d\n", MAX_BUF);

    /* --- Function-like macros --- */
    printf("\n  --- Function-Like Macros ---\n");
    int a = 10, b = 20;
    printf("  MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("  MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("  ABS(-42) = %d\n", ABS(-42));
    printf("  CLAMP(15, 0, 10) = %d\n", CLAMP(15, 0, 10));

    int arr[] = {1, 2, 3, 4, 5};
    printf("  ARRAY_SIZE = %zu\n", ARRAY_SIZE(arr));

    printf("  Before SWAP: a=%d, b=%d\n", a, b);
    SWAP(a, b);
    printf("  After SWAP:  a=%d, b=%d\n", a, b);

    /* --- Side effect warning --- */
    printf("\n  --- MACRO SIDE EFFECT WARNING ---\n");
    printf("  MAX(i++, j++) evaluates one side TWICE!\n");
    printf("  Use inline functions for expressions with side effects\n");

    /* --- Token pasting --- */
    printf("\n  --- Token Pasting (##) ---\n");
    int MAKE_VAR(coord, x) = 10;
    int MAKE_VAR(coord, y) = 20;
    printf("  coord_x = %d, coord_y = %d\n", coord_x, coord_y);

    /* --- Stringification --- */
    printf("\n  --- Stringification (#) ---\n");
    printf("  STRINGIFY(Hello World) = \"%s\"\n", STRINGIFY(Hello World));
    int sv = 42;
    PRINT_VAR(sv);

    /* --- Variadic macros --- */
    printf("\n  --- Variadic Macros ---\n");
    LOG("Server started on port %d", 8080);

    /* --- X-Macro pattern --- */
    printf("\n  --- X-Macro Pattern ---\n");
    printf("  RED_COLOR=0x%06X, GREEN_COLOR=0x%06X, BLUE_COLOR=0x%06X\n",
           RED_COLOR, GREEN_COLOR, BLUE_COLOR);

    /* --- Predefined macros --- */
    printf("\n  --- Predefined Macros ---\n");
    printf("  __FILE__         = %s\n", __FILE__);
    printf("  __LINE__         = %d\n", __LINE__);
    printf("  __DATE__         = %s\n", __DATE__);
    printf("  __TIME__         = %s\n", __TIME__);
    printf("  __STDC_VERSION__ = %ld\n", __STDC_VERSION__);
    printf("  __func__         = %s\n", __func__);

    /* --- Conditional compilation --- */
    printf("\n  --- Conditional Compilation ---\n");
    #if defined(__linux__)
        printf("  Platform: Linux\n");
    #elif defined(__APPLE__)
        printf("  Platform: macOS\n");
    #elif defined(_WIN32)
        printf("  Platform: Windows\n");
    #else
        printf("  Platform: Unknown\n");
    #endif

    #ifdef __GNUC__
        printf("  Compiler: GCC %d.%d\n", __GNUC__, __GNUC_MINOR__);
    #endif

    /* --- Best practices --- */
    printf("\n  --- Preprocessor Best Practices ---\n");
    printf("  1. UPPER_CASE for macro names\n");
    printf("  2. Parenthesize ALL macro arguments\n");
    printf("  3. do { ... } while(0) for multi-statement macros\n");
    printf("  4. Prefer const/enum/inline over #define\n");
    printf("  5. Include guards in every header\n");
    printf("  6. Be aware of multiple evaluation\n");
}


/* ============================================================================
 *  SECTION 13: INPUT/OUTPUT
 * ============================================================================
 *
 * THEORY:
 * -------
 * <stdio.h> provides STREAM-BASED I/O through FILE* pointers.
 *
 * STANDARD STREAMS:
 *   stdin  — standard input (keyboard, pipe)
 *   stdout — standard output (terminal, pipe) — line-buffered
 *   stderr — standard error (terminal) — unbuffered
 *
 * BUFFERING MODES:
 *   _IOFBF — fully buffered (data sent when buffer full)
 *   _IOLBF — line buffered (data sent on newline)
 *   _IONBF — unbuffered (data sent immediately)
 *
 * FILE OPERATIONS:
 *   fopen(path, mode)  → FILE* (NULL on failure)
 *   fclose(stream)     → 0 on success, EOF on error
 *   fread / fwrite     — block I/O
 *   fprintf / fscanf   — formatted I/O
 *   fgets / fputs      — line I/O
 *   fgetc / fputc      — character I/O
 *   fseek / ftell      — positioning
 *   feof / ferror      — error checking
 *
 * FORMAT SPECIFIERS:
 *   %d int    %u unsigned    %o octal    %x hex    %X HEX
 *   %f float  %e scientific  %g shorter  %a hex float
 *   %c char   %s string      %p pointer  %n chars written
 *   %zu size_t  %td ptrdiff_t  %lld long long
 *   Flags: - left-align  + show-sign  0 zero-pad  # alternate  ' ' space
 *   Width: %10d (min width)  %.5f (precision)  %*d (dynamic width)
 *
 * REAL-WORLD ANALOGY:
 *   Streams are like WATER PIPES:
 *
 *   - A stream (FILE*) is a pipe connecting your program to a data source/sink
 *   - stdin is the water main (input from outside)
 *   - stdout is the drain (output to display)
 *   - stderr is the emergency overflow (error messages, unbuffered)
 *
 *   Buffering is like a RESERVOIR:
 *   - Fully buffered: water fills the reservoir, then flushes all at once
 *   - Line buffered: water flushes every time a newline arrives
 *   - Unbuffered: water flows through immediately (slower but real-time)
 *
 *   fopen("file", "r") = "Connect a pipe to this file for reading"
 *   fclose(stream) = "Disconnect the pipe, flush remaining water"
 *   fprintf(stream, ...) = "Send formatted water through the pipe"
 *   fgets(buf, n, stream) = "Collect up to n-1 characters of water into buf"
 *
 *   Binary vs Text streams:
 *   - Text: may translate line endings (\n ↔ \r\n on Windows)
 *   - Binary: raw bytes, no translation (use for images, data files)
 * ============================================================================
 */

static void section_13_io(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 13: INPUT/OUTPUT\n");
    printf("============================================================\n\n");

    /* --- printf format specifiers --- */
    printf("  --- printf Format Specifiers ---\n");
    printf("  %%d:   %d\n", 42);
    printf("  %%u:   %u\n", 42u);
    printf("  %%o:   %o (octal)\n", 42);
    printf("  %%x:   %x (hex)\n", 255);
    printf("  %%X:   %X (HEX)\n", 255);
    printf("  %%f:   %f\n", 3.14159);
    printf("  %%.2f: %.2f\n", 3.14159);
    printf("  %%e:   %e (scientific)\n", 123456.789);
    printf("  %%g:   %g (shorter)\n", 123456.789);
    printf("  %%a:   %a (hex float)\n", 3.14159);
    printf("  %%c:   %c\n", 'A');
    printf("  %%s:   %s\n", "hello");
    printf("  %%p:   %p\n", (void*)&printf);
    printf("  %%zu:  %zu (size_t)\n", sizeof(int));
    printf("  %%08x: %08x (zero-padded)\n", 42);
    printf("  %%+d:  %+d (show sign)\n", 42);
    printf("  %%10d: \"%10d\" (right-align)\n", 42);
    printf("  %%-10d:\"%-10d\" (left-align)\n", 42);
    printf("  %%%%:  literal percent\n");

    /* --- File I/O --- */
    printf("\n  --- File I/O ---\n");
    const char *fn = "/tmp/c_master_test.txt";

    /* Write */
    FILE *f = fopen(fn, "w");
    if (f) {
        fprintf(f, "Line 1: Hello, File!\n");
        fprintf(f, "Line 2: Number = %d\n", 42);
        fprintf(f, "Line 3: Pi = %.6f\n", 3.141593);
        fclose(f);
        printf("  Wrote 3 lines to %s\n", fn);
    }

    /* Read */
    f = fopen(fn, "r");
    if (f) {
        char line[256];
        printf("  File contents:\n");
        while (fgets(line, sizeof(line), f)) {
            printf("    > %s", line);
        }
        if (ferror(f)) printf("  Error reading!\n");
        else printf("  (EOF reached)\n");
        fclose(f);
    }

    /* --- Binary I/O --- */
    printf("\n  --- Binary I/O ---\n");
    const char *bfn = "/tmp/c_master_binary.bin";
    int nums[] = {10, 20, 30, 40, 50};
    f = fopen(bfn, "wb");
    if (f) { fwrite(nums, sizeof(int), 5, f); fclose(f); }

    int rnums[5] = {0};
    f = fopen(bfn, "rb");
    if (f) {
        size_t cnt = fread(rnums, sizeof(int), 5, f);
        printf("  Read %zu ints: ", cnt);
        for (int i = 0; i < 5; i++) printf("%d ", rnums[i]);
        printf("\n");
        fclose(f);
    }

    /* --- File positioning --- */
    printf("\n  --- File Positioning ---\n");
    f = fopen(fn, "r");
    if (f) {
        fseek(f, 0, SEEK_END);
        printf("  File size: %ld bytes\n", ftell(f));
        fseek(f, 0, SEEK_SET);
        fclose(f);
    }

    /* --- sscanf --- */
    printf("\n  --- sscanf ---\n");
    const char *data = "Alice 25 95.5";
    char name[50]; int age; float score;
    int matched = sscanf(data, "%49s %d %f", name, &age, &score);
    printf("  sscanf matched %d: name=\"%s\", age=%d, score=%.1f\n",
           matched, name, age, score);

    /* Cleanup */
    remove(fn);
    remove(bfn);
}


/* ============================================================================
 *  SECTION 14: TYPE CONVERSIONS
 * ============================================================================
 *
 * THEORY:
 * -------
 * C performs implicit conversions (coercions) in many contexts:
 *
 * INTEGER PROMOTION:
 *   char/short → int (or unsigned int if int can't represent all values)
 *   _Bool → int
 *   Happens automatically in expressions
 *
 * USUAL ARITHMETIC CONVERSIONS (for binary operators):
 *   1. If either is long double → both long double
 *   2. Else if either is double → both double
 *   3. Else if either is float → both float
 *   4. Else: integer promotions, then:
 *      a. Same type → no change
 *      b. Same signedness → smaller to larger
 *      c. Unsigned ≥ signed in size → signed to unsigned (DANGEROUS!)
 *      d. Signed can represent all unsigned values → unsigned to signed
 *      e. Otherwise → both to unsigned version of signed type
 *
 * ASSIGNMENT CONVERSION:
 *   Right side converted to left side type
 *   Narrowing may lose data: int x = 3.9; → x = 3
 *
 * EXPLICIT CAST: (type)expression
 *   Forces conversion — use sparingly, signals intentional conversion
 *
 * _Generic (C11):
 *   Compile-time type-based dispatch:
 *   _Generic(expr, int: ..., float: ..., default: ...)
 *
 * REAL-WORLD ANALOGY:
 *   Type conversions are like UNIT CONVERSIONS in measurement:
 *
 *   Implicit = automatic conversion when mixing units:
 *     1 meter + 100 centimeters → both converted to same unit
 *     int + double → both converted to double (the "bigger" unit)
 *
 *   Dangerous implicit = losing information:
 *     int x = -1; unsigned int y = x;  // -1 becomes 4294967295!
 *     Like saying "I owe you $1" but the unsigned register shows "$4,294,967295"
 *
 *   Explicit cast = deliberately converting:
 *     (int)3.9 → 3 (you KNOW you're losing the .9)
 *     Like choosing to round down deliberately
 *
 *   _Generic = a type-based switch statement at compile time:
 *     "If the input is an int, use this formula; if float, use that one"
 * ============================================================================
 */

/* _Generic macro: type-based dispatch */
#define type_name(x) _Generic((x),    \
    int:        "int",                  \
    long:       "long",                 \
    long long:  "long long",            \
    float:      "float",                \
    double:     "double",               \
    char *:     "char*",                \
    default:    "other"                 \
)

static void section_14_type_conversions(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 14: TYPE CONVERSIONS\n");
    printf("============================================================\n\n");

    /* --- Integer promotion --- */
    printf("  --- Integer Promotion ---\n");
    char ca = 100, cb = 200;
    int sum = ca + cb;  /* both promoted to int: 300, not -56 */
    printf("  char %d + char %d = int %d (promoted before addition)\n", ca, cb, sum);
    printf("  sizeof('A') = %zu (char promoted to int)\n", sizeof('A'));

    /* --- Usual arithmetic conversions --- */
    printf("\n  --- Usual Arithmetic Conversions ---\n");
    int i = 10;
    double d = 3.14;
    printf("  int + double → %s: %f\n", type_name(i + d), i + d);
    float f = 2.5f;
    printf("  float + int → %s: %f\n", type_name(f + i), f + i);

    /* --- SIGNED/UNSIGNED MIXING (DANGEROUS!) --- */
    printf("\n  --- SIGNED/UNSIGNED MIXING (DANGER!) ---\n");
    unsigned int ui = 4294967295u;  /* UINT_MAX */
    int si = -1;
    printf("  ui = %u (UINT_MAX)\n", ui);
    printf("  si = %d (-1)\n", si);
    printf("  ui == si? %s (signed -1 converted to unsigned UINT_MAX!)\n",
           (ui == (unsigned int)si) ? "TRUE" : "false");
    printf("  LESSON: Never compare signed and unsigned!\n");

    /* --- Narrowing conversions --- */
    printf("\n  --- Narrowing Conversions ---\n");
    double dbl = 3.99;
    int trunc = (int)dbl;
    printf("  (int)%.2f = %d (truncation toward zero)\n", dbl, trunc);

    int precise = 16777217;  /* 2^24 + 1 */
    float imprecise = (float)precise;
    printf("  (float)%d = %f → (int)%f = %d (precision lost!)\n",
           precise, imprecise, imprecise, (int)imprecise);

    /* --- _Generic (C11) --- */
    printf("\n  --- _Generic (C11) ---\n");
    printf("  type_name(42)    = \"%s\"\n", type_name(42));
    printf("  type_name(42L)   = \"%s\"\n", type_name(42L));
    printf("  type_name(42LL)  = \"%s\"\n", type_name(42LL));
    printf("  type_name(3.14f) = \"%s\"\n", type_name(3.14f));
    printf("  type_name(3.14)  = \"%s\"\n", type_name(3.14));
    printf("  type_name(\"hi\")  = \"%s\"\n", type_name("hi"));

    /* --- Boolean context --- */
    printf("\n  --- Boolean Context ---\n");
    int vals[] = {0, 1, -1, 42, -100};
    for (size_t vi = 0; vi < 5; vi++) {
        printf("  (%d) is %s\n", vals[vi], vals[vi] ? "true" : "false");
    }
    printf("  Any non-zero value is true in C\n");
}


/* ============================================================================
 *  SECTION 15: SCOPE, LINKAGE, AND STORAGE DURATION
 * ============================================================================
 *
 * THEORY:
 * -------
 * Three independent concepts:
 *
 * SCOPE (where a name is visible):
 *   File scope       — declared outside all blocks (global)
 *   Block scope      — declared inside { } or function parameters
 *   Function scope   — labels only (goto targets)
 *   Prototype scope  — parameter names in function prototypes
 *
 * LINKAGE (whether names in different scopes refer to the same entity):
 *   External linkage — visible across translation units (default for functions/globals)
 *   Internal linkage — visible only in this translation unit (static at file scope)
 *   No linkage       — block-scoped variables, labels
 *
 * STORAGE DURATION (when memory is allocated/freed):
 *   Automatic  — block entry to block exit (local variables, stack)
 *   Static     — program startup to program exit (globals, static locals)
 *   Allocated  — malloc to free (heap)
 *   Thread     — thread creation to thread exit (_Thread_local)
 *
 * NAME SPACES (C11):
 *   1. Label names (goto targets)
 *   2. Tag names (struct/union/enum tags)
 *   3. Member names (each struct/union has its own)
 *   4. All other identifiers (variables, functions, typedefs, enumerators)
 *
 * REAL-WORLD ANALOGY:
 *   Scope is like VISIBILITY in a building:
 *   - File scope = the entire building can see it (lobby sign)
 *   - Block scope = only people in this room can see it (whiteboard)
 *   - Function scope = only labels (exit signs visible from anywhere on the floor)
 *
 *   Linkage is like PHONE NUMBERS:
 *   - External = listed in the public directory (other files can call)
 *   - Internal = extension number within one office (same .c file only)
 *   - No linkage = internal memo (only exists within one room)
 *
 *   Storage duration is like LEASE TERMS:
 *   - Automatic = daily rental (created when you enter, gone when you leave)
 *   - Static = permanent lease (exists for the life of the building)
 *   - Allocated = on-demand warehouse (created when needed, returned when done)
 *   - Thread = per-worker desk (exists as long as the worker is employed)
 * ============================================================================
 */

/* File scope, external linkage */
int global_extern = 100;

/* File scope, internal linkage */
static int file_static = 200;

static void scope_linkage_demo(void) {
    printf("  --- Block Scope & Shadowing ---\n");
    int x = 10;
    printf("  Outer x = %d\n", x);
    {
        int x = 20;  /* shadows outer */
        printf("  Inner x = %d (shadows outer)\n", x);
        {
            int x = 30;
            printf("  Deepest x = %d\n", x);
        }
        printf("  Inner x = %d\n", x);
    }
    printf("  Outer x = %d (restored)\n", x);
}

static void counter_demo(void) {
    static int count = 0;  /* persists across calls, initialized once */
    count++;
    printf("  counter() call #%d\n", count);
}

static void section_15_scope_linkage(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 15: SCOPE, LINKAGE, STORAGE DURATION\n");
    printf("============================================================\n\n");

    printf("  --- Linkage ---\n");
    printf("  global_extern (external): %d\n", global_extern);
    printf("  file_static (internal):   %d\n", file_static);

    scope_linkage_demo();

    printf("\n  --- Static Local (Persists Across Calls) ---\n");
    counter_demo();
    counter_demo();
    counter_demo();

    printf("\n  --- Loop Variable Scope (C99+) ---\n");
    for (int li = 0; li < 3; li++) printf("  loop i = %d\n", li);
    /* i not accessible here */

    printf("\n  --- Summary ---\n");
    printf("  Scope:     WHERE a name is visible\n");
    printf("  Linkage:   WHETHER names across scopes match\n");
    printf("  Lifetime:  WHEN storage exists\n");
    printf("  These three are INDEPENDENT concepts!\n");
}


/* ============================================================================
 *  SECTION 16: ERROR HANDLING
 * ============================================================================
 *
 * THEORY:
 * -------
 * C has NO exceptions. Error handling uses:
 *
 *   1. RETURN VALUES: Functions return error codes (0=success, -1=error)
 *      Result passed via output pointer parameter
 *
 *   2. errno (<errno.h>): Thread-local error code set by library functions
 *      Standard codes: EDOM, ERANGE, EILSEQ
 *      Check IMMEDIATELY after the failing call
 *      perror() prints human-readable error message
 *
 *   3. setjmp/longjmp: Non-local jumps (like try/catch)
 *      setjmp(env) saves context, returns 0
 *      longjmp(env, val) restores context, returns val
 *      Local variables modified between setjmp/longjmp must be volatile
 *
 *   4. assert(expr): Aborts on failure (disabled with NDEBUG)
 *      _Static_assert(expr, msg): Compile-time assertion (C11)
 *
 * REAL-WORLD ANALOGY:
 *   Error handling is like SAFETY PROCEDURES in a factory:
 *
 *   Return values = Quality control checkpoints:
 *     "Did this step succeed? Yes → continue. No → handle the defect."
 *
 *   errno = A shared error logbook:
 *     When a machine fails, it writes the error code in the logbook.
 *     You must check the logbook IMMEDIATELY — another machine might overwrite it.
 *
 *   setjmp/longjmp = Emergency evacuation:
 *     setjmp = "Remember this location in case of emergency"
 *     longjmp = "EMERGENCY! Everyone back to the assembly point!"
 *     Like a fire drill — everyone jumps back to the rally point.
 *
 *   assert = Safety interlock:
 *     "If this condition isn't met, STOP EVERYTHING immediately."
 *     Only active during testing (disabled in production with NDEBUG).
 * ============================================================================
 */

typedef enum {
    ERR_OK = 0,
    ERR_NULL_PTR,
    ERR_OUT_OF_RANGE,
    ERR_ALLOC_FAILED,
    ERR_IO
} ErrorCode;

static const char *err_str(ErrorCode e) {
    static const char *msgs[] = {
        "Success", "Null pointer", "Out of range",
        "Allocation failed", "I/O error"
    };
    return (e >= 0 && e <= ERR_IO) ? msgs[e] : "Unknown";
}

static ErrorCode safe_divide(int a, int b, int *result) {
    if (!result) return ERR_NULL_PTR;
    if (b == 0) { *result = 0; return ERR_OUT_OF_RANGE; }
    *result = a / b;
    return ERR_OK;
}

/* Goto-based cleanup */
static ErrorCode process_data(const char *input, int *output) {
    ErrorCode err = ERR_OK;
    int *buf = NULL;

    if (!input || !output) { err = ERR_NULL_PTR; goto cleanup; }

    buf = malloc(1024 * sizeof(int));
    if (!buf) { err = ERR_ALLOC_FAILED; goto cleanup; }

    /* Simulate processing */
    *output = (int)strlen(input);

cleanup:
    free(buf);
    return err;
}

/* setjmp/longjmp */
static jmp_buf jump_buf;
static void risky_operation(int depth) {
    if (depth >= 3) {
        longjmp(jump_buf, depth);  /* jump back! */
    }
    risky_operation(depth + 1);
}

static void section_16_error_handling(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 16: ERROR HANDLING\n");
    printf("============================================================\n\n");

    /* --- Return value pattern --- */
    printf("  --- Return Value Pattern ---\n");
    int result;
    ErrorCode err;
    err = safe_divide(10, 3, &result);
    printf("  10 / 3 = %d (%s)\n", result, err_str(err));
    err = safe_divide(10, 0, &result);
    printf("  10 / 0 = %d (%s)\n", result, err_str(err));

    /* --- errno --- */
    printf("\n  --- errno ---\n");
    errno = 0;
    strtod("1e99999", NULL);
    printf("  strtod overflow: errno=%d (ERANGE=%d)\n", errno, ERANGE);

    errno = 0;
    FILE *f = fopen("/nonexistent", "r");
    if (!f) {
        printf("  fopen failed: %s\n", strerror(errno));
        perror("  perror");
    }

    /* --- Goto cleanup --- */
    printf("\n  --- Goto Cleanup Pattern ---\n");
    int out;
    err = process_data("hello", &out);
    printf("  process_data: %s (output=%d)\n", err_str(err), out);

    /* --- setjmp/longjmp --- */
    printf("\n  --- setjmp/longjmp ---\n");
    int ret = setjmp(jump_buf);
    if (ret == 0) {
        printf("  setjmp returned 0 (initial)\n");
        risky_operation(0);
    } else {
        printf("  longjmp returned %d (error from depth %d)\n", ret, ret);
    }

    /* --- Assertions --- */
    printf("\n  --- Assertions ---\n");
    int av = 42;
    assert(av == 42);  /* passes silently */
    printf("  assert(42 == 42): passed\n");
    _Static_assert(sizeof(void*) >= 4, "pointers must be >= 4 bytes");
    printf("  _Static_assert: passed at compile time\n");
}


/* ============================================================================
 *  SECTION 17: CONCURRENCY (POSIX Threads)
 * ============================================================================
 *
 * THEORY:
 * -------
 * C11 added <threads.h> but POSIX threads (pthreads) are more widely available.
 *
 * THREADS:
 *   pthread_create() — spawn a new thread
 *   pthread_join()   — wait for thread to finish
 *   pthread_detach() — let thread run independently
 *
 * SYNCHRONIZATION:
 *   Mutex (mutual exclusion):
 *     pthread_mutex_lock()   — acquire (blocks if held by another)
 *     pthread_mutex_unlock() — release
 *     pthread_mutex_trylock() — non-blocking acquire
 *
 *   Condition variable:
 *     pthread_cond_wait()      — release mutex and sleep
 *     pthread_cond_signal()    — wake one waiting thread
 *     pthread_cond_broadcast() — wake all waiting threads
 *
 *   Atomics (<stdatomic.h>):
 *     atomic_int, atomic_store, atomic_load
 *     atomic_fetch_add, atomic_compare_exchange_strong
 *     Memory ordering: relaxed, acquire, release, acq_rel, seq_cst
 *
 * DATA RACES:
 *   Two threads access same memory, at least one writes, no synchronization.
 *   Data races are UNDEFINED BEHAVIOR. Use -fsanitize=thread to detect.
 *
 * REAL-WORLD ANALOGY:
 *   Threads are like WORKERS in a restaurant kitchen:
 *
 *   pthread_create = "Hire a new worker and assign them a task"
 *   pthread_join   = "Wait for this worker to finish their task"
 *
 *   Mutex = A SINGLE KEY to the walk-in freezer:
 *     Only one worker can hold the key at a time
 *     If the freezer is locked, you wait in line (block)
 *     Forgetting to return the key (unlock) = deadlock!
 *
 *   Condition variable = A BELL SYSTEM:
 *     "When the oven is ready, ring the bell to notify the baker"
 *     The baker sleeps until the bell rings (cond_wait)
 *     Spurious wakeups = "I thought I heard the bell" → always check in a loop
 *
 *   Atomic operations = SELF-CHECKOUT COUNTERS:
 *     Each transaction is indivisible (atomic)
 *     No need for a cashier (mutex) for simple operations
 *     atomic_fetch_add = "Take a number" — guaranteed unique
 *
 *   Data race = Two workers grabbing the same ingredient simultaneously:
 *     Chaos! One might get half of what they need.
 *     Solution: mutex (one at a time) or atomic (indivisible operations)
 * ============================================================================
 */

#define NUM_THREADS 4
#define ITERATIONS 100000

static int unsafe_counter = 0;
static atomic_int safe_counter = 0;
static int mutex_counter = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *unsafe_inc(void *arg) {
    (void)arg;
    for (int i = 0; i < ITERATIONS; i++) unsafe_counter++;  /* DATA RACE! */
    return NULL;
}

static void *safe_inc(void *arg) {
    (void)arg;
    for (int i = 0; i < ITERATIONS; i++) atomic_fetch_add(&safe_counter, 1);
    return NULL;
}

static void *mutex_inc(void *arg) {
    (void)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mtx);
        mutex_counter++;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

static void *compute_sum(void *arg) {
    int n = *(int *)arg;
    long *res = malloc(sizeof(long));
    *res = 0;
    for (int i = 1; i <= n; i++) *res += i;
    return res;
}

static void section_17_concurrency(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 17: CONCURRENCY\n");
    printf("============================================================\n\n");

    pthread_t t[NUM_THREADS];

    /* --- Race condition demo --- */
    printf("  --- Race Condition Demo ---\n");
    unsafe_counter = 0;
    for (int i = 0; i < NUM_THREADS; i++) pthread_create(&t[i], NULL, unsafe_inc, NULL);
    for (int i = 0; i < NUM_THREADS; i++) pthread_join(t[i], NULL);
    printf("  Unsafe counter: %d (expected %d, likely LESS due to race)\n",
           unsafe_counter, NUM_THREADS * ITERATIONS);

    /* --- Atomic --- */
    atomic_store(&safe_counter, 0);
    for (int i = 0; i < NUM_THREADS; i++) pthread_create(&t[i], NULL, safe_inc, NULL);
    for (int i = 0; i < NUM_THREADS; i++) pthread_join(t[i], NULL);
    printf("  Atomic counter: %d (exact: %d)\n",
           atomic_load(&safe_counter), NUM_THREADS * ITERATIONS);

    /* --- Mutex --- */
    mutex_counter = 0;
    for (int i = 0; i < NUM_THREADS; i++) pthread_create(&t[i], NULL, mutex_inc, NULL);
    for (int i = 0; i < NUM_THREADS; i++) pthread_join(t[i], NULL);
    printf("  Mutex counter:  %d (exact: %d)\n",
           mutex_counter, NUM_THREADS * ITERATIONS);

    /* --- Thread return values --- */
    printf("\n  --- Thread Return Values ---\n");
    int n = 1000;
    pthread_t tid;
    pthread_create(&tid, NULL, compute_sum, &n);
    long *result;
    pthread_join(tid, (void **)&result);
    printf("  Sum of 1 to %d = %ld\n", n, *result);
    free(result);

    /* --- Atomic operations --- */
    printf("\n  --- Atomic Operations ---\n");
    atomic_int ac = ATOMIC_VAR_INIT(0);
    atomic_fetch_add(&ac, 10);
    atomic_fetch_sub(&ac, 3);
    printf("  counter: %d\n", atomic_load(&ac));

    int expected = 7;
    _Bool ok = atomic_compare_exchange_strong(&ac, &expected, 100);
    printf("  CAS(7→100): %s, counter=%d\n", ok ? "success" : "failed",
           atomic_load(&ac));

    /* --- Best practices --- */
    printf("\n  --- Concurrency Best Practices ---\n");
    printf("  1. Use atomics for simple counters/flags\n");
    printf("  2. Use mutexes for complex critical sections\n");
    printf("  3. Use condition variables for signaling\n");
    printf("  4. Always check condition in while loop (spurious wakeups)\n");
    printf("  5. Data races are UB — use -fsanitize=thread\n");
    printf("  6. Prefer memory_order_seq_cst unless you have specific needs\n");
}


/* ============================================================================
 *  SECTION 18: SIGNAL HANDLING
 * ============================================================================
 *
 * THEORY:
 * -------
 * Signals are asynchronous notifications to a process.
 *
 * STANDARD SIGNALS:
 *   SIGINT  (2)  — Ctrl+C (interactive attention)
 *   SIGTERM (15) — termination request
 *   SIGSEGV (11) — segmentation fault (invalid memory access)
 *   SIGABRT (6)  — abort() called
 *   SIGFPE  (8)  — arithmetic exception (divide by zero)
 *   SIGILL  (4)  — illegal instruction
 *
 * HANDLING:
 *   signal(sig, handler) — register handler (behavior varies by OS)
 *   raise(sig)           — send signal to self
 *   SIG_DFL              — default handler
 *   SIG_IGN              — ignore signal
 *
 * SIGNAL HANDLER RULES:
 *   1. Only access volatile sig_atomic_t variables
 *   2. Only call async-signal-safe functions (write, _exit, signal)
 *   3. printf is NOT async-signal-safe!
 *   4. POSIX: use sigaction() instead of signal() for reliability
 *
 * REAL-WORLD ANALOGY:
 *   Signals are like INTERRUPTIONS at work:
 *
 *   SIGINT = Someone tapping your shoulder (Ctrl+C)
 *   SIGTERM = Boss saying "wrap up and go home"
 *   SIGSEGV = Walking into a wall (accessing invalid memory)
 *   SIGFPE  = Calculator error (divide by zero)
 *
 *   Signal handler = Your response to the interruption:
 *     "When someone taps my shoulder, save my work and respond"
 *     But you can only do SAFE things in the handler:
 *     - Writing a note (write()) = safe
 *     - Making a phone call (printf()) = NOT safe (might be interrupted itself!)
 *
 *   volatile sig_atomic_t = A sticky note that's always visible:
 *     Even during interruptions, you can read/write this one variable safely
 * ============================================================================
 */

static volatile sig_atomic_t got_signal = 0;
static volatile sig_atomic_t sig_num = 0;

static void signal_handler(int sig) {
    got_signal = 1;
    sig_num = sig;
    /* Only async-signal-safe operations here! */
}

static void section_18_signals(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 18: SIGNAL HANDLING\n");
    printf("============================================================\n\n");

    printf("  Standard signals:\n");
    printf("    SIGINT  (%2d): Ctrl+C\n", SIGINT);
    printf("    SIGTERM (%2d): Termination request\n", SIGTERM);
    printf("    SIGSEGV (%2d): Segmentation fault\n", SIGSEGV);
    printf("    SIGABRT (%2d): Abort\n", SIGABRT);
    printf("    SIGFPE  (%2d): Arithmetic exception\n", SIGFPE);
    printf("    SIGILL  (%2d): Illegal instruction\n", SIGILL);

    /* Install handler and send signal to self */
    signal(SIGINT, signal_handler);
    raise(SIGINT);  /* send SIGINT to self */
    if (got_signal) {
        printf("\n  Caught signal %d via handler\n", sig_num);
        got_signal = 0;
    }
    signal(SIGINT, SIG_DFL);  /* restore default */

    printf("\n  Signal handler rules:\n");
    printf("    1. Only access volatile sig_atomic_t variables\n");
    printf("    2. Only call async-signal-safe functions\n");
    printf("    3. write() is safe, printf() is NOT\n");
    printf("    4. Use sigaction() on POSIX for reliable handling\n");
}


/* ============================================================================
 *  SECTION 19: MATH, TIME, AND RANDOM NUMBERS
 * ============================================================================
 *
 * THEORY:
 * -------
 * <math.h> provides mathematical functions with float/double/long double variants:
 *   Trig: sin, cos, tan, asin, acos, atan, atan2
 *   Hyperbolic: sinh, cosh, tanh, asinh, acosh, atanh
 *   Exponential: exp, exp2, expm1, log, log2, log10, log1p
 *   Power: pow, sqrt, cbrt, hypot
 *   Rounding: ceil, floor, round, trunc
 *   Other: fmod, remainder, fabs, fma, copysign, nextafter
 *
 * <time.h>:
 *   time(NULL)         — current calendar time (epoch seconds)
 *   clock()            — CPU time used
 *   localtime()        — convert to local time struct
 *   strftime()         — format time as string
 *   timespec_get()     — high-resolution time (C11)
 *   difftime()         — difference between two times
 *
 * <stdlib.h> random:
 *   srand(seed)        — seed the PRNG
 *   rand()             — pseudo-random [0, RAND_MAX]
 *   WARNING: rand() is LOW QUALITY. Use better alternatives for real applications.
 *
 * REAL-WORLD ANALOGY:
 *   Math functions are like a SCIENTIFIC CALCULATOR:
 *   - sin/cos/tan = trigonometry for angles and waves
 *   - exp/log = growth and decay (compound interest, radioactive decay)
 *   - sqrt/pow = geometry and scaling
 *   - ceil/floor = rounding up/down (like rounding up to next dollar)
 *
 *   Time functions are like a CLOCK on the wall:
 *   - time() = reading the current time
 *   - clock() = a stopwatch (measures CPU time, not wall time)
 *   - strftime() = formatting the time for display
 *
 *   rand() is like a CHEAP DICE SET:
 *   - Good enough for simple games
 *   - NOT good enough for cryptography or scientific simulation
 *   - For serious randomness: /dev/urandom, arc4random, or proper PRNGs
 * ============================================================================
 */

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static void section_19_math_time_random(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 19: MATH, TIME, RANDOM\n");
    printf("============================================================\n\n");

    /* --- Math --- */
    printf("  --- Math Functions ---\n");
    printf("  sqrt(2)    = %.15f\n", sqrt(2.0));
    printf("  pow(2,10)  = %.0f\n", pow(2.0, 10.0));
    printf("  exp(1)     = %.15f (e)\n", exp(1.0));
    printf("  log(e)     = %.15f\n", log(exp(1.0)));
    printf("  sin(pi/2)  = %.15f\n", sin(M_PI / 2.0));
    printf("  cos(0)     = %.15f\n", cos(0.0));
    printf("  atan2(1,1) = %.15f (pi/4)\n", atan2(1.0, 1.0));
    printf("  ceil(2.3)  = %.0f\n", ceil(2.3));
    printf("  floor(2.7) = %.0f\n", floor(2.7));
    printf("  round(2.5) = %.0f\n", round(2.5));
    printf("  fma(2,3,4) = %.0f (2*3+4)\n", fma(2.0, 3.0, 4.0));
    printf("  hypot(3,4) = %.0f\n", hypot(3.0, 4.0));
    printf("  erf(1)     = %.15f\n", erf(1.0));
    printf("  fabs(-42)  = %.0f\n", fabs(-42.0));

    /* --- Time --- */
    printf("\n  --- Time Functions ---\n");
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    char buf[100];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", local);
    printf("  Current time: %s\n", buf);

    clock_t start = clock();
    volatile double s = 0;
    for (int i = 0; i < 1000000; i++) s += 1.0 / (i + 1);
    clock_t end = clock();
    printf("  CPU time (1M iterations): %.6f sec\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    struct timespec ts;
    if (timespec_get(&ts, TIME_UTC) == TIME_UTC) {
        printf("  High-res: %ld.%09ld sec\n", (long)ts.tv_sec, ts.tv_nsec);
    }

    /* --- Random --- */
    printf("\n  --- Random Numbers ---\n");
    srand((unsigned)time(NULL));
    printf("  RAND_MAX = %d\n", RAND_MAX);
    printf("  Random [1,100]: ");
    for (int i = 0; i < 10; i++) printf("%d ", rand() % 100 + 1);
    printf("\n  Random [0,1):   ");
    for (int i = 0; i < 5; i++) printf("%.4f ", (double)rand() / RAND_MAX);
    printf("\n  WARNING: rand() is low quality. Use /dev/urandom or arc4random\n");
}


/* ============================================================================
 *  SECTION 20: DATA STRUCTURES
 * ============================================================================
 *
 * THEORY:
 * -------
 * C lacks built-in generics, so data structures use:
 *   1. void* (type-erased) — flexible but no type safety
 *   2. Macros (type-safe) — verbose but compiler-checked
 *   3. _Generic (C11) — compile-time dispatch
 *
 * COMMON DATA STRUCTURES:
 *   Linked list — O(1) insert/delete, O(n) search
 *   Stack — LIFO, O(1) push/pop
 *   Queue — FIFO, O(1) enqueue/dequeue
 *   Hash table — O(1) average insert/search/delete
 *   Binary search tree — O(log n) average operations
 *   Heap — O(1) find-min, O(log n) insert/extract
 *
 * REAL-WORLD ANALOGY:
 *   Linked list = A SCAVENGER HUNT:
 *     Each clue (node) tells you where the next clue is
 *     Easy to add/remove clues, but finding the 50th clue requires
 *     following all 49 previous ones
 *
 *   Stack = A STACK OF PLATES:
 *     You can only add/remove from the top (LIFO)
 *     push = place a plate on top, pop = take the top plate
 *
 *   Queue = A CHECKOUT LINE:
 *     First person in line is served first (FIFO)
 *     enqueue = join the back of the line, dequeue = serve the front
 *
 *   Hash table = A FILING SYSTEM WITH TABS:
 *     Each name hashes to a tab number
 *     Look up "Smith" → go directly to tab S → find the record
 *     Collisions = two names with same tab → chain them together
 *
 *   Tree = A COMPANY ORG CHART:
 *     CEO at top, each person has subordinates
 *     Binary search tree: left < parent < right (sorted!)
 *     Balanced tree = equal number of levels on each side
 * ============================================================================
 */

/* --- Linked List (intrusive, Linux kernel style) --- */
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

static inline void list_init(ListNode *head) {
    head->next = head->prev = head;
}

static inline void list_push_back(ListNode *head, ListNode *node) {
    node->prev = head->prev;
    node->next = head;
    head->prev->next = node;
    head->prev = node;
}

static inline void list_remove(ListNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) container_of(ptr, type, member)

typedef struct {
    int id;
    char name[32];
    ListNode node;
} Person;

/* --- Hash Table (separate chaining) --- */
#define HT_SIZE 16

typedef struct HTEntry {
    char *key;
    int value;
    struct HTEntry *next;
} HTEntry;

typedef struct {
    HTEntry *buckets[HT_SIZE];
} HashTable;

static unsigned long hash_fn(const char *s) {
    unsigned long h = 5381;
    int c;
    while ((c = *s++)) h = ((h << 5) + h) + c;
    return h;
}

static void ht_set(HashTable *ht, const char *key, int val) {
    unsigned long idx = hash_fn(key) % HT_SIZE;
    for (HTEntry *e = ht->buckets[idx]; e; e = e->next) {
        if (strcmp(e->key, key) == 0) { e->value = val; return; }
    }
    HTEntry *e = malloc(sizeof(HTEntry));
    e->key = strdup(key);
    e->value = val;
    e->next = ht->buckets[idx];
    ht->buckets[idx] = e;
}

static int ht_get(HashTable *ht, const char *key, int *out) {
    unsigned long idx = hash_fn(key) % HT_SIZE;
    for (HTEntry *e = ht->buckets[idx]; e; e = e->next) {
        if (strcmp(e->key, key) == 0) { *out = e->value; return 1; }
    }
    return 0;
}

static void ht_free(HashTable *ht) {
    for (int i = 0; i < HT_SIZE; i++) {
        HTEntry *e = ht->buckets[i];
        while (e) { HTEntry *n = e->next; free(e->key); free(e); e = n; }
    }
}

/* --- Stack --- */
typedef struct { int *data; size_t len, cap; } Stack;
static Stack stk_new(void) { return (Stack){NULL, 0, 0}; }
static void stk_push(Stack *s, int v) {
    if (s->len >= s->cap) {
        s->cap = s->cap ? s->cap * 2 : 8;
        s->data = realloc(s->data, s->cap * sizeof(int));
    }
    s->data[s->len++] = v;
}
static int stk_pop(Stack *s) { return s->data[--s->len]; }
static int stk_empty(Stack *s) { return s->len == 0; }
static void stk_free(Stack *s) { free(s->data); *s = stk_new(); }

static void section_20_data_structures(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 20: DATA STRUCTURES\n");
    printf("============================================================\n\n");

    /* --- Linked List --- */
    printf("  --- Linked List (Intrusive) ---\n");
    ListNode head;
    list_init(&head);

    Person p1 = {1, "Alice",   {NULL, NULL}};
    Person p2 = {2, "Bob",     {NULL, NULL}};
    Person p3 = {3, "Charlie", {NULL, NULL}};
    list_push_back(&head, &p1.node);
    list_push_back(&head, &p2.node);
    list_push_back(&head, &p3.node);

    ListNode *pos;
    printf("  List: ");
    list_for_each(pos, &head) {
        Person *p = list_entry(pos, Person, node);
        printf("%s(id=%d) → ", p->name, p->id);
    }
    printf("NULL\n");

    list_remove(&p2.node);
    printf("  After removing Bob: ");
    list_for_each(pos, &head) {
        Person *p = list_entry(pos, Person, node);
        printf("%s → ", p->name);
    }
    printf("NULL\n");

    /* --- Hash Table --- */
    printf("\n  --- Hash Table ---\n");
    HashTable ht = {0};
    ht_set(&ht, "Alice", 95);
    ht_set(&ht, "Bob", 87);
    ht_set(&ht, "Charlie", 92);
    ht_set(&ht, "Alice", 98);  /* update */

    const char *keys[] = {"Alice", "Bob", "Charlie", "Diana", NULL};
    for (int i = 0; keys[i]; i++) {
        int val;
        if (ht_get(&ht, keys[i], &val))
            printf("  %s: %d\n", keys[i], val);
        else
            printf("  %s: NOT FOUND\n", keys[i]);
    }
    ht_free(&ht);

    /* --- Stack --- */
    printf("\n  --- Stack (LIFO) ---\n");
    Stack stk = stk_new();
    for (int i = 1; i <= 5; i++) stk_push(&stk, i * 10);
    printf("  Pop order: ");
    while (!stk_empty(&stk)) printf("%d ", stk_pop(&stk));
    printf("\n");
    stk_free(&stk);
}


/* ============================================================================
 *  SECTION 21: UNDEFINED, UNSPECIFIED, AND IMPLEMENTATION-DEFINED BEHAVIOR
 * ============================================================================
 *
 * THEORY:
 * -------
 * UNDEFINED BEHAVIOR (UB):
 *   The standard imposes NO requirements. Anything can happen:
 *   - Program may crash, produce wrong results, or appear to work
 *   - Compiler assumes UB NEVER happens and optimizes accordingly
 *   - Different optimization levels may produce different results
 *
 *   Common UB:
 *     Signed integer overflow          Dereferencing NULL
 *     Array out-of-bounds              Use of uninitialized variable
 *     Modifying string literal         Double free
 *     Use-after-free                   Sequence point violations (i = i++)
 *     Shift by >= bit width            Strict aliasing violation
 *     Division by zero (integer)       Returning address of local
 *
 * UNSPECIFIED BEHAVIOR:
 *   One of several valid behaviors; implementation chooses:
 *     Function argument evaluation order
 *     Order of side effects between sequence points
 *     Value of padding bytes in structs
 *
 * IMPLEMENTATION-DEFINED BEHAVIOR:
 *   Behavior documented by the implementation:
 *     sizeof(int), signedness of char, byte order
 *     Right shift of negative signed integer
 *     Bit-field layout
 *
 * REAL-WORLD ANALOGY:
 *   UB = "What happens if you divide by zero on a physical calculator?"
 *     Some show "Error", some show "Inf", some explode.
 *     The calculator manual says "don't do that" — no guarantees.
 *
 *   Unspecified = "Which cashier will serve you first?"
 *     There are valid options, but you can't predict which one.
 *
 *   Implementation-defined = "What color are the walls?"
 *     The building owner chose a specific color and documented it,
 *     but different buildings may have different colors.
 * ============================================================================
 */

static void section_21_behavior(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 21: UB, UNSPECIFIED, IMPLEMENTATION-DEFINED\n");
    printf("============================================================\n\n");

    printf("  --- Undefined Behavior (NEVER DO THESE) ---\n");
    printf("  1. Signed overflow:     int x = INT_MAX; x++; // UB!\n");
    printf("  2. NULL dereference:    int *p = NULL; *p = 42; // UB!\n");
    printf("  3. Out-of-bounds:       int a[5]; a[10] = 1; // UB!\n");
    printf("  4. Uninitialized:       int x; printf(\"%%d\", x); // UB!\n");
    printf("  5. Modify string lit:   char *s=\"hi\"; s[0]='H'; // UB!\n");
    printf("  6. Double free:         free(p); free(p); // UB!\n");
    printf("  7. Use after free:      free(p); *p = 1; // UB!\n");
    printf("  8. Sequence point:      i = i++ + ++i; // UB!\n");
    printf("  9. Shift overflow:      1 << 32 (if int is 32-bit) // UB!\n");
    printf("  10. Aliasing:           float f; int *p=(int*)&f; // UB!\n");

    /* Safe demo: unsigned wraps correctly */
    unsigned int ui = UINT_MAX;
    ui++;
    printf("\n  Unsigned wrapping (well-defined): UINT_MAX + 1 = %u\n", ui);

    printf("\n  --- Unspecified Behavior ---\n");
    printf("  1. f(g(), h()) — which function runs first? unspecified\n");
    printf("  2. a[i] = i++ — which i is used? unspecified\n");
    printf("  3. Struct padding bytes — value unspecified\n");

    printf("\n  --- Implementation-Defined ---\n");
    printf("  sizeof(int)       = %zu\n", sizeof(int));
    printf("  sizeof(long)      = %zu\n", sizeof(long));
    char c = -1;
    printf("  char signedness   = %s\n", (c < 0) ? "signed" : "unsigned");

    union { uint32_t w; uint8_t b[4]; } e;
    e.w = 1;
    printf("  Byte order        = %s\n",
           (e.b[0] == 1) ? "little-endian" : "big-endian");

    int neg = -16;
    printf("  -16 >> 2          = %d (implementation-defined for signed)\n", neg >> 2);

    printf("\n  --- Safety Compiler Flags ---\n");
    printf("  -Wall -Wextra           General warnings\n");
    printf("  -Wconversion            Narrowing conversions\n");
    printf("  -fsanitize=undefined    Runtime UB detection\n");
    printf("  -fsanitize=address      Memory errors\n");
    printf("  -fsanitize=thread       Data races\n");
    printf("  -fwrapv                 Make signed overflow defined\n");
    printf("  -fno-strict-aliasing    Disable aliasing optimization\n");
}


/* ============================================================================
 *  SECTION 22: PERFORMANCE OPTIMIZATION
 * ============================================================================
 *
 * THEORY:
 * -------
 * COMPILER OPTIMIZATION LEVELS:
 *   -O0 : No optimization (fast compile, debuggable)
 *   -O1 : Basic optimizations
 *   -O2 : Standard optimizations (recommended for production)
 *   -O3 : Aggressive (may increase code size)
 *   -Os : Optimize for size
 *   -Ofast : O3 + -ffast-math (may break IEEE compliance)
 *
 * KEY TECHNIQUES:
 *   restrict     — tells compiler no aliasing → enables vectorization
 *   inline       — suggests function inlining
 *   Cache-friendly layout — sequential access >> strided access
 *   Strength reduction — replace expensive ops with cheaper ones
 *   LTO          — cross-file inlining and optimization
 *   PGO          — optimize based on real execution profiles
 *   SIMD         — process multiple data with single instruction
 *
 * REAL-WORLD ANALOGY:
 *   Optimization is like IMPROVING A FACTORY ASSEMBLY LINE:
 *
 *   -O0 = Prototype line (slow but easy to debug)
 *   -O2 = Production line (optimized for throughput)
 *   -O3 = Maximum speed line (may use more space/materials)
 *
 *   restrict = "These two conveyor belts NEVER share items"
 *     → Allows parallel processing without conflict checks
 *
 *   Cache-friendly = "Organize items by how they're used together"
 *     → Workers don't have to walk across the factory for related items
 *     → Row-major access = walking down a single aisle
 *     → Column-major access = zigzagging across all aisles
 *
 *   Strength reduction = "Use a cheaper tool for a simpler job"
 *     → Instead of multiplying by 2, shift left by 1
 *     → Instead of i*i, add the next odd number
 *
 *   LTO = "Optimize the ENTIRE factory, not just individual stations"
 *   PGO = "Watch how the factory actually runs, then optimize for real usage"
 * ============================================================================
 */

static void section_22_performance(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 22: PERFORMANCE OPTIMIZATION\n");
    printf("============================================================\n\n");

    printf("  --- Compiler Optimization Flags ---\n");
    printf("  -O0   : No optimization (debug)\n");
    printf("  -O1   : Basic optimizations\n");
    printf("  -O2   : Standard (recommended for production)\n");
    printf("  -O3   : Aggressive (may increase code size)\n");
    printf("  -Os   : Optimize for size\n");
    printf("  -Ofast: O3 + fast-math (may break IEEE)\n");
    printf("  -march=native : Optimize for current CPU\n");
    printf("  -flto : Link-Time Optimization\n");
    printf("  -fprofile-generate / -fprofile-use : PGO\n");

    printf("\n  --- Key Optimization Techniques ---\n");
    printf("  1. restrict qualifier: enables auto-vectorization\n");
    printf("     void add(int *restrict d, const int *restrict a,\n");
    printf("              const int *restrict b, int n);\n");
    printf("  2. Cache-friendly access: sequential >> strided\n");
    printf("     Row-major traversal of 2D arrays\n");
    printf("  3. Strength reduction: replace i*i with incremental addition\n");
    printf("  4. Inline small functions: static inline int square(int x)\n");
    printf("  5. Avoid unnecessary allocations in hot loops\n");
    printf("  6. Use __builtin_expect() for branch prediction hints\n");
    printf("  7. SIMD intrinsics: <immintrin.h> for SSE/AVX\n");
    printf("  8. Profile-Guided Optimization for real workloads\n");
    printf("  9. Link-Time Optimization for cross-file inlining\n");
    printf("  10. Measure with clock_gettime(CLOCK_MONOTONIC), not guess!\n");

    /* Demonstrate cache-friendly vs unfriendly */
    printf("\n  --- Cache Access Pattern Demo ---\n");
    #define DIM 1024
    static int mat[DIM][DIM];  /* static to avoid stack overflow */
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            mat[i][j] = 1;

    struct timespec t0, t1;

    /* Row-major (cache-friendly) */
    clock_gettime(CLOCK_MONOTONIC, &t0);
    volatile long sum1 = 0;
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            sum1 += mat[i][j];
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double row_ms = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                    (t1.tv_nsec - t0.tv_nsec) / 1e6;

    /* Column-major (cache-unfriendly) */
    clock_gettime(CLOCK_MONOTONIC, &t0);
    volatile long sum2 = 0;
    for (int j = 0; j < DIM; j++)
        for (int i = 0; i < DIM; i++)
            sum2 += mat[i][j];
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double col_ms = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                    (t1.tv_nsec - t0.tv_nsec) / 1e6;

    printf("  Row-major (sequential):  %.2f ms\n", row_ms);
    printf("  Column-major (strided):  %.2f ms\n", col_ms);
    printf("  Ratio: %.2fx slower for strided access\n",
           row_ms > 0 ? col_ms / row_ms : 0);
    printf("  (Due to CPU cache line fetching — each cache line is %d bytes)\n",
           64);
}


/* ============================================================================
 *  SECTION 23: SECURITY
 * ============================================================================
 *
 * THEORY:
 * -------
 * C's power comes with security responsibilities. Common vulnerabilities:
 *
 *   BUFFER OVERFLOW: Writing past the end of an array
 *     → Stack smashing, heap overflow, return address overwrite
 *     → Prevention: use bounded functions (snprintf, strncpy, fgets)
 *
 *   FORMAT STRING ATTACK: printf(user_input)
 *     → Attacker reads/writes arbitrary memory via %n, %x
 *     → Prevention: printf("%s", user_input)
 *
 *   INTEGER OVERFLOW: size calculation wraps to small value
 *     → malloc(n * size) where n*size overflows → tiny buffer → overflow
 *     → Prevention: check for overflow before multiplication
 *
 *   USE-AFTER-FREE: Accessing freed memory
 *     → Attacker may have reallocated that memory
 *     → Prevention: set pointer to NULL after free
 *
 * REAL-WORLD ANALOGY:
 *   Security is like HOME SAFETY:
 *
 *   Buffer overflow = Leaving your front door wide open
 *     → Anyone can walk in and rearrange your furniture (overwrite memory)
 *     → Lock the door: use bounded functions
 *
 *   Format string = Letting a stranger write your address labels
 *     → They could write anything, including their own address (%n writes)
 *     → Always use format specifiers: printf("%s", user_input)
 *
 *   Integer overflow = Ordering -1 items (wraps to 4 billion)
 *     → The warehouse allocates space for 4 billion items → crash
 *     → Check math before allocating
 *
 *   CERT C and MISRA C are safety standards that define rules to prevent these.
 * ============================================================================
 */

static void section_23_security(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 23: SECURITY\n");
    printf("============================================================\n\n");

    /* Safe string copy */
    printf("  --- Safe String Operations ---\n");
    char dest[20];
    const char *src = "This is a very long string that won't fit";
    /* Unsafe: strcpy(dest, src); → BUFFER OVERFLOW */
    /* Safe: */
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
    printf("  Safe copy: \"%s\" (truncated)\n", dest);

    /* Safe formatting */
    char buf[50];
    snprintf(buf, sizeof(buf), "Hello, %s!", "World");
    printf("  Safe format: \"%s\"\n", buf);

    /* Integer overflow check */
    printf("\n  --- Integer Overflow Check ---\n");
    size_t nmemb = SIZE_MAX / 2;
    size_t size = 3;
    if (nmemb > 0 && size > SIZE_MAX / nmemb) {
        printf("  Overflow detected! nmemb * size would wrap\n");
    } else {
        printf("  Safe to allocate\n");
    }

    /* Format string safety */
    printf("\n  --- Format String Safety ---\n");
    char *user_input = "Hello %s %s %n";  /* malicious */
    /* printf(user_input);  // DANGEROUS! */
    printf("  Safe: printf(\"%%s\", user_input) → \"%s\"\n", user_input);

    /* Security checklist */
    printf("\n  --- Security Checklist ---\n");
    printf("  [x] snprintf instead of sprintf\n");
    printf("  [x] fgets instead of gets (removed in C11)\n");
    printf("  [x] Check malloc/calloc/realloc return values\n");
    printf("  [x] Validate all external input\n");
    printf("  [x] Never use user input as printf format string\n");
    printf("  [x] Check integer overflow before size calculations\n");
    printf("  [x] Zero sensitive data with volatile before free\n");
    printf("  [x] Compile with -Wall -Wextra -Wformat-security\n");
    printf("  [x] Use -fsanitize=address,undefined in testing\n");
    printf("  [x] Follow CERT C or MISRA C coding standards\n");
    printf("  [x] Use static analysis: cppcheck, clang-tidy, Coverity\n");
    printf("  [x] Enable -fstack-protector-strong\n");
    printf("  [x] Enable -D_FORTIFY_SOURCE=2\n");
}


/* ============================================================================
 *  SECTION 24: EMBEDDED C & SYSTEMS PROGRAMMING
 * ============================================================================
 *
 * THEORY:
 * -------
 * Embedded C involves direct hardware interaction:
 *
 *   VOLATILE: Tells compiler "this may change at any time"
 *     → Used for hardware registers, memory-mapped I/O
 *     → Prevents compiler from optimizing away reads/writes
 *
 *   MEMORY-MAPPED I/O: Hardware registers appear as memory addresses
 *     → Write to address 0x40001000 = write to UART control register
 *
 *   INTERRUPTS: Asynchronous events from hardware
 *     → ISR (Interrupt Service Routine) handles the event
 *     → Must be fast, use volatile for shared data
 *
 *   LINKER SCRIPTS: Define memory layout
 *     → .text (code in flash), .data (initialized RAM), .bss (zeroed RAM)
 *
 *   CROSS-COMPILATION: Compile for different architecture
 *     → arm-none-eabi-gcc for ARM Cortex-M
 *     → -mcpu=cortex-m4 -mthumb for specific ARM target
 *
 * REAL-WORLD ANALOGY:
 *   Embedded programming is like OPERATING A MACHINE DIRECTLY:
 *
 *   volatile = "This gauge can change at any moment"
 *     → You must read it fresh each time, can't rely on a cached reading
 *
 *   Memory-mapped I/O = "Control panel buttons mapped to specific addresses"
 *     → Press button at address 0x4000 = turn on motor
 *     → Read gauge at address 0x4004 = check temperature
 *
 *   Interrupt = "An alarm that goes off when something happens"
 *     → Temperature too high → alarm rings → ISR runs → turn on fan
 *     → Must respond quickly (keep ISR short!)
 *
 *   Linker script = "Blueprint showing where everything goes in the building"
 *     → Code goes in the vault (flash/ROM)
 *     → Variables go on the workbench (RAM)
 *     → Uninitialized variables go in the empty shelf (.bss)
 * ============================================================================
 */

/* Simulated hardware registers */
typedef struct {
    volatile uint32_t CR;    /* Control register */
    volatile uint32_t SR;    /* Status register */
    volatile uint32_t DR;    /* Data register */
} UART_TypeDef;

static uint32_t sim_regs[3];
#define SIM_UART ((UART_TypeDef *)sim_regs)

#define BIT(n) (1U << (n))
#define SET_BIT(r, b) ((r) |= (b))
#define CLR_BIT(r, b) ((r) &= ~(b))
#define TST_BIT(r, b) ((r) & (b))

static void section_24_embedded(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 24: EMBEDDED C & SYSTEMS PROGRAMMING\n");
    printf("============================================================\n\n");

    /* --- Memory-mapped I/O --- */
    printf("  --- Memory-Mapped I/O ---\n");
    sim_regs[1] = BIT(0) | BIT(1);  /* SR: TX empty, RX not empty */
    SIM_UART->CR = BIT(0) | BIT(1); /* Enable UART + TX */
    printf("  UART CR = 0x%08X (EN=%d, TX=%d)\n",
           SIM_UART->CR, TST_BIT(SIM_UART->CR, BIT(0)),
           TST_BIT(SIM_UART->CR, BIT(1)));
    printf("  UART SR = 0x%08X (TXE=%d, RXNE=%d)\n",
           SIM_UART->SR, TST_BIT(SIM_UART->SR, BIT(0)),
           TST_BIT(SIM_UART->SR, BIT(1)));

    /* --- Register bit manipulation --- */
    printf("\n  --- Register Bit Manipulation ---\n");
    uint32_t reg = 0;
    SET_BIT(reg, BIT(3) | BIT(7));
    printf("  Set 3,7:     0x%08X\n", reg);
    CLR_BIT(reg, BIT(3));
    printf("  Clear 3:     0x%08X\n", reg);
    printf("  Test 7:      %s\n", TST_BIT(reg, BIT(7)) ? "set" : "clear");

    /* --- Endianness for protocols --- */
    printf("\n  --- Protocol Endianness ---\n");
    uint16_t val = 0x1234;
    uint16_t be = (val >> 8) | (val << 8);
    printf("  Host 0x%04X → Big-endian 0x%04X\n", val, be);

    /* --- Embedded best practices --- */
    printf("\n  --- Embedded Best Practices ---\n");
    printf("  1. volatile for ALL hardware register accesses\n");
    printf("  2. Use uint32_t, int16_t (exact-width types)\n");
    printf("  3. Keep ISRs short — set flags, defer to main loop\n");
    printf("  4. Critical sections for ISR/main shared data\n");
    printf("  5. Initialize all variables (no OS to zero .bss for you)\n");
    printf("  6. Use linker scripts for memory layout\n");
    printf("  7. Watchdog timer: feed periodically or device resets\n");
    printf("  8. Cross-compile: arm-none-eabi-gcc -mcpu=cortex-m4\n");
}


/* ============================================================================
 *  SECTION 25: C23 NEW FEATURES
 * ============================================================================
 *
 * THEORY:
 * -------
 * C23 (ISO/IEC 9899:2024) is the latest standard. Key additions:
 *
 *   NEW KEYWORDS: bool, true, false, nullptr, nullptr_t, constexpr,
 *                 typeof, typeof_unqual, alignas, alignof, static_assert,
 *                 thread_local, _BitInt
 *
 *   auto TYPE INFERENCE: auto x = 42; (type deduced from initializer)
 *
 *   nullptr: Type-safe null pointer constant (nullptr_t, not int)
 *
 *   _BitInt(N): Arbitrary-width integers (e.g., _BitInt(128))
 *
 *   #embed: Binary resource inclusion
 *   #elifdef / #elifndef: Shorthand for conditional compilation
 *   #warning: Standardized warning directive
 *
 *   ATTRIBUTES: [[nodiscard]], [[maybe_unused]], [[noreturn]],
 *               [[deprecated]], [[fallthrough]], [[reproducible]],
 *               [[unsequenced]]
 *
 *   DIGIT SEPARATORS: 1'000'000
 *   BINARY LITERALS: 0b101010
 *   EMPTY INITIALIZERS: int x = {};
 *
 *   REMOVED: Trigraphs, K&R function definitions, implicit int
 *
 *   NEW LIBRARY: <stdbit.h>, <stdckdint.h>, memset_explicit(),
 *                strdup(), strndup(), unreachable()
 *
 * REAL-WORLD ANALOGY:
 *   C23 is like a MAJOR RENOVATION of the C language building:
 *
 *   - bool/true/false = Finally getting proper light switches
 *     (instead of using 0 and 1 as makeshift on/off)
 *
 *   - nullptr = A proper "empty envelope" instead of using "the number 0"
 *     (clearer intent, type-safe)
 *
 *   - #embed = A built-in photocopier for binary files
 *     (instead of converting to C arrays manually)
 *
 *   - Attributes = Standardized sticky notes for the compiler
 *     [[nodiscard]] = "DON'T THROW THIS RETURN VALUE AWAY!"
 *     [[fallthrough]] = "I MEANT to fall through here"
 *
 *   - Digit separators = Putting commas in large numbers
 *     1'000'000 is much easier to read than 1000000
 * ============================================================================
 */

static void section_25_c23(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 25: C23 NEW FEATURES\n");
    printf("============================================================\n\n");

    /* --- Binary literals and digit separators --- */
    printf("  --- Binary Literals & Digit Separators ---\n");
    int bin = 0b10101010;
    int mil = 1'000'000;
    int hex_sep = 0xFF'FF'FF;
    printf("  0b10101010 = %d (0x%X)\n", bin, bin);
    printf("  1'000'000  = %d\n", mil);
    printf("  0xFF'FF'FF = 0x%X\n", hex_sep);

    /* --- Native bool (no <stdbool.h> needed in C23) --- */
    printf("\n  --- Native bool ---\n");
    /* bool flag = true;  -- C23 keyword */
    /* bool other = false; */
    printf("  C23: bool, true, false are keywords (not macros)\n");
    printf("  sizeof(bool) = %zu\n", sizeof(bool));

    /* --- nullptr --- */
    printf("\n  --- nullptr ---\n");
    /* int *p = nullptr;  -- C23 */
    printf("  nullptr has type nullptr_t (not int like NULL)\n");
    printf("  Type-safe: can't accidentally use as integer\n");

    /* --- _BitInt --- */
    printf("\n  --- _BitInt(N) ---\n");
    /* _BitInt(128) wide = ...; */
    printf("  _BitInt(N) provides arbitrary-width integers\n");
    printf("  e.g., _BitInt(3) is a 3-bit signed integer\n");

    /* --- typeof --- */
    printf("\n  --- typeof / typeof_unqual ---\n");
    int x = 42;
    /* typeof(x) y = 100;  -- y has same type as x */
    /* typeof_unqual(const int) strips const qualifier */
    printf("  typeof(x) y = 100; → y is int (same as x)\n");
    printf("  typeof_unqual(const int) → int (const stripped)\n");

    /* --- Attributes --- */
    printf("\n  --- Attributes ---\n");
    printf("  [[nodiscard]]    — warn if return value ignored\n");
    printf("  [[maybe_unused]] — suppress unused warning\n");
    printf("  [[noreturn]]     — function never returns\n");
    printf("  [[deprecated]]   — mark as deprecated\n");
    printf("  [[fallthrough]]  — intentional switch fall-through\n");
    printf("  [[reproducible]] — same inputs → same outputs\n");
    printf("  [[unsequenced]]  — no side effects, no dependencies\n");

    /* --- #embed --- */
    printf("\n  --- #embed ---\n");
    printf("  #embed \"file.dat\" includes binary data as initializer\n");
    printf("  Parameters: limit(N), prefix(...), suffix(...), if_empty(...)\n");

    /* --- New library features --- */
    printf("\n  --- New Library Features ---\n");
    printf("  <stdbit.h>:     popcount, leading_zeros, bit_width, bit_ceil\n");
    printf("  <stdckdint.h>:  ckd_add(), ckd_sub(), ckd_mul() (overflow-checked)\n");
    printf("  memset_explicit(): guaranteed zeroing (not optimized away)\n");
    printf("  unreachable():    undefined behavior hint for optimizer\n");
    printf("  strdup/strndup(): now standardized (was POSIX-only)\n");

    /* --- Removed features --- */
    printf("\n  --- Removed in C23 ---\n");
    printf("  Trigraphs, K&R function definitions, implicit int\n");
    printf("  register keyword (reserved but does nothing)\n");
    printf("  gets() (removed in C11, gone in C23)\n");
}


/* ============================================================================
 *  SECTION 26: FILE ORGANIZATION & LIBRARIES
 * ============================================================================
 *
 * THEORY:
 * -------
 * A C project is organized into TRANSLATION UNITS (source files):
 *
 *   HEADER FILES (.h):
 *     - Declarations (function prototypes, type definitions, macros)
 *     - Include guards (#ifndef X / #define X / #endif)
 *     - Should be self-contained (include their own dependencies)
 *     - What belongs: declarations, typedefs, macros, inline functions
 *     - What does NOT belong: definitions with external linkage
 *
 *   SOURCE FILES (.c):
 *     - Definitions (function bodies, variable definitions)
 *     - Each .c compiles independently into an object file (.o)
 *     - Use static for file-internal functions and variables
 *
 *   LIBRARIES:
 *     Static (.a / .lib): Object files archived together, linked at compile time
 *     Shared (.so / .dll / .dylib): Loaded at runtime, shared between programs
 *
 *   BUILD PROCESS:
 *     .c → [compiler] → .o → [linker] → executable
 *     Multiple .c files: each compiles separately, then linked together
 *
 * REAL-WORLD ANALOGY:
 *   File organization is like a COMPANY STRUCTURE:
 *
 *   Header file (.h) = COMPANY DIRECTORY:
 *     Lists who does what (function declarations)
 *     Lists what data structures look like (type definitions)
 *     Shared with everyone who needs to interact with the department
 *     Include guards = "This directory has been verified, don't re-verify"
 *
 *   Source file (.c) = DEPARTMENT INTERNALS:
 *     The actual implementation of how each person does their job
 *     Private helpers (static) = internal department procedures
 *     Only the department head (linker) sees all departments together
 *
 *   Static library (.a) = BOUND EMPLOYEE HANDBOOK:
 *     All procedures compiled and archived into one book
 *     Linked directly into your program at compile time
 *
 *   Shared library (.so) = OUTSOURCED CONTRACTOR:
 *     Loaded when needed at runtime
 *     Multiple programs can share the same contractor
 *     Can be updated without recompiling the main program
 * ============================================================================
 */

static void section_26_file_organization(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 26: FILE ORGANIZATION & LIBRARIES\n");
    printf("============================================================\n\n");

    printf("  --- Header File (.h) Best Practices ---\n");
    printf("  1. Include guards:\n");
    printf("     #ifndef MY_HEADER_H\n");
    printf("     #define MY_HEADER_H\n");
    printf("     /* ... declarations ... */\n");
    printf("     #endif /* MY_HEADER_H */\n\n");
    printf("  2. Or use #pragma once (non-standard but widely supported)\n\n");
    printf("  3. What belongs in headers:\n");
    printf("     - Function prototypes\n");
    printf("     - Type definitions (typedef, struct, enum)\n");
    printf("     - Macro definitions\n");
    printf("     - static inline function definitions\n");
    printf("     - extern variable declarations\n\n");
    printf("  4. What does NOT belong:\n");
    printf("     - Function definitions (except static inline)\n");
    printf("     - Variable definitions (use extern in header, define in .c)\n");
    printf("     - #include of implementation-specific headers\n\n");

    printf("  --- Source File (.c) Best Practices ---\n");
    printf("  1. Include corresponding .h file first\n");
    printf("  2. Use static for file-internal functions and variables\n");
    printf("  3. One definition per translation unit\n\n");

    printf("  --- Build Commands ---\n");
    printf("  Compile to object:  gcc -c file.c -o file.o\n");
    printf("  Link objects:       gcc main.o utils.o -o program\n");
    printf("  Static library:     ar rcs libutil.a utils.o\n");
    printf("  Link static:        gcc main.o -L. -lutil -o program\n");
    printf("  Shared library:     gcc -shared -fPIC utils.c -o libutil.so\n");
    printf("  Link shared:        gcc main.o -L. -lutil -o program\n");
    printf("  Run with shared:    LD_LIBRARY_PATH=. ./program\n\n");

    printf("  --- Opaque Pointer Pattern (Encapsulation) ---\n");
    printf("  /* In header: */\n");
    printf("  typedef struct Vector Vector;  /* forward declaration */\n");
    printf("  Vector *vec_create(void);\n");
    printf("  void vec_push(Vector *v, int x);\n");
    printf("  void vec_destroy(Vector *v);\n\n");
    printf("  /* In source: */\n");
    printf("  struct Vector { int *data; size_t len, cap; };\n");
    printf("  /* Users can't access internals — true encapsulation */\n");
}


/* ============================================================================
 *  SECTION 27: INTERFACING C WITH OTHER LANGUAGES
 * ============================================================================
 *
 * THEORY:
 * -------
 * C is the LINGUA FRANCA of programming. Its ABI defines:
 *   - Calling conventions (how arguments are passed)
 *   - Name mangling (C has NONE — function names are preserved)
 *   - Struct layout (padding, alignment)
 *   - Return value conventions
 *
 * FFI (Foreign Function Interface) from other languages:
 *   Python:  ctypes, cffi, SWIG
 *   Rust:    extern "C" + #[repr(C)]
 *   C++:     extern "C" { ... }
 *   Java:    JNI (Java Native Interface)
 *   Go:      cgo
 *   C#:      P/Invoke
 *   Lua:     Lua C API
 *
 * BEST PRACTICES FOR CROSS-LANGUAGE APIs:
 *   1. Use standard integer types (int32_t, uint64_t)
 *   2. Use #pragma pack or __attribute__((packed)) for consistent layout
 *   3. Use opaque handles (void* or forward-declared struct*) for encapsulation
 *   4. Document ownership rules for pointers
 *   5. Return error codes, not complex structures
 *   6. Avoid variadic functions across FFI boundaries
 *   7. Use simple function signatures
 *
 * REAL-WORLD ANALOGY:
 *   C interop is like INTERNATIONAL TRADE:
 *
 *   C ABI = The standard shipping container size
 *     → Every country (language) agrees on the container format
 *     → Goods (data) can be shipped between any two countries
 *
 *   extern "C" = "Use the international standard, not local customs"
 *     → C++ normally mangles names (adds type info) — extern "C" stops that
 *     → Rust normally uses its own ABI — extern "C" uses the standard
 *
 *   Opaque handle = A numbered ticket at a coat check
 *     → You don't see the coat (internal struct), just the ticket number (void*)
 *     → Give the ticket to get your coat back (call a function with the handle)
 * ============================================================================
 */

/* Functions callable from any language with C FFI */
int ffi_add(int a, int b) { return a + b; }

double ffi_average(const double *values, int count) {
    if (!values || count <= 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < count; i++) sum += values[i];
    return sum / count;
}

char *ffi_greet(const char *name) {
    if (!name) return NULL;
    size_t len = strlen("Hello, ") + strlen(name) + 2;
    char *result = malloc(len);
    if (result) snprintf(result, len, "Hello, %s!", name);
    return result;
}

/* Opaque handle pattern */
typedef struct { int x, y, z; char name[32]; } InternalObj;
typedef InternalObj *OpaqueHandle;

OpaqueHandle obj_create(const char *name, int x, int y, int z) {
    InternalObj *o = malloc(sizeof(InternalObj));
    if (!o) return NULL;
    o->x = x; o->y = y; o->z = z;
    strncpy(o->name, name, sizeof(o->name) - 1);
    o->name[sizeof(o->name) - 1] = '\0';
    return o;
}
void obj_destroy(OpaqueHandle h) { free(h); }
int obj_get_x(OpaqueHandle h) { return h ? h->x : 0; }

static void section_27_interop(void) {
    printf("\n");
    printf("============================================================\n");
    printf("  SECTION 27: INTERFACING C WITH OTHER LANGUAGES\n");
    printf("============================================================\n\n");

    printf("  --- Simple FFI Functions ---\n");
    printf("  ffi_add(3, 4) = %d\n", ffi_add(3, 4));

    double vals[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    printf("  ffi_average = %.2f\n", ffi_average(vals, 5));

    char *greeting = ffi_greet("World");
    printf("  ffi_greet = \"%s\"\n", greeting);
    free(greeting);

    printf("\n  --- Opaque Handle Pattern ---\n");
    OpaqueHandle obj = obj_create("Test", 10, 20, 30);
    printf("  obj_get_x = %d\n", obj_get_x(obj));
    obj_destroy(obj);

    printf("\n  --- Language-Specific FFI ---\n");
    printf("  Python:  ctypes.cdll.LoadLibrary(\"./lib.so\")\n");
    printf("  Rust:    extern \"C\" { fn ffi_add(a: i32, b: i32) -> i32; }\n");
    printf("  C++:     extern \"C\" { int ffi_add(int a, int b); }\n");
    printf("  Java:    JNI: native int ffi_add(int a, int b);\n");
    printf("  Go:      // #include \"header.h\" import \"C\"\n");
    printf("  C#:      [DllImport(\"lib\")] static extern int ffi_add(int a, int b);\n");

    printf("\n  --- FFI Best Practices ---\n");
    printf("  1. Use C linkage (no name mangling)\n");
    printf("  2. Standard integer types (int32_t, uint64_t)\n");
    printf("  3. Opaque handles for encapsulation\n");
    printf("  4. Document pointer ownership\n");
    printf("  5. Return error codes, not complex structures\n");
    printf("  6. Avoid variadic functions across FFI\n");
    printf("  7. Use #pragma pack for consistent struct layout\n");
}


/* ============================================================================
 *  MAIN — RUN ALL SECTIONS
 * ============================================================================
 */

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║  THE DEFINITIVE C PROGRAMMING LANGUAGE — COMPLETE GUIDE    ║\n");
    printf("║  Every topic, every concept, with theory and code          ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");

    section_01_program_structure();
    section_02_lexical_elements();
    section_03_data_types();
    section_04_operators();
    section_05_control_flow();
    section_06_arrays();
    section_07_pointers();
    section_08_functions();
    section_09_structs_unions_enums();
    section_10_dynamic_memory();
    section_11_strings();
    section_12_preprocessor();
    section_13_io();
    section_14_type_conversions();
    section_15_scope_linkage();
    section_16_error_handling();
    section_17_concurrency();
    section_18_signals();
    section_19_math_time_random();
    section_20_data_structures();
    section_21_behavior();
    section_22_performance();
    section_23_security();
    section_24_embedded();
    section_25_c23();
    section_26_file_organization();
    section_27_interop();

    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║  ALL 27 SECTIONS COMPLETE                                  ║\n");
    printf("║  Topics covered:                                           ║\n");
    printf("║    1.  Program Structure & Compilation                     ║\n");
    printf("║    2.  Lexical Elements (Tokens, Keywords, Constants)      ║\n");
    printf("║    3.  Data Types (Integers, Floats, Complex, Limits)      ║\n");
    printf("║    4.  Operators (Arithmetic, Bitwise, Logical, Precedence)║\n");
    printf("║    5.  Control Flow (if, switch, for, while, goto)         ║\n");
    printf("║    6.  Arrays (1D, 2D, VLA, Designated Init)              ║\n");
    printf("║    7.  Pointers (Arithmetic, Const, Double, Function Ptrs) ║\n");
    printf("║    8.  Functions (Variadic, Inline, Recursion, Callbacks)  ║\n");
    printf("║    9.  Structs, Unions, Enums (Bit-fields, Tagged Union)   ║\n");
    printf("║    10. Dynamic Memory (malloc, calloc, realloc, free)      ║\n");
    printf("║    11. Strings (Safe Ops, Search, Tokenize, Memory Funcs)  ║\n");
    printf("║    12. Preprocessor (Macros, Conditional, X-Macros)        ║\n");
    printf("║    13. I/O (printf, File, Binary, sscanf, Positioning)     ║\n");
    printf("║    14. Type Conversions (Implicit, Explicit, _Generic)     ║\n");
    printf("║    15. Scope, Linkage, Storage Duration                    ║\n");
    printf("║    16. Error Handling (errno, setjmp, assert, Cleanup)     ║\n");
    printf("║    17. Concurrency (Threads, Mutex, Atomics, Race Cond)   ║\n");
    printf("║    18. Signal Handling (Signals, Handlers, Safety)         ║\n");
    printf("║    19. Math, Time, Random Numbers                          ║\n");
    printf("║    20. Data Structures (List, Hash Table, Stack)           ║\n");
    printf("║    21. UB, Unspecified, Implementation-Defined Behavior    ║\n");
    printf("║    22. Performance Optimization (Cache, restrict, LTO)     ║\n");
    printf("║    23. Security (Buffer Overflow, Format String, CERT C)   ║\n");
    printf("║    24. Embedded C (Volatile, MMIO, Interrupts, Linker)     ║\n");
    printf("║    25. C23 New Features (bool, nullptr, typeof, #embed)    ║\n");
    printf("║    26. File Organization & Libraries                       ║\n");
    printf("║    27. Interfacing C with Other Languages                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");

    return 0;
}