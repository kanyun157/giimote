#define layer_init
var dll;
dll = temp_directory+'/temp756/gmdll.dll';
global.layerinit = external_define(dll,'Init',dll_cdecl,ty_real,1,ty_real);
global.layerdll = external_define(dll,'DLLVer',dll_cdecl,ty_string,0);
global.layerasetr = external_define(dll,'SetArgumentReal',dll_cdecl,ty_real,1,ty_real);
global.layerasets = external_define(dll,'SetArgumentString',dll_cdecl,ty_real,1,ty_string);
global.layeraclear = external_define(dll,'ClearArguments',dll_cdecl,ty_real,0);
global.layerfuncr = external_define(dll,'FuncReal',dll_cdecl,ty_real,2,ty_real,ty_string);
global.layerfuncs = external_define(dll,'FuncString',dll_cdecl,ty_string,2,ty_real,ty_string);
global.layerldll = external_define(dll,'LoadDll',dll_cdecl,ty_real,1,ty_string);

global.layerlast = external_define(dll,'LastError',dll_cdecl,ty_string,0);
global.layercreate = external_define(dll,'CreateInstance',dll_cdecl,ty_real,2,ty_real,ty_string);

if (external_call(global.layerdll) != "1.0 BETA")
{
    show_error("LAYER VERSION MISMATCH!",true);
}
if (!external_call(global.layerinit,1))
{
    show_error("LAYER INIT FAILED!",true);
}






#define layer_loaddll
// argument0: filename
// returns: dll_handle
return external_call(global.layerldll,argument0);
#define layer_createinstance
//argument0: dll_handle
//argument1: class name
//argument2: argumentcount (max 8!)
//argument3-10: arguments
//returns: instance_handle
var i, r;
external_call(global.layeraclear);
for (i = 0; i < argument2; i+=1)
{
    if (is_string(argument[i+3]))
    {
        external_call(global.layerasets,argument[i+3]);
    }
    else
    {
        external_call(global.layerasetr,argument[i+3]);
    }
}
r = external_call(global.layercreate,argument0,argument1);
external_call(global.layeraclear);
return r;
#define layer_function
//argument0: instance_handle
//argument1: function_name
//argument2: returntype (ty_real / ty_string)
//argument3: argumentcount (max 8!)
//argument4-11: arguments

var i, r;
external_call(global.layeraclear);
for (i = 0; i < argument3; i+=1)
{
    if (is_string(argument[i+4]))
    {
        external_call(global.layerasets,argument[i+4]);
    }
    else
    {
        external_call(global.layerasetr,argument[i+4]);
    }
}
if (argument2 == ty_string)
{
    r = external_call(global.layerfuncs,argument0,argument1);
}
else
{
    r = external_call(global.layerfuncr,argument0,argument1);
}
external_call(global.layeraclear);
return r;

    
