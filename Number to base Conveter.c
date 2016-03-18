#include<stdio.h>
#include<stdlib.h>
#include <string.h>
// Program to convert a number (decimal) into a number
// of any base up to 16

// a number of a some base implies that each digit representing
// that number may only take on values [0, n-1], where n is the
// base

void convert(int num, int base){
	
	// Add in obvious boundary conditions
	int num_clone = num;
	char str[80];
	strcpy(str, "The string of arbitrary base is: ");

	if(base == 0 || base == 1){
		printf("Choose another base");
	}
	else if(d <0){
		printf("You cannot pass a negative number");
	}

	// Now perform the required routine
	else
	{
		while( num_clone != 0)
		{
			num_clone = num_clone % base;
			if(num_clone == 0){
			strcat(str, '0');
			} 
			else{
				if(num_clone < 10){
				strcat(str, (char) numclone + '0');
				} else {
						if(num_clone == 11){
						strcat(str, 'a');
						}
						else if(num_clone == 12){
						strcat(str, 'b');
						}
						else if(num_clone == 13){
						strcat(str, 'c');
						}
						else if(num_clone == 14){
						strcat(str, 'd');
						}
						else if(num_clone == 15){
						strcat(str, 'e');
						}
						else if(num_clone == 16){
						strcat(str, 'f');
						}
						else if(num_clone == 17){
						strcat(str, 'g');
						}
						else if(num_clone == 18){
						strcat(str, 'h');
						}
						else if(num_clone == 19){
						strcat(str, 'i');
						}
						else if(num_clone == 20){
						strcat(str, 'j');
						}
						else if(num_clone == 21){
						strcat(str, 'k');
						}
						else if(num_clone == 22){
						strcat(str, 'l');
						}
						else if(num_clone == 23){
						strcat(str, 'm');
						}
						else if(num_clone == 24){
						strcat(str, 'n');
						}	
						else if(num_clone == 25){
						strcat(str, 'o');
						}
						else if(num_clone == 26){
						strcat(str, 'p');
						}
						else if(num_clone == 27){
						strcat(str, 'q');
						}
						else if(num_clone == 28){
						strcat(str, 'r');
						}
						else if(num_clone == 29){
						strcat(str, 's');
						}
						else if(num_clone == 30){
						strcat(str, 't');
						}
						else if(num_clone == 31){
						strcat(str, 'u');
						}
						else if(num_clone == 32){
						strcat(str, 'v');
						}
						else if(num_clone == 33){
						strcat(str, 'w');
						}
						else if(num_clone == 34){
						strcat(str, 'x');
						} 
						else if(num_clone == 35){
						strcat(str, 'y')'
						}			 
						else{
						strcat(str, 'z');
						}
				}	}
		}

// Remember to reverse the string afterwards	
strrev(str)
}


}

printf("%s", str);
	
}