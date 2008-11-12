% Calls a function in GiiMote
% retVal = gmCallFunction(funcName, arg1, ..., argN)
% Returns:
%   retVal - The value returned by the function or an empty vector if there
%   is an error
% Arguments:
%   funcName - The name of the function to call as a string
%       args - The arguments to pass the function as a cell array or
%       vector.
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
function retVal = gmCallFunction(funcName, args)
    if (gmIsLoaded())
        len = length(args);
        retVal = 'calllib(''GiiMote'', funcName ';
        if (len ~= 0)
            for i = 1:len
                retVal = [retVal ', '];
                if (iscell(args))
                    retVal = [retVal num2str(args{i})];
                else
                    retVal = [retVal num2str(args(i))];
                end
            end
        end
        retVal = [retVal ');'];
        retVal
        retVal = eval(retVal);
    else
        retVal = [];
        warning('GiiMote:libNotLoaded', 'GiiMote is not loaded!');
    end
end