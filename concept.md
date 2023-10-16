printf(string, ...)
{
	get the arguments and pass them into process_string function
	clean up with va_end
}

process_string(string, args)
{
	for string[0]
		if not a %, print it.
		if %, call identify_specials function with pointer to %
			and save the return value to string.
}

identify_specials(*string, args)
{
	is there a flag?
		save flag two variables
		display_number_system and display_positive_identifier
		iterate string by 1
	switch (string[1])
		case d:
			print_int(args(int), display_number_system, display_positive_identifier)
		case c:
			print_char(args(char));
		...
		case %:
			write(1, '%', 1);
	return string (which has the pointer position saved)
}

// type specifiers always get passed into their functions. it just depends on the function whether they are used. that way when we add a # modifier to the char function it wont blow up