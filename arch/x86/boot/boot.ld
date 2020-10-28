SECTIONS
{
	.text  0x7c00 :
	{
		code = .; _code = .; __code = .;
		*(.text)
	}
}
