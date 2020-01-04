#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > * b)
		return 1;
	else return 0;
}

int main(void)
{
	int i, nx, ky;
	int* x;
	int* p;
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf("%d", &ky);
	p = bsearch(&ky,
		x,
		nx,
		sizeof(int), (int(*)(const void*, const void*))int_cmp);
	if (p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	free(x);

	return 0;
}