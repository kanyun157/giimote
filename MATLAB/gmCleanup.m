function gmCleanup()
% Unloads GiiMote from memory.
    if (gmIsLoaded())
        calllib('GiiMote', 'gm_cleanup');
        unloadlibrary('GiiMote');
    end
end