#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_T 1024

int main() {
	srand(time(NULL));
	char input[MAX_T];
	char key[MAX_T];
	int t, i;

	/* Get the message from the user */
	i = 0;
	memset(input, 0, MAX_T);
	while(input[i] = getchar()) {
		if(input[i] == '\n') {
			input[i] = '\0';
			break;
		}
		i++;
	}
	printf("\nPlaintext: %s\n\n", input);
	
	/* Generate a random key of the same length as the input */
	t = strlen(input);
	for(i = 0; i < t; i++)
		key[i] = rand();

	/* Generate the cipher by XORing each bit of the message with each bit
	   of the key */
	for(i = 0; i < t; i++)
		input[i] ^= key[i];

	/* Print out the cipher */
	printf("Cipher: %s\n\n", input);

	/* Decrypt the cipher by XORing each bit of the cipher with each bit of
	   the key */
	for(i = 0; i < t; i++)
		input[i] ^= key[i];

	/* Print out the decrypted message to verify it worked */
	printf("Decrypted message: %s\n\n", input);

	return 0;
}