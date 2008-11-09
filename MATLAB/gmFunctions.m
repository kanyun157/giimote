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
% Copyright 2008 Sam Whited
% 
%     This file is part of GiiMote.
% 
%     GiiMote is free software: you can redistribute it and/or modify
%     it under the terms of the GNU Lesser General Public License as published by
%     the Free Software Foundation, either version 3 of the License, or
%     (at your option) any later version.
% 
%     GiiMote is distributed in the hope that it will be useful,
%     but WITHOUT ANY WARRANTY; without even the implied warranty of
%     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%     GNU Lesser General Public License for more details.
% 
%     You should have received a copy of the GNU Lesser General Public License
%     along with GiiMote.  If not, see <http://www.gnu.org/licenses/>.
function cFunctions = gmFunctions(full)
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