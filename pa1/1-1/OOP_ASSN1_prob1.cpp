#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>

int main() {

	FILE* infile = fopen("input.txt", "r");
	FILE* outfile = fopen("output.txt", "w");
	char op=0;
	float num1 = 0, num2 = 0, ans = 0;

	while (fscanf(infile, "%c %f %f\n", &op, &num1, &num2) == 3) {

		if (op == '+') ans = (num1 + num2)*1000;
		else if (op == '-') ans =  (num1 - num2)*1000;
		else if (op == '*') ans = (num1 * num2)*1000;
		else if (op == '/') ans = (num1 / num2)*1000;

		if ((int)ans - ans == 0 && (int)ans % 10 == 0) fprintf(outfile, "%.2f\n", ans / 1000.0);
		else fprintf(outfile, "%.3f\n", ans / 1000.0);
	}

	fclose(infile);
	fclose(outfile);

	return 0;
}