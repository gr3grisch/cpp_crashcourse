#include <iostream>
#include <cstdio>
#include <cstddef>


#define MAX 61

unsigned int absolute_value(int value)
{
	return value >= 0 ? value : -value;
}

int sum(const int op1, const int op2)
{
	return op1 + op2;
}

bool is_prime(const int x)
{
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

unsigned long find_max_in_array(const unsigned long A[], size_t len)
{
	unsigned long max = 0uL;
	for (int i = 0; i < len; ++i)
	{
		if (A[i] > max) max = A[i];
	}
	return max;
}

void taunt()
{
	printf("Hey, laser lips, your mama was a snow blower.\n");
}

int main()
{
	/* Chapter 1*/

	int my_num = 500000;
	printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));

	const int a = 19, b = -29;
	printf("The sum of %d + %d = %d\n", a, b, sum(a, b));

	printf("\n");

	/* Chapter 2*/
	// types and format specifiers
	printf("the types and format specifiers\n\n");

	const short hd = -1;
	const unsigned short hu = 24;
	const int d = -120450;
	const unsigned int u = 12000;;
	const long l = -120490000;
	const unsigned long lu = 120494496;
	const long long lld = -45545456;
	const unsigned long long llu = 8'054'560; // Can be written like this for readability


	/*
	 * The usual format specifiers for a size_t are %zu for a decimal
	 * representation or %zx for a hexadecimal representation
	 */
	constexpr size_t size_char = sizeof(short);
	printf("%-20s %-5s %zx %s %-8hd\n", "short", "%hd", size_char, " bytes", hd);
	constexpr size_t size_u_short = sizeof(unsigned short);
	printf("%-20s %-5s %zu %s %-8hu\n", "unsigned short", "%hu", size_u_short, " bytes", hu);
	printf("%-20s %-5s %zu %s %-8d\n", "int", "%d", sizeof(int), " bytes", d);
	printf("%-20s %-5s %zu %s %-8u\n", "unsigned int", "%u", sizeof(unsigned int), " bytes", u);
	printf("%-20s %-5s %zu %s %-8ld\n", "long", "%l", sizeof(long), " bytes", l);
	printf("%-20s %-5s %zu %s %-8lu\n", "unsigned long", "%lu", sizeof(unsigned long), " bytes", lu);
	printf("%-20s %-5s %zu %s %-8lld\n", "long long", "%lld", sizeof(long long), " bytes", lld);
	printf("%-20s %-5s %zu %s %-8llu\n", "unsigned long long", "%llu", sizeof(unsigned long long), " bytes", llu);


	printf("\nBinary, octal and hexadecimal representations:\n\n");

	const unsigned short binary = 0b10101010;
	printf("%-25s %s %hu\n", "binary prefix is 0b", "eg. 0b10101010 =", binary);
	const int octal = 0123;
	printf("%-25s %s %d\n", "octal prefix is 0", "eg. 0123 =", octal);
	const unsigned long long hexadecimal = 0xFFFFFFFFFFFFFFFFL;
	printf("%-25s %s %llu\n", "hexadecimal prefix is 0x", "eg. 0xFFFFFFFFFFFFFFFF =", hexadecimal);

	const unsigned int i_like_this = 69u; // enforces the fact that 69 is unsigned integer - posfix is u
	const unsigned long one_coffee_please = 0xCAFEul;
	// or uL, UL etc for the suffix. ll LL when a long long (ull for unsigned)

	printf("%-5u = 0%-6o (octal) = 0x%-6x (hexadecimal)\n", i_like_this, i_like_this, i_like_this);
	// take care at the format in the next snip
	printf("%-5lu = 0%-6lo (octal) = 0x%-6lx (hexadecimal)\n", one_coffee_please, one_coffee_please, one_coffee_please);

	// floating stuffs
	printf("\nFloating numbers:\n\n");
	/*
	 * Floating-point literals are double precision by default.
	 * If you need single precision, use an f or F suffix;
	 * for extended precision, use l or L, as shown here:
	 */
	const float a_float = 0.1F; // or f
	const double a_double = 0.2;
	const long double a_long_double = 0.3L; // or l

	/*
	 * The format specifier %f displays a float with decimal digits,
	 * whereas %e displays the same number in scientific notation.
	 * You can let printf decide which of these two to use with
	 * the %g format specifier, which selects the more compact of %e or %f.
	 */

	printf("%-20s %11s %zu %s %g %f %e\n", "float", "%g  %f  %e", sizeof(float), " bytes", a_float, a_float, a_float);
	printf("%-20s %11s %zu %s %lg %lf %le\n", "double", "%lg %lf %le", sizeof(double), " bytes", a_double, a_double,
	       a_double);
	printf("%-20s %11s %zu %s %lg %lf %le\n", "long double", "%lg %lf %le", sizeof(long double), " bytes",
	       a_long_double, a_long_double,
	       a_long_double);

	puts("");

	const long double avo_num = 6.0221409e23l;
	printf("Avogadro's Number  :  %le %lf %lg\n", avo_num, avo_num, avo_num);
	const double planck_const = 6.62607004e-34;
	printf("Planck's constant  :  %le %lf %lg\n", planck_const, planck_const, planck_const);
	const float hogwarts_num = 9.75f;
	printf("Hogwarts' Platform : %e %f %g\n", hogwarts_num, hogwarts_num, hogwarts_num);

	// intermezzo 
	printf("\nprime numbers up to %d =>", MAX - 1);

	for (int i = 1; i < MAX; ++i)
	{
		if (is_prime(i)) { printf("%4d", i); }
	}

	// Character Types

	/*
	 * If the character is any type but char, you must also provide
	 * a prefix: L for wchar_t, u for char16_t, and U for char32_t.
	 * For example, 'J' declares a char literal and L'J' declares a wchar_t.
	 */
	printf("\n\nthe different Character types:\n\n");
	const char c = 'M';
	const char16_t c16 = '\u0222';
	const char32_t c32 = L'\u0422';
	const signed char schar = 67u;
	const unsigned char uchar = u'J';
	const wchar_t wchar = L'Z';

	// The printf format specifier for char is %c. The wchar_t format specifier is %lc.
	printf("Windows binaries start with %c%lc.\n", c, wchar);
	printf("other chars: %c %c %c %c\n", c16, c32, schar, uchar);

	// boolean types
	printf("\nBoolean stuffs:\n\n");
	const bool b1 = true;
	const bool b2 = false;
	printf("true && false  : %d\n", b1 && b2);
	printf("true || false  : %d\n", b1 || b2);
	printf("10 <= 12       : %d\n", 10 <= 12);

	// std::byte type (available in the <cstddef> header)
	printf("\nstd::byte for the system programmers\n\n");

	// void type
	printf("the void type:\n\n");
	taunt();

	printf("\nArrays:\n");
	printf("\ninitialize 'em:\n");
	const int A[] = {1, 2, 3, 4};
	// a cool for each
	for (const int element : A)
	{
		printf("%d,  ", element);
	}
	puts("");

	// all is set to 0 in both initializations
	const int B[10]{}; // or const int B[10]{};
	for (size_t i = 0; i < 4; ++i)
	{
		printf("B[%zu]:%d ", i, B[i]);
	}
	puts("");

	// find nax of an array of long unsigned
	const unsigned long values[] = {10, 50, 20, 40, 0};
	const size_t max_index = sizeof(values) / sizeof(unsigned long);
	const unsigned long maximum = find_max_in_array(values, max_index);
	printf("MAX value of an array of %zu (%zu bytes / %zu bytes) elements containing {10, 50, 20, 40, 0} : %lu ",
	       max_index,
	       sizeof(values),
	       sizeof(unsigned long),
	       maximum);
	puts("");

	// the C style strings in C++
	printf("\nthe C style strings in C++\n\n");
	char english[] = "A book holds a house of gold.";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
	printf("%s\n%ls\n", english, chinese);

	// intermezzo
	char alphabet[27];
	for (int i = 0; i < 26; ++i)
	{
		alphabet[i] = i + 97;
	}
	alphabet[26] = 0;
	printf("%s\n", alphabet);

	for (int i = 0; i < 26; ++i)
	{
		alphabet[i] = i + 65;
	}
	printf("%s\n", alphabet);

	// User defined types
	enum class race {
		Dinan,
		Teklan,
		Ivyn,
		Moiran,
		Camite,
		Julian,
		Aidan
	};

	auto race = race::Dinan;



	return EXIT_SUCCESS;
}
