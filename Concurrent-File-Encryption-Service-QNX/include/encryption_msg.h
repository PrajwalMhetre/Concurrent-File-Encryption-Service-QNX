#ifndef ENCRYPTION_MSG_H
#define ENCRYPTION_MSG_H

#include <stdint.h>
#include <sys/neutrino.h>

/*
 * Project:
 * Concurrent File Encryption Service
 *
 * Purpose:
 * Common message definitions shared by client and server.
 *
 * Mandatory QNX requirements covered:
 * - QNX Message API
 * - Client-server architecture
 * - Common message header
 * - 64 KB+ payload definition
 * - Asynchronous event notification
 */

#define SERVER_NAME             "qnx_encrypt_server"

#define MIN_PAYLOAD_SIZE        (64U * 1024U)

#define MAX_DATA_SIZE           (256U * 1024U)

#define MAX_WORKERS             4

#define CHUNK_SIZE              (16U * 1024U)

/*
 * Request types
 */
typedef enum
{
    MSG_ENCRYPT = 1,
    MSG_GET_RESULT,
    MSG_SHUTDOWN
} request_type_t;


/*
 * Common message header.
 *
 * Every client-server message starts with this structure.
 */
typedef struct
{
    uint32_t type;
    uint32_t request_id;
    uint32_t data_size;
    uint32_t chunk_count;

} message_header_t;


/*
 * Encryption request.
 *
 * The actual large payload will be transferred using IOV.
 */
typedef struct
{
    message_header_t header;

    uint32_t encryption_key;

} encryption_request_t;


/*
 * Result information.
 *
 * Large encrypted data is not placed directly inside this
 * fixed-size response structure.
 */
typedef struct
{
    uint32_t request_id;
    uint32_t result_size;
    int32_t  status;

} encryption_result_t;


/*
 * Status values.
 */
#define STATUS_SUCCESS          0
#define STATUS_INVALID_SIZE    -1
#define STATUS_INVALID_REQUEST -2
#define STATUS_ENCRYPTION_FAIL -3
#define STATUS_TIMEOUT         -4
#define STATUS_INTERNAL_ERROR  -5


/*
 * Event code used by the server to notify the client
 * that processing has completed.
 */
#define ENCRYPTION_EVENT_CODE  (_PULSE_CODE_MINAVAIL + 1)

#endif /* ENCRYPTION_MSG_H */