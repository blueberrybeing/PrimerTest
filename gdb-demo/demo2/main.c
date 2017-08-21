#include <stdio.h> 
  
void print_str(char* str){
        printf("%s", str);
        str[0] = 'a';
        printf("\n");
}
int main(){
        char* str = "hello, world!";

       print_str(str);

       return 0;
}

