//Name: Hasin Shadab Rahman
#include <stdio.h>
#include <ctype.h>
// The following program get an input from and validates. The inputs can contain only All alphabetic letters are lower case, Non alphabetic letters like digits, white space, exclamation point, question mark, or period.
int main(){
    // Asks input 
    printf("Enter input:");
    char c = getchar();
    int val = 1;
    while ((c = getchar()) != '\n'){
    // Validates the inputs by assigning  a value to 'val' if the conditions are not met
    if(!(islower(c)||isdigit(c)|| c ==' '|| c == '?'|| c== '!'|| c == '.')){
        val = 0;
        break;
    }}
    // Validates the input if the conditions are met i.e when the value for val is 1
    if(val){
        printf("valid");
    }
    // Invalidates the input if the conditions are not met i.e when the value for val is 0
    else{
        printf("invalid");
    }
    
    return 0;
}