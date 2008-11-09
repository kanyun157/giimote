% Loads GiiMote into memory
% Returns:
%   notfound - A list of functions which were not found in the library
%   warnings - Any warnigns which occured during the processing of the
%   header or m file
% Arguments:
%   None
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
function [notfound, warnings] = gmInit()
    if ~(gmIsLoaded())
        [notfound, warnings] = loadlibrary('GiiMote', 'gmProto.m');
        calllib('GiiMote', 'gm_init');
    end
end