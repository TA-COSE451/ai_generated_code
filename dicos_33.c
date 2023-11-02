/*
I have binary data in an unsigned char variable. I need to convert them to PEM base64 in c. I looked in openssl library but i could not find any function. Does any body have any idea?
*/

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

char *binary_to_pem_base64(const unsigned char *data, size_t data_len) {
    // Create a BIO to write the data into
    BIO *bio = BIO_new(BIO_s_mem());

    // Create a Base64 BIO filter
    BIO *base64 = BIO_new(BIO_f_base64());
    BIO_set_flags(base64, BIO_FLAGS_BASE64_NO_NL); // No line breaks

    // Chain the BIOs together
    bio = BIO_push(base64, bio);

    // Write the binary data to the BIO
    BIO_write(bio, data, data_len);
    BIO_flush(bio);

    // Get the length of the encoded data
    int pem_len = BIO_get_mem_data(bio, NULL);

    // Allocate memory for the PEM data
    char *pem_data = (char *)malloc(pem_len + 1);

    // Read the data from the BIO into the pem_data buffer
    BIO_read(bio, pem_data, pem_len);
    pem_data[pem_len] = '\0'; // Null-terminate the string

    // Clean up the BIOs
    BIO_free_all(bio);

    return pem_data;
}

int main() {
    unsigned char binary_data[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64};
    size_t data_len = sizeof(binary_data);

    char *pem_base64_data = binary_to_pem_base64(binary_data, data_len);

    // Use the PEM base64-encoded data as needed

    // Don't forget to free the allocated memory
    free(pem_base64_data);

    return 0;
}
