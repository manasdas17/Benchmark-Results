##############################################################################
# File: Makefile
#
# HPEC Challenge Benchmark Suite
# QR Kernel Makefile
#
# Contents:
#  Makefile for the Complex Fast Givens QR Factorization C kernel.
#
# Usage:
#  Typing "make" will build the qr and qrVerify programs.  Typing 
#  "make clean" will remove the executables.
#
# Author: Ryan Haney
#         MIT Lincoln Laboratory
#
##############################################################################

CC = gcc
CCFLAGS = -xc -ansi -Wall
INC = -I../include
LIBS = -lm

default:
	$(CC) $(CCFLAGS) qr.c -o qr $(INC) $(LIBS)
	$(CC) $(CCFLAGS) qrVerify.c -o qrVerify $(INC) $(LIBS)

clean:
	rm -f qr qrVerify 
##############################################################################
# Copyright (c) 2006, Massachusetts Institute of Technology
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are  
# met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Massachusetts Institute of Technology nor  
#       the names of its contributors may be used to endorse or promote 
#       products derived from this software without specific prior written 
#       permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  
# THE POSSIBILITY OF SUCH DAMAGE.
##############################################################################
