#include <stdio.h>
#include <string.h>

char ac[1000001], bc[1000001], ab[1000001], bb[1000001];
bool isSpace(char c) {
	return c=='\n' || c == '\t' || c == '\r' || c == ' ';
}
void removeTrailingSpace(char *a) {
	int len = strlen(a);
	while (len > 0 && isSpace(a[len-1])) {
		len --;
		a[len] = '\0';
	}
}
int main(int argc, char *argv[])
{
	if (argc < 4) {
		fprintf(stderr, "usage : %s system_input.txt correct_answer.txt user_output.txt",
			argc == 0 ? "grading" : argv[0]);
		return 0;
	}
	FILE *inp=fopen(argv[1],"r");
	if (inp == NULL) {
		fprintf(stderr, "No File %s", argv[1]);
		return 0;
	}
	FILE *sol=fopen(argv[2],"r");
	if (sol == NULL) {
		fprintf(stderr, "No File %s", argv[2]);
		return 0;
	}
	FILE *out=fopen(argv[3],"r");
	if (out == NULL) {
		fprintf(stderr, "No File %s", argv[3]);
		return 0;
	}
	int T;
	fscanf(inp, "%d", &T);
	fclose(inp);

	double r = 100.0, c, score = 0.0;
	int wrong = 0;
	c = r / (double)T;

	for (int i=1;i<=T;i++) {
		fgets(ab, 1000000, out);
		fgets(bb, 1000000, sol);
		ab[1000000] = bb[1000000] = '\0';
		removeTrailingSpace(ab);
		removeTrailingSpace(bb);
		fgets(ac, 1000000, out);
		fgets(bc, 1000000, sol);
		ac[1000000] = bc[1000000] = '\0';
		removeTrailingSpace(ac);
		removeTrailingSpace(bc);
		if (!strcmp(ac, bc) && !strcmp(ab, bb)) {
			score += c;
		}
		else {
			wrong ++;
		}

	}
	if (wrong == 0) printf("100");
	else printf("%d", (int)score);
	fclose(out);
	fclose(sol);
	return 0;
}
