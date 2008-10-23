function retcode = buildPrototype(fname)
    cd ../MATLAB
    loadlibrary('GiiMote.dll', '../GiiMote/GiiMote.h', 'mfilename', fname);
    if (libisloaded('GiiMote.dll'))
        retcode = 0;
        unloadlibrary('GiiMote.dll');
    else
        retcode = 1;
    end
end