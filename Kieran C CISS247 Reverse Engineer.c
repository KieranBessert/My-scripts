// Exercise1.c - Reverse Engineering
// CISS 247, Lab 6, Fall, 2020
// Coded by Kieran Bessert 13 Nov 2020 
int main() {
	int x = 0;
	int y = 0;
	y = x + y;
	x = y + x;
	x = x++;
	y = y + x;
}

// Exercise1.c - Reverse Engineering
// CISS 247, Lab 6, Fall, 2020
// Coded by Kieran Bessert 13 Nov 2020 
int main() {
	int x = 19;
	int y = 34;
	int z = 12;
	int aa = (x * 3) + (y << 2) + (z * 2);
	return aa;
}

// Exercise1.c - Reverse Engineering
// CISS 247, Lab 6, Fall, 2020
// Coded by Kieran Bessert 13 Nov 2020 
int main() {
	int x[6] = {23,19,12,2,3,1};
	int y = 0;
	y += x[0] * x[3];
	y += x[1] * x[4];
	y += x[2] * x[5];
	return 0;
}
