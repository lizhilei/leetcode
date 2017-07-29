#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int head = 0,end = 0, i, length = 0;
    
    while (s[end] != '\0') {
        end++;
        for (i = head; i < end; i++) {
            if (s[i] == s[end]) {
                if (end -head > length)
                    length = end - head;
                head =i + 1;
                break;
            } else {
                if (end -head > length)
                    length = end - head;
            }
        }
    }
    return length;   
}

int main(){
	char *x = "12345adfsd123";
	int  l = lengthOfLongestSubstring(x);

	return 0;
	
}
