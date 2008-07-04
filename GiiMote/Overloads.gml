#define wm_get_guid
/*
function wm_get_guid():string
*/
{
    if ( argument0 == 0 )
    {
        return ( wm_get_guid_current() );
    }
    else
    {
        return ( wm_get_guid_id(argument0) );
    }
}
#define wm_get_id
/*
function wm_get_id():real
*/
{
    if (is_string(argument0))
    {
        return ( wm_get_id_guid(argument0) );
    }
    else
    {
        return ( wm_get_id_current() );
    }
}
#define wm_get_index
/*
function wm_get_index():real
*/
{
    if (is_string(argument0))
    {
        return ( wm_get_index_guid(argument0) );
    }
    else
    {
        if (argument0 == 0)
        {
            return ( wm_get_index_current() );
        }
        else
        {
            return ( wm_get_index_id(argument0) );
        }
    }

}
#define wm_set_using
/*
function wm_set_using(wm:real):real
*/
{
    if (is_string(argument0))
    {
        return ( wm_set_using_guid(argument0) );
    }
    else
    {
        return ( wm_set_using_val(argument0) );
    }
}
