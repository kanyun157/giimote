function retVal = gmCallFunction(funcName, arg1)
% Calls a function in GiiMote
% retVal = gmCallFunction(funcName, arg1, ..., argN)
% Returns:
%   retVal - The value returned by the function
% Arguments:
%   funcName - The name of the function to call as a string
%   arg1, ... argN - The arguments to pass the function
    if (gmIsLoaded())
        retVal = calllib('GiiMote', funcName, arg1);
    else
        retVal = 0;
        warning('GiiMote:libNotLoaded', 'GiiMote is not loaded!');
    end
end