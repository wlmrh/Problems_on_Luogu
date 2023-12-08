#include <stdio.h>
#include <string.h>
#include <math.h>
char rst[300], card[105];
int l = 0, srt, end, zeros = 0;
char left[300], right[300];

void stringcpy(char *s1, char *s2){
  for(int i = 0; i < 300; i++){
    *(s1++) = *(s2++);
  }
}

int main(){
    scanf("%s", card);
    int len = strlen(card);
    for(int i = len - 1; i >= 0; i--){
        if(card[i] == '0'){
            zeros++;
        }
        if(card[i] != '0'){
            break;
        }
    }
    srt = 150; end = 150;
    rst[srt] = card[0];
    for(int i = 1; i <= len - 1 - zeros; i++){
        stringcpy(left, rst); stringcpy(right, rst);
        left[srt - 1] = card[i]; right[end + 1] = card[i];
        if(strcmp(left + srt - 1, right + srt) > 0){
            stringcpy(rst, right); end++;
        }
        else{
            stringcpy(rst, left); srt--;
        }
    }
    for(int i = srt; i <= end - zeros + 1; i++){
        printf("%c", rst[i]);
    }
    for(int i = 0; i < zeros; i++){
      printf("0");
    }
    return 0;
}