#pragma once

typedef enum {
  /* Used to indicate that the telemetry data is invalid.
     It should not have a pack function. */
  TELEM_NONE = 0,

  // Temperature values
  TELEM_CC1120_TEMP,
  TELEM_COMMS_CUSTOM_TRANSCEIVER_TEMP,
  TELEM_OBC_TEMP,
  TELEM_ADCS_MAG_BOARD_TEMP,
  TELEM_ADCS_SENSOR_BOARD_TEMP,
  TELEM_EPS_BOARD_TEMP,
  TELEM_SOLAR_PANEL_1_TEMP,
  TELEM_SOLAR_PANEL_2_TEMP,
  TELEM_SOLAR_PANEL_3_TEMP,
  TELEM_SOLAR_PANEL_4_TEMP,

  // Current values
  TELEM_EPS_COMMS_5V_CURRENT,
  TELEM_EPS_COMMS_3V3_CURRENT,
  TELEM_EPS_MAGNETORQUER_8V_CURRENT,
  TELEM_EPS_ADCS_5V_CURRENT,
  TELEM_EPS_ADCS_3V3_CURRENT,
  TELEM_EPS_OBC_3V3_CURRENT,

  // Voltage values
  TELEM_EPS_COMMS_5V_VOLTAGE,
  TELEM_EPS_COMMS_3V3_VOLTAGE,
  TELEM_EPS_MAGNETORQUER_8V_VOLTAGE,
  TELEM_EPS_ADCS_5V_VOLTAGE,
  TELEM_EPS_ADCS_3V3_VOLTAGE,
  TELEM_EPS_OBC_3V3_VOLTAGE,

  TELEM_OBC_STATE,
  TELEM_EPS_STATE,

  TELEM_NUM_CSP_PACKETS_RCVD,
  TELEM_PONG,
} telemetry_data_id_t;
