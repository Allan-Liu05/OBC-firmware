#include "obc_gs_aes128.h"
#include "obc_gs_errors.h"

#include <aes.h>

#include <stdint.h>
#include <string.h>

// Store the AES context
static struct AES_ctx ctx;

/**
 * @brief Decrypts the AES blocks
 *
 * @param aesData Pointer to an aes_data_t struct that includes a struct of the IV and encrypted data
 * @param output array to store the decrypted data
 * @param outputBufferLen length of the buffer to store the decrypted data
 *
 * @return obc_gs_error_code_t - whether or not the data was successfully decrypted
 */
obc_gs_error_code_t aes128Decrypt(aes_data_t *aesData, uint8_t *output, uint8_t BufferLen) {
  if (aesData == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  if (output == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  if (BufferLen != aesData->textLen) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  memcpy(output, aesData->ciphertext, aesData->textLen);
  AES_ctx_set_iv(&ctx, aesData->iv);
  AES_CTR_xcrypt_buffer(&ctx, output, aesData->textLen);

  return OBC_GS_ERR_CODE_SUCCESS;
}

/**
 * @brief Initializes the AES context
 *
 * @param key - The key to decrypt the AES blocks with
 * @return obc_gs_error_code_t - whether or not the context was successfully initialized
 */
obc_gs_error_code_t initializeAesCtx(const uint8_t *key) {
  if (key == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  AES_init_ctx(&ctx, key);

  return OBC_GS_ERR_CODE_SUCCESS;
}
/**
 * @brief Decrypts the AES blocks
 *
 * @param aesData Pointer to an aes_data_t struct that includes a struct of the IV and data to encrypt
 * @param input array to store the encrypted data
 * @param outputBufferLen length of the buffer to store the encrypted data
 *
 * @return obc_gs_error_code_t - whether or not the data was successfully decrypted
 */
obc_gs_error_code_t aes128Encrypt(aes_data_t *aesData, uint8_t *input, uint8_t BufferLen) {
  if (aesData == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }
  if (input == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }
  if (aesData->textLen != BufferLen) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  memcpy(input, aesData->ciphertext, aesData->textLen);
  AES_ctx_set_iv(&ctx, aesData->iv);
  AES_CTR_xcrypt_buffer(&ctx, input, aesData->textLen);

  return OBC_GS_ERR_CODE_SUCCESS;
}
