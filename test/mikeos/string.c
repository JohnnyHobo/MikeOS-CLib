#include <mikeos.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char *hello = "Hello World";
	char elloh[12];
	char buf[30];
	char *str1, *str2, *str3, *str4;
	long i;

	os_print_string("Hello World");
	os_print_newline();

	os_print_string("Let's see that backwards: ");
	os_print_string(os_string_reverse(os_string_copy(hello, elloh)));
	os_print_newline();

	os_print_string("Now uppercase: ");
	os_print_string(os_string_uppercase(os_string_copy(hello, buf)));
	os_print_newline();
	
	os_print_string("Now lowercase: ");
	os_print_string(os_string_lowercase(os_string_copy(hello, buf)));
	os_print_newline();
	
	os_print_string("This string: \"");
	os_print_string(os_string_copy("  spaced   ", buf));
	os_print_string("\" has spaces.\r\n");
	
	os_print_string("Let's remove them: \"");
	os_print_string(os_string_chomp(buf));
	os_print_string("\"\r\n");
	
	os_string_copy(hello, buf);
	printf("Change the l's to m's: \"%s\"\n", 
			os_string_charchange(buf, 'l', 'm'));

	os_string_copy(hello, buf);
	printf("Remove all the l's: \"%s\"\n", os_string_strip(buf, 'l'));

	os_string_copy(hello, buf);
	printf("Limit it to 4 characters: \"%s\"\n", 
			os_string_truncate(buf, 4));

	printf("The string: \"%s\" is %d characters long.\n", hello,
			os_string_length(hello));
	
	printf("Join the strings \"%s\" and \"%s\" to make: \"%s\"\n", "abcde",
			"fghij", os_string_join("abcde", "fghij", buf));

	str1 = os_string_copy("asdf", buf);
	str2 = os_string_copy("asdf", buf + 10);
	printf("Comparing \"%s\" and \"%s\"...", str1, str2);
	if (os_string_compare(str1, str2)) {
		printf("match!\n");
	} else {
		printf("no match.\n");
	}


	str1 = os_string_copy("asdf", buf);
	str2 = os_string_copy("jkl;", buf + 10);
	printf("Comparing \"%s\" and \"%s\"...", str1, str2);
	if (os_string_compare(str1, str2)) {
		printf("match!\n");
	} else {
		printf("no match.\n");
	}


	str1 = os_string_copy("asdf", buf);
	str2 = os_string_copy("asdn", buf + 10);
	printf("Comparing \"%s\" and \"%s\"...", str1, str2);
	if (os_string_compare(str1, str2)) {
		printf("match!\n");
	} else {
		printf("no match.\n");
	}


	str1 = os_string_copy("asdf", buf);
	str2 = os_string_copy("asdn", buf + 10);
	printf("Comparing \"%s\" and \"%s\" up to char %d...", str1, str2, 3);
	if (os_string_strincmp(str1, str2, 3)) {
		printf("match\n");
	} else {
		printf("no match\n");
	}


	str1 = os_string_copy("asdf", buf);
	str2 = os_string_copy("asnf", buf + 10);
	printf("Comparing \"%s\" and \"%s\" up to char %d...", str1, str2, 3);
	if (os_string_strincmp(str1, str2, 3)) {
		printf("match\n");
	} else {
		printf("no match\n");
	}

	
	os_string_copy("foo.bin -d bar -n", buf);
	printf("Original string is \"%s\"\n", buf);
	os_string_parse(buf, &str1, &str2, &str3, &str4);
	printf("Parsed strings are: \"%s\",  \"%s\",  \"%s\" and  \"%s\"\n",
			str1, str2, str3, str4);

	os_wait_for_key();

	os_string_copy("12345", buf);
	printf("Converting \"%s\" to an int: %d\n", buf, os_string_to_int(buf));

	i = 54321;
	printf("Converting unsigned value %d to a string: \"%s\"\n", i,
			os_int_to_string(i));

	i = -30001;
	printf("Converting unsigned value %d to a string: \"%s\"\n", i,
			os_sint_to_string(i));

	i = 1234567890;
	printf("Converting long unsigned value %d to a string: \"%s\"\n", i,
			os_long_int_to_string(i, 10, buf));


	os_set_time_fmt(CLOCK_12H);
	printf("Getting time in format %s: \"%s\"\n", "CLOCK_12H", 
			os_get_time_string(buf));

	os_set_time_fmt(CLOCK_24H);
	printf("Getting time in format %s: \"%s\"\n", "CLOCK_24H", 
			os_get_time_string(buf));

	os_set_date_fmt(SIMPLE_DATE);
	printf("Getting date in format %s: \"%s\"\n", "SIMPLE_DATE", 
			os_get_date_string(buf));

	os_set_date_fmt(AMERICAN_DATE);
	printf("Getting date in format %s: \"%s\"\n", "AMERICAN_DATE", 
			os_get_date_string(buf));

	os_set_date_fmt(BRITISH_DATE);
	printf("Getting date in format %s: \"%s\"\n", "BRITISH_DATE", 
			os_get_date_string(buf));

	os_set_date_fmt(ISO8601_DATE);
	printf("Getting date in format %s: \"%s\"\n", "ISO8601_DATE", 
			os_get_date_string(buf));

	os_wait_for_key();
	os_print_newline();
	return 0;
}
