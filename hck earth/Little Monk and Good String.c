#include<stdio.h>
#include<string.h>

int main()
{
	char arr[100006];
	scanf("%s", arr);
	int n = strlen(arr);
	int max = 0;
	int flag = 0;
	int cnt = 0;
	for (int i = 0;i<n;i++) {
		if ((arr[i] == 'a') || (arr[i] == 'e') || (arr[i] == 'i') || (arr[i] == 'o') || (arr[i] == 'u')) {
			cnt++;
			if (i == n - 1) {
				if (cnt>max) {
					flag = 1;
					max = cnt;
				}
			}
		}
		else {
			flag = 1;
			if (cnt>max) {
				max = cnt;
			}
			cnt = 0;
		}
	}
	if (flag == 1) {
		printf("%d", max);
	}
	else {
		printf("%d", cnt);
	}
	return 0;
}