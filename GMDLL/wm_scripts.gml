#define wm_classic_get_calibration_maxtrigger
// argument0 - Trigger ID
layer_function(global.gm_class,"wm_classic_get_calibration_maxtrigger",ty_real,1,argument0);
#define wm_classic_get_calibration_maxx
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_get_calibration_maxx",ty_real,1,argument0);
#define wm_classic_get_calibration_maxy
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_get_calibration_maxy",ty_real,1,argument0);
#define wm_classic_get_calibration_midx
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_get_calibration_midx",ty_real,1,argument0);
#define wm_classic_get_calibration_midy
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_get_calibration_midy",ty_real,1,argument0);
#define wm_classic_get_calibration_mintrigger
// argument0 - Trigger ID
layer_function(global.gm_class,"wm_classic_get_calibration_mintrigger",ty_real,1,argument0);
#define wm_classic_get_calibration_minx
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_get_calibration_minx",ty_real,1,argument0);
#define wm_classic_get_calibration_miny
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_get_calibration_miny",ty_real,1,argument0);
#define wm_classic_set_calibration_maxtrigger
// argument0 - Trigger
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_maxtrigger",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_maxx
// argument0 - Joystick
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_maxx",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_maxy
// argument0 - Joystick
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_maxy",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_midx
// argument0 - Joystick
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_midx",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_midy
// argument0 - Joystick
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_midy",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_mintrigger
// argument0 - Trigger
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_mintrigger",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_minx
// argument0 - Joystick
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_minx",ty_real,2,argument0,argument1);
#define wm_classic_set_calibration_miny
// argument0 - Joystick
// argument1 - Value
layer_function(global.gm_class,"wm_classic_set_calibration_miny",ty_real,2,argument0,argument1);
#define wm_classic_check_button
// argument0 - Button key code
layer_function(global.gm_class,"wm_classic_check_button",ty_real,1,argument0);
#define wm_classic_direction
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_direction",ty_real,1,argument0);
#define wm_classic_pressure
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_pressure",ty_real,1,argument0);
#define wm_classic_rawx
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_rawx",ty_real,1,argument0);
#define wm_classic_rawy
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_rawy",ty_real,1,argument0);
#define wm_classic_trigger_pressure
// argument0 - Trigger ID
layer_function(global.gm_class,"wm_classic_trigger_pressure",ty_real,1,argument0);
#define wm_classic_trigger_raw
// argument0 - Trigger ID
layer_function(global.gm_class,"wm_classic_trigger_raw",ty_real,1,argument0);
#define wm_classic_xpos
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_xpos",ty_real,1,argument0);
#define wm_classic_ypos
// argument0 - Joystick ID
layer_function(global.gm_class,"wm_classic_ypos",ty_real,1,argument0);
#define GED_Definitions
/**********************************************************************************

///////////////////////////////////
// GED Function Definitions
///////////////////////////////////

kind dll-cdecl
hfunction gm_init():real
function wm_connect():real
function wm_get_status():real
function wm_exists():real
hfunction wm_set_write_method(alt_write_method:real):real
function wm_disconnect():real
function wm_connected():real
function wm_get_led(led:real):real
function wm_set_led(led:real,on:real):real
function wm_set_leds(led1:real,led2:real,led3:real,led4:real):real
function wm_set_leds_int(leds:real):real
function wm_check_button(wm_button:real):real
function wm_classic_check_button(wm_button:real):real
function wm_nunchuck_check_button(wm_button:real):real
function wm_get_battery():real
function wm_nunchuck_xpos():real
function wm_nunchuck_ypos():real
hfunction wm_nunchuck_rawx():real
hfunction wm_nunchuck_rawy():real
function wm_nunchuck_direction():real
function wm_nunchuck_pressure():real
function wm_classic_xpos(wm_joystick:real):real
function wm_classic_ypos(wm_joystick:real):real
hfunction wm_classic_rawx(wm_joystick:real):real
hfunction wm_classic_rawy(wm_joystick:real):real
function wm_classic_direction(wm_joystick:real):real
function wm_classic_pressure(wm_joystick:real):real
function wm_classic_trigger_pressure(trigger:real):real
hfunction wm_classic_trigger_raw(trigger:real):real
function wm_check_extension():real
function wm_set_rumble(rumbling:real):real
function wm_get_rumble():real

function wm_set_joystick_dead_zone(val:real):real
function wm_set_trigger_dead_zone(val:real):real
function wm_get_joystick_dead_zone():real
function wm_get_trigger_dead_zone():real

function wm_get_accel_x():real
function wm_get_accel_y():real
function wm_get_accel_z():real
function wm_get_accel_dead_zone_x():real
function wm_get_accel_dead_zone_y():real
function wm_get_accel_dead_zone_z():real
function wm_set_accel_dead_zone_x(val:real):real
function wm_set_accel_dead_zone_y(val:real):real
function wm_set_accel_dead_zone_z(val:real):real
hfunction wm_get_accel_rawx():real
hfunction wm_get_accel_rawy():real
hfunction wm_get_accel_rawz():real
function wm_nunchuck_get_accel_x():real
function wm_nunchuck_get_accel_y():real
function wm_nunchuck_get_accel_z():real
function wm_nunchuck_get_accel_dead_zone_x():real
function wm_nunchuck_get_accel_dead_zone_y():real
function wm_nunchuck_get_accel_dead_zone_z():real
function wm_nunchuck_set_accel_dead_zone_x(val:real):real
function wm_nunchuck_set_accel_dead_zone_y(val:real):real
function wm_nunchuck_set_accel_dead_zone_z(val:real):real
hfunction wm_nunchuck_get_accel_rawx():real
hfunction wm_nunchuck_get_accel_rawy():real
hfunction wm_nunchuck_get_accel_rawz():real

function wm_ir_found_dot(dot:real):real
function wm_ir_dot_size(dot:real):real
function wm_ir_dot_get_x(dot:real):real
function wm_ir_dot_get_y(dot:real):real
function wm_ir_dot_get_midx():real
function wm_ir_dot_get_midy():real
hfunction wm_ir_dot_get_rawx(dot:real):real
hfunction wm_ir_dot_get_rawy(dot:real):real
hfunction wm_ir_dot_get_rawmidx():real
hfunction wm_ir_dot_get_rawmidy():real
function wm_ir_display_get_x():real
function wm_ir_display_get_y():real
function wm_ir_set_calibration_right():real
function wm_ir_set_calibration_left():real
function wm_ir_set_calibration_top():real
function wm_ir_set_calibration_bottom():real
function wm_ir_sensor_bar_set_pos():real
function wm_ir_get_calibration_right():real
function wm_ir_get_calibration_left():real
function wm_ir_get_calibration_top():real
function wm_ir_get_calibration_bottom():real
function wm_ir_sensor_bar_get_pos():real

function wm_get_calibration_x0():real
function wm_get_calibration_xg():real
function wm_get_calibration_y0():real
function wm_get_calibration_yg():real
function wm_get_calibration_z0():real
function wm_get_calibration_zg():real
function wm_set_calibration_x0(val:real):real
function wm_set_calibration_xg(val:real):real
function wm_set_calibration_y0(val:real):real
function wm_set_calibration_yg(val:real):real
function wm_set_calibration_z0(val:real):real
function wm_set_calibration_zg(val:real):real

function wm_nunchuck_get_calibration_x0():real
function wm_nunchuck_get_calibration_xg():real
function wm_nunchuck_get_calibration_y0():real
function wm_nunchuck_get_calibration_yg():real
function wm_nunchuck_get_calibration_z0():real
function wm_nunchuck_get_calibration_zg():real
function wm_nunchuck_get_calibration_maxx():real
function wm_nunchuck_get_calibration_maxy():real
function wm_nunchuck_get_calibration_midx():real
function wm_nunchuck_get_calibration_midy():real
function wm_nunchuck_get_calibration_minx():real
function wm_nunchuck_get_calibration_miny():real
function wm_nunchuck_set_calibration_x0(val:real):real
function wm_nunchuck_set_calibration_xg(val:real):real
function wm_nunchuck_set_calibration_y0(val:real):real
function wm_nunchuck_set_calibration_yg(val:real):real
function wm_nunchuck_set_calibration_z0(val:real):real
function wm_nunchuck_set_calibration_zg(val:real):real
function wm_nunchuck_set_calibration_maxx(val:real):real
function wm_nunchuck_set_calibration_maxy(val:real):real
function wm_nunchuck_set_calibration_midx(val:real):real
function wm_nunchuck_set_calibration_midy(val:real):real
function wm_nunchuck_set_calibration_minx(val:real):real
function wm_nunchuck_set_calibration_miny(val:real):real

function wm_classic_get_calibration_maxtrigger(trigger:real):real
function wm_classic_get_calibration_mintrigger(trigger:real):real
function wm_classic_get_calibration_maxx(joystick:real):real
function wm_classic_get_calibration_minx(joystick:real):real
function wm_classic_get_calibration_midx(joystick:real):real
function wm_classic_get_calibration_maxy(joystick:real):real
function wm_classic_get_calibration_miny(joystick:real):real
function wm_classic_get_calibration_midy(joystick:real):real
function wm_classic_set_calibration_maxtrigger(trigger:real,val:real):real
function wm_classic_set_calibration_mintrigger(trigger:real,val:real):real
function wm_classic_set_calibration_maxx(joystick:real,val:real):real
function wm_classic_set_calibration_minx(joystick:real,val:real):real
function wm_classic_set_calibration_midx(joystick:real,val:real):real
function wm_classic_set_calibration_midy(joystick:real,val:real):real
function wm_classic_set_calibration_maxy(joystick:real,val:real):real
function wm_classic_set_calibration_miny(joystick:real,val:real):real

function wm_bin_read_byte(address:real):real
function wm_bin_write_byte(address:real,byte:real):real

function wm_mii_data_dump(file:string,block:real,mii:real):real
function wm_mii_data_inject(file:string,block:real,mii:real):real
function wm_mii_update_crc(file:string):real
function wm_mii_get_address(mii:real,block:real):real

///////////////////////////////////
// GED Constant Definitions
///////////////////////////////////

// General Buttons
const wm_a = 0
const wm_b = 1
const wm_up = 2
const wm_down = 3
const wm_right = 4
const wm_left = 5
const wm_one = 6
const wm_two = 7
const wm_plus = 8
const wm_minus = 9
const wm_home = 10

// Classic Specific
const wm_x = 6
const wm_y = 7
const wm_l = 11
const wm_r = 12
const wm_zl = 13
const wm_zr = 14

const wm_joy_left = 0
const wm_joy_right = 1

// Nunchuck Specific
const wm_c = 0
const wm_z = 1

// Extension Types
const ext_classic = 1
const ext_nunchuck = 2
const ext_none = 0
const ext_unknown = -1

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


**********************************************************************************/
#define wm_ir_display_get_x
layer_function(global.gm_class,"wm_ir_display_get_x",ty_real,1,display_get_width());
#define wm_ir_display_get_y
layer_function(global.gm_class,"wm_ir_display_get_y",ty_real,1,display_get_height());
#define wm_ir_dot_get_midx
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_midx",ty_real);
#define wm_ir_dot_get_midy
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_midy",ty_real);
#define wm_ir_dot_get_rawmidx
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_rawmidx",ty_real);
#define wm_ir_dot_get_rawmidy
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_rawmidy",ty_real);
#define wm_ir_dot_get_rawx
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_rawx",ty_real,1,argument0);
#define wm_ir_dot_get_rawy
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_rawy",ty_real,1,argument0);
#define wm_ir_dot_get_x
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_x",ty_real,1,argument0);
#define wm_ir_dot_get_y
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_get_y",ty_real,1,argument0);
#define wm_ir_dot_size
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_dot_size",ty_real,1,argument0);
#define wm_ir_found_dot
// argument0 - Dot number (1 or 2)
layer_function(global.gm_class,"wm_ir_found_dot",ty_real,1,argument0);
#define wm_ir_get_calibration_bottom
// wm_ir_get_calibration_bottom()
layer_function(global.gm_class,"wm_ir_get_calibration_bottom",ty_real,0);
#define wm_ir_get_calibration_left
// wm_ir_get_calibration_left()
layer_function(global.gm_class,"wm_ir_get_calibration_left",ty_real,0);
#define wm_ir_get_calibration_right
// wm_ir_get_calibration_right()
layer_function(global.gm_class,"wm_ir_get_calibration_right",ty_real,0);
#define wm_ir_get_calibration_top
// wm_ir_get_calibration_top()
layer_function(global.gm_class,"wm_ir_get_calibration_top",ty_real,0);
#define wm_ir_sensor_bar_get_pos
// wm_ir_sensor_bar_get_pos()
layer_function(global.gm_class,"wm_ir_sensor_bar_get_pos",ty_real,0);
#define wm_ir_sensor_bar_set_pos
// wm_ir_sensor_bar_set_pos(pos)
// pos == ir_screen_top || ir_screen_bottom
layer_function(global.gm_class,"wm_ir_sensor_bar_set_pos",ty_real,1,argument0);
#define wm_ir_set_calibration_bottom
// wm_ir_set_calibration_bottom(val)
// Domain: [0,1]
layer_function(global.gm_class,"wm_ir_set_calibration_bottom",ty_real,1,argument0);
#define wm_ir_set_calibration_left
// wm_ir_set_calibration_left(val)
// Domain: [0,1]
layer_function(global.gm_class,"wm_ir_set_calibration_left",ty_real,1,argument0);
#define wm_ir_set_calibration_right
// wm_ir_set_calibration_right(val)
// Domain: [0,1]
layer_function(global.gm_class,"wm_ir_set_calibration_right",ty_real,1,argument0);
#define wm_ir_set_calibration_top
// wm_ir_set_calibration_top(val)
// Domain: [0,1]
layer_function(global.gm_class,"wm_ir_set_calibration_top",ty_real,1,argument0);
#define wm_nunchuck_get_calibration_maxx
layer_function(global.gm_class,"wm_nunchuck_get_calibration_maxx",ty_real,0);
#define wm_nunchuck_get_calibration_maxy
layer_function(global.gm_class,"wm_nunchuck_get_calibration_maxy",ty_real,0);
#define wm_nunchuck_get_calibration_midx
layer_function(global.gm_class,"wm_nunchuck_get_calibration_midx",ty_real,0);
#define wm_nunchuck_get_calibration_midy
layer_function(global.gm_class,"wm_nunchuck_get_calibration_midy",ty_real,0);
#define wm_nunchuck_get_calibration_minx
layer_function(global.gm_class,"wm_nunchuck_get_calibration_minx",ty_real,0);
#define wm_nunchuck_get_calibration_miny
layer_function(global.gm_class,"wm_nunchuck_get_calibration_miny",ty_real,0);
#define wm_nunchuck_get_calibration_x0
layer_function(global.gm_class,"wm_nunchuck_get_calibration_x0",ty_real,0);
#define wm_nunchuck_get_calibration_xg
layer_function(global.gm_class,"wm_nunchuck_get_calibration_xg",ty_real,0);
#define wm_nunchuck_get_calibration_y0
layer_function(global.gm_class,"wm_nunchuck_get_calibration_y0",ty_real,0);
#define wm_nunchuck_get_calibration_yg
layer_function(global.gm_class,"wm_nunchuck_get_calibration_yg",ty_real,0);
#define wm_nunchuck_get_calibration_z0
layer_function(global.gm_class,"wm_nunchuck_get_calibration_z0",ty_real,0);
#define wm_nunchuck_get_calibration_zg
layer_function(global.gm_class,"wm_nunchuck_get_calibration_zg",ty_real,0);
#define wm_nunchuck_set_calibration_maxx
layer_function(global.gm_class,"wm_nunchuck_set_calibration_maxx",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_maxy
layer_function(global.gm_class,"wm_nunchuck_set_calibration_maxy",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_midx
layer_function(global.gm_class,"wm_nunchuck_set_calibration_midx",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_midy
layer_function(global.gm_class,"wm_nunchuck_set_calibration_midy",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_minx
layer_function(global.gm_class,"wm_nunchuck_set_calibration_minx",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_miny
layer_function(global.gm_class,"wm_nunchuck_set_calibration_miny",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_x0
layer_function(global.gm_class,"wm_nunchuck_set_calibration_x0",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_xg
layer_function(global.gm_class,"wm_nunchuck_set_calibration_xg",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_y0
layer_function(global.gm_class,"wm_nunchuck_set_calibration_y0",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_yg
layer_function(global.gm_class,"wm_nunchuck_set_calibration_yg",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_z0
layer_function(global.gm_class,"wm_nunchuck_set_calibration_z0",ty_real,1,argument0);
#define wm_nunchuck_set_calibration_zg
layer_function(global.gm_class,"wm_nunchuck_set_calibration_zg",ty_real,1,argument0);
#define wm_nunchuck_check_button
// argument0 - Button key code
layer_function(global.gm_class,"wm_nunchuck_check_button",ty_real,1,argument0);
#define wm_nunchuck_direction
layer_function(global.gm_class,"wm_nunchuck_direction",ty_real,0);
#define wm_nunchuck_get_accel_dead_zone_x
layer_function(global.gm_class,"wm_nunchuck_get_accel_dead_zone_x",ty_real,0);
#define wm_nunchuck_get_accel_dead_zone_y
layer_function(global.gm_class,"wm_nunchuck_get_accel_dead_zone_y",ty_real,0);
#define wm_nunchuck_get_accel_dead_zone_z
layer_function(global.gm_class,"wm_nunchuck_get_accel_dead_zone_z",ty_real,0);
#define wm_nunchuck_get_accel_rawx
layer_function(global.gm_class,"wm_nunchuck_get_accel_rawx",ty_real,0);
#define wm_nunchuck_get_accel_rawy
layer_function(global.gm_class,"wm_nunchuck_get_accel_rawy",ty_real,0);
#define wm_nunchuck_get_accel_rawz
layer_function(global.gm_class,"wm_nunchuck_get_accel_rawz",ty_real,0);
#define wm_nunchuck_get_accel_x
layer_function(global.gm_class,"wm_nunchuck_get_accel_x",ty_real,0);
#define wm_nunchuck_get_accel_y
layer_function(global.gm_class,"wm_nunchuck_get_accel_y",ty_real,0);
#define wm_nunchuck_get_accel_z
layer_function(global.gm_class,"wm_nunchuck_get_accel_z",ty_real,0);
#define wm_nunchuck_pressure
layer_function(global.gm_class,"wm_nunchuck_pressure",ty_real,0);
#define wm_nunchuck_rawx
layer_function(global.gm_class,"wm_nunchuck_rawx",ty_real,0);
#define wm_nunchuck_rawy
layer_function(global.gm_class,"wm_nunchuck_rawy",ty_real,0);
#define wm_nunchuck_set_accel_dead_zone_x
layer_function(global.gm_class,"wm_nunchuck_set_accel_dead_zone_x",ty_real,1,argument0);
#define wm_nunchuck_set_accel_dead_zone_y
layer_function(global.gm_class,"wm_nunchuck_set_accel_dead_zone_y",ty_real,1,argument0);
#define wm_nunchuck_set_accel_dead_zone_z
layer_function(global.gm_class,"wm_nunchuck_set_accel_dead_zone_z",ty_real,1,argument0);
#define wm_nunchuck_xpos
layer_function(global.gm_class,"wm_nunchuck_xpos",ty_real,0);
#define wm_nunchuck_ypos
layer_function(global.gm_class,"wm_nunchuck_ypos",ty_real,0);
#define gm_init
layer_init();
global.gm_dll = layer_loaddll(temp_directory+'/temp756/GiiMote.dll');
global.gm_class = layer_createinstance(global.gm_dll,"GiiMoteLib.GiiMote",0);
if (global.gm_class == 0)
{
    show_error("Error! GiiMote.dll not found or link failed.",true);
}
// layer_function(global.gm_class,"gm_init",ty_real,0);
#define wm_check_extension
layer_function(global.gm_class,"wm_check_extension",ty_real,0);
#define wm_connect
// The alternate writing method has been depricated, the
// write method is now automatically detected. You can
// still set it (if you really have to) by using wm_set_write_method
// before connecting.
layer_function(global.gm_class,"wm_connect",ty_real,0);
#define wm_connected
layer_function(global.gm_class,"wm_connected",ty_real,0);
#define wm_disconnect
layer_function(global.gm_class,"wm_disconnect",ty_real,0);
#define wm_exists
layer_function(global.gm_class,"wm_exists",ty_real,0);
#define wm_get_joystick_dead_zone
layer_function(global.gm_class,"wm_get_joystick_dead_zone",ty_real,0);
#define wm_get_status
// Updates the Wii Remote and ensures that the other functions have
// the latest data.
layer_function(global.gm_class,"wm_get_status",ty_real,0);
#define wm_get_trigger_dead_zone
layer_function(global.gm_class,"wm_get_trigger_dead_zone",ty_real,0);
#define wm_set_joystick_dead_zone
layer_function(global.gm_class,"wm_set_joystick_dead_zone",ty_real,1,argument0);
#define wm_set_trigger_dead_zone
layer_function(global.gm_class,"wm_set_trigger_dead_zone",ty_real,1,argument0);
#define wm_set_write_method
layer_function(global.gm_class,"wm_set_write_method",ty_real,1,argument0);
#define wm_get_accel_dead_zone_x
layer_function(global.gm_class,"wm_get_accel_dead_zone_x",ty_real,0);
#define wm_get_accel_dead_zone_y
layer_function(global.gm_class,"wm_get_accel_dead_zone_y",ty_real,0);
#define wm_get_accel_dead_zone_z
layer_function(global.gm_class,"wm_get_accel_dead_zone_z",ty_real,0);
#define wm_get_accel_rawx
layer_function(global.gm_class,"wm_get_accel_rawx",ty_real,0);
#define wm_get_accel_rawy
layer_function(global.gm_class,"wm_get_accel_rawy",ty_real,0);
#define wm_get_accel_rawz
layer_function(global.gm_class,"wm_get_accel_rawz",ty_real,0);
#define wm_get_accel_x
layer_function(global.gm_class,"wm_get_accel_x",ty_real,0);
#define wm_get_accel_y
layer_function(global.gm_class,"wm_get_accel_y",ty_real,0);
#define wm_get_accel_z
layer_function(global.gm_class,"wm_get_accel_z",ty_real,0);
#define wm_set_accel_dead_zone_x
layer_function(global.gm_class,"wm_set_accel_dead_zone_x",ty_real,1,argument0);
#define wm_set_accel_dead_zone_y
layer_function(global.gm_class,"wm_set_accel_dead_zone_y",ty_real,1,argument0);
#define wm_set_accel_dead_zone_z
layer_function(global.gm_class,"wm_set_accel_dead_zone_z",ty_real,1,argument0);
#define wm_get_calibration_x0
layer_function(global.gm_class,"wm_get_calibration_x0",ty_real,0);
#define wm_get_calibration_xg
layer_function(global.gm_class,"wm_get_calibration_xg",ty_real,0);
#define wm_get_calibration_y0
layer_function(global.gm_class,"wm_get_calibration_y0",ty_real,0);
#define wm_get_calibration_yg
layer_function(global.gm_class,"wm_get_calibration_yg",ty_real,0);
#define wm_get_calibration_z0
layer_function(global.gm_class,"wm_get_calibration_z0",ty_real,0);
#define wm_get_calibration_zg
layer_function(global.gm_class,"wm_get_calibration_zg",ty_real,0);
#define wm_set_calibration_x0
layer_function(global.gm_class,"wm_set_calibration_x0",ty_real,1,argument0);
#define wm_set_calibration_xg
layer_function(global.gm_class,"wm_set_calibration_xg",ty_real,1,argument0);
#define wm_set_calibration_y0
layer_function(global.gm_class,"wm_set_calibration_y0",ty_real,1,argument0);
#define wm_set_calibration_yg
layer_function(global.gm_class,"wm_set_calibration_yg",ty_real,1,argument0);
#define wm_set_calibration_z0
layer_function(global.gm_class,"wm_set_calibration_z0",ty_real,1,argument0);
#define wm_set_calibration_zg
layer_function(global.gm_class,"wm_set_calibration_zg",ty_real,1,argument0);
#define wm_bin_read_byte
// argument0 - Address
layer_function(global.gm_class,"wm_bin_read_byte",ty_real,1,argument0);
#define wm_bin_write_byte
// argument0 - Address
// argument1 - Value
layer_function(global.gm_class,"wm_bin_write_byte",ty_real,2,argument0,argument1);
#define wm_mii_data_dump
// argument0 - The filename to dump to
// argument1 - The Mii block to dump (1 or 2 or 0 for both)
// argument2 - Optional: The Mii to dump (1-10 or 0 for all Mii's)
// Returns:
// -1 - Failure to read from WM / no such Mii/block
//  0 - Failure to write to file
//  1 - Success
layer_function(global.gm_class,"wm_mii_data_dump",ty_real,3,argument0,argument1,argument2);
#define wm_mii_data_inject
// argument0 - The filename to inject from
// argument1 - The Mii block to inject (1 or 2 or 0 for both)
// argument2 - Optional: The Mii to inject (1-10 or 0 for all Mii's)
// Returns:
// -1 - Failure to read from file / no such Mii/block
//  0 - Failure to write to WM
//  1 - Success
layer_function(global.gm_class,"wm_mii_data_inject",ty_real,3,argument0,argument1,argument2);
#define wm_mii_get_address
// Argument1 - Mii to get the address of (1 - 10)
// Argument2 - Optional, the block the Mii Resides in (1 or 2)
// Returns:
//         Address if sucessfull
//         -1 if Mii does not exist

var mii_num, mii_block;
mii_num = argument1;
mii_block = argument2;
if (mii_num > 10 || mii_num < 1 || mii_block < 1 || mii_block > 2)
{
     return (-1);
}

return (wm_mii_block_offset + (wm_mii_block_size * (mii_block - 1)) + (wm_mii_size * mii_num) );
#define wm_mii_update_crc
// argument0 - The filename to update.
layer_function(global.gm_class,"wm_mii_update_crc",ty_real,1,argument0);
#define wm_check_button
// argument0 - Button key code
layer_function(global.gm_class,"wm_check_button",ty_real,1,argument0);
#define wm_clear_leds
return( wm_set_leds(0,0,0,0) );
#define wm_get_battery
layer_function(global.gm_class,"wm_get_battery",ty_real,0);
#define wm_get_led
// argument0 - Led number (1-4)
layer_function(global.gm_class,"wm_get_led",ty_real,1,argument0);
#define wm_get_rumble
layer_function(global.gm_class,"wm_get_rumble",ty_real,0);
#define wm_set_led
// argument0 - Led number (1-4)
// argument1 - Led state

var leds;
leds[0] = wm_get_led(1);
leds[1] = wm_get_led(2);
leds[2] = wm_get_led(3);
leds[3] = wm_get_led(4);
leds[argument0 - 1] = argument1;
wm_set_leds(leds[0],leds[1],leds[2],leds[3]);
#define wm_set_leds
// argument0 - Led 1 state
// argument1 - Led 2 state
// argument2 - Led 3 state
// argument3 - Led 4 state
layer_function(global.gm_class,"wm_set_leds",ty_real,4,argument0,argument1,argument2,argument3);
#define wm_set_leds_int
// argument0 - Leds as Integer
layer_function(global.gm_class,"wm_set_leds_int",ty_real,1,argument0);
#define wm_set_rumble
// argument0 - rumbling
layer_function(global.gm_class,"wm_set_rumble",ty_real,1,argument0);
