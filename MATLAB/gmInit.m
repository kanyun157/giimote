function gmInit()
% Loads GiiMote into memory
    if ~(gmIsLoaded())
        loadlibrary('GiiMote', 'gmProto.m');
        calllib('GiiMote', 'gm_init');
    end
end