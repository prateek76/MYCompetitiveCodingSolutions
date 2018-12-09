#include<stdio.h>
#include<string.h>


int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int cnt = 0;
		char s[1000000];
		scanf("%s",s);
		if(strlen(s)>2){
		for(int i=0;i<strlen(s)-3;i++){
			int check = 0;
			if(s[i] == 'c' || s[i] == 'h' || s[i] == 'e' || s[i] == 'f'){
				check++;
				if((s[i+1] == 'c' || s[i+1] == 'h' || s[i+1] == 'e' || s[i+1] == 'f') && (s[i+1] != s[i])){
					check++;
					if((s[i+2] == 'c' || s[i+2] == 'h' || s[i+2] == 'e' || s[i+2] == 'f') &&  ((s[i+1] != s[i+2]) && (s[i] != s[i+2]))){
						check++;
						if((s[i+3] == 'c' || s[i+3] == 'h' || s[i+3] == 'e' || s[i+3] == 'f') && ((s[i+2] != s[i+3]) && (s[i] != s[i+3]) && (s[i+1] != s[i+3]))){
							check++;
						}
					}
				}
			} else
					continue;
			if(check == 4)
				cnt++;
		}
		if(cnt != 0){
			printf("lovely ");
			printf("%d\n",cnt);
		}
		else
			printf("normal\n");
		}
		else
		    printf("normal\n");
	}
	return 0;
}