#pragma once
// MESSAGE MODALITY_SNAPSHOT PACKING

#define MAVLINK_MSG_ID_MODALITY_SNAPSHOT 1400


typedef struct __mavlink_modality_snapshot_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot).*/
 uint32_t sequence_number; /*<  Sequence number.*/
 uint8_t snapshot[12]; /*<  Modality probe snapshot bytes.*/
} mavlink_modality_snapshot_t;

#define MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN 24
#define MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN 24
#define MAVLINK_MSG_ID_1400_LEN 24
#define MAVLINK_MSG_ID_1400_MIN_LEN 24

#define MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC 105
#define MAVLINK_MSG_ID_1400_CRC 105

#define MAVLINK_MSG_MODALITY_SNAPSHOT_FIELD_SNAPSHOT_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MODALITY_SNAPSHOT { \
    1400, \
    "MODALITY_SNAPSHOT", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_modality_snapshot_t, time_usec) }, \
         { "sequence_number", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_modality_snapshot_t, sequence_number) }, \
         { "snapshot", NULL, MAVLINK_TYPE_UINT8_T, 12, 12, offsetof(mavlink_modality_snapshot_t, snapshot) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MODALITY_SNAPSHOT { \
    "MODALITY_SNAPSHOT", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_modality_snapshot_t, time_usec) }, \
         { "sequence_number", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_modality_snapshot_t, sequence_number) }, \
         { "snapshot", NULL, MAVLINK_TYPE_UINT8_T, 12, 12, offsetof(mavlink_modality_snapshot_t, snapshot) }, \
         } \
}
#endif

/**
 * @brief Pack a modality_snapshot message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot).
 * @param sequence_number  Sequence number.
 * @param snapshot  Modality probe snapshot bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_modality_snapshot_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t sequence_number, const uint8_t *snapshot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, sequence_number);
    _mav_put_uint8_t_array(buf, 12, snapshot, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN);
#else
    mavlink_modality_snapshot_t packet;
    packet.time_usec = time_usec;
    packet.sequence_number = sequence_number;
    mav_array_memcpy(packet.snapshot, snapshot, sizeof(uint8_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MODALITY_SNAPSHOT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
}

/**
 * @brief Pack a modality_snapshot message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot).
 * @param sequence_number  Sequence number.
 * @param snapshot  Modality probe snapshot bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_modality_snapshot_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t sequence_number,const uint8_t *snapshot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, sequence_number);
    _mav_put_uint8_t_array(buf, 12, snapshot, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN);
#else
    mavlink_modality_snapshot_t packet;
    packet.time_usec = time_usec;
    packet.sequence_number = sequence_number;
    mav_array_memcpy(packet.snapshot, snapshot, sizeof(uint8_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MODALITY_SNAPSHOT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
}

/**
 * @brief Encode a modality_snapshot struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param modality_snapshot C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_modality_snapshot_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_modality_snapshot_t* modality_snapshot)
{
    return mavlink_msg_modality_snapshot_pack(system_id, component_id, msg, modality_snapshot->time_usec, modality_snapshot->sequence_number, modality_snapshot->snapshot);
}

/**
 * @brief Encode a modality_snapshot struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param modality_snapshot C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_modality_snapshot_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_modality_snapshot_t* modality_snapshot)
{
    return mavlink_msg_modality_snapshot_pack_chan(system_id, component_id, chan, msg, modality_snapshot->time_usec, modality_snapshot->sequence_number, modality_snapshot->snapshot);
}

/**
 * @brief Send a modality_snapshot message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot).
 * @param sequence_number  Sequence number.
 * @param snapshot  Modality probe snapshot bytes.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_modality_snapshot_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t sequence_number, const uint8_t *snapshot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, sequence_number);
    _mav_put_uint8_t_array(buf, 12, snapshot, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODALITY_SNAPSHOT, buf, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
#else
    mavlink_modality_snapshot_t packet;
    packet.time_usec = time_usec;
    packet.sequence_number = sequence_number;
    mav_array_memcpy(packet.snapshot, snapshot, sizeof(uint8_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODALITY_SNAPSHOT, (const char *)&packet, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
#endif
}

/**
 * @brief Send a modality_snapshot message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_modality_snapshot_send_struct(mavlink_channel_t chan, const mavlink_modality_snapshot_t* modality_snapshot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_modality_snapshot_send(chan, modality_snapshot->time_usec, modality_snapshot->sequence_number, modality_snapshot->snapshot);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODALITY_SNAPSHOT, (const char *)modality_snapshot, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
#endif
}

#if MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_modality_snapshot_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t sequence_number, const uint8_t *snapshot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, sequence_number);
    _mav_put_uint8_t_array(buf, 12, snapshot, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODALITY_SNAPSHOT, buf, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
#else
    mavlink_modality_snapshot_t *packet = (mavlink_modality_snapshot_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->sequence_number = sequence_number;
    mav_array_memcpy(packet->snapshot, snapshot, sizeof(uint8_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODALITY_SNAPSHOT, (const char *)packet, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_MIN_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_CRC);
#endif
}
#endif

#endif

// MESSAGE MODALITY_SNAPSHOT UNPACKING


/**
 * @brief Get field time_usec from modality_snapshot message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot).
 */
static inline uint64_t mavlink_msg_modality_snapshot_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field sequence_number from modality_snapshot message
 *
 * @return  Sequence number.
 */
static inline uint32_t mavlink_msg_modality_snapshot_get_sequence_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field snapshot from modality_snapshot message
 *
 * @return  Modality probe snapshot bytes.
 */
static inline uint16_t mavlink_msg_modality_snapshot_get_snapshot(const mavlink_message_t* msg, uint8_t *snapshot)
{
    return _MAV_RETURN_uint8_t_array(msg, snapshot, 12,  12);
}

/**
 * @brief Decode a modality_snapshot message into a struct
 *
 * @param msg The message to decode
 * @param modality_snapshot C-struct to decode the message contents into
 */
static inline void mavlink_msg_modality_snapshot_decode(const mavlink_message_t* msg, mavlink_modality_snapshot_t* modality_snapshot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    modality_snapshot->time_usec = mavlink_msg_modality_snapshot_get_time_usec(msg);
    modality_snapshot->sequence_number = mavlink_msg_modality_snapshot_get_sequence_number(msg);
    mavlink_msg_modality_snapshot_get_snapshot(msg, modality_snapshot->snapshot);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN? msg->len : MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN;
        memset(modality_snapshot, 0, MAVLINK_MSG_ID_MODALITY_SNAPSHOT_LEN);
    memcpy(modality_snapshot, _MAV_PAYLOAD(msg), len);
#endif
}
