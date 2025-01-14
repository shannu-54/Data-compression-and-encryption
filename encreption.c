#include <stdio.h>
#include <string.h>

// Function to compress data using Run-Length Encoding (RLE)
void compressData(const char *input, char *compressed) {
    int i, count, len = strlen(input);
    int index = 0;

    for (i = 0; i < len; i++) {
        // Count occurrences of the current character
        count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Append character and its count to compressed string
        compressed[index++] = input[i];
        compressed[index++] = count + '0';
    }
    compressed[index] = '\0'; // Null-terminate the compressed string
}

// Function to encrypt data using XOR encryption
void encryptData(const char *input, char *encrypted, char key) {
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        encrypted[i] = input[i] ^ key; // XOR operation
    }
    encrypted[len] = '\0'; // Null-terminate the encrypted string
}

// Function to decrypt data using XOR decryption
void decryptData(const char *encrypted, char *decrypted, char key) {
    encryptData(encrypted, decrypted, key); // Decryption is the same as encryption
}

int main() {
    char input[100], compressed[200], encrypted[200], decrypted[200];
    char key;

    // Input original data and encryption key
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    printf("Enter a single character encryption key: ");
    scanf(" %c", &key);

    // Compress the input data
    compressData(input, compressed);
    printf("Compressed Data: %s\n", compressed);

    // Encrypt the compressed data
    encryptData(compressed, encrypted, key);
    printf("Encrypted Data: %s\n", encrypted);

    // Decrypt the encrypted data
    decryptData(encrypted, decrypted, key);
    printf("Decrypted Data: %s\n", decrypted);

    // Decompress the decrypted data
    char decompressed[200];
    int i, index = 0, len = strlen(decrypted);
    for (i = 0; i < len; i += 2) {
        char ch = decrypted[i];
        int count = decrypted[i + 1] - '0';
        while (count--) {
            decompressed[index++] = ch;
        }
    }
    decompressed[index] = '\0';
    printf("Decompressed Data: %s\n", decompressed);

    return 0;
}