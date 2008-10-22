function isLoaded = gmIsLoaded()
% Returns wheather or not GiiMote is loaded
% isLoaded = gmIsLoaded()
% Returns:
%   isLoaded - Wheather or not GiiMote is loaded (boolean).
% Arguments:
%   None
    isLoaded = libisloaded('GiiMote');
end