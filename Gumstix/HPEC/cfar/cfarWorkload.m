%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File: cfarWorkload.m
%
% HPEC Challenge Benchmark Suite
% CFAR Workload Matlab Function 
%
% function w = cfarWorkload(id)
%
%  Calculates the workload given the identifier for a CFAR
%  datafile.  The workload is expressed in number of floating
%  point operations (flops).
%
%  This function works properly ONLY if run within the cfar
%  subdirectory (i.e. the location of this file is matlab's current
%  working directory).
%
%  Parameters:
%   id - identifier representing which dataset to use; the file read
%        will be of the same form as generated by cfarGenerator,
%        i.e. "<id>-cfar-param.dat".
%
%  Input files:
%   data/<id>-cfar-param.dat - the parameters for dataset <id>
%                              (generated by cfarGenerator()).
%
%  Author: Edmund L. Wong 
%          MIT Lincoln Laboratory
%

function w = cfarWorkload(id)

% Check the identifier
if isnumeric(id)
  id = num2str(id);
end

% Check to see the file exists
cfarPath = '.';
filename = [cfarPath filesep 'data' filesep id '-cfar-param.dat'];
if ~exist(filename, 'file')
  error(['Parameters for dataset ' id ' do not exist.  Run ' ...
         'cfarGenerator() in matlab to generate parameters ' ...
         'for this dataset.']);
end

% Add path to needed matlab functions
oldPath = path;
addpath([cfarPath filesep '..' filesep 'matlab']); 

% Read in the parameters
CfarParam = readFile(['data' filesep id '-cfar-param.dat'], 'int32');
G     = CfarParam(1);
Nbm   = CfarParam(2);
Ncfar = CfarParam(3);
Ndop  = CfarParam(4);
Nrg   = CfarParam(5);
mu    = CfarParam(6);

% now calculate the workload
opsPerCell = 7;
w = opsPerCell*Nbm*Ndop*Nrg;

% Restore path
path(oldPath);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Copyright (c) 2006, Massachusetts Institute of Technology
% All rights reserved.
% 
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are  
% met:
%     * Redistributions of source code must retain the above copyright
%       notice, this list of conditions and the following disclaimer.
%     * Redistributions in binary form must reproduce the above copyright
%       notice, this list of conditions and the following disclaimer in the
%       documentation and/or other materials provided with the distribution.
%     * Neither the name of the Massachusetts Institute of Technology nor  
%       the names of its contributors may be used to endorse or promote 
%       products derived from this software without specific prior written 
%       permission.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  
% THE POSSIBILITY OF SUCH DAMAGE.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
