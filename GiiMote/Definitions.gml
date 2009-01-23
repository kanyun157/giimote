#define GED_Constants
/*****************************************************************************

///////////////////////////////////
// GED Constant Definitions
///////////////////////////////////

// General Buttons
const wm_a     = 0
const wm_b     = 1
const wm_up    = 2
const wm_down  = 3
const wm_right = 4
const wm_left  = 5
const wm_one   = 6
const wm_two   = 7
const wm_plus  = 8
const wm_minus = 9
const wm_home  = 10

// Classic Specific Buttons
const wm_x  = 11
const wm_y  = 12
const wm_l  = 13
const wm_r  = 14
const wm_zl = 15
const wm_zr = 16

// Classic Joysticks
const wm_joy_left  = 0
const wm_joy_right = 1

// Nunchuck Specific Buttons
const wm_c = 19
const wm_z = 20

// Guitar Specific Buttons
const wm_blue         = 21
const wm_green        = 22
const wm_orange       = 23
const wm_red          = 24
const wm_yellow       = 25
const wm_touch_blue   = 28
const wm_touch_green  = 29;
const wm_touch_orange = 30;
const wm_touch_red    = 31;
const wm_touch_yellow = 32;
const wm_strum_down   = 26
const wm_strum_up     = 27

// Balance Board Sensors
const bb_btmleft  = 0
const bb_btmright = 1
const bb_topleft  = 2
const bb_topright = 3

// Extension Types
const ext_classic         = 1
const ext_nunchuck        = 2
const ext_guitar          = 3
const ext_balanceboard    = 4
const ext_drums		  = 5
const ext_none            = 0
const ext_unknown         = -1

// Report Types
const rt_auto             = 0
const rt_buttons          = 1
const rt_buttonsaccel     = 2
const rt_buttonsextension = 3
const rt_extensionaccel   = 4
const rt_iraccel          = 5
const rt_irextensionaccel = 6
const rt_readdata         = 7
const rt_status           = 8

// Mii Data
const wm_mii_block_size             = $2F0
const wm_mii_block_offset           = $FCA
const wm_mii_size                   = $4A
const wm_mii_name_length		= 10
const wm_mii_creator_name_length 	= 10
const wm_mii_height_min 		= $00
const wm_mii_height_max			= $7F
const wm_mii_weight_min			= $00
const wm_mii_weight_max			= $7F

*****************************************************************************/
#define GED_Definitions
/*****************************************************************************

///////////////////////////////////
// GED Function Definitions
///////////////////////////////////

kind dll-cdecl
hfunction gm_init():real
hfunction gm_cleanup():real
function wm_bin_read_byte(address:real):real
function wm_bin_write_byte(address:real,byte:real):real
function wm_check_button(wm_button:real):real
function wm_check_extension():real
function wm_classic_check_button(wm_button:real):real
function wm_classic_direction(wm_joystick:real):real
function wm_classic_get_calibration_maxtrigger(trigger:real):real
function wm_classic_get_calibration_maxx(joystick:real):real
function wm_classic_get_calibration_maxy(joystick:real):real
function wm_classic_get_calibration_midx(joystick:real):real
function wm_classic_get_calibration_midy(joystick:real):real
function wm_classic_get_calibration_mintrigger(trigger:real):real
function wm_classic_get_calibration_minx(joystick:real):real
function wm_classic_get_calibration_miny(joystick:real):real
function wm_classic_pressure(wm_joystick:real):real
function wm_classic_set_calibration_maxtrigger(trigger:real,val:real):real
function wm_classic_set_calibration_maxx(joystick:real,val:real):real
function wm_classic_set_calibration_maxy(joystick:real,val:real):real
function wm_classic_set_calibration_midx(joystick:real,val:real):real
function wm_classic_set_calibration_midy(joystick:real,val:real):real
function wm_classic_set_calibration_mintrigger(trigger:real,val:real):real
function wm_classic_set_calibration_minx(joystick:real,val:real):real
function wm_classic_set_calibration_miny(joystick:real,val:real):real
function wm_classic_trigger_pressure(trigger:real):real
function wm_classic_xpos(wm_joystick:real):real
function wm_classic_ypos(wm_joystick:real):real
function wm_connect():real
function wm_connect_all():real
function wm_connected():real
function wm_disconnect():real
function wm_disconnect_all();
function wm_exists():real
function wm_num_exists():real
function wm_find_all():real
function wm_found():real
function wm_get_accel_dead_zone_x():real
function wm_get_accel_dead_zone_y():real
function wm_get_accel_dead_zone_z():real
function wm_get_accel_x():real
function wm_get_accel_y():real
function wm_get_accel_z():real
function wm_get_altitude():real
function wm_get_battery():real
function wm_get_calibration_x0():real
function wm_get_calibration_xg():real
function wm_get_calibration_y0():real
function wm_get_calibration_yg():real
function wm_get_calibration_z0():real
function wm_get_calibration_zg():real
hfunction wm_get_guid_current():string
hfunction wm_get_guid_id(val:real):string
hfunction wm_get_id_current():real
hfunction wm_get_id_guid(guid:string):real
hfunction wm_get_index_current():real
hfunction wm_get_index_guid(guid:string):real
hfunction wm_get_index_id(id:real):real
function wm_get_joystick_dead_zone():real
function wm_get_led(led:real):real
function wm_get_moving():real
function wm_get_pitch():real
function wm_get_report_continuous():real
function wm_get_report_type():real
function wm_get_roll():real
function wm_get_rumble():real
function wm_get_status():real
function wm_get_trigger_dead_zone():real
function wm_get_yaw():real
function wm_guitar_check_button(wm_button:real):real
function wm_guitar_direction():real
function wm_guitar_get_type():real
function wm_guitar_pressure():real
function wm_guitar_rawx():real
function wm_guitar_rawy():real
function wm_guitar_whammybar_pos():real
function wm_guitar_whammybar_rawpos():real
function wm_guitar_xpos():real
function wm_guitar_ypos():real
function wm_ir_display_get_x():real
function wm_ir_display_get_y():real
function wm_ir_dot_get_delta_midx():real
function wm_ir_dot_get_delta_midy():real
function wm_ir_dot_get_delta_x(dot:real):real
function wm_ir_dot_get_delta_y(dot:real):real
function wm_ir_dot_get_midx():real
function wm_ir_dot_get_midy():real
function wm_ir_dot_get_x(dot:real):real
function wm_ir_dot_get_y(dot:real):real
function wm_ir_dot_size(dot:real):real
function wm_ir_found_dot(dot:real):real
function wm_ir_get_sensitivity():real
function wm_ir_set_sensitivity(sensitivity:real):real
function wm_ir_window_get_x():real
function wm_ir_window_get_y():real
function wm_mii_data_dump(file:string,block:real,mii:real):real
function wm_mii_data_inject(file:string,block:real,mii:real):real
function wm_mii_get_address(mii:real,block:real):real
function wm_mii_update_crc(file:string):real
function wm_nunchuck_check_button(wm_button:real):real
function wm_nunchuck_direction():real
function wm_nunchuck_get_accel_dead_zone_x():real
function wm_nunchuck_get_accel_dead_zone_y():real
function wm_nunchuck_get_accel_dead_zone_z():real
function wm_nunchuck_get_accel_x():real
function wm_nunchuck_get_accel_y():real
function wm_nunchuck_get_accel_z():real
function wm_nunchuck_get_calibration_maxx():real
function wm_nunchuck_get_calibration_maxy():real
function wm_nunchuck_get_calibration_midx():real
function wm_nunchuck_get_calibration_midy():real
function wm_nunchuck_get_calibration_minx():real
function wm_nunchuck_get_calibration_miny():real
function wm_nunchuck_get_calibration_x0():real
function wm_nunchuck_get_calibration_xg():real
function wm_nunchuck_get_calibration_y0():real
function wm_nunchuck_get_calibration_yg():real
function wm_nunchuck_get_calibration_z0():real
function wm_nunchuck_get_calibration_zg():real
function wm_nunchuck_pressure():real
function wm_nunchuck_set_accel_dead_zone_x(val:real):real
function wm_nunchuck_set_accel_dead_zone_y(val:real):real
function wm_nunchuck_set_accel_dead_zone_z(val:real):real
function wm_nunchuck_set_calibration_maxx(val:real):real
function wm_nunchuck_set_calibration_maxy(val:real):real
function wm_nunchuck_set_calibration_midx(val:real):real
function wm_nunchuck_set_calibration_midy(val:real):real
function wm_nunchuck_set_calibration_minx(val:real):real
function wm_nunchuck_set_calibration_miny(val:real):real
function wm_nunchuck_set_calibration_x0(val:real):real
function wm_nunchuck_set_calibration_xg(val:real):real
function wm_nunchuck_set_calibration_y0(val:real):real
function wm_nunchuck_set_calibration_yg(val:real):real
function wm_nunchuck_set_calibration_z0(val:real):real
function wm_nunchuck_set_calibration_zg(val:real):real
function wm_nunchuck_xpos():real
function wm_nunchuck_ypos():real
function wm_set_accel_dead_zone_x(val:real):real
function wm_set_accel_dead_zone_y(val:real):real
function wm_set_accel_dead_zone_z(val:real):real
function wm_set_calibration_x0(val:real):real
function wm_set_calibration_xg(val:real):real
function wm_set_calibration_y0(val:real):real
function wm_set_calibration_yg(val:real):real
function wm_set_calibration_z0(val:real):real
function wm_set_calibration_zg(val:real):real
function wm_set_joystick_dead_zone(val:real):real
function wm_set_led(led:real,on:real):real
function wm_set_leds(led1:real,led2:real,led3:real,led4:real):real
function wm_set_leds_int(leds:real):real
function wm_set_report_type(report_type:real, continuous:real):real
function wm_set_rumble(rumbling:real):real
function wm_set_trigger_dead_zone(val:real):real
hfunction wm_set_using_guid(wm:string):real
hfunction wm_set_using_val(wm:real):real
function wm_classic_rawx(wm_joystick:real):real
function wm_classic_rawy(wm_joystick:real):real
function wm_classic_trigger_raw(trigger:real):real
function wm_get_accel_rawx():real
function wm_get_accel_rawy():real
function wm_get_accel_rawz():real
function wm_ir_dot_get_delta_rawmidx():real
function wm_ir_dot_get_delta_rawmidy():real
function wm_ir_dot_get_delta_rawx(dot:real):real
function wm_ir_dot_get_delta_rawy(dot:real):real
function wm_ir_dot_get_rawmidx():real
function wm_ir_dot_get_rawmidy():real
function wm_ir_dot_get_rawx(dot:real):real
function wm_ir_dot_get_rawy(dot:real):real
function wm_nunchuck_get_accel_rawx():real
function wm_nunchuck_get_accel_rawy():real
function wm_nunchuck_get_accel_rawz():real
function wm_nunchuck_rawx():real
function wm_nunchuck_rawy():real

*****************************************************************************/
