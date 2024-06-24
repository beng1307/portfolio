unsigned char	reverse_bits(unsigned char octet)
{
	int				index = 8;
	unsigned char	rev_byte = 0;

	while (index > 0)
	{
		rev_byte = rev_byte * 2 + (octet % 2);
		octet = octet / 2;
		index--;
	}
	return (rev_byte);
}