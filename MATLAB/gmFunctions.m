function cFunctions = gmFunctions(full)
% Returns a cell array of GiiMote's internal function names
% cFunctions = gmFunctions(full)
% Returns:
%   cFunctions - A cell array containing GiiMote's internal function names
%   as strings. If full is specified, return a ful description of the
%   functions in the library, including function signatures.
%   This includes duplicate function names with different signatures. If
%   GiiMote is not loaded, returns -1.
% Arguments:
%   full - wheather or not to return full function descriptions and
%   signatures.
    if (gmIsLoaded())
        if (full == true || strcmp(full, '-full'))
            cFunctions = libfunctions('GiiMote', '-full');
        else
            cFunctions = libfunctions('GiiMote');
        end
    else
        cFunctions = -1;
    end
end