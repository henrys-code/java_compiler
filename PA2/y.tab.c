/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 11 "parser.y" /* yacc.c:339  */


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "lexer.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine


#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Void = 258,
    T_Bool = 259,
    T_Int = 260,
    T_LessEqual = 261,
    T_GreaterEqual = 262,
    T_EQ = 263,
    T_NE = 264,
    T_LeftAngle = 265,
    T_RightAngle = 266,
    T_And = 267,
    T_Or = 268,
    T_Equal = 269,
    T_MulAssign = 270,
    T_DivAssign = 271,
    T_AddAssign = 272,
    T_SubAssign = 273,
    T_While = 274,
    T_For = 275,
    T_If = 276,
    T_Else = 277,
    T_Return = 278,
    T_Break = 279,
    T_Continue = 280,
    T_Inc = 281,
    T_Dec = 282,
    T_Semicolon = 283,
    T_Comma = 284,
    T_Dash = 285,
    T_Plus = 286,
    T_Star = 287,
    T_Slash = 288,
    T_LeftParen = 289,
    T_RightParen = 290,
    T_LeftBracket = 291,
    T_RightBracket = 292,
    T_LeftBrace = 293,
    T_RightBrace = 294,
    T_Public = 295,
    T_Private = 296,
    T_Static = 297,
    T_Class = 298,
    T_Identifier = 299,
    T_IntConstant = 300,
    T_BoolConstant = 301,
    LOWEST = 302,
    LOWER_THAN_ELSE = 303
  };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_LessEqual 261
#define T_GreaterEqual 262
#define T_EQ 263
#define T_NE 264
#define T_LeftAngle 265
#define T_RightAngle 266
#define T_And 267
#define T_Or 268
#define T_Equal 269
#define T_MulAssign 270
#define T_DivAssign 271
#define T_AddAssign 272
#define T_SubAssign 273
#define T_While 274
#define T_For 275
#define T_If 276
#define T_Else 277
#define T_Return 278
#define T_Break 279
#define T_Continue 280
#define T_Inc 281
#define T_Dec 282
#define T_Semicolon 283
#define T_Comma 284
#define T_Dash 285
#define T_Plus 286
#define T_Star 287
#define T_Slash 288
#define T_LeftParen 289
#define T_RightParen 290
#define T_LeftBracket 291
#define T_RightBracket 292
#define T_LeftBrace 293
#define T_RightBrace 294
#define T_Public 295
#define T_Private 296
#define T_Static 297
#define T_Class 298
#define T_Identifier 299
#define T_IntConstant 300
#define T_BoolConstant 301
#define LOWEST 302
#define LOWER_THAN_ELSE 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

    int integerConstant;
    bool boolConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null






#line 229 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   120,   121,   124,   125,   128,   129,   132,
     133,   134,   137,   138,   141,   144,   145,   148,   149,   152,
     155,   156,   159,   160,   163,   164,   165,   166,   167,   168,
     171,   172,   175,   176,   179,   180,   183,   184,   187,   190,
     193,   196,   199,   202,   205,   206,   207,   208,   209,   210,
     213,   216,   217,   218,   219,   220,   223,   224,   225,   226,
     229,   230,   231,   232,   235,   236,   239,   240,   243,   244,
     245,   246,   249,   250,   253,   254,   257,   260,   261,   262,
     263,   266,   269,   270,   271,   274,   275,   276,   277,   278,
     281,   282
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int",
  "T_LessEqual", "T_GreaterEqual", "T_EQ", "T_NE", "T_LeftAngle",
  "T_RightAngle", "T_And", "T_Or", "T_Equal", "T_MulAssign", "T_DivAssign",
  "T_AddAssign", "T_SubAssign", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_Continue", "T_Inc", "T_Dec", "T_Semicolon",
  "T_Comma", "T_Dash", "T_Plus", "T_Star", "T_Slash", "T_LeftParen",
  "T_RightParen", "T_LeftBracket", "T_RightBracket", "T_LeftBrace",
  "T_RightBrace", "T_Public", "T_Private", "T_Static", "T_Class",
  "T_Identifier", "T_IntConstant", "T_BoolConstant", "LOWEST",
  "LOWER_THAN_ELSE", "$accept", "Program", "DeclList", "Decl",
  "single_declaration", "type_specifier", "function_definition",
  "function_prototype", "function_prototype_header",
  "parameter_declaration_list", "paramater_declaraion",
  "compound_statement_with_scope", "statement_list", "statement",
  "simple_statement", "expression_statement", "selection_statement",
  "iteration_statement", "while_statement", "for_statement", "condition",
  "return_statement", "decl_statement", "break_statement", "expression",
  "assignment_expression", "assignment_operator", "arithmetic_expression",
  "relational_expression", "equality_expression", "logical_expression",
  "postfix_expression", "func_call_expression",
  "function_call_header_no_parameters",
  "function_call_header_with_parameters", "arg_list", "function_identfier",
  "primary_expression", "unary_expression", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -82

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      97,  -101,  -101,  -101,     6,    97,  -101,  -101,    -3,  -101,
     -19,     7,  -101,  -101,   340,  -101,    92,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,    97,   307,     4,    11,    12,
     301,    22,   307,   307,  -101,   307,   307,   307,  -101,    14,
    -101,  -101,  -101,    16,  -101,   124,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,   243,  -101,  -101,  -101,
    -101,  -101,    -5,  -101,    26,    35,    41,  -101,    69,  -101,
      32,    49,  -101,   251,   307,   301,   307,  -101,  -101,  -101,
    -101,  -101,  -101,   197,    89,  -101,  -101,   307,   307,   307,
     307,   307,   307,   307,   307,  -101,   307,   307,   307,   307,
    -101,  -101,  -101,  -101,    13,   307,  -101,    97,  -101,    44,
     279,   301,   205,  -101,    61,    61,   293,   293,    61,    61,
     287,    23,    -6,    -6,  -101,  -101,  -101,  -101,    52,   -12,
      69,   279,  -101,   156,   307,    51,   307,  -101,   213,    76,
    -101,   -11,   156,    51,  -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    11,    10,     0,     2,     4,     5,     0,     6,
       0,     0,     1,     3,     0,    13,     0,    12,    14,    51,
      52,    53,    54,    55,     7,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,    21,    82,
      90,    91,    42,     0,    24,     0,    23,    25,    30,    31,
      26,    36,    37,    27,    28,    29,     0,    44,    45,    46,
      47,    48,    85,    71,     0,     0,     0,    68,    49,    83,
       0,    16,    18,     0,     0,     0,     0,    41,    43,    86,
      87,    89,    88,     0,     0,    20,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
      69,    70,    73,    72,    75,     0,    19,     0,     8,     0,
      40,     0,     0,    84,    62,    63,    64,    65,    60,    61,
      66,    67,    57,    56,    58,    59,    74,    77,    76,    68,
       0,    50,    17,     0,     0,     0,     0,    38,     0,    34,
      78,    68,     0,     0,    39,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,  -101,   103,    20,     3,  -101,  -101,  -101,  -101,
      17,   -10,  -101,   -43,  -101,   -23,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,   -25,  -100,   -53,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,   -99,   -22,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    42,    43,     9,    10,    11,    71,
      72,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     109,    53,    54,    55,    56,    57,    26,    58,    59,    60,
      61,    62,    63,    64,    65,   128,    66,    67,    68,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    73,    86,     8,   127,   129,    12,    77,     8,    15,
      79,    80,    83,    81,    82,   105,   126,   -79,   -80,    16,
       7,   100,   101,   -79,   -80,     7,    98,    99,    70,    87,
      88,    89,    90,    91,    92,    93,   140,   141,    74,    32,
      33,    14,    18,    35,    36,    75,    76,    37,   -81,   110,
      78,   112,   111,    96,    97,    98,    99,    39,    40,    41,
      84,   102,   114,   115,   116,   117,   118,   119,   120,   121,
     103,   122,   123,   124,   125,   104,   106,   105,   107,   133,
     131,   136,   130,    19,    20,    21,    22,    23,   134,    16,
     137,    96,    97,    98,    99,     1,     2,     3,   143,   144,
       1,     2,     3,    19,    20,    21,    22,    23,    13,   138,
      70,    27,    28,    29,   130,    30,    31,    24,    32,    33,
      34,     0,    35,    36,   132,   139,    37,     1,     2,     3,
      16,    38,     0,   145,     0,     0,    39,    40,    41,     0,
       0,     0,     0,    27,    28,    29,     0,    30,    31,     0,
      32,    33,    34,     0,    35,    36,     0,     0,    37,     1,
       2,     3,    16,    85,     0,     0,     0,     0,    39,    40,
      41,     0,     0,     0,     0,    27,    28,    29,     0,    30,
      31,     0,    32,    33,    34,     0,    35,    36,     0,     0,
      37,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      39,    40,    41,    87,    88,    89,    90,    91,    92,    93,
      94,    87,    88,    89,    90,    91,    92,    93,    94,    87,
      88,    89,    90,    91,    92,    93,    94,    96,    97,    98,
      99,     0,   113,     0,     0,    96,    97,    98,    99,     0,
     135,     0,     0,    96,    97,    98,    99,     0,   142,    87,
      88,    89,    90,    91,    92,    93,    94,    87,    88,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,     0,    96,    97,    98,    99,     0,     0,   108,
       0,    96,    97,    98,    99,    87,    88,    89,    90,    91,
      92,    93,    94,    87,    88,    89,    90,    91,    92,    87,
      88,     0,     0,    91,    92,     0,     0,     0,     0,    96,
      97,    98,    99,     0,     0,     0,     0,    96,    97,    98,
      99,     0,     0,    96,    97,    98,    99,    32,    33,    34,
       0,    35,    36,    32,    33,    37,     0,    35,    36,     0,
       0,    37,     0,     0,     0,    39,    40,    41,     0,     0,
       0,    39,    40,    41,    19,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
      10,    26,    45,     0,   104,   104,     0,    30,     5,    28,
      32,    33,    37,    35,    36,    68,     3,    29,    29,    38,
       0,    26,    27,    35,    35,     5,    32,    33,    25,     6,
       7,     8,     9,    10,    11,    12,   136,   136,    34,    26,
      27,    44,    35,    30,    31,    34,    34,    34,    34,    74,
      28,    76,    75,    30,    31,    32,    33,    44,    45,    46,
      44,    35,    87,    88,    89,    90,    91,    92,    93,    94,
      35,    96,    97,    98,    99,    34,    44,   130,    29,    35,
     105,    29,   104,    14,    15,    16,    17,    18,   111,    38,
     133,    30,    31,    32,    33,     3,     4,     5,    22,   142,
       3,     4,     5,    14,    15,    16,    17,    18,     5,   134,
     107,    19,    20,    21,   136,    23,    24,    28,    26,    27,
      28,    -1,    30,    31,   107,   135,    34,     3,     4,     5,
      38,    39,    -1,   143,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    34,     3,
       4,     5,    38,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    19,    20,    21,    -1,    23,
      24,    -1,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,     6,
       7,     8,     9,    10,    11,    12,    13,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    30,    31,    32,    33,    -1,    35,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    -1,    -1,    28,
      -1,    30,    31,    32,    33,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,     6,
       7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    30,    31,    32,    33,    26,    27,    28,
      -1,    30,    31,    26,    27,    34,    -1,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    44,    45,    46,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    50,    51,    52,    53,    54,    55,
      56,    57,     0,    52,    44,    28,    38,    60,    35,    14,
      15,    16,    17,    18,    28,    34,    75,    19,    20,    21,
      23,    24,    26,    27,    28,    30,    31,    34,    39,    44,
      45,    46,    53,    54,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    70,    71,    72,    73,    74,    76,    77,
      78,    79,    80,    81,    82,    83,    85,    86,    87,    88,
      54,    58,    59,    73,    34,    34,    34,    64,    28,    87,
      87,    87,    87,    73,    44,    39,    62,     6,     7,     8,
       9,    10,    11,    12,    13,    28,    30,    31,    32,    33,
      26,    27,    35,    35,    34,    75,    44,    29,    28,    69,
      73,    64,    73,    35,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,     3,    74,    84,    86,
      87,    73,    59,    35,    64,    35,    29,    62,    73,    60,
      74,    86,    35,    22,    62,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    56,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    68,
      69,    70,    71,    72,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    84,    84,    84,
      84,    85,    86,    86,    86,    87,    87,    87,    87,    87,
      88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     1,
       1,     1,     2,     2,     2,     3,     4,     3,     1,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     7,     1,     1,     5,     7,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     1,     2,     2,     3,     2,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     1,     2,     2,     2,     2,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 110 "parser.y" /* yacc.c:1646  */
    {
                                      (yylsp[0]);
                                      /* pp2: The @1 is needed to convince
                                       * yacc to set up yylloc. You can remove
                                       * it once you have other uses of @n*/
                                      if (ReportError::NumErrors() == 0)
                                          printf("Successfully finished parsing\n");
                                    }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 120 "parser.y" /* yacc.c:1646  */
    {}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 124 "parser.y" /* yacc.c:1646  */
    {}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 125 "parser.y" /* yacc.c:1646  */
    {}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 128 "parser.y" /* yacc.c:1646  */
    {}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "parser.y" /* yacc.c:1646  */
    {}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 132 "parser.y" /* yacc.c:1646  */
    {}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "parser.y" /* yacc.c:1646  */
    {}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "parser.y" /* yacc.c:1646  */
    {}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    {}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "parser.y" /* yacc.c:1646  */
    {}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.y" /* yacc.c:1646  */
    {}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 144 "parser.y" /* yacc.c:1646  */
    {}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 145 "parser.y" /* yacc.c:1646  */
    {}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "parser.y" /* yacc.c:1646  */
    {}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 149 "parser.y" /* yacc.c:1646  */
    {}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "parser.y" /* yacc.c:1646  */
    {}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 155 "parser.y" /* yacc.c:1646  */
    {}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 156 "parser.y" /* yacc.c:1646  */
    {}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 159 "parser.y" /* yacc.c:1646  */
    {}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 160 "parser.y" /* yacc.c:1646  */
    {}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "parser.y" /* yacc.c:1646  */
    {}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "parser.y" /* yacc.c:1646  */
    {}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 165 "parser.y" /* yacc.c:1646  */
    {}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 166 "parser.y" /* yacc.c:1646  */
    {}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 167 "parser.y" /* yacc.c:1646  */
    {}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "parser.y" /* yacc.c:1646  */
    {}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "parser.y" /* yacc.c:1646  */
    {}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "parser.y" /* yacc.c:1646  */
    {}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "parser.y" /* yacc.c:1646  */
    {}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 176 "parser.y" /* yacc.c:1646  */
    {}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 179 "parser.y" /* yacc.c:1646  */
    {}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 180 "parser.y" /* yacc.c:1646  */
    {}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 183 "parser.y" /* yacc.c:1646  */
    {}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 184 "parser.y" /* yacc.c:1646  */
    {}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 187 "parser.y" /* yacc.c:1646  */
    {}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 190 "parser.y" /* yacc.c:1646  */
    {}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 193 "parser.y" /* yacc.c:1646  */
    {}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "parser.y" /* yacc.c:1646  */
    {}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 199 "parser.y" /* yacc.c:1646  */
    {}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "parser.y" /* yacc.c:1646  */
    {}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 205 "parser.y" /* yacc.c:1646  */
    {}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 206 "parser.y" /* yacc.c:1646  */
    {}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 207 "parser.y" /* yacc.c:1646  */
    {}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 208 "parser.y" /* yacc.c:1646  */
    {}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 209 "parser.y" /* yacc.c:1646  */
    {}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 210 "parser.y" /* yacc.c:1646  */
    {}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 213 "parser.y" /* yacc.c:1646  */
    {}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 216 "parser.y" /* yacc.c:1646  */
    {}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "parser.y" /* yacc.c:1646  */
    {}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "parser.y" /* yacc.c:1646  */
    {}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 219 "parser.y" /* yacc.c:1646  */
    {}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 220 "parser.y" /* yacc.c:1646  */
    {}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 223 "parser.y" /* yacc.c:1646  */
    {}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 224 "parser.y" /* yacc.c:1646  */
    {}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 225 "parser.y" /* yacc.c:1646  */
    {}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 226 "parser.y" /* yacc.c:1646  */
    {}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 229 "parser.y" /* yacc.c:1646  */
    {}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 230 "parser.y" /* yacc.c:1646  */
    {}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 231 "parser.y" /* yacc.c:1646  */
    {}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "parser.y" /* yacc.c:1646  */
    {}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 235 "parser.y" /* yacc.c:1646  */
    {}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 236 "parser.y" /* yacc.c:1646  */
    {}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 239 "parser.y" /* yacc.c:1646  */
    {}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 240 "parser.y" /* yacc.c:1646  */
    {}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "parser.y" /* yacc.c:1646  */
    {}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 244 "parser.y" /* yacc.c:1646  */
    {}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 245 "parser.y" /* yacc.c:1646  */
    {}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 246 "parser.y" /* yacc.c:1646  */
    {}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 249 "parser.y" /* yacc.c:1646  */
    {}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 250 "parser.y" /* yacc.c:1646  */
    {}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 253 "parser.y" /* yacc.c:1646  */
    {}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 254 "parser.y" /* yacc.c:1646  */
    {}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 257 "parser.y" /* yacc.c:1646  */
    {}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 260 "parser.y" /* yacc.c:1646  */
    {}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 261 "parser.y" /* yacc.c:1646  */
    {}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 262 "parser.y" /* yacc.c:1646  */
    {}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 263 "parser.y" /* yacc.c:1646  */
    {}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 266 "parser.y" /* yacc.c:1646  */
    {}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 269 "parser.y" /* yacc.c:1646  */
    {}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 270 "parser.y" /* yacc.c:1646  */
    {}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 271 "parser.y" /* yacc.c:1646  */
    {}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 274 "parser.y" /* yacc.c:1646  */
    {}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 275 "parser.y" /* yacc.c:1646  */
    {}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 276 "parser.y" /* yacc.c:1646  */
    {}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 277 "parser.y" /* yacc.c:1646  */
    {}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 278 "parser.y" /* yacc.c:1646  */
    {}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 281 "parser.y" /* yacc.c:1646  */
    {}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 282 "parser.y" /* yacc.c:1646  */
    {}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2136 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 285 "parser.y" /* yacc.c:1906  */


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
