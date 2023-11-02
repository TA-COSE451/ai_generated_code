/*
I have binary data in an unsigned char variable. I need to convert them to PEM base64 in c. I looked in openssl library but i could not find any function. Does any body have any idea?
*/

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>

int binaryToPEMBase64(const unsigned char *binaryData, size_t binaryDataSize, char **pemBase64Data) {
    BIO *bio_mem = BIO_new(BIO_s_mem());

    if (bio_mem == NULL) {
        return -1; // Error creating BIO
    }

    BIO *bio_base64 = BIO_new(BIO_f_base64());

    if (bio_base64 == NULL) {
        BIO_free(bio_mem);
        return -1; // Error creating BIO
    }

    BIO_push(bio_base64, bio_mem);
    BIO_set_flags(bio_base64, BIO_FLAGS_BASE64_NO_NL);

    if (BIO_write(bio_base64, binaryData, binaryDataSize) <= 0) {
        BIO_free_all(bio_base64);
        return -1; // Error encoding data
    }

    BIO_flush(bio_base64);

    BUF_MEM *bio_mem_buf;
    BIO_get_mem_ptr(bio_mem, &bio_mem_buf);

    *pemBase64Data = (char *)malloc(bio_mem_buf->length + 1);

    if (*pemBase64Data == NULL) {
        BIO_free_all(bio_base64);
        return -1; // Memory allocation error
    }

    memcpy(*pemBase64Data, bio_mem_buf->data, bio_mem_buf->length);
    (*pemBase64Data)[bio_mem_buf->length] = '\0';

    BIO_free_all(bio_base64);

    return 0; // Success
}

int main() {
    unsigned char binaryData[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64}; // Your binary data
    size_t binaryDataSize = sizeof(binaryData);

    char *pemBase64Data = NULL;

    if (binaryToPEMBase64(binaryData, binaryDataSize, &pemBase64Data) == 0) {
        printf("PEM Base64 Data:\n%s\n", pemBase64Data);
        free(pemBase64Data);
    } else {
        printf("Error converting binary to PEM base64.\n");
    }

    return 0;
}
