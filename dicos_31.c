/*
I have binary data in an unsigned char variable. I need to convert them to PEM base64 in c. I looked in openssl library but i could not find any function. Does any body have any idea?
*/

#include <stdio.h>
#include <openssl/evp.h>

int main() {
    // Binary data
    unsigned char binaryData[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int binaryDataLength = sizeof(binaryData);

    // Create an output buffer to hold the base64 data
    unsigned char base64Data[(binaryDataLength * 4 / 3) + 4]; // The +4 accounts for padding

    // Initialize the EVP_ENCODE_CTX structure
    EVP_ENCODE_CTX ctx;
    EVP_EncodeInit(&ctx);

    // Encode the binary data to base64
    int base64Length;
    EVP_EncodeUpdate(&ctx, base64Data, &base64Length, binaryData, binaryDataLength);
    int finalBase64Length;
    EVP_EncodeFinal(&ctx, base64Data + base64Length, &finalBase64Length);

    // Print the base64 data
    base64Length += finalBase64Length;
    base64Data[base64Length] = '\0';
    printf("Base64 encoded data:\n%s\n", base64Data);

    return 0;
}
