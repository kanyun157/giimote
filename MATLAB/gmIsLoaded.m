% Returns wheather or not GiiMote is loaded
% isLoaded = gmIsLoaded()
% Returns:
%   isLoaded - Wheather or not GiiMote is loaded (boolean).
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
function isLoaded = gmIsLoaded()
    isLoaded = libisloaded('GiiMote');
end