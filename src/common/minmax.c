
int min(int x, int y)
{
	if (x < y) return x;
	return y;
}

int max(int x, int y)
{
	if (x > y) return x;
	return y;
}

int abs(int n)
{
	if (n < 0) return -n;
	return n;
}

int amin(int x, int y)
{
	if (abs(x) < abs(y)) return x;
	return y;
}

int amax(int x, int y)
{
	if (abs(x) > abs(y)) return x;
	return y;
}

