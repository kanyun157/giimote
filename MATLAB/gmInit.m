function gmInit()
% Loads GiiMote into memory
    if ~(gmIsLoaded())
        loadlibrary('GiiMote');
        calllib('GiiMote', 'gm_init');
    end
end