/******************************************************************************
** File: dbVerify.c
**
** HPEC Challenge Benchmark Suite
** Database Kernel Benchmark
**
** Contents:
**  The verifier for the database benchmark.  Checks the number of
**  targets found during each search instruction against the known
**  number of targets that should have been found.
**
** Input files:
**  data/<id>-db-soln.dat    - the actual number of targets that should
**                             be found each cycle (generated by 
**                             dbGenerator()).
**  data/<id>-db-results.dat - the targets found each cycle (generated 
**                             by db).
**
** Author: Edmund L. Wong
**         MIT Lincoln Laboratory
**
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <PcaCArray.h>

/* useful typedef's */
typedef unsigned int uint;

int main(int argc, char** argv)
{
  /* files containing the solution and what the kernel achieved */
  struct PcaCArrayInt param, results, soln;
  char *m_paramfile, *m_resfile, *m_solnfile;

  /* counter */
  uint i, j, num_errors = 0;

  /* check arguments */
  if (argc != 2) {
    fprintf(stderr, "Usage: %s [dataset id]\n", argv[0]);
    exit(-1);
  }

#ifdef VERBOSE
  /* print informative message */
  printf("[Verifying dataset %s]\n", argv[1]);
#endif
  
  /* load up files */
  m_paramfile  = (char*) malloc(strlen("data/") + strlen(argv[1]) +
				strlen("-db-param.dat") + 1);
  m_resfile = (char*) malloc(strlen("data/") + strlen(argv[1]) + 
			     strlen("-db-results.dat") + 1);
  m_solnfile = (char*) malloc(strlen("data/") + strlen(argv[1]) + 
			      strlen("-db-soln.dat") + 1);
  sprintf(m_paramfile, "data/%s-db-param.dat", argv[1]);
  sprintf(m_resfile, "data/%s-db-results.dat", argv[1]);
  sprintf(m_solnfile, "data/%s-db-soln.dat", argv[1]);
  readFromFile(int, m_paramfile, param);
  readFromFile(int, m_resfile, results);
  readFromFile(int, m_solnfile, soln);

  /* check each cycle */
  for (i = 0; i < param.data[6]; i++) {
    for (j = 0; j < param.data[5]; j++) {
      if (results.data[i*param.data[5] + j] != 
	  soln.data[i*param.data[5] + j]) {
#ifdef VERBOSE
	printf("Cycle %d, Search %d: Kernel found %d matching "
	       "target(s), should have found %d target(s).\n", 
	       i, j, results.data[i*param.data[5] + j], 
	       soln.data[i*param.data[5] + j]);
#endif
	num_errors++;
      }
    }
  }
#ifdef VERBOSE
  printf("Total number of error(s) = %d\n", num_errors);
#endif
  printf("Verification: ");
  if (num_errors == 0) printf("PASS\n");
  else printf("FAIL\n");
  
  /* clean up memory */
  clean_mem(int, results);
  clean_mem(int, soln);
  return 0;
}
/* ----------------------------------------------------------------------------
Copyright (c) 2006, Massachusetts Institute of Technology
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are  
met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the Massachusetts Institute of Technology nor  
       the names of its contributors may be used to endorse or promote 
       products derived from this software without specific prior written 
       permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  
THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------- */