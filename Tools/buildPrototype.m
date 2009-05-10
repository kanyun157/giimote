% Builds a prototype file for GiiMote
% This file is part of the build process for the MATLAB version of GiiMote.
% Returns:
%   None
% Arguments:
%   fname - The filename of the prototype file to output.
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
function retcode = buildPrototype(fname)
    loadlibrary('GiiMote.dll', '../GiiMote/GiiMote.h', 'mfilename', fname);
    if (libisloaded('GiiMote.dll'))
        retcode = 0;
        unloadlibrary('GiiMote.dll');
    else
        retcode = 1;
    end
end